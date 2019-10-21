#include "gestionDesTouches.h"
#include "constante.h"

void gestionTouche(SDL_Event evenements, SDL_Renderer * ecran, bool* terminer,int *debut, int *numSprite){
    
        switch(evenements.type)
        {
            case SDL_QUIT:
                *terminer = true; 
            break;
        case SDL_KEYDOWN:
        switch(evenements.key.keysym.sym)
        {
            case SDLK_ESCAPE: //touche echappe
            case SDLK_q:
                *terminer = true; 
                break;
            //test de l'affichage du game over avec la touche entrer
            case SDLK_RETURN  : //touche entrer
                gameOver("gameOver.bmp", ecran);
                *terminer = true ;
                break;
            //test affichage du winner avec la touche espace
            case SDLK_SPACE : //touche barre d'espace
                win("winner.bmp", ecran);
                *terminer = true ;
               break ;
            case SDLK_RIGHT :
            if(*debut<LARGEUR_TABLEAU - LARGEUR_MAP){
                    *debut += 1;
                    printf("%d\n",*numSprite);
                    if ((*numSprite < 11)&&(*numSprite > 7)) {
                        printf("coucou\n");
                        *numSprite += 1 ;
                    } 
                    else {
                        *numSprite = 8 ;
                    }
                }
                break;
            case SDLK_LEFT :
            if(*debut > 0){
                *debut -= 1;
            }
        }

        }

    
    
}