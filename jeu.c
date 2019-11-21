
#include "fenetreDuJeu.h"
#include "finDeJeu.h"
#include "gestionDesTouches.h"
#include "constante.h"
#include "map.h"
#include "personnage.h"
#include "ennemis.h"
#include "lecture_map.h"

int main(int argc, char *argv[])
{

  int *map = lire_fichier("map.txt");

  SDL_Window *fenetre;  // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre

  bool terminer = false;
  // Créer la fenêtre
  fenetre = fenetreDuJeu();

  //initialisation de l'image du menu
  SDL_Renderer *ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  SDL_Texture *fond = charger_image("raccoon.bmp", ecran); //charger l'image de fond

  SDL_Texture *sol = charger_image("sol.bmp", ecran);
  SDL_Texture *ciel = charger_image("ciel.bmp", ecran);
  SDL_Texture *troux = charger_image("trou.bmp", ecran);
  SDL_Texture *obstacle = charger_image("obstacle.bmp", ecran);
  SDL_Texture* perso = charger_image_transparente("mario.bmp", ecran, 0, 115, 0);

  //SDL_Texture *perso = charger_image_transparente("rocket.bmp", ecran, 0, 137, 84);

  //SDL_Texture *balle1 = charger_image_transparente("balle1.bmp", ecran, 0, 128, 255);
  SDL_Texture *tour4 = charger_image("tour4.bmp", ecran);
  SDL_Texture *tour5 = charger_image("tour5.bmp", ecran);

  SDL_Texture *scientifique = charger_image_transparente("scientifique.bmp", ecran, 255, 0, 0);

  // Boucle principale

  int w = 0;
  int h = 0;
  int debutX = 0; // colonne a partir de laquelle on affiche la map
  int debutY = 0; // ligne a partir de laquelle on affiche la map
  int numSprite = 10;
  int positionX = debutX + 1;
  int positionY = HAUTEUR_TABLEAU - 5; // * hauteur_une_case(h);
  int affichage_position_x = 1;
  SDL_Rect *sprite = sprite_personnage();

  //SDL_Rect image_balle1 = sprite_balle1();

  SDL_Rect *image_scientifique = sprite_stf();

  while (!terminer)
  {

    SDL_GetWindowSize(fenetre, &w, &h);
    SDL_RenderClear(ecran);
    SDL_RenderCopy(ecran, fond, NULL, NULL); // affiche le fond

    carteDuJeu(ecran, sol, ciel, troux, obstacle, tour4, tour5, w, h, debutX, debutY, map); // affiche la map
    personnage_jeu(ecran, h, w, positionY, perso, numSprite, sprite, affichage_position_x);
    //emplacement_balle1(ecran, balle1, image_balle1, map);
    stf(ecran, scientifique, image_scientifique, NB_SPRITE_STF);

    SDL_RenderPresent(ecran);
    if (SDL_PollEvent(&evenements))
    {
      gestionTouche(evenements, ecran, &terminer, &debutX, &debutY, &numSprite, &positionX, &positionY, &affichage_position_x, map, h);
    }
    //
  }
  // Quitter SDL
  free(sprite);
  SDL_DestroyTexture(fond);
  SDL_DestroyTexture(ciel);
  SDL_DestroyTexture(sol);
  SDL_DestroyTexture(troux);
  SDL_DestroyTexture(obstacle);
  SDL_DestroyTexture(perso);
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
  return 0;
}