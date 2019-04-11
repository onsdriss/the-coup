#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"



void initialisation(Acteurs* acteurs, SDL_Rect* camera)
{
	acteurs->backg = IMG_Load("stage 1.jpg");
	camera->x = 0;
	camera->y = 0;
	camera->w = SCREEN_WIDTH;
	camera->h = SCREEN_HEIGHT;
}

/*---fonction d initialisation de l hero---*/

void initializeHero(Hero* hero)
{

	hero->sprite = IMG_Load("sprite_hero_right.png");
	SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));


	//Indique l'état et la direction de notre héros
	hero->direction = RIGHT;
	hero->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	hero->frame_timer = TIME_BETWEEN_2_FRAMES;
	hero->frame_number = 0;

	/* Coordonnées de démarrage de notre héros */
	hero->x = 48 ;
	hero->y = 309 ;

}

/*---fontion pour afficher l'hero ---*//////////////////////////

void drawHero(Hero hero , Acteurs acteurs, SDL_Rect camera)
{


/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero.x - camera.x;
dest.y = hero.y ;

SDL_Rect frame;
frame.x = hero.frame_number*PLAYER_WIDTH;
frame.y = 0;
frame.w = PLAYER_WIDTH;
frame.h = PLAYER_HEIGHT;

/* Blitte notre héros sur l'écran aux coordonnées x et y */
SDL_BlitSurface(acteurs.backg, &camera, acteurs.screen, NULL);
SDL_BlitSurface(hero.sprite , &frame , acteurs.screen , &dest) ;
SDL_SetColorKey(hero.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero.sprite->format, 255, 255, 255));
SDL_Flip(acteurs.screen);
}
/*________________________________________________________________________________________*/


//scrolling 

/*________________________________________________________________________________________*/

/*---fonction de deplacement de l hero---*/

void updatePlayer(Hero* hero , Acteurs* acteurs, SDL_Rect camera)
{
	if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT)
		{
			if(hero->etat == IMMOBILE || hero->etat == WALK_LEFT)
			{
				hero->etat = WALK_RIGHT;
			}
			if(hero->direction == LEFT)
				{
					hero->direction = RIGHT ;
				}
			hero->sprite = IMG_Load("sprite_hero_right.png") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x += PLAYER_SPEED ;
			//*frame = AnimationHeroRight(*hero, *acteurs);

			if (hero->x + PLAYER_WIDTH >= Backg_W)
				{
					hero->x = Backg_W - PLAYER_WIDTH ;
				}
		}
		else if(acteurs->event.key.keysym.sym == SDLK_LEFT)
		{
			if(hero->etat == IMMOBILE || hero->etat == WALK_RIGHT)
			{
				hero->etat = WALK_LEFT;
			}
			if(hero->direction == RIGHT)
				{
					hero->direction = LEFT ;
				}
			hero->sprite = IMG_Load("sprite_hero_left.png") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x -= PLAYER_SPEED ;
			//*frame = AnimationHeroLeft(*hero, *acteurs);
            if (hero->x < 0)
				{
					hero->x = 0 ;
				}
		}
	}
	else if(acteurs->event.type == SDL_KEYUP)
	{
		if(hero->etat != IMMOBILE)
		{
			hero->etat = IMMOBILE;
		}
	}
	//centerScrollingOnPlayer(*hero, acteurs, &camera);

}



//fonction pour afficher les ennemi






void animation(Hero* hero, Acteurs acteurs)
{
	if(acteurs.event.type == SDL_KEYDOWN)
	{
		if(acteurs.event.key.keysym.sym == SDLK_LEFT || acteurs.event.key.keysym.sym == SDLK_RIGHT)
		{
			if(hero->frame_timer <= 0)
			{
				hero->frame_number++;
			if(hero->frame_number > MAXF)
				hero->frame_number = 0;
			}
		else
		hero->frame_timer--;
		}
	}
	
	if(acteurs.event.type == SDL_KEYUP)
	{
		if(hero->direction == RIGHT)
		{
			hero->frame_number = 0;
		}
		else if(hero->direction == LEFT)
		{
			hero->frame_number = MAXF;
		}
	}
}
