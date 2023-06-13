#include <iostream>
#include <vector>

// Funkcja pomocnicza do wyĹwietlania macierzy
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// Funkcja do obliczania wyznacznika macierzy
int calculateDeterminant(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int determinant = 0;

    // ObsĹuga macierzy 1x1
    if (n == 1) {
        return matrix[0][0];
    }

    // ObsĹuga macierzy 2x2
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    // Eliminacja Gaussa
    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> subMatrix(n - 1, std::vector<int>(n - 1, 0));
        for (int j = 1; j < n; j++) {
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l == i) {
                    continue;
                }
                subMatrix[j - 1][k] = matrix[j][l];
                k++;
            }
        }
        determinant += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * calculateDeterminant(subMatrix);
    }

    return determinant;
}