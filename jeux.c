#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "jeux.h"

void initialiser_score(sco *s,sec se)
{
TTF_Init();
s->font=TTF_OpenFont("BebasNeue-Book.ttf", 50);
SDL_Color color={255,0,0};
char ch[10];
s->sscore;
sprintf(ch,"%d XP",s->sscore);
s->score=TTF_RenderText_Solid(s->font,ch,color);
SDL_BlitSurface(s->score,NULL,se.screen,&s->position_score);
SDL_Flip(se.screen);
TTF_Quit();
}

int vie(int state , int v)
{
    if (state==1)
          {
         if(v<3)
                v++;
          }
      else
          if(state==-1)
              v--;
                 else
                    return v;
 return v;
}

void DepAlea(SDL_Rect *positionsp,int intermin , int intermax)
{
    int x;
    x=(rand()%20)+100;
    switch(x)
       {
       case 1:
        if(positionsp->x<intermax)
            positionsp->x++;
        break;
       case 2:
        if(positionsp->x>intermin)
            positionsp->x--;
        break;
       }
}

void init_obj(sec se,objet *ob)
{
    ob->objet=IMG_Load("objet.png");       
    SDL_BlitSurface(ob->objet, NULL, se.screen,&ob->position_objet);    
}

void time(obj *o,sec se)
{
TTF_Init();
char ch[50];
o->fonte=TTF_OpenFont("BebasNeue-Book.ttf", 70);
SDL_Color color={255,0,0};
o->suiv = SDL_GetTicks();
if (o->suiv - o->prec>=1000)
{
o->tmp ++;
if (o->tmp<10)
{
sprintf(ch,"00:0%d",o->tmp);
}
else if (o->tmp==10)
{
sprintf(ch,"00:%d",o->tmp);
}
o->prec=o->suiv;
}
o->temp=TTF_RenderText_Solid(o->fonte,ch,color);
SDL_BlitSurface(o->temp,NULL,se.screen,&o->postime);
if (o->tmp==10)
{ 
o->tmp = 0 ;
o->Num_try-- ;
TTF_Quit();
}
}
