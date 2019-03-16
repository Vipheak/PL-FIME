import javax.swing.*;

public class Simplex2
{
    //Algoritmo basado en maximizacion

    private double A[][];
    private double B[][] = {{1,-30,-100,0,0,0,0},{0,1,1,1,0,0,7},{0,4,10,0,1,0,40},{0,10,0,0,0,-1,30}}; //Matriz
    private int J; // Columna pivote
    private int I; // Fila pivote
    private int variables; // Cantidad de variables
    private int min;

    public static void main(String[] args)
    {
        Simplex2 S = new Simplex2();

        S.variables = Integer.parseInt(JOptionPane.showInputDialog("Cuantas variables son: "));
        S.min = Integer.parseInt(JOptionPane.showInputDialog("Es minimizacion? 1.- si "));

        if(S.min == 1)
        {
            for (int j = 1; j < (S.B[0].length-(S.variables+1));j++)
            {
                S.B[0][j] = (S.B[0][j])*-1;
            }
        }

        S.imprimirMatriz(S.B);
        for(int vuelta = 1; vuelta <= S.variables; vuelta++ )
        {
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
        }
    }

    private void setA()
    {

        int variables = Integer.parseInt(JOptionPane.showInputDialog("Cuantas variables son: "));
        variables = variables+variables+2;


        int restricciones = Integer.parseInt(JOptionPane.showInputDialog("Restricciones son: "));
        restricciones = restricciones+1;


        System.out.println("Dimensiones de tu matriz: A ["+restricciones+"]["+variables+"]");
        System.out.println();

        this.A= new double[restricciones][variables];

        for (int i = 0; i < restricciones; i++)
        {
            for (int j = 0; j < variables; j++)
            {
                this.A[i][j] = Integer.parseInt(JOptionPane.showInputDialog("Valor de elemento X"+(i)+""+(j)+" : "));

                if(this.A[i][j] >= 0 && this.A[i][j] < 10)
                {
                    System.out.print("\t"+this.A[i][j]+"\t"+"\t"+"|");
                }
                else
                {
                    System.out.print("\t"+this.A[i][j]+"\t"+"|");
                }

            }
            System.out.println();
        }
    }

    private void imprimirMatriz(double[][] matriz)
    {
        int siONo = Integer.parseInt(JOptionPane.showInputDialog("Deseas imprimir la matriz? 1 = Si"));

        if(siONo == 1)
        {
            System.out.println("Matriz A =");
            System.out.println();
            for (int i = 0; i < matriz.length; i++)
            {
                for (int j = 0; j < matriz[i].length; j++)
                {
                    if(matriz[i][j] >= 0 && matriz[i][j] < 10)
                    {
                        System.out.print("\t"+matriz[i][j]+"\t"+"\t"+"|");
                    }
                    else
                        {
                        System.out.print("\t"+matriz[i][j]+"\t"+"|");
                        }
                }
                System.out.println();
            }
        }
    }

    private void setJ(double[][] matriz) // Ubicamos la columna pivote
    {
        int siONo = Integer.parseInt(JOptionPane.showInputDialog("Ubicar columna pivote... 1 = Si"));

        if(siONo == 1)
        {
            double elementoMasNegativo = Double.MAX_VALUE;

            for(int j =1; j < matriz[0].length; j++)
            {
                if(matriz[0][j] != 0)
                {
                    if(elementoMasNegativo > matriz[0][j])
                    {
                        elementoMasNegativo = matriz[0][j];
                        this.J = j;
                    }
                }
            }
        }

    }

    private void setI() // Ubicamos el renglon pivote (haciendo prueba del cociente en cada fila de i > 0, puesto que la fila i = 0 es nuestra funcion objetivo).
    {
        int siONo = Integer.parseInt(JOptionPane.showInputDialog("Ubicar fila pivote... 1 = Si"));

        if(siONo == 1)
        {
            double elementomenor = Double.MAX_VALUE;

            for (int i = 1; i < this.B.length; i++) {
                for (int j = this.J; j <= this.B[i].length; j++)
                {
                    if (j == this.J)
                    {
                        if (elementomenor > this.B[i][(this.B[i].length) - 1] / (this.B[i][j]))
                        {
                            elementomenor = this.B[i][(this.B[i].length) - 1] / (this.B[i][j]);
                            this.I = i;
                        }
                    }
                }
                System.out.println();
            }
        }
    }

    private void paso1()
    {
        int siONo = Integer.parseInt(JOptionPane.showInputDialog("Multiplicamos la fila I por el valor inverso del elemento pivote? 1 = Si"));

        if(siONo == 1)
        {
            double elementoPivote = this.B[this.I][this.J];
            for (int j = 0; j < this.B[this.I].length; j++)
            {
                this.B[this.I][j] = ((this.B[this.I][j]) * (1 / elementoPivote));
            }
        }
    }

    private void paso2()
    {
        int siONo = Integer.parseInt(JOptionPane.showInputDialog("Restamos la fila I multiplicada por factor de cada fila, para hacer 0 los elementos superiores e inferiores 1 = Si"));

        if(siONo == 1)
        {
            for (int i = 0; i < this.B.length; i++)
            {
                double elemento = this.B[i][this.J];
                if (i != this.I)
                {
                    for (int j = 0; j < this.B[i].length; j++)
                    {
                        this.B[i][j] += (this.B[this.I][j]) * ((elemento) * -1);
                    }
                }
            }
        }
    }

}
