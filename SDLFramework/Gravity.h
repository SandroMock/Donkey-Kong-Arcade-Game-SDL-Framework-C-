/*****************************************************************************
* Project: SDLFramework
* File   : Gravity.h
* Date   : 26.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	26.02.20	MS	Created, Benennung von UseGravityPhysics zu IsFalling,
*					Benennung von selektiver Schwerkraft zu UseGravity,
*	28.02.20	MS	Inkludiert nicht mehr Schwerkraft
*					Vorinitialisierung für Parameter von IsFalling entfernt
*	29.02.20	MS	Funktion mit CCircCollObject als Parameter erstellt und
*					CBarrel & CFlame-Funktionen entfernt
*	01.03.20	MS	CPlayer-Funktionen entfernt
*	03.03.20	MS	_setCirclePos als Parameter entfernt,
*					Ins Reine geschrieben, inkludiert nicht mehr Player.h,
*					inkludiert GameObject.h & CircCollObject
******************************************************************************/
#pragma once
#include "GameObject.h"
#include "CircCollObject.h"
#include "Level.h"

const float F_DEFAULT_SPEED = 100.0f;
/*****************************************************************************/
// Runterfallen
/*****************************************************************************/
bool IsFalling( CGameObject& _gameObj, bool _isGravity, float _speed );
/*****************************************************************************/

/*****************************************************************************/
// Schwerkraft
/*****************************************************************************/
bool UseGravity( CCircCollObject& _pCollObj, CLevel& _pLevel, STAGE _stage,
				 float _speed = F_DEFAULT_SPEED, bool _isActive = true );
/*****************************************************************************/