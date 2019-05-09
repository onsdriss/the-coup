#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_image.h>
#include "menu.h"
#include "scrolling.h"


void music()
{
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
	printf("%s",Mix_GetError());
	}
	Mix_Music *music;
	music = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,-1);
}

void intialiser_menu (Perso *start, Perso *settings,Perso *quitter,Perso *jour ,Perso *nuit ,Perso *set,Perso *load_newgame,Perso *sousmenu,Perso *newgame,Perso *loadgame,Perso *clavier,Perso *souris,Perso *manette)
{

  newgame->image=IMG_Load("newgame.png") ;
  newgame->p.x=0;
  newgame->p.y=0 ;

  loadgame->image=IMG_Load("loadgame.png") ;
  loadgame->p.x=0;
  loadgame->p.y=0 ;  

  clavier->image=IMG_Load("clavier.png") ;
  clavier->p.x=0;
  clavier->p.y=0 ;

  souris->image=IMG_Load("souris.png") ;
  souris->p.x=0;
  souris->p.y=0 ;

  manette->image=IMG_Load("manette.png") ;
  manette->p.x=0;
  manette->p.y=0 ;

  sousmenu->image=IMG_Load("select.png") ;
  sousmenu->p.x=0;
  sousmenu->p.y=0 ;

  load_newgame->image=IMG_Load("load_newgame.png") ;
  load_newgame->p.x=0;
  load_newgame->p.y=0 ;

  start->image=IMG_Load("start.png") ;
  start->image2=IMG_Load("start2.png") ;
  start->p.x=390 ;
  start->p.y=-10 ;



  settings->image=IMG_Load("settings.png") ;
  settings->image2=IMG_Load("settings2.png") ;
  settings->p.x=357 ;
  settings->p.y=122 ;

  quitter->image=IMG_Load("exit.png") ;
  quitter->image2=IMG_Load("exit2.png") ;
  quitter->p.x=385 ;
  quitter->p.y=243 ;

  jour->image=IMG_Load("jour.png") ;
  jour->p.x=0;
  jour->p.y=0 ; 

  set->image=IMG_Load("set.png") ;
  set->p.x=00;
  set->p.y=0 ;  

  nuit->image=IMG_Load("nuit.png") ;
  nuit->p.x=0;
  nuit->p.y=0 ;


}
void render_menu (SDL_Surface *screen , Perso start, Perso settings,Perso quitter,Perso jour ,Perso nuit ,Perso set,int curseur,int i) 
{
  if(i==1)
  SDL_BlitSurface(jour.image,NULL,screen,&(jour.p));
  else if (i==2)
  SDL_BlitSurface(set.image,NULL,screen,&(set.p));
  else if (i==3)
  SDL_BlitSurface(nuit.image,NULL,screen,&(nuit.p));
  
  if(curseur==1)
  SDL_BlitSurface(start.image2,NULL,screen,&(start.p));
  else if (curseur==2)
  SDL_BlitSurface(settings.image2,NULL,screen,&(settings.p));
  else if (curseur==3)
  SDL_BlitSurface(quitter.image2,NULL,screen,&(quitter.p));


  SDL_Flip(screen)  ; 

}