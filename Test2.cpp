#include <ncurses.h>

int main() {
  // ncurses initialisieren
  initscr();
  cbreak(); // Tastendruck ohne Enter interpretieren
  noecho(); // Eingaben nicht auf dem Bildschirm anzeigen

  // Startposition festlegen
  int x = 10;
  int y = 10;

  // Text ausgeben
  mvprintw(y, x, "Hallo Welt!");

  // Terminal aktualisieren
  refresh();

  // Wartezeit, bis Benutzer eine Taste drückt
  getch();

  // ncurses beenden
  endwin();

  return 0;
}
