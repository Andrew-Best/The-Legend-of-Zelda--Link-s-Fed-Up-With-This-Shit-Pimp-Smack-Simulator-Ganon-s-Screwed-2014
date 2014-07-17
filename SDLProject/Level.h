#pragma once
#include <string>
#include "SDL.h"

class Level
{
protected:
	SDL_Surface* pTileSheet_;
	Uint16 tileWidth_;
	Uint16 tileHeight_;
	Uint16 tilesWide_;
	Uint16 tilesHigh_;
	
	Uint16** ppTileMapLayer_;
	Uint16** ppTileObjectsLayer_; //this layer is drawn over top of the map layer
	Uint16** ppTilePoleLayer_; //poles bitches

	void loadData(std::string fileName);

public:
	Level(std::string fileName);
	~Level();
	
	Uint16 GetTileWidth()
	{
		return tileWidth_;
	}

	Uint16 GetTileHeight()
	{
		return tileHeight_;
	}

	Uint16 GetTilesWide()
	{
		return tilesWide_;
	}

	SDL_Surface* GetTileSheet()
	{
		return pTileSheet_;
	}

	Uint16 GetWidth()
	{
		return tilesWide_ * tileWidth_;
	}

	Uint16 GetHeight()
	{
		return tilesHigh_ * tileHeight_;
	}

	Uint16 const * const * const GetMapData() const
	{
		return ppTileMapLayer_;
	}

	Uint16  const * const * const GetObjectData() const
	{
		return ppTileObjectsLayer_;
	}

	Uint16 const * const * const GetPoleData() const
	{
		return ppTilePoleLayer_;
	}

};