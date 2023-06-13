#include <iostream>
#include <cmath>

double oblicz_asin(double x) {
    if (x >= -1 && x <= 1) {
        return asin(x);
    } else {
        throw std::invalid_argument("Nieprawidłowy argument. Wartość musi być między -1 a 1.");
    }
}

double oblicz_acos(double x) {
    if (x >= -1 && x <= 1) {
        return acos(x);
    } else {
        throw std::invalid_argument("Nieprawidłowy argument. Wartość musi być między -1 a 1.");
    }
}
