#include <iostream>
#include <string>

class Utilisateur {
private:
    std::string nom;
    std::string role;
    
    // Attribut statique privé pour suivre le nombre d'utilisateurs connectés
    static int nbUtilisateursConnectes;

public:
    // Constructeur : simule la connexion de l'utilisateur
    Utilisateur(std::string n, std::string r) : nom(n), role(r) {
        nbUtilisateursConnectes++;
        std::cout << "[Connexion] " << nom << " (" << role << ") vient de se connecter." << std::endl;
    }

    // Destructeur : simule la déconnexion de l'utilisateur
    ~Utilisateur() {
        std::cout << "[Deconnexion] " << nom << " vient de se deconnecter." << std::endl;
        nbUtilisateursConnectes--;
    }

    // Méthode statique pour accéder au nombre d'utilisateurs connectés (attribut privé)
    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }

    // Méthode d'affichage des infos
    void afficherInfos() const {
        std::cout << "Utilisateur : " << nom << " | Role : " << role << std::endl;
    }
};

// Initialisation obligatoire de l'attribut statique privé en dehors de la classe
int Utilisateur::nbUtilisateursConnectes = 0;

int main() {
    // 1. État initial (aucun utilisateur)
    std::cout << "=== ETAT INITIAL ===" << std::endl;
    std::cout << "Utilisateurs connectes : " << Utilisateur::getNbUtilisateursConnectes() << "\n\n";

    // 2. Simulation d'un bloc de connexions (gestion par portée)
    std::cout << "=== CONNEXIONS SIMULTANEES ===" << std::endl;
    {
        Utilisateur u1("Alice", "admin");
        std::cout << "-> Nombre d'utilisateurs connectes : " << Utilisateur::getNbUtilisateursConnectes() << std::endl;

        Utilisateur u2("Bob", "visiteur");
        std::cout << "-> Nombre d'utilisateurs connectes : " << Utilisateur::getNbUtilisateursConnectes() << std::endl;

        Utilisateur u3("Charlie", "visiteur");
        std::cout << "-> Nombre d'utilisateurs connectes : " << Utilisateur::getNbUtilisateursConnectes() << std::endl;
        
        std::cout << "\nFin du bloc : destruction automatique des objets u1, u2, u3..." << std::endl;
    } 
    // Sortie du bloc : les destructeurs s'exécutent automatiquement ici

    std::cout << "\n=== APRES DECONNEXION AUTOMATIQUE ===" << std::endl;
    std::cout << "Utilisateurs connectes : " << Utilisateur::getNbUtilisateursConnectes() << "\n\n";

    // 3. Simulation d'une connexion dynamique (allocation tas / heap)
    std::cout << "=== CONNEXION DYNAMIQUE ===" << std::endl;
    Utilisateur* u4 = new Utilisateur("Diana", "admin");
    std::cout << "-> Nombre d'utilisateurs connectes : " << Utilisateur::getNbUtilisateursConnectes() << std::endl;

    // Déconnexion manuelle via delete
    std::cout << "\nSuppression manuelle de l'utilisateur dynamique..." << std::endl;
    delete u4; // Appelle explicitement le destructeur

    std::cout << "\n=== ETAT FINAL ===" << std::endl;
    std::cout << "Utilisateurs connectes : " << Utilisateur::getNbUtilisateursConnectes() << std::endl;

    return 0;
}