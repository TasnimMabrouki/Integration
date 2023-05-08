#include "buttons.h"
#include <stdlib.h>
#include <stdio.h>
void initBouton(bouton *B,char *ch1,char *ch2,int num)
//les chemins des images ch1 et ch2 car ils changent +pos change
{
	int SCREEN_W=728,SCREEN_H=582;
	
	//les reponses
	B->TabB[0]=IMG_Load(ch1);
	B->TabB[1]=IMG_Load(ch2);
	B->etat=0;
	if(num==1)
	{
		B->pos.x=(SCREEN_W/3)-110;
		B->pos.y=50;
	}
	if(num>=2 && num<=4)
	{
		B->pos.x=SCREEN_W/3;
		B->pos.y=SCREEN_H/5+(num*80);
	}
			
}
void updateButtonSelection(bouton *buttons, int numButtons, int selectedIndex, SDL_Surface *screen)
{
    for (int i = 0; i < numButtons; i++)
    {
        if (i == selectedIndex)
        {
            buttons[i].etat = 1;
        }
        else
        {
            buttons[i].etat = 0;
        }
        afficherBouton(buttons[i], screen);
    }
}
void afficherBouton(bouton B,SDL_Surface *screen)
{
	SDL_BlitSurface(B.TabB[B.etat],NULL,screen,&B.pos);
	SDL_Flip(screen);
}
void libererbouton(bouton b)
{
	SDL_FreeSurface(b.TabB[b.etat]);
}
