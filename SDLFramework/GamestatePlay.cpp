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
*	14.01.20	MS	Level initialisiert, finalisiert und gerendert
*	15.01.20	MS	Level Update hinzugefügt
*	18.02.20	MS	Physik initialisiert, finalisiert, geupdated und gerendert.
*					Physik-Methoden die noch nicht notwendig sind, 
*					auskommentiert
*	28.02.20	MS	Win-Aniamtion in Physics als Parameter übergeben
*	02.03.20	MS	Enemy als Parameter in Physics-Update
*	05.03.20	SW	GameOver hinzugefügt
******************************************************************************/
#include "Engine.h"
#include "GamestatePlay.h"

/*****************************************************************************/
int CGamestatePlay::Initialize()
{
	/* Background init, Foreground init, m_pHero, m_pEnemy, m_pBullet 
	*  und m_pCollision von Marcus Schaal entfernt */
	
	m_pWinAnimation = new CWinAnimation(); //Von Stephan Weber
	m_pWinAnimation->Initialize(); //Von Stephan Weber

	m_pLevel = new CLevel();     //Von Marcus Schaal
	m_pLevel->Initialize();      //Von Marcus Schaal

	m_pDonkeyKong = new CDonkeyKong();			// Von Sandro Mock
	m_pDonkeyKong->Initialize(m_pBarrel);	// Von Sandro Mock

	m_pPlayer = new CPlayer(); //Von Stephan Weber
	m_pPlayer->Initialize(); //Von Stephan Weber

	m_pHammer1 = new CHammer(); //Von Stephan Weber
	m_pHammer1->Initialize(); //Von Stephan Weber
	m_pHammer1->SetPosition(m_pHammer1->GetHammer1Pos()); //Von Stephan Weber

	m_pHammer2 = new CHammer(); //Von Stephan Weber
	m_pHammer2->Initialize(); //Von Stephan Weber
	m_pHammer2->SetPosition(m_pHammer2->GetHammer2Pos()); //Von Stephan Weber

	m_pPhysics = new CPhysics(); //Von Marcus Schaal
	/*m_pPhysics->Initialize();*/    //Von Marcus Schaal

	//Niklas Englmeier = CUIPanel
	m_pGameUI = new CUIPanel();
	m_pGameUI->Initialize();
	m_pGameUI->SetLevel(M_I_LEVEL);
	m_pGameUI->SetLife(CEngine::m_pDataManager->GetLivesLeft());

/************************Ab hier von Sandro Mock******************************/
//Rollende Faesser
//Erstes Fass
	m_pBarrel[M_I_1ST_BARREL_IDX] = new CBarrel();
	m_pBarrel[M_I_1ST_BARREL_IDX]->Initialize( M_I_1ST_BARREL_IMAGE, 
											   M_F_1ST_BARREL_X, 
											   M_F_1ST_BARREL_Y );
	m_pBarrel[M_I_1ST_BARREL_IDX]->SetActive(false, m_pFlame, false);

	////Braune Faesser
	for (int i = M_I_BROWN_BARREL_1ST_IDX; i < M_I_BROWN_BARREL_SIZE; i++)
	{
		m_pBarrel[i] = new CBarrel();
		m_pBarrel[i]->Initialize( M_I_BROWN_BARREL_IMAGE, M_F_BROWN_BARREL_X, 
								  M_F_BROWN_BARREL_Y );
		m_pBarrel[i]->SetActive(false, m_pFlame, false);


	}
	////Blaue Faesser
	for (int j = M_I_BLUE_BARREL_1ST_IDX; j < M_I_BARREL_SIZE; j++)
	{
		m_pBarrel[j] = new CBarrel();
		m_pBarrel[j]->Initialize( M_I_BLUE_BARREL_IMAGE, M_F_BLUE_BARREL_X, 
								  M_F_BLUE_BARREL_Y );
		m_pBarrel[j]->SetActive(false, m_pFlame, false);

	}

	////Flammen
	for (int i = M_I_FLAME_1ST_IDX; i < M_I_FLAME_SIZE; i++)
	{
		m_pFlame[i] = new CFlame();
		m_pFlame[i]->Initialize(M_F_FLAME_X, M_F_FLAME_Y);
		m_pFlame[i]->SetActive(false, false);
	}
	
	m_pPauline = new CPauline();
	m_pPauline->Initialize();
/*****************Sandro Mock Ende********************************************/

	m_pGameOver = new CSprite(); //SW
	m_pGameOver->Initialize(M_SZ_GAME_OVER_SPRITE); //SW
	m_pGameOver->SetPosition(m_vGameOverPos);
	m_pGameOver->SetActive(false); //SW

	CEngine::PlayMusic(BGM_LEVEL_START); //SW
	m_fBGMTimer = M_F_DEFAULT_TIMER; //SW
	m_bAudioIsUpdated = false; //SW

	return 0;
}

/*****************************************************************************/
void CGamestatePlay::Finalize()
{
	/* m_pBullet, m_pEnemy, m_pHero, m_pForeground2, m_pForeground
	* m_pBackground2 und m_pBackground von Marcus Schaal entfernt*/

	FINALIZE_DELETE(m_pGameOver); //SW
	FINALIZE_DELETE(m_pPauline); // Von Sandro Mock
	for (int i = M_I_FLAME_LAST_IDX; i > M_I_FINALIZE_LIMIT; i--)
	{
		FINALIZE_DELETE(m_pFlame[i]);	// Von Sandro Mock
	}
	for (int i = M_I_BARREL_LAST_IDX; i > M_I_FINALIZE_LIMIT; i--)
	{
		FINALIZE_DELETE(m_pBarrel[i]);	// Von Sandro Mock
	}

	SAFE_DELETE(m_pPhysics);	//Von Marcus Schaal
	FINALIZE_DELETE(m_pPlayer) //Von Stephan Weber
	FINALIZE_DELETE(m_pDonkeyKong);	// Von Sandro Mock
	FINALIZE_DELETE(m_pLevel);		//Von Marcus Schaal
	FINALIZE_DELETE(m_pGameUI);		//Von Niklas Englmeier
	FINALIZE_DELETE(m_pHammer1); //Von Stephan Weber
	FINALIZE_DELETE(m_pHammer2); //Von Stephan Weber
	FINALIZE_DELETE(m_pWinAnimation); //Von Stephan Weber
}

/*****************************************************************************/
int CGamestatePlay::Update()
{
	if (CEngine::m_pDataManager->GetLivesLeft() <= 0 && m_pPlayer->GetIsDeath()) //SW
	{
		m_pGameOver->SetActive(true);
		cout << "gameOver" << endl;
	}

	/* Background scrollen, Foreground scrollen, Hero Movement, herorotation,
	*  m_pHero, m_pEnemy, m_pCollision, IsColliding, Shooting und m_pBullet
	*  von Marcus Schaal entfernt */

	m_fBGMTimer -= CEngine::GetDeltaTime(); //SW
	
	if (m_fBGMTimer <= M_F_TIMER_LIMIT && !m_bAudioIsUpdated) //SW
	{
		m_bAudioIsUpdated = true;
		CEngine::PlayMusic(BGM_LEVEL);	
	}

	m_pLevel->Update();		//Von Marcus Schaal

	m_pBarrel[M_I_1ST_BARREL_IDX]->Update();	// Von Sandro Mock
	for (int i = M_I_BROWN_BARREL_1ST_IDX; i < M_I_BROWN_BARREL_SIZE; i++)
	{
		m_pBarrel[i]->Update();	// Von Sandro Mock
	}
	for (int j = M_I_BLUE_BARREL_1ST_IDX; j < M_I_BARREL_SIZE; j++)
	{
		m_pBarrel[j]->Update();	// Von Sandro Mock
	}
	m_pDonkeyKong->Update(m_pBarrel, m_pFlame);	// Von Sandro Mock
	/*-----------------------------------------------------------------------*/
	// Ab hier von Marcus Schaal

	// allgemeine Physik
	m_pPhysics->Update( *m_pPlayer, *m_pDonkeyKong, *m_pLevel, *m_pHammer1, 
					    *m_pHammer2, *m_pWinAnimation, *m_pDonkeyKong, 
						*m_pPauline );	
	// Fässer Physik
	for (int i = M_I_BROWN_BARREL_1ST_IDX; i < M_I_BROWN_BARREL_SIZE; i++)
	{
		m_pPhysics->BarrelUpdate(*m_pPlayer, *m_pBarrel[i], *m_pLevel);
	}
	for (int j = M_I_BLUE_BARREL_1ST_IDX; j < M_I_BARREL_SIZE; j++)
	{
		m_pPhysics->BarrelUpdate(*m_pPlayer, *m_pBarrel[j], *m_pLevel);
	}

	// Flammen-Physik
	for (int i = M_I_FLAME_1ST_IDX; i < M_I_FLAME_SIZE; i++)
	{
		m_pPhysics->FlameUpdate(*m_pPlayer, *m_pFlame[i], *m_pLevel);
	}	// Bis hier von Marcus Schaal
	/*-----------------------------------------------------------------------*/

	m_pPlayer->Update(); //Von Stephan Weber

	for (int i = M_I_FLAME_1ST_IDX; i < M_I_FLAME_SIZE; i++)
	{
		m_pFlame[i]->Update(); // Von Sandro Mock
	}
	m_pHammer1->Update(); //Von Stephan Weber
	m_pHammer2->Update(); //Von Stephan Weber

	m_pWinAnimation->Update(); //Von Stephan Weber
	m_pGameUI->Update(); //Von Niklas Englmeier

	m_pPauline->Update();	// Von Sandro Mock

	if (CEngine::HasKeyBeenPressed(VK_DELETE)) //NE
	{     
		CGamestateManager::ChangeGamestate(M_SZ_GAMESTATE_MENU);
	}

	if (m_bShouldChangeGamestate)
	{
		CGamestateManager::ChangeGamestate(m_sGamestate);
		m_bShouldChangeGamestate = false;
	}

	return 0;
}

/*****************************************************************************/
void CGamestatePlay::Render()
{
	/* m_pBackground, m_pBackground2, m_pEnemy, m_pHero, m_pCollision,
	*  m_pBullet, m_pForeground, m_pForeground2, SDL_SetRenderDrawColor und
	*  SDL_RenderDrawLine von Marcus Schaal entfernt*/

	m_pLevel->Render();		 //Von Marcus Schaal

	m_pPlayer->Render(); //Von Stephan Weber
	m_pDonkeyKong->Render();	// Von Sandro Mock
	m_pGameUI->Render(); //Von Niklas Englmeier

	m_pBarrel[M_I_1ST_BARREL_IDX]->Render();	// Von Sandro Mock
	for (int i = M_I_BROWN_BARREL_1ST_IDX; i < M_I_BROWN_BARREL_SIZE; i++)
	{
		m_pBarrel[i]->Render();	// Von Sandro Mock
	}
	for (int j = M_I_BLUE_BARREL_1ST_IDX; j < M_I_BARREL_SIZE; j++)
	{
		m_pBarrel[j]->Render();	// Von Sandro Mock
	}
	for (int i = M_I_FLAME_1ST_IDX; i < M_I_FLAME_SIZE; i++)
	{
		m_pFlame[i]->Render();	// Von Sandro Mock
	}	m_pHammer1->Render(); //Von Stephan Weber
	m_pHammer2->Render(); //Von Stephan Weber
	m_pWinAnimation->Render(); //Von Stephan Weber
	m_pPauline->Render();	// Von Sandro Mock
	m_pGameOver->Render(); //SW
}