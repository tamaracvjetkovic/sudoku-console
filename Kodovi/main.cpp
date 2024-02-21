
/* file: main.cpp
   desc: Main function of the program
   author: Tamara Cvjetkovic
   date: 04.01.2024. */

#include <iostream>
#include <string>
#include <random>

#include "Sudoku.h"
#include "TestSudoku.h"
#include "App.h"

using namespace std;

int Sudoku::gamesPlayedCnt = 0;


int main(int argc, char** argv) {
    
    //TestSudoku test;

    App app(argv[1], argv[2]);

    return 0;
}
