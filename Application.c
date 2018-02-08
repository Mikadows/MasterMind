/*
 * MasterMind couche Application.
 */
#include <string.h>
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
/**
 * Lance le programme
 */
void start(){
    //testData();
    if (!chargerData()){
        affErreurLoadIHM();
    }
    mainAffichaheIHM();
    if(!saveData()){
        affErreurSaveIHM();
    }
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
            nb_aleatoire = rand()% 15 +1;         //+1 pour ne pas être à 0    
            break;
        case 2:
            nb_aleatoire = rand()% 2;
            break;
        case 3:
            nb_aleatoire = rand()%8 +1;         //+1 pour ne pas être à 0
            break;
    }
    
return(nb_aleatoire);
}
/**
 * Vérifie le code couleur secret qu'on lui envoie. Si elle est bonne, la stock dans data.
 * @param c <- code secret de type code
 * @return 1 si pas d'erreur, -2 si mauvaise couleur, -1 si couleur redondante.
 */
int verifCodeSaisieApp(code c, int entrer){
    int i=0, ret=0, y=0;

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
    
    if((ret != -2) && (entrer != 0)){      //Si les couleurs saisies sont bonnes on vérifie si elles ne sont pas redondantes.
        ret=1;
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
    if((ret == 0) && (entrer == 0)){
        ret=1;
    }

    return(ret);
}
/**
 * Vérifie le nombre de manches
 * @param nbManche      <- Nombre manches a vérifier
 * @return retourne 1 si la valeur est bonne
 */
int verifNbMancheApp(int nbManche){
    int ret = 0;
    
    if((nbManche == 1) || (nbManche == 3) || (nbManche == 5)){
        ret = 1;
        ajouterNombreMancheData(nbManche);
    }
    
    return(ret);
}
/**
 * Convertit un code saisie
 * @param c <- prend un code
 * @return retourne le code convertit pour les couleurs console
 */
code convertCode(code c){
    int i=0;
    
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
        }
    }
    return(c);
}
/**
 * Verifie si le nombre de pions est conforme.
 * @param nb    <-  Prend le nombre de pions à vérifié.
 * @return      <-  Retourne 1 si ok.
 */
int checkCodeNbPionsApp(int nb){
    int ret =0;
    
    if((nb>-1) && (nb<5)){
        ret=1;
    }
    return(ret);
}
/**
 * Compte combien de couleurs de la propositions sont bonne et bien placé.
 * @param try   <- Prend l'essaie du joueur
 * @return      <- retourne le nombre de bon et bien placé
 */
int verifCodeFoundedApp(code try){
    int i = 0, ret=0;
    code codeSecret;
  
    sendCodeSecretData(&codeSecret);
    for(i=0; i<4; i++){
        if(codeSecret.codeCouleur[i] == try.codeCouleur[i]){
            ret+=1;
        }
    }
    return(ret);
}
/**
 * Vérifie si la partie est finie
 * @param tour  <- le nombre de 
 * @param found
 * @return 
 */
int verifEndGameApp(int tour, int found){
    int ret = 0;
    
    if((tour == 0) || (found == 4)){
        ret=-1;
    }
    return(ret);
}
/**
 * Vérifie qui à gagné la partie.
 * @param tour  <- nombre de tour joué
 * @return 1 si joueur qui def le code win, ou 2 si le code est trouvé
 */
int winApp(int tour){
    int ret = 0;
    
    if(tour == 0){
        ret = 1;
    }else{
        ret = 2;
    }
    return(ret);
}
/**
 * Initialise le score à 0 dans la partie data
 */
void initScoreApp(){
    score s;
    
    s.scoreJ1=0;
    s.scoreJ2=0; 
    addScoreData(s);
}
/**
 * Appelle et redonne le score de la partie.
 * @return  <-- retourne le score
 */
score getScoreApp(){
    score s;
    
    sendScoreData(&s);
    return(s);
}
/**
 * Définie de score de la partie en cours. Attribue les points au bon joueur
 * @param winner    <-- Type de victoire (code trouvé ou tour épuisé)
 * @param joueurDefCode     <-- Joueur qui à définie de code
 * @return  <-- 1 si bien ajouté ou 0 si erreur dans l'ajout.
 */
int defScoreApp(int winner, int joueurDefCode){
    score s;
    int ret=0;
    
    sendScoreData(&s);
    switch(joueurDefCode){
        case 1:
            switch(winner){
                case 1:
                    s.scoreJ1+=1;
                    ret=1;
                    break;
                case 2:
                    s.scoreJ2+=1;
                    ret=1;
                    break;
                default:
                    ret = 0;
                    break;
            }
            break;
        case 2:
            switch(winner){
                case 2:
                    s.scoreJ1+=1;
                    ret=1;
                    break;
                case 1:
                    s.scoreJ2+=1;
                    ret=1;
                    break;
                default:
                    ret = 0;
                    break;
            }            
            break;
    }
    addScoreData(s);
    return(ret);
}
/**
 * Vérifie si les joueurs ont atteint le nombre de point limite. Si oui,
 * met fin à la partie
 * @return <-- -1 si la partie est finie.
 */
int endGameApp(){
    int ptWin=0, ret=0;
    score s;
    
    sendNbPtWinData(&ptWin);
    sendScoreData(&s);
    if((s.scoreJ1 == ptWin) || (s.scoreJ2 == ptWin)){
        ret = -1;
    }
    return(ret);
}
/**
 * Définie quelle joueur met le code
 * @param joueurDefCode <-- Joueur qui à mit précedement le code
 * @return  <-- retourne le nouveaux joueur qui va définir le code
 */
int quiJouApp(int joueurDefCode){
    switch(joueurDefCode){
        case 1:
            joueurDefCode=2;
            break;
        case 2:
            joueurDefCode=1;
            break;
    }
    return(joueurDefCode);
}
/**
 * Definie un code couleur aléatoire
 * @return retoune le code généré
 */
code defCodeIaApp(){
    code cs;
    int i=0, nb=0;
    
    for(i=0; i<4; i++){
        do{
            nb = nb_rand(3);
            //printf("%d\n", nb);
        }while(nb == cs.codeCouleur[i-1]);
        cs.codeCouleur[i] = nb;
    }
    return(cs);
}
/**
 * Vérifie 
 * @param y
 * @param try
 * @return 
 */
int checkCodeApp(int y, code try){
    code cs;
    int i=0, j=0, nbPions=0, tmp=0;
    
    sendCodeSecretData(&cs);
    
    for(i=0; i<4; i++){         //Vérifie les pions bon et bien placés
        if(try.codeCouleur[i] == cs.codeCouleur[i]){    //Si couleur try position i == couleur code position i
            tmp = try.codeCouleur[i];
            try.codeCouleur[i] = 0;                     //Si la couleur est bien placé on met celle du try à 0 pour ne pas la re vérifier 
            nbPions+=1;
        }
    }
    affPionRougeIHM(nbPions, y);
    gotoxy(1, 37);
    //system("pause");
    nbPions=0;
    for(i=0;i<4;i++){
        if(try.codeCouleur[i] != 0){
            for(j=0;j<4;j++){
                if((try.codeCouleur[i] == cs.codeCouleur[j]) && (try.codeCouleur[i] != tmp)){
                    nbPions += 1;
                }
            }
        }
    }
    //printf("%d", nbPions);
    //system("pause");
    affPionBlancIHM(nbPions, y);
    
    return(y+2);
}
/**
 * Demande et renvoie le code secret
 * @return le code secret.
 */
code sendCodeApp(){
    code cs;
    
    sendCodeSecretData(&cs);
    return(cs);
}

int verifNomsJoueursApp(highscore hsc){
    int ret=-1, taille = 0;
    time_t temps;
    score sc;
    
    if((strlen(hsc.nomJ1)<20) && (strlen(hsc.nomJ2)<20)){
        ret=1;
        sendScoreData(&sc);
        hsc.sc = sc;
        time(&temps);
        strcpy(hsc.date, ctime(&temps));
        taille = strlen(hsc.nomJ1);
        hsc.nomJ1[taille-1] = '\0';
        taille = strlen(hsc.nomJ2);
        hsc.nomJ2[taille-1] = '\0';
        ret = addHscJvJData(hsc);
        
    }
    //system("pause");
    return(ret);
}