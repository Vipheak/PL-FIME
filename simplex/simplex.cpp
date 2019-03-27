#include "simplex.h"

Simplex::Simplex() { /* ... */ }

void Simplex::generarTableau(int nFunciones, int nVariables, float (*tableau)[MAX_VARIABLES]) {
    this->nFunciones = nFunciones;
    this->nVariables = nVariables;

    for(int i = 0; i<this->nFunciones; i++) {
        for(int j = 0; j<this->nVariables; j++) {
            this->tableau[i][j] = tableau[i][j];
        }
    }

    //this->verTableau(); cout << endl; //debug
}

void Simplex::obtenCPivote() {
    float nMenor = this->tableau[0][0];

    for(int i = 0; i<this->nVariables; i++) {
        if(this->tableau[0][i] < nMenor) {
            nMenor = this->tableau[0][i];
            this->cPivote = i;
        }
    }

    //cout << this->cPivote << " " << nMenor << endl; //debug
}

void Simplex::obtenFPivote() {
    float nMenor = this->tableau[1][this->nVariables-1] / this->tableau[1][this->cPivote];
    this->fPivote = 1;

    for(int i = 1; i<this->nFunciones; i++) {
        if(this->tableau[i][this->nVariables-1] / this->tableau[i][this->cPivote] < nMenor) {
            nMenor = this->tableau[i][this->nVariables-1] / this->tableau[i][this->cPivote];
            this->fPivote = i;
        }
    }

    //cout << this->fPivote << " " << nMenor << endl; //debug
}

void Simplex::obtenEPivote() {
    this->ePivote = tableau[this->fPivote][this->cPivote];
    //cout << this->ePivote << endl; //debug
}

void Simplex::actualizarTableau() {
    for(int i=0; i<this->nVariables; i++) {
        this->tableau[this->fPivote][i] /= this->ePivote;
        //cout << this->tableau[this->fPivote][i] << endl; //debug
    }

    for(int i=0; i<this->nFunciones; i++) {
        if(i == this->fPivote) { i++; }
        float coeficiente = this->tableau[i][this->cPivote];
        //cout << endl << coeficiente << endl; //debug

        for(int j=0; j<this->nVariables; j++) {
            //cout << this->tableau[i][j] << " - (" << coeficiente << " * " << this->tableau[this->fPivote][j] << ")" << endl; //debug
            this->tableau[i][j] -= coeficiente * this->tableau[this->fPivote][j];
        }
    }

    //this->verTableau(); //debug
}

bool Simplex::estaResuelto() {
    bool resuelto = true;

    for(int i=0; i<this->nVariables; i++) {
        if(this->tableau[0][i] >= 0) { resuelto &= true; }
        else { resuelto &= false; }
    }

    return resuelto;
}

void Simplex::maximizar() {
    while(!this->estaResuelto()) {
        this->obtenCPivote();
        this->obtenFPivote();
        this->obtenEPivote();
        this->actualizarTableau();
        //this->verTableau(); // debug
    }
}

void Simplex::minimizar() {
    for(int i=0; i<this->nVariables; i++) { this->tableau[0][i] *= -1; }

    while(!this->estaResuelto()) {
        this->obtenCPivote();
        this->obtenFPivote();
        this->obtenEPivote();
        this->actualizarTableau();
        //this->verTableau(); // debug
    }
}

void Simplex::verTableau() {
    for(int i = 0; i<this->nFunciones; i++) {
        for(int j = 0; j<this->nVariables; j++) {
            cout << this->tableau[i][j] << " ";
        }   cout << endl;
    }
}

Simplex::~Simplex() { /* ... */ }
