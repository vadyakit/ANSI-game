#include "SpritePack.h"
#include <fstream>
#include <sstream>
#include <filesystem>

std::map<std::string, std::vector<std::string>> SpritePack::sprites;

void SpritePack::LoadSprites()
{
	std::ifstream f;
	std::stringstream ss;

	std::string keyname;

	for (auto& p : std::filesystem::directory_iterator(std::filesystem::current_path().string() + sprites_path)) {

		keyname = p.path().filename().string();

		for (auto& s : std::filesystem::directory_iterator(p.path()))
		{
			f.open(s);
			ss << f.rdbuf();
			sprites[keyname].push_back(ss.str());
		}
	}
}

std::string SpritePack::GetSprite(std::string SpritePackName, unsigned number)
{
	return sprites[SpritePackName][number];
}