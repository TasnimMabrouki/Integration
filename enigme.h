#ifndef ENIGME_h
#define ENIGME_h
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
typedef struct 
{
    SDL_Rect src_rect, dest_rect; 
    SDL_Surface *spritesheet;
    int sprite_index;
    int sprite_width; 
    int sprite_height;
}Entity;

typedef struct {
    char question[100];  //idee: 4 tab ou bien tab pour la suppression
    char choices[3][50];
    SDL_Surface *img;
    SDL_Rect p;
//position d affichage pour chaqu'un
//detection souris et boutons
    int etat; //-1:echec, 0:non encore résolu, 1:succès
    int num_enigme;
    char correct_choice[10];
    char player_choice[10];
}enigme;

void initializeEntity(Entity* entity);
void animateEntity(Entity* entity,SDL_Surface *screen);
void afficherEnigme(enigme e, SDL_Surface * screen);
void genererEnigme(enigme *e, char *nomfichier1, char *nomfichier2);
void generate_afficher (int *alea);
void afficher_resultat (SDL_Surface * screen,char* r,enigme *en);
void libererEntity(Entity *ent);
void libererEnigme(enigme *e);
/*void sauvegarder(personne p, background b,char * nomfichier);
void charger(personne *p, background *b ,char * nomfichier);*/
//void animerEnigme(enigme * e);
//void animerEnigme(SDL_Surface *screen, enigme *e);
#endif

