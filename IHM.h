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
void colorDispoIHM(int nbColor);
code defCodeIHM(int nbAff, int nbColor);
int nbManchesIHM(int nbAff, int nbColor);

#ifdef __cplusplus
}
#endif

#endif /* IHM_H */
