#ifndef SOUND_H
#define sOUND_H

#include <SDL/SDL_mixer.h>

Mix_Music* load_music(const char* filename);
void free_music(Mix_Music* music);

#endif
/*SDL_mixer;
//Initialiser les fonctions audio de SDL_mixer
int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize);
//Chargement de la musique
Mix_Music *musique;
musique = Mix_LoadMUS("musique.mp3");
//Jouer la musique
int Mix_PlayMusic(Mix_Music *music, int loops);
//Libération de la musique
Mix_FreeMusic(musique); 

//son bref
//Chargement des effets sonores:
Mix_Chunk * son;
son= Mix_LoadWAV( "effet.wav" );
//Jouer l'effet sonore
Mix_PlayChannel( -1, son, 0 ); //0 pour repeter une seule fois
//Libération des effets sonores 
Mix_FreeChunk( son);*/ 
