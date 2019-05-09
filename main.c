#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL_mixer.h"
#include "animation.h"
#include "scrolling.h"




int main ()
{

SDL_Surface *screen=NULL,*level1=NULL ;
Perso sprite,start,settings,quitter,jour,set,nuit,newgame,sousmenu,loadgame,clavier,load_newgame,souris,manette,enemy_D[20],box,box2,win ;
int run= 1 ,i=2,curseur=1,actuel,prec,starting=0 ,running2=1,save=2,settingss=0,j=0,k=0,souris1=0,manette1=0,clavier1=0,level=1,nb_life,score_finale,seconde,minute,run2=1 ;
SDL_Event event ;
SDL_Rect posfond,positionFond ;
Mix_Chunk *effect ;
  win.image=IMG_Load("chaima.png") ;
  win.p.x=0;
  win.p.y=0 ;
SDL_Init(SDL_INIT_EVERYTHING) ;

SDL_EnableKeyRepeat(100,100) ;
intialiser_menu (&start,&settings,&quitter,&jour ,&nuit ,&set,&load_newgame,&sousmenu,&newgame,&loadgame,&clavier,&souris,&manette) ;
music() ;
effect= Mix_LoadWAV("futuresoundfx-13.wav");

Mix_Volume(1,50); 
screen=SDL_SetVideoMode(1280,720,32,SDL_DOUBLEBUF |SDL_HWSURFACE) ;
render_menu (screen,start,settings,quitter,jour,nuit ,set,curseur,i)  ;
while (run)
{

                    SDL_WaitEvent(&event) ;
                      switch(event.type)
               {
                 case SDL_QUIT:
                 run = 0 ;
                 break;
                 case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                 case SDLK_UP :
                 Mix_PlayChannel(1,effect,0);
                   curseur--  ;
                   if(curseur<1)
                   curseur=3 ;
                 render_menu (screen,start,settings,quitter,jour,nuit ,set,curseur,i)  ;
                 break ;
                 case SDLK_DOWN :
                 Mix_PlayChannel(1,effect,0);

                   curseur++ ;
                   if(curseur>3)
                   curseur=1 ;
                 render_menu (screen,start,settings,quitter,jour,nuit ,set,curseur,i)  ;
                  break ;
                 case SDLK_RETURN :
                   if(curseur==1)
                    starting=1 ;
                  else if(curseur==3) 
                    run=0 ;
                  else if(curseur==2) 
                    settingss=1 ;
                  break ;
                }
                case SDL_MOUSEMOTION  :

                 if(event.motion.x>858 && event.motion.y>267 && event.motion.x<858+351 && event.motion.y<267+117 )
                 {
                   if(curseur!=1)
                   {
                    curseur=1 ;
                    Mix_PlayChannel(1,effect,0);
                    render_menu (screen,start,settings,quitter,jour,nuit ,set,curseur,i)  ;
                   }
                 }
                    
                         
                
                 else if(event.motion.x>860 && event.motion.y>421 && event.motion.x<858+351 && event.motion.y<421+117 )
                 {
                   if(curseur!=2)
                   {
                    curseur=2 ;
                    Mix_PlayChannel(1,effect,0);
                    render_menu (screen,start,settings,quitter,jour,nuit ,set,curseur,i)  ;
                   }
                    
                 } 
                 else if(event.motion.x>860 && event.motion.y>560 && event.motion.x<858+351 && event.motion.y<560+117 )
                 {
                   if(curseur!=3)
                   {
                    curseur=3 ;
                    Mix_PlayChannel(1,effect,0);
                    render_menu (screen,start,settings,quitter,jour,nuit ,set,curseur,i)  ;
                   }
                 }
                break ; 
                case SDL_MOUSEBUTTONDOWN :
                 if(event.button.button == SDL_BUTTON_LEFT)
                 {
                    if(curseur==1)
                    starting=1 ;
                  else if(curseur==3) 
                    run=0 ;
                  else if(curseur==2) 
                    settingss=1 ;                  
                 }
                break ;
                
                break  ;
               }

                     actuel = SDL_GetTicks();
                      if (actuel - prec > 3000)
                         { 
                           i++ ;
                           if(i>3)                          
                            i=1 ;

                           prec = actuel;
                         }
                     if(starting)
                     {
                       	   SDL_BlitSurface(newgame.image,NULL,screen,&(newgame.p)) ;
							             SDL_Flip (screen) ;
                       running2=1 ;
                       while (running2)
						             	{

                           SDL_WaitEvent(&event) ;
            
                       switch(event.type)
                        {
													case SDL_QUIT:
                           running2=0 ;
                           save=2 ;
													break ;
													case SDL_KEYDOWN :
                           switch (event.key.keysym.sym)
													 {
                           case SDLK_ESCAPE :
                            running2=0 ;
                            save=2 ;
                           break ;  
													 case SDLK_RIGHT:
                              Mix_PlayChannel(1,effect,0);

													 save=0 ;  
                           j=0 ;
													 break;
													 
													 case SDLK_LEFT :
                           Mix_PlayChannel(1,effect,0);
													 save= 1 ;
                           j=1 ;
													 break;
													 case SDLK_RETURN :
                            if(save==1 || save==0)
														running2=0 ;
													 break ;
													 }
													break ;
												}
                        if(running2!=0)
                        {
                          if(j==1)
                         SDL_BlitSurface(loadgame.image,NULL,screen,&(loadgame.p));
                         else if (j==0)
                          SDL_BlitSurface(newgame.image,NULL,screen,&(newgame.p));  

                          SDL_Flip(screen) ;
                        }
                        if(running2==0 &&(save==1 ||save==0))
                        {
                          running2=1 ;
                          if(save)
                          {
                            FILE *f=fopen("save_file","r") ; 
                             fscanf(f,"%hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %d %d %d %d %d",&(positionFond.x),&(positionFond.y),&(sprite.p.x),&(sprite.p.y),&(enemy_D[0].p.x),&(enemy_D[0].p.y),&(box.p.x),&(box.p.y),&(box2.p.x),&(box2.p.y),&(nb_life),&(score_finale),&seconde,&minute,&level) ;
                             fclose(f) ; 
                             if(level==1)
                               level=scroll1(screen,level1 ,&running2,posfond,save,level) ;                                                      
                             if(level==2)
								               {
								                 running2=1 ;
                                 level=scroll2(screen,level1 ,&running2,posfond,save,level) ;
								                  level=3 ;
							                	}                                                                
                            if(level==3)
								               {
									              running2=1 ;
                                level=scroll3(screen,level1 ,&running2,posfond,save,level) ;
                             if(save==1) 
                             {  
                      while (run2 )
  {
    SDL_BlitSurface(win.image,NULL,screen,&(win.p)) ;
    SDL_Flip(screen) ;
    SDL_WaitEvent(&event) ;
                               switch(event.type)
                                 {
                                   
                                   case SDL_QUIT :
                                      run2=0 ;
                                   break ;
                                   case SDL_KEYDOWN:

                                    switch(event.key.keysym.sym)


                                       {
                                           case SDLK_ESCAPE :
                                           run2=0 ;
                                           break ;
                                       }
                                      
                                      
                                      break ;
                                 }
    }
                             }
								               }
                          }
                          else
                          {
                           level=scroll1(screen,level1 ,&running2,posfond,save,level) ;                                                      
                             if(level==2)
								               {
								                 running2=1 ;
                                 level=scroll2(screen,level1 ,&running2,posfond,save,level) ;
								                  level=3 ;
							                	}                                                                
                            if(level==3)
								               {
									              running2=1 ;
                                level=scroll3(screen,level1 ,&running2,posfond,save,level) ;
                                if( save==1)
                                {
                     while (run2 )
  {
    SDL_BlitSurface(win.image,NULL,screen,&(win.p)) ;
    SDL_Flip(screen) ;
    SDL_WaitEvent(&event) ;
                               switch(event.type)
                                 {
                                   
                                   case SDL_QUIT :
                                      run2=0 ;
                                   break ;
                                   case SDL_KEYDOWN:

                                    switch(event.key.keysym.sym)


                                       {
                                           case SDLK_ESCAPE :
                                           run2=0 ;
                                           break ;
                                       }
                                      
                                      
                                      break ;
                                 }
    }
                                }                                
								               }                            
                          }
                          

                        }
 
						 	          }
                         render_menu (screen,start,settings,quitter,jour,nuit ,set,curseur,i)  ;
                         starting=0 ;
                     }  
                     if(settingss)
                     {
						               SDL_BlitSurface(sousmenu.image,NULL,screen,&(sousmenu.p)) ;
							             SDL_Flip (screen) ;                       
                        running2=1 ;
                        while (running2)
						             	{

                           SDL_WaitEvent(&event) ;
            
                        switch(event.type)
                        {
													case SDL_QUIT:
                           running2=0 ;
													break ;
													case SDL_KEYDOWN :
                           switch (event.key.keysym.sym)
													 {
                           case SDLK_ESCAPE :
                            running2=0 ;
                           break ;  
													 case SDLK_RIGHT:
                           Mix_PlayChannel(1,effect,0);

													  k++ ;
                            if(k>3)
                            k=1 ;
													 break;
													 case SDLK_LEFT :
                            Mix_PlayChannel(1,effect,0);

													  k-- ;
                            if(k<1)
                            k=3 ;													 
													 break;
													 case SDLK_RETURN :
                            
														running2=0 ;
													 break ;
													 }
													break ;
												}
                       if(k==1)
                         {
			                     SDL_BlitSurface(souris.image,NULL,screen,&(souris.p)) ;
                         } 
                       if(k==2)
                         {
						               SDL_BlitSurface(clavier.image,NULL,screen,&(clavier.p)) ;        
                         }
                       if(k==3)
                         {
						              SDL_BlitSurface(manette.image,NULL,screen,&(manette.p)) ;                      
                         }     
                          SDL_Flip(screen) ;                            
						             }
                           if(k==1)
                         {
                          souris1=1 ;
                          clavier1=0 ;
                          manette1=0 ;
                         }
                          if(k==2)
                         {
                          souris1=0 ;
                          clavier1=1 ;
                          manette1=0 ;
                         }
                          if(k==3)
                         {
                          souris1=0 ;
                          clavier1=0 ;
                          manette1=1 ;
                         }
                    render_menu (screen,start,settings,quitter,jour,nuit ,set,curseur,i)  ;                        
                       settingss=0 ;
                     }                        

                      
}




}
