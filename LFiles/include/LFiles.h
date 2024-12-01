#ifndef LFILES_H
#define LFILES_H
#include <StandardFile.h>       // For StandardFileReply, NewFileFilterUPP and NewDlgHookUPP

#ifdef __cplusplus
extern "C" {
    namespace LFiles {
#endif

void StandardGetFolder(
    Point               where,
    Str255              message,
    StandardFileReply   *mySFReply
);

int getFileInformation(const char* fileName, short *exists, short *isFile, short *isDir);

#ifdef __cplusplus
    }
}
#endif

#endif // LFILES_H