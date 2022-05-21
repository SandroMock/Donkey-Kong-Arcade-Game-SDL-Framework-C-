#include "WinAnimation.h"
#include "GamestateManager.h"
#include "Defines.h"
#include "Engine.h"
#include "GamestatePlay.h"
#include <iostream>

CWinAnimation::CWinAnimation()
{
}

CWinAnimation::~CWinAnimation()
{
}

int CWinAnimation::Initialize()
{
	m_pDonkeyKong = new CSprite();
	m_pDonkeyKong->Initialize(DonkeyKongClimb1_132x72_f2, 2);
	m_pDonkeyKong->SetDefaultDelay(m_fDefaultDefaultDelay);
	m_pDonkeyKong->SetPosition(m_vStartPos);
	m_pDonkeyKong->SetActive(false);

	//Verdeckt den DonkeyKong, wenn er aus dem Spiel hinaus klettert
	m_pCover = new CSprite();
	m_pCover->Initialize(Cover_200x100_f1);
	m_pCover->SetPosition(m_vCoverPos);
	m_pCover->SetActive(false);

	m_bSoundIsPlaying = false;

	return 0;
}

void CWinAnimation::Finalize()
{
	FINALIZE_DELETE(m_pCover);
	FINALIZE_DELETE(m_pDonkeyKong);
}

int CWinAnimation::Update()
{
	//Warten bis getriggert wurde
	if (!m_bHasStartet) { return 0; }

	if (!m_bSoundIsPlaying)
	{
		CEngine::PlayMusic( BGM_WIN);
		m_bSoundIsPlaying = true;
	}
	

	CEngine::PauseGame();

	if (!m_bBonusIsAdded)
	{
		CEngine::m_pDataManager->SetPlayerHasWon();
		m_bBonusIsAdded = true;
	}

	m_pDonkeyKong->SetActive(true);
	m_pCover->SetActive(true);

	if (!m_bDonkeykongShoudBeInactive)
	{
		m_bDonkeykongShoudBeInactive = true;
	}

	m_pDonkeyKong->Update(2);

	//Kletterbewegung
	m_pDonkeyKong->IncPositionY(m_fClimbSpeed * CEngine::GetDeltaTime2());

	//Animation Ändern, wenn bestimmte Höhe erreicht
	if (m_pDonkeyKong->GetPositionY() <= m_fChangePos &&
		!m_bSpriteSheetHasChanged &&
		m_pDonkeyKong->GetActualFrame() == 0)
	{
		m_vNowPos = m_pDonkeyKong->GetPosition();
		m_pDonkeyKong->Finalize();
		m_pDonkeyKong->Initialize(DonkeyKongClimb2_172x72_f2, 2);
		m_pDonkeyKong->SetPosition(m_vNowPos);
		m_bSpriteSheetHasChanged = true;
		m_bPaulineShoudBeInactive = true;

		CGamestatePlay* play = dynamic_cast<CGamestatePlay*>(&CGamestateManager::GetActiveGamestate());
		play->ChangeGamestate(CEngine::m_pDataManager->isNewHighscore() ? "highscore" : "menu");

		//CGamestatePlay::ChangeGamestate(CEngine::m_pDataManager->isNewHighscore() ? "highscore" : "menu");d
	}
	//anhalten, wenn kompletter hinter m_pCover
	else if (m_pDonkeyKong->GetPositionY() <= m_vCoverPos.y)
	{
		m_fClimbSpeed = 0;
	}

	return 0;
}

void CWinAnimation::Render()
{
	m_pDonkeyKong->Render();
	m_pCover->Render();
}
