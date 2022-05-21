/*****************************************************************************
* Project: SDLFramework
* File   : Overlap.h
* Date   : 28.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	28.02.20	MS	Created, Box-Box-Überlappung entfernt
*	29.02.20	MS	Funktion mit CCircCollObject als Parameter erstellt und
*					CBarrel & CFlame-Funktionen entfernt
*	01.03.20	MS	CPlayer-Funktionen entfernt
*	03.03.20	MS	_setCirclePos als Parameter entfernt
******************************************************************************/
#pragma once
#include "Collision.h"
#include "CircCollObject.h"
#include "Level.h"

/*****************************************************************************/
//Überlappungen
/*****************************************************************************/
//Collider-Überlappung
bool IsCircRectOverlap( CCircleCollider& _pCircleColl,
						CBoxCollider& _pBoxColl );

//Überlappung mit Plattform
float IsPlatformOverlap( int _arBegin, int _arEnd, CCircCollObject& _gameObj,
						 CLevel& _level, STAGE _stage );

//Überlappung mit Ebene
float IsStageOverlap( CCircCollObject& _gameObj, CLevel& _level, 
					  STAGE _stage );
/*****************************************************************************/


/*****************************************************************************/
//Schräg hochgehen
/*****************************************************************************/
void MoveUpAngle( CCircCollObject& _gameObj, CLevel& _level, STAGE _stage,
				  bool _isActive = true );
/*****************************************************************************/