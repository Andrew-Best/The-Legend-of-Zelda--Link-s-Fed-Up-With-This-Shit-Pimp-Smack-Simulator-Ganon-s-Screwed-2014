#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "MathUtils.h"

class Game
{
protected:
	SDL_Surface* pDisplay_; // main frame buffer

	const Uint16 SCREEN_WIDTH;
	const Uint16 SCREEN_HEIGHT;

	void clearBackBuffer();
	void handleEvent(const SDL_Event& newEvent);

	virtual void loadAssets() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw();
	virtual void onKeyDown(Uint16 key);
	virtual void onKeyUp(Uint16 key);

	bool running_;

	Uint32 clearColour_;
	

public:
	Game(void);
	~Game(void);

	void InitSDL();
	void Run();
	void Clean();
};