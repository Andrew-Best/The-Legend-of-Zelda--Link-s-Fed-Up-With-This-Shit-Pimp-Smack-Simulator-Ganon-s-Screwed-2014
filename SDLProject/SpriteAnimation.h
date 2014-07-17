#pragma once
#include "Sprite.h"
#include <map>
#include <string>

class SpriteAnimation : public Sprite
{
public:
	struct AnimationData
	{
		Uint16 startFrame;
		float frameRate;
		Uint16 numFrames;
	};

protected:
	std::map<std::string, AnimationData> anims_;

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
	void initAnim();

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

	void SetCurrAnim(std::string animation, Uint16 currFrame = 0)
	{
		AnimationData newAnim = anims_[animation];
		frameRate_ = newAnim.frameRate;
		startFrame_ = newAnim.startFrame;
		numFrames_ = newAnim.numFrames;
		currFrame_ = currFrame;
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

