#pragma once
#include "Sprite.h"

class SpriteAnimation : public Sprite
{
protected:
	Uint16 numFrames_;
	Uint16 currFrame_;
	Uint16 startFrame_;

	Uint16 framesWide_;
	Uint16 framesHigh_;
	Uint16 frameWidth_;
	Uint16 frameHeight_;
	
	float frameRate_;
	float frameTimer_;

	bool isLooped_;
	bool isPlaying_;

	void updateSrcFrame(); //recalculate the srcRect_ based on the current frame

public:
	SpriteAnimation();
	SpriteAnimation(SDL_Surface* image, const Vec2& pos, SDL_Rect srcRect, Uint8 alpha, Uint16 frameWidth, Uint16 frameHeight, Uint16 startFrame, Uint16 numFrames, float frameRate);
	virtual ~SpriteAnimation();

	void Update(float deltaTime); // keeps track of time and switches frames

	void Play(bool looped)
	{
		isLooped_ = looped;
		isPlaying_ = true;
	}

	void Pause()
	{
		isPlaying_ = false;
	}

	void Stop()
	{
		isPlaying_ = false;
		currFrame_ = 0;
	}

	void SetStartFrame(Uint16 startFrame)
	{
		startFrame_ = startFrame;
	}

	//frameIndex is the absolute frame index (not relative to startFrame)
	void JumpToFrame(Uint16 frameIndex)
	{
		//absFrame = startFrame + currFrame
		if (frameIndex < 0)
		{
			currFrame_ = 0;
		}
		else if (frameIndex >= numFrames_)
		{
			currFrame_ = numFrames_ - 1;
		}
		else
		{
			currFrame_ = 0;
		}
	}

	void SetNumFrames(Uint16 numFrames)
	{
		numFrames_ = numFrames;
	}

	Uint16 GetWidth()
	{
		return frameWidth_;
	}

	Uint16 GetHeight()
	{
		return frameHeight_;
	}

	Uint16 GetCurrFrame()
	{
		return currFrame_;
	}

	bool GetIsPlaying()
	{
		return isPlaying_;
	}

	bool GetIsLooped()
	{
		return isLooped_;
	}
};

