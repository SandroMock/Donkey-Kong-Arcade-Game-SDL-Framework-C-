#include "GamestateControls.h"
#include "GamestateManager.h"
#include "LevelConfig.h"
#include "Engine.h"
#include "Defines.h"

int CGamestateControls::Initialize()
{
	m_pControls = new CSprite();
	m_pControls->Initialize(Controls_2048x768_f2, 2);
	m_pControls->SetPosition(m_vStartPos);

	return I_SUCCESS;
}

void CGamestateControls::Finalize()
{
	FINALIZE_DELETE(m_pControls);
}

int CGamestateControls::Update()
{
	m_pControls->Update();

	if (CEngine::HasKeyBeenPressed(m_cSpaceKey))
	{
		CGamestateManager::ChangeGamestate("menu");
	}

	return I_SUCCESS;
}

void CGamestateControls::Render()
{
	m_pControls->Render();
}
