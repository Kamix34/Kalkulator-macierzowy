#include <iostream>
#include <vector>

// Funkcja do wyświetlania macierzy
void wyswietlMacierz(const std::vector<std::vector<double>>& macierz) {
    int n = macierz.size();
    int m = macierz[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << macierz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Funkcja do mnożenia macierzy przez stałą
std::vector<std::vector<double>> pomnozMacierzPrzezStala(const std::vector<std::vector<double>>& macierz, double stala) {
    int n = macierz.size();
    int m = macierz[0].size();
    std::vector<std::vector<double>> wynik(n, std::vector<double>(m, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            wynik[i][j] = macierz[i][j] * stala;
        }
    }
    return wynik;
}

// Funkcja do mnożenia macierzy przez siebie
std::vector<std::vector<double>> pomnozMacierze(const std::vector<std::vector<double>>& macierz1, const std::vector<std::vector<double>>& macierz2) {
    int n1 = macierz1.size();
    int m1 = macierz1[0].size();
    int n2 = macierz2.size();
    int m2 = macierz2[0].size();

    if (m1 != n2) {
        throw std::invalid_argument("Nieprawidłowe wymiary macierzy.");
    }

    std::vector<std::vector<double>> wynik(n1, std::vector<double>(m2, 0.0));
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m2; ++j) {
            for (int k = 0; k < m1; ++k) {
                wynik[i][j] += macierz1[i][k] * macierz2[k][j];
            }
        }
    }
    return wynik;
}
