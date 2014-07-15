#include "ExampleGame.h"

void ExampleGame::loadAssets()
{
	//test doge
	SDL_Surface* temp = IMG_Load("spritesheet.png");
	SDL_Surface* temp2 = SDL_DisplayFormatAlpha(temp);
	SDL_FreeSurface(temp);

	SDL_Rect srcRect = SDL_Rect();
	srcRect.x = 0;
	srcRect.y = 0;
	//srcRect.w = temp2->w;
	//srcRect.h = temp2->h;
	srcRect.w = 40;
	srcRect.h = 40;

	pTestSprite_ = new SpriteAnimation(temp2, Vec2(100.0f, 100.0f), srcRect, 255, 40, 40, 26, 1, 0.2f);
	//pTestSprite_->Play(true);
}

void ExampleGame::update(float deltaTime)
{
	if (isRunningLeft_)
	{
		pTestSprite_->SetStartFrame(31);
		pTestSprite_->SetNumFrames(5);
		pTestSprite_->Play(true);
	}
	if (isRunningRight_)
	{
		pTestSprite_->SetStartFrame(10);
		pTestSprite_->SetNumFrames(5);
		pTestSprite_->Play(true);
	}
	if (isFacingLeft_)
	{
		if (isAttacking_)
		{
			pTestSprite_->SetStartFrame(38);
			pTestSprite_->SetNumFrames(2);
			pTestSprite_->Play(false);
		}
		else if (isJumping_)
		{
			pTestSprite_->SetStartFrame(28);
			pTestSprite_->SetNumFrames(1);
			pTestSprite_->Play(false);
		}
		else
		{
			pTestSprite_->SetStartFrame(27);
			pTestSprite_->SetNumFrames(1);
			pTestSprite_->Play(true);
		}
	}
	if (isFacingRight_)
	{
		if (isAttacking_)
		{
			pTestSprite_->SetStartFrame(20);
			pTestSprite_->SetNumFrames(2);
			pTestSprite_->Play(false);
		}
		else if (isJumping_)
		{
			pTestSprite_->SetStartFrame(9);
			pTestSprite_->SetNumFrames(1);
			pTestSprite_->Play(false);
		}
		else
		{
			pTestSprite_->SetStartFrame(26);
			pTestSprite_->SetNumFrames(1);
			pTestSprite_->Play(true);
		}
	}
	pTestSprite_->Update(deltaTime);
}

void ExampleGame::draw()
{
	pTestSprite_->Draw(pDisplay_);
	Game::draw();
}