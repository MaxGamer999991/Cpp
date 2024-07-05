#include <SDL2/SDL.h>

int main() {
  // Initialisiere SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Fehler beim Initialisieren von SDL: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Erstelle ein Fenster
  SDL_Window* window = SDL_CreateWindow("Mein Spiel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cerr << "Fehler beim Erstellen des Fensters: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  // Erstelle einen Renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    std::cerr << "Fehler beim Erstellen des Renderers: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Haupt-Schleife
  bool running = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          running = false;
          break;
        default:
          break;
      }
    }

    // Zeichne etwas auf den Bildschirm
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_Rect rect = {100, 100, 200, 200};
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
  }

  // Gebe die Ressourcen frei
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
