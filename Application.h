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

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_H */

