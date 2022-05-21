#include "GamestateHowHeight.h"
#include "Engine.h"
#include "LevelConfig.h"
#include "Defines.h"
#include "GamestateManager.h"

int CGamestateHowHeight::Initialize()
{
	m_pBackground = new CSprite();
	m_pBackground->Initialize(m_sHowHightCanYouGetScreen_448x512_f1);
	m_pBackground->SetPosition(m_vStartPos);

	m_pUIPanel = new CUIPanel();
	m_pUIPanel->Initialize();
	m_pUIPanel->SetBonusActive(false);
	m_pUIPanel->SetLevel(1);

	CEngine::StopMusic();
	CEngine::PlayMusic(BGM_HOW_HIGH);

	m_fTimer = m_fDefaultTimer;

	return I_SUCCESS;
}

void CGamestateHowHeight::Finalize()
{
	FINALIZE_DELETE(m_pUIPanel);
	FINALIZE_DELETE(m_pBackground);
}

int CGamestateHowHeight::Update()
{
	m_pUIPanel->Update();

	m_fTimer -= CEngine::GetDeltaTime();
	if (m_fTimer <= M_F_END_OF_TIMER)
	{
		CGamestateManager::ChangeGamestate("play");
	}

	return I_SUCCESS;
}

void CGamestateHowHeight::Render()
{
	m_pBackground->Render();
	m_pUIPanel->Render();
}
