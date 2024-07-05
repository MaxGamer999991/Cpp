#include <ncurses.h>

int main() {
  // ncurses initialisieren
  initscr();
  cbreak();
  noecho();

  // Startposition und Ballposition festlegen
  int x = 10, y = 10;
  int ball_x = 20, ball_y = 10;

  while (true) {
    // Terminal löschen
    clear();

    // Ball zeichnen
    mvprintw(ball_y, ball_x, "O");

    // Spielerposition mit Pfeiltasten steuern
    int c = getch();
    switch (c) {
      case KEY_LEFT:
        if (x > 0) x--;
        break;
      case KEY_RIGHT:
        if (x < COLS - 1) x++;
        break;
      case KEY_UP:
        if (y > 0) y--;
        break;
      case KEY_DOWN:
        if (y < LINES - 1) y++;
        break;
      case 'q':
        goto end; // Schleife beenden
    }

    // Spieler
