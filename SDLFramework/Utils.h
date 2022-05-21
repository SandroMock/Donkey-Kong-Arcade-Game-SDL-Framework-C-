/*****************************************************************************
* Project: SDLFramework
* File   : Utils.h
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
#pragma once
#include <SDL.h>
#include <string>
#include "types.h"
#include "Defines.h"

template <class T>
T Lesser( T _value1, T _value2 )
{
	return (_value1 < _value2) ? _value1 : _value2;
}

bool IsPointInRect( SDL_Point _pt, Rect _rc );

std::string FormatToStringWithZeros(int _value, int _digits = 6);

const std::string SZ_ZERO_FORMAT = "0";
const int I_ZERO_POSITION = 0;