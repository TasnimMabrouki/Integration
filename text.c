#include<SDL/SDL.h>
#include"text.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
//liberer memoire a chaque fois on quitte un stage

void initText(Text *A)
{
	A->position.x=220;
	A->position.y=50;
//couleur jaune
	A->textColor.r=255;
	A->textColor.g=255;
	A->textColor.b=0;
	A->font=TTF_OpenFont("Ubuntu-RI.ttf",70);
	if(!A->font){
		fprintf(stderr,"Error opening font: %s \n",TTF_GetError());
		exit(1);
	}
	A->SurfaceTexte=NULL;
}
void freeText(Text A)
{
	SDL_FreeSurface(A.SurfaceTexte);
	TTF_CloseFont(A.font);
}
void displayText(Text t,SDL_Surface *screen)//affichage
{
	t.SurfaceTexte=TTF_RenderText_Blended(t.font,"METIS",t.textColor);
	if(!t.SurfaceTexte){
		fprintf(stderr,"Error rendering text: %s\n",TTF_GetError());
		exit(1);
	}
	SDL_BlitSurface(t.SurfaceTexte,NULL,screen,&t.position);
}

