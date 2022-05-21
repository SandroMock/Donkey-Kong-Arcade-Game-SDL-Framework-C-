/*****************************************************************************
* Project: SDLFramework
* File   : LevelConfig.h
* Date   : 10.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	13.02.20	MS	Created
*	17.02.20	MS	Array-Größe hinzugefügt
*	19.02.20	MS	STAGE-enum hinzugefügt
*	02.03.20	MS	Leiteraussparungen hinzugefügt,
*					konstante Ebenen,
*					Kollisions-Box-Objekte hinzugefügt
*	03.03.20	MS	vorletzte Leiter-Indices (penultimate) hinzugefügt,
*					kleine & große Leiter-Indices hinzugefügt
*	04.03.20	MS	kaputte Leiter-Incidec hinzugefügt
******************************************************************************/
#pragma once

//Ebenen von oben nach unten
enum STAGE { DEFAULT_STAGE, STAGE_ONE, STAGE_TWO, STAGE_THREE, STAGE_FOUR,
			 STAGE_FIVE,STAGE_SIX, STAGE_SEVEN }; 

/*Im Folgenden wird Plattform im Bezeichner mit PL abgekürzt, Leiter mit LDR,
* große Leiter mit LLDR, kleine Leiter mit SLDR, BLDR für kaputte Leiter.
* Bei letzten und vorletzten Indexen wird nicht berücksichtigt,
* dass Arrays beginnen bei 0 zu zählen, 
* damit die For-Schleifen die Werte bekommen die sie nicht überschreiten
* dürfen.*/

const int I_SUCCESS			   = 0;
const int ZERO_IDX			   = 0;

const STAGE STAGE_DEFAULT_ELEM = DEFAULT_STAGE;
const STAGE STAGE_ELEM_ONE	   = STAGE_ONE;
const STAGE STAGE_ELEM_TWO	   = STAGE_TWO;
const STAGE STAGE_ELEM_THREE   = STAGE_THREE;
const STAGE STAGE_ELEM_FOUR	   = STAGE_FOUR;
const STAGE STAGE_ELEM_FIVE    = STAGE_FIVE;
const STAGE STAGE_ELEM_SIX     = STAGE_SIX;
const STAGE STAGE_ELEM_SEVEN   = STAGE_SEVEN;

/*****************************************************************************/
//Leitern
/*****************************************************************************/
const int	I_LDR_AR_SIZE	   = 51;
							   
//Leiterinitalisierung		   
const int	I_LDR_INCR	       = 16;
							   
//Leiter 1					   
const float F_LDR_1_X		   = 424.0f;
const float F_LDR_1_Y		   = 196.0f;
const int	LDR_1_1ST_IDX	   = ZERO_IDX;
const int	LDR_1_LAST_IDX     = 7;
							   
//Leiter 2					   
const float F_LDR_2_X		   = 456.0f;
const float F_LDR_2_Y		   = F_LDR_1_Y;
const int	LDR_2_1ST_IDX	       = LDR_1_LAST_IDX;
const int	LDR_2_LAST_IDX     = 14;
							   
//Leiter3					   
const float F_LDR_3_X		   = 552.0f;
const float F_LDR_3_Y		   = 264.0f;
const int	LDR_3_IDX_1	       = LDR_2_LAST_IDX;
const int	LDR_3_PENULT_IDX   = 16;
const int	LDR_3_LAST_IDX     = 17;
							   
//Leiter 4					   
const float F_LDR_4_X		   = 472.0f;
const float F_LDR_4_Y		   = 312.0f;
const int	LDR_4_IDX	       = LDR_3_LAST_IDX;
							   
//Leiter 5					   
const float F_LDR_5_X		   = F_LDR_4_X;
const float F_LDR_5_Y		   = 344.0f;
const int	LDR_5_1ST_IDX      = 18;
const int	LDR_5_LAST_IDX     = 20;
							   
//Leiter 6					   
const float F_LDR_6_X		   = 664.0f;
const float F_LDR_6_Y          = 312.0f;
const int	LDR_6_1ST_IDX      = LDR_5_LAST_IDX;
const int	LDR_6_PENULT_IDX   = 22;
const int	LDR_6_LAST_IDX     = 23;
							   
//Leiter 7					   
const float F_LDR_7_X		   = 360.0f;
const float F_LDR_7_Y		   = 392.0f;
const int	LDR_7_1ST_IDX	   = LDR_6_LAST_IDX;
const int	LDR_7_PENULT_IDX   = 24;
const int	LDR_7_LAST_IDX     = 25;
							   
//Leiter 8					   
const float F_LDR_8_X		   = 440.0f;
const float F_LDR_8_Y		   = 384.0f;
const int	LDR_8_1ST_IDX      = LDR_7_LAST_IDX;
const int	LDR_8_PENULT_IDX   = 27;
const int	LDR_8_LAST_IDX     = 28;
							   
//Leiter 9					   
const float F_LDR_9_X		   = 632.0f;
const float F_LDR_9_Y		   = 376.0f;
const int	LDR_9_IDX	       = LDR_8_LAST_IDX;
							   
//Leiter 10					   
const float F_LDR_10_X	       = F_LDR_9_X;
const float F_LDR_10_Y	       = 424.0f;
const int	LDR_10_IDX	       = LDR_9_IDX + 1;
							   
//Leiter 11					   
const float F_LDR_11_X	       = 424.0f;
const float F_LDR_11_Y	       = 440.0f;
const int	LDR_11_IDX	       = LDR_10_IDX + 1;
							   
//Leiter 12 				   
const float F_LDR_12_X	       = F_LDR_11_X;
const float F_LDR_12_Y	       = 488.0f;
const int	LDR_12_IDX	       = LDR_11_IDX + 1;
							   
//Leiter 13					   
const float F_LDR_13_X		   = 520.0f;
const float F_LDR_13_Y		   = 448.0f;
const int	LDR_13_1ST_IDX     = LDR_12_IDX + 1;
const int	LDR_13_PENULT_IDX  = 35;
const int	LDR_13_LAST_IDX    = 36;
							   
//Leiter 14					   
const float F_LDR_14_X		   = 664.0f;
const float F_LDR_14_Y		   = 456.0f;
const int	LDR_14_1ST_IDX	   = LDR_13_LAST_IDX;
const int	LDR_14_PENULT_IDX  = 38;
const int	LDR_14_LAST_IDX    = 39;
							 
//Leiter 15					 
const float F_LDR_15_X		   = 360.0f;
const float F_LDR_15_Y		   = 520.0f;
const int	LDR_15_1ST_IDX	   = LDR_14_LAST_IDX;
const int	LDR_15_PENULT_IDX  = 41;
const int	LDR_15_LAST_IDX    = 42;
							   
//Leiter 16					   
const float F_LDR_16_X		   = 488.0f;
const float F_LDR_16_Y		   = 512.0f;
const int	LDR_16_1ST_IDX	   = LDR_15_LAST_IDX;
const int	LDR_16_PENULT_IDX  = 45;
const int	LDR_16_LAST_IDX    = 46;
							   
//Leiter 17					   
const float F_LDR_17_X		   = 456.0f;
const float F_LDR_17_Y		   = 568.0f;
const int	LDR_17_IDX		   = LDR_16_LAST_IDX;
							   
//Leiter 18					   
const float F_LDR_18_X		   = F_LDR_17_X;
const float F_LDR_18_Y		   = 616.0f;
const int	LDR_18_IDX		   = LDR_17_IDX + 1;
							   
//Leiter 19					   
const float F_LDR_19_X		   = 664.0f;
const float F_LDR_19_Y		   = 584.0f;
const int	LDR_19_1ST_IDX	   = LDR_18_IDX + 1;
const int	LDR_19_PENULT_IDX  = 50;
const int	LDR_19_LAST_IDX    = 51;
							   
//Leiterfinalisierung		   
const int	LDR_LAST_IDX	   = 50;
/*****************************************************************************/

/*****************************************************************************/
//Plattformen
/*****************************************************************************/
const int	I_PL_AR_SIZE	   = 82;
const int	I_PL_STEP_INRC	   = 2;
const int	I_PL_STEP_DECR	   = -2;
							   
//Plattforminitialisierung	   
const int	PL_INCR			   = 32;
							   
//1. Plattform				   
const float F_PL_1_X		   = 480.0f;
const float F_PL_1_Y		   = 248.0f;
const int	PL_1_1ST_IDX	   = ZERO_IDX;
const int	PL_1_PENULT_IDX    = 2;
const int	PL_1_LAST_IDX	   = 3;
							   
//2. Plattform (grader Teil)   
const float F_PL_2_1_X		   = 304.0f;
const float F_PL_2_1_Y		   = F_PL_2_1_X;
const int	PL_2_1_1ST_IDX	   = PL_1_LAST_IDX;
const int	PL_2_BLDR_1ST_IDX  = 9;
const int	PL_2_BLDR_LAST_IDX = 10;
const int	PL_2_1_LAST_IDX    = 12;
							   
//2. Plattform (schräger Teil  )
const float F_PL_2_2_X		   = 592.0f;
const float F_PL_2_2_Y		   = 306.0f;
const int	PL_2_2_1ST_IDX	   = PL_2_1_LAST_IDX;
const int	PL_2_SLDR_1ST_IDX  = 14;
const int	PL_2_SLDR_LAST_IDX = 15;
const int	PL_2_2_LAST_IDX    = 16;
							   
//3. Plattform				   
const float F_PL_3_X		   = 336.0f;
const float F_PL_3_Y		   = 378.0f;
const int	PL_3_1ST_IDX	   = PL_2_2_LAST_IDX;
const int	PL_3_SLDR_1ST_IDX  = 17;
const int	PL_3_SLDR_LAST_IDX = 18;
const int	PL_3_LLDR_1ST_IDX  = 19;
const int	PL_3_LLDR_LAST_IDX = 20;
const int	PL_3_BLDR_1ST_IDX  = 25;
const int	PL_3_BLDR_LAST_IDX = 26;
const int	PL_3_LAST_IDX	   = 29;
							   
//4. Plattform				   
const float F_PL_4_X		   = F_PL_2_1_X;
const float F_PL_4_Y		   = 420.0f;
const int	PL_4_1ST_IDX	   = PL_3_LAST_IDX;
const int	PL_4_BLDR_1ST_IDX  = 33;
const int	PL_4_BLDR_LAST_IDX = 34;
const int	PL_4_LLDR_1ST_IDX  = 36;
const int	PL_4_LLDR_LAST_IDX = 37;
const int	PL_4_SLDR_1ST_IDX  = 40;
const int	PL_4_SLDR_LAST_IDX = 41;
const int	PL_4_LAST_IDX	   = 42;
							   
//5. Plattform				   
const float F_PL_5_X		   = F_PL_3_X;
const float F_PL_5_Y		   = 510.0f;
const int	PL_5_1ST_IDX	   = PL_4_LAST_IDX;
const int	PL_5_SLDR_1ST_IDX  = 43;
const int	PL_5_SLDR_LAST_IDX = 44;
const int	PL_5_LLDR_1ST_IDX  = 47;
const int	PL_5_LLDR_LAST_IDX = 48;
const int	PL_5_LAST_IDX	   = 55;
							   
//6. Plattform				   
const float F_PL_6_X		   = F_PL_2_1_X;
const float F_PL_6_Y		   = 552.0f;
const int	PL_6_1ST_IDX	   = PL_5_LAST_IDX;
const int	PL_6_BLDR_1ST_IDX  = 60;
const int	PL_6_BLDR_LAST_IDX = 61;
const int	PL_6_SLDR_1ST_IDX  = 66;
const int	PL_6_SLDR_LAST_IDX = 67;
const int	PL_6_LAST_IDX	   = 68;
							   
//7. Plattform (grader Teil)   
const float F_PL_7_1_X		   = F_PL_2_1_X;
const float F_PL_7_1_Y		   = 632.0f;
const int	PL_7_1_1ST_IDX	   = PL_6_LAST_IDX;
const int	PL_7_1_LAST_IDX    = 75;
							   
//7. Plattform (schräger Teil  )
const float F_PL_7_2_X		   = 528.0f;
const float F_PL_7_2_Y		   = 630.0f;
const int	PL_7_2_1ST_IDX	   = PL_7_1_LAST_IDX;
const int	PL_7_2_LAST_IDX    = 82;
							   
//Plattformfinalisierung	   
const int	PL_LAST_IDX		   = 81;
/*****************************************************************************/

/*****************************************************************************/
// Kollisions-Box-Objekte
/*****************************************************************************/
//linke Außenbegrenzung
const float F_L_BOUNDARY_X	   = 143.0f;
const float	F_L_BOUNDARY_Y	   = 384.0f;
const int	I_L_BOUNDARY_W	   = 288;
const int	I_L_BOUNDARY_H	   = 768;
							   
//rechte Außenbegrenzung	   
const float	F_R_BOUNDARY_X	   = 882.0f;
const float F_R_BOUNDARY_Y	   = 384.0f;
const int	I_R_BOUNDARY_W	   = 288;
const int	I_R_BOUNDARY_H	   = 768;
							   
//Siegesbereich				   
const float	F_WIN_AREA_X	   = 512.0f;
const float F_WIN_AREA_Y	   = 201.0f;
const int	I_WIN_AREA_W	   = 96;
const int	I_WIN_AREA_H	   = 16;
/*****************************************************************************/