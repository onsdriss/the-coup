#include "objet.h"
 
 
int main(int argc, char ** argv)
{
  SDL_Init(SDL_INIT_VIDEO);
 
screen=SDL_SetVideoMode(640,640,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_FillRect(screen, NULL, SDL_MapRGBA(screen->format, 0,0,0,0));

if(screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}

 
    coin=IMG_Load("coin.png");
   
     

   if (coin==NULL)
    
   {printf("erreur. %s \n",SDL_GetError() );
    }
    
    positioncoin.x = 540 ;
    positioncoin.y = 10 ;
    
        SDL_BlitSurface(coin, NULL, screen, &positioncoin);
        SDL_Flip(screen);   SDL_Delay(9000);

        SDL_FreeSurface(screen);
        SDL_FreeSurface(coin);
SDL_Quit();

        return 0;
             
}

