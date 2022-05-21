/*****************************************************************************
* Project: SDLFramework
* File   : Level.cpp
* Date   : 14.01.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	14.01.20	MS	Created,
*					CLadder und Child-Classes hinzugefügt
*	15.01.20	MS	DefaultObject hinzugefügt,
*					Update-Methode hinzugefügt
*	20.01.20	MS	Finalize zu FINALIZE_DELETE(x),
*					Engine-Methoden mit for-Schleife vereinfacht,
*					Gravitation erweitert, 
*					Leveltiles justiert
*	23.01.20	MS	Schwerkraft realisiert
*	29.01.20	MS	Spritegröße verdoppelt und Positionen angepasst
*	30.01.20	MS	Schwerkraft Kreis-Box-Kollision hinzugefügt
*					Leiter-Initialisierung mit InitLadder vereinfacht
*	03.02.20	MS	Leiter-Initialisierung vollendet
*					Plattform-Initialisierungen vollendet
*	04.02.20	MS	Plattform-Getter + Levelunabhängige UseGravity-Funktion
*	10.02.20	MS	Schwerkraftfunktionen Rückgabewerte hinzugefügt
*	12.02.20	MS	Plattform und Level Initialize um Position erweitert
*	13.02.20	MS	Literale aus Plattform/Leiterinitialisierungen nach
*					LevelConfig.
*	17.02.20	MS	LevelConfig-include in Header
*	01.03.20	MS	Plattform & Leiterinitialisierungen auf Konstruktor 
*					umgestellt
*	02.03.20	MS	Literale entfernt
******************************************************************************/
#include "Level.h"
#include "Engine.h"
#include "Collision.h"
#include <iostream>


/*****************************************************************************/
//Inititalisierungen
/*****************************************************************************/
//Leiter-Initialisierung 
/*****************************************************************************/
int CLevel::InitLadder( float _PosX, float _PosY, int _Elem )
{
	m_pLadder[_Elem] = new CLadder( _PosX, _PosY );
	m_pLadder[_Elem]->Initialize();

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Leiter-Initialisierung (Überladung)
/*****************************************************************************/
int CLevel::InitLadder( float _constX, float _firstY,
						int _firstElem, int _elemLimit )
{
	/* _ElementLimit ist immer um eine ganze Zahl größer,
	   als das letzte Leiterelement.

	   _step zeigt immer die Anzahl der Pixelhöhe eines Sprites an*/

	for( int i = _firstElem; i < _elemLimit; i++ )
	{
		//Anzahl der Pixel zwischen den Leitern werden errechnen
		float incr = static_cast<float>( ( i - _firstElem ) * I_LDR_INCR );

		//Initialisierung der aktuellen Leiter + Überladung
		m_pLadder[i] = new CLadder( _constX, _firstY + incr );

		//Position der jeweiligen Leiter
		m_pLadder[i]->Initialize();
	}
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Initialisierung aller Leitern
/*****************************************************************************/
int CLevel::InitAllLadders() //Leiter aus LevelConfig als LDR abgekürzt
{ 
	//Leitern von 1 - 19
	InitLadder( F_LDR_1_X,  F_LDR_1_Y,  LDR_1_1ST_IDX,  LDR_1_LAST_IDX ); 
	InitLadder( F_LDR_2_X,  F_LDR_2_Y,  LDR_2_1ST_IDX,  LDR_2_LAST_IDX ); 
	InitLadder( F_LDR_3_X,  F_LDR_3_Y,  LDR_3_IDX_1,  LDR_3_LAST_IDX ); 
	InitLadder( F_LDR_4_X,  F_LDR_4_Y,  LDR_4_IDX ); 				    
	InitLadder( F_LDR_5_X,  F_LDR_5_Y,  LDR_5_1ST_IDX,  LDR_5_LAST_IDX );
	InitLadder( F_LDR_6_X,  F_LDR_6_Y,  LDR_6_1ST_IDX,  LDR_6_LAST_IDX );
	InitLadder( F_LDR_7_X,  F_LDR_7_Y,  LDR_7_1ST_IDX,  LDR_7_LAST_IDX );
	InitLadder( F_LDR_8_X,  F_LDR_8_Y,  LDR_8_1ST_IDX,  LDR_8_LAST_IDX );
	InitLadder( F_LDR_9_X,  F_LDR_9_Y,  LDR_9_IDX );				    
	InitLadder( F_LDR_10_X, F_LDR_10_Y, LDR_10_IDX );			        
	InitLadder( F_LDR_11_X, F_LDR_11_Y, LDR_11_IDX );				    
	InitLadder( F_LDR_12_X, F_LDR_12_Y, LDR_12_IDX );				    
	InitLadder( F_LDR_13_X, F_LDR_13_Y, LDR_13_1ST_IDX, LDR_13_LAST_IDX );
	InitLadder( F_LDR_14_X, F_LDR_14_Y, LDR_14_1ST_IDX, LDR_14_LAST_IDX );
	InitLadder( F_LDR_15_X, F_LDR_15_Y, LDR_15_1ST_IDX, LDR_15_LAST_IDX );
	InitLadder( F_LDR_16_X, F_LDR_16_Y, LDR_16_1ST_IDX, LDR_16_LAST_IDX );
	InitLadder( F_LDR_17_X, F_LDR_17_Y, LDR_17_IDX );			        
	InitLadder( F_LDR_18_X, F_LDR_18_Y, LDR_18_IDX );		 		    
	InitLadder( F_LDR_19_X, F_LDR_19_Y, LDR_19_1ST_IDX, LDR_19_LAST_IDX );
	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
// Plattform-Initialisierung
/*****************************************************************************/
int CLevel::InitPlatform( float _firstX, float _constY, int _firstElem, 
						  int _ElemLimit )
{
	/* _ElementLimit ist immer um eine ganze Zahl größer,
	   als das letzte Leiterelement.

	   _step zeigt immer die Anzahl der Pixelhöhe eines Sprites an*/
	for( int i = _firstElem; i < _ElemLimit; i++ )
	{
		//Anzahl der Pixel zwischen den Platformen werden errechnen
		float incr = static_cast<float>( ( i - _firstElem ) * PL_INCR );

		//Initialisierung der aktuellen Platform
		m_pPlatform[i] = new CPlatform( _firstX + incr, _constY );

		//Position der jeweiligen Platformen
		m_pPlatform[i]->Initialize();
	}

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Plattform-Initialisierung (Überladung)
/*****************************************************************************/
int CLevel::InitPlatform( float _firstX, float _firstY, int _firstElem, 
						  int _ElemLimit, int _step )
{
	/* _ElementLimit ist immer um eine ganze Zahl größer,
	   als das letzte Leiterelement.

	   _step zeigt immer die Anzahl der Pixelhöhe eines Sprites an*/
	for( int i = _firstElem; i < _ElemLimit; i++ )
	{
		//Anzahl der Pixel zwischen den Platformen werden errechnen
		float incrX = static_cast<float>( ( i - _firstElem ) * PL_INCR );
		float incrY = static_cast<float>( ( i - _firstElem ) * _step );

	   //Initialisierung der aktuellen Platform
		m_pPlatform[i] = new CPlatform( _firstX + incrX, _firstY + incrY );

		//Position der jeweiligen Platformen
		m_pPlatform[i]->Initialize();
	}

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Initialisierung aller Plattformen
/*****************************************************************************/
int CLevel::InitAllPlatforms() //Plattform aus LevelConfig als PL abgekürzt
{
	//1. Plattform
	InitPlatform( F_PL_1_X, F_PL_1_Y, PL_1_1ST_IDX, PL_1_LAST_IDX );

	//2. Plattform (grader Teil)
	InitPlatform( F_PL_2_1_X, F_PL_2_1_Y, PL_2_1_1ST_IDX, PL_2_1_LAST_IDX );

	//2. Plattform (schräger Teil)
	InitPlatform( F_PL_2_2_X, F_PL_2_2_Y, PL_2_2_1ST_IDX, PL_2_2_LAST_IDX, 
				  I_PL_STEP_INRC );  

	//3. Plattform
	InitPlatform( F_PL_3_X, F_PL_3_Y, PL_3_1ST_IDX, PL_3_LAST_IDX, I_PL_STEP_DECR );

	//4. Plattform
	InitPlatform( F_PL_4_X, F_PL_4_Y, PL_4_1ST_IDX, PL_4_LAST_IDX, I_PL_STEP_INRC );

	//5. Plattform
	InitPlatform( F_PL_5_X, F_PL_5_Y, PL_5_1ST_IDX, PL_5_LAST_IDX, I_PL_STEP_DECR ); 

	//6. Plattform
	InitPlatform( F_PL_6_X, F_PL_6_Y, PL_6_1ST_IDX, PL_6_LAST_IDX, I_PL_STEP_INRC );

	//7. Plattform (grader Teil)
	InitPlatform( F_PL_7_1_X, F_PL_7_1_Y, PL_7_1_1ST_IDX, PL_7_1_LAST_IDX );

	//7. Plattform (schräger Teil)
	InitPlatform( F_PL_7_2_X, F_PL_7_2_Y, PL_7_2_1ST_IDX, PL_7_2_LAST_IDX, 
				  I_PL_STEP_DECR);

	return I_SUCCESS;
}
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
//Haupt-Initialisierung
/*****************************************************************************/
int CLevel::Initialize()
{
	//Masseninitialisierungen
	InitAllLadders();
	InitAllPlatforms();


	//Kollisions-Box-Objekt-Initialisierungen
	m_pLeftBoundary = new CBoxCollObject();
	m_pLeftBoundary->Initialize( F_L_BOUNDARY_X, F_L_BOUNDARY_Y, 
								 I_L_BOUNDARY_W, I_L_BOUNDARY_H );

	m_pRightBoundary = new CBoxCollObject();
	m_pRightBoundary->Initialize( F_R_BOUNDARY_X, F_R_BOUNDARY_Y, 
								  I_R_BOUNDARY_W, I_R_BOUNDARY_H );

	m_pWinArea = new CBoxCollObject();
	m_pWinArea->Initialize( F_WIN_AREA_X, F_WIN_AREA_Y, 
							I_WIN_AREA_W, I_WIN_AREA_H );

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Finalisierung
/*****************************************************************************/
void CLevel::Finalize()
{
	m_pWinArea->Finalize();
	m_pRightBoundary->Finalize();
	m_pLeftBoundary->Finalize();

	for (int i = PL_LAST_IDX; i > M_I_FINALIZE_LIMIT; i--)
	{

		FINALIZE_DELETE(m_pPlatform[i]);
	}

	for (int i = LDR_LAST_IDX; i > M_I_FINALIZE_LIMIT; i--)
	{
		FINALIZE_DELETE(m_pLadder[i]);

	}
}
/*****************************************************************************/

/*****************************************************************************/
//Update
/*****************************************************************************/
int CLevel::Update()
{
	for (CTile* elem : m_pLadder)
	{
		elem->Update();
	}

	for (CTile* elem : m_pPlatform)
	{
		elem->Update();
	}

	return I_SUCCESS;
}
/*****************************************************************************/

/*****************************************************************************/
//Render
/*****************************************************************************/
void CLevel::Render()
{
	for (CTile* elem : m_pLadder)
	{
		elem->Render();
	}

	for (CTile* elem : m_pPlatform)
	{
		elem->Render();
	}
}
/*****************************************************************************/