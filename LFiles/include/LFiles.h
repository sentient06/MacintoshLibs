#ifndef LFILES_H
#define LFILES_H

namespace LFiles {
    int getFileInformation(const char* fileName, bool *exists, bool *isFile, bool *isDir);
}

#endif // LFILES_H