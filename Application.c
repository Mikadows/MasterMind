/*
 * MasterMind couche Application.
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Application.h"
#include "IHM.h"
#include "data.h"


/**
 * Change la couleur de fond et du texte dans la console
 * @param t     parametre pour changer la couleur du texte
 * @param f     parametre pour ghanger la couleur du fond
 */
void color(int t,int f){
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}
/**
* Permet de vider le tampon d'entrée (stdin) (ex : après un scanf)
*/
void viderTamponEntree(){
    int c;
    
    while ((c = fgetc(stdin)) != '\n'){
        //puts("caractère supprimé");
    }
}

void start(){
    mainAffichaheIHM();
}
/**
 * Génère un nombre aléatoire adapté à l'entrer
 * @param entrer = 1 ou 2 | 1 pour un choix de couleur et 2 pour l'affichage.
 * @return Retourne le nombre aléatoire adapté à l'entré.
 */
int nb_rand(int entrer){
    int nb_aleatoire=0;    
    srand(time(NULL));              // initialisation de rand
    
    switch(entrer){
        case 1:
            do{
                nb_aleatoire = rand()% 15;
            }while(nb_aleatoire == 0);          // On ne sort pas de la boucle tant qu'on à 0 pour ne pas avoir du noir    
        break;
        case 2:
            nb_aleatoire = rand()% 2;
        break;
    }
    
return(nb_aleatoire);
}
/**
 * Vérifie le code couleur secret qu'on lui envoie.
 * @param c <- code secret de type code
 * @return 1 si pas d'erreur, -2 si mauvaise couleur, -1 si couleur redondante.
 */
int verifCodeSaisieApp(code c){
    int i=0, ret=1, y=0;

    for(i=0; i<4; i++){             //Test si les couleurs saisies sont bonnes 
        switch(c.codeCouleur[i]){   //Et les fais correspondres.
            case 1:
                c.codeCouleur[i] = ROUGE;
                break;
            case 2:
                c.codeCouleur[i] = JAUNEF;
                break;   
            case 3:
                c.codeCouleur[i] = VERTF;
                break;
            case 4:
                c.codeCouleur[i] = TURQ;
                break;                
            case 5:
                c.codeCouleur[i] = MARRON;
                break;
            case 6:
                c.codeCouleur[i] = BLANC;
                break;
            case 7:
                c.codeCouleur[i] = POURP;
                break;
            case 8:
                c.codeCouleur[i] = ROSEF;
                break;
            default:
                ret = -2;
                break;
        }
    }
    if(ret != -2){      //Si les couleurs saisies sont bonnes on vérifie si elles ne sont pas redondantes.
        for(y = 0; y < 4; y++){
            for(i = y + 1; i < 4; i++){
                //printf("\n y : %d - i : %d \n", y, i);
                if(c.codeCouleur[y] == c.codeCouleur[i]){
                    ret = -1;
                }     
            }       
        }
        /*for(i=1; i<4; i++){       //ancien test de redondance.
            if(c.codeCouleur[0] == c.codeCouleur[i]){
                ret=-1;
            }
        }
        for(i=2; i<4; i++){
            if(c.codeCouleur[1] == c.codeCouleur[i]){
                ret=-1;
            }
        }
        if(c.codeCouleur[2] == c.codeCouleur[i]){
            ret=-1;
        }*/
    }
    if(ret == 1){
        ajouterCodeSecretData(c);
    }
    return(ret);
}

int verifNbMancheApp(int nbManche){
    int ret = 0;
    
    if((nbManche == 1) || (nbManche == 3) || (nbManche == 5)){
        ret = 1;
        ajouterNombreManche(nbManche);
    }
    
    return(ret);
}