#pragma once

#include "Game.h"
#include "SpriteAnimation.h"
#include "Player.h"
#include "Level.h"

class ExampleGame : public Game
{
protected:
	virtual void loadAssets();
	virtual void update(float deltaTime);
	virtual void draw();
	void drawLevel();
	
	virtual void onKeyDown(Uint16 key);
	virtual void onKeyUp(Uint16 key);

	//test doge
	Player* pTestSprite_;
	Level* pLevel_;
	Vec2 camera_;

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

