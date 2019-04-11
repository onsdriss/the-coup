#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"



/*________________________________________________________________________________________*/



void initialisation(Acteurs* acteurs)
{
	acteurs->backg_collision = SDL_LoadBMP("stage1_collision.bmp");
	acteurs->backg = SDL_LoadBMP("stage1.bmp");
	acteurs->camera.x = 0;
	acteurs->camera.y = 0;
	acteurs->camera.w = SCREEN_WIDTH;
	acteurs->camera.h = SCREEN_HEIGHT;
}



/*________________________________________________________________________________________*/



/*---fonction d initialisation de l hero---*/

void initializeHero(Hero* hero)
{

	hero->sprite = SDL_LoadBMP("sprite_hero_right.bmp");
	SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));


	//Indique l'état et la direction de notre héros
	hero->direction = RIGHT;
	hero->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	hero->frame_timer = TIME_BETWEEN_2_FRAMES;
	hero->frame_number = 0;

	/* Coordonnées de démarrage de notre héros */
	hero->x = 48 ;
	hero->y = 50 ;

	hero->Ysaut = 0;

}



/*________________________________________________________________________________________*/



/*---fontion pour afficher l'hero ---*//////////////////////////

void drawHero(Hero hero , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero.x - acteurs->camera.x;
dest.y = hero.y ;

SDL_Rect frame;
frame.x = hero.frame_number*PLAYER_WIDTH;
frame.y = 0;
frame.w = PLAYER_WIDTH;
frame.h = PLAYER_HEIGHT;

/* Blitte notre héros sur l'écran aux coordonnées x et y */
SDL_BlitSurface(acteurs->backg_collision, &acteurs->camera, acteurs->screen, NULL);
SDL_BlitSurface(acteurs->backg, &acteurs->camera, acteurs->screen, NULL);
SDL_BlitSurface(hero.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(hero.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero.sprite->format, 255, 255, 255));
SDL_Flip(acteurs->screen);
}


/*________________________________________________________________________________________*/



/*---fonction de deplacement de l hero---*/

void updatePlayer(Hero* hero , Acteurs* acteurs)
{	
	int resultat_de_collision ;


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
			hero->sprite = SDL_LoadBMP("sprite_hero_right.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x += PLAYER_SPEED ;
			update_points_de_collision(hero) ;

			resultat_de_collision=verification_collision_player_map( acteurs , hero) ;

			if(acteurs->event.key.keysym.sym == SDLK_RIGHT && resultat_de_collision==1)
			{

			hero->x -= PLAYER_SPEED ;

			update_points_de_collision(hero) ;

			}

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
			hero->sprite = SDL_LoadBMP("sprite_hero_left.bmp") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x -= PLAYER_SPEED ;

			update_points_de_collision(hero) ;

			resultat_de_collision=verification_collision_player_map( acteurs , hero) ;

			if(acteurs->event.key.keysym.sym == SDLK_LEFT && resultat_de_collision==1)
			{

			hero->x += PLAYER_SPEED ;
			update_points_de_collision(hero) ;

			}


            if (hero->x < 0)
				{
					hero->x = 0 ;
				}
		}
	}     
	else if(acteurs->event.key.keysym.sym == SDLK_SPACE)
	{
		hero->Ysaut -= SPEEDJUMP;
		hero->x += SPEEDJUMP;
	}  
	else if(acteurs->event.type == SDL_KEYUP)
	{
		if(hero->etat != IMMOBILE)
		{
			hero->etat = IMMOBILE;
		}
	}

	resultat_de_collision = verification_collision_player_map(acteurs , hero);
	update_points_de_collision(hero);
	//printf("Collision = %s\n", (resultat_de_collision == 1) ? "Detecté" : "Pas de collision");
	if(hero->Ysaut <= JUMPHEIGHT && resultat_de_collision == 0)
	{
		hero->Ysaut += GRAVITY;
	}
	
	if(resultat_de_collision == 1 && acteurs->event.key.keysym.sym != SDLK_SPACE)
	{
		hero->Ysaut = 0;
	}
	hero->y += hero->Ysaut;
	
}



/*________________________________________________________________________________________*/


//fonction pour annimer l'hero

void animationhero(Hero* hero, Acteurs acteurs)
{
	if(acteurs.event.type == SDL_KEYDOWN)
	{
		if(acteurs.event.key.keysym.sym == SDLK_LEFT || acteurs.event.key.keysym.sym == SDLK_RIGHT)
		{
			if(hero->frame_timer <= 0)
			{
				hero->frame_number++;
				SDL_Delay(15);
			if(hero->frame_number > MAXF-1)
				hero->frame_number = 0;
			}
		else
		hero->frame_timer--;
		SDL_Delay(15);

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
			hero->frame_number = MAXF-1;
		}
	}
}



/*________________________________________________________________________________________*/




/*---fonction pour faire le scrolling---*/

void centerScrollingOnPlayer(Hero hero, Acteurs* acteurs)
{
	if(acteurs->event.type == SDL_KEYDOWN)
	{
		if(acteurs->event.key.keysym.sym == SDLK_RIGHT)
	{
		if((hero.x + PLAYER_WIDTH/2) > SCREEN_WIDTH/2)
			{
				acteurs->camera.x += PLAYER_SPEED;
			}
		if(acteurs->camera.x > Backg_W - SCREEN_WIDTH)
			{
				acteurs->camera.x = Backg_W - SCREEN_WIDTH;
			}
	}
	else if(acteurs->event.key.keysym.sym == SDLK_LEFT)
	{
		
				acteurs->camera.x -= PLAYER_SPEED;
		if((hero.x + PLAYER_WIDTH/2) > (Backg_W - SCREEN_WIDTH/2))
		{
			acteurs->camera.x = Backg_W - SCREEN_WIDTH;
		}
			
		if(acteurs->camera.x < 0)
			{
				acteurs->camera.x = 0;
			}
	}
	}
}



/*________________________________________________________________________________________*/


SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y) 
{

SDL_Color color ;
Uint32 col=0;
char* pPosition = (char*) pSurface->pixels ;
pPosition += (pSurface->pitch * y);
pPosition += (pSurface->format->BytesPerPixel * x);

memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );


return (color) ;

}

/*________________________________________________________________________________________*/


//pour mettre a jour les points de collision ! on 12 points de collision !!!


void update_points_de_collision(Hero* hero)
{				

//points a droite de l'hero 

hero->x1=hero->x + PLAYER_WIDTH ;
hero->y1=hero->y ;												

hero->x2=  hero->x + PLAYER_WIDTH;
hero->y2= hero->y + 100  ;


hero->x3=hero->x + PLAYER_WIDTH ;
hero->y3= hero->y + PLAYER_HEIGHT  ;


hero->x4=hero->x + PLAYER_WIDTH ;
hero->y4= hero->y + 50  ;


hero->x5=hero->x + PLAYER_WIDTH ;
hero->y5= hero->y + 150  ;

//points a gauche de l'hero 

hero->x6=  hero->x ;
hero->y6=  hero->y ;

hero->x7=  hero->x ;
hero->y7=  hero->y + 100 ;

hero->x8= hero->x  ;
hero->y8=  hero->y + PLAYER_HEIGHT ;

hero->x9=  hero->x ;
hero->y9=  hero->y + 50 ;

hero->x10=  hero->x ;
hero->y10=  hero->y + 150 ;

//points au milieu de l'hero 

hero->x11=  hero->x + 50 ;
hero->y11=  hero->y ;

hero->x12=  hero->x + 50 ;
hero->y12=  hero->y + PLAYER_HEIGHT ;


}


/*________________________________________________________________________________________*/

//fonction de verification de collision entre le bachground du premier stage et l'hero ! cette fonction retourne 1 en cas de collision sinon 0


int verification_collision_player_map(Acteurs* acteurs , Hero* hero)
{

SDL_Color color1 , color2 , color3 , color4 , color5 , color6 , color7 , color8 , color9 , color10 , color11 , color12 ;


color1=GetPixel (acteurs->backg_collision , hero->x1 , hero->y1) ; 
color2=GetPixel (acteurs->backg_collision , hero->x2 , hero->y2) ; 
color3=GetPixel (acteurs->backg_collision , hero->x3 , hero->y3) ;
color4=GetPixel (acteurs->backg_collision , hero->x4 , hero->y4) ;     
color5=GetPixel (acteurs->backg_collision , hero->x5 , hero->y5) ;

color6=GetPixel (acteurs->backg_collision , hero->x6 , hero->y6) ;
color7=GetPixel (acteurs->backg_collision , hero->x7 , hero->y7) ;
color8=GetPixel (acteurs->backg_collision , hero->x8 , hero->y8) ;
color9=GetPixel (acteurs->backg_collision , hero->x9 , hero->y9) ;
color10=GetPixel (acteurs->backg_collision , hero->x10 , hero->y10) ;

color11=GetPixel (acteurs->backg_collision , hero->x11 , hero->y11) ;
color12=GetPixel (acteurs->backg_collision , hero->x12 , hero->y12) ;

  
if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255)) 
	|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255) ) || ((color4.r==255)  &&  (color4.g==255)  &&  (color4.b==255) ) 
	|| ((color5.r==255)  &&  (color5.g==255)  &&  (color5.b==255) ) || ((color6.r==255)  &&  (color6.g==255)  &&  (color6.b==255) ) 
	|| ((color7.r==255)  &&  (color7.g==255)  &&  (color7.b==255) ) || ((color8.r==255)  &&  (color8.g==255)  &&  (color8.b==255) )
	 || ((color9.r==255)  &&  (color9.g==255)  &&  (color9.b==255) ) || ((color10.r==255)  &&  (color10.g==255)  &&  (color10.b==255)) 
	 | ((color11.r==255)  &&  (color11.g==255)  &&  (color11.b==255) ) || ((color12.r==255)  &&  (color12.g==255)  &&  (color12.b==255)))
{
return 1 ;
}

else 
{
return 0 ;	
}


}


/*________________________________________________________________________________________*/


/*---fonction d initialisation de l enemy---*/

void initializeEnemy(Enemy* enemy)
{

	enemy->sprite = SDL_LoadBMP("sprite_enemy_right.bmp");
	SDL_SetColorKey(enemy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite->format, 255, 255, 255));


	//Indique l'état et la direction de notre enemy
	enemy->direction = RIGHT;
	enemy->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	enemy->frame_timer = TIME_BETWEEN_2_FRAMES;
	enemy->frame_number = 0;

	/* Coordonnées de démarrage de notre enemies */
	enemy->x = 900 ;
	enemy->y = 300 ;

}


/*________________________________________________________________________________________*/



/*---fontion pour afficher l'enemy ---*//////////////////////////

void drawEnemy(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x - acteurs->camera.x;
dest.y = enemy.y ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite->format, 255, 255, 255));
SDL_Flip(acteurs->screen);
SDL_Delay(15);
	
}


/*________________________________________________________________________________________*/


void animationEnemy(Enemy* enemy, Acteurs acteurs)
{		
			if(enemy->frame_timer <= 0)
			{
				enemy->frame_number++;
				SDL_Delay(15);
			if(enemy->frame_number > MAXF_ENEMY-1)
				enemy->frame_number = 0;
			}
		else
		enemy->frame_timer--;
		SDL_Delay(15);	
	
}

/*________________________________________________________________________________________*/
