#include "enigme.h"
#include"image.h"
#include "buttons.h"
#include "son.h"
#include "sonbref.h"
#include "ennemi.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>  
#include <SDL/SDL_mixer.h>
#define LARGEUR_ECRAN 728
#define HAUTEUR_ECRAN 582

int main(int agrc,char** argv) 
{
    int SCREEN_W=728,SCREEN_H=582;
	 SDL_WM_SetCaption("entite secondaire", NULL);
         SDL_Rect pos_perso;
    char f1[20]="Questions.txt";
    char f2[20]="Reponses.txt";
	backg bg;
	bouton B[4];
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    Mix_Music* music;
    SDL_Surface *screen;
    int done=1,a_pressed=0,b_pressed=0,c_pressed=0,i;
    char response[10];
    int nb=0; //nb d'affichage
    SDL_Event event;
    enigme e;
	bouton b;
Entity entity;

SDL_Surface *background;
  SDL_Surface *personne;
  SDL_Surface *personne2=NULL;
Ennemi en;
//char line[100];
    screen=SDL_SetVideoMode(728, 582, 32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    if(!screen){
		printf("Unable to set 640x480 video: %s\n",SDL_GetError());
		return 1;}
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1) {
	        return 1;}
//initialisation des variables
	pos_perso.h = 114;
  pos_perso.w = 71;
  pos_perso.x = 0;
  pos_perso.y = 600 - pos_perso.h;
initEnnemi(&en);

background = IMG_Load("background.png");
  personne = IMG_Load("personne.png");
  personne2 = IMG_Load("personne2.png");
	initBackg(&bg);
	initializeEntity(&entity);
	initBouton(&B[0],"q.png","q.png",1);
	initBouton(&B[1],"bnc.png","bc.png",2);
	initBouton(&B[2],"bnc.png","bc.png",3);
	initBouton(&B[3],"bnc.png","bc.png",4);
	music = load_music("music.mp3");
	Mix_Chunk* soundEffect=load_sound_effect(); //load the sound effect of the clock ticking
	Mix_Chunk* sound=load_sound();
	e.img=IMG_Load("t.png");
	
    genererEnigme(&e,f1,f2);
//loop
    while(done)
    {
	//Display
	SDL_BlitSurface(background, NULL, screen, NULL);
    SDL_BlitSurface(personne, NULL, screen, &pos_perso);

    deplacerEnnemi(&en);
    animerEnnemi(&en);
    afficherEnnemi(en, screen);
    deplacerIAEnnemi(&en,pos_perso);
    if (collisionBB_Ennemi(en.pos, pos_perso) == 1)
    {
    SDL_BlitSurface(personne2, NULL, screen, &pos_perso);
	afficherBackg(bg,screen);
	//SDL_Flip(screen);
	afficherBouton(B[0],screen);
	afficherBouton(B[1],screen);
	afficherBouton(B[2],screen);
	afficherBouton(B[3],screen);
	//SDL_Flip(screen);
	if(a_pressed==1)
	{
	Mix_PlayChannel( -1,sound, 0 ); 
	B[1].etat=1;
	//afficherBouton(B[0],screen);
	//SDL_Delay(5000);
	strcpy(response,"a");
	}
	else{
		if(b_pressed==1)
		{
			Mix_PlayChannel( -1, sound, 0 ); 
			B[2].etat=1;
			//afficherBouton(B[1],screen);
			//SDL_Delay(5000);
		        strcpy(response,"b");
		}
	
		else{
			if(c_pressed==1)
			{
			Mix_PlayChannel( -1,sound, 0 );
			B[3].etat=1;
	 		//afficherBouton(B[2],screen); 
			//SDL_Delay(5000);
		        strcpy(response,"c");
			}
		}
	}
        afficherEnigme(e,screen);
       if(nb<7 ) { // 3 seconds per sprite
		Mix_PlayChannel(-1,soundEffect,0);
                animateEntity(&entity,screen);
		//SDL_Flip(screen);
		nb++;
		// Mettre à jour la position de l'entité sur l'écran
    		entity.sprite_index++;
		}
	
	/*if(strcmp(response,"nothing")==0)
	{
 		SDL_BlitSurface(e.img, NULL, screen, &(e.p)) ;
		e.etat=0;
        	//SDL_Flip(screen);
	}
	else
	{*/
	afficher_resultat (screen,response,&e);
	if(e.etat==1){
	e.img=IMG_Load("w.png");
		e.p.x=500;
		e.p.y=0;
 		SDL_BlitSurface(e.img, NULL, screen, &(e.p)) ;}
	else{
	e.img=IMG_Load("f.png");
		e.p.x=500;
		e.p.y=0;
 		SDL_BlitSurface(e.img, NULL, screen, &(e.p)) ;}
        	//SDL_Flip(screen);
		//SDL_Delay(10000);
	//}
    }
    else
    {
    SDL_BlitSurface(personne, NULL, screen, &pos_perso);
    }
    SDL_Flip(screen);
    SDL_Delay(50);

	
	
	
	//Input
		SDL_PollEvent(&event);
		switch(event.type)
		{
		case SDL_QUIT:
            		done = 0;
			SDL_Quit();
            	break;
       		case SDL_KEYDOWN:
            	switch (event.key.keysym.sym) 
		{
               		case SDLK_ESCAPE:
			SDL_Quit();
                   	 done = 0;
                   	 break;
			 case SDLK_LEFT:
          pos_perso.x -= 100;

          break;
        case SDLK_RIGHT:
          pos_perso.x += 100;

          break;
        case SDLK_UP:
          pos_perso.y -= 100;
          break;
        case SDLK_DOWN:
          pos_perso.y += 100;
          break;
                	case  SDLK_a:
				a_pressed=1;
				b_pressed=0;
				c_pressed=0;
			      	B[1].etat=1;
			   break ;
			case  SDLK_b:
				b_pressed=1;
				a_pressed=0;
				c_pressed=0;
			        B[2].etat=1;
			    break;
			case SDLK_c:
				c_pressed=1;
				b_pressed=0;
				a_pressed=0;
			        B[3].etat=1;
			   break;
		}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) 
		        {
			case SDLK_a:
				a_pressed=0;
				B[1].etat=0;
		        break;
			case SDLK_b:
				b_pressed=0;
				B[2].etat=0;
		        break;
			case SDLK_c:
				c_pressed=0;
				B[3].etat=0;
		        break;
			}break;
		/*case SDL_MOUSEMOTION:
		{
			if(event.motion.x>=133 && event.motion.x<=133+282 && 
			event.motion.y>=50 && event.motion.y<=50+84)
				{B[1].etat=1;
				afficherBouton(B[1],screen);
				Mix_PlayChannel(-1,sound,0);}
			else
				{B[1].etat=0;
				afficherBouton(B[1],screen);}*
			//proposition 1
			if(event.motion.x>=243 && event.motion.x<=243+282 && 
			event.motion.y>=186 && event.motion.y<=186+84)
				{
				B[1].etat=1;
				afficherBouton(B[1],screen);
				Mix_PlayChannel(-1,sound,0);}
			else
				{B[1].etat=0;
				afficherBouton(B[1],screen);}
			//proposition 2
			if(event.motion.x>=243 && event.motion.x<=243+282 && 
			event.motion.y>=266 && event.motion.y<=266+84)
				{
				B[2].etat=1;
				afficherBouton(B[2],screen);
				Mix_PlayChannel(-1,sound,0);}
			else
				{B[2].etat=0;
				afficherBouton(B[2],screen);}
			//proposition 3
			if(event.motion.x>=243 && event.motion.x<=243+282 && 
			event.motion.y>=346 && event.motion.y<=346+84)
				{
				B[3].etat=1;
				afficherBouton(B[3],screen);
				Mix_PlayChannel(-1,sound,0);}
			else
				{B[3].etat=0;
				afficherBouton(B[3],screen);}
			SDL_Flip(screen);
			
		}
		break;
		case SDL_MOUSEBUTTONUP:
		{
		if(event.button.button == SDL_BUTTON_LEFT)
			{
			if(event.button.x>=243 && event.button.x<=243+282 && event.button.y>=186 && event.button.y<=186+84)
				{a_pressed=1;
				b_pressed=0;
				c_pressed=0;
				strcpy(response,"a");}
			else if(event.button.x>=243 && event.button.x<=243+282 && event.button.y>=266 && event.button.y<=266+84)
				{b_pressed=1;
				a_pressed=0;
				c_pressed=0;
				strcpy(response,"b");}
			else if(event.button.x>=243 && event.button.x<=243+282 && event.button.y>=346 && event.button.y<=346+84)
				{c_pressed=1;
				b_pressed=0;
				a_pressed=0;
				strcpy(response,"c");}
			}
		}
		break;
		}*/
    }
    
}


    //free surfaces
SDL_FreeSurface(background);
  SDL_FreeSurface(personne);
  SDL_FreeSurface(personne2);
  libererEnnemi(&en);

    libererBackg(&bg);
    for(i=0;i<4;i++)
    	{libererbouton(B[i]);}
    SDL_FreeSurface(screen);
	libererEntity(&entity);
	libererEnigme(&e);
    free_music(music);
    TTF_Quit();
    cleanup_sound_effect(soundEffect);
    cleanup_sound(sound);
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}
