double obliczWyznacznik() {
    if (rozmiar == 1) {
            return macierz[0][0];
        } else {
            double wyznacznik = 0;
            int znak = 1;
            for (int k = 0; k < rozmiar; k++) {
                std::vector<std::vector<double>> podmacierz(rozmiar - 1, std::vector<double>(rozmiar - 1));
                for (int i = 1; i < rozmiar; i++) {
                    int j1 = 0;
                    for (int j = 0; j < rozmiar; j++) {
                        if (j == k)  
                            continue;
                        podmacierz[i - 1][j1] = macierz[i][j];
                        j1++;
                    }
                }
                wyznacznik += znak * macierz[0][k] * Macierz(podmacierz).obliczWyznacznik();
                znak = -znak;
            }
            return wyznacznik;
        }
    }
