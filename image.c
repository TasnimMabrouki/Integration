
#include"image.h"
void initBackg(backg *bg)
{
	bg->bk=IMG_Load("bg.jpg");
	if(bg->bk==NULL)
		printf("background n'existe pas\n");
	bg->pos.x=0;
	bg->pos.y=0;
	
	
}
void afficherBackg(backg bg,SDL_Surface *screen)
{
	SDL_BlitSurface(bg.bk,NULL,screen,&bg.pos);
	SDL_Flip(screen);
}
void libererBackg(backg *bg)
{
	SDL_FreeSurface(bg->bk);
	bg->bk= NULL;
}

