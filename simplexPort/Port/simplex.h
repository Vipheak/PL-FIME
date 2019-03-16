#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <iostream>

#define FUNCIONES 4
#define VARIABLES 7

using namespace std;

class Simplex
{
    //Algoritmo basado en maximizacion

    private:
        double A[FUNCIONES][VARIABLES];
        double B[FUNCIONES][VARIABLES]; //Matriz
        int J; // Columna pivote
        int I; // Fila pivote
        int variables; // Cantidad de variables
        int min;
    public:
        Simplex();

        void setVariables(int variables);
        int getVariables();
        int getMin();
        void setMin(int min);
        void setA();
        void imprimirMatriz(double matriz[FUNCIONES][VARIABLES]);
        void setJ(double matriz[FUNCIONES][VARIABLES]);
        void setI();
        void paso1();
        void paso2();

        ~Simplex();
};

#endif // SIMPLEX_H
