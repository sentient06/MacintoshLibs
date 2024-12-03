# Files Library

## Namespace `LFiles`

### Functions

#### StandardGetFolder(where, message, mySFReply)

- `where` - `Point` - coordinates to align the window
- `message` - `Str255` - text to prompt the user
- `*mySFReply` - `StandardFileReply` - pointer to return folder's information
- Returns `void`

Shows the user a window to select a folder.

Returns nothing, but sets a `StandardFileReply` via pointer.

**Usage:**
```
StandardFileReply myReply;
Point  where;
Str255 message = "\pSelect a folder";
where.h = -1;
where.v = -1;

LFiles::StandardGetFolder(where, message, &myReply);
```

---

#### getFileInformation(fileName, exists, isFile, isDir)

- `const char* fileName` - Path of file or directory
- `bool *exists` - pointer to boolean flag
- `bool *isFile` - pointer to boolean flag
- `bool *isDir` - pointer to boolean flag
- Returns `int`

Fetches basic information of a filepath. If any error occurs, it returns a number different than `0`. Otherwise, it returns `0` and sets all the three flags to match their description.

**Usage:**
```
const char * fileName = "Macintosh:Documents:myFile.txt";
bool exists = false;
bool isFile = false;
bool isDir  = false;

LFiles::getFileInformation(fileName, &exists, &isFile, &isDir);
```

---

## Building

1. Install [Retro68](https://github.com/autc04/Retro68);
2. `cd` into this directory;
3. `make clean`
4. `make`
5. `make install`

## Scripts

#### Clean
https://gist.github.com/sentient06/35662e72b75377a44944c7f5c66a0e19

#### Build
https://gist.github.com/sentient06/e4b5a4853a2f3c36884c9ae2187fc012

#### Create HFS image
https://gist.github.com/sentient06/484a27b556777a35467b2e0a2c3edfe2

#### Check for QEMU
https://gist.github.com/sentient06/cce2734c8761991abd8432bbd9772855

#### Mount on QEMU
https://gist.github.com/sentient06/336ba40598e06425bf75ab80fab1e779

#### Build and mount
https://gist.github.com/sentient06/5ee11499cbf157d5ab6973f313c95078