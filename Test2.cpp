#include <ncurses.h>

int main() {
  // ncurses initialisieren
  initscr();
  cbreak();
  noecho();

  // Startposition festlegen
  int x = 10;
  int y = 10;

  // Quadrat zeichnen
  attron(A_COLOR);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      mvprintw(y + i, x + j, " ");
    }
  }

  attroff(COLOR_PAIR(1));
  attroff(A_COLOR);

  // Zeichen aktualisieren
  refresh();

  // Wartezeit, bis Benutzer eine Taste drückt
  getch();

  // ncurses beenden
  endwin();

  return 0;
}
