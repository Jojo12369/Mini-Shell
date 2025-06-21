/*
 * Mini Terminal utilisant SDL3
 * Crée une fenêtre contenant un terminal
 */

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

int main(int argc, char* argv[]) {

    SDL_Window *window = NULL; // Pointeur vers la fenêtre SDL
    SDL_Renderer *renderer = NULL; // Pointeur vers le renderer SDL
    TTF_Font *police = NULL; // Pointeur vers la police
    SDL_Surface *texteSurface = NULL; // Pointeur vers la surface du texte
    SDL_Texture *texteTexture = NULL; // Pointure vers la texture du texte

    // Couleur du texte (blanc)
    SDL_Color color = {255, 255, 255, 255};

    int status = SDL_APP_FAILURE;

    // Initialise le sous-système vidéo de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    // Initialise SDL3_ttf
    if (TTF_Init() < 0) {
        SDL_Log("Erreur TTF_Init : %s", SDL_GetError());
        goto Quit;
    }

    // Crée la fenêtre avec un titre et ses dimensions
    window = SDL_CreateWindow("MiniShell", 700, 450, 0);
    if (window == NULL) {
        SDL_Log("Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }

    // Crée un rendu pour ma fenêtre
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        SDL_Log("Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }

    // Initialisation de la poclice
    police = TTF_OpenFont("SourceCodePro.ttf", 14);
    if (police == NULL) {
        SDL_Log("Erreur TTF_OpentFont : %s", SDL_GetError());
        goto Quit;
    }

    // Crée une surface pour le texte
    const char* texte = "Hello World";
    texteSurface = TTF_RenderText_Blended(police, texte, strlen(texte), color);
    if (texteSurface == NULL) {
        SDL_Log("Erreur TTF_RenderText_Blended : %s", SDL_GetError());
        goto Quit;
    }

    // Crée une texture à partir de la surface
    texteTexture = SDL_CreateTextureFromSurface(renderer, texteSurface);
    if (texteTexture == NULL) {
        SDL_Log("Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        goto Quit;
    }

    // Récupère la taille du texte
    SDL_FRect dstRect = {50, 50, texteSurface->w, texteSurface->h};

    // Affichage
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // fond noir
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texteTexture, NULL, &dstRect);
    SDL_RenderPresent(renderer);

    SDL_SetWindowPosition(window, 50, 70); // Gère la position de ma fenêtre
    SDL_Delay(3000); // Ajoute un délai avant la fermeture de la fenêtre

    status = SDL_APP_SUCCESS;

    // Gère le nettoyage des ressources et la fermeture propre de SDL
Quit:
    if (texteTexture != NULL) SDL_DestroyTexture(texteTexture);
    if (texteSurface != NULL) SDL_DestroySurface(texteSurface);
    if (police != NULL) TTF_CloseFont(police);
    if (renderer != NULL) SDL_DestroyRenderer(renderer);
    if (window != NULL) SDL_DestroyWindow(window);
    SDL_Quit();
    return status;
}