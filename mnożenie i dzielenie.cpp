// funkcja mnożenia 2 liczb
double mnozenie(double a, double b) {
    return a * b;
}

// Funkcja dzielenia dwóch liczb
double dzielenie(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "Nie mozna dzielic przez zero!" << std::endl;
        return 0;
    }
}
