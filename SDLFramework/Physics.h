/*****************************************************************************
* Project: SDLFramework
* File   : Physics.h
* Date   : 10.02.2020
* Author : Marcus Schaal (MS)
*		   Stephan Weber (SW)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	18.02.20	MS	Created
*	19.02.20	MS	Spieler-Leiter-Kollision in kleine und gro�e Leitern 
*					geteilt,
*					Schwerkraft mit verschiedenen Stages f�r Spieler,
*					Update f�r F�sser + F�sser-Schwerkraft,
*	20.02.20	MS	_elem-Parameter f�r Fassarten in Barrel-Update,
*					Schwerkraft f�r Flammen,
*					F�sser-Leiter-Kollisions-Positionen gefixt
*	21.02.20	MS	Flammen k�nnen schr�g gehen und haben verschiedene Stages,
*					Spieler kollidiert mit F�ssern und Flammen,
*					Siegbedingungen eingef�gt,
*	24.02.20	MS	CirclePointer in Parametern zu Referenzen,
*					Spieler kollidiert mit Hammer
*	25.02.20	MS	Flammen-Leiter-Kollision
*	28.02.20	MS  WinAnimation wird ausgef�hrt,
*					DK und Pauline werden gel�scht
*	29.02.20	MS	Flamme bekommt Flammen-Update um alle Indices auszuf�hren
*	02.03.20	MS  DK kann als gegner getroffen werden, 
*					�brige Kollisions-Funktionen zu Methoden dieser Klasse,
*					Methode f�r Punkte bei �ber F�sser springen,
*					Methode f�r Hammer kann F�sser/Flammen zerst�ren
*	04.03.20	MS	�berfl�ssige _isActive Parameter entfernt
*	05.03.20	SW  TakeHammer Parameter hinzugef�gt und Inhalt angepasst
******************************************************************************/
#pragma once
#include "Player.h"
#include "Level.h"
#include "Barrel.h"
#include "Flame.h"
#include "Hammer.h"
#include "WinAnimation.h"
#include "DonkeyKong.h"
#include "Pauline.h"


class CPhysics
{
private:
	/*************************************************************************/
	// Kollisionen
	/*************************************************************************/
	bool IsEnemyHitten( CPlayer& _player, CCircCollObject& _enemy );

	bool IsEnemyHitten( CPlayer& _player, CBoxCollObject& _enemy );


	void DefineBoundary( CPlayer& _player, CLevel& _level );

	//SW: im Folgenden 2. CHammer& als Parameter hinzugef�gt
	bool TakeHammer( CPlayer& _player, CHammer& _hammer1, CHammer& _hammer2 );

	void JumpOverBarrel( CPlayer& _player, CBarrel& _barrel );
	
	void DestroyWithHammer( CPlayer& _player, CBarrel& _barrel );
	/*************************************************************************/

	/*************************************************************************/
	//Spiel gewinnen
	/*************************************************************************/
	bool WinGame( CPlayer& _pPlayer, CLevel& _pLevel );
	/*************************************************************************/

public:
	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	int BarrelUpdate( CPlayer& _player, CBarrel& _barrel, CLevel& _level );

	int FlameUpdate( CPlayer& _player, CFlame& _flame, CLevel& _level );

	int Update( CPlayer& _player, CDonkeyKong& _enemy, CLevel& _level,
			    CHammer& _hammer1, CHammer& _hammer2, CWinAnimation& _win, 
				CDonkeyKong& _dk, CPauline& _pauline );
	/*************************************************************************/

private:
	/*************************************************************************/
	//Attribute
	/*************************************************************************/
	const int	M_I_SUCCESS		   = 0;
	const float M_I_BORDER		   = 160.009f;
	const float M_F_BARREL_GRAVITY = 100.0f;
	const float M_F_FLAME_GRAVITY  = 50.0f;

		  bool m_bIsPlayerDead	   = false;
	/*************************************************************************/
};