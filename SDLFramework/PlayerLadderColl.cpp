/*****************************************************************************
* Project: SDLFramework
* File   : PlayerLadderColl.cpp
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
#include "PlayerLadderColl.h"
#include "LadderCollision.h"
#include "PhysicsConfig.h"



/*****************************************************************************/
//Abfrage aller möglichen unteren Enden kleinen Leiterkollisionen für Spieler
/*****************************************************************************/
bool IsSmallLdrColl( CPlayer& _gameObj, CLevel& _level )
{
	//bezieht die kaputten Leitern nicht mit ein!
	bool bIsLadder = false;


	//Leiter 6
	bIsLadder = IsLadderIdx( LDR_6_PENULT_IDX, LDR_6_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y, 
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//Leiter 7
	bIsLadder = IsLadderIdx( LDR_7_PENULT_IDX, LDR_7_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y,
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//Leiter 14 
	bIsLadder = IsLadderIdx( LDR_14_PENULT_IDX, LDR_14_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y,
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//Leiter 15
	bIsLadder = IsLadderIdx( LDR_15_PENULT_IDX, LDR_15_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y,
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//Leiter 19
	bIsLadder = IsLadderIdx( LDR_19_PENULT_IDX, LDR_19_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y,
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Abfrage aller möglichen unteren Enden großen Leiterkollisionen für Spieler
/*****************************************************************************/
bool IsLargeLdrColl( CPlayer& _gameObj, CLevel& _level )
{
	//bezieht die kaputten Leitern nicht mit ein!
	bool bIsLadder = false;


	//Leiter 3
	bIsLadder = IsLadderIdx( LDR_3_PENULT_IDX, LDR_3_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y,
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//Leiter 8
	bIsLadder = IsLadderIdx( LDR_8_PENULT_IDX, LDR_8_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y,
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//Leiter 13
	bIsLadder = IsLadderIdx( LDR_13_PENULT_IDX, LDR_13_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y,
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//Leiter 16
	bIsLadder = IsLadderIdx( LDR_16_PENULT_IDX, LDR_16_LAST_IDX, _gameObj,
							 _level, I_LOW_LDR_TL_X, I_LOW_LDR_TL_Y,
							 I_LOW_LDR_BR_X );
	if( bIsLadder == true ) return true;

	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Leiterkollision für untere Enden große Leitern
/*****************************************************************************/
void UseLargeLadders( CPlayer& _gameObj, CLevel& _level)
{
	_gameObj.SetPlayerCollidesWithLargeLadder( IsLargeLdrColl( _gameObj,
															   _level ) );
}
/*****************************************************************************/

/*****************************************************************************/
//Leiterkollision für untere Enden kleine Leitern
/*****************************************************************************/
void UseSmallLadders( CPlayer& _gameObj, CLevel& _level )
{
	_gameObj.SetPlayerCollidesWithSmallLadder(IsSmallLdrColl( _gameObj,
															  _level ) );
}
/*****************************************************************************/

/*****************************************************************************/
//Abfrage aller möglichen oberen Enden großen Leiterkollisionen für Spieler
/*****************************************************************************/
bool IsLargeLdrPlColl( CPlayer& _gameObj, CLevel& _level )
{
	//Plattformen über Leitern
	//bezieht die kaputten Leitern nicht mit ein!
	bool bIsLadder = false;


	//1. Plattform
	bIsLadder = IsPlatformIdxRHalf( PL_1_PENULT_IDX, PL_1_LAST_IDX, 
									_gameObj, _level, I_RPL_LDR_TL_X, 
									I_RPL_LDR_TL_Y, I_RPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//3. Plattform
	bIsLadder = IsPlatformIdxRHalf( PL_3_LLDR_1ST_IDX, PL_3_LLDR_LAST_IDX, 
									_gameObj, _level, I_RPL_LDR_TL_X,
									I_RPL_LDR_TL_Y, I_RPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//4. Plattform
	bIsLadder = IsPlatformIdxLHalf( PL_4_LLDR_1ST_IDX, PL_4_LLDR_LAST_IDX, 
									_gameObj, _level, I_LPL_LDR_TL_X, 
									I_LPL_LDR_TL_Y, I_LPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//5. Plattform
	bIsLadder = IsPlatformIdxLHalf( PL_5_LLDR_1ST_IDX, PL_5_LLDR_LAST_IDX, 
									_gameObj, _level, I_LPL_LDR_TL_X,
									I_LPL_LDR_TL_Y, I_LPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Abfrage aller möglichen oberen Enden kleinen Leiterkollisionen für Spieler
/*****************************************************************************/
bool IsSmallLdrPlColl( CPlayer& _gameObj, CLevel& _level )
{
	//Plattformen über Leitern
	//bezieht die kaputten Leitern nicht mit ein!
	bool bIsLadder = false;


	//2. Platform
	bIsLadder = IsPlatformIdxRHalf( PL_2_SLDR_1ST_IDX, PL_2_SLDR_LAST_IDX, 
									_gameObj, _level, I_RPL_LDR_TL_X,
									I_RPL_LDR_TL_Y, I_RPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//3. Platform
	bIsLadder = IsPlatformIdxLHalf( PL_3_SLDR_1ST_IDX, PL_3_SLDR_LAST_IDX, 
									_gameObj, _level, I_LPL_LDR_TL_X,
									I_LPL_LDR_TL_Y, I_LPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//4. Platform
	bIsLadder = IsPlatformIdxRHalf( PL_4_SLDR_1ST_IDX, PL_4_SLDR_LAST_IDX, 
									_gameObj, _level, I_RPL_LDR_TL_X,
									I_RPL_LDR_TL_Y, I_RPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//5. Platform
	bIsLadder = IsPlatformIdxLHalf( PL_5_SLDR_1ST_IDX, PL_5_SLDR_LAST_IDX, 
									_gameObj, _level, I_LPL_LDR_TL_X,
									I_LPL_LDR_TL_Y, I_LPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	//6. Platform
	bIsLadder = IsPlatformIdxRHalf( PL_6_SLDR_1ST_IDX, PL_6_SLDR_LAST_IDX, 
									_gameObj, _level, I_RPL_LDR_TL_X,
									I_RPL_LDR_TL_Y, I_RPL_LDR_BR_X );
	if( bIsLadder == true ) return true;

	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Leiterkollision für obere Enden großer Leitern
/*****************************************************************************/
void UseLargeLadderPlatforms( CPlayer& _gameObj, CLevel& _level)
{
	_gameObj.SetPlayerLadderPlatformLarge( IsLargeLdrPlColl( _gameObj,
															 _level ) );
}
/*****************************************************************************/

/*****************************************************************************/
//Leiterkollision für obere Enden kleine Leitern
/*****************************************************************************/
void UseSmallLadderPlatforms( CPlayer& _gameObj, CLevel& _level)
{
	_gameObj.SetPlayerLadderPlatformSmall( IsSmallLdrPlColl( _gameObj,
															 _level ) );
}
/*****************************************************************************/