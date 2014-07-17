#include <string>
#include <iostream>
#include <sstream>
#include "Character.h"


Character::Character(CharacterType type, const Vec2& pos)
{
	LoadCharacter(type);
	pos_ = pos;
}


Character::~Character()
{
}

void Character::LoadCharacter(CharacterType type)
{
	std::ifstream characterData;
	std::string filename;

	switch (type)
	{
	case PLAYER:
		filename = "Player.dat";
		break;
	case GRIM_REAPER:
		filename = "Grim_Reaper.dat";
		break;
	default:
		break;
	}

	characterData.open(filename, std::ios::in);

	if (characterData.is_open())
	{
		processDataFile(characterData);
	}
	else
	{
		characterData.close();
		std::cerr << "Error opening character data: " << filename << std::endl;
	}

	characterData.close();
}

void Character::processDataFile(std::ifstream& file)
{
	std::string buf;
	while (file.good())
	{
		file >> buf;

		if (buf[0] == '#')
		{
			std::getline(file, buf);
		}
		else if (buf == "image:")
		{
			file >> buf;
			pImage_ = IMG_Load(buf.c_str());
		}
		else if (buf == "cellWidth:")
		{
			file >> buf;
			std::stringstream ss(buf);
			ss >> frameWidth_;
		}
		else if (buf == "cellHeight:")
		{
			file >> buf;
			std::stringstream ss(buf);
			ss >> frameHeight_;
		}
		else if (buf == "Animation")
		{
			file >> buf;
			anims_.insert(std::pair<std::string, AnimationData>(buf, AnimationData()));
		}
		else if (buf == "frameRate")
		{
			std::string animName;
			file >> animName;
			file >> buf;
			std::stringstream ss(buf);
			ss >> anims_[animName].frameRate;
		}
		else if (buf == "startFrame")
		{
			std::string animName;
			file >> animName;
			file >> buf;
			std::stringstream ss(buf);
			ss >> anims_[animName].startFrame;
		}
		else if (buf == "numFrames")
		{
			std::string animName;
			file >> animName;
			file >> buf;
			std::stringstream ss(buf);
			ss >> anims_[animName].numFrames;
		}
		else if (buf == "defaultAnimation")
		{
			file >> buf;
			SetCurrAnim(buf);
		}
	}
	initAnim();
}