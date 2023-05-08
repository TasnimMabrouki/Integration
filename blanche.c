#include "blanche.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sauvegarder(personne p, Ennemi e, background b, char *nomfichier) {
    // Open the file for writing
    FILE *f = fopen(nomfichier, "wb");
    if (f == NULL) {
        printf("Error: could not open file '%s' for writing\n", nomfichier);
        return;
    }
    
    // Write the 'personne' struct to the file
    fwrite(&p, sizeof(personne), 1, f);
    
    // Write the 'Ennemi' struct to the file
    fwrite(&e, sizeof(Ennemi), 1, f);
    
    // Write the 'background' struct to the file
    fwrite(&b, sizeof(background), 1, f);
    
    // Close the file
    fclose(f);
}

void charger(personne *p, Ennemi *e, background *b, char *nomfichier) {
    // Open the file for reading
    FILE *f = fopen(nomfichier, "rb");
    if (f == NULL) {
        printf("Error: could not open file '%s' for reading\n", nomfichier);
        return;
    }
    
    // Read the 'personne' struct from the file
    fread(p, sizeof(personne), 1, f);
    
    // Read the 'Ennemi' struct from the file
    fread(e, sizeof(Ennemi), 1, f);
    
    // Read the 'background' struct from the file
    fread(b, sizeof(background), 1, f);
    
    // Close the file
    fclose(f);
}
