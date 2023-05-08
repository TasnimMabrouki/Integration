#ifndef SONBREF_H
#define SONBREF_H
#include <SDL/SDL_mixer.h>
//load sound effect of the clock ticking//
Mix_Chunk* load_sound_effect();
//free sound effect and clean up ressources
void cleanup_sound_effect(Mix_Chunk* soundEffect);
//Sound of the butoons//
Mix_Chunk* load_sound();
void cleanup_sound(Mix_Chunk* sound);
#endif
