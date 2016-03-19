#pragma once
#include "breakout.h"
#ifndef FILE_H
#define FILE_H

#include <cstring>

class File {
        DIR dir;
    public:
        File(DIR directoryOfChoice = ".");
        vector<String> files;
        vector<String> unfortunateFiles;
        void addRandomFile();
        void deleteFile(String* unfortunateFile);
        
}

#endif
