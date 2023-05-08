#ifndef BUTTON_H
#define BUTTON_H
#include<SDL/SDL_image.h>
typedef struct{
	SDL_Surface *TabB[2];
	SDL_Rect pos;
	//Mix_Chunk son;
	int etat;}bouton;	
void initBouton(bouton *B,char *ch1,char *ch2,int num);
void updateButtonSelection(bouton *buttons, int numButtons, int selectedIndex, SDL_Surface *screen);
void afficherBouton(bouton b,SDL_Surface *screen);
void libererbouton(bouton b);
#endif
