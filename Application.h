/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Application.h
 * Author: Mikadows
 *
 * Created on 21 janvier 2018, 14:59
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "code.h"
    
void color(int t,int f);
void viderTamponEntree();
void start();
int nb_rand(int entrer);
int verifCodeSaisieApp(code c, int entrer);
int verifNbMancheApp(int nbManche);
code convertCode(code c);
int checkCodeNbPionsApp(int nb);
int verifCodeFoundedApp(code try);
int verifEndGameApp(int tour, int found);
int winApp(int tour);
void initScoreApp();
score getScoreApp();
int defScoreApp(int winner, int joueurDefCode);
int quiJouApp(int joueurDefCode);
code defCodeIaApp();
int checkCodeApp(int y, code try);
code sendCodeApp();
int verifNomsJoueursApp(highscore hsc, int mode);

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_H */

