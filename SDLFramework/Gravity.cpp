/*****************************************************************************
* Project: SDLFramework
* File   : Gravity.cpp
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
*	26.02.20	MS	Created
*	03.03.20	MS	Ins Reine geschrieben, Literale entfernt
******************************************************************************/
#include "Gravity.h"
#include "LadderCollision.h"



/*****************************************************************************/
//Schwerkraft + Abfrage
/*****************************************************************************/
bool IsFalling( CGameObject& _gameObj, bool _isGravity, float _speed )
{
	float speed = _speed * CEngine::GetDeltaTime();
	if ( _isGravity == false ) //Schwerkraft
	{
		_gameObj.IncPositionY( speed ); //Lässt Spieler fallen
		return true;
	}
	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Schwerkraft mit Kreis-Box-Kollision für einzelne Plattform-Ebenen
/*****************************************************************************/
bool UseGravity( CCircCollObject& _pCollObj, CLevel& _pLevel, STAGE _stage, 
				 float _speed, bool _isActive )
{
	if( _isActive == true )
	{
		bool isGravity = false;

		switch( _stage ) //Auswahl: Plattform-Ebene (von oben nach unten)
		{
		case STAGE_ELEM_ONE:
			isGravity = IsPlatformIdx( PL_1_1ST_IDX, PL_1_LAST_IDX, _pCollObj,
									  _pLevel );
			break;

		case STAGE_ELEM_TWO:
			isGravity = IsPlatformIdx( PL_2_1_1ST_IDX, PL_2_2_LAST_IDX, _pCollObj,
									  _pLevel );
			break;

		case STAGE_ELEM_THREE:
			isGravity = IsPlatformIdx( PL_3_1ST_IDX, PL_3_LAST_IDX, _pCollObj,
									  _pLevel );
			break;

		case STAGE_ELEM_FOUR:
			isGravity = IsPlatformIdx( PL_4_1ST_IDX, PL_4_LAST_IDX, _pCollObj,
									  _pLevel );
			break;

		case STAGE_ELEM_FIVE:
			isGravity = IsPlatformIdx( PL_5_1ST_IDX, PL_5_LAST_IDX, _pCollObj,
									  _pLevel );
			break;

		case STAGE_ELEM_SIX:
			isGravity = IsPlatformIdx( PL_6_1ST_IDX, PL_6_LAST_IDX, _pCollObj,
									  _pLevel );
			break;

		case STAGE_ELEM_SEVEN:
			isGravity = IsPlatformIdx( PL_7_1_1ST_IDX, PL_7_2_LAST_IDX, _pCollObj,
									  _pLevel );
			break;

		default:
			isGravity = IsPlatformIdx( PL_1_1ST_IDX, I_PL_AR_SIZE, _pCollObj,
									  _pLevel );
			break;
		}

		// Schwerkraft-Physik wird abgefragt
		// Flamme fällt wenn Schwerkraft falsch ist
		return IsFalling( _pCollObj, isGravity, _speed );
	}
	return false;
}
/*****************************************************************************/