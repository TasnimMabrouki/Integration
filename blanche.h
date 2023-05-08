#ifndef ENIGME_h
#define ENIGME_h
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct{
	SDL_Rect pos_perso;
}personne;

typedef struct{
	SDL_Surface * bk;
	SDL_Rect pos;
}background;

typedef struct Ennemi
{
        SDL_Surface *ennemi;
        SDL_Rect pos;
        SDL_Rect pos_sp;
        int direction;
        float speed;

}Ennemi;
void sauvegarder(personne p,Ennemi e, background b,char * nomfichier);
void charger(personne *p,Ennemi *e, background *b ,char * nomfichier);
#endif
