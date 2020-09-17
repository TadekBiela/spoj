#ifndef TMUL_H
#define TMUL_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

/*
Treść zadania:
Pomnóż dwie podane liczby.

Wejście
n [liczba par liczb, które trzeba pomnożyć ≤ 1000]
l1 l2 [liczby do pomnożenia, długości liczb ograniczone do 10000 cyfr]
Tekst w nawiasach [ ] nie występuje w pliku wejściowym.

Wyjście
Wynik mnożenia podanych liczb.
*/

vector<int> convertStrToVectorOfNumbers(string inputStr) {
    vector<int> resultVectorWithNumbers;
    for(char sign : inputStr) {
        resultVectorWithNumbers.push_back(atoi(&sign));
    }
    return resultVectorWithNumbers;
}

void multiplieVectorByValueAndAddToResultShiftedByOffset(
    const vector<int>& vector,
    int value,
    std::vector<int>& result,
    int plusShiftOffset
) {
    auto resultIt = result.rbegin();
    for(auto vectorIt = vector.rbegin();
        vectorIt != vector.rend();
        vectorIt++, resultIt++) {
        *(resultIt + plusShiftOffset) += ((*vectorIt) * value);
    }
}

void shiftNumbersInVectors(vector<int>& vectorWithNumbers) {
    for(auto valueIt = vectorWithNumbers.rbegin();
        valueIt != vectorWithNumbers.rend();
        valueIt++) {
        int numberOfUnity = *valueIt % 10;
        int numberOfTens = *valueIt / 10;
        *valueIt = numberOfUnity;
        if((valueIt + 1) != vectorWithNumbers.rend()) {
            *(valueIt + 1) += numberOfTens;
        }
        else if(0 < numberOfTens){
            vectorWithNumbers.insert(
                vectorWithNumbers.begin(),
                numberOfTens);
            break;
        }
    }
}

void multiplieVectorsOfNubmersIntoOneVector(
    const vector<int>& longerVector,
    const vector<int>& shorterVector,
    vector<int>& result
) {
    int plusShiftOffset = 0;
    for(auto shorterVectorIt = shorterVector.rbegin();
        shorterVectorIt != shorterVector.rend();
        shorterVectorIt++) {
        multiplieVectorByValueAndAddToResultShiftedByOffset(
             longerVector,
             *shorterVectorIt,
             result,
             plusShiftOffset);
        plusShiftOffset++;
    }
    shiftNumbersInVectors(result);
}

int TMUL() {
    int numOfInputData = 0;
    cin >> numOfInputData;
    while(numOfInputData--) {
        string inputStrWithNumbers;
        cin >> inputStrWithNumbers;
        vector<int> firstVectorOfNumbers = convertStrToVectorOfNumbers(inputStrWithNumbers);

        cin >> inputStrWithNumbers;
        vector<int> secondVectorOfNumbers = convertStrToVectorOfNumbers(inputStrWithNumbers);

        if(0 == firstVectorOfNumbers.at(0) ||
           0 == secondVectorOfNumbers.at(0)) {
            cout << "0\n";
            continue;
        }
        vector<int> reslutMultipliesNumbers((firstVectorOfNumbers.size() + secondVectorOfNumbers.size()), 0);
        if(firstVectorOfNumbers.size() < secondVectorOfNumbers.size()) {
            multiplieVectorsOfNubmersIntoOneVector(
                secondVectorOfNumbers,
                firstVectorOfNumbers,
                reslutMultipliesNumbers);
        }
        else {
            multiplieVectorsOfNubmersIntoOneVector(
                firstVectorOfNumbers,
                secondVectorOfNumbers,
                reslutMultipliesNumbers);
        }

        while(0 == reslutMultipliesNumbers.at(0))
        {
            reslutMultipliesNumbers.erase(reslutMultipliesNumbers.begin());
        }

        for(auto number : reslutMultipliesNumbers) {
            cout << number;
        }
        cout << endl;
    }
    return 0;
}

#endif // TMUL_H
