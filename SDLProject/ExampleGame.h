#pragma once

#include "Game.h"
#include "SpriteAnimation.h"

class ExampleGame : public Game
{
protected:
	
	virtual void loadAssets();
	virtual void update(float deltaTime);
	virtual void draw();

	//test doge
	SpriteAnimation* pTestSprite_;

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

