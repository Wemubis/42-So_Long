# ft_so_long

Ce projet a été réalisé dans le cadre du cursus à l'école 42. L'objectif est de créer un jeu graphique en utilisant la bibliothèque mlx, qui permet de manipuler des images, de gérer les événements de la souris et du clavier, et d'afficher des éléments graphiques.

<br>

## Description

ft_so_long est un jeu simple inspiré du classique jeu vidéo "Sokoban". Le joueur contrôle un personnage qui doit collecter des objets sur la carte tout en évitant les obstacles. Le jeu se termine lorsque tous les objets ont été collectés, et le joueur doit atteindre la sortie pour gagner.

<br>

## Fonctionnalités

- Affichage d'une carte graphique en utilisant la mlx.
- Gestion des mouvements du joueur à l'aide des touches du clavier.
- Collecte d'objets sur la carte.
- Gestion des collisions avec les obstacles.
- Affichage du nombre d'objets collectés et de l'état actuel du joueur.

<br>

## Utilisation

1. Clonez ce dépôt :
```bash
  git clone https://github.com/Wemubis/so_long.git
```

3. Compilez le projet :
```bash
  make
```

5. Exécutez le jeu avec une carte spécifique :
```bash
  ./so_long maps/map.ber
```

7. Ressources :
- [MinilibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [Sokoban](https://fr.wikipedia.org/wiki/Sokoban)
