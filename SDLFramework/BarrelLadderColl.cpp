/*****************************************************************************
* Project: SDLFramework
* File   : BarrelLadderColl.cpp
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
#include "BarrelLadderColl.h"
#include "LadderCollision.h"
#include "PhysicsConfig.h"

/*****************************************************************************/
//Abfrage aller möglichen Leiterkollisionen für Fässer (2. Platform)
/*****************************************************************************/
bool IsBarrelLadderColl2( CBarrel& _gameObj, CLevel& _level )
{
	bool bIsLadder = false;


	bIsLadder = IsPlatformIdxLHalf( PL_2_BLDR_1ST_IDX, PL_2_BLDR_LAST_IDX, 
									_gameObj, _level, PL_2_BLDR_TL_X_IDX, 
									PL_2_BLDR_TL_Y_IDX, PL_2_BLDR_BR_X_IDX, 
									PL_2_BLDR_BR_Y_IDX );
	if( bIsLadder == true ) return true;

	bIsLadder = IsPlatformIdxRHalf( PL_2_SLDR_1ST_IDX, PL_2_SLDR_LAST_IDX,
									_gameObj, _level, PL_2_SLDR_TL_X_IDX );
	if( bIsLadder == true ) return true;


	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Abfrage aller möglichen Leiterkollisionen für Fässer (3. Platform)
/*****************************************************************************/
bool IsBarrelLadderColl3( CBarrel& _gameObj, CLevel& _level )
{
	bool bIsLadder = false;


	bIsLadder = IsPlatformIdxLHalf( PL_3_SLDR_1ST_IDX, PL_3_SLDR_LAST_IDX,
									_gameObj, _level, PL_3_SLDR_TL_X_IDX, 
									PL_3_SLDR_TL_Y_IDX, PL_3_SLDR_BR_X_IDX );
	if( bIsLadder == true ) return true;

	bIsLadder = IsPlatformIdxRHalf( PL_3_LLDR_1ST_IDX, PL_3_LLDR_LAST_IDX, 
									_gameObj, _level, PL_3_LLDR_TL_X_IDX, 
									PL_3_LLDR_TL_Y_IDX, PL_3_LLDR_BR_X_IDX, 
									PL_3_LLDR_BR_Y_IDX );
	if( bIsLadder == true ) return true;

	bIsLadder = IsPlatformIdxRHalf( PL_3_BLDR_1ST_IDX, PL_3_BLDR_LAST_IDX, 
									_gameObj, _level, PL_3_BLDR_TL_X_IDX, 
									PL_3_BLDR_TL_Y_IDX, PL_3_BLDR_BR_X_IDX, 
									PL_3_BLDR_BR_Y_IDX );
	if( bIsLadder == true ) return true;


	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Abfrage aller möglichen Leiterkollisionen für Fässer (4. Platform)
/*****************************************************************************/
bool IsBarrelLadderColl4( CBarrel & _gameObj, CLevel & _level )
{
	bool bIsLadder = false;


	bIsLadder = IsPlatformIdxLHalf( PL_4_BLDR_1ST_IDX, PL_4_BLDR_LAST_IDX, 
									_gameObj, _level, PL_4_BLDR_TL_X_IDX, 
									PL_4_BLDR_TL_Y_IDX, PL_4_BLDR_BR_X_IDX, 
									PL_4_BLDR_BR_Y_IDX );
	if( bIsLadder == true ) return true;

	bIsLadder = IsPlatformIdxLHalf( PL_4_LLDR_1ST_IDX, PL_4_LLDR_LAST_IDX, 
									_gameObj, _level, PL_4_LLDR_TL_X_IDX, 
									PL_4_LLDR_TL_Y_IDX, PL_4_LLDR_BR_X_IDX, 
									PL_4_LLDR_BR_Y_IDX );
	if( bIsLadder == true ) return true;

	bIsLadder = IsPlatformIdxRHalf( PL_4_SLDR_1ST_IDX, PL_4_SLDR_LAST_IDX, 
									_gameObj, _level, PL_4_SLDR_TL_X_IDX );
	if( bIsLadder == true ) return true;


	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Abfrage aller möglichen Leiterkollisionen für Fässer (5. Platform)
/*****************************************************************************/
bool IsBarrelLadderColl5( CBarrel & _gameObj, CLevel & _level )
{
	bool bIsLadder = false;


	bIsLadder = IsPlatformIdxLHalf( PL_5_SLDR_1ST_IDX, PL_5_SLDR_LAST_IDX, 
									_gameObj, _level, PL_5_SLDR_TL_X_IDX, 
									PL_5_SLDR_TL_Y_IDX, PL_5_SLDR_BR_X_IDX );
	if( bIsLadder == true ) return true;

	bIsLadder = IsPlatformIdxLHalf( PL_5_LLDR_1ST_IDX, PL_5_LLDR_LAST_IDX, 
									_gameObj, _level, PL_5_LLDR_TL_X_IDX, 
									PL_5_LLDR_TL_Y_IDX, PL_5_LLDR_BR_X_IDX, 
									PL_5_LLDR_BR_Y_IDX );
	if( bIsLadder == true ) return true;


	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Abfrage aller möglichen Leiterkollisionen für Fässer (6. Platform)
/*****************************************************************************/
bool IsBarrelLadderColl6( CBarrel & _gameObj, CLevel & _level )
{
	bool bIsLadder = false;


	bIsLadder = IsPlatformIdxLHalf( PL_6_BLDR_1ST_IDX, PL_6_BLDR_LAST_IDX, 
									_gameObj, _level, PL_6_BLDR_TL_X_IDX,
									PL_6_BLDR_TL_Y_IDX, PL_6_BLDR_BR_X_IDX, 
									PL_6_BLDR_BR_Y_IDX );
	if( bIsLadder == true ) return true;

	bIsLadder = IsPlatformIdxRHalf( PL_6_SLDR_1ST_IDX, PL_6_SLDR_LAST_IDX, 
									_gameObj, _level, PL_6_SLDR_TL_X_IDX );
	if( bIsLadder == true ) return true;


	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Abfrage aller möglichen Leiterkollisionen für Fässer (alle Fässer)
/*****************************************************************************/
bool AreAllBarrelLadderColls( CBarrel& _gameObj, CLevel& _level )
{
	if( IsBarrelLadderColl2(_gameObj, _level) == true ) return true;
	else if( IsBarrelLadderColl3(_gameObj, _level) == true ) return true;
	else if( IsBarrelLadderColl4(_gameObj, _level) == true ) return true;
	else if( IsBarrelLadderColl5(_gameObj, _level) == true ) return true;
	else if( IsBarrelLadderColl6(_gameObj, _level) == true ) return true;
	else return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Leiterkollision für Fässer
/*****************************************************************************/
void UseBarrelLadder( CBarrel& _gameObj, CLevel& _level, bool _isActive )
{
	if( _isActive == true )
	{
		_gameObj.SetLadderColl( AreAllBarrelLadderColls( _gameObj, _level ) );
	}
}
/*****************************************************************************/