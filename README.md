# Mini Shell

Une petite console qui exécute des fonctions de bases.

## 📌 Description



## 🚀 Fonctionnalités

-

## 🛠️ Technologies utilisées

- **Language** : C
- **Compilation** : GCC ou autre compilateur C compatible
- **Exécution** : MSYS2 avec GKT4

## 📥 Installation et Compilation

1. **Cloner le dépôt** :

```sh
git clone https://github.com/Jojo12369/Mini-Shell.git
```

2. **Compiler le programme** :

```sh
gcc main.c source/window.c source/style.c source/message_start.c source/terminal.c source/style.c `pkg-config --cflags --libs gtk4` -o minishell

# ou

make
```

3. **Lancer le jeu** :

```sh
./minishell

# ou

make run
```

## 🎮 Comment l'utiliser ?

1. **Lancer le programme** dans un terminal MSYS2 ucrt64 avec GKT4.
2. **Permet d'exécuter** des commandes de bases.

## 📂 Structure du projet

```plaintext
📦 Mini Shell
 ┣ 📜 minishell.c      # Code source de l'application
 ┣ 📜 README.md        # Documentation
 ┗ 📜 .gitignore       # Fichiers à ignorer par Git
```

## 📝 Améliorations futures

- Pas d'amélioration à apporter pour le moment

## 🤝 Contribution

Toute suggestion ou amélioration est la bienvenue ! Ouvrez une issue ou proposez une pull request.