#pragma once
#include "breakout.h"
#ifndef FILE_H
#define FILE_H

#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include <dirent.h>



class File {
    public: 
        // Not entirely sure why it let me get away with this but okay
        File(std::string directoryOfChoice =".", bool * endGameBool= (new bool)); 

        std::vector<std::string> files;
        std::vector<bool> goneFiles;
        void addRandomFile();
        void deleteFile(std::string unfortunateFile);
        
        void drawFiles(int * frameX);
};

#endif
