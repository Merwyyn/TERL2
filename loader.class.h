#ifndef LOAD_CLASS_H
#define LOAD_CLASS_H

#include "SDL/include/SDL.h"
#include "SDL/include/SDL_image.h"
#include "SDL/include/SDL_ttf.h"
enum{ECRAN,VIDE,ASCENSEUR,PERSONNE,ASCENSEUR_REAL,ASCENSEUR_OPEN,TOOLTIP_SCREEN,PERSONNE_HOVER};
class LoaderObject{
    private:
        SDL_Window *window;
        SDL_Surface *ecran;
        SDL_Surface *vide;
        SDL_Surface *ascenseur;
        SDL_Surface *personne;
        SDL_Surface *ascenseur_real;
        SDL_Surface *ascenseur_open;
        SDL_Surface *texte;
        SDL_Surface *tooltip_screen;
        SDL_Surface *personne_hover;
        TTF_Font *police;
        bool error;
    public:
        LoaderObject(int, int);
        ~LoaderObject();
        SDL_Surface* getSurface(int);
        void setSurface(int, SDL_Surface*);
        TTF_Font* getPolice();
        bool getError();
        SDL_Window* getWindow();
};

#endif // LOAD_CLASS_H
