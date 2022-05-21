#include <string>
#pragma once

using namespace std;

//Aktuelles Level
const int I_LEVEL = 0;

//Keyboard Key für Interaktion
const char C_BUTTON_CONFIRM = ' ';

//Gesamtanzahl Zeilen
const int I_ROW_COUNT = 5;
//Ranks Spalte X Position
const int I_RANKS_XPOSITION = 20;
//Scores Spalte X Position
const int I_SCORES_XPOSITION = 225;
//Names Spalte X Position
const int I_NAMES_XPOSITION = 470;
//Zeilenabstand
const int I_ROW_YOFFSET = 35;
//Abhängigkeit der Tabellen Y Position von Screenhöhe
const float F_ROW_SCREENHEIGHT_DEPENDENCE = 1.5f;

//Anzahl roter Zeilen
const int I_AMOUNT_RED_ROW = 3;
//Anzahl gelber Reihen
const int I_AMOUNT_YELLOW_ROW = 2;

//Anzahl Leben im Gamestate
const int I_LIFES_IN_LEVEL = 0;

//Credit Text
const string SZ_CREDIT_TEXT = "CREDIT 00";

//Rank 
const string SZ_FIRST = "1ST";
const int IDX_FIRST = 0;
const string SZ_SECOND = "2ND";
const int IDX_SECOND = 1;
const string SZ_THIRD = "3RD";
const int IDX_THIRD = 2;
const string SZ_FOURTH = "4TH";
const int IDX_FOURTH = 3;
const string SZ_FIFTH = "5TH";
const int IDX_FIFTH = 4;

//Table and Score
const int I_AMOUNT_ROWS = 5;
const int I_INCREASE = 1;
const int I_SCORE_DIGITS = 6;