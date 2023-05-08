#include "son.h"
#include <stdio.h>

Mix_Music* load_music(const char* filename) {
  Mix_Music* music;

  // Charger la musique
  music = Mix_LoadMUS(filename);
  if (!music) {
    printf("Erreur lors du chargement de la musique : %s\n", Mix_GetError());
  }
  Mix_PlayMusic(music,-1);
  return music;}
void free_music(Mix_Music* music) {
  // Libération de la mémoire allouée pour la musique
  Mix_FreeMusic(music);
}



