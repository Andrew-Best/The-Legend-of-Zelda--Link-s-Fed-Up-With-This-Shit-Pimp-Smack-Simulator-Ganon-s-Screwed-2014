#pragma once
#include "Character.h"

class Player : public Character
{
protected:
	const char* RUN_LEFT_ANIM;
	const char* RUN_RIGHT_ANIM;
	const char* JUMP_LEFT_ANIM;
	const char* JUMP_RIGHT_ANIM;
	const char* WALK_LEFT_ANIM;
	const char* WALK_RIGHT_ANIM;
	const char* ATTACK_LEFT_ANIM;
	const char* ATTACK_RIGHT_ANIM;
	const char* FACE_LEFT;
	const char* FACE_RIGHT;

	const float ACCEL; //player acceleration in pixels per second per second
	const float EPSILON;
	const float JUMP_POWER;
	const float GRAVITY;

	bool facingLeft_ = false;
	bool facingRight_ = true;

	Vec2 inputDir_;

	void updateCurrAnim();
	bool jump();
	bool grounded_ = true;

public:
	//Player(Vec2 pos) : Character(PLAYER, pos){}
	Player(const Vec2& pos) : Character(pos), RUN_LEFT_ANIM("RunLeft"), RUN_RIGHT_ANIM("RunRight"), JUMP_LEFT_ANIM("JumpLeft"), JUMP_RIGHT_ANIM("JumpRight"),
		WALK_LEFT_ANIM("WalkLeft"), WALK_RIGHT_ANIM("WalkRight"), ATTACK_LEFT_ANIM("AttackLeft"), ATTACK_RIGHT_ANIM("AttackRight"), FACE_LEFT("FaceLeft"),
		FACE_RIGHT("FaceRight"), ACCEL(100.0f), EPSILON(0.0001f), JUMP_POWER(500.0f), GRAVITY(0.98f)
	{
		inputDir_ = Vec2();
		LoadCharacter();
	}

	~Player(){}

	//Overrides LoadCharacter so that is always loads player data
	virtual void LoadCharacter(CharacterType type)
	{
		Character::LoadCharacter(CharacterType::PLAYER);
	}

	void LoadCharacter()
	{
		Character::LoadCharacter(Character::PLAYER);
	}

	virtual void OnKeyDown(Uint16 key);
	virtual void OnKeyUp(Uint16 key);

	virtual void Update(float deltaTime);
};

