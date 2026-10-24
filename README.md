# TP 5 – Attributs et méthodes statiques en C++

##  Description du projet

Ce projet a été réalisé dans le cadre de la formation en programmation orientée objet (POO) en C++ sur la plateforme MLIAEdu.

L’objectif de ce TP est de comprendre et de mettre en pratique les **attributs statiques et les méthodes statiques** en C++, à travers trois exercices pratiques.

##  Objectifs pédagogiques

- Comprendre le fonctionnement des attributs statiques.
- Utiliser les méthodes statiques pour accéder aux données partagées.
- Maîtriser les constructeurs et les destructeurs.
- Gérer un compteur d’objets et le nombre d’utilisateurs connectés.
- Appliquer un taux de TVA commun à plusieurs produits.

## Exercices réalisés

### Exercice 1 : Compteur d’objets
- Création d’une classe `Boite` avec longueur, largeur et hauteur.
- Utilisation de l’attribut statique `nbBoites`.
- Incrémentation du compteur dans le constructeur.
- Décrémentation du compteur dans le destructeur.
- Affichage du nombre d’objets grâce à `getNombreBoites()`.

### Exercice 2 : Taux de TVA partagé
- Création d’une classe `Produit` avec un nom et un prix hors taxe.
- Définition d’un attribut statique `tauxTVA`, initialisé à 20 %.
- Calcul du prix TTC avec `getPrixTTC()`.
- Modification du taux de TVA pour tous les produits avec `modifierTVA()`.

### Exercice 3 : Gestion des sessions utilisateurs
- Création d’une classe `Utilisateur` avec un nom et un rôle.
- Utilisation de l’attribut statique privé `nbUtilisateursConnectes`.
- Mise à jour du nombre de connexions dans le constructeur et le destructeur.
- Consultation du nombre d’utilisateurs connectés avec `getNbUtilisateursConnectes()`.

## 🛠️ Technologies utilisées

- **Langage :** C++
- **Concepts :** Programmation orientée objet, attributs statiques, méthodes statiques, constructeurs et destructeurs.
- **Environnement :** Compilateur C++ compatible.

## Captures d’écran de l’exécution

Les captures d’écran ci-dessous sont réservées aux résultats de l’exécution des trois exercices.

### Exercice 1 – Compteur d’objets

<img width="1366" height="768" alt="ex1" src="https://github.com/user-attachments/assets/f029bd7b-1da1-4586-bec3-e6ebcaeb178b" />


### Exercice 2 – Taux de TVA partagé

<img width="1366" height="768" alt="ex2" src="https://github.com/user-attachments/assets/4a614303-e6ae-4fe2-afb3-28deb0fbddd9" />


### Exercice 3 – Gestion des sessions utilisateurs

<img width="1366" height="768" alt="ex3" src="https://github.com/user-attachments/assets/729b95d0-4bec-4a3f-8f2a-6714db2624be" />

`


Remplacer `exercice1.cpp` par le fichier correspondant à l’exercice souhaité.

##  Conclusion

Ce TP permet de consolider les bases de la programmation orientée objet en C++, notamment la gestion des données partagées entre plusieurs objets et le suivi de leur cycle de vie à l’aide des constructeurs et des destructeurs.
