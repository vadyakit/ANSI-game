#include <map>
#include <string>
#include <vector>

#pragma once

	class SpritePack
	{
		static std::map<std::string, std::vector<std::string>> sprites;
		static inline const std::string sprites_path = "\\Sprites\\";

	public:
		static std::string GetSprite(std::string SpritePackName, unsigned number);
		void LoadSprites();
	};


