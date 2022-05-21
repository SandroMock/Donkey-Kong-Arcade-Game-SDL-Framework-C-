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
******************************************************************************/
#include "Overlap.h"
#include "PhysicsConfig.h"
#include <Windows.h>
#include <typeinfo> 
#include "Player.h"



/*****************************************************************************/
// Collider-Überlappungs-Abfrage
/*****************************************************************************/
bool IsCircRectOverlap( CCircleCollider& _pCircleColl,
						CBoxCollider& _pBoxColl )
{

	if( ( _pCircleColl.GetPositionY() + _pCircleColl.GetRadius() )
		> _pBoxColl.GetTopLeft().y ) return true;

	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Plattform-Überlappungs-Abfrage
/*****************************************************************************/
float IsPlatformOverlap( int _arBegin, int _arEnd, CCircCollObject & _gameObj, 
						 CLevel & _level, STAGE _stage )
{
	for( int i = _arBegin; i < _arEnd; ++i )
	{
		if( IsCircRectColl( _gameObj.GetCollider(),
			_level.GetPlatformColl( i ) ) == true ) // fragt Kollision ab
		{
			if( IsCircRectOverlap( _gameObj.GetCollider(),
				_level.GetPlatformColl( i )) == true ) // fragt Überlappung ab
			{
				
				if( typeid( _gameObj ) != typeid( CPlayer ) )
				{
					/* Fragt ab ob sich Spieler auf der richtigen Ebene
				*  nach links oder rechts bewegt,
				*  um zu verhindern erhöhen des Spielers und Schwerkraft
				*  sich überlagern */
					if( ( CEngine::IsKeyPressed( C_D_KEY ) 
						  && _stage == STAGE_ELEM_SEVEN )
						|| ( CEngine::IsKeyPressed( C_D_KEY ) 
							 && _stage == STAGE_ELEM_FIVE )
						|| ( CEngine::IsKeyPressed( C_D_KEY ) 
							 && _stage == STAGE_ELEM_THREE )
						|| ( CEngine::IsKeyPressed( VK_RIGHT ) 
							&& _stage == STAGE_ELEM_SEVEN )
						|| ( CEngine::IsKeyPressed( VK_RIGHT ) 
							 && _stage == STAGE_ELEM_FIVE)
						|| ( CEngine::IsKeyPressed( VK_RIGHT ) 
							 && _stage == STAGE_ELEM_THREE )
						|| ( CEngine::IsKeyPressed( C_A_KEY ) 
							 && _stage == STAGE_ELEM_SIX )
						|| ( CEngine::IsKeyPressed( C_A_KEY ) 
							 && _stage == STAGE_ELEM_FOUR )
						|| ( CEngine::IsKeyPressed( C_A_KEY ) 
							 && _stage == STAGE_ELEM_TWO )
						|| ( CEngine::IsKeyPressed( VK_LEFT )
							 && _stage == STAGE_ELEM_SIX )
						|| ( CEngine::IsKeyPressed( VK_LEFT ) 
							 && _stage == STAGE_ELEM_FOUR )
						|| ( CEngine::IsKeyPressed( VK_LEFT ) 
							 && _stage == STAGE_ELEM_TWO ) )
					{
						return _gameObj.GetPositionY() - F_PUT_OVER_PL;
					}
				}
				else
				{
					return _gameObj.GetPosition().y - F_PUT_OVER_PL;
				}
				
			}
		}
	}
	return _gameObj.GetPosition().y;
}
/*****************************************************************************/

/*****************************************************************************/
//Ebenen-Überlappungs-Abfrage 
/*****************************************************************************/
float IsStageOverlap( CCircCollObject & _gameObj, CLevel & _level, 
					  STAGE _stage )
{
	switch( _stage ) //Auswahl: Plattform-Ebene (von oben nach unten)
	{
	case STAGE_ONE:
		return IsPlatformOverlap( PL_1_1ST_IDX, PL_1_LAST_IDX,
								  _gameObj, _level, _stage );
		break;

	case STAGE_TWO:
		return IsPlatformOverlap( PL_2_1_1ST_IDX, PL_2_2_LAST_IDX,
								  _gameObj, _level, _stage );
		break;

	case STAGE_THREE:
		return IsPlatformOverlap( PL_3_1ST_IDX, PL_3_LAST_IDX,
								  _gameObj, _level, _stage );
		break;

	case STAGE_FOUR:
		return IsPlatformOverlap( PL_4_1ST_IDX, PL_4_LAST_IDX,
								  _gameObj, _level, _stage );
		break;

	case STAGE_FIVE:
		return IsPlatformOverlap( PL_5_1ST_IDX, PL_5_LAST_IDX,
								  _gameObj, _level, _stage );
		break;

	case STAGE_SIX:
		return IsPlatformOverlap( PL_6_1ST_IDX, PL_6_LAST_IDX,
								  _gameObj, _level, _stage );
		break;

	case STAGE_SEVEN:
		return IsPlatformOverlap( PL_7_1_1ST_IDX, PL_7_2_LAST_IDX,
								  _gameObj, _level, _stage );
		break;

	default:
		return IsPlatformOverlap( PL_1_1ST_IDX, I_PL_AR_SIZE,
								  _gameObj, _level, _stage );
		break;
	}
}
/*****************************************************************************/

/*****************************************************************************/
//Funktion um schräg laufen zu können
/*****************************************************************************/
void MoveUpAngle( CCircCollObject & _gameObj, CLevel & _level, STAGE _stage, 
				  bool _isActive )
{
	if( _isActive == true )
	{
		_gameObj.SetPosition( _gameObj.GetPosition().x,
							  IsStageOverlap(_gameObj, _level, _stage ) );
	}
}
/*****************************************************************************/