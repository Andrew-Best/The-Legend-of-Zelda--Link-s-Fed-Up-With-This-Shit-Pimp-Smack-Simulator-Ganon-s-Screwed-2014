#include "ExampleGame.h"

void ExampleGame::loadAssets()
{
	//test doge
	SDL_Surface* temp = IMG_Load("testSprite.png");
	SDL_Surface* temp2 = SDL_DisplayFormatAlpha(temp);
	SDL_FreeSurface(temp);

	SDL_Rect srcRect = SDL_Rect();
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = temp2->w;
	srcRect.h = temp2->h;

	pTestSprite_ = new Sprite(temp2, Vec2(0.0f, 0.0f), srcRect, 255);
}

void ExampleGame::update(float deltaTime)
{
	
}

void ExampleGame::draw()
{
	pTestSprite_->Draw(pDisplay_);
	Game::draw();
}