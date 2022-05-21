#pragma once
#include "Engine.h"

/*****************************************************************************/
//Audio
/*****************************************************************************/
//BGM
const BGM BGM_ELEM_NONE = BGM_NONE;
const BGM BGM_ELEM_INTRO1 = BGM_INTRO1;
const BGM BGM_ELEM_INTRO2 = BGM_INTRO2;
const BGM BGM_ELEM_HOW_HIGH = BGM_HOW_HIGH;
const BGM BGM_ELEM_LEVEL_START = BGM_LEVEL_START;
const BGM BGM_ELEM_LEVEL = BGM_LEVEL;
const BGM BGM_ELEM_HAMMER = BGM_HAMMER;
const BGM BGM_ELEM_WIN = BGM_WIN;
const BGM BGM_ELEM_COUNT = BGM_COUNT;

//SFX
const SFX SFX_ELEM_NONE = SFX_NONE;
const SFX SFX_ELEM_JUMP = SFX_JUMP;
const SFX SFX_ELEM_COIN = SFX_COIN;
const SFX SFX_ELEM_DK_STOMP = SFX_DK_STOMP;
const SFX SFX_ELEM_WALKING = SFX_WALKING;
const SFX SFX_ELEM_GET_POINTS = SFX_GET_POINTS;
const SFX SFX_ELEM_DEATH = SFX_DEATH;
const SFX SFX_ELEM_COUNT = SFX_COUNT;

//Audiofiles (Hintergrundmusik)
const char*			m_cBgmNone = NULL;
const char*			m_cBgmIntro1 =
"Assets\\Sound\\BGM\\BGM_Intro1.wav";
const char*			m_cBgmIntro2 =
"Assets\\Sound\\BGM\\BGM_Intro2.wav";
const char*			m_cBgmHowHigh =
"Assets\\Sound\\BGM\\BGM_HowHigh.wav";
const char*			m_cBgmLevelStart =
"Assets\\Sound\\BGM\\BGM_LevelStart.wav";
const char*			m_cBgmLevel =
"Assets\\Sound\\BGM\\BGM_Level.wav";
const char*			m_cBgmHammer =
"Assets\\Sound\\BGM\\BGM_Hammer.wav";
const char*			m_cBgmWin =
"Assets\\Sound\\BGM\\BGM_Win.wav";

//Audiofiles (Geräusche)
const char*			m_cSfxNone = NULL;

const char*			m_cSfxJump =
"Assets\\Sound\\SFX\\SFX_Jump.wav";
const char*			m_cSfxCoin =
"Assets\\Sound\\SFX\\SFX_Coin.wav";
const char*			m_cSfxDKStomp =
"Assets\\Sound\\SFX\\SFX_DK_Stomp.wav";
const char*			m_cSfxWalking =
"Assets\\Sound\\SFX\\SFX_Walking.wav";
const char*			m_cSfxGetPoints =
"Assets\\Sound\\SFX\\SFX_GetPoints.wav";
const char*			m_cSfxDeath =
"Assets\\Sound\\SFX\\SFX_Death.wav";
/*****************************************************************************/