/*
 * MasterMind couche IHM.
 */

/*                                                                                                                                            
 *   
 * 
  __  __              _                __  __  _             _ 
 |  \/  |            | |              |  \/  |(_)           | |
 | \  / |  __ _  ___ | |_  ___  _ __  | \  / | _  _ __    __| |
 | |\/| | / _` |/ __|| __|/ _ \| '__| | |\/| || || '_ \  / _` |
 | |  | || (_| |\__ \| |_|  __/| |    | |  | || || | | || (_| |
 |_|  |_| \__,_||___/ \__|\___||_|    |_|  |_||_||_| |_| \__,_|
                                                                                                                             
 * 
 *  
___  ___             _               ___  ___ _             _ 
|  \/  |            | |              |  \/  |(_)           | |
| .  . |  __ _  ___ | |_  ___  _ __  | .  . | _  _ __    __| |
| |\/| | / _` |/ __|| __|/ _ \| '__| | |\/| || || '_ \  / _` |
| |  | || (_| |\__ \| |_|  __/| |    | |  | || || | | || (_| |
\_|  |_/ \__,_||___/ \__|\___||_|    \_|  |_/|_||_| |_| \__,_|
   
 *         
 $$$$$$\                                 $$\     
$$  __$$\                                $$ |    
$$ /  $$ | $$$$$$\   $$$$$$\   $$$$$$\ $$$$$$\   
$$$$$$$$ |$$  __$$\ $$  __$$\ $$  __$$\\_$$  _|  
$$  __$$ |$$ |  \__|$$ |  \__|$$$$$$$$ | $$ |    
$$ |  $$ |$$ |      $$ |      $$   ____| $$ |$$\ 
$$ |  $$ |$$ |      $$ |      \$$$$$$$\  \$$$$  |
\__|  \__|\__|      \__|       \_______|  \____/ 
 * 
 * 
"\t╔══════════════════════════════════════════════════╗ \n"
"\t║\t• 12 Rouge\t\t• 4  Marron        ║\n"
"\t║                                    \t\t   ║\n"
"\t║\t• 14 Jaune\t\t• 15 Blanc         ║\n"
"\t║                                    \t\t   ║\n"
"\t║\t• 10 Vert \t\t• 5  Violet        ║\n"
"\t║                                    \t\t   ║\n"
"\t║\t• 11 Bleu \t\t• 13 Rose          ║\n"
"\t╚══════════════════════════════════════════════════╝ \n"
 * 
"\t╔══════════════════════════════════════════════════╗ \n"
"\t║\t• 12 Rouge\t\t• 4  Marron        ║\n"
"\t║                                    \t\t   ║\n"
"\t║\t• 14 Jaune\t\t• 15 Blanc         ║\n
"\t║                                    \t\t   ║  ╔═══════╗\n
"\t║\t• 10 Vert \t\t• 5  Violet        ║  ║            ║\n
"\t║                                    \t\t   ║  ╠═══╦═══╣\n 
"\t║\t• 11 Bleu \t\t• 13 Rose          ║  ║     ║     ║\n
"\t╚══════════════════════════════════════════════════╝  ╚═══╩═══╝\n
 * ╔═══════╗\n
 * ║            ║\n
 * ╠═══╦═══╣\n 
 * ║     ║     ║\n 
 * ╚═══╩═══╝\n"
 * 
 * ╔═══╦═══╦═══╦═══╗\n
 * ║     ║     ║     ║     ║\n
 * ╠═══╬═══╬═══╬═══╣\n
 * ╚═══╩═══╩═══╩═══╝\n
 * 
 * ╔═══════════════════════════════════════════════════════════════════╗\n
 * ║                                            • !! Règles du Jeux !! •                                         ║\n
 * ║                                                                                                             ║\n
 * ║                                          •   Joueur  contre Joueur   •                                      ║\n
 * ║                  En JcJ, vous devez définir le nombre de manches gagnantes pour remporter la partie.        ║\n                                      
 * ║                     Le "Joueur1" doit composé un code secret de 4 couleurs différentes.                     ║\n
 * ║                          Ce code couleur devra être composé des couleurs proposés.                          ║\n
 * ║                Après ceci l'autre "Joueur2" à 12 tentatives pour trouver le code secret.                    ║\n
 * ║                                                                                                             ║\n
 * ║             • Après chaque tentatives du "Joueur2" le "Joueur1" lui indique si dans la proposition,         ║\n
 * ║             un ou plusieurs "pions" de couleurs sont bien dans la combinaison et à la bonne place,          ║\n
 * ║             en plaçant des "pions" rouges selon le nombre.                                                  ║\n
 * ║             • Le "Joueur1" fera de même en indiquant si dans la proposition, un ou plusieurs pions          ║\n
 * ║             de couleurs sont bien dans la combinaison mais pas à la bonne place, en plaçant des             ║\n
 * ║             "pions" blancs selon le nombre.                                                                 ║\n
 * ║                                                                                                             ║\n
 * ║             Au bout des 12 tentavies si le code secret n'est pas trouvé, le "Joueur1" remporte la           ║\n
 * ║            manche et 1 point. Si le code est trouvé le "Joueur2" remporte la manche et le point.            ║\n
 * ║                                                                                                             ║\n 
 * ║                                 Quand une manche est gagné les rôles s'inversent.                           ║\n
 * ║                                                                                                             ║\n
 * ╚═══════════════════════════════════════════════════════════════════╝\n
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Application.h"
#include "IHM.h"
#include "conio21/conio.c"

/**
 * Menu principal du MasterMind.
 */
void mainAffichaheIHM(){
    int nbColor=0, nbAff=0, choix=0;

    
    system("chcp 65001");   //Permet l'affichage des caratères spéciaux/ASCII étendue.
    system("cls");
    
    nbAff = nb_rand(2);
    nbColor = nb_rand(1);

    do{
        system("mode con lines=40 cols=120"); //Permet de configurer la taille de la console, lines=NombreDeLigne (hauteur) && cols=NombreDeColonnes (Largeur).
        system("cls");
        affMainTitleIHM(nbAff, nbColor);       
        affMainMenuIHM(nbColor);
        scanf("%d", &choix);
        viderTamponEntree();
    
        switch(choix){
            case 1:
                playVsFriendIHM(nbAff, nbColor);
                break;
            case 2:
                playVsIaIHM(nbAff, nbColor);
                break;
            case 3:
            
                break;
            case 0:
                affArretIHM();
                break;
            default:
                system("cls");
                break;
        }
    }while(choix != 0);
}
/**
 * Affiche "Arret" puis ferme le programme.
 */
void affArretIHM(){
    system("cls");
    color(ROUGE, NOIR);
    printf("\n\n\n\n\n\t\t\t\t $$$$$$\\                                 $$\\         \n"
           "\t\t\t\t$$  __$$\\                                $$ |         \n"
           "\t\t\t\t$$ /  $$ | $$$$$$\\   $$$$$$\\   $$$$$$\\ $$$$$$\\     \n"
           "\t\t\t\t$$$$$$$$ |$$  __$$\\ $$  __$$\\ $$  __$$\\_$$  _|      \n"
           "\t\t\t\t$$  __$$ |$$ |  \\__|$$ |  \\__|$$$$$$$$ | $$ |        \n"
           "\t\t\t\t$$ |  $$ |$$ |      $$ |      $$   ____| $$ |$$\\      \n"
           "\t\t\t\t$$ |  $$ |$$ |      $$ |      \\$$$$$$$\\  \\$$$$  |   \n"
           "\t\t\t\t\\__|  \\__|\\__|      \\__|       \\_______|  \\____/ \n\n\n\n\n\n\n");
    system("pause");
}
/**
 * Fonction pour l'affichage du titre "MasterMind"
 * @param nbAff Parametre pour l'affichage aléatoire de l'écriture
 * @param nbColor Parametre pour la couleur du cadre 
 */
void affMainTitleIHM(int nbAff, int nbColor){
    
    switch(nbAff){
        case 0:
            color(nbColor, NOIR);
            printf("\n\n\n\t\t**********************************************************************************\n"
                   "\t\t**                                                                       \t**\n"
                   "\t\t**\t");
            color(14, NOIR);
            printf("  __  __              _                __  __  _             _");
            color(nbColor,  NOIR);
            printf("       \t**\n\t\t**\t ");
            color(14, NOIR);
            printf("|  \\/  |            | |              |  \\/  |(_)           | |");
            color(nbColor,  NOIR);
            printf("    \t**\n\t\t**\t ");
            color(14, NOIR);
            printf("| \\  / |  __ _  ___ | |_  ___  _ __  | \\  / | _  _ __    __| |");
            color(nbColor,  NOIR);
            printf("    \t**\n\t\t**\t ");
            color(14, NOIR);
            printf("| |\\/| | / _` |/ __|| __|/ _ \\| '__| | |\\/| || || '_ \\  / _` |");
            color(nbColor,  NOIR);
            printf("  \t**\n\t\t**\t ");
            color(14, NOIR);
            printf("| |  | || (_| |\\__ \\| |_|  __/| |    | |  | || || | | || (_| |");
            color(nbColor,  NOIR);
            printf("    \t**\n\t\t**\t ");
            color(14, NOIR);
            printf("|_|  |_| \\__,_||___/ \\__|\\___||_|    |_|  |_||_||_| |_| \\__,_|");
            color(nbColor,  NOIR);
            printf("  \t**\n\t\t**\t                                                                     \t**\n"
                    "\t\t**\t                                                                     \t**\n"
                    "\t\t**********************************************************************************\n\n");
            color(BLANC, NOIR);          
        break;
        
        case 1:
            color(nbColor, NOIR);
            printf("\n\n\n\t\t**********************************************************************************\n"
                   "\t\t**                                                                              **\n"
                   "\t\t**\t ");
            color(14, NOIR);
            printf("___  ___             _               ___  ___ _             _");
            color(nbColor, NOIR);
            printf("          **\n\t\t**\t ");
            color(14, NOIR);
            printf("|  \\/  |            | |              |  \\/  |(_)           | |");
            color(nbColor, NOIR);
            printf("         **\n\t\t**\t ");
            color(14, NOIR);
            printf("| .  . |  __ _  ___ | |_  ___  _ __  | .  . | _  _ __    __| |");
            color(nbColor, NOIR);
            printf("         **\n\t\t**\t ");
            color(14, NOIR);
            printf("| |\\/| | / _` |/ __|| __|/ _ \\| '__| | |\\/| || || '_ \\  / _` |");
            color(nbColor, NOIR);
            printf("         **\n\t\t**\t ");
            color(14, NOIR);
            printf("| |  | || (_| |\\__ \\| |_|  __/| |    | |  | || || | | || (_| |");
            color(nbColor, NOIR);
            printf("         **\n\t\t**\t ");
            color(14, NOIR);
            printf("\\_|  |_/ \\__,_||___/ \\__|\\___||_|    \\_|  |_/|_||_| |_| \\__,_|");
            color(nbColor, NOIR);
            printf("         **\n\t\t**\t                                                                        **\n"
                   "\t\t**\t                                                                        **\n"
                   "\t\t**********************************************************************************\n\n");
            color(BLANC, NOIR);
        break;       
    }        
}
/**
 * Affichage du menu principal du programme 
 * @param nbColor Parametre pour la couleur des chiffres.
 */
void affMainMenuIHM(int nbColor){
    
        color(nbColor, NOIR);
        printf("\t\t\t\t\t 1 ");
        color(ROUGE, NOIR);
        printf("- ");
        color(JAUNEF, NOIR);
        printf("Jouer contre un amis  \n");
        color(nbColor, NOIR);
        printf("\t\t\t\t\t 2 ");
        color(ROUGE, NOIR);
        printf("- ");
        color(JAUNEF, NOIR);
        printf("Jouer contre une IA  \n");
        color(nbColor, NOIR);
        printf("\t\t\t\t\t 3 ");
        color(ROUGE, NOIR);
        printf("- ");
        color(JAUNEF, NOIR);
        printf("High Score          \n\n");
        color(ROUGE, NOIR);
        printf("\t\t\t\t\t 0 - Fermer le programme   \n");
        color(nbColor, NOIR);
        printf("\n\n\t\tChoix: ");
        color(BLANC, NOIR);    
}
/**
 * Permet de lancer une partie contre un amis.
 * @param nbAff Parametre pour l'affichage du titre
 * @param nbColor Parametre pour la couleur du cadre 
 */
void playVsFriendIHM(int nbAff, int nbColor){
    int ret=0, joueurDefCode=2;
    code c;
    score s;
    
    regleJcJIHM(nbColor, nbAff);
    initScoreApp();
    
    do{ //On définit le nombre de manche
        ret = verifNbMancheApp(nbManchesIHM(nbAff, nbColor, 1));
        if(ret == 1){
            color(VERTF, NOIR);
            printf("\n\t\t\t\tNombre de manche bien enregistré !\n");
            color(BLANC, NOIR);
        }else{
            color(ROUGE, NOIR);
            printf("\n\t\t\t\tERREUR:");
            color(BLANC, NOIR);            
            printf(" vous avez saisie un mauvais nombre de manche !!\n");            
        }
        system("pause");
        system("cls");        
    }while(ret != 1);
    
    do{
        joueurDefCode = quiJouApp(joueurDefCode);
        do{ //On définis le code couleur secret à trouver.
            system("mode con lines=40 cols=120"); //Permet de configurer la taille de la console, lines=NombreDeLigne (hauteur) && cols=NombreDeColonnes (Largeur).
            system("cls");
            ret = verifCodeSaisieApp(defCodeIHM(nbAff, nbColor,joueurDefCode), 1);
            switch(ret){
                case -2:
                    color(ROUGE, NOIR);
                    printf("\n\t\t\t\tERREUR:");
                    color(BLANC, NOIR);            
                    printf(" vous avez saisie une mauvaise couleur !!\n");
                    break;
                case -1:
                    color(ROUGE, NOIR);
                    printf("\n\t\t\t\tERREUR:");
                    color(BLANC, NOIR);            
                    printf(" Il y a des couleurs identiques dans le code !!\n");
                    break;
                case 1:
                    color(VERTF, NOIR);
                    printf("\n\t\t\t\tCode corect et bien enregistré!\n");
                    color(BLANC, NOIR);
                    break;  
            }
            system("pause");
            system("cls");
        }while(ret != 1);
    
        //configuration de l'écran de jeux
        system("mode con lines=50 cols=80");
        colorDispoIHM(nbColor, 2); 
        plateauDeJeuxIHM(nbColor);
        s = getScoreApp();        
        affichScoreIHM(s);
        //Lance la partie
        ret = gameIHM(1);    //Retoune 1 si J1 win ou 2 si J2 win
        //Ajoute un point au gagnant
        ret = defScoreApp(ret, joueurDefCode);
        switch(ret){
            case 1:
                printf("Score bien ajouté !");
                break;
            case 0:
                printf("ERREUR: dans l'ajout des score");
                break;
        }
        system("pause");
        
        ret = endGameApp();
    }while(ret != -1);
}
/**
 * Affiche les couleurs disponibles pour jouer.
 * @param nbColor   <- Permet l'affichage du cadre de la même couleur que le cadre du titre principal
 * @param entrer    <- 1 ou 2 selon l'endroit appelé
 */
void colorDispoIHM(int nbColor, int entrer){
    switch(entrer){
        case 1:
            printf("\t\t\t\tLes couleurs disponibles pour composer le code sont: \n");
            color(nbColor, NOIR);
            printf("\t\t\t\t╔══════════════════════════════════════════════════╗ \n"
                   "\t\t\t\t║\t");
            color(ROUGE, NOIR);
            printf("• 1 Rouge\t\t");
            color(MARRON, NOIR);
            printf("• 5  Marron");
            color(nbColor, NOIR);
            printf("        ║\n"
                   "\t\t\t\t║                                    \t\t   ║\n"
                   "\t\t\t\t║\t");
            color(JAUNEF, NOIR);
            printf("• 2 Jaune\t\t");
            color(BLANC, NOIR);
            printf("• 6 Blanc");
            color(nbColor, NOIR);
            printf("          ║\n"
                   "\t\t\t\t║                                    \t\t   ║\n"
                   "\t\t\t\t║\t");
            color(VERTF, NOIR);
            printf("• 3 Vert \t\t");
            color(POURP, NOIR);
            printf("• 7  Violet");
            color(nbColor, NOIR);
            printf("        ║\n"
                   "\t\t\t\t║                                    \t\t   ║\n"
                   "\t\t\t\t║\t");
            color(TURQ, NOIR);
            printf("• 4 Bleu \t\t");
            color(ROSEF, NOIR);
            printf("• 8 Rose");
            color(nbColor, NOIR);
            printf("           ║\n"
                   "\t\t\t\t╚══════════════════════════════════════════════════╝  ");     
            break;
        case 2:
            color(nbColor, NOIR);
            printf("\n\t╔══════════════════════════════════════════════════╗ \n"
                   "\t║\t");
            color(ROUGE, NOIR);
            printf("• 1 Rouge\t\t");
            color(MARRON, NOIR);
            printf("• 5  Marron");
            color(nbColor, NOIR);
            printf("        ║\n"
                   "\t║                                    \t\t   ║\n"
                   "\t║\t");
            color(JAUNEF, NOIR);
            printf("• 2 Jaune\t\t");
            color(BLANC, NOIR);
            printf("• 6 Blanc");
            color(nbColor, NOIR);
            printf("          ║\n"
                   "\t║                                    \t\t   ║  ╔═══════╗\n"
                   "\t║\t");
            color(VERTF, NOIR);
            printf("• 3 Vert \t\t");
            color(POURP, NOIR);
            printf("• 7  Violet");
            color(nbColor, NOIR);
            printf("        ║  ║ ");
            color(JAUNEF, NOIR);
            printf("Score");
            color(nbColor, NOIR);
            printf(" ║\n"
                   "\t║                                    \t\t   ║  ╠═══╦═══╣\n "
                   "\t║\t");
            color(TURQ, NOIR);
            printf("• 4 Bleu \t\t");
            color(ROSEF, NOIR);
            printf("• 8 Rose");
            color(nbColor, NOIR);
            printf("           ║  ║ 0 ║ 0 ║\n"
                   "\t╚══════════════════════════════════════════════════╝  ╚═══╩═══╝\n");
            color(BLANC, NOIR);
            break;
        default:
            break;
   
    }

}
/**
 * Permet d'entré un code de couleur.
 * @param nbAff  <- permet l'affichage du titre.
 * @param nbColor   <- Permet l'affichage de la couleur du cadre.
 * @param entrer    <- 1 ou 2 selon l'endroit appelé
 * @return <- retourne le code couleur.
 */
code defCodeIHM(int nbAff, int nbColor, int joueurDefCode){          //int defCodeIHM(){
    code couleurs;
    int i=0, y=1; 
    
    switch(joueurDefCode){
        case 1:
            for(i=0; i<4; i++){
                system("cls");
                affMainTitleIHM(nbAff, nbColor);
                color(JAUNEF, NOIR);
                printf("\t\t\t\t  • Joueur");
                color(ROUGE, NOIR);
                printf(" %d", joueurDefCode);
                color(JAUNEF, NOIR);
                printf(" veuillez choisir le code couleur •\n\n");
                colorDispoIHM(nbColor, 1);
                color(JAUNEF, NOIR);
                printf("Couleur %d", y);
                color(nbColor, NOIR);
                printf(": ");
                color(BLANC, NOIR);
                scanf("%d", &couleurs.codeCouleur[i]);
                viderTamponEntree();
                y++;
            }
            break;
        case 2:
            for(i=0; i<4; i++){
                system("cls");
                affMainTitleIHM(nbAff, nbColor);
                color(JAUNEF, NOIR);
                printf("\t\t\t\t  • Joueur");
                color(ROUGE, NOIR);
                printf(" %d", joueurDefCode);
                color(JAUNEF, NOIR);
                printf(" veuillez choisir le code couleur •\n\n");                colorDispoIHM(nbColor, 1);
                color(JAUNEF, NOIR);
                printf("Couleur %d", y);
                color(nbColor, NOIR);
                printf(": ");
                color(BLANC, NOIR);
                scanf("%d", &couleurs.codeCouleur[i]);
                viderTamponEntree();
                y++;
            }
            break;            
        case 3:
            for(i=0; i<4; i++){
                color(JAUNEF, NOIR);
                clearBottomClearIHM();
                printf("Couleur %d: ",y);
                scanf("%d", &couleurs.codeCouleur[i]);
                viderTamponEntree();
                y++;                
            }
            break;
        default:
            printf("Erreur d'appel pas d'entré définie");
            break;
            
    }
    return(couleurs);
}
/**
 * Affiche et demande à l'utilisateur le nombre de manches.
 * @param nbAff  <- permet l'affichage du titre.
 * @param nbColor   <- Permet l'affichage de la couleur du cadre.
 * @return <- retourne le nombre de manche pour être vérifié.
 */
int nbManchesIHM(int nbAff, int nbColor, int mode){
    int manche = 0;
    
    system("cls");
    affMainTitleIHM(nbAff, nbColor);
    color(JAUNEF, NOIR);
    switch(mode){
        case 1:
            printf("\t\t\t\t!! Vous avez choisis le Joueur contre Joueur !!\n\n");
            printf("\t\t\t\tCombien de points gagnant ?\n"
                   "\t\t\t\t\t• 1\n"
                   "\t\t\t\t\t• 3\n"
                   "\t\t\t\t\t• 5\n"
                   "\t\t\t\tChoix");
            break;
        case 2:
            printf("\t\t\t\t!! Vous avez choisis le Joueur contre IA !!\n\n");
            printf("\t\t\t\tCombien de points gagnant ?\n"
                   "\t\t\t\t\t• 1\n"
                   "\t\t\t\t\t• 3\n"
                   "\t\t\t\t\t• 5\n"
                   "\t\t\t\tChoix");
            break;
    }

    color(nbColor, NOIR);
    printf(" : ");
    color(BLANC, NOIR);
    scanf("%d", &manche);
    viderTamponEntree();
    
    return(manche);
}
/**
 * Affiche le plateau de Jeux
 * @param nbColor   <- paramettre de la couleur du plateau de jeux
 */
void plateauDeJeuxIHM(int nbColor){
    int i=0;
    
    color(nbColor, NOIR);
    printf("\n\t\t\t╔═══╦═══╦═══╦═══╗\n");
    for(i=0; i<11; i++){
        printf("\t\t\t║   ║   ║   ║   ║\n"
               "\t\t\t╠═══╬═══╬═══╬═══╣\n");
    }
    printf("\t\t\t║   ║   ║   ║   ║\n"
           "\t\t\t╚═══╩═══╩═══╩═══╝\n\n");
    color(BLANC, NOIR);
    gotoxy(1,37);
}
/**
 * Permet de lancer la partie.
 */
int gameIHM(int mode){
    int ret=1, x=27, y=13, tour=12, found=0, i=0;
    code try;
    
    do{
        do{
            try = defCodeIHM(0, 0, 3);
            ret = verifCodeSaisieApp(try, 0);
            switch(ret){
                case 1:
                    color(VERTF, NOIR);
                    printf("Code OK!");
                    color(BLANC, NOIR);
                    try = convertCode(try);
                    break;
                case -2:
                    color(ROUGE, NOIR);
                    printf("ERREUR: ");
                    color(BLANC, NOIR);
                    printf("vous avez saisie une mauvaise couleur !!\n");
                    break;
                default:
                    printf("unexpeted error");
                    break;
            }
        }while(ret != 1);
    
        affichTentativeIHM(try, y);
        switch(mode){
            case 1:
                y = checkCodeIHM(y);
                break;
            case 2:
                y = checkCodeApp(y, try);
                break;
        }
        found = verifCodeFoundedApp(try);
        tour--;
        ret = verifEndGameApp(tour, found);
    }while(ret != -1);
    ret = winApp(tour);
    return(ret);
}
/**
 * Affiche la tentative de code du joueur.
 * @param c     <- tentavie du code.
 * @param y     <- Rang auquel écrire.
 */
void affichTentativeIHM(code c, int y){
    int x=27, i=0;
    
    for(x=27; x<40; x+=4){
        gotoxy(x, y);
        color(c.codeCouleur[i], NOIR);
        printf("■");    //■
        i++;
    }
    clearBottomClearIHM();
}
/**
 * Permet de saisir et afficher le nombre de pions bon, mauvais etc ...
 * @param y     <-  Permet d'écrire à la bonne ligne.
 * @return y+2  <-  Retourne le prochain rang auquel écrire.
 */
int checkCodeIHM(int y){
    int ret = 0, nbPions=0, x=20, i=0;
    
    do{    
        clearBottomClearIHM();
        color(JAUNEF, NOIR);
        printf("Nombre de pions de la bonne couleur et bien placé: ");
        scanf("%d", &nbPions);
        ret = checkCodeNbPionsApp(nbPions);
        viderTamponEntree();
    }while(ret != 1);
    affPionRouge(nbPions, y);
    color(BLANC, NOIR);
    clearBottomClearIHM();
    do{
        color(JAUNEF, NOIR);
        printf("Nombre de pions de la bonne couleur et mal placé: ");
        scanf("%d", &nbPions);
        ret = checkCodeNbPionsApp(nbPions);
        viderTamponEntree();
        clearBottomClearIHM();        
    }while(ret != 1);
    affPionBlanc(nbPions, y);
    clearBottomClearIHM();
    
    return(y+2);
}
/**
 * Affiche les pionts rouges (bon et bien placé)
 * @param nbPions   <-- Nombre de pions à placer
 * @param y     <-- rang auquel écrire.
 */
void affPionRouge(int nbPions, int y){
    int x=20, i=0;
    
    color(ROUGE, NOIR);
    for(i=0; i<nbPions; i++){
        gotoxy(x, y);
        printf("●");
        x-=2;
    }
}
/**
 * Affiche les pionts blanc (Bon mais mal placé)
 * @param nbPions   <-- Nombre de pions à placer
 * @param y     <-- rang auquel écrire.
 */
void affPionBlanc(int nbPions, int y){
    int x=44, i=0;
    
    color(BLANC, NOIR);
    for(i=0; i<nbPions; i++){
        gotoxy(x, y);
        printf("●");
        x+=2;
    }
}

/**
 * Efface la partie basse de l'écrans quand la partie est en cours.
 */
void clearBottomClearIHM(){
    gotoxy(1,37);
    printf("                                                                \n"
           "                                                                \n"
           "                                                                \n"
           "                                                                \n");
    gotoxy(1,37);
}
/**
 * Affiche le score de la partie.
 * @param s <-- Score de la partie.
 */
void affichScoreIHM(score s){
    //TODO: faire les gotoxy au bon endroit pour afficher le score
    //system("cls");
    color(JAUNEF, NOIR);
    gotoxy(65, 9);
    printf("%d", s.scoreJ1);
    gotoxy(69, 9);
    printf("%d", s.scoreJ2);
}
/**
 * Affiche les règles
 * @param nbColor   <-- Couleur pour l'affichage
 * @param nbAff     <-- Nombre pour l'affichage du titre
 */
void regleJcJIHM(int nbColor, int nbAff){
    system("cls");
    affMainTitleIHM(nbAff, nbColor);
    color(nbColor, NOIR);
    printf("    ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n"
           "    ║                                            ");
    color(ROUGE, NOIR);
    printf("•");
    color(JAUNEF, NOIR);
    printf(" !! Règles du Jeux !!");
    color(ROUGE, NOIR);
    printf(" •");
    color(nbColor, NOIR);
    printf("                                         ║\n"
           "    ║                                                                                                             ║\n"
           "    ║                                          ");
    color(ROUGE, NOIR);
    printf("•");
    color(JAUNEF, NOIR);
    printf("   Joueur  contre Joueur   ");
    color(ROUGE, NOIR);
    printf("•");
    color(nbColor, NOIR);
    printf("                                      ║\n"
           "    ║                  ");
    color(JAUNEF, NOIR);
    printf("En JcJ, vous devez définir le nombre de manches gagnantes pour remporter la partie.");
    color(nbColor, NOIR);
    printf("        ║\n"                                     
           "    ║                     ");
    color(JAUNEF, NOIR);
    printf("Le \"Joueur1\" doit composé un code secret de 4 couleurs différentes.");
    color(nbColor, NOIR);
    printf("                     ║\n"
           "    ║                          ");
    color(JAUNEF, NOIR);
    printf("Ce code couleur devra être composé des couleurs proposés.");
    color(nbColor, NOIR);
    printf("                          ║\n"
           "    ║                ");
    color(JAUNEF, NOIR);
    printf("Après ceci l'autre \"Joueur2\" à 12 tentatives pour trouver le code secret.");
    color(nbColor, NOIR);
    printf("                    ║\n"
           "    ║                                                                                                             ║\n"
           "    ║             ");
    color(ROUGE, NOIR);
    printf("•");
    color(JAUNEF, NOIR);
    printf(" Après chaque tentatives du \"Joueur2\" le \"Joueur1\" lui indique si dans la proposition,");
    color(nbColor, NOIR);
    printf("         ║\n"
           "    ║             ");
    color(JAUNEF, NOIR);
    printf("un ou plusieurs \"pions\" de couleurs sont bien dans la combinaison et à la bonne place,");
    color(nbColor, NOIR);
    printf("          ║\n"
           "    ║             ");
    color(JAUNEF, NOIR);
    printf("en plaçant des \"pions\" rouges selon le nombre.");
    color(nbColor, NOIR);
    printf("                                                  ║\n"
           "    ║             ");
    color(ROUGE, NOIR);
    printf("•");
    color(JAUNEF, NOIR);
    printf(" Le \"Joueur1\" fera de même en indiquant si dans la proposition, un ou plusieurs pions");
    color(nbColor, NOIR);
    printf("          ║\n"
           "    ║             ");
    color(JAUNEF, NOIR);
    printf("de couleurs sont bien dans la combinaison mais pas à la bonne place, en plaçant des");
    color(nbColor, NOIR);
    printf("             ║\n"
           "    ║             ");
    color(JAUNEF, NOIR);
    printf("\"pions\" blancs selon le nombre.");
    color(nbColor, NOIR);
    printf("                                                                 ║\n"
           "    ║                                                                                                             ║\n"
           "    ║             ");
    color(JAUNEF, NOIR);
    printf("Au bout des 12 tentavies si le code secret n'est pas trouvé, le \"Joueur1\" remporte la");
    color(nbColor, NOIR);
    printf("           ║\n"
           "    ║            ");
    color(JAUNEF, NOIR);
    printf("manche et 1 point. Si le code est trouvé le \"Joueur2\" remporte la manche et le point.");
    color(nbColor, NOIR);
    printf("            ║\n"
           "    ║                                                                                                             ║\n"
           "    ║                                 ");
    color(JAUNEF, NOIR);
    printf("Quand une manche est gagné les rôles s'inversent.");
    color(nbColor, NOIR);
    printf("                           ║\n"
           "    ║                                                                                                             ║\n"
           "    ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    color(BLANC, NOIR);
    system("pause");
}

void playVsIaIHM(int nbAff, int nbColor){
    int ret=0, joueurDefCode=2, i=0;
    code c;
    score s;
    
    //regleJcJIHM(nbColor, nbAff);
    initScoreApp();
    
    do{ //On définit le nombre de manche
        ret = verifNbMancheApp(nbManchesIHM(nbAff, nbColor, 2));
        if(ret == 1){
            color(VERTF, NOIR);
            printf("\n\t\t\t\tNombre de manche bien enregistré !\n");
            color(BLANC, NOIR);
        }else{
            color(ROUGE, NOIR);
            printf("\n\t\t\t\tERREUR:");
            color(BLANC, NOIR);            
            printf(" vous avez saisie un mauvais nombre de manche !!\n");            
        }
        system("pause");
        system("cls");        
    }while(ret != 1);
    
    do{
        do{ //On définis le code couleur secret à trouver.
            system("mode con lines=40 cols=120"); //Permet de configurer la taille de la console, lines=NombreDeLigne (hauteur) && cols=NombreDeColonnes (Largeur).
            system("cls");
            ret = verifCodeSaisieApp(defCodeIaApp(), 1);
        }while(ret != 1);

        //configuration de l'écran de jeux
        system("mode con lines=50 cols=80");
        colorDispoIHM(nbColor, 2); 
        plateauDeJeuxIHM(nbColor);
        s = getScoreApp();        
        affichScoreIHM(s);
        //Lance la partie
        ret = gameIHM(2);    //Retoune 1 si J1 win ou 2 si J2 win
        //Ajoute un point au gagnant
        ret = defScoreApp(ret, joueurDefCode);
        switch(ret){
            case 1:
                printf("Score bien ajouté !");
                break;
            case 0:
                printf("ERREUR: dans l'ajout des score");
                break;
        }
        system("pause");
        
        ret = endGameApp();
    }while(ret != -1);
}