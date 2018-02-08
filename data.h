/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data.h
 * Author: Mikadows
 *
 * Created on 21 janvier 2018, 15:00
 */

#ifndef DATA_H
#define DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "code.h"
    
void ajouterCodeSecretData(code c);
void ajouterNombreMancheData(int nbManche);
void sendCodeSecretData(code *cs);
void addScoreData(score s);
void sendScoreData(score *sc);
void sendNbPtWinData(int *ptWin);
int addHscJvJData(highscore hsc);
int saveData();
static int ouvrirFichierData(FILE **f, int mode);
static int fermerFichierData(FILE **f);



#ifdef __cplusplus
}
#endif

#endif /* DATA_H */

