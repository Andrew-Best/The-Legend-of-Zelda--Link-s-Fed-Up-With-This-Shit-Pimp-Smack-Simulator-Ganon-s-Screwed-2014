#include "SpriteAnimation.h"
#include <cmath>

SpriteAnimation::SpriteAnimation() : Sprite(), frameWidth_(0), frameHeight_(0), numFrames_(0), startFrame_(0), currFrame_(0), frameRate_(0.0f), 
									 frameTimer_(0.0f), framesWide_(0), framesHigh_(0), isLooped_(false), isPlaying_(false)
{

}
SpriteAnimation::SpriteAnimation(SDL_Surface* image, const Vec2& pos, SDL_Rect srcRect, Uint8 alpha, Uint16 frameWidth, Uint16 frameHeight, 
	Uint16 startFrame, Uint16 numFrames, float frameRate) : Sprite(image, pos, srcRect, alpha), frameWidth_(frameWidth), frameHeight_(frameHeight), 
	numFrames_(numFrames), startFrame_(startFrame), frameRate_(frameRate)
{
	framesWide_ = pImage_->w / frameWidth;
	framesHigh_ = pImage_->h / frameHeight;
	updateSrcFrame();
}


SpriteAnimation::~SpriteAnimation()
{
}

void SpriteAnimation::Update(float deltaTime)
{
	if (isPlaying_)
	{
		frameTimer_ += deltaTime;
		if (frameTimer_ > frameRate_)
		{
			frameTimer_ -= frameRate_;
			currFrame_++;
			if (currFrame_ >= numFrames_)
			{
				currFrame_ = 0;
				if (!isLooped_)
				{
					isPlaying_ = false;
				}
			}
			updateSrcFrame();
		}
	}
}

void SpriteAnimation::updateSrcFrame()
{
	Uint16 absIndex = startFrame_ + currFrame_;
	srcRect_.x = (absIndex % framesWide_) * frameWidth_;
	srcRect_.y = floor(absIndex / framesWide_) * frameHeight_;

	srcRect_.w = frameWidth_;
	srcRect_.h = frameHeight_;
}