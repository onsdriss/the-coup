#ifndef JEUX
#define JEUX
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
SDL_Surface *screen;
SDL_Surface *image;
SDL_Rect positionecran,positionecran1;
}sec;

typedef struct 
{
TTF_Font *font;
SDL_Surface *score;
SDL_Rect position_score;
int sscore;
}sco;

typedef struct
{
    TTF_Font *fonte;
    SDL_Surface * temp;
    SDL_Rect postime;
    int Num_try, suiv,prec,tmp;
}obj;

typedef struct
{
    SDL_Surface *objet;
    SDL_Rect position_objet;
}objet;
void initialiser_score(sco *s,sec se);
int vie(int state , int v);
void DepAlea(SDL_Rect *positionsp,int intermin , int intermax);
void times(obj *o,sec se);
void init_obj(sec se,objet *ob);
#endif
