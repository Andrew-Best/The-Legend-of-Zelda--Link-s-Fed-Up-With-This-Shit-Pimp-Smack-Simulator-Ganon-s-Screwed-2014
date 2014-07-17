#include "Level.h"
#include "SDL_image.h"
#include <fstream>
#include <iostream>
#include <sstream>

Level::Level(std::string fileName)
{
	loadData(fileName);
}


Level::~Level()
{
	if (pTileSheet_)
	{
		SDL_FreeSurface(pTileSheet_);
	}

	for (int i = 0; i < tilesHigh_; ++i)
	{
		delete[] ppTileMapLayer_[i];
		delete[] ppTileObjectsLayer_[i];
		delete[] ppTilePoleLayer_[i];
	}

	delete[] ppTileMapLayer_;
	delete[] ppTileObjectsLayer_;
	delete[] ppTilePoleLayer_;

	ppTileMapLayer_ = NULL;
	ppTileObjectsLayer_ = NULL;
	ppTilePoleLayer_ = NULL;
}

void Level::loadData(std::string fileName)
{
	std::ifstream levelInfo;
	levelInfo.open(fileName, std::ios::in);

	if (!levelInfo.is_open())
	{
		levelInfo.close();
		std::cerr << "Error, can't open the data file: " << fileName << std::endl;
		return;
	}

	std::string buf;
	Uint16 ** arrayToInit = NULL;

	while (levelInfo.good())
	{
		levelInfo >> buf;

		if (buf == "width=")
		{
			levelInfo >> buf;
			std::stringstream ss(buf);
			ss >> tilesWide_;
		}
		else if (buf == "height=")
		{
			levelInfo >> buf;
			std::stringstream ss(buf);
			ss >> tilesHigh_;

			ppTileMapLayer_ = new Uint16*[tilesHigh_];
			ppTileObjectsLayer_ = new Uint16*[tilesHigh_];
			ppTilePoleLayer_ = new Uint16*[tilesHigh_];
		}
		else if (buf == "tilewidth=")
		{
			levelInfo >> buf;
			std::stringstream ss(buf);
			ss >> tileWidth_;
		}
		else if (buf == "tileheight=")
		{
			levelInfo >> buf;
			std::stringstream ss(buf);
			ss >> tileHeight_;
		}
		else if (buf == "tileset=")
		{
			levelInfo >> buf;
			pTileSheet_ = IMG_Load(buf.c_str());
		}
		else if (buf == "type=")
		{
			levelInfo >> buf;
			if (buf == "Background")
			{
				arrayToInit = ppTileMapLayer_;
			}
			else if (buf == "Objects")
			{
				arrayToInit = ppTileObjectsLayer_;
			}
			else if (buf == "Poles")
			{
				arrayToInit = ppTilePoleLayer_;
			}
		}
		else if (buf == "data=")
		{
			for (int row = 0; row < tilesHigh_; ++row)
			{
				arrayToInit[row] = new Uint16[tilesWide_];
				for (int col = 0; col < tilesWide_; ++col)
				{
					levelInfo >> buf;
					std::stringstream ss(buf);
					ss >> arrayToInit[row][col];
				}
			}
		}
	}
	tilesWide_ = pTileSheet_->w / tileWidth_;
	levelInfo.close();
}