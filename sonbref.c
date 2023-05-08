#include "sonbref.h"
Mix_Chunk* load_sound_effect()
{
	Mix_Chunk* soundEffect=Mix_LoadWAV("Clock_Sound.wav");
	if(soundEffect==NULL){
		printf("Failed to load!SDL_mixer Error: %s\n",Mix_GetError());}
	return soundEffect;
}
void cleanup_sound_effect(Mix_Chunk* soundEffect)
{
	//clean up ressources
	Mix_FreeChunk(soundEffect);
	Mix_CloseAudio();
}
Mix_Chunk* load_sound()
{
	Mix_Chunk* sound=Mix_LoadWAV("Sound.wav");
	if(sound==NULL){
		printf("Failed to load!SDL_mixer Error: %s\n",Mix_GetError());}
	return sound;
}
void cleanup_sound(Mix_Chunk* sound)
{
	//clean up ressources
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
}
