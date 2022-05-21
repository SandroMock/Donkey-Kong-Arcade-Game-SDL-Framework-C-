/*****************************************************************************
* Project: SDLFramework
* File   : LadderCollision.cpp
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
*	28.02.20	MS	Created
******************************************************************************/
#include "LadderCollision.h"
#include "Collision.h"
#include "PhysicsConfig.h"



/*****************************************************************************/
//Plattform-Array-Abfrage
/*****************************************************************************/
bool IsPlatformIdx( int _arBegin, int _arEnd, CCircCollObject& _gameObj, 
					CLevel & _level )
{
	for( int i = _arBegin; i < _arEnd; ++i )
	{
		if( IsCircRectColl( _gameObj.GetCollider(),
			_level.GetPlatformColl( i )) == true )
		{
			return true;
		}
	}
	return false;
}
/*****************************************************************************/


/*****************************************************************************/
//Plattform-Array-Abfrage (linke Hälfte) (Überladung)
/*****************************************************************************/
bool IsPlatformIdxLHalf( int _arBegin, int _arEnd, CCircCollObject& _gameObj, 
						 CLevel& _level, int _topLeftX, int _topLeftY, 
						 int _bottomRightX, int _bottomRightY )
{
	//Durch Parameter zu verändernder Collider für den jeweiligen Index
	CBoxCollider PlatformColl;  

	for( int i = _arBegin; i < _arEnd; ++i )
	{
		PlatformColl = _level.GetPlatformColl( i );

		PlatformColl.SetTopLeftX( PlatformColl.GetTopLeftX() + _topLeftX );

		PlatformColl.SetTopLeftY( PlatformColl.GetTopLeft().y + _topLeftY );

		PlatformColl.SetBottomRightX(    PlatformColl.GetBottomRightX() 
									  - (PlatformColl.GetWidth() / I_DOUBLE)
									  + _bottomRightX );

		PlatformColl.SetBottomRightY(   PlatformColl.GetBottomRight().y 
									  + _bottomRightY );


		if( IsCircRectColl( _gameObj.GetCollider(), PlatformColl ) == true )
		{
			return true;
		}
	}
	return false;
}
/*****************************************************************************/


/*****************************************************************************/
//Plattform-Array-Abfrage (rechte Hälfte)
/*****************************************************************************/
bool IsPlatformIdxRHalf( int _arBegin, int _arEnd, CCircCollObject& _gameObj, 
						 CLevel& _level, int _topLeftX, int _topLeftY, 
						 int _bottomRightX, int _bottomRightY )
{
	//Durch Parameter zu verändernder Collider für den jeweiligen Index
	CBoxCollider PlatformColl;

	for( int i = _arBegin; i < _arEnd; ++i )
	{
		PlatformColl = _level.GetPlatformColl( i );

		PlatformColl.SetTopLeftX(	PlatformColl.GetTopLeft().x 
								  + PlatformColl.GetWidth() + _topLeftX );

		PlatformColl.SetTopLeftY( PlatformColl.GetTopLeft().y + _topLeftY );

		PlatformColl.SetBottomRightX(   PlatformColl.GetBottomRightX() 
									  + _bottomRightX );

		PlatformColl.SetBottomRightY(   PlatformColl.GetBottomRight().y 
									  + _bottomRightY );

		if( IsCircRectColl( _gameObj.GetCollider(), PlatformColl ) == true )
		{
			return true;
		}
	}
	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Leiter-Array-Abfrage
/*****************************************************************************/
bool IsLadderIdx( int _arBegin, int _arEnd, CCircCollObject& _gameObj, 
				  CLevel& _level, int _topLeftX, int _topLeftY, 
				  int _bottomRightX, int _bottomRightY )
{
	//Durch Parameter zu verändernder Collider für den jeweiligen Index
	CBoxCollider LadderColl;

	for( int i = _arBegin; i < _arEnd; ++i )
	{
		LadderColl = _level.GetLadderColl( i );

		LadderColl.SetTopLeftX( LadderColl.GetTopLeftX() + _topLeftX );

		LadderColl.SetTopLeftY( LadderColl.GetTopLeft().y + _topLeftY );

		LadderColl.SetBottomRightX(   LadderColl.GetBottomRightX() 
									- _bottomRightX );

		LadderColl.SetBottomRightY(   LadderColl.GetBottomRight().y 
									+ _bottomRightY );

		if( IsCircRectColl( _gameObj.GetCollider(), LadderColl ) == true )
		{
			return true;
		}
	}
	return false;
}
/*****************************************************************************/