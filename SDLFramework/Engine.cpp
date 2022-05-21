/*****************************************************************************
* Project: SDLFramework
* File   : Engine.cpp
* Date   : 18.12.2019
* Author : Ralf Hüwe (RH)
*		   Marcus Schaal (MS)
*	       Sandro Mock (SM)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	18.12.19	RH	Created
*	19.12.19	RH	+Mehr Logik
*	25.02.20	MS	Audio überarbeitet
*	27.02.20	MS	Weitere Audioquellen hinzugefügt
*	29.02.20	MS	ComponentConfig inkludiert + Literale entfernt
*	03.03.20	SM	+DeltaTime2
*	05.03.20	MS	Literale entfernt & ins Reine geschrieben
******************************************************************************/
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "Engine.h"
#include "EngineConfig.h" //MS

bool			CEngine::m_bRunning = false;
SDL_Window*		CEngine::m_pWindow = nullptr;
SDL_Renderer*	CEngine::m_pRenderer = nullptr;
SDL_Event*		CEngine::m_pEvent = nullptr;
int				CEngine::m_iWindowWidth = I_DEFAULT_VALUE;
int				CEngine::m_iWindowHeight = I_DEFAULT_VALUE;
bool			CEngine::m_bFullscreen = false;
Uint32			CEngine::m_tActualFrameTime = I32_DEFAULT_VALUE;
Uint32			CEngine::m_tLastFrameTime = I32_DEFAULT_VALUE;
float			CEngine::m_fDeltaTime = F_DEFAULT_VALUE;
float			CEngine::m_fDeltaTime2 = F_DEFAULT_VALUE; // von SM und SW
int				CEngine::m_iKeyboardArraySize = I_DEFAULT_VALUE;
bool			CEngine::m_bGameIsPaused = false; //SW
Mix_Music*		CEngine::m_pAtmo[BGM_ELEM_COUNT] = {}; //MS: +AR & BGM
Mix_Chunk*		CEngine::m_pSounds[SFX_ELEM_COUNT] = {}; //MS:	+SFX

Uint8*			CEngine::m_pOldKeyboardState = nullptr;
Uint8*			CEngine::m_pNewKeyboardState = nullptr;

DataManager*	CEngine::m_pDataManager		 = nullptr; //NE

/*****************************************************************************/
int CEngine::Initialize( int _screenWidth, int _screenHeight )
{
	// Step 1
	int result = SDL_Init( SDL_INIT_EVERYTHING );
	if( result != I_INIT_SUCCESS ) return I_INIT_RETURN_STEP1;

	// Step 2
	// Fenstermodus könnte man über den Befehlszeilenparameter "fullscreen"
	// bei Programmstart festlegen.
	SDL_WindowFlags displaymode = SDL_WINDOW_BORDERLESS; //SM: Modus verändert
	m_pWindow = SDL_CreateWindow(
								  APP_TITLE, I_WINDOW_X, I_WINDOW_Y, 
								  _screenWidth, _screenHeight, 
								  displaymode ); // 4:3
	if( m_pWindow == nullptr ) result = I_INIT_RETURN_STEP2;
	else
	{
		SDL_GetWindowSize( m_pWindow, &m_iWindowWidth, &m_iWindowHeight );
		// Step 3
		m_pRenderer = SDL_CreateRenderer( m_pWindow, I_RENDERER_IDX, 
										  SDL_RENDERER_ACCELERATED );
		if( m_pRenderer == nullptr ) result = I_INIT_RETURN_STEP3;
		else
		{
			// Step 4
			m_pEvent = new SDL_Event();
			if( m_pEvent == nullptr ) result = I_INIT_RETURN_STEP4;
			else
			{
				result = Mix_OpenAudio( I_FREQUENCY, MIX_DEFAULT_FORMAT,
										I_CHANNELS, I_CHUNKSIZE );
				if( result < I_INIT_SUCCESS) 
					std::cout << Mix_GetError() << std::endl;
				if( result < I_INIT_SUCCESS) result = I_INIT_RETURN_STEP5;
				else
				{
					/*-------------------------------------------------------*/
					//m_pSounds-Initialisierungen von Marcus Schaal
					//auf SFX angepasst
					m_pSounds[SFX_ELEM_NONE] = 
						Mix_LoadWAV( m_cSfxNone );

					m_pSounds[SFX_ELEM_JUMP] =
						Mix_LoadWAV(m_cSfxJump);

					m_pSounds[SFX_ELEM_COIN] = 
						Mix_LoadWAV( m_cSfxCoin );

					m_pSounds[SFX_ELEM_DK_STOMP] = 
						Mix_LoadWAV( m_cSfxDKStomp );

					m_pSounds[SFX_ELEM_WALKING] = 
						Mix_LoadWAV( m_cSfxWalking );
					m_pSounds[SFX_ELEM_GET_POINTS] = 
						Mix_LoadWAV( m_cSfxGetPoints );

					m_pSounds[SFX_ELEM_DEATH] = 
						Mix_LoadWAV( m_cSfxDeath );
					/*-------------------------------------------------------*/
					for( int i = SFX_ELEM_NONE; i < SFX_ELEM_COUNT; i++ )
					{
						if( m_pSounds[i] == nullptr )
						{
							result = I_INIT_RETURN_STEP6;
						}
					}
					/*-------------------------------------------------------*/
					//m_pAtmo-Initialisierungen von Marcus Schaal
					//auf BGM & SFX angepasst
					m_pAtmo[BGM_ELEM_NONE] = 
						Mix_LoadMUS(m_cBgmNone);

					m_pAtmo[BGM_ELEM_INTRO1] = 
						Mix_LoadMUS(m_cBgmIntro1);

					m_pAtmo[BGM_ELEM_INTRO2] = 
						Mix_LoadMUS(m_cBgmIntro2);

					m_pAtmo[BGM_ELEM_HOW_HIGH] = 
						Mix_LoadMUS(m_cBgmHowHigh);

					m_pAtmo[BGM_ELEM_LEVEL_START] = 
						Mix_LoadMUS(m_cBgmLevelStart);

					m_pAtmo[BGM_ELEM_LEVEL] = 
						Mix_LoadMUS(m_cBgmLevel);

					m_pAtmo[BGM_ELEM_HAMMER] = 
						Mix_LoadMUS(m_cBgmHammer);

					m_pAtmo[BGM_ELEM_WIN] = 
						Mix_LoadMUS(m_cBgmWin);
					/*-------------------------------------------------------*/
					Mix_VolumeMusic(I_INIT_VOLUME);
					if (m_pAtmo == nullptr) result = I_INIT_RETURN_STEP6;
					/*---------------------------------------------------*/
						//ab hier von Niklas Englmeier
					else
					{
						result = TTF_Init();
						if (result < I_INIT_SUCCESS) return I_INIT_RETURN_STEP7;

						m_pDataManager = new DataManager();
						if (m_pDataManager == NULL) {
							return I_INIT_RETURN_STEP8;
						}
					}
					//bis hier von Niklas Englmeier
					/*---------------------------------------------------*/
				}
			}
		}
	}

	// Wenn irgendwas schief gegangen ist (result!=0), aufräumen!
	switch (result)
	{
		case I_INIT_RETURN_STEP6: Mix_CloseAudio(); // nobreak;
		case I_INIT_RETURN_STEP5: SAFE_DELETE( m_pEvent ); // nobreak;
		case I_INIT_RETURN_STEP4: SDL_DestroyRenderer(m_pRenderer); // nobreak;
		case I_INIT_RETURN_STEP3: SDL_DestroyWindow(m_pWindow); // nobreak;
		case I_INIT_RETURN_STEP2: SDL_Quit(); // nobreak;
			return result;
	}
	
	// Keyboardzeug initialisieren
	SDL_GetKeyboardState(&m_iKeyboardArraySize); // Wie groß muss das array sein?
	m_pOldKeyboardState = new Uint8[m_iKeyboardArraySize];
	m_pNewKeyboardState = new Uint8[m_iKeyboardArraySize];

	// keyboardarrays initialisieren
	SDL_memset(m_pOldKeyboardState, I_MEMSET_C, m_iKeyboardArraySize);
	SDL_memset(m_pNewKeyboardState, I_MEMSET_C, m_iKeyboardArraySize);

	// Deltatime initialisieren
	m_tLastFrameTime = SDL_GetTicks();
	m_tActualFrameTime = m_tLastFrameTime;

	m_bRunning = true;

	return I_INIT_SUCCESS;
}

/*****************************************************************************/
void CEngine::Finalize()
{
	if( m_pNewKeyboardState != nullptr ) delete[] m_pNewKeyboardState;
	if( m_pOldKeyboardState != nullptr ) delete[] m_pOldKeyboardState;

	// Sounds aufräumen
	Mix_HaltMusic();
	/*-----------------------------------------------------------------------*/
	//ab hier von Marcus BGM & SFX-enum angepasst
	for (int i = BGM_ELEM_NONE; i < BGM_ELEM_COUNT; i++) //MS: Literale entf.
	{
		if (m_pAtmo[i] != nullptr)
		{
			Mix_FreeMusic(m_pAtmo[i]);
			m_pAtmo[i] = nullptr;
		}
	}
	for (int i = SFX_ELEM_NONE; i < SFX_ELEM_COUNT; i++) //MS: Literale entf.
	{
		if (m_pSounds[i] != nullptr)
		{
			Mix_FreeChunk(m_pSounds[i]);
			m_pSounds[i] = nullptr;
		}
	}
	/*-----------------------------------------------------------------------*/
	Mix_CloseAudio();

	if( m_pEvent != nullptr )
	{
		delete m_pEvent;
		m_pEvent = nullptr;
	}
	if (m_pRenderer != nullptr)
	{
		SDL_DestroyRenderer(m_pRenderer);
		m_pRenderer = nullptr;
	}
	if (m_pWindow != nullptr)
	{
		SDL_DestroyWindow(m_pWindow);
		m_pWindow = nullptr;
	}

	SDL_Quit();
}

// Mapping - gewünschter Code => SDL_Scancode
/*****************************************************************************/
SDL_Scancode CEngine::KeyToSDL( int _key )
{
	switch( _key )
	{
		case C_W_KEY: return SDL_SCANCODE_W;
		case C_A_KEY: return SDL_SCANCODE_A;
		case C_S_KEY: return SDL_SCANCODE_S;
		case C_D_KEY: return SDL_SCANCODE_D;
		//case 'k', case '-' & case '+' von Marcus Schaal entfernt
		case C_SPACE_KEY: return SDL_SCANCODE_SPACE;
		case VK_UP: return SDL_SCANCODE_UP;
		case VK_DOWN: return SDL_SCANCODE_DOWN;
		case VK_LEFT: return SDL_SCANCODE_LEFT;
		case VK_RIGHT: return SDL_SCANCODE_RIGHT;
		case VK_ESCAPE: return SDL_SCANCODE_ESCAPE;
		case VK_DELETE: return SDL_SCANCODE_DELETE; //NE
		default: return SDL_SCANCODE_UNKNOWN;
	}
}

/*****************************************************************************/
bool CEngine::HasKeyBeenPressed( int _key )
{
	SDL_Scancode key = KeyToSDL( _key );

	// War im alten und ist nicht im neuen state gedrückt
	return( m_pOldKeyboardState[ key ] && !m_pNewKeyboardState[ key ] );
}

/*****************************************************************************/
bool CEngine::IsKeyPressed( int _key )
{
	SDL_Scancode key = KeyToSDL( _key );

	return( m_pNewKeyboardState[ key ] );
}

/*****************************************************************************/
SDL_Point CEngine::GetMousePosition()
{
	SDL_Point pt;
	SDL_GetMouseState( &pt.x, &pt.y );

	return pt;
}

/*****************************************************************************/
bool CEngine::IsMouseButtonUp()
{	
	//MS: _which entfernt
	// atm only left button
	return(m_pEvent->type == SDL_MOUSEBUTTONUP &&
		m_pEvent->button.button == SDL_BUTTON_LEFT);
}

/***************************************************************************** 
 * _which is ignored, atm only left button									 * 
 *****************************************************************************/
bool CEngine::IsMouseButtonDown()
{	
	return(m_pEvent->type == SDL_MOUSEBUTTONDOWN &&
		m_pEvent->button.button == SDL_BUTTON_LEFT);
}

/*****************************************************************************/
void CEngine::SetWindowTitle( std::string _title )
{
	SDL_SetWindowTitle( m_pWindow, _title.c_str() );
}
/*---------------------------------------------------------------------------*/
//ab hier in Ralf Hüwes Methoden von Marcus Schaal bearbeitet
/*****************************************************************************/
void CEngine::PlaySFX(int _sfxChannel, SFX _sfxIdx, int _sfxLoop)
{
	if (_sfxIdx == SFX_ELEM_COUNT)
		//MS: Um zu verhindern das Count ausgeführt wird
	{
		//MS: Literal in folgender Zeile entfernt
		Mix_PlayChannel(_sfxChannel, m_pSounds[SFX_ELEM_NONE], _sfxLoop);
	}
	else
	{
		//MS: Literale in folgender Zeile entfernt
		Mix_PlayChannel(_sfxChannel, m_pSounds[_sfxIdx], _sfxLoop);
	}

}

//*****************************************************************************/
void CEngine::PlayMusic(BGM _bgmIdx, int _BgmLoop)
{
	if (_bgmIdx == BGM_ELEM_COUNT) //MS: Literal entfernt
		//MS: Um zu verhindern das Count ausgeführt wird
	{
		//MS: Literale in folgender Zeile entfernt
		Mix_PlayMusic(m_pAtmo[BGM_ELEM_NONE], _BgmLoop);
	}
	else
	{
		Mix_PlayMusic(m_pAtmo[_bgmIdx], _BgmLoop); //MS: Literal entfernt
	}
}
//bis hier von Marcus Schaal bearbeitet
/*---------------------------------------------------------------------------*/

//*****************************************************************************/
void CEngine::StopMusic()
{
	Mix_HaltMusic();
}

/*****************************************************************************/
void CEngine::CalcDeltaTime()
{
	m_tActualFrameTime = SDL_GetTicks();
	m_fDeltaTime = ( m_tActualFrameTime - m_tLastFrameTime ) / F_SEC; // [sec]
	m_tLastFrameTime = m_tActualFrameTime;
	m_fDeltaTime2 = m_fDeltaTime; // von Sandro und Stefan

	if (m_bGameIsPaused) { m_fDeltaTime = F_DELTA_TIME_ZERO; } //SW
}

/*****************************************************************************/
int CEngine::Update()
{
	CalcDeltaTime();

	SDL_PollEvent(m_pEvent);

	// Ansonsten den eingetroffenen Event ggf. bearbeiten
	switch(m_pEvent->type)
	{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		case SDL_KEYDOWN:
			if (m_pEvent->key.keysym.sym == SDLK_ESCAPE)
			{
				m_bRunning = false;
			}
			break;
	}

	SDL_memcpy( m_pOldKeyboardState, m_pNewKeyboardState, 
				m_iKeyboardArraySize );
	SDL_memcpy( m_pNewKeyboardState, SDL_GetKeyboardState(nullptr), 
				m_iKeyboardArraySize );

	return I_UPDATE_SUCCESS;
}

/*****************************************************************************/
void CEngine::Render()
{
	SDL_RenderClear(m_pRenderer);
}