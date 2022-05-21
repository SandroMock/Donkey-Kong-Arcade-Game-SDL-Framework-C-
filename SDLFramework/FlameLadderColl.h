/*****************************************************************************
* Project: SDLFramework
* File   : FlameLadderColl.h
* Date   : 03.03.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	03.03.20	MS	Created
******************************************************************************/
#pragma once
#include "Level.h"
#include "Flame.h"

//Flamme-Leiter-Kollision
bool IsFlameLadderColl( CFlame& _gameObj, CLevel& _level );
void UseFlameLadder( CFlame& _gameObj, CLevel& _level,
					 bool _isActive = true );