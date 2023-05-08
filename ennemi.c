#include "ennemi.h"

void initEnnemi(Ennemi *e)
{
    e->ennemi = IMG_Load("ennemi.png");
    e->pos.y = 400;
    e->pos.x = 800;
    e->direction = 1;
    e->speed = 10;
    e->pos_sp.x = 0;
    e->pos_sp.y = 0;
    e->pos_sp.h = 100;
    e->pos_sp.w = 100;
}
void afficherEnnemi(Ennemi e, SDL_Surface *screen)
{
    SDL_BlitSurface(e.ennemi, &e.pos_sp, screen, &e.pos);
}
void animerEnnemi(Ennemi *e)
{
    if (e->pos_sp.x == 800)
    {
        e->pos_sp.x = 0;
    }
    e->pos_sp.x += e->pos_sp.w;
    e->pos_sp.y = e->direction * e->pos_sp.h;
}
void deplacerEnnemi(Ennemi* e) 
{
    int speed = -10;
    int largeur_fenetre = 800;
    int depassement = 80; 
    e->pos.x += speed;
    if (e->pos.x < -e->pos.w - depassement) 
    {
        e->pos.x = largeur_fenetre + depassement;
    }
}
int collisionBB_Ennemi(SDL_Rect E, SDL_Rect p)
{
    int collision;
    if (((p.x + p.w) < E.x) || (p.x > (E.x + E.w)) || ((p.y + p.h) < E.y) || (p.y > (E.y + E.h)))
    {
        collision = 0;
    }
    else
    {
        collision = 1;
    }
    return collision;
}
void deplacerIAEnnemi(Ennemi *e, SDL_Rect pos_perso)
{
    if (((e->pos.x - pos_perso.x) < 200) && ((e->pos.x - pos_perso.x) > 80))
    {
        e->direction = 1;
        e->pos.x -= 20;
    }
    else if (((e->pos.x - pos_perso.x) < -80) && ((e->pos.x - pos_perso.x) > -200))
    {
        e->direction = 0;
        e->pos.x += 20;
    }
    else if (((e->pos.x - pos_perso.x) <= 80) && ((e->pos.x - pos_perso.x) >= 0))
    {
        e->direction = 3;
    }
    else if (((e->pos.x - pos_perso.x) <= 0) && ((e->pos.x - pos_perso.x) >= -80))
    {
        e->direction = 2;
    }
}
void libererEnnemi(Ennemi *e)
{
    SDL_FreeSurface(e->ennemi);
    e->ennemi = NULL;
}

