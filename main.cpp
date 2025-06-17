#include<iostream>
#include<filesystem>
#include<fstream>

int main(){

    std::string directory = std::filesystem::current_path();
    std::string directory_name = std::filesystem::current_path().filename();

    if(std::filesystem::exists(directory) && std::filesystem::is_directory(directory)){

        //create/overwrite .M3U file.
        std::ofstream FILE(directory_name + ".M3U");
        
        //list files into the .M3U file.
        for(const auto& track : std::filesystem::directory_iterator(directory)){
            std::string file_extension = track.path().extension();
            //for .mp3 files.
            if(file_extension == ".mp3"){
                FILE << track.path().filename().string() << std::endl;
            
            //for .flac files.
            }else if(file_extension == ".flac"){
                FILE << track.path().filename().string() << std::endl;
            }
        }

    }else{
        std::cerr << "M3U_Creator Cannot Work in the Current Directory.\n";
    }

    return 0;
}