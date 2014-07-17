#include "ExampleGame.h"

void ExampleGame::loadAssets()
{
	pLevel_ = new Level("zelda.dat");
	//test doge
	/*SDL_Surface* temp = IMG_Load("spritesheet.png");
	SDL_Surface* temp2 = SDL_DisplayFormatAlpha(temp);
	SDL_FreeSurface(temp);*/

	/*SDL_Rect srcRect = SDL_Rect();
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 40;
	srcRect.h = 40;*/

	//test doge
	pTestSprite_ = new Player(Vec2(100.0f, 100.0f));
	camera_.x = 0.0f;
	camera_.y = 0.0f;
}

void ExampleGame::update(float deltaTime)
{
	pTestSprite_->Update(deltaTime);
}

void ExampleGame::drawLevel()
{
	Uint16 lCol = camera_.x / pLevel_->GetTileWidth();
	Uint16 rCol = (camera_.x + SCREEN_WIDTH) / pLevel_->GetTileWidth();

	Uint16 tRow = camera_.y / pLevel_->GetTileHeight();
	Uint16 bRow = (camera_.y + SCREEN_HEIGHT) / pLevel_->GetTileHeight();

	Uint16 const * const * const data = pLevel_->GetObjectData();

	for (Uint16 row = tRow; row <= bRow; ++row)
	{
		for (Uint16 col = lCol; col <= rCol; ++col)
		{
			if (data[row][col] != 0)
			{
				Uint16 index = data[row][col] - 1;

				SDL_Rect srcRect;
				Uint16 tileSheetCol = index % pLevel_->GetTilesWide();
				srcRect.x = tileSheetCol * pLevel_->GetTileWidth();

				Uint16 tileSheetRow = index / pLevel_->GetTilesWide();
				srcRect.y = tileSheetRow * pLevel_->GetTileHeight();

				srcRect.w = pLevel_->GetTileWidth();
				srcRect.h = pLevel_->GetTileHeight();

				SDL_Rect dstRect;
				dstRect.x = (col * pLevel_->GetTileWidth()) - camera_.x;
				dstRect.y = (row * pLevel_->GetTileHeight()) - camera_.y;
				dstRect.w = pLevel_->GetTileWidth();
				dstRect.h = pLevel_->GetTileHeight();

				SDL_BlitSurface(pLevel_->GetTileSheet(), &srcRect, pDisplay_, &dstRect);
			}
		}
	}
}

void ExampleGame::draw()
{
	drawLevel();
	pTestSprite_->Draw(pDisplay_);
	Game::draw();
}

void ExampleGame::onKeyDown(Uint16 key)
{
	pTestSprite_->OnKeyDown(key);
}

void ExampleGame::onKeyUp(Uint16 key)
{
	pTestSprite_->OnKeyUp(key);
}