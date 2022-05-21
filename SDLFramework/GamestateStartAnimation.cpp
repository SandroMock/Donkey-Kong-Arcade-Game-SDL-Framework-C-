#include "GamestateStartAnimation.h"
#include "GamestateManager.h"
#include "Defines.h"

int CGamestateStartAnimation::Initialize()
{
	m_pStartAnimation = new CStartAnimation();
	m_pStartAnimation->Initialize();

	m_pUIPanel = new CUIPanel();
	m_pUIPanel->Initialize();
	m_pUIPanel->SetLife(3);
	m_pUIPanel->SetLevel(1);
	m_pUIPanel->SetBonusActive(false);
	m_pUIPanel->SetOneUpActionActive(true);

	return 0;
}

void CGamestateStartAnimation::Finalize()
{
	FINALIZE_DELETE(m_pUIPanel);
	FINALIZE_DELETE(m_pStartAnimation);
}

int CGamestateStartAnimation::Update()
{
	m_pStartAnimation->Update();

	m_pUIPanel->Update();
	
	if (m_pStartAnimation->GetAnimationEnd())
	{
		CGamestateManager::ChangeGamestate("howHeigh");
	}

	return 0;
}

void CGamestateStartAnimation::Render()
{
	m_pStartAnimation->Render();
	m_pUIPanel->Render();
}
