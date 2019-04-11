#include <SDL/SDL.h>
#include <stdio.h>

int collision(SDL_Rect* rect1,SDL_Rect* rect2)
{
        if(rect1->y >= rect2->y + rect2->h)
                return 0;
        if(rect1->x >= rect2->x + rect2->w)
                return 0;
        if(rect1->y + rect1->h <= rect2->y)
                return 0;
        if(rect1->x + rect1->w <= rect2->x)
                return 0;
        return 1;
}
int collision_trigo(SDL_Surface *perso, SDL_Surface *enemie, SDL_Rect posp, SDL_Rect pose)
{
    int ra,rb,xb,xa,ya,yb,distance;
    ra=(perso->w)/2;
    xa=(posp.x+(perso->w/2));
    ya=(posp.y+(perso->h/2));
    rb=(enemie->w)/2;
    xb=(pose.x+(enemie->w/2));
    yb=(pose.y+(enemie->h/2));
    distance=((xa-xb)*(xa-xb)+( ya+yb)*( ya+yb));


    if(distance<=(ra+rb)*(ra+rb))
    {
        return 1 ;
    }
    else
    {
        return 0;
    }
}

 
int width = 640;
int height = 480;
 
int main(int argc, char** argv)
{
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface *screen;

        screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
        int running = 1;
        const int FPS = 30;
        Uint32 start;
        int b[4] = {0,0,0,0};
        SDL_Rect rect;
        rect.x = 10;
        rect.y = 10;
        rect.w = 20;
        rect.h = 20;
         SDL_Rect recarr[5];
        recarr[0].x=70;
        recarr[0].y=0;
        recarr[0].h=200;
        recarr[0].w=10;
 
        recarr[1].x=300;
        recarr[1].y=200;
        recarr[1].h=20;
        recarr[1].w=80;
 
        recarr[2].x=200;
        recarr[2].y=100;
        recarr[2].h=100;
        recarr[2].w=10;
 
        recarr[3].x=40;
        recarr[3].y=300;
        recarr[3].h=20;
        recarr[3].w=60;
 
        recarr[4].x=100;
        recarr[4].y=0;
        recarr[4].h=200;
        recarr[4].w=10;


 int i=0;
        Uint32 color2 = SDL_MapRGB(screen->format, 255,255,255);
        Uint32 color = SDL_MapRGB(screen->format, 0,0,0);
        for(i = 0; i < 5; i += 1) {
              SDL_FillRect(screen,&recarr[i],color2);
        }
        while(running) {
                start = SDL_GetTicks();

                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 0;
                                        break;
                                case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym) {
                                                case SDLK_UP:
                                                        b[0] = 1;
                                                        break;
                                                case SDLK_LEFT:
                                                        b[1] = 1;
                                                        break;
                                                case SDLK_DOWN:
                                                        b[2] = 1;
                                                        break;
                                                case SDLK_RIGHT:
                                                        b[3] = 1;
                                                        break;
                                       
                                        }
                                        break;
                                case SDL_KEYUP:
                                        switch(event.key.keysym.sym) {
                                                case SDLK_UP:
                                                        b[0] = 0;
                                                        break;
                                                case SDLK_LEFT:
                                                        b[1] = 0;
                                                        break;
                                                case SDLK_DOWN:
                                                        b[2] = 0;
                                                        break;
                                                case SDLK_RIGHT:
                                                        b[3] = 0;
                                                        break;
                                       
                                        }
                                        break;
                        }
                }
 
                SDL_FillRect(screen, &rect, color);
 
                //logic
                if(b[0]) {
int i=0;
                        rect.y--;
                        for( i = 0; i < 5; i ++)
                                {if(collision(&rect,&recarr[i]))
                                        rect.y++;}
                }
                if(b[1]) {
                        rect.x--;
                        for(i = 0; i < 5; i += 1)
                                {if(collision(&rect,&recarr[i]))
                                        rect.x++;}
                }
                if(b[2]) {
                        rect.y++;
                        for(i = 0; i < 5; i += 1)
                               { if(collision(&rect,&recarr[i]))
                                        rect.y--;}
                }
                if(b[3]) {
                        rect.x++;
                        for(i = 0; i < 5; i += 1)
                                {if(collision(&rect,&recarr[i]))
                                        rect.x--;}
                }
 
 
                //render
                SDL_FillRect(screen, &rect, color2);
                SDL_Flip(screen);
 
                if(1000/FPS > SDL_GetTicks()-start) {
                        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                }
        }
        SDL_Quit();
        return 0;
}
