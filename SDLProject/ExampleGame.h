#pragma once

#include "Game.h"
#include "Sprite.h"

class ExampleGame : public Game
{
protected:
	virtual void loadAssets();
	virtual void update(float deltaTime);
	virtual void draw();

	//test doge
	Sprite* pTestSprite_;

public:
	ExampleGame() : Game(), pTestSprite_(NULL){}
	virtual ~ExampleGame()
	{
		if (pTestSprite_)
		{
			delete pTestSprite_;
		}
	}
};

