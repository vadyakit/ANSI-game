#include "ResourceLoader.h"
#include <fstream>
#include <sstream>
#include <filesystem>

std::vector<std::string> ResourceLoader::GetSpritesFromAnsFiles(std::string pathToFolder) 
{
    std::ifstream f;
    std::stringstream ss;

    std::vector<std::string> paths;
    std::vector<std::string> sprite;

    for (auto& p : std::filesystem::directory_iterator(pathToFolder)) {
        f.open(p);
        ss << f.rdbuf();
        sprite.push_back(ss.str());
    }
    return sprite;
}