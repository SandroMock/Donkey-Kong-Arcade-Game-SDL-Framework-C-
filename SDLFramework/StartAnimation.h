/*****************************************************************************
* Project: SDLFramework
* File   : StartAnimation.h
* Date   : 26.02.2020
* Author : Stephan Weber (SW)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	26.02.2020	SW	Created
******************************************************************************/
#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include <iostream>
#include "Pauline.h"

using namespace std;
class CStartAnimation : public CGameObject
{
public:
	CStartAnimation();
	~CStartAnimation();

	int Initialize();
	void Finalize();
	int Update();
	void Render();

	bool GetAnimationEnd() { return m_bAnimationEnd; }

private:
	void Climb();
	void Jump();


	float m_fLadderDefaultDelay = 0.35f;
	float m_fDonkeyKongDefaultDelay = 0.5f;
	float m_fLevelDefaultDelay = 8000.0f;
	float m_fDonkeyKongJumpingDefaultDelay = 500.0f;
	float m_fToothDefaultDelay = 2.0f;

	float m_fLadderStartTimer = 0.75f;
	float m_fPauseTimer = 0.75f;
	float m_fTimerBetweenFirstAndOtherJumps = 1.0f;
	float m_fStartBGM = 4.0f;
	float m_fEndBGM = 2.0f;
	float m_fToothTimer = 6.0f;

	//Audio
	float m_fBGMTimer = 5.0f;
	bool m_bAudioisPlaying = false;

	float m_fMaxHeight = 250.0f;
	float m_fJumpSpeed = 100.0f;
	float m_fChangePos = 350.0f;
	float m_fEndPos = 260.0f;
	float m_fJumpSpeedReduction = 1.1f;
		
	bool m_bIsClimbing = true;
	bool m_fIsInEndScreen = false;
	bool m_bHasRightSpriteseet = false;
	bool m_bAnimationEnd = false;

	float m_fClimbSpeed = 45.0f;

	int m_iHowManyJumps = 0;
	int m_iMaxJumps = 5;

	float m_fMaxJumpHight = 0.41f;
	float m_fActualJumpHeight = 0.0f;
	float m_fSidejumpSpeed = 40.0f;
	bool m_bIsGoingDown = false;
	bool m_bDelayIsCorrect = false;

	CSprite* m_pLadder = nullptr;
	CSprite* m_pDonkeyKong = nullptr;
	CSprite* m_pLevel = nullptr;
	CSprite* m_pCover = nullptr;
	CPauline* m_pPauline = nullptr;

	Vector m_vNowPos{ 0,0 };

	Vector m_vLadderStartPos{ 536,460 };
	Vector m_vDonkyKongStartPos{ 541,574 };
	Vector m_vLevelStartPos{ 512,416 };
	Vector m_vCoverStartPos{ 512,384 };

	//Strings für m_pPLayer->Initialize( );
	//									^
	//  								|
	string m_sLadder_672x269_f14
		= "Assets\\StartAnimation\\Ladder_672x269_f14.bmp";
	string m_sDonkeyKongClimbing_172x72_f2
		= "Assets\\StartAnimation\\DonkeyKongClimbing_172x72_f2.bmp";
	string m_sDonkyKongJumping_160x72_f2
		= "Assets\\StartAnimation\\DonkyKongJumping_160x72_f2.bmp";
	string m_sLevel_3136x448_f7
		= "Assets\\StartAnimation\\Level_3136x448_f7.bmp";
	string m_sCover_1024x768_f1
		= "Assets\\StartAnimation\\Cover_1024x768_f1.bmp";
};

