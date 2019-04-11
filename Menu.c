#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"


int main(int argc, char const *argv[])
{

  Acteurs acteurs;
  Boutons boutons;
  Hero hero ;
  SDL_Rect camera;
    

   //initialisations
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

  
/* appel des fonctions */
#include "fonctions.h"

acteurs.screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "chaima chakroun Mafia", NULL );

    initializeHero(&hero);
    initialisation(&acteurs, &camera);
    /*SDL_BlitSurface(backg, , acteurs.screen, NULL);
    SDL_Flip(acteurs.screen);*/

    drawHero(hero, acteurs, camera);

int carryon = 1;
while(carryon)
{
		SDL_PollEvent(&acteurs.event);
		updatePlayer(&hero , &acteurs, camera) ;
		animation(&hero, acteurs);
		drawHero(hero , acteurs, camera) ;

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






