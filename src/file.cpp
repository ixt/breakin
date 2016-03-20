#include "file.h"

File::File(std::string directoryOfChoice, bool * endGameBool){
    struct dirent * file;
    std::vector<const char *> paths;

    paths.push_back(directoryOfChoice.c_str());
    int pathCount = paths.size()-1;
    int pathLocation = 0;

    while (pathCount != pathLocation-1){
        DIR * dir;
        dir = opendir(paths[pathLocation++]);

        if (dir == NULL){
            std::cout << "No files found :P";
            *endGameBool = true;
        }

        while((file = readdir(dir))){
            std::string fileNameAndType = file -> d_name;
            if ( file -> d_type != 4 ) // if the listing isnt a directory add it to the list
               files.push_back(fileNameAndType);
            if ( file -> d_type == 4 && 
                 strcmp(file -> d_name, "..")  != 0 && 
                 strcmp(file -> d_name, "." )  != 0 &&
                 strcmp(file -> d_name, ".git")!= 0) { // if the listing is a directory add it to its list
                std::string separator = "/";
                std::string pathPath = paths[pathLocation-1] + separator + fileNameAndType;
               //files.push_back(pathPath.c_str());
            }
        }
        closedir(dir);
        pathCount = paths.size()-1;
    }
}

void File::drawFiles(int * frameX){
    int counter = 0;
    for (std::string file : files) {
        mvprintw(counter, *frameX, file.c_str());
        counter++;
    }
}
void File::deleteFile(std::string * unfortunateFile){
    auto strike = [] (std::string& text){
        std::string result;
        for (auto ch : text) {
            result.append(u8"\u0336");
            result.push_back(ch);
        }
        text = result;
    };
    for (int i = 0; i < files.size(); i++){
        if(strcmp(files[i].c_str(),unfortunateFile -> c_str())==0){
            strike(files[i]);
            std::cout << files[i];
            // remove(file.c_str());
        }
    }
}
