#include "enigme.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NB_REPONSES 3
#define MAX_LONGUEUR 100
#define LARGEUR_ECRAN 728
#define HAUTEUR_ECRAN 582

void genererEnigme(enigme *e, char nomfichier1[], char nomfichier2[])
{
	e->p.x=0;
	e->p.y=0;
	e->img=NULL;
    FILE * f_questions=NULL, * f_reponses=NULL;
    char line[2000];
    char s[20];
    int i;
	//generate_afficher(&e->num_enigme);
    // Open the files for reading
    f_questions = fopen(nomfichier1,"r");
    if (f_questions== NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des questions \n");
        return;
    }
    // Read the question from the questions file
    fgets(line,2000,f_questions);
    strcpy(e->question,line);
	printf("%s \n",e->question);
    // Read the answer choices from the questions file
    for (i = 0; i < 3; i++) {
        fgets(line,2000, f_questions);
        strcpy(e->choices[i],line);
    }
    // Close the file
    fclose(f_questions);
	
    f_reponses = fopen(nomfichier2,"r");
    if (f_reponses== NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des reponses \n");
        return;
    }
    // Read the answer from the answers file and assign it to the correct choice
    fgets(s,20,f_reponses);
    strcpy(e->correct_choice, s);
    printf("la bonne reponse: %s\n",e->correct_choice);
    // Close the file
    fclose(f_reponses);
}

void afficherEnigme(enigme e, SDL_Surface *screen) {
    int i;
    SDL_Color couleur = {255,255,255};
    TTF_Font* police = TTF_OpenFont("Ubuntu-RI.ttf",17);
    SDL_Surface *texte_question = TTF_RenderText_Blended(police,e.question,couleur);
    SDL_Rect position_question = {130,150,0,0};
    SDL_BlitSurface(texte_question, NULL, screen, &position_question);
    //SDL_Flip(screen);
    SDL_Surface *texte_choix[NB_REPONSES];
    SDL_Rect position_choix[NB_REPONSES];
    for (i = 0; i < NB_REPONSES; i++) {
        texte_choix[i] = TTF_RenderText_Blended(police, e.choices[i], couleur);
        position_choix[i].x = 350;
        position_choix[i].y = 300 + i * 85;
        SDL_BlitSurface(texte_choix[i], NULL, screen, &position_choix[i]);
	SDL_Flip(screen);
    }

    SDL_FreeSurface(texte_question);
    for (i = 0; i < NB_REPONSES; i++) {
        SDL_FreeSurface(texte_choix[i]);
    }
    TTF_CloseFont(police);
}


// Fonction pour initialiser l'entité à animer
void initializeEntity(Entity* entity) {
    entity->spritesheet = IMG_Load("hourglass.png");
    entity->sprite_width =535/7 ; //7 sprites in the sprite sheet
    entity->sprite_height = 69;
    entity->dest_rect.x = 10; // fixed position
    entity->dest_rect.y = 500; // fixed position
    entity->dest_rect.w = entity->sprite_width;
    entity->dest_rect.h = entity->sprite_height;
    entity->sprite_index = 0;
}

// Fonction pour animer l'entité
void animateEntity(Entity* entity,SDL_Surface *screen) {
        entity->src_rect.x = entity->sprite_index % 7 * entity->sprite_width;
        entity->src_rect.y = 0;
        entity->src_rect.w = entity->sprite_width;
        entity->src_rect.h = entity->sprite_height;
        SDL_BlitSurface(entity->spritesheet, &entity->src_rect, screen, &entity->dest_rect);
	SDL_Flip(screen);
	SDL_Delay(3000);
	}

void generate_afficher (int *alea) //random enigms from 1 engims to 3 engims //
{
	int test=*alea ;
       srand(SDL_GetTicks()); // SDL_gettick to generate number //   

 do
  {
     *alea = 1+ rand()%3; 
  }
while(*alea==test) ; 
}


/////////////////////////////////////////////////////
 void afficher_resultat (SDL_Surface * screen,char* r,enigme *en)
 {

 	if (strcmp(r,en->correct_choice)==0)
 	{
 		
        	//SDL_Flip(screen);
		en->etat=1;
 	}
 	else
 	{
		en->etat=-1;
 	}
 }
void libererEntity(Entity *ent)
{
	SDL_FreeSurface(ent->spritesheet);
   	 ent->spritesheet= NULL;
}
void libererEnigme(enigme *e)
{
	SDL_FreeSurface(e->img);
   	 e->img= NULL;
}
////////////////////////////////////////////////
   
/*void charger(personne *p, background *b,char * nomfichier)
{

}
void sauvegarder(personne p, background b,char * nomfichier)
{

}*/


