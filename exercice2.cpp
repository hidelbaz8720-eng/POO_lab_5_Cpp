#include <iostream>
#include <string>

class Produit {
private:
    std::string nom;
    double prixHT;
    
    // Attribut statique partagé par tous les produits pour le taux de TVA
    static float tauxTVA;

public:
    // Constructeur
    Produit(std::string n, double p) : nom(n), prixHT(p) {}

    // Méthode pour calculer et retourner le prix TTC en utilisant l'attribut statique
    double getPrixTTC() const {
        return prixHT * (1.0 + tauxTVA / 100.0);
    }

    // Méthode statique pour modifier le taux de TVA pour tous les produits
    static void modifierTVA(float nouveauTaux) {
        tauxTVA = nouveauTaux;
    }

    // Méthode d'affichage pour faciliter les tests
    void afficher() const {
        std::cout << "Produit : " << nom 
                  << " | Prix HT : " << prixHT << " €"
                  << " | Prix TTC : " << getPrixTTC() << " €" << std::endl;
    }
};

// Initialisation indispensable de l'attribut statique à 20%
float Produit::tauxTVA = 20.0f;

int main() {
    // 1. Création de plusieurs produits avec le taux initial de 20%
    std::cout << "--- Situation initiale (TVA a 20%) ---" << std::endl;
    Produit p1("Ordinateur", 1000.0);
    Produit p2("Casque audio", 150.0);
    Produit p3("Souris", 50.0);

    p1.afficher();
    p2.afficher();
    p3.afficher();

    // 2. Modification du taux de TVA pour tous les produits (ex: passage à 10%)
    std::cout << "\nModification de la TVA a 10%..." << std::endl;
    Produit::modifierTVA(10.0f);

    // 3. Affichage après modification pour vérifier l'impact global
    std::cout << "\n--- Apres modification (TVA a 10%) ---" << std::endl;
    p1.afficher();
    p2.afficher();
    p3.afficher();

    return 0;
}