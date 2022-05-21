/*****************************************************************************
* Project: SDLFramework
* File   : DonkeyKong.h
* Date   : 20.01.2020
* Author : Sandro Mock (SM)
*
* In dieser Klasse wird Donkey Kong behandelt. Er wird animiert, es werden
* durch einen Timer Faesser gerollt und das Spiel wird angehalten falls der
* Spieler mit deinem Fass kollidiert oder der Spieler die oberste Plattform
* erreicht hat.
*
* History:
*	20.01.20	SM	Created
*	21.01.20	SM	+Donkey Kong Animation
*	10.02.20	SM	+RollBarrels Methode
*	17.02.20	SM	+RollBarrels und Update Parameter
*	19.02.20	SM	-CBarrel Array
*	20.02.20	SM	Initialize erweitert
*	28.02.20	SM	+SetIsWinActive, SetIsPlayerDead Methoden
******************************************************************************/
#pragma once
#include "Level.h"
#include "Sprite.h"
#include "Barrel.h"
#include "BoxCollObject.h"
#include <vector>

using namespace std;
class CDonkeyKong :
	public CBoxCollObject
{
public:
	void SetIsWinActive(bool _win) { m_bIsWinActive = _win; }
	void SetIsPlayerDead(bool _dead) { m_bIsPlayerDead = _dead; }
	void DeleteDK(bool _isActive)
	{
		if (_isActive)
		{
			m_pDK1->Finalize();
			m_pDK2->Finalize();
			m_pDK3->Finalize();
			m_pDKJubel->Finalize();
		}
	}
	void RollBarrels(CBarrel* _barrel[40], CFlame* _flame[5]);
	int Initialize(CBarrel* _barrel[40]);
	void Finalize();
	int Update(CBarrel* _barrel[40], CFlame* _flame[5]);
	void Render();
private:
	enum DKANIMATION { START, BROWN, BLUE };
	DKANIMATION m_animation = { START };

	// 4Faesser und Oel
	CSprite* m_pBarrelStack = nullptr;

	// DK Animationen
	CSprite* m_pDK1 = nullptr;
	CSprite* m_pDK2 = nullptr;
	CSprite* m_pDK3 = nullptr;
	CSprite* m_pDKJubel = nullptr;

	float	m_fTimer = 2.5f;
	float	m_fDK1Timer = 17.5f;
	float	m_fDK2Timer = 2.5f;
	float	m_fBarrelTimer = 102.0f;

	const float M_F_OIL_POS_X = 305;
	const float M_F_OIL_POS_Y = 612;
	float m_fDieAnimationTimer = 1.0f;


	const Vector M_V_DK_POS{ 371, 259 };
	const Vector M_V_BARREL_STACK_POS{ 305, 263 };

	bool m_bIsWinActive = false;
	bool m_bIsPlayerDead = false;
	bool m_bOnPlayerDeath = false;

	const string M_S_BARREL_STACK = "Assets\\Enemy\\4Barrels_40x64_f1.bmp";
	const string M_S_FIRST_BARREL = "Assets\\Enemy\\DK_Start_Barrel_286x86_f2.bmp";
	const string M_S_BROWN_BARREL = "Assets\\Enemy\\DK_Brown_Barrel_495x87_f5.bmp";
	const string M_S_BLUE_BARREL = "Assets\\Enemy\\DK_Blue_Barrel_495x87_f5.bmp";
	const string M_S_DK_JUBEL = "Assets\\Enemy\\DKJubel_495x87_f5.bmp";

};
