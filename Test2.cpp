#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  // Werte für x und Helligkeit berechnen
  vector<double> x_values;
  vector<double> brightness_values;

  for (double x = 0; x <= 10; x += 0.1) {
    double brightness = x;

    x_values.push_back(x);
    brightness_values.push_back(brightness);
  }

  // Daten in eine Datei schreiben
  ofstream data_file("brightness.dat");

  if (data_file.is_open()) {
    for (int i = 0; i < x_values.size(); i++) {
      data_file << x_values[i] << " " << brightness_values[i] << endl;
    }

    data_file.close();
  } else {
    cerr << "Fehler beim Öffnen der Datei" << endl;
    return 1;
  }

  // Gnuplot-Skript erstellen und ausführen
  string gnuplot_script = "plot 'brightness.dat' with lines";

  system(gnuplot_script.c_str());

  return 0;
}
