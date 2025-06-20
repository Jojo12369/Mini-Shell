/*
 * Mini Terminal utilisant SDL3
 * Crée une fenêtre contenant un terminal
 */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {

    SDL_Window *window = NULL; // Pointeur vers la fenêtre SDL

    // Initialise le sous-système vidéo de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    // Crée la fenêtre avec un titre et ses dimensions
    window = SDL_CreateWindow("MiniShell", 700, 450, 0);
    if (window == NULL) {
        SDL_Log("Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }

    SDL_SetWindowPosition(window, 50, 70); // Gère la position de ma fenêtre
    SDL_Delay(3000); // Ajoute un délai avant la fermeture de la fenêtre

    // Gère la fermeture de la fenêtre proprement
    SDL_DestroyWindow(window);

    // Gère le nettoyage des ressources et la fermeture propre de SDL
    Quit:
        SDL_Quit();
        return SDL_APP_SUCCESS;
}