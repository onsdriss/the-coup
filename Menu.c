#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"


int main(int argc, char const *argv[])
{

  Acteurs acteurs;
  Hero hero ;
  
    

   //initialisations
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

  
/* appel des fonctions */

acteurs.screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "THE MYSTERIOUS ISLAND", NULL );

    initializeHero(&hero);
    initialisation(&acteurs);
    update_points_de_collision(&hero);


    drawHero(hero, &acteurs);
    



int carryon = 1;
while(carryon)
{		

		SDL_PollEvent(&acteurs.event);
		updatePlayer(&hero , &acteurs) ;
		animationhero(&hero, acteurs);
	
		drawHero(hero , &acteurs) ;
	
		SDL_Flip(acteurs.screen);






	switch(acteurs.event.type)
	{
		case SDL_QUIT:
             carryon = 0;
    	case SDL_KEYDOWN:
			if(acteurs.event.key.keysym.sym == SDLK_ESCAPE)
				{
					carryon= 0;
				}
			break;

	}


}

    //LIB
	SDL_Quit();
	return 0 ;

}






