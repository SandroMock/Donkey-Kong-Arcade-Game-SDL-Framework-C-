/*****************************************************************************
* Project:	SDLFramework
* File   :	Engine.h
* Date   :	18.12.2019
* Author :	Ralf Hüwe (RH)
*			Marcus Schaal (MS)
*			Stephan Weber (SW)
*			Sandro Mock	(SM)
*			Niklas Englmeier(NE)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	18.12.19	RH	Created
*	14.02.20	NE	+sdl_ttf
*	25.02.20	MS	Musik überarbeitet, enum SOUNDS entfernt
*	27.02.20	MS	Weitere Audioquellen hinzugefügt
*	28.02.20	NE	+DataManager
*	29.02.20	MS	+Attribute
*	02.03.20	MS	Werte für Vorinitialisierungen, + Parameter bei PlayMusic
*	02.03.20	SW	namespace std wir jetzt genutzt
*					Deltatime kann mit hilfe einer Methode auf 0 gesetzt werden
*	03.03.20	MS	Coin-Geröusch hinzugefügt
*	03.03.20	SM/SW +DeltaTime2
*	05.03.20	MS	Literale entfernt & ins Reine geschrieben
******************************************************************************/
#pragma once
#include <string>
#include <SDL.h>
#undef main
#include <SDL_mixer.h>
#include <SDL_ttf.h> //von Niklas Englmeier
#include "Defines.h"
#include "DataManager.h" //von Niklas Englmeier

#pragma comment( lib, "SDL2.lib" )
#pragma comment( lib, "SDL2_mixer.lib" )
#pragma comment( lib, "SDL2_ttf.lib" ) //von Niklas Englmeier

using namespace std;

//enum SOUNDS von Marcus Schaal entfernt
/*---------------------------------------------------------------------------*/
//MS: enum SOUNDS von Ralf Hüwe nachempfunden
enum BGM { BGM_NONE, BGM_INTRO1, BGM_INTRO2, BGM_HOW_HIGH, BGM_LEVEL_START,
		   BGM_LEVEL, BGM_HAMMER, BGM_WIN, BGM_COUNT };
enum SFX { SFX_NONE, SFX_JUMP, SFX_COIN, SFX_DK_STOMP, SFX_WALKING, SFX_GET_POINTS,
		   SFX_DEATH, SFX_COUNT };

//Werte für Vorinitialisierung
const int	 I_BGM_LOOP        = -1;
const int	 I_SFX_LOOP		   = 0;
const int	 I_DEFAULT_VALUE   = -1;
const float	 F_DEFAULT_VALUE   = -1.0f;
const Uint32 I32_DEFAULT_VALUE = (Uint32)-1;

//Initialize
const int	I_INIT_SUCCESS		= 0;
const int	I_INIT_RETURN_STEP1 = -1;
const int	I_INIT_RETURN_STEP2 = -2;
const int	I_INIT_RETURN_STEP3 = -3;
const int	I_INIT_RETURN_STEP4 = -4;
const int	I_INIT_RETURN_STEP5 = -5;
const int	I_INIT_RETURN_STEP6 = -6;
const int	I_INIT_RETURN_STEP7 = -7;
const int	I_INIT_RETURN_STEP8 = -8;

//Window
const int	I_WINDOW_X			= 10;
const int	I_WINDOW_Y			= 30;

//Render
const int	I_RENDERER_IDX		= -1;

//Audio
const int	I_FREQUENCY			= 44100;
const int	I_CHANNELS			= 2;
const int	I_CHUNKSIZE			= 2048;
const int	I_INIT_VOLUME		= 16;

//Keyboard
const int	I_MEMSET_C			= 0;
const char	C_W_KEY				= 'w';
const char	C_A_KEY				= 'a';
const char	C_S_KEY				= 's';
const char	C_D_KEY				= 'd';
const char	C_SPACE_KEY			= ' ';

//DeltaTime
const float	F_SEC				= 1000.0f;
const float F_DELTA_TIME_ZERO	= 0;

//Update
const int	I_UPDATE_SUCCESS	= 0;
/*---------------------------------------------------------------------------*/

class CEngine
{
public:
	static int Initialize( int _screenWidth, int _screenHeight );
	static void Finalize();

	static int Update();
	static void Render();

	// bool getter, deswegen "Is"
	static bool IsRunning() { return m_bRunning; } 
	static float GetDeltaTime() { return m_fDeltaTime; }

	//folgende Zeile von Sandro und Stefan
	static float GetDeltaTime2() { return m_fDeltaTime2; } 

	// Keyboard
	static bool IsKeyPressed( int _key );
	static bool HasKeyBeenPressed( int _key );

	// Mouse
	static SDL_Point GetMousePosition();
	static bool IsMouseButtonUp(); //MS: Parameter entfernt
	static bool IsMouseButtonDown(); //MS: Parameter entfernt

	static void PauseGame( bool _bool = true ) { m_bGameIsPaused = _bool; }//SW

	static SDL_Renderer* GetRenderer() { return m_pRenderer; }
	static void SwapBackbuffer() { SDL_RenderPresent( m_pRenderer ); }
	//SetFullscreenMode von Marcus Schaal entfernt
	static int GetWindowWidth() { return m_iWindowWidth; }
	static int GetWindowHeight() { return m_iWindowHeight; }
	static void SetWindowTitle( std::string _title );

	// Sound & Music
	/*-----------------------------------------------------------------------*/
	//ab hier von Marcus Schaal bearbeitet
	//MS: PlaySound in PlaySFX umbennant um Bennenungszweideutigkeit 
	//	  zu verhindern
	//    + Parameter(PlaySFX & PlayMusic)
	static void PlaySFX( int _sfxChannel, SFX _sfxIdx, 
						 int _sfxLoop = I_SFX_LOOP );
	static void PlayMusic( BGM _bgmIdx, int _BgmLoop = I_BGM_LOOP );
	//bis hier von Marcus Schaal bearbeitet
	/*-----------------------------------------------------------------------*/
	static void StopMusic();

	static DataManager* m_pDataManager; //von Niklas Englmeier

private:
	static bool				m_bRunning;
	static bool				m_bGameIsPaused;	//SW

	static SDL_Window*		m_pWindow;
	static SDL_Renderer*	m_pRenderer;
	static SDL_Event*		m_pEvent;
	static bool				m_bFullscreen;
	static int				m_iWindowWidth;
	static int				m_iWindowHeight;

	// Deltatime
	static Uint32			m_tActualFrameTime;
	static Uint32			m_tLastFrameTime;
	static float			m_fDeltaTime;
	static float			m_fDeltaTime2; // von Sandro und Stefan

	// Array für Tastenabfrage
	static int				m_iKeyboardArraySize;
	static Uint8*			m_pOldKeyboardState;
	static Uint8*			m_pNewKeyboardState;

	// Sound & Music
	/*-----------------------------------------------------------------------*/
	//ab hier von Marcus Schaal bearbeitet
	//MS: enums hinzugefügt
	static Mix_Music*		m_pAtmo[BGM_COUNT];
	static Mix_Chunk*		m_pSounds[SFX_COUNT];
	//bis hier von Marcus Schaal bearbeitet
	/*-----------------------------------------------------------------------*/
	
	static void CalcDeltaTime();
	static SDL_Scancode KeyToSDL( int _key );

};

