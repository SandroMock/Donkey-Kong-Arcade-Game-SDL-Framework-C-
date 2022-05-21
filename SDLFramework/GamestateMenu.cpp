/*****************************************************************************
* Project: SDLFramework
* File   : GamestateMenu.cpp
* Date   : 22.01.2020
* Author : Ralf Hüwe (RH)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	22.01.20	RH	Created
*	15.02.20	NE	Added game specific objects
******************************************************************************/
#include "GamestateMenu.h"

void CGamestateMenu::HandleCB( int _id )
{
	switch( _id )
	{
		case 0: CGamestateManager::ChangeGamestate( "play" ); break;
		case 1: CGamestateManager::ChangeGamestate( "credits" ); break;
		case 2: break;
	}
}

/*****************************************************************************/
int CGamestateMenu::Initialize()
{
	//Rank Initialisieren
	m_pRank = new Text();
	m_pRank->Initialize(DEFAULT_FONT, 
						DEFAULT_FONT_RESOLUTION, 
						DEFAULT_SMALL_FONT);

	m_pRank->SetText(SZ_RANK_TEXT);
	m_pRank->SetPosition(20, 
		(int) (SCREENHEIGHT / F_SCREENHEIGHT_TABLE_DEPENDENCY));
	m_pRank->SetColor(CTORQUOISE);

	//Name Initialisieren
	m_pName = new Text();
	m_pName->Initialize(DEFAULT_FONT, 
						DEFAULT_FONT_RESOLUTION, 
						DEFAULT_SMALL_FONT);
	m_pName->SetText(SZ_NAME_TEXT);
	m_pName->SetPosition(I_NAMES_XPOSITION, 
		(int) (SCREENHEIGHT / F_SCREENHEIGHT_TABLE_DEPENDENCY));
	m_pName->SetColor(CTORQUOISE);

	//Name Initialisieren
	m_pScore = new Text();
	m_pScore->Initialize(DEFAULT_FONT, 
						 DEFAULT_FONT_RESOLUTION,
						 DEFAULT_SMALL_FONT);
	m_pScore->SetText(SZ_SCORE_TEXT);
	m_pScore->SetPosition(I_SCORE_XOFFSET + m_pScore->GetWidth(),
		(int) (SCREENHEIGHT / F_SCREENHEIGHT_TABLE_DEPENDENCY));
	m_pScore->SetColor(CTORQUOISE);

	//Insert Coin Initialisieren
	m_pInsertCoin = new Text();
	m_pInsertCoin->Initialize(DEFAULT_FONT, 
							  DEFAULT_FONT_RESOLUTION, 
							  I_INSERT_COIN_FONT_SIZE);
	m_pInsertCoin->SetText(SZ_INSERT_COIN);
	m_pInsertCoin->SetColor(CTORQUOISE);
	m_pInsertCoin->SetPosition(SCREENWIDTH / I_HALF - 
		m_pInsertCoin->GetWidth() / I_HALF,
		SCREENHEIGHT / I_QUARTER);

	m_pOneRed = new Text();
	m_pOneRed->Initialize(DEFAULT_FONT, 
						  DEFAULT_FONT_RESOLUTION, 
						  DEFAULT_BIG_FONT);
	m_pOneRed->SetText(SZ_ONE_TEXT);
	m_pOneRed->SetColor(CRED);
	m_pOneRed->SetPosition(SCREENWIDTH / I_HALF - m_pOneRed->GetWidth() - 
		I_ONETWO_XPOSITION, I_ONETWO_LOWER_YPOSITION);

	m_pTwoRed = new Text();
	m_pTwoRed->Initialize(DEFAULT_FONT, 
						  DEFAULT_FONT_RESOLUTION, 
						  DEFAULT_BIG_FONT);
	m_pTwoRed->SetText(SZ_TWO_TEXT);
	m_pTwoRed->SetColor(CRED);
	m_pTwoRed->SetPosition(SCREENWIDTH / I_HALF + I_ONETWO_XPOSITION, 
		I_ONETWO_LOWER_YPOSITION);

	m_pOneBlue = new Text();
	m_pOneBlue->Initialize(DEFAULT_FONT, 
						   DEFAULT_FONT_RESOLUTION, 
						   DEFAULT_BIG_FONT);
	m_pOneBlue->SetText(SZ_ONE_TEXT);
	m_pOneBlue->SetColor(CTORQUOISE);
	m_pOneBlue->SetPosition(SCREENWIDTH / I_HALF - m_pOneBlue->GetWidth() - 
		I_ONETWO_XPOSITION, I_ONETWO_UPPER_YPOSITION);

	m_pTwoBlue = new Text();
	m_pTwoBlue->Initialize(DEFAULT_FONT, 
						   DEFAULT_FONT_RESOLUTION, 
						   DEFAULT_BIG_FONT);
	m_pTwoBlue->SetText(SZ_TWO_TEXT);
	m_pTwoBlue->SetColor(CTORQUOISE);
	m_pTwoBlue->SetPosition(SCREENWIDTH / I_HALF + I_ONETWO_XPOSITION, 
		I_ONETWO_UPPER_YPOSITION);

	m_pUIPanel = new CUIPanel();
	m_pUIPanel->Initialize();
	m_pUIPanel->SetLife(I_MENU_LIVES);
	m_pUIPanel->SetLevel(I_MENU_LEVEL);
	m_pUIPanel->SetBonusActive(false);
	m_pUIPanel->SetOneUpActionActive(false);

	for (int i = I_ZERO; i < I_AMOUNT_ROWS; i++) {
		m_pRanks[i] = new Text();
		m_pRanks[i]->Initialize(DEFAULT_FONT, 
								DEFAULT_FONT_RESOLUTION, 
								DEFAULT_BIG_FONT);
		m_pRanks[i]->SetPosition(I_RANKS_XPOSITION, 
			(int) (SCREENHEIGHT / F_SCREENHEIGHT_TABLE_DEPENDENCY + 
			(i + I_INCREASE) * I_ROW_YOFFSET));

		m_pScores[i] = new Text();
		m_pScores[i]->Initialize(DEFAULT_FONT, 
								DEFAULT_FONT_RESOLUTION, 
								DEFAULT_BIG_FONT);
		m_pScores[i]->SetPosition(I_SCORES_XPOSITION + m_pScores[i]->GetWidth(), 
			(int)(SCREENHEIGHT / F_SCREENHEIGHT_TABLE_DEPENDENCY + 
			(i + I_INCREASE) * I_ROW_YOFFSET));
		m_pScores[i]->SetText(
			FormatToStringWithZeros(CEngine::m_pDataManager->GetSlot(i)->m_iScore, 
				I_SCORE_DIGITS));

		m_pNames[i] = new Text();
		m_pNames[i]->Initialize(DEFAULT_FONT, 
								DEFAULT_FONT_RESOLUTION,
								DEFAULT_BIG_FONT);
		m_pNames[i]->SetPosition(I_NAMES_XPOSITION, 
			(int) (SCREENHEIGHT / F_SCREENHEIGHT_TABLE_DEPENDENCY + 
			(i + I_INCREASE) * I_ROW_YOFFSET));
		m_pNames[i]->SetText(CEngine::m_pDataManager->GetSlot(i)->m_szName);

		if (i < I_AMOUNT_RED_ROW) {
			m_pRanks[i]->SetColor(CRED);
			m_pScores[i]->SetColor(CRED);
			m_pNames[i]->SetColor(CRED);
		}
		else 
		{
			m_pRanks[i]->SetColor(CYELLOW);
			m_pScores[i]->SetColor(CYELLOW);
			m_pNames[i]->SetColor(CYELLOW);
		}
	}

	m_pRanks[IDX_FIRST]->SetText(SZ_FIRST);
	m_pRanks[IDX_SECOND]->SetText(SZ_SECOND);
	m_pRanks[IDX_THIRD]->SetText(SZ_THIRD);
	m_pRanks[IDX_FOURTH]->SetText(SZ_FOURTH);
	m_pRanks[IDX_FIFTH]->SetText(SZ_FIFTH);
	
	m_pCredit = new Text();
	m_pCredit->Initialize(DEFAULT_FONT, 
						  DEFAULT_FONT_RESOLUTION, 
						  DEFAULT_BIG_FONT);
	m_pCredit->SetText(SZ_CREDIT_TEXT);
	m_pCredit->SetColor(CGREEN);
	m_pCredit->SetPosition(SCREENWIDTH - m_pCredit->GetWidth(), 
		SCREENHEIGHT - m_pCredit->GetHeight());

	CEngine::PlayMusic(BGM_INTRO2, I_INTRO_SOUND_REPEAT_COUNT);

	//Gamestate zurücksetzen
	m_iState = I_STATE_ONE;
	m_iCredits = I_ZERO;

	return I_SUCCESS;
}

/*****************************************************************************/
void CGamestateMenu::Finalize()
{
	FINALIZE_DELETE(m_pRank);
	FINALIZE_DELETE(m_pScore);
	FINALIZE_DELETE(m_pName);

	for (int i = I_ZERO; i < I_AMOUNT_ROWS; i++) {
		FINALIZE_DELETE(m_pRanks[i]);
		FINALIZE_DELETE(m_pScores[i]);
		FINALIZE_DELETE(m_pNames[i]);
	}

	FINALIZE_DELETE(m_pInsertCoin);
	FINALIZE_DELETE(m_pOneRed);
	FINALIZE_DELETE(m_pTwoRed);
	FINALIZE_DELETE(m_pOneBlue);
	FINALIZE_DELETE(m_pTwoBlue);
	FINALIZE_DELETE(m_pCredit);

	FINALIZE_DELETE(m_pUIPanel);

	CEngine::StopMusic();
	CEngine::PauseGame(false);
}

/*****************************************************************************/
int CGamestateMenu::Update()
{
	//Timer hochzählen
	m_fCreditTimer += CEngine::GetDeltaTime();
	m_fOneUpTimer += CEngine::GetDeltaTime();

	m_pUIPanel->Update();

	//Wenn Confirm gedrückt (Leertaste)
	if (CEngine::HasKeyBeenPressed(C_KEY_CONFIRM)) {
		switch (m_iState)
		{
			//Erster Klick
			case I_STATE_ONE:
				//Zurücksetzen
				CEngine::m_pDataManager->ResetScore();
				m_pUIPanel->SetScore(CEngine::m_pDataManager->GetScore());
				//One Up Blinken
				m_pUIPanel->SetOneUpActionActive(true);
				//Texte aktualisieren
				m_pInsertCoin->SetText(SZ_PUSH);
				m_pInsertCoin->SetPosition(SCREENWIDTH / I_HALF -
					m_pInsertCoin->GetWidth() / I_HALF,
					SCREENHEIGHT / I_QUARTER);

				//Text updaten für nächsten State
				m_pOneBlue->SetText(SZ_BUTTON);
				m_pOneBlue->SetPosition(SCREENWIDTH / I_HALF -
					m_pOneBlue->GetWidth() / I_HALF,
					I_ONEBLUE_SECOND_YPOSITION);

				//Texte clearen
				m_pTwoBlue->SetText();
				m_pOneRed->SetText();
				m_pTwoRed->SetText();


				CEngine::PlaySFX(I_AUDIO_CHANNEL ,SFX_COIN, I_CREDIT_SOUND_REPEAT_COUNT);
				break;

			//Zweiter Klick
			case I_STATE_TWO:
				//In den nächsten Gamestate Änderung
				CGamestateManager::ChangeGamestate(SZ_NEXT_GAMESTATE);
				break;

		default:
			break;
		}
		m_iState++;
	}

	switch (m_iState)
	{
	case I_STATE_ONE:

		break;

	case I_STATE_TWO:
		//Credit hochzählen mit Timer
		if (m_fCreditTimer > F_CREDIT_TRIGGER) {
			if (m_iCredits < I_CREDIT_MAXVALUE) {
				m_iCredits++;
			}
			m_pCredit->SetText(SZ_CREDITS_TEXT + 
				FormatToStringWithZeros(m_iCredits, I_CREDIT_DIGITS));
			m_fCreditTimer = F_TIMER_DEFAULT;
		}
		break;

	default:
		break;
	}

	return I_SUCCESS;
}

/*****************************************************************************/
void CGamestateMenu::Render()
{
	m_pRank->Render();
	m_pScore->Render();
	m_pName->Render();
	for (int i = I_ZERO; i < I_AMOUNT_ROWS; i++) {
		m_pRanks[i]->Render();
		m_pScores[i]->Render();
		m_pNames[i]->Render();
	}

	m_pInsertCoin->Render();

	m_pOneRed->Render();
	m_pTwoRed->Render();
	m_pOneBlue->Render();
	m_pTwoBlue->Render();

	m_pCredit->Render();

	m_pUIPanel->Render();
}