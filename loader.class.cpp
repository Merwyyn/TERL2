#include <cstdlib>
#include <iostream>
#include "loader.class.h"
using namespace std;
LoaderObject::LoaderObject(int w, int h){
    error=false;
    vide=IMG_Load("vide.png");
    if (vide==NULL)
    {
        cout << "Erreur chargement image vide" << endl;
        error=true;
    }
    ascenseur=IMG_Load("ascenseur.png");
    if (ascenseur==NULL)
    {
        cout << "Erreur chargement image ascenseur" << endl;
        error=true;
    }
    personne=IMG_Load("personne.png");
    if (personne==NULL)
    {
        cout << "Erreur chargement image personne" << endl;
        error=true;
    }
    ascenseur_real=IMG_Load("ascenseur_real.png");
    if (ascenseur_real==NULL)
    {
        cout << "Erreur chargement image ascenseur_real" << endl;
        error=true;
    }
    ascenseur_open=IMG_Load("ascenseur_open.png");
    if (ascenseur_open==NULL)
    {
        cout << "Erreur chargement image ascenseur_open" << endl;
        error=true;
    }
    personne_hover=IMG_Load("personne_hover.png");
    if (ascenseur_open==NULL)
    {
        cout << "Erreur chargement image personne_hover" << endl;
        error=true;
    }
    tooltip_screen=SDL_CreateRGBSurface(0, 600, 200, 32, 0, 0, 0, 0);
    if (tooltip_screen==NULL)
    {
        cout << "Erreur chargement surface tooltip_screen" << endl;
        error=true;
    }
    if (h>6)
        h=6;
    if (w>6)
        w=6;
    window = SDL_CreateWindow("Simulation Ascenseur", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w*ascenseur->w, h*ascenseur->h, 0);
    if (!window)
    {
        cout << "Unable to set " << w*ascenseur->w << "x" << h*ascenseur->h << " video " << SDL_GetError() << endl;
        error=true;
    }
    ecran = SDL_GetWindowSurface(window);
    SDL_FillRect(tooltip_screen, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
}

LoaderObject::~LoaderObject(){
    SDL_FreeSurface(ascenseur);
    SDL_FreeSurface(vide);
    SDL_FreeSurface(personne);
    SDL_FreeSurface(ascenseur_real);
    SDL_FreeSurface(ascenseur_open);
    SDL_FreeSurface(tooltip_screen);
    SDL_FreeSurface(personne_hover);
}

SDL_Surface* LoaderObject::getSurface(int s){
    switch (s){
        default:
            return ecran;
            break;
        case VIDE:
            return vide;
        case ASCENSEUR:
            return ascenseur;
        case PERSONNE:
            return personne;
        case ASCENSEUR_REAL:
            return ascenseur_real;
        case ASCENSEUR_OPEN:
            return ascenseur_open;
        case TOOLTIP_SCREEN:
            return tooltip_screen;
        case PERSONNE_HOVER:
            return personne_hover;
    }
}

bool LoaderObject::getError(){
    return error;
}

SDL_Window* LoaderObject::getWindow(){
    return window;
}
