#include <iostream>
#include <vector>

// Funkcja do wyświetlania macierzy
void wyswietlMacierz(const std::vector<std::vector<double>>& macierz) {
    int n = macierz.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << macierz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Funkcja do obliczania macierzy jednostkowej
std::vector<std::vector<double>> macierzJednostkowa(int n) {
    std::vector<std::vector<double>> macierz(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        macierz[i][i] = 1.0;
    }
    return macierz;
}

// Funkcja do obliczania macierzy odwrotnej
std::vector<std::vector<double>> obliczOdwrotnoscMacierzy(const std::vector<std::vector<double>>& macierz) {
    int n = macierz.size();

    // Tworzenie macierzy jednostkowej
    std::vector<std::vector<double>> macierzJednostkowa = macierzJednostkowa(n);

    // Tworzenie macierzy roboczej z kopią wejściowej macierzy
    std::vector<std::vector<double>> macierzRobocza = macierz;

    // Iteracyjne eliminowanie Gaussa-Jordana
    for (int k = 0; k < n; ++k) {
        // Pivoting
        double maxElement = std::abs(macierzRobocza[k][k]);
        int maxRow = k;
        for (int i = k + 1; i < n; ++i) {
            if (std::abs(macierzRobocza[i][k]) > maxElement) {
                maxElement = std::abs(macierzRobocza[i][k]);
                maxRow = i;
            }
        }
        std::swap(macierzRobocza[k], macierzRobocza[maxRow]);
        std::swap(macierzJednostkowa[k], macierzJednostkowa[maxRow]);

        // Skalowanie wiersza głównego
        double pivot = macierzRobocza[k][k];
        for (int j = 0; j < n; ++j) {
            macierzRobocza[k][j] /= pivot;
            macierzJednostkowa[k][j] /= pivot;
        }

        // Eliminacja Gaussa-Jordana
        for (int i = 0; i < n; ++i) {
            if (i != k) {
                double factor = macierzRobocza[i][k];
                for (int j = 0; j < n; ++j) {
                    macierzRobocza[i][j] -= factor * macierzRobocza[k][j];
                    macierzJednostkowa[i][j] -= factor * macierzJednostkowa[k][j];
                }
            }
        }
    }

    return macierzJednostkowa;
}