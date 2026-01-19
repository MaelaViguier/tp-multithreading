# Comparaison des performances Python vs C++

Ce projet illustre la résolution de systèmes linéaires `Ax = B` avec Python et C++, en comparant les temps de calcul pour la même tâche.

## Description

- **Python** : utilisation de Numpy pour générer les matrices et résoudre les systèmes. Les tâches sont gérées par un `Boss` et des `Minions` via un serveur `Manager`.
- **C++** : utilisation d’Eigen pour résoudre le même système récupéré via un proxy HTTP.

Chaque tâche consiste à résoudre un système linéaire de taille **200x200**.

## Temps de calcul observés

- **C++** : `Temps de calcul C++ : 0.00408851 s`
- **Python** : `[Boss] Résultat tâche 5 en 0.0017s`

Remarque : les temps sont mesurés pour la même tâche (tâche 5) et peuvent varier légèrement selon la machine.

## Conclusion

Cette comparaison montre que pour cette tâche spécifique, Python et C++ ont des performances comparables sur la matrice de taille 200x200, bien que C++ soit généralement plus performant pour des systèmes plus grands.
