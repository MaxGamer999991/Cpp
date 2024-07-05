#include <SDL2/SDL.h>

int main() {
  // SDL initialisieren
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Quit();
    return 1;
  }

  // Fenster erstellen
  SDL_Window *window = SDL_CreateWindow("Pixel manipulation", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

  if (window == nullptr) {
    SDL_Quit();
    return 1;
  }

  // Renderer erstellen
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

  if (renderer == nullptr) {
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Pixel mit RGB-Wert ändern
  int x = 100;
  int y = 100;
  Uint8 r = 255;
  Uint8 g = 0;
  Uint8 b = 0;

  SDL_SetRenderDrawColor(renderer, r, g, b);
  SDL_RenderDrawPoint(renderer, x, y);

  // Fenster aktualisieren
  SDL_RenderPresent(renderer);

  // Wartezeit, bis Benutzer eine Taste drückt
  SDL_Event event;
  while (true) {
    if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
      break;
    }
  }

  // Ressourcen freigeben
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
