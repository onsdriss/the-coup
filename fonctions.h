#ifndef FONCTIONS_H_
#define FONCTIONS_H_

/*/////// 9dom hedom
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SHEET_WIDTH 2400 
#define SHEET_HEIGHT 600
#define FPS 60
#define speed 2
#define SHEET_WIDTH_HERO 300
#define SHEET_HEIGHT_HERO 400
*//////////


#define TIME_BETWEEN_2_FRAMES 18

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PLAYER_WIDTH 72
#define PLAYER_HEIGHT 400
#define PLAYER_SPEED 5


enum{WALK_RIGHT, WALK_LEFT, IMMOBILE, JUMP};
//Valeurs attribuées aux états/directions


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define RIGHT 1
#define LEFT 2

/*#define ENEMY_Height 80
#define ENEMY_Width 80*/

#define Backg_W 8000
#define Backg_H 600

#define MAXF 3


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
  SDL_Surface* backg;
};


/*_________   structure numero 2  ____________ */

typedef struct Boutons Boutons ;
struct Boutons 
{
	  SDL_Surface *b1 ;
    SDL_Surface *b2 ;
    SDL_Surface *b3 ;
    SDL_Surface *b4 ;
    SDL_Surface *b5 ;

    SDL_Rect posB1;
    SDL_Rect posB2;
    SDL_Rect posB3;
    SDL_Rect posB4;
    SDL_Rect posB5;
};

/*_________   structure de l hero  ____________ */

typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *sprite;

/* Coordonnées du héros */
int x , y ;

/* Variables utiles pour l'animation */
int frame_timer, frame_number;
int etat  , direction ; 

};

/* prototypes */
void initialisation(Acteurs* acteurs, SDL_Rect* camera);

void initializeHero(Hero* hero) ;

void drawHero(Hero hero , Acteurs acteurs, SDL_Rect camera) ;

void updatePlayer(Hero* hero , Acteurs* acteurs, SDL_Rect camera) ;

void centerScrollingOnPlayer(Hero hero, Acteurs* acteurs, SDL_Rect* camera);

//SDL_Rect AnimationHero(Hero hero);

void animation(Hero* hero, Acteurs acteurs);

//SDL_Rect AnimationHeroRight(Hero hero, Acteurs acteurs);

//SDL_Rect AnimationHeroLeft(Hero hero, Acteurs acteurs);
#endif /* FONCTIONS_H_ */
