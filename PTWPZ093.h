#ifndef PTWPZ093_H
#define PTWPZ093_H

#include <iostream>
#include <string>
using namespace std;

/*
Treść zadania:

Zgodnie z definicją w Wikipedii

XML (ang. Extensible Markup Language, w wolnym tłumaczeniu Rozszerzalny Język Znaczników)
to uniwersalny język formalny przeznaczony do reprezentowania różnych danych w
ustrukturalizowany sposób. XML jest niezależny od platformy, co umożliwia łatwą wymianę
dokumentów pomiędzy różnymi systemami i znacząco przyczyniło się do popularności tego
języka w dobie Internetu. XML jest podzbiorem języka SGML, tj. każdy dokument XML jest
też dokumentem SGML. XML jest rekomendowany oraz specyfikowany przez organizację W3C.
XML jest jednym z najczęściej stosowanych formatów wymiany danych pomiędzy programami. Co
prawda jego tekstowa postać daje też człowiekowi możliwość przeczytania takiego dokumentu,
jednak jest to utrudnione przez brak odpowiedniego formatowania. Grupa studentów z Koła
Naukowego Studentów Wydziału Informatyki Politechniki Białostockiej postanowiła coś na to
poradzić i opracowała własny format o nazwie KWIX. Zasady przekształcania dokumentów z XML
na KWIX są następujące:

Nazwa każdego elementu jest wypisana w osobnej linii. Przed nazwą, w zależności od poziomu
zagłębienia, wypisywane są znaki spacji (po 4 spacje na każdy poziom). Po nazwie występuje
znak dwukropka.
Jeżeli element posiada atrybuty, to każdy z nich jest wypisywany w osobnej linii pod nazwą
elementu w kolejności zgodnej z kolejnością wystąpienia w dokumencie XML. Każdy atrybut
wypisywany jest według następującej formuły. Na początku wypisywane są znaki spacji: tyle
ile dla nazwy elementu plus 4 dodatkowe. Po tym następują kolejno: nazwa atrybutu, spacja,
znak równości, spacja i wartość atrybutu.
Po atrybutach wypisywane są elementy potomne, w kolejności wystąpienia w dokumencie XML
i zgodnie z regułami 1 i 2.
Ostatnia linia dokumentu KWIX jest zakończona znakiem nowej linii.
Prezentacja tekstu między elementami, komentarzy, przestrzeni nazw i innych nie wymienionych
powyżej składników języka XML jest przedmiotem dalszych prac i będzie ujęta w kolejnych
wersjach formatu KWIX.
Tobie jako świeżo upieczonemu członkowi Koła przypadł w udziale obowiązek i przyjemność
zaimplementowania tego, co wymyślili Twoi starsi koledzy i koleżanki. Napisz program, który
zamieni dokument XML na KWIX zgodnie ze specyfikacją.

Wejście
Dane podawane są na standardowe wejście. Stanowią one poprawny dokument XML. W dokumencie
tym nazwy elementów oraz nazwy i wartości atrybutów składają się wyłącznie z małych
i wielkich liter alfabetu łacińskiego oraz cyfr. Nie występują tu początkowe linie
z deklaracjami XML. Brak jest też komentarzy i tekstu. Między elementami występują jedynie
znaki spacji i nowej linii. Każdy element otwierający (nazwa i atrybuty) zaczyna się
i kończy w tej samej linii. Wartości atrybutów podawane są w cudzysłowach. Cały dokument
zawiera nie więcej niż 10 000 znaków.

Wyjście
Wynik programu powinien być wypisywany na standardowe wyjście. Jest nim dokument XML z wejścia
przekształcony do formatu KWIX.
 */

void printTabs(int numOfTabs) {
    for(int i = 0; i < numOfTabs; i++) {
        cout << "\t";
    }
}

void printAndCutWord(string& inputStr, int& letterInWord)
{
    cout << inputStr.substr(0, letterInWord);
    inputStr.erase(0, letterInWord);
    letterInWord = 0;
}

enum end_of_line_sign
{
    start_param = 0,
    end_of_param = 1,
    category = 2
};

void printEndOfLineSign(end_of_line_sign endOfLineSignIdx)
{
    const string endOfLineSings[] = { " = ", "\n", ":\n"};
    cout << endOfLineSings[endOfLineSignIdx];
}

void printCategory(string categoryStr, int& numOfTabs) {
    const char closeCategorySign = '/';
    bool isParamReaded = false;
    int letterInWordCounter = 0;

    while(!categoryStr.empty()) {
        if(isalnum(categoryStr[letterInWordCounter])) {
            letterInWordCounter++;
        }
        else if(0 < letterInWordCounter) {
            const char starParamSign = '=';
            if(categoryStr[letterInWordCounter] == starParamSign) {
                printTabs(numOfTabs);
                printAndCutWord(categoryStr, letterInWordCounter);
                printEndOfLineSign(end_of_line_sign::start_param);
                isParamReaded = true;
            }
            else if(isParamReaded) {
                printAndCutWord(categoryStr, letterInWordCounter);
                printEndOfLineSign(end_of_line_sign::end_of_param);
                isParamReaded = false;
            }
            else {
                printTabs(numOfTabs);
                printAndCutWord(categoryStr, letterInWordCounter);
                printEndOfLineSign(end_of_line_sign::category);
                numOfTabs++;
            }
        }
        else if(categoryStr[0] == closeCategorySign) {
            numOfTabs--;
            const char endOfCategorySign = '>';
            categoryStr.erase(0, categoryStr.find(endOfCategorySign));
        }
        else {
            categoryStr.erase(0, 1);
        }
    }
}

void PTWPZ093()
{
    string inputStrLine;
    int tabCounter = 0;
    while(cin >> inputStrLine)
    {
        printCategory(inputStrLine, tabCounter);
    }
}

#endif // PTWPZ093_H
