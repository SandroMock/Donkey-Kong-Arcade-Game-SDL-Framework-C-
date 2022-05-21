/*****************************************************************************
* Project: SDLFramework
* File   : types.h
* Date   : ??.??.20??
* Author : Ralf Hüwe (RH)
*		   Marcus Schaal (MS)		
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	??.??.??	RH	Created
*	02.03.20	MS	Distanz und RectToSDLRect entfernt
******************************************************************************/
#pragma once
#include <cmath>

struct Point
{
	int x;
	int y;
};

struct Vector
{
	float x;
	float y;
	float len;

	Vector( float _x, float _y )
	{
		x = _x; 
		y = _y;
		len = CalcLength();
	}

	Vector operator*( float _scalar )
	{
		return Vector( x * _scalar, y * _scalar );
	}

	void Normalize()
	{
		len = CalcLength();
		x /= len;
		y /= len;
		len = CalcLength();
	}

	float CalcLength()
	{
		// c = squareroot(x²+y²) , squareroot=Quadratwurzel
		return static_cast<float>( sqrt( x * x + y * y ) );
	}
};

struct Rect
{
	Point topLeft;
	Point bottomRight;
};


// RectToSDLRect von Marcus Schaal entfernt

struct Circle
{
	Vector position = { -1, -1 };
	float radius = -1.0f;

	//Distance von Marcus Schaal entfernt
};