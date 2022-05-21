/*****************************************************************************
* Project: SDLFramework
* File   : Physics.cpp
* Date   : 10.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	18.02.20	MS	Created
*	19.02.20	MS	Überlappungen(schräge Flächen hochlaufen) hinzugefügt,
*					Fässer fallen Leitern runter
*	21.02.20	MS	Levelaußenbegrenzungen für Spieler
*	26.02.20	MS	GetGravity bei _flame betreffende Funktionen hinzugefügt,
*					Schwerkraft vereinfacht

******************************************************************************/
#include "Physics.h"
#include "Gravity.h"
#include "PlayerLadderColl.h"
#include "BarrelLadderColl.h"
#include "FlameLadderColl.h"
#include "Overlap.h"
#include "PhysicsConfig.h"


/*****************************************************************************/
// Spieler-Gegner-Kollision
/*****************************************************************************/
bool CPhysics::IsEnemyHitten( CPlayer& _player, CCircCollObject& _enemy )
{
	bool collision = IsCircColl( _player.GetCollider(), 
								 _enemy.GetCollider() );
	_player.SetPlayerCollidesWithBarrel( collision );
	return collision;
}
/*****************************************************************************/

/*****************************************************************************/
// Spieler-Gegner-Kollision (Überladung)
/*****************************************************************************/
bool CPhysics::IsEnemyHitten( CPlayer & _player, CBoxCollObject & _enemy)
{
	bool collision = IsCircRectColl( _player.GetCollider(), 
									 _enemy.GetCollider() );
	_player.SetPlayerCollidesWithBarrel( collision );
	return collision;
}
/*****************************************************************************/

/*****************************************************************************/
//Level-Außenbegrenzungen
/*****************************************************************************/
void CPhysics::DefineBoundary( CPlayer& _player, CLevel& _level )
{
	bool collision = false;

	//linke Begrenzung
	if( IsCircRectColl( _player.GetCollider(), 
						_level.GetLeftBoundColl() ) == true )
	{
		_player.SetPositionX( F_L_BOUNDARY_X + M_I_BORDER );
		collision = true;
	}

	//rechte Begrenzung
	if( IsCircRectColl( _player.GetCollider(), 
						_level.GetRightBoundColl() ) )
	{
		_player.SetPositionX( F_R_BOUNDARY_X - M_I_BORDER );
		collision = true;
	}

	_player.SetPlayerCollidesWithBorder(collision);
}
/*****************************************************************************/

/*****************************************************************************/
//Hammer-Item benutzen
/*****************************************************************************/
bool CPhysics::TakeHammer( CPlayer& _player, CHammer& _hammer1, 
						   CHammer& _hammer2 )
{
	bool collision = false;
	if( IsCircColl( _player.GetCollider(), _hammer1.GetCollider() ) )
	{
		collision = true;
		_hammer1.SetPlayerCollidesWithHammer( true ); //SW
	}
	/*-----------------------------------------------------------------------*/
	//ab hier von Stephan Weber
	else if (IsCircColl(_player.GetCollider(), _hammer2.GetCollider()))
	{
		collision = true;
		_hammer2.SetPlayerCollidesWithHammer( true );
	}
	//bis hier von Stephan Weber
	/*-----------------------------------------------------------------------*/

	_player.SetPlayerCollidesWithHammer(collision);
	
	return false;
}
/*****************************************************************************/

/*****************************************************************************/
//Über Fässser springen
/*****************************************************************************/
void CPhysics::JumpOverBarrel( CPlayer& _player, CBarrel& _barrel )
{
	bool collision = IsCircRectColl( _player.GetCollider(), 
									 _barrel.GetScoreColl() );
	_barrel.SetPlayerJumpOverBarrel( collision );
}
/*****************************************************************************/

/*****************************************************************************/
//Gegner zerstören
/*****************************************************************************/
void CPhysics::DestroyWithHammer( CPlayer& _player, CBarrel& _barrel )
{
	bool collision = IsCircColl( _player.GetHammerCollider(),
								 _barrel.GetCollider() );
	_barrel.SetDestroyOnHit(collision);
}
/*****************************************************************************/



/*****************************************************************************/
//Spiel gewinnen
/*****************************************************************************/
bool CPhysics::WinGame( CPlayer& _pPlayer, CLevel& _pLevel )
{

	return IsCircRectColl( _pPlayer.GetCollider(),
						   _pLevel.GetWinColl() );
}
/*****************************************************************************/


/*****************************************************************************/
//Update für Fässer
/*****************************************************************************/
int CPhysics::BarrelUpdate( CPlayer& _player, CBarrel& _barrel, 
							CLevel& _level )
{
	//Schwerkraft
	UseGravity( _barrel, _level, _barrel.GetStage(), M_F_BARREL_GRAVITY,
				_barrel.GetGravity() );

	//Fass-Leiter-Kollision
	UseBarrelLadder( _barrel, _level );

	//Tod der Spielfigur
	if( m_bIsPlayerDead == false )
	{
		m_bIsPlayerDead = IsEnemyHitten( _player, _barrel );
		_barrel.SetIsPlayerDead( m_bIsPlayerDead );
	}
	
	//Über Fass springen generiert Punkte
	JumpOverBarrel( _player, _barrel );

	//Fass mit Hammer zerstören
	DestroyWithHammer( _player, _barrel );

	//Siegbedingung
	if( WinGame( _player, _level ) == true ) _barrel.SetIsWinActive( true );
	
	return M_I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Update für Flammen
/*****************************************************************************/
int CPhysics::FlameUpdate( CPlayer& _player, CFlame& _flame, CLevel& _level )
{
	//Schwerkraft
	UseGravity( _flame, _level, _flame.GetStage(), M_F_FLAME_GRAVITY, 
				_flame.GetGravity() );

	//Schräg hochgehen
	MoveUpAngle( _flame, _level, _flame.GetStage(), _flame.GetGravity() );

	//Tod der Spielfigut
	if( m_bIsPlayerDead == false )
	{
		m_bIsPlayerDead = IsEnemyHitten( _player, _flame );
		_flame.SetIsPlayerDead( m_bIsPlayerDead );
	}

	//Flamme-Leiter-Kollision
	UseFlameLadder( _flame, _level, true );

	//Siegbedingung
	if( WinGame( _player, _level ) == true ) _flame.SetIsWinActive( true );

	return M_I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Update
/*****************************************************************************/
int CPhysics::Update( CPlayer& _player, CDonkeyKong& _enemy, CLevel& _level,
					  CHammer& _hammer1, CHammer& _hammer2, 
					  CWinAnimation& _win, CDonkeyKong& _dk, 
					  CPauline& _pauline )
{
	//Schräg hochgehen
	MoveUpAngle( _player, _level, _player.GetStage() );

	//Schwerkraft
	_player.SetPlayerCollidesWithPlatform( !UseGravity(_player, _level, 
											_player.GetStage(),
											_player.GetPlayerFallSpeed(),
											_player.GetShouldUseGravity() ) );

	//Spieler-Leiter-Kollision & Klettern
	UseLargeLadders( _player, _level);
	UseSmallLadders( _player, _level);
	UseSmallLadderPlatforms( _player, _level );
	UseLargeLadderPlatforms( _player, _level );

	//Spieler-Level-Randbegrenzungen
	DefineBoundary(_player, _level );

	TakeHammer( _player, _hammer1 , _hammer2);
	//SW: zweite TakeHammer entfernt

	//Tod der Spielfigur
	if( m_bIsPlayerDead == false )
	{
		m_bIsPlayerDead = IsEnemyHitten( _player, _enemy );
		_enemy.SetIsPlayerDead( m_bIsPlayerDead );
		_pauline.SetIsPlayerDead( m_bIsPlayerDead );
	}
	

	//Siegbedingung
	if( WinGame( _player, _level ) == true )
	{
		_player.SetPlayerHasWon( true );
		_win.StartAnimation( true );
		if( _win.DonkeyKongOff() == true ) _dk.DeleteDK( true );
		
		if ( _win.PaulineShoudBeOff() == true ) _pauline.DeletePauline( true );
		
	}

	return M_I_SUCCESS;
}
/*****************************************************************************/