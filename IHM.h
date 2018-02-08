/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IHM.h
 * Author: Mikadows
 *
 * Created on 21 janvier 2018, 14:59
 */

#ifndef IHM_H
#define IHM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "code.h"
#include "color.h"
    
void affMainMenuIHM(int nbColor);
void mainAffichaheIHM();
void affArretIHM();
void affMainTitleIHM(int nbAff, int nbColor);
void playVsFriendIHM();
void colorDispoIHM(int nbColor, int entrer);
code defCodeIHM(int nbAff, int nbColor, int joueurDefCode);
int nbManchesIHM(int nbAff, int nbColor, int mode);
void plateauDeJeuxIHM(int nbColor);
int gameIHM(int mode);
void affichTentativeIHM(code c, int y);
int checkCodeIHM(int y);
void affPionRougeIHM(int nbPions, int y);
void affPionBlancIHM(int nbPions, int y);
void clearBottomClearIHM();
void affichScoreIHM(score s);
void regleJcJIHM(int nbColor, int nbAff);
void playVsIaIHM(int nbAff, int nbColor);
void affCodeSecretIHM();
void affGGIHM();
void askScoreIHM(int mode);
highscore saisieNomsJoueursIHM();
    
#ifdef __cplusplus
}
#endif

#endif /* IHM_H */

