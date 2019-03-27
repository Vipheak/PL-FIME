#include <iostream>
#include <cstdlib>
#include "simplex.h"

using namespace std;

int main() {
    Simplex *spx = new Simplex();

    // PROBLEMA 1

    float tableau[MAX_FUNCIONES][MAX_VARIABLES] = {
        {1, -10, -20, 0, 0, 0,  0},
        {0,   4,   2, 1, 0, 0, 20},
        {0,   8,   8, 0 ,1 ,0, 20},
        {0,   0,   2, 0, 0, 1, 10}
    };

    spx->generarTableau(4, 7, tableau);
    spx->maximizar();
    spx->verTableau();

    // PROBLEMA 2

    cout << endl;

    float tableau2[MAX_FUNCIONES][MAX_VARIABLES] = {
        {1, -50, -80, 0, 0,   0},
        {0,   1,   2, 1, 0, 120},
        {0,   1,   1, 0, 1,  90}
    };

    spx->generarTableau(3, 6, tableau2);
    spx->maximizar();
    spx->verTableau();

    return 0;
}
