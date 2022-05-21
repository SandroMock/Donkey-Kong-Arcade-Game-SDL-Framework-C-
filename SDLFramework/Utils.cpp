/*****************************************************************************
* Project: SDLFramework
* File   : Utils.cpp
* Date   : ??.??.20??
* Author : Ralf Hüwe (RH)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	??.??.??	RH	Created
******************************************************************************/
#include "Utils.h"

bool IsPointInRect( SDL_Point _pt, Rect _rc )
{
	if( _pt.x < _rc.topLeft.x ) return false;
	if( _pt.x > _rc.bottomRight.x ) return false;
	if( _pt.y < _rc.topLeft.y ) return false;
	if( _pt.y > _rc.bottomRight.y ) return false;

	return true;
}

std::string FormatToStringWithZeros(int _value, int _digits) {
	std::string *s = new std::string(std::to_string(_value));

	int zeros = _digits - s->length();

	for (int i = I_ZERO; i < zeros; i++) {
		s->insert(I_ZERO_POSITION, SZ_ZERO_FORMAT);
	}

	std::string resolve = *s;

	if (s != nullptr) {
		s = nullptr;
		delete s;
	}

	return resolve.c_str();
}