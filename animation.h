#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
typedef struct 
{

int X;
int Y;

}Coordinate;

typedef struct 
{
  int x ;
  int y ;
  float rayon ;

}Circle;

typedef struct 
{
  int vx ;
  Circle c ;
  float vy ;
  int jump ;
  int stop ;
  SDL_Surface *image ;
  SDL_Rect p ;

}Caractere ;
typedef struct 
{
  int vx ;
  float vy ;
  int jump ;
  int stop ;
  SDL_Surface *image ;
  SDL_Surface *image2 ;
  SDL_Rect p ;
  Circle c ;
  SDL_Rect clip [5] ;
  
}Perso;

void music() ;
void intialiser_menu (Perso *start, Perso *settings,Perso *quitter,Perso *jour ,Perso *nuit ,Perso *set,Perso *load_newgame,Perso *sousmenu,Perso *newgame,Perso *loadgame,Perso *clavier,Perso *souris,Perso *manette) ;
void render_menu (SDL_Surface *screen , Perso start, Perso settings,Perso quitter,Perso jour ,Perso nuit ,Perso set,int curseur,int i)  ;
void setrects(SDL_Rect* clip) ; 
int collisionBB(SDL_Rect rect_perso,SDL_Rect rects ,Caractere enemy_D []  ) ;
void update (SDL_Surface *screen ,SDL_Surface *Background,Perso sprite, Caractere  enemy_D [],Caractere  enemy_G [],int r_enemy,int l_enemy,int frame,float frame_enemy ,SDL_Rect positionFond,int l_pers ,int r_pers,Caractere box,SDL_Surface *texte,SDL_Surface *gestion_score,SDL_Rect position,SDL_Rect position2,Caractere life [],int nb_life,Caractere box2,SDL_Surface *mask,int first, Caractere  enemy_2D [],Caractere  enemy_2G [],Caractere chair,Caractere minimap,Caractere curseur_map)  ;
void update_fonts(int *tempsActuel,int *tempsPrecedent,int *compteurr,int *seconde,char temps [],char score [],int *score_finale,SDL_Surface **texte,SDL_Surface **gestion_score,TTF_Font *police,SDL_Color couleurBlanche,int *minute ) ;
void move_ennemi(Caractere  enemy_D [],int *r_enemy,int *l_enemy,float *frame) ;
void setup (Perso *sprite,Caractere enemy_G [],Caractere  enemy_D [],Caractere *box,Caractere life [],Caractere *box2,Caractere *mouse,Caractere *keyboard,Caractere *controller,Caractere *quitter,Caractere enemy_2G [],Caractere  enemy_2D [],Caractere *chair,Caractere *minimap,int level,Caractere *curseur_map,Caractere *win,Perso *sprite2) ;
void calculer_centre_rayon (Perso *perso,Caractere *box) ;
float calculer_distance (Perso perso,Caractere box)  ;
int verif_collision (Perso perso,Caractere box,float D1 ) ;
int animate(SDL_Surface *screen , SDL_Surface *sprit ,SDL_Surface *sprite2,SDL_Surface *sprite3,  SDL_Surface *Background , SDL_Rect positionFond , int *running,SDL_Surface *mask,int save,int level) ;
int animate2(SDL_Surface *screen , SDL_Surface *sprit ,SDL_Surface *sprite2,SDL_Surface *sprite3,  SDL_Surface *Background , SDL_Rect positionFond , int *running,SDL_Surface *mask,int save,int level) ;
int animate3(SDL_Surface *screen , SDL_Surface *sprit ,SDL_Surface *sprite2,SDL_Surface *sprite3,  SDL_Surface *Background , SDL_Rect positionFond , int *running,SDL_Surface *mask,int save,int level) ;
void init_enigme(Perso * e) ;
void generate_afficher (SDL_Surface * screen  , char image [],Perso *e,int *alea) ;
int solution_e (char image []) ;
int resolution (int * running,int *run ) ;
void afficher_resultat (SDL_Surface * screen,int s,int r,Perso *en) ;
int Collision_Parfaite(SDL_Surface *Background,Coordinate C) ;
Uint32 getpixel(SDL_Surface *surface,Coordinate C) ;