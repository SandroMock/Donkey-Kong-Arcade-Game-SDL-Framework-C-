/*****************************************************************************
* Project: SDLFramework
* File   : PlayerLadderColl.h
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
*	04.03.20	MS	_isActive als Parameter entfernt
******************************************************************************/
#pragma once
#include "Player.h"
#include "Level.h"



/*****************************************************************************/
//Spieler-Leiter-Kollision
/*****************************************************************************/
//unteres Leiterende
bool IsSmallLdrColl( CPlayer& _gameObj, CLevel& _level );
bool IsLargeLdrColl( CPlayer& _gameObj, CLevel& _level );

void UseLargeLadders( CPlayer& _gameObj, CLevel& _level);
void UseSmallLadders( CPlayer& _gameObj, CLevel& _level );


//oberes Leiterende
bool IsLargeLdrPlColl( CPlayer& _gameObj, CLevel& _level );
bool IsSmallLdrPlColl( CPlayer& _gameObj, CLevel& _level );

void UseLargeLadderPlatforms( CPlayer& _gameObj, CLevel& _level);
void UseSmallLadderPlatforms( CPlayer& _gameObj, CLevel& _level);
/*****************************************************************************/