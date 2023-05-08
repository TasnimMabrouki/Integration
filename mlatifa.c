#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ennemi.h"

int main()
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen;
  screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  SDL_WM_SetCaption("entite secondaire", NULL);
  SDL_Rect pos_perso;

  pos_perso.h = 114;
  pos_perso.w = 71;
  pos_perso.x = 0;
  pos_perso.y = 600 - pos_perso.h;
 
  Ennemi e;

  SDL_Event event;
  SDL_Surface *background;
  SDL_Surface *personne;
  SDL_Surface *personne2=NULL;

  initEnnemi(&e);
  int continuer = 1;
  background = IMG_Load("background.png");
  personne = IMG_Load("personne.png");
  personne2 = IMG_Load("personne2.png");

  while (continuer)
  {

    while (SDL_PollEvent(&event))
    {

      switch (event.type)
      {
      case SDL_QUIT:

        continuer = 0;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {

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
        }
        break;
      }
    }
    SDL_BlitSurface(background, NULL, screen, NULL);
    SDL_BlitSurface(personne, NULL, screen, &pos_perso);

    deplacerEnnemi(&e);
    animerEnnemi(&e);
    afficherEnnemi(e, screen);
    deplacerIAEnnemi(&e,pos_perso);
  if (collisionBB_Ennemi(e.pos, pos_perso) == 1)
  {
    SDL_BlitSurface(personne2, NULL, screen, &pos_perso);
  }
  else
  {
    SDL_BlitSurface(personne, NULL, screen, &pos_perso);
  }

    SDL_Flip(screen);
    SDL_Delay(50);
  }
  SDL_FreeSurface(background);
  SDL_FreeSurface(personne);
  SDL_FreeSurface(personne2);
  libererEnnemi(&e);
  SDL_Quit();
}
