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
 * ║
 * ║                                 Quand une manche est gagné les rôles s'inversent.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Application.h"
#include "IHM.h"

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
 * @param nbAff
 * @param nbColor
 */
void playVsFriendIHM(int nbAff, int nbColor){
    int ret=0, i=0, try=12;
    code c;
    
    do{ //On définit le nombre de manche
        ret = verifNbMancheApp(nbManchesIHM(nbAff, nbColor));
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
    
    
    do{ //On définis le code couleur secret à trouver.
        ret = verifCodeSaisieApp(defCodeIHM(nbAff, nbColor));
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
    
    system("mode con lines=50 cols=80");
    printf("La partie commence !\n\n");
    //colorDispoIHM(nbColor);   //A tester et a redimensionner
    printf("Joueur 2 faite une tentative! ( %d essaie restant.)", try);
    
    
    
    system("pause");

}
/**
 * Affiche les couleurs disponibles pour jouer.
 * @param nbColor   <- Permet l'affichage du cadre de la même couleur que le cadre du titre principal
 */
void colorDispoIHM(int nbColor){
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
    printf("         ║\n"
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
    printf("          ║\n"
           "\t\t\t\t╚══════════════════════════════════════════════════╝  ");
}
/**
 * Permet d'entré un code de couleur.
 * @param nbAff  <- permet l'affichage du titre.
 * @param nbColor   <- Permet l'affichage de la couleur du cadre.
 * @return <- retourne le code couleur.
 */
code defCodeIHM(int nbAff, int nbColor){          //int defCodeIHM(){
    code couleurs;
    int i=0, y=1; 
    
    for(i=0; i<4; i++){
        system("cls");
        affMainTitleIHM(nbAff, nbColor);
        color(JAUNEF, NOIR);
        printf("\t\t\t\t  • Joueur1 veuillez choisir le code couleur •\n\n");
        colorDispoIHM(nbColor);
        color(JAUNEF, NOIR);
        printf("Couleur ");
        printf("%d", y);
        color(nbColor, NOIR);
        printf(": ");
        color(BLANC, NOIR);
        scanf("%d", &couleurs.codeCouleur[i]);
        viderTamponEntree();
        y++;
    }
    return(couleurs);
}
/**
 * Affiche et demande à l'utilisateur le nombre de manches.
 * @param nbAff  <- permet l'affichage du titre.
 * @param nbColor   <- Permet l'affichage de la couleur du cadre.
 * @return <- retourne le nombre de manche pour être vérifié.
 */
int nbManchesIHM(int nbAff, int nbColor){
    int manche = 0;
    
    system("cls");
    affMainTitleIHM(nbAff, nbColor);
    color(JAUNEF, NOIR);
    printf("\t\t\t\t!! Vous avez choisis le Joueur contre Joueur !!\n\n");
    printf("\t\t\t\tCombien de points gagnant ?\n"
           "\t\t\t\t\t• 1\n"
           "\t\t\t\t\t• 3\n"
           "\t\t\t\t\t• 5\n"
           "\t\t\t\tChoix");
    color(nbColor, NOIR);
    printf(" : ");
    color(BLANC, NOIR);
    scanf("%d", &manche);
    viderTamponEntree();
    
    return(manche);
}