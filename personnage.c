#include "personnage.h"

void personnage_jeu(SDL_Renderer *ecran, int h, int w, int positionY, SDL_Texture *perso, int numSprite, SDL_Rect *sprite, int affichage_position_x,int hauteur)
{

    SDL_Rect position;
    //SDL_Rect* sprite = sprite_personnage();

    position.x = affichage_position_x * largeur_une_case(w);

    position.y = positionY * hauteur_une_case(h,hauteur);

    position.h = (h / hauteur) * 3;
    position.w = w / LARGEUR_MAP;


    SDL_RenderCopy(ecran, perso, &sprite[numSprite], &position);
}

SDL_Rect *sprite_personnage()
{
    SDL_Rect *sprite;
    sprite = malloc(sizeof(SDL_Rect) * NB_CASE_PERSO);

    int j = 0;
    for (int i = 0; i < NB_CASE_PERSO; i++)
    {
        //hauteur d'une case
        sprite[i].h = (HAUTEUR_SPRITE / NB_CASE_HAUTEUR);

        //largeur d'une case
        sprite[i].w = LARGEUR_SPRITE / NB_CASE_LARGEUR;

        //coordonnees x du sprite a afficher
        sprite[i].x = (i % NB_CASE_LARGEUR) * (sprite[i].w);
        if ((i % NB_CASE_LARGEUR == 0) && (i != 0))
        {

            j++;
        }

        //coordonnee y du sprite a afficher
        sprite[i].y = j * (sprite[i].h);
    }

    return sprite;
}

void deplacement_sur_map(int *debutX, int direction, int *positionX, int *affichage_position_x, int largeur)
{

    if (((direction > 0) && (*positionX < largeur - 1)) || (direction < 0 && *positionX > 0))
    {
        *positionX += direction;
    }
    if (*debutX + (direction) <= largeur - LARGEUR_MAP && *debutX + (direction) >= 0)
    {
        *debutX = *debutX + direction;
    }
    else
    {

        if ((*affichage_position_x < LARGEUR_MAP - 1 && direction > 0) || (direction < 0 && *affichage_position_x > 0))
        {
            *affichage_position_x += direction;
        }
    }
}

//fonction du saut du personnage
void saut(int direction, int vitesse, int *positionY, int hauteur)
{ 

    if ((*positionY + (direction*vitesse) < hauteur - 1) && (*positionY + (direction*vitesse) > 0))//ne sort pas du tableau 
    //for (int i = 0 ; i< vitesse; i++)
    {         
        *positionY -= 1 * vitesse ;  
              

    }
}


void gravite( int direction, int *positionY, int hauteur){//(int* map, int direction, int vitesse, int *positionX, int *positionY
   
       if ((*positionY + (direction) < hauteur - 1) && (*positionY + (direction) > 0)){
           
            *positionY += direction ;//* vitesse ;

       }

    
}


bool collision(char *map, int direction, int positionX, int positionY, int largeur)
{

    //ajouter la colision au niveau de la tete
    bool condition1 = map[(positionX + direction) + positionY * largeur] == '2';       //position de x1 +1 == 2
    bool condition2 = map[(positionX + direction) + (positionY + 1) * largeur] == '2'; // position de x2 +1 ==2
    bool condition3 = map[(positionX + direction) + (positionY + 2) * largeur] == '2'; //position de x3 +1 == 2

    

    //colision avec le sol

   // bool condition4 = map[(positionX) + (positionY +2)*LARGEUR_TABLEAU + direction] == 3 ;  //les pied du perso touche le sol
    return condition1 || condition2 || condition3 ;// || condition4 ;
}

bool collision_pied(char *map, int positionX, int positionY,int largeur){
    //printf("collision_pied personnage \n");

    bool condition_sol = map[((positionX) + (positionY + 3)*largeur)]== '3';
    bool condition_bloc = map[((positionX) + (positionY + 3)*largeur)]== '2' ;
    bool condition_gain = map[((positionX) + (positionY + 3)*largeur)]== '9';
    //printf ("collision pied %d\n", condition_sol || condition_bloc);
        
    return (condition_sol || condition_bloc || condition_gain) ;
}

bool collision_tete(char *map, int positionX, int positionY, int largeur){
    bool collision = false;
    //printf("direction %d\n",direction);
    //if ((positionY + (direction) < HAUTEUR_MAP - 1) && (positionY + (direction) > 0)){
        for (int i= 0 ; i<15 ; i++){
        
            if (!collision){
                collision = map[(positionX) + (positionY - i)*largeur] == '2';
            }
        //printf("%d\n",collision);
        
        }
    //}
    return collision ;
}

// gerer lorsque le personnage atteint un trou
bool trou(char *map, int positionX, int positionY,int largeur)
{
    return map[positionX + (positionY + 3) * largeur] == '1';
}

bool gagner(char *map,int positionX, int positionY, int largeur){
    return map[positionX + (positionY + 3) * largeur] == '9' ;
}


int vie_du_personnage(){
    int vie = 3 ; 
    //sif (trou())
}









