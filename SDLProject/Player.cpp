#include "Player.h"

void Player::Update(float deltaTime)
{
	velocity_.x += inputDir_.x * ((ACCEL * deltaTime) * 0.9);
	pos_ += velocity_ * deltaTime;
	velocity_.y += inputDir_.y * 0.98;
	SpriteAnimation::Update(deltaTime);

	if (inputDir_.x > 0 && velocity_.x < 0 || inputDir_.x < 0 && velocity_.x > 0 || inputDir_.x == 0)
	{
		velocity_.x *= 0.5;
	}
	if (inputDir_.y > 0 && velocity_.y < 0 || inputDir_.y < 0 && velocity_.y > 0 || inputDir_.y == 0)
	{
		velocity_.y *= -GRAVITY;
	}
}

void Player::OnKeyDown(Uint16 key)
{
	switch(key)
	{
	case SDLK_UP:
	case SDLK_w:
		if (grounded_)
		{
			jump();
		}
		break;
	/*case SDLK_DOWN:
	case SDLK_s:
		inputDir_.y = 1.0f;
		break;*/
	case SDLK_RIGHT:
	case SDLK_d:
		inputDir_.x = 1.0f;
		break;
	case SDLK_LEFT:
	case SDLK_a:
		inputDir_.x = -1.0f;
		break;
	}

	inputDir_ = VectorMath::Normalize(&inputDir_);

	if (!isPlaying_)
	{
		Play(true);
	}

	updateCurrAnim();
}

void Player::OnKeyUp(Uint16 key)
{
	switch (key)
	{
	/*case SDLK_UP:
	case SDLK_w:
		if (inputDir_.y < -EPSILON)
		{
			inputDir_.y = 0.0f;
		}
		break;*/
	case SDLK_DOWN:
	case SDLK_s:
		if (inputDir_.y > EPSILON)
		{
			inputDir_.y = 0.0f;
		}
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		if (inputDir_.x > EPSILON)
		{
			inputDir_.x = 0.0f;
		}
		break;
	case SDLK_LEFT:
	case SDLK_a:
		if (inputDir_.x < -EPSILON)
		{
			inputDir_.x = 0.0f;
		}
		break;
	}
	updateCurrAnim();
}

bool Player::jump()
{
	if (grounded_)
	{
		grounded_ = false;
		velocity_.y = -JUMP_POWER;
		return true;
	}
	return false;
}

void Player::updateCurrAnim()
{
	if (inputDir_.x > EPSILON)
	{
		facingLeft_ = false;
		facingRight_ = true;
		SetCurrAnim(RUN_RIGHT_ANIM);
	}
	else if (inputDir_.x < -EPSILON)
	{
		facingLeft_ = true;
		facingRight_ = false;
		SetCurrAnim(RUN_LEFT_ANIM);
	}
	else if (inputDir_.y < -EPSILON)
	{
		SetCurrAnim(JUMP_RIGHT_ANIM);
	}
	else
	{
		if (facingLeft_)
		{
			SetCurrAnim(FACE_LEFT);
		}
		else
		{
			SetCurrAnim(FACE_RIGHT);
		}
	}
}