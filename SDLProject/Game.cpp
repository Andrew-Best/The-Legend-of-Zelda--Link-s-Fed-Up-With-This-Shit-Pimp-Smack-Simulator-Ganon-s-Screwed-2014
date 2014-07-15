#include <iostream>
#include "Game.h"

const Uint8 CLEAR_RED = 0;
const Uint8 CLEAR_GREEN = 0;
const Uint8 CLEAR_BLUE = 0;

Game::Game(void) : pDisplay_(0), SCREEN_WIDTH(1024), SCREEN_HEIGHT(768), running_(true)
{}


Game::~Game(void)
{}

void Game::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << stderr << "Unable to init SDL: %s\n" << SDL_GetError();
		exit(1);
	}
	pDisplay_ = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	clearColour_ = SDL_MapRGB(pDisplay_->format, CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE);

	loadAssets();
}

void Game::Run()
{
	LARGE_INTEGER currTime, prevTime, frequency;
	float deltaTime = 0.0f;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&prevTime);

	SDL_Event newEvent;
	while (running_)
	{		
		while (SDL_PollEvent(&newEvent))
		{
			handleEvent(newEvent);
		}

		QueryPerformanceCounter(&currTime);
		deltaTime = (float)(currTime.QuadPart - prevTime.QuadPart) / (float)frequency.QuadPart;
		prevTime = currTime;

		update(deltaTime);

		clearBackBuffer();
		draw();
	}
}

void Game::clearBackBuffer()
{
	SDL_FillRect(pDisplay_, &pDisplay_->clip_rect, clearColour_);
}

void Game::draw()
{
	SDL_Flip(pDisplay_);
}

void Game::Clean()
{
	SDL_Quit();
}

void Game::handleEvent(const SDL_Event& newEvent)
{
	switch (newEvent.type)
	{
	case SDL_QUIT:
		running_ = false;
		break;
	case SDL_KEYDOWN:
		onKeyDown(newEvent.key.keysym.sym);
		break;
	case SDL_KEYUP:
		onKeyUp(newEvent.key.keysym.sym);
		break;
	}
}

void Game::onKeyDown(Uint16 key)
{
	switch (key)
	{
	case SDLK_ESCAPE:
		running_ = false;
		break;
	case SDLK_LEFT:
		//vx += 1.0f;
		isAttacking_ = false;
		isFacingLeft_ = false;
		isRunningLeft_ = true;
		isFacingRight_ = false;
		isRunningRight_ = false;
		break;
	case SDLK_RIGHT:
		//vx -= 1.0f;
		isAttacking_ = false;
		isFacingLeft_ = false;
		isRunningLeft_ = false;
		isFacingRight_ = false;
		isRunningRight_ = true;
		break;
	case SDLK_UP:
		//jump
		//if on door, enter door, restart game
		isJumping_ = true;
		break;
	case SDLK_LSHIFT:
		//accelerate
		break;
	case SDLK_SPACE:
		//attack
		isAttacking_ = true;
		break;
	case SDLK_DOWN:
		isJumping_ = false;
		break;
	}
}

void Game::onKeyUp(Uint16 key)
{
	//Cancel velocity, end attack
	if(isRunningRight_)
	{
		if (isAttacking_)
		{
			isAttacking_ = false;
			isRunningRight_ = false;
			isFacingRight_ = true;
		}
		else if (isJumping_)
		{
			isJumping_ = false;
			isRunningRight_ = false;
			isFacingRight_ = true;
		}
		else
		{
			isFacingRight_ = true;
			isRunningRight_ = false;
		}
	}
	if(isRunningLeft_)
	{
		if (isAttacking_)
		{
			isAttacking_ = false;
			isRunningLeft_ = false;
			isFacingLeft_ = true;
		}
		else if (isJumping_)
		{
			isJumping_ = false;
			isRunningLeft_ = false;
			isFacingLeft_ = true;
		}
		else
		{
			isFacingLeft_ = true;
			isRunningLeft_ = false;
		}
	}
}