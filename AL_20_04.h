#ifndef AL_20_04_H
#define AL_20_04_H

#include <iostream>
#include <vector>
using namespace std;

/*
Treść zadania:

AL_20_04 - Miara profesora Algobita
Wielkimi krokami zbliża się Nowy Rok 2015. Profesor Algoblit właśnie przygotowuje nowe
zadanie zaliczeniowe dla swoich studentów, które zada na koniec pierszego semestru. Nie
mając pomysłu wybrał się do swojego ulubionego chińskiego sklepu po miarkę do mierzenia.
Okazało się, że podziałka miarki nie była pełna. Zaznaczone zostały tylko niektóre
odległości od jej początku. Każdy zwykły klient byłby bardzo niezadowolony z tego faktu,
ale nie profesor. Był on wręcz wniebowzięty. Długość miarki jaką zakupił oraz rozkład
podziałki pozwala na wymierzenie każdej długości całkowitej nie dłuższej niż jej długość,
wykonując nie więcej niż jedno mierzenie. I w ten sposób narodził się pomysł na zadanie
dla studentów. Czy dla danej długości miarki o długości d, definiując rozkład jej podziału
(są to liczby całkowite) można wymierzyć każdą długość całkowitą z przedziału [1..d]
wykonując tylko jedno mierzenie.

Wejście
Nieokreślona niewielka liczba zestawów danych.

Każdy zestaw składa się z dwóch wierszy. W pierwszym wierszu dwie liczby d i n
(1 ≤ d ≤ 103 oraz 0 ≤ n < d) określające odpowiednio długość miarki oraz liczbę podziałek miarki.

W drugim wierszu n posortowanych rosnąco liczb całkowitych zawierających się w przedziale [1..d-1].

Wyjście
Dla każdego zestawu danych napis Tak, jeśli można odmierzyć każdą możliwą długość
z przedziału [1..d], lub Nie w przeciwnym razie.

*/

/*Procedura sprawdza czy dana miarka z podaną podziałką jest w stanie zmierzyć
  wszystkie odległości, mierząc tylko raz
*/
void validMeasure(const int measureSize, vector<int>& measureScale) {
    measureScale.insert(measureScale.begin(), 0);
    measureScale.push_back(measureSize);

    vector<int> measureScaleDistances(measureSize, 0);

    //Obliczamy odległość między punktami podziałki na miarce
    for(auto scaleValue = measureScale.begin();
        scaleValue != measureScale.end();
        scaleValue++) {
        for(auto scaleNextValue = (scaleValue + 1);
            scaleNextValue != measureScale.end();
            scaleNextValue++) {
            int scaleDistance = *scaleNextValue - *scaleValue;
            measureScaleDistances[scaleDistance - 1] = 1;
        }
    }

    int numOfMeasureScaleDistances = 0;
    for(auto item : measureScaleDistances)
    {
        numOfMeasureScaleDistances += item;
    }

    if(numOfMeasureScaleDistances == measureSize) {
        cout << "Tak\n";
    }
    else {
        cout << "Nie\n";
    }
}

void AL_20_04()
{
    int measureSize = 0;
    while(cin >> measureSize) {
        int numOfMeasureScaleItems = 0;
        cin >> numOfMeasureScaleItems;

        vector<int> measureScale;
        int scaleItemValue = 0;
        for(int scaleItem = 0; scaleItem < numOfMeasureScaleItems; scaleItem++) {
            cin >> scaleItemValue;
            measureScale.push_back(scaleItemValue);
        }

        validMeasure(measureSize, measureScale);
    }
}

#endif // AL_20_04_H
