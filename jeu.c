
#include "fenetreDuJeu.h"
#include "finDeJeu.h"
#include "gestionDesTouches.h"
#include "constante.h"
#include "map.h"




int main(int argc, char *argv[])
{
  

  SDL_Window* fenetre; // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre

  bool terminer = false;
  // Créer la fenêtre
  fenetre = fenetreDuJeu();
  
    //initialisation de l'image de fond
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* fond = charger_image("raccoon.bmp", ecran ); //charger l'image de fond
  
  SDL_Texture* sol = charger_image ("sol.bmp", ecran);
  SDL_Texture* ciel = charger_image ("ciel.bmp", ecran);
  SDL_Texture* trou = charger_image ("trou.bmp", ecran);
  SDL_Texture* obstacle = charger_image ("obstacle.bmp", ecran);
  
  // Boucle principale


  while(!terminer)
  {
    SDL_RenderClear(ecran);
    SDL_RenderCopy(ecran, fond, NULL, NULL); // affiche le fond
    carteDuJeu (ecran, sol, ciel, trou, obstacle) ;
    SDL_RenderPresent(ecran); 
    if (SDL_PollEvent(&evenements)){ 
      gestionTouche(evenements, ecran ,&terminer);
    }
}
// Quitter SDL
SDL_DestroyWindow(fenetre);
SDL_Quit();
return 0;
}