#pragma once

#include <Windows.h>
#include <xnamath.h>

struct Vec2
{
	float x, y;

	Vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2 operator + (const Vec2& rhs)
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}

	Vec2 operator - (const Vec2& rhs)
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}

	Vec2 operator * (const Vec2& rhs)
	{
		return Vec2(x * rhs.x, y * rhs.y);
	}

	Vec2 operator / (const Vec2& rhs)
	{
		return Vec2(x / rhs.x, y / rhs.y);
	}

	void operator += (const Vec2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
	}

	void operator -= (const Vec2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
	}

	Vec2 operator *= (const float& rhs)
	{
		x *= rhs;
		y *= rhs;
	}

	Vec2 operator /= (const float& rhs)
	{
		x /= rhs;
		y /= rhs;
	}

};

class VectorMath
{
public:
	VectorMath();
	~VectorMath();

	static Vec2 Normalize(const Vec2* vec);
	static float Magnitude(const Vec2* vec);
};
