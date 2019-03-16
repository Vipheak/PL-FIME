#include <simplex.h>

using namespace std;

int main()
{
    Simplex *S = new Simplex();

    int Svariables;
    cout << "Cuantas variables son: "; cin >> Svariables;
    S->setVariables(Svariables);

    int Smin;
    cout << "Es minimizacion? 1.- si "; cin >> Smin;
    S->setMin(Smin);

    /*if(S->getMin() == 1) { // NECESITA CREARSE UN METODO
        for(int j = 1; j < (VARIABLES-(S->getVariables()+1)); j++) {
            S->B[0][j] = (S.B[0][j])*-1;
        }
    }*/

    /**************************************************************************
     *  Se necesitan crear metodos o una matriz en main para suplantar o usar *
     *  La propiedad B de de la clase Simplex.                                *
     **************************************************************************/

    /*
    S->imprimirMatriz(S.B);

    for(int vuelta = 1; vuelta <= S.variables; vuelta++ ) {
        S.setJ(S.B); // Ubicamos la columna pivote (J)

        System.out.println("Ubicamos la columna pivote (J)");
        System.out.println("J = "+S.J);

        S.setI(); // Ubicamos la fila pivote (I)
        System.out.println("Ubicamos la fila pivote (I) haciendo las pruebas de cociente ");
        System.out.println("I = "+S.I);

        System.out.println("\n"+"Elemento pivote = A["+S.I+"]["+S.J+"] = "+S.B[S.I][S.J]); // Imprimimos el indice del elemento pivote y su valor.

        S.paso1(); // Muliplicamos el renglon pivote por 1/elemento pivote.

        S.imprimirMatriz(S.B);

        S.paso2(); // Recorremos la matriz, si el renglon actual no es el renglon I, entonces a cada elemento A[i][j] se le suma (A[I][j] * (A[i][J])*(-1))

        S.imprimirMatriz(S.B);
    }*/

    return 0;
}
