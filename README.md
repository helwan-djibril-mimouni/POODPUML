# Tower Defense

## Description

Ce projet est un jeu de Tower Defense développé en C++ en utilisant la bibliothèque Raylib. Le but du jeu est de défendre votre base en plaçant des tours le long du chemin des ennemis. Les ennemis essaieront d'atteindre votre base, et vos tours les attaqueront automatiquement lorsqu'ils sont à portée.

## Installation

1. Clonez ce dépôt sur votre machine locale :
   ```sh
   git clone https://github.com/votre-utilisateur/tower-defense.git
2. Assurez-vous d'avoir Raylib installé. Vous pouvez télécharger Raylib depuis le site officiel et suivez les instructions d'installation.

3. Placez les fichiers d'en-tête de Raylib dans le dossier include et les fichiers de bibliothèque dans le dossier lib.

## Compilation

Pour compiler le projet, utilisez la commande suivante :

    g++ .\main.cpp -I .\include\ -L .\lib\ -lraylib -lopengl32 -lgdi32 -lwinmm

Cette commande inclut les fichiers d'en-tête de Raylib depuis le dossier include et lie les bibliothèques depuis le dossier lib.

## Utilisation

Après avoir compilé le projet, exécutez le fichier exécutable généré pour démarrer le jeu. Utilisez votre souris et votre clavier pour interagir avec le jeu et placer vos tours stratégiquement pour empêcher les ennemis d'atteindre votre base.

## Structure du Projet

Le projet est structuré de la manière suivante :

/tower-defense
├── include/           # Dossier pour les fichiers d'en-tête (headers) de Raylib
├── lib/               # Dossier pour les bibliothèques compilées de Raylib
├── src/               # Dossier pour les fichiers source additionnels
├── assets/            # Dossier pour les ressources du jeu (images, sons, etc.)
├── main.cpp           # Fichier source principal
├── README.md          # Ce fichier
├── .gitignore         # Fichier gitignore