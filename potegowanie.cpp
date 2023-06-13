#include <iostream>

//Funckja potegowania
float potega(float liczba, float wykladnik){
    float wynik = liczba;
    for(int i = 0; i < wykladnik; i++){
        wynik = wynik * liczba;
    }
    return wynik
}