# Librería Simplex

Librería desarrollada para resolver problemas de programación lineal para la materia de optimización en FIME.

## Uso de la librería

Instancia un objeto de la clase Simplex

 ``` c++
 Simplex *spx = new Simplex();
 ```
crea una matriz flotante con un tamaño MAX_FUNCIONES y MAX_VARIABLES y agrega los datos del tableau.

**Problema**
 ``` c++
    Z  X1  X2 S1 S2 S3  b
Z  1 -10 -20  0  0  0  0 
S1 0   4   2  1  0  0 20
S2 0   8   8  0  1  0 20
S3 0   0   2  0  0  1 10
```
**Código**
 ``` c++
float tableau[MAX_FUNCIONES][MAX_VARIABLES] = {
    {1, -10, -20, 0, 0, 0,  0},
    {0,   4,   2, 1, 0, 0, 20},
    {0,   8,   8, 0 ,1 ,0, 20},
    {0,   0,   2, 0, 0, 1, 10}
};
 ```
*Para cambiar el tamaño máximo de la matriz modifica los valores de los macros MAX_FUNCIONES Y MAX_VARIABLES en [simplex.h](https://github.com/Vipheak/PL-FIME/blob/master/simplex/simplex.h)
si no el default será de 255.*

Genera la tabla con el método generarTableau(numero_de_funciones, numero_de_variables, tableau)

``` c++
spx->generarTableau(3, 6, tableau2);
 ```
 *los valores dependen del tamaño de la matriz*
 
 Escoge si deseas maximizar o minimizar.
 ``` c++
spx->maximizar();
 ```
 **o**
 ``` c++
spx->minimizar();
 ```
 y muestra el resultado con el método verTableau
 ``` c++
spx->verTableau();
 ```

### Ejemplo del código
**[Click aquí](https://github.com/Vipheak/PL-FIME/blob/master/simplex/ejemplo.cpp)**
