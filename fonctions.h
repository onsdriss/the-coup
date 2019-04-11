#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#define TIME_BETWEEN_2_FRAMES 20

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 200
#define PLAYER_SPEED 8
#define JUMPHEIGHT 5
#define GRAVITY 2

#define Collision_droite 20
#define Collision_gauche 30
#define Collision_top 40
#define Collision_bas 50

enum{WALK_RIGHT, WALK_LEFT, IMMOBILE, JUMP};
//Valeurs attribuées aux états/directions

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define RIGHT 1
#define LEFT 2



#define Backg_W 8000
#define Backg_H 600

#define MAXF 3
#define MAXF_ENEMY 6

#define SPEEDJUMP 1


/*_________   structure numero 1  ____________ */



typedef struct Acteurs Acteurs;
struct Acteurs
{
	  SDL_Surface *screen;
    SDL_Event event ;

	//fond
	SDL_Surface *fond ;
	SDL_Rect posFond;

  //fond noir
  SDL_Surface* backg_collision;
  SDL_Surface* backg;
  SDL_Rect camera;

};



/*_________   structure numero 2  ____________ */


/*_________   structure de l hero  ____________ */

typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *sprite;

/* Coordonnées du héros */
int x , y ;
int Ysaut;

/* Variables utiles pour l'animation */
int frame_timer, frame_number;
int etat  , direction ; 

float x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9 , x10 , x11 , x12  ;  //points de verification de collision parfaite 
float y1 , y2 , y3 , y4 , y5 , y6 , y7 , y8 , y9 , y10 , y11 , y12  ;  // points de verification de collision parfaite 



};





/* prototypes */
void initialisation(Acteurs* acteurs);

void initializeHero(Hero* hero) ;

void drawHero(Hero hero , Acteurs *acteurs) ;

void updatePlayer(Hero* hero , Acteurs* acteurs) ;


void animationhero(Hero* hero, Acteurs acteurs);

SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y) ;

void update_points_de_collision(Hero* hero);



int verification_collision_player_map_droite(Acteurs* acteurs , Hero* hero);

int verification_collision_player_map_gauche(Acteurs* acteurs , Hero* hero);

int verification_collision_player_map_top(Acteurs* acteurs , Hero* hero);

int verification_collision_player_map_bas(Acteurs* acteurs , Hero* hero);


#endif /* FONCTIONS_H_ */
