#include "file.h"

File::File(std::string directoryOfChoice, bool * endGameBool){
    std::vector<std::string> * paths = new std::vector<std::string>;

    paths -> push_back(directoryOfChoice.c_str());
    unsigned int pathLocation = 0;

    while (1){
        std::vector <std::string> &path = *paths;

        if (path.size() == pathLocation){
            break;
        }

        struct dirent * file;
        DIR * dir;
        dir = opendir(path.at(pathLocation).c_str());

        if (dir == NULL){
            std::cout << "No files found :P";
            *endGameBool = true;
        }

        while((file = readdir(dir))){
                std::string prepend = "";
            if (pathLocation != 0)
                prepend = path.at(pathLocation) + "/";
            std::string fileNameAndType = file -> d_name;
            if ( file -> d_type != 4 ) // if the listing isnt a directory add it to the list
               files.push_back(prepend + fileNameAndType);
            if ( file -> d_type == 4 && 
                 strcmp(file -> d_name, "..")  != 0 && 
                 strcmp(file -> d_name, "." )  != 0 &&
                 strcmp(file -> d_name, ".git")!= 0) { // if the listing is a directory add it to its list
                std::string separator = "/";
                std::string pathPath = path.at(pathLocation) + separator + fileNameAndType;
               path.push_back(pathPath.c_str());
            }
        }
        closedir(dir);
        pathLocation++;
    }
    goneFiles.resize(paths -> size(),false);
    std::cout << files.size();

}

void File::drawFiles(int * frameX){
    int counter = 0;
    for (std::string file : files) {
        mvprintw(counter, *frameX, file.c_str());
        counter++;
    }
}

void File::deleteFile(int fileToDelete){
    if (fileToDelete > files.size())
        return;
    auto strike = [] (std::string& text){
        std::string result;
        for (auto& ch: text) {
            result.append(u8"\u0336");
            result.push_back(ch);
        }
        text = result;
    };
    // the code to delete files //////////////////////////////////////////////////
    
    // std::remove(files[fileToDelete].c_str());
    
    // end code to delete files //////////////////////////////////////////////////
    
    if (!goneFiles[fileToDelete]){ // if file hasnt already been deleted, then go on!
        strike(files[fileToDelete]);
        goneFiles[fileToDelete] = true;
    }
}
