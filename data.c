/*
 * MasterMind couche Data.
 */
#include "data.h"
#include "code.h"

static code codeSecret;
static int nombreDeManche = 0;
static score scoreDeLaGame;

void ajouterCodeSecretData(code c){
    codeSecret = c;
}

void ajouterNombreMancheData(int nbManche){
    nombreDeManche = nbManche;
}

void sendCodeSecretData(code *cs){
    *cs = codeSecret;
}

void addScoreData(score s){
    scoreDeLaGame = s;
}

void sendScoreData(score *sc){
    *sc = scoreDeLaGame;
}

void sendNbPtWinData(int *ptWin){
    *ptWin = nombreDeManche;
}