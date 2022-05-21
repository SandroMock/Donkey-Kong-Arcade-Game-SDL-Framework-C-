#include "StartAnimation.h"
#include "Engine.h"
#include "Defines.h"

CStartAnimation::CStartAnimation()
{
}

CStartAnimation::~CStartAnimation()
{
}

int CStartAnimation::Initialize()
{
	m_pLadder = new CSprite();
	m_pLadder->Initialize(m_sLadder_672x269_f14, 14);
	m_pLadder->SetPosition(m_vLadderStartPos);
	m_pLadder->SetDefaultDelay(m_fLadderDefaultDelay);

	m_pDonkeyKong = new CSprite();
	m_pDonkeyKong->Initialize(m_sDonkeyKongClimbing_172x72_f2, 2);
	m_pDonkeyKong->SetPosition(m_vDonkyKongStartPos);
	m_pDonkeyKong->SetDefaultDelay(m_fDonkeyKongDefaultDelay);

	m_pLevel = new CSprite();
	m_pLevel->Initialize(m_sLevel_3136x448_f7, 7);
	m_pLevel->SetPosition(m_vLevelStartPos);
	m_pLevel->SetDefaultDelay(m_fLevelDefaultDelay);

	m_pCover = new CSprite();
	m_pCover->Initialize(m_sCover_1024x768_f1);
	m_pCover->SetPosition(m_vCoverStartPos);

	m_pPauline = new CPauline();
	m_pPauline->Initialize();
	m_pPauline->SetActive(false);

	CEngine::PlayMusic(BGM_INTRO1);

	return 0;
}

void CStartAnimation::Finalize()
{
	FINALIZE_DELETE(m_pPauline);
	FINALIZE_DELETE(m_pCover);
	FINALIZE_DELETE(m_pLevel);
	FINALIZE_DELETE(m_pDonkeyKong);
	FINALIZE_DELETE(m_pLadder);
}

void CStartAnimation::Climb()
{
	if (m_pDonkeyKong->GetPositionY() >= m_fChangePos)
	{
		m_pDonkeyKong->Update();
		m_pDonkeyKong->IncPositionY(-m_fClimbSpeed * CEngine::GetDeltaTime());
	}
	else
	{
		m_fPauseTimer -= CEngine::GetDeltaTime();

		if (m_fPauseTimer > 0) { return; }

		m_pDonkeyKong->IncPositionY(-m_fJumpSpeed * CEngine::GetDeltaTime());

		if (m_pDonkeyKong->GetPositionY() <= m_fMaxHeight)
		{
			m_fJumpSpeed -= m_fJumpSpeedReduction;
		}

		if (m_pDonkeyKong->GetPositionY() >= m_fEndPos && m_fJumpSpeed < 0)
		{
			CEngine::PlaySFX(-1, SFX_DK_STOMP);
			m_pPauline->SetActive(true);
			m_bIsClimbing = false;
		}
	}
}

void CStartAnimation::Jump()
{
	if (!m_bHasRightSpriteseet)
	{
		m_vNowPos = m_pDonkeyKong->GetPosition();
		m_pDonkeyKong->Finalize();
		m_pDonkeyKong->Initialize(m_sDonkyKongJumping_160x72_f2, 2);
		m_pDonkeyKong->SetDefaultDelay(m_fDonkeyKongJumpingDefaultDelay);
		m_pDonkeyKong->SetPosition(m_vNowPos);
		m_bHasRightSpriteseet = true;
		m_pLadder->Finalize();
		m_pLevel->SetActualFrame(m_pLevel->GetActualFrame() + 1);
		m_fPauseTimer = m_fTimerBetweenFirstAndOtherJumps;
	}

	m_pPauline->Update();

	m_fPauseTimer -= CEngine::GetDeltaTime();

	if (m_fPauseTimer > 0) return;

	if (m_iHowManyJumps < m_iMaxJumps)
	{
		m_pDonkeyKong->IncPositionX(-m_fSidejumpSpeed * CEngine::GetDeltaTime());

		if (!m_bIsGoingDown)
		{
			m_pDonkeyKong->IncPositionY(-m_fSidejumpSpeed * CEngine::GetDeltaTime());
			m_fActualJumpHeight += CEngine::GetDeltaTime();

			if (m_fActualJumpHeight >= m_fMaxJumpHight)
			{
				m_bIsGoingDown = true;
			}
		}
		else
		{
			m_pDonkeyKong->IncPositionY(m_fSidejumpSpeed * CEngine::GetDeltaTime());
			m_fActualJumpHeight -= CEngine::GetDeltaTime();

			if (m_fActualJumpHeight <= 0)
			{
				m_fActualJumpHeight = 0;
				m_bIsGoingDown = false;
				m_iHowManyJumps++;
				m_pLevel->SetActualFrame(m_pLevel->GetActualFrame() + 1);

				CEngine::PlaySFX(-1, SFX_DK_STOMP);
			}
		}
	}
	else
	{
		if (!m_bDelayIsCorrect)
		{
			m_pDonkeyKong->SetDefaultDelay(m_fToothDefaultDelay);
			m_pDonkeyKong->SetActualDelay(m_fToothDefaultDelay);
			m_bDelayIsCorrect = true;
		}

		m_fToothTimer -= CEngine::GetDeltaTime();

		if (m_fToothTimer <=  m_fStartBGM && !m_bAudioisPlaying)
		{
			m_bAudioisPlaying = true;
			CEngine::PlayMusic(BGM_INTRO2);
		}
		if (m_fToothTimer <= m_fEndBGM)
		{
			CEngine::StopMusic();
		}

		m_pDonkeyKong->Update();

		if (m_fToothTimer <= 0)
		{
			m_pDonkeyKong->Finalize();
			m_pPauline->SetActive(false);

			m_fIsInEndScreen = true;
			m_bAudioisPlaying = false;
		}
	}
}

int CStartAnimation::Update()
{
	m_fBGMTimer -= CEngine::GetDeltaTime();

	if (m_fBGMTimer <= 0)
	{
		CEngine::StopMusic();
		m_fBGMTimer = 1000000;
	}

	m_fLadderStartTimer -= CEngine::GetDeltaTime();

	if (m_fLadderStartTimer <= 0)
	{
		m_pLadder->Update();
		if (m_pLadder->GetActualFrame() == 13)
		{
			m_fLadderStartTimer = 100.0f;
		}
	}

	if (m_fIsInEndScreen)
	{
		m_bAnimationEnd = true;
	}

	if (m_bIsClimbing)
	{
		Climb();
	}
	else
	{
		Jump();
	}

	return 0;
}

void CStartAnimation::Render()
{
	m_pCover->Render();
	m_pLevel->Render();
	m_pLadder->Render();
	m_pPauline->Render();
	m_pDonkeyKong->Render();
}
