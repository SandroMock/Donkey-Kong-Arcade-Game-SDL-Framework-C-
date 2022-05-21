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
#include "FlameLadderColl.h"
#include "LadderCollision.h"
#include "PhysicsConfig.h"


/*****************************************************************************/
//Abfrage aller möglichen Leiterkollisionen für Flammen
/*****************************************************************************/
bool IsFlameLadderColl( CFlame& _gameObj, CLevel& _level )
{
	bool bIsLadder = false;

	bIsLadder = IsLadderIdx( LDR_4_IDX, LDR_19_LAST_IDX, _gameObj, _level,
							 FL_LDR_TL_X_IDX, -FL_LDR_TL_Y_IDX, 
							 FL_LDR_BR_X_IDX );
	if( bIsLadder == true ) return true;

	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Leiterkollision für Flammen
/*****************************************************************************/
void UseFlameLadder( CFlame& _gameObj, CLevel& _level, bool _isActive )
{
	if( _isActive == true )
	{
		_gameObj.SetLadderColl( IsFlameLadderColl( _gameObj, _level ) );
	}
}
/*****************************************************************************/