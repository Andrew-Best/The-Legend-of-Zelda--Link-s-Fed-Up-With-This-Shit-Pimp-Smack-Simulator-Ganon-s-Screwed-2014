#pragma once

#include <fstream>
#include "MathUtils.h"
#include "SpriteAnimation.h"
#include "SDL_image.h"

class Character : public SpriteAnimation
{
public:
	enum CharacterType
	{
		PLAYER,
		GRIM_REAPER
	};

protected:
	Vec2 velocity_;

	void processDataFile(std::ifstream& file);


public:
	Character(CharacterType type, const Vec2& pos);
	Character(const Vec2& pos){ pos_ = pos; }
	virtual void LoadCharacter(CharacterType type);
	virtual ~Character(void);
};