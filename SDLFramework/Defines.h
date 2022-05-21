/*****************************************************************************
* Project: SDLFramework
* File   : Defines.h
* Date   : ??.??.20??
* Author : Ralf Hüwe (RH)
*		   Marcus Schaal (MS)
*		   Niklas Englmeier (NE)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	??.??.??	RH	Created
*	04.02.2020	MS	Titel in Donkey Kong geändert
*	26.02.2020	NE	DEFAULT_FONT und DEFAULT_FONT_SIZE hinzugefügt
*	28.02.2020	NE	Added colors and savegame filename
******************************************************************************/
#pragma once

#define APP_TITLE "Donkey Kong"

#ifndef SAFE_DELETE 
#define SAFE_DELETE(x) {if(x!=nullptr) delete x; x=nullptr;}
#endif

#define FINALIZE_DELETE(x)	\
{							\
	if( (x) != nullptr )	\
	{						\
		(x)->Finalize();	\
		delete (x);			\
		(x) = nullptr;		\
	}						\
}

#define SAVEGAME_DIR			"savegame.txt"

#define DEFAULT_FONT			"Assets/kongtext.ttf"
#define DEFAULT_FONT_RESOLUTION	96

#define DEFAULT_BIG_FONT 30
#define DEFAULT_SMALL_FONT 25

#define CRED {255, 0, 0}
#define CGREEN {0, 255, 0}
#define CBLUE {0, 0, 255}

#define CTORQUOISE {0, 255, 255}
#define CYELLOW {255, 255, 0}

const int I_ZERO = 0;
const float F_TIMER_DEFAULT = 0.0f;
const int I_HALF = 2;
const int I_QUARTER = 4;