#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <iostream>

using namespace std;

#define MAX_FUNCIONES 255
#define MAX_VARIABLES 255

class Simplex {
    private:
        int nFunciones;
        int nVariables;
        float tableau[MAX_FUNCIONES][MAX_VARIABLES];

        int cPivote;
        int fPivote;
        float ePivote;

        void obtenCPivote();
        void obtenFPivote();
        void obtenEPivote();

        void actualizarTableau();
        bool estaResuelto();

    public:
        Simplex();

        void generarTableau(int nFunciones, int nVariables, float (*tableau)[MAX_VARIABLES]);
        void maximizar();
        void minimizar();

        void verTableau(); // Funcion de Debug

        ~Simplex();
};

#endif // SIMPLEX_H
