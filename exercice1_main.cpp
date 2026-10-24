
#include <iostream>

class Boite {
private:
    double longueur;
    double largeur;
    double hauteur;
    
    // Attribut statique pour compter les boîtes
    static int nbBoites;

public:
    // Constructeur par défaut et paramétré
    Boite(double l = 0.0, double la = 0.0, double h = 0.0) 
        : longueur(l), largeur(la), hauteur(h) {
        nbBoites++; // Incrémentation dans le constructeur
    }

    // Destructeur
    ~Boite() {
        nbBoites--; // Décrémentation dans le destructeur
    }

    // Méthode statique pour récupérer le nombre de boîtes
    static int getNombreBoites() {
        return nbBoites;
    }
};

// Initialisation indispensable de l'attribut statique en dehors de la classe
int Boite::nbBoites = 0;

int main() {
    // Affichage initial
    std::cout << "Nombre de boites au debut : " << Boite::getNombreBoites() << std::endl;

    // Création d'un bloc pour tester la portée et le destructeur automatique
    {
        Boite b1(10.0, 5.0, 2.0);
        Boite b2(3.0, 3.0, 3.0);
        std::cout << "Nombre de boites dans le bloc : " << Boite::getNombreBoites() << std::endl;
    } // Fin du bloc : b1 et b2 sont détruits ici, le destructeur est appelé

    std::cout << "Nombre de boites apres la sortie du bloc : " << Boite::getNombreBoites() << std::endl;

    // Allocation dynamique d'une boîte
    Boite* b3 = new Boite(7.0, 4.0, 5.0);
    std::cout << "Nombre de boites apres allocation dynamique : " << Boite::getNombreBoites() << std::endl;

    // Libération manuelle de la mémoire (appelle le destructeur)
    delete b3;
    std::cout << "Nombre de boites apres suppression (delete) : " << Boite::getNombreBoites() << std::endl;

    return 0;
}