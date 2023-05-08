#include "blanche.h"
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
    

    // Create some test data
    personne p = { { 0, 600 - 114, 71, 114 } };
    Ennemi e = { NULL, { 100, 100, 50, 50 }, { 0, 0, 50, 50 }, 1, 2.5 };
    background b = { NULL, { 0, 0, 800, 600 } };
    
    // Save the data to a binary file
    sauvegarder(p, e, b, "binaire.bin");
    
    // Load the data from the binary file
    personne p2;
    Ennemi e2;
    background b2;
    charger(&p2, &e2, &b2, "binaire.bin");
    
    // Print out the loaded data to verify that it was loaded correctly
    printf("Loaded data:\n");
    printf("personne: pos_perso = { x=%d, y=%d, w=%d, h=%d }\n", p2.pos_perso.x, p2.pos_perso.y, p2.pos_perso.w, p2.pos_perso.h);
    printf("Ennemi: pos = { x=%d, y=%d, w=%d, h=%d }, pos_sp = { x=%d, y=%d, w=%d, h=%d }, direction = %d, speed = %f\n", e2.pos.x, e2.pos.y, e2.pos.w, e2.pos.h, e2.pos_sp.x, e2.pos_sp.y, e2.pos_sp.w, e2.pos_sp.h, e2.direction, e2.speed);
    printf("background: pos = { x=%d, y=%d, w=%d, h=%d }\n", b2.pos.x, b2.pos.y, b2.pos.w, b2.pos.h);
    
    return 0;
}
    
