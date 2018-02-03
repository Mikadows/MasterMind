/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   code.h
 * Author: Mikadows
 *
 * Created on 22 janvier 2018, 20:20
 */

#ifndef CODE_H
#define CODE_H

#ifdef __cplusplus
extern "C" {
#endif
  
    typedef struct{
        int scoreJ1;
        int scoreJ2;
    }score; 

    typedef struct{
        int codeCouleur[4];
    }code;
    
    typedef struct{
        char nomJ1[21];
        char nomJ2[21];
        score sc;
    }highscore;


#ifdef __cplusplus
}
#endif

#endif /* CODE_H */

