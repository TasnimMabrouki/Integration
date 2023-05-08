#ifndef image_H
#define image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct{
	SDL_Surface * bk;
	SDL_Rect pos;
}backg;
void initBackg(backg *bg);
void afficherBackg(backg bg,SDL_Surface *screen);
void libererBackg(backg *bg);

#endif

