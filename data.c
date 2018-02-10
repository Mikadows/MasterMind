/*
 * MasterMind couche Data.
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Application.h"
#include "data.h"
#include "code.h"

static code codeSecret;
static int nombreDeManche = 0;
static score scoreDeLaGame;
static highscore scVsFriend[3];
static highscore scVsIA[3];

/**
 * Ajoute le code secret à la data
 * @param c     <-- Code secret à ajouter.
 */
void ajouterCodeSecretData(code c){
    codeSecret = c;
}
/**
 * Ajoute le nombre de manche à la data
 * @param nbManche  <-- Nombre de manche à ajouter.
 */
void ajouterNombreMancheData(int nbManche){
    nombreDeManche = nbManche;
}
/**
 * Envoie le code secret 
 * @param cs    <-- Pointeur sur le code secret à ajouter.
 */
void sendCodeSecretData(code *cs){
    *cs = codeSecret;
}
/**
 * Ajoute le score de la game
 * @param s <-- Score de la game à ajouter à ajouter.
 */
void addScoreData(score s){
    scoreDeLaGame = s;
}
/**
 * Envoie le score de la game
 * @param sc    <-- Pointeur sur le score à ajouter.
 */
void sendScoreData(score *sc){
    *sc = scoreDeLaGame;
}
/**
 * Envoie le high score au rang demandé du mode de jeux demandé
 * @param hsc       <-- Pointeur sur HighScore
 * @param rang      <-- Rang du highscore du tableau demandé
 * @param mode      <-- 1 ou 2 en fonction du mode de jeux
 *                      1 pour J vs J
 *                      2 pour J vs IA
 */
void sendHighScoreData(highscore *hsc, int rang, int mode){
    switch(mode){
        case 1:
            *hsc = scVsFriend[rang];
            break;
        case 2:
            *hsc = scVsIA[rang];
            break;
        case 3:
            break;
    }
}
/**
 * Envoie le nombre de points gagnant
 * @param ptWin     <-- pointeur sur le nombre de points gagnants
 */
void sendNbPtWinData(int *ptWin){
    *ptWin = nombreDeManche;
}
/**
 * Ajoute à les highScore
 * @param hsc   <-- HighScore à ajouter.
 * @param mode  <-- 1 ou 2 en fonction du mode de jeux
 *                  1 pour J vs J
 *                  2 pour J vs IA
 * @return 1 si bien ajouté ou 0 si non ajouté
 */
int addHscData(highscore hsc, int mode){
   int ret=0, i=0;
   
   switch(mode){
       case 1:
            for(i=0; i<3; i++){
                if ((abs(hsc.sc.scoreJ1 - hsc.sc.scoreJ2)) >= (abs(scVsFriend[i].sc.scoreJ1 - scVsFriend[i].sc.scoreJ2))){
                    strcpy(scVsFriend[i].nomJ1, hsc.nomJ1);
                    strcpy(scVsFriend[i].nomJ2, hsc.nomJ2);
                    scVsFriend[i].sc.scoreJ1 = hsc.sc.scoreJ1;
                    scVsFriend[i].sc.scoreJ2 = hsc.sc.scoreJ2;
                    strcpy(scVsFriend[i].date, hsc.date);
                    i=4;
                    ret=1;
                }
            }   
           break;
       case 2:
            for(i=0; i<3; i++){
                if ((abs(hsc.sc.scoreJ1 - hsc.sc.scoreJ2)) >= (abs(scVsIA[i].sc.scoreJ1 - scVsIA[i].sc.scoreJ2))){
                    strcpy(scVsIA[i].nomJ1, hsc.nomJ1);
                    strcpy(scVsIA[i].nomJ2, hsc.nomJ2);
                    scVsIA[i].sc.scoreJ1 = hsc.sc.scoreJ1;
                    scVsIA[i].sc.scoreJ2 = hsc.sc.scoreJ2;
                    strcpy(scVsIA[i].date, hsc.date);
                    i=4;
                    ret=1;
                }
            }              
           break;
   }

   return(ret);
}
/**
 * Charge le fichier
 * @return 1 si bien éxécuté, 0 si erreur
 */
int chargerData(){
    FILE *f;
    int ret = 0;
    
    if (ouvrirFichierData(&f, 2)){
        fread(scVsFriend, sizeof(highscore), 3, f);
        ret = 1;
    }
    if(!fermerFichierData(&f)){
        ret = 0;
    }
    if (ouvrirFichierData(&f, 4)){
        fread(scVsIA, sizeof(highscore), 3, f);
        ret = 1;
    }
    if(!fermerFichierData(&f)){
        ret = 0;
    }

    return(ret);
}
/**
 * Sauvegarde le fichier
 * @return 1 si bien éxécuté, 0 si erreur
 */
int saveData(){
    FILE *f = NULL;
    int ret=0, i=0;

    if (ouvrirFichierData(&f, 1)) {
        fwrite(scVsFriend, sizeof(highscore), 3, f);
        ret = 1;
    }
    if(!fermerFichierData(&f)){
        ret = 0;
    }
    if (ouvrirFichierData(&f, 3)) {
        fwrite(scVsIA, sizeof(highscore), 3, f);
        ret = 1;
    }
    if(!fermerFichierData(&f)){
        ret = 0;
    }    
    return(ret);
}
/**
 * Remplis les tableaux des HighScores pour tester
 */
void testData(){
    strcpy(scVsFriend[0].nomJ1, "Un truc");
    scVsFriend[0].sc.scoreJ1 = 5;
    strcpy(scVsFriend[0].nomJ2, "Simple");
    scVsFriend[0].sc.scoreJ2 = 2;
    strcpy(scVsFriend[0].date, "blabla 08/42/2076 blabla");
    strcpy(scVsFriend[1].nomJ1, "Jean");
    scVsFriend[1].sc.scoreJ1 = 3;
    strcpy(scVsFriend[1].nomJ2, "val Jean");
    scVsFriend[1].sc.scoreJ2 = 1;
    strcpy(scVsFriend[1].date, "ouioui 08/42/2076 ouioui");
    strcpy(scVsFriend[2].nomJ1, "Un truc");
    scVsFriend[2].sc.scoreJ1 = 1;
    strcpy(scVsFriend[2].nomJ2, "val Jean");
    scVsFriend[2].sc.scoreJ2 = 0;
    strcpy(scVsFriend[2].date, "naynay 08/42/2076 naynay");
    
    strcpy(scVsIA[0].nomJ1, "Robert");
    scVsIA[0].sc.scoreJ1 = 5;
    strcpy(scVsIA[0].nomJ2, "IA");
    scVsIA[0].sc.scoreJ2 = 2;
    strcpy(scVsIA[0].date, "blabla 08/42/2076 blabla");
    strcpy(scVsIA[1].nomJ1, "Jean");
    scVsIA[1].sc.scoreJ1 = 3;
    strcpy(scVsIA[1].nomJ2, "IA");
    scVsIA[1].sc.scoreJ2 = 1;
    strcpy(scVsIA[1].date, "ouioui 08/42/2076 ouioui");
    strcpy(scVsIA[2].nomJ1, "Math");
    scVsIA[2].sc.scoreJ1 = 1;
    strcpy(scVsIA[2].nomJ2, "IA");
    scVsIA[2].sc.scoreJ2 = 0;
    strcpy(scVsIA[2].date, "naynay 08/42/2076 naynay");
}
/**
 * Ouvre un flux vers un fichier
 * @param f     <-- Descripteurs de fichiers
 * @param mode  <-- Mode d'ouverture
 *                  1 : Ouvre en mode ECRITURE le fichier J vs J
 *                  2 : Ouvre en mode LECTURE le fichier J vs J
 *                  3 : Ouvre en mode ECRITURE le fichier J vs IA
 *                  4 : Ouvre en mode LECTURE le fichier J vs IA
 * @return 1 si bien éxécuté, 0 si erreur
 */
static int ouvrirFichierData(FILE **f, int mode){
    int ret=0;
    
    switch(mode){
        case 1:     //Permet d'ouvrir le fichier Joueur vs Joueur pour l'écrire
            if(fopen("masterMindHSJvJ.bin", "wb+") == NULL){
                ret=0;
            }else{
                *f = fopen("masterMindHSJvJ.bin", "wb+");
                ret = 1;
            }
            break;
        case 2:     //Permet d'ouvrir le fichier Joueur vs Joueur pour le lire
            if(fopen("masterMindHSJvJ.bin", "rb") == NULL){
                ret=0;
            }else{
                *f = fopen("masterMindHSJvJ.bin", "rb");
                ret = 1;
            }            
            break;
        case 3:     //Permet d'ouvrir le fichier Joueur vs IA pour l'écrire
            if(fopen("masterMindHSJvIA.bin", "wb+") == NULL){
                ret=0;
            }else{
                *f = fopen("masterMindHSJvIA.bin", "wb+");
                ret = 1;
            }            
            break;
        case 4:     //Permet d'ouvrir le fichier Joueur vs IA pour le lire
            if(fopen("masterMindHSJvIA.bin", "rb") == NULL){
                ret=0;
            }else{
                *f = fopen("masterMindHSJvIA.bin", "rb");
                ret = 1;
            }               
            break;
    }
    return(ret);
}
/**
 * Ferme un flux vers le fichier
 * @param f     <-- Descripteurs de fichiers
 * @return 1 si bien éxécuté, 0 si erreur
 */
static int fermerFichierData(FILE **f){
    int ret=0;
    
    if(fclose(*f) == 0){
        ret = 1;
    }
    return(ret);
}