/*****************************************************************************
* Project: SDLFramework
* File   : WinAnimation.h
* Date   : 24.01.2019
* Author : Stephan Weber (SW)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	25.02.2020	SW	Created
******************************************************************************/
#pragma once
#include "GameObject.h"
#include "Sprite.h"

using namespace std;

class CWinAnimation : public CGameObject
{
public:
	CWinAnimation();
	~CWinAnimation();

	int Initialize();
	void Finalize();
	int Update();
	void Render();

	void StartAnimation(bool _bool) { m_bHasStartet = _bool; }
	bool DonkeyKongOff() { return m_bDonkeykongShoudBeInactive; }
	bool PaulineShoudBeOff() { return m_bPaulineShoudBeInactive; }

private:
	bool m_bHasStartet = false;
	float m_fDefaultDefaultDelay = 0.35f;
	float m_fClimbSpeed = -15.0f;
	float m_fChangePos = 230.0f;
	bool m_bSpriteSheetHasChanged = false;
	bool m_bBonusIsAdded = false;

	bool m_bDonkeykongShoudBeInactive = false;
	bool m_bPaulineShoudBeInactive = false;
	bool m_bSoundIsPlaying = false;

	Vector m_vStartPos{ 440, 260 };
	Vector m_vCoverPos{ 440, 150 };
	Vector m_vNowPos{ 0,0 };

	CSprite* m_pDonkeyKong = nullptr;
	CSprite* m_pCover = nullptr;

	//Strings für m_pPLayer->Initialize( );
	//									^
	//  								|
	string DonkeyKongClimb1_132x72_f2 = "Assets\\WinAnimation\\DonkeyKongClimb1_132x72_f2.bmp";
	string DonkeyKongClimb2_172x72_f2 = "Assets\\WinAnimation\\DonkeyKongClimb2_172x72_f2.bmp";
	string Cover_200x100_f1 = "Assets\\WinAnimation\\Cover_200x100_f1.bmp";
};

