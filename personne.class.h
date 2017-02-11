#ifndef PERSONNE_CLASS_H
#define PERSONNE_CLASS_H
#include "decision.class.h"
#include <iostream>
#include "SDL/include/SDL.h"
#include <vector>
#include <time.h>
#include <algorithm>
#include <functional>
#include "config.h"
class Personne{
    private:
        static unsigned int countPersonnes;
        unsigned int id;
        int current_etage;
        bool visible;
        int posX, posY;
        float time_arrive;
        float vitesse;
        int cols_aim; /// La colonne o� il se dirige
        bool busy; /// Est il occup� ? Si oui, on ne lui donne pas de nouvelles directives
        bool waitElevators;
        bool isHome; /// est rentr� chez lui ?
        int ascenseur_id; /// L'ascenseur o� il se trouve/va
        int aim_etage; /// L'�tage o� on lui indique d'aller, permet de g�rer le fait d'aller � un �tage X, pour y prendre un ascenseur
        std::vector<Decision> listes_montant; /// Premi�re partie de ses courses
        std::vector<Decision> listes_descendant;  /// Derni�re partie de ses courses
        float attente_total;
        float attente;
        unsigned int nombreVoyages;
    public:
        Personne();
        ~Personne();
        std::vector<int> getListesEtages();
        Decision& getNextDecision();
        void setCurrentEtage(int);
        int getCurrentEtage();
        int getNextEtages();
        float getTimeArrive();
        void setPosition(int,int);
        void setVisible(bool);
        void setVitesse(float);
        void setColsAim(int);
        bool getWaitElevators();
        void setWaitElevators(bool);
        void setTimeArrive(float);
        void setBusy(bool);
        bool getVisible();
        bool getBusy();
        float getVitesse();
        int getColsAim();
        int getPositionX();
        int getPositionY();
        void removeDecision();
        bool getIsHome();
        void setIsHome(bool);
        int getAscenseurId();
        void setAscenseur(int);
        float getTempsAttente();
        void setTempsAttente(float);
        unsigned int getNombreVoyages();
        float getTempsTotal();
        void setAimEtage(int);
        int getAimEtage();
};

bool vectorHave(int, std::vector<int>); /// Fonction de recherche dans un vecteur, la complexit� est de type n (pas tr�s bonne)
bool vectorHave(int, std::vector<unsigned int>);  /// Fonction de recherche dans un vecteur, la complexit� est de type n (pas tr�s bonne)
std::vector<int> vectorGetCommun(std::vector<unsigned int> a, std::vector<unsigned int> b);  /// Fonction de recherche dans un vecteur, la complexit� est de type n� (pas tr�s bonne)
#endif // PERSONNE_CLASS_H
