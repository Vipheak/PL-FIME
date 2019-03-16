#include "simplex.h"

Simplex::Simplex() { /* ... */ }

void Simplex::setVariables(int variables) {
    this->variables = variables;
}

void Simplex::setMin(int min) {
    this->min = min;
}

int Simplex::getVariables() {
    return this->variables;
}

int Simplex::getMin() {
    return this->min;
}

void Simplex::setA() {
    int variables;
    cout << "Cuantas variables son: "; cin >> variables;
    variables = variables+variables+2;

    int restricciones;
    cout << "Restricciones son: "; cin >> restricciones;
    restricciones = restricciones+1;

    cout << "Dimensiones de tu matriz: A [" << restricciones << "][" << variables <<"]" << endl;
    cout << endl;

    //this->A = new double[restricciones][variables];

    for(int i = 0; i < restricciones; i++) {
        for(int j = 0; j < variables; j++) {
            cout << "Valor de elemento X" << i << "" << j << " : "; cin >> this->A[i][j];

            if(this->A[i][j] >= 0 && this->A[i][j] < 10) {
                cout << "\t" << this->A[i][j] << "\t" << "\t" << "|";
            } else {
                cout << "\t" << this->A[i][j] << "\t" << "|";
            }
        }

        cout << endl;
    }
}

void Simplex::imprimirMatriz(double matriz[FUNCIONES][VARIABLES]) {
    int siONo;
    cout << "Deseas imprimir la matriz? 1 = Si"; cin >> siONo;

    if(siONo == 1) {
        cout << "Matriz A =" << endl;
        cout << endl;

        for(int i = 0; i < FUNCIONES; i++) {
            for(int j = 0; j < VARIABLES; j++) {
                if(matriz[i][j] >= 0 && matriz[i][j] < 10) {
                    cout << "\t" << matriz[i][j] << "\t" << "\t" << "|";
                } else {
                    cout << "\t" << matriz[i][j] << "\t" << "|";
                }
            }

            cout << endl;
        }
    }
}

void Simplex::setJ(double matriz[FUNCIONES][VARIABLES]) {
    int siONo;
    cout << "Ubicar columna pivote... 1 = Si"; cin >> siONo;

    if(siONo == 1) {
        //double elementoMasNegativo = Double.MAX_VALUE; NO EXISTE

        /*for(int j =1; j < VARIABLES; j++) { // USA LA VARIABLE elementoMasNegativo
            if(matriz[0][j] != 0) {
                if(elementoMasNegativo > matriz[0][j]) {
                    elementoMasNegativo = matriz[0][j];
                    this->J = j;
                }
            }
        }*/
    }
}

void Simplex::setI() {
    int siONo;
    cout << "Ubicar fila pivote... 1 = Si"; cin >> siONo;

    if(siONo == 1) {
        //double elementomenor = Double.MAX_VALUE; NO EXISTE

        for(int i = 1; i < FUNCIONES; i++) {
            for(int j = this->J; j <= VARIABLES; j++) {
                if(j == this->J) {
                    /*if(elementomenor > this->B[i][(VARIABLES) - 1] / (this.B[i][j])) { // USA LA VARIABLE elementomenor
                        elementomenor = this->B[i][VARIABLES) - 1] / (this.B[i][j]);
                        this->I = i;*/
                }
            }
        }

        cout << endl;
    }
}

void Simplex::paso1() {
    int siONo;
    cout << "Multiplicamos la fila I por el valor inverso del elemento pivote? 1 = Si"; cin >> siONo;

    if(siONo == 1) {
        double elementoPivote = this->B[this->I][this->J];
        for(int j = 0; j < VARIABLES; j++) {
            this->B[this->I][j] = ((this->B[this->I][j]) * (1 / elementoPivote));
        }
    }
}

void Simplex::paso2() {
    int siONo;
    cout << "Restamos la fila I multiplicada por factor de cada fila, para hacer 0 los elementos superiores e inferiores 1 = Si"; cin >> siONo;

    if(siONo == 1) {
        for(int i = 0; i < VARIABLES; i++) {
            double elemento = this->B[i][this->J];
            if(i != this->I) {
                for(int j = 0; j < VARIABLES; j++) {
                    this->B[i][j] += (this->B[this->I][j]) * ((elemento) * -1);
                }
            }
        }
    }
}

Simplex::~Simplex() { /* ... */ }
