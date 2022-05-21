/*****************************************************************************
* Project: SDLFramework
* File   : BarrelLadderColl.h
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
#include "Barrel.h"
#include "Level.h"


/*****************************************************************************/
//Fass-Leiter-Kollision
/*****************************************************************************/
bool IsBarrelLadderColl2( CBarrel& _gameObj, CLevel& _level );
bool IsBarrelLadderColl3( CBarrel& _gameObj, CLevel& _level );
bool IsBarrelLadderColl4( CBarrel& _gameObj, CLevel& _level );
bool IsBarrelLadderColl5( CBarrel& _gameObj, CLevel& _level );
bool IsBarrelLadderColl6( CBarrel& _gameObj, CLevel& _level );

bool AreAllBarrelLadderColls( CBarrel& _gameObj, CLevel& _level );

void UseBarrelLadder( CBarrel& _gameObj, CLevel& _level,
					  bool _isActive = true );
/*****************************************************************************/