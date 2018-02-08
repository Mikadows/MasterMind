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

int addHscData(highscore hsc, int mode){
   int ret=0, i=0;
   
   /*hsc.sc.scoreJ1 = 3;
   hsc.sc.scoreJ2 = 2;
   
   scVsFriend[0].sc.scoreJ1 = 5;
   scVsFriend[0].sc.scoreJ2 = 2;
   scVsFriend[1].sc.scoreJ1 = 3;
   scVsFriend[1].sc.scoreJ2 = 2;
   scVsFriend[2].sc.scoreJ1 = 1;
   scVsFriend[2].sc.scoreJ2 = 0;
   
   printf("%s : %d\n"
          "%s : %d\n"
          "%s", hsc.nomJ1, hsc.sc.scoreJ1, hsc.nomJ2, hsc.sc.scoreJ2, hsc.date);*/

            //printf("( %d >= %d ) && ( %d >= %d )\n", hsc.sc.scoreJ1, scVsFriend[i].sc.scoreJ1, hsc.sc.scoreJ2, scVsFriend[i].sc.scoreJ2);
            //printf("Ajouté\n");
   switch(mode){
       case 1:
            for(i=0; i<3; i++){
                if(((hsc.sc.scoreJ1>=scVsFriend[i].sc.scoreJ1) && (hsc.sc.scoreJ2>=scVsFriend[i].sc.scoreJ2)) || ((scVsFriend[i].sc.scoreJ1 == 0) && (scVsFriend[i].sc.scoreJ2 == 0))){
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
                if(((hsc.sc.scoreJ1>=scVsIA[i].sc.scoreJ1) && (hsc.sc.scoreJ2>=scVsIA[i].sc.scoreJ2)) || ((scVsIA[i].sc.scoreJ1 == 0) && (scVsIA[i].sc.scoreJ2 == 0))){
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


int chargerData(){
    FILE *f;
    int ret = 0;
    //char tabTmp[300] = {'\0'};
    //char tabTmp2[300] = {'\0'};
    //int i=0, y=0, ret=0;
    
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
    
    /*if (ouvrirFichierData(&f, 2)){
        while(((i=fgetc(f)) != EOF)!= NULL){
            tabTmp[y]=i;
            y++;
        }
        i=0;
        strcpy(scVsFriend[i].nomJ1, strtok(tabTmp, ";"));
        scVsFriend[i].sc.scoreJ1 = atoi(strtok(NULL, ";"));
        strcpy(scVsFriend[i].nomJ2, strtok(NULL, ";"));
        scVsFriend[i].sc.scoreJ2 = atoi(strtok(NULL, ";"));
        strcpy(scVsFriend[i].date, strtok(NULL, ";"));
        i+=1;
        do{
            strcpy(scVsFriend[i].nomJ1, strtok(NULL, ";"));
            scVsFriend[i].sc.scoreJ1 = atoi(strtok(NULL, ";"));
            strcpy(scVsFriend[i].nomJ2, strtok(NULL, ";"));
            scVsFriend[i].sc.scoreJ2 = atoi(strtok(NULL, ";"));
            strcpy(scVsFriend[i].date, strtok(NULL, ";"));
            i+=1;
        }while(i < 3);
        /*for(i=0; i<3; i++){
            printf("%s : %d\n"
                   "%s : %d\n"
                   "%s\n\n", scVsFriend[i].nomJ1, scVsFriend[i].sc.scoreJ1, scVsFriend[i].nomJ2, scVsFriend[i].sc.scoreJ2, scVsFriend[i].date);
        
            system("pause");
        }*/
     /*   ret = 1;
    }
    if(!fermerFichierData(&f)){
        ret = 0;
    }
    
    if (ouvrirFichierData(&f, 4)){
        while(((i=fgetc(f)) != EOF)!= NULL){
            tabTmp2[y]=i;
            y++;
        }
        y=0;
        printf("%s\n", tabTmp2);
        system("pause");
        printf("aaaaaaaaa\n");
        system("pause");
        i=0;
        strcpy(scVsIA[i].nomJ1, strtok(tabTmp2, ";"));
        scVsIA[i].sc.scoreJ1 = atoi(strtok(NULL, ";"));
        strcpy(scVsIA[i].nomJ2, strtok(NULL, ";"));
        scVsIA[i].sc.scoreJ2 = atoi(strtok(NULL, ";"));
        strcpy(scVsIA[i].date, strtok(NULL, ";"));
        
        i+=1;
        do{
            
        
        printf("xxxxxxxxxa\n");
        system("pause");
            strcpy(scVsIA[i].nomJ1, strtok(NULL, ";"));
            scVsIA[i].sc.scoreJ1 = atoi(strtok(NULL, ";"));
            strcpy(scVsIA[i].nomJ2, strtok(NULL, ";"));
            scVsIA[i].sc.scoreJ2 = atoi(strtok(NULL, ";"));
            strcpy(scVsIA[i].date, strtok(NULL, ";"));
            i+=1;
        }while(i < 3);
        ret = 1;
    }
    if(!fermerFichierData(&f)){
        ret = 0;
    }*/
    
    return(ret);
}


int saveData(){
    FILE *f = NULL;
    int ret=0, i=0;
    char c =';';

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
    
    
   /* if(ouvrirFichierData(&f, 1)){
        for(i=0; i<3; i++){
            /*printf("%s : %d\n"
                    "%s : %d\n"
                    "%s", scVsFriend[i].nomJ1, scVsFriend[i].sc.scoreJ1, scVsFriend[i].nomJ2, scVsFriend[i].sc.scoreJ2, scVsFriend[i].date);
            
            system("pause");*/
            
    /*        fprintf(f, "%s", scVsFriend[i].nomJ1);
            fprintf(f, "%c", c);
            fprintf(f, "%d", scVsFriend[i].sc.scoreJ1);
            fprintf(f, "%c", c);
            fprintf(f, "%s", scVsFriend[i].nomJ2);
            fprintf(f, "%c", c);
            fprintf(f, "%d", scVsFriend[i].sc.scoreJ2);
            fprintf(f, "%c", c);
            fprintf(f, "%s", scVsFriend[i].date);
            fprintf(f, "%c", c);
            ret = 1;
        }
    }
    if(!fermerFichierData(&f)){
        ret = 0;
    }
    if (ouvrirFichierData(&f, 3)){
        for(i=0; i<3; i++){
            /*printf("%s : %d\n"
                    "%s : %d\n"
                    "%s", scVsFriend[i].nomJ1, scVsFriend[i].sc.scoreJ1, scVsFriend[i].nomJ2, scVsFriend[i].sc.scoreJ2, scVsFriend[i].date);
            
            system("pause");*/
            
  /*          fprintf(f, "%s", scVsIA[i].nomJ1);
            fprintf(f, "%c", c);
            fprintf(f, "%d", scVsIA[i].sc.scoreJ1);
            fprintf(f, "%c", c);
            fprintf(f, "%s", scVsIA[i].nomJ2);
            fprintf(f, "%c", c);
            fprintf(f, "%d", scVsIA[i].sc.scoreJ2);
            fprintf(f, "%c", c);
            fprintf(f, "%s", scVsIA[i].date);
            fprintf(f, "%c", c);
            ret = 1;
        }
    }
    if(!fermerFichierData(&f)){
        ret = 0;
    }*/
    
    return(ret);
}

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

static int fermerFichierData(FILE **f){
    int ret=0;
    
    if(fclose(*f) == 0){
        ret = 1;
    }
    return(ret);
}