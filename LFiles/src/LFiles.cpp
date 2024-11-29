#include <Files.h>
#include <string.h>
#include "../include/LFiles.h"

namespace LFiles {

  /**
   * C to Pascal String.
   */
  void CtoPStr(const char* cString, Str255 pStr) {
    size_t len = strlen(cString);
    pStr[0] = len;
    memcpy(&pStr[1], cString, len);
  }

  /**
   * Pascal to C String.
   */
  void PtoCStr(const unsigned char *pStr, char *cStr) {
    unsigned char length = pStr[0];
    memcpy(cStr, &pStr[1], length);
    cStr[length] = '\0';
  }

  /**
   * getFileInformation returns information about a file.
   * This implementation searches for relative path.
   * It's not encouraged to use full paths on Mac OS, so any other file checks
   * would involve the GUI.
   * As it uses relative paths, this doesn't work with application packages.
   *
   * @param (const char) fileName - A C string. The file or directory we want to
   *                                check.
   */
  int getFileInformation(const char* fileName, bool *exists, bool *isFile, bool *isDir) {

    short      vRefNum   = 0;  // Volume and directory reference number.
    long       dirID     = 0L; // Directory ID.
    Str63      pFileName = ""; // File name in pascal string.
    Str255     volName;        // Volume name. It's optional.
    OSErr      err;            // Error handling.
    CInfoPBRec catInfo;        // Catalogue information to get file's info.
    
    if (fileName == NULL || fileName[0] == '\0') return -1;
    
    *exists = false;
    *isFile = false;
    *isDir  = false;

    /**
     * GetVol returns a volume name and a Working Directory Reference Number
     * (aka ioVRefNum).
     *
     * @param (Str255) volName - pointer to a pascal string that will receive the
     *                           volume name.
     * @param (short)  vRefNum - a pointer to a short that will receive the
     *                           Working Directory Reference Number.
     */
    err = GetVol(&volName[0], &vRefNum);
    if (err != noErr) {
      return err;
    }

    /**
     * GetWDInfo can break up a ioVRefNum into a ioVRefNum/ioDirID pair.
     * ioVRefNum-s are either volume ids or a concatenated version of volume and
     * dir. That's for backwards compatibility with MFS.
     *
     * @param (short) wdRefNum - a 'working directory' ref num.
     * @param (short) vRefNum  - pointer, volume or drive number, returns a
     *                           reference number for the working directory.
     * @param (long)  dirID    - pointer, outputs a dir id for the wd.
     * @param (long)  procID   - wd's user identifier.
     */
    err = GetWDInfo(
      vRefNum,
      &vRefNum,
      &dirID,
      NULL
    );

    if (err != noErr) {
      return err;
    }
    
    // Copy C string into pascal string:  
    CtoPStr(fileName, pFileName);
    
    // CInfoPBRec catInfo - init
    memset(&catInfo, 0, sizeof(CInfoPBRec));
    catInfo.hFileInfo.ioNamePtr = pFileName;
    catInfo.hFileInfo.ioVRefNum = vRefNum;
    catInfo.hFileInfo.ioDirID   = dirID;

    /**
     * PBGetCatInfoSync does many things.
     * Here we use it to get information about the file/directory.
     *
     * @param (CInfoPBRec) paramBlock - Pointer. A catalog information.
     * @see Inside Macintosh - Files. 2-190. (Page 278 in the pdf.)
     */
    err = PBGetCatInfoSync(&catInfo);
    if (err == noErr) {
      *exists = true;
      /*
       * The ioDirMask constant is part of the ioFlAttrib field in the CInfoPBRec
       * structure, which is returned by various file system calls in the
       * Macintosh Toolbox. This checks if the file is a directory by looking for
       * the ioDirMask bit being set in the ioFlAttrib attribute field.
       * ioDirMask's value is 0x10.
       */
      if (catInfo.hFileInfo.ioFlAttrib & ioDirMask) {
        *isDir = true;
      } else {
        *isFile = true;
      }
    } else {
      return err;
    }
    
    return 0;
  }
}