/*****************************************************************************
* Project: SDLFramework
* File   : PhysicsConfig.h
* Date   : 28.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	28.02.20	MS	Created
*	03.03.20	MS	Spieler-Leiter-Kollision hinzugef�gt
*	04.03.20	MS	Fass-Leiter-Kollision hinzugef�gt,
*					Flammen-Leiter-Kollision hinzugef�gt
******************************************************************************/
#pragma once
#include <Windows.h>



//Mathe
const int	I_DOUBLE		 = 2;	 //um Wert durch 2 zu teilen

/*PL als K�rzel f�r "Platform", LPL f�r "linke Plattformh�lfte"
* RPL f�r "rechte Plattformh�lfte" LDR f�r "Leiter," TL f�r "TopLeft", 
* BR f�r "BottomRight" gro�e Leiter mit LLDR, kleine Leiter mit SLDR,
* BLDR f�r "kaputte Leiter", "FL" f�r "Flamme"*/


// Overlap
const float F_PUT_OVER_PL		 = 1.0f;

// Physics
/*****************************************************************************/
//Spieler-Leiter-Kollision
/*****************************************************************************/
//Colliderverschiebungen: unteres Leiterende
const int I_LOW_LDR_TL_X		 = 22;
const int I_LOW_LDR_TL_Y		 = 0;
const int I_LOW_LDR_BR_X		 = 20;

//Colliderverschiebungen: oberes Leiterende (rechte Plattformh�lfte)
const int I_RPL_LDR_TL_X		 = 6;
const int I_RPL_LDR_TL_Y		 = 0;
const int I_RPL_LDR_BR_X		 = -20;

//Colliderverschiebungen: oberes Leiterende (linke Plattformh�lfte)
const int I_LPL_LDR_TL_X		 = 22;
const int I_LPL_LDR_TL_Y		 = 0;
const int I_LPL_LDR_BR_X		 = -20;
/*****************************************************************************/


/*****************************************************************************/
//Fass-Leiter-Kollision
/*****************************************************************************/
//2. Plattform
const int PL_2_BLDR_TL_X_IDX = 2;
const int PL_2_BLDR_TL_Y_IDX = 0;
const int PL_2_BLDR_BR_X_IDX = 0;
const int PL_2_BLDR_BR_Y_IDX = 25;

const int PL_2_SLDR_TL_X_IDX = 2;


//3. Plattform
const int PL_3_SLDR_TL_X_IDX = 0;
const int PL_3_SLDR_TL_Y_IDX = 0;
const int PL_3_SLDR_BR_X_IDX = -17;

const int PL_3_LLDR_TL_X_IDX = 0;
const int PL_3_LLDR_TL_Y_IDX = -2;
const int PL_3_LLDR_BR_X_IDX = -17;
const int PL_3_LLDR_BR_Y_IDX = 18;

const int PL_3_BLDR_TL_X_IDX = 0;
const int PL_3_BLDR_TL_Y_IDX = -2;
const int PL_3_BLDR_BR_X_IDX = -17;
const int PL_3_BLDR_BR_Y_IDX = 40;


//4. Plattform
const int PL_4_BLDR_TL_X_IDX = 18;
const int PL_4_BLDR_TL_Y_IDX = -2;
const int PL_4_BLDR_BR_X_IDX = -4;
const int PL_4_BLDR_BR_Y_IDX = 35;

const int PL_4_LLDR_TL_X_IDX = 18;
const int PL_4_LLDR_TL_Y_IDX = -2;
const int PL_4_LLDR_BR_X_IDX = 0;
const int PL_4_LLDR_BR_Y_IDX = 18;

const int PL_4_SLDR_TL_X_IDX = 2;


//5. Plattform
const int PL_5_SLDR_TL_X_IDX = 0;
const int PL_5_SLDR_TL_Y_IDX = 0;
const int PL_5_SLDR_BR_X_IDX = -17;

const int PL_5_LLDR_TL_X_IDX = 0;
const int PL_5_LLDR_TL_Y_IDX = 0;
const int PL_5_LLDR_BR_X_IDX = -17;
const int PL_5_LLDR_BR_Y_IDX = 18;


//6. Plattform
const int PL_6_BLDR_TL_X_IDX = 18;
const int PL_6_BLDR_TL_Y_IDX = -2;
const int PL_6_BLDR_BR_X_IDX = 0;
const int PL_6_BLDR_BR_Y_IDX = 29;

const int PL_6_SLDR_TL_X_IDX = 2;
/*****************************************************************************/

/*****************************************************************************/
//Flammen-Leiter-Kollision
/*****************************************************************************/
const int FL_LDR_TL_X_IDX = 18;
const int FL_LDR_TL_Y_IDX = -16;
const int FL_LDR_BR_X_IDX = 18;