/*****************************************************************************
* Project: SDLFramework
* File   : GamestatePlay.h
* Date   : 22.01.2020
* Author : Ralf Hüwe		(RH)
*		   Marcus Schaal	(MS)
*		   Stephan Weber	(SW)
*		   Sandro Mock      (SM)
*		   Niklas Englmeier (NE)
*
* Die GamestatePlay Klasse gehört zu den Gamestates und Initialisiert alles, 
* was im Laufenden Spiel exestiern soll.
*
* History:
*	22.01.20	RH	Created
*	14.01.20	MS	Level hinzugefügt
*	15.01.20	SW	Spieler hinzugefügt
*	25.02.20	SW	WinAnimation hinzugefügt
*	05.03.20	SW	GameOver Pointer hinzugefügt
*	06.03.20	MS	Ins Reine geschrieben & Literale entfernt
******************************************************************************/
#pragma once
#include <Windows.h> //?
#include "GamestateManager.h" //?
#include "Sprite.h"
#include "Player.h" //Von Stephan Weber
#include "Hammer.h" //Von Stephan Weber
#include "Level.h" //Von Marcus Schaal
#include "Physics.h" //Von Marcus Schaal
#include "DonkeyKong.h"	// Von Sandro Mock
#include "Pauline.h"	// Von Sandro Mock
#include "Barrel.h"	// Von Sandro Mock
#include "Flame.h"	// Von Sandro Mock
#include "UIPanel.h" // Von Niklas Englmeier
#include "Gamestate.h"
#include "WinAnimation.h" //Von Stephan Weber

/*---------------------------------------------------------------------------*/
//ab hier von Marcus Schaal
//Vorinirialisierungen
const std::string M_SZ_GAMESTATE_PLAY = "play";
const std::string M_SZ_GAMESTATE_MENU = "menu";
const int M_I_BARREL_SIZE = 40;
const int M_I_FLAME_SIZE = 5;
//bis hier von Marcus Schaal
/*---------------------------------------------------------------------------*/

class CGamestatePlay : public CGamestate
{
public:
	CGamestatePlay() { m_sName = M_SZ_GAMESTATE_PLAY; } //?

	void ChangeGamestate(string _gamestate)
	{
		m_sGamestate = _gamestate;
		m_bShouldChangeGamestate = true;
	}

	int Initialize();
	void Finalize();

	int Update();
	void Render();

	CUIPanel* GetUIPanel() { return m_pGameUI; }; // von Niklas Englmeier

private:
	/*m_pHero, m_pBackground, m_pBackground2, m_pForeground, m_pForeground2, 
	* m_pEnemy, m_pCollision, m_pBullet, m_BulletDir und m_fBulletSpeed  
	* von Marcus Schaal entfernt */

	string m_sGamestate = "";
	bool m_bShouldChangeGamestate = false;

	CLevel*				m_pLevel = nullptr; //Von Marcus Schaal
	CDonkeyKong*		m_pDonkeyKong = nullptr;	// Von Sandro Mock
	CBarrel*			m_pBarrel[M_I_BARREL_SIZE] = {};	// Von Sandro Mock
	CFlame*				m_pFlame[M_I_FLAME_SIZE] = {};	// Von Sandro Mock
	CPauline*			m_pPauline = nullptr;	// Von Sandro Mock

	CPlayer*			m_pPlayer = nullptr; //Von Stephan Weber
	CHammer*			m_pHammer1 = nullptr; //Von Stephan Weber
	CHammer*			m_pHammer2 = nullptr; //Von Stephan Weber

	CPhysics*			m_pPhysics = nullptr;	//Von Marcus Schaal
	CUIPanel*			m_pGameUI = nullptr; // Von Niklas Englmeier

	CWinAnimation*		m_pWinAnimation = nullptr; //Von Stephan Weber
	CSprite*			m_pGameOver = nullptr; //SW

	float m_fBGMTimer = M_F_DEFAULT_TIMER; //?
	bool m_bAudioIsUpdated = false; //?

	const int	M_I_LEVEL = 1; //SW

	/*-----------------------------------------------------------------------*/
	//ab hier von Marcus Schaal
	const float M_F_DEFAULT_TIMER = 0.4f;
	const float M_F_TIMER_LIMIT = 0.0f;

	const int	M_I_1ST_BARREL_IDX = 0;
	const int	M_I_1ST_BARREL_IMAGE = M_I_1ST_BARREL_IDX;
	const float	M_F_1ST_BARREL_X = 375.0f; 
	const float	M_F_1ST_BARREL_Y = 286.0f; 

	const int	M_I_BROWN_BARREL_1ST_IDX = 1;
	const int	M_I_BROWN_BARREL_SIZE = 36;
	const int	M_I_BROWN_BARREL_IMAGE = M_I_BROWN_BARREL_1ST_IDX;
	const float M_F_BROWN_BARREL_X = 420.0f;
	const float M_F_BROWN_BARREL_Y = 286.0f;

	const int	M_I_BLUE_BARREL_1ST_IDX = M_I_BROWN_BARREL_SIZE;
	const int	M_I_BLUE_BARREL_IMAGE = 2;
	const float	M_F_BLUE_BARREL_X = M_F_BROWN_BARREL_X;
	const float M_F_BLUE_BARREL_Y = M_F_BROWN_BARREL_Y;

	const int	M_I_FINALIZE_LIMIT = -1;
	const int	M_I_BARREL_LAST_IDX = 39;

	const int	M_I_FLAME_1ST_IDX = M_I_1ST_BARREL_IDX;
	const int	M_I_FLAME_LAST_IDX = 4;
	const float	M_F_FLAME_X = 302.0f;
	const float M_F_FLAME_Y = 600.0f;

	const Vector m_vGameOverPos{ 512,500 };

	const std::string M_SZ_GAME_OVER_SPRITE = 
		"Assets\\GameOver_500x100_f1.bmp";
	//bis hier von Marcus Schaal
	/*-----------------------------------------------------------------------*/
};