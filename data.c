/*
 * MasterMind couche Data.
 */
#include "data.h"
#include "code.h"


static code codeSecret;
static int nombreDeManche = 0;

void ajouterCodeSecretData(code c){   
    codeSecret = c;
}

void ajouterNombreManche(int nbManche){
    nombreDeManche = nbManche;
}
