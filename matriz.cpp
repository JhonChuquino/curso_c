//13/04/2023
//HACER UN PROGRAMA DE UNA MATRIZ 5X4 DONDE HALLAMOS LA SUMA DE LA MATRIZ, IMPRIMIR LA MATRIZ POR PANTALLAA
//SUMAR LAS FILAS, SUMA DE LAS COLUMNAS, EL VALOR MAXIMO Y MINIMO, PROMEDIO DE LA MATRIZ, PROMEDIO DE FILAS
//PROMEDIO DE COLUMNAS, INVERTIR LA MATRIZ

#include<iostream>

using namespace std;

//declarando funciones

//Funcion sumar matriz.

//Declaramos una funcion suma y establecemos los parametros
int suma_matriz(int matriz_suma[5][4],int fila,int columna)
{   //inicializamos la variable suma en 0.
    int suma=0;
    //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
    for(int i=0;i<fila;i++)
    {   
        //Usamos el ciclo for para hacer el recorrido con los valores de la columna.
        for(int j=0;j<columna;j++)
        {    
            //Realizamos la operacion para sumar los elementos de la matriz.
            suma = suma + matriz_suma[i][j];
        }
    }
    //Al ser una funcion nos debe retornar algo, en este caso la variable suma.
    return suma;
}

//Imprimir la matriz.

//Usamos la funcion void que es cuando queremos que no se muestre.
void imprimir_matriz(int matriz[5][4],int fila,int columna)
{
    //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
    for(int i=0;i<fila;i++)
    {   
        //Usamos el ciclo for para hacer el recorrido con los valores de la columna.
        for(int j=0;j<columna;j++)
        {
            //mostramos por pantalla todos los valores de la matriz.
            cout<<"\t"<<matriz[i][j]<<"|";
        }
        cout<<endl;
    }
}

//funcion para sumar las filas

//usamos la funcion void para que no nos retorne ningun valor.
void sumar_filas(int matriz_suma[5][4],int fila,int columna)
{
    //Declaramos una nueva variable donde se almacenara el resultado.
    int suma_fila;
    //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
    for(int i=0;i<fila;i++)
    {   //inicializamos la variable en 0.
        suma_fila=0;
        //Usamos el ciclo for para hacer el recorrido con los valores de la columna.
        for(int j=0;j<columna;j++)
        {
            //Realizamos la operacion, donde las columnas toman el valor de 0, solo recorriendo
            //los valores de las filas.
            suma_fila += matriz_suma[i][j];            //suma = suma + matriz_suma[i][j]
        }
        //mostramos por pantalla el resultado.
        cout<<"La suma de la fila ["<<i<<"] es :" <<suma_fila<<endl;
    } 
}

//funcion sumar columnas

//usamos la funcion void para que nos nos retorne ningun valor.
void sumar_columnas(int matriz_suma[5][4],int fila,int columna)
{
    //declaramos una variable
    int suma_columna;
    //Usamos el ciclo for para hacer el recorrido con los valores de la columna.
    for(int i=0;i<columna;i++)
    {   //inicializamos la variable
        suma_columna=0;
        //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
        for(int j=0;j<fila;j++)
        {   //realizamos la operacion, en este caso durante todos recorridos solo se tomara el valor
            //de cada columna ya que la fila toma el valor de 0
            suma_columna += matriz_suma[j][i];              
        }
        //mostramos por pantalla el resulatado.
        cout<<"La suma de la columa ["<<i<<"] es :" <<suma_columna<<endl;
    }  
}

//Encontrar el numero mayor.

//Declaramos una funcion 

int valor_maximo(int matriz[5][4], int fila,int columna){
    int mayor = matriz[0][0];
    //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
    for(int i=0;i<fila;i++)
    {   
        //Usamos el ciclo for para hacer el recorrido con los valores de la columna.
        for(int j=0;j<columna;j++)
        {
            if(mayor < matriz[i][j]){
                mayor = matriz[i][j];
            }
        }
    }
    return mayor;
}

//Encontrar el valor minimo-
int valor_minimo(int matriz[5][4], int fila, int columna){
    //declaramos la variable menor que toma el valor de la posicion inicial de la fila y la columna.
    int menor = matriz[0][0];
    //usamos un ciclo for para hacer el recorrido para los valores de la fila
    for(int i = 0; i < fila; i++){
        //usamos for para hacer el recorrido para los valores de la columna
        for(int j = 0; j < columna; j++){
            //usamos una condicional para hacer las comparaciones del valor asignado a menor con 
            //los valores de los parametros que va recorriendo
            if( menor > matriz[i][j] ){
                menor = matriz[i][j];
            }
        }
    }
    return menor;
}
   

//funcion promedio de la matriz.

void promedio_matriz(int matriz_suma[5][4], int fila, int columna){
    //declaramos las variables y la inicializamos 
    int promedio=0;
    int suma=0;
    //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
    for(int i=0;i<fila;i++)
    {   //Usamos el ciclo for para hacer el recorrido con los valores de la columna.
        for(int j=0;j<columna;j++)
        {   //realizamos la operacion correspondiente.
            suma += matriz_suma[i][j];
            promedio = suma/(fila*columna);
        }
    }
    cout<<"El promedio de la matriz es :" <<promedio<<endl;
}

//Promedio de las filas
void promedio_filas(int matriz_suma[5][4],int fila,int columna)
{
    //Declaramos una nueva variable donde se almacenara el resultado.
    int suma_fila;
    double promedio_fila;
    //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
    for(int i=0;i<fila;i++)
    {   //inicializamos la variable en 0.
        suma_fila=0;
        promedio_fila = 0;
        //Usamos el ciclo for para hacer el recorrido con los valores de la columna.
        for(int j=0;j<columna;j++)
        {
            //Realizamos la operacion, donde las columnas toman el valor de 0, solo recorriendo
            //los valores de las filas.
            suma_fila += matriz_suma[i][j];            //suma = suma + matriz_suma[i][j]
            promedio_fila = suma_fila/fila;
        }
        //mostramos por pantalla el resultado.
        cout<<"El promedio de la fila ["<<i<<"] es :" <<promedio_fila<<endl;
    } 
}


//Promedio de las columnas.
void promedio_columnas(int matriz_suma[5][4], int fila, int columna){
    //inicializamos las variables.
    int suma_columna = 0;
    double promedio_columna = 0;
    //usamos un ciclo para hacer los recorridos de los valores de la columna
    for(int i=0;i<columna;i++)
    {   //inicializamos la variable
        suma_columna=0;
        //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
        for(int j=0;j<fila;j++)
        {   //realizamos la operacion, en este caso durante todos recorridos solo se tomara el valor
            //de cada columna ya que la fila toma el valor de 0
            suma_columna += matriz_suma[j][i]; 
            promedio_columna = suma_columna / columna;           
        }
        //mostramos por pantalla el resulatado.
        cout<<"El promedio de la columa ["<<i<<"] es :" <<promedio_columna<<endl;
    }  
}



//funcion para invertir las columnas y filas.

//usamos una funcion void e invertimos de posicion sus paramentros.
void imprimir_matriz(int matriz[4][5],int fila,int columna)
{   //Usamos el ciclo for para hacer el recorrido con los valores de la comuna.
    for(int i=0;i<columna;i++)
    {   //Usamos el ciclo for para hacer el recorrido con los valores de la fila.
        for(int j=0;j<fila;j++)
        {   //mostramos por pantalla el nuevo orden de las matrices
            cout<<"\t"<<matriz[j][i]<<"|";
            //suma +=matriz_suma[i][j];
        }
        cout<<endl;
    }
}


//la funcion principal
int main()
{ 
    //declaramos la matriz 5*4
    //         f  c      filas      
    int matriz[5][4]={{2,3,4,5},{6,7,8,9},{10,11,12,13},{14,15,16,17},{18,19,20,21}};
    //mostramos por pantalla los valores de la matriz segun su fila y columna.
    cout<<matriz[2][4]<<endl;
    cout<<matriz[5][4]<<endl;
    cout<<matriz[5][4]<<endl;
    //Usamos el ciclo for para hacer el recorrido con los valores de la fila, representada por el i.
    for(int i=0;i<5;i++)
    {   //Usamos el ciclo for para hacer el recorrido con los valores de la columna representada por la j.
        for(int j=0;j<4;j++)
        {   //mostramos por pantalla la matriz
            cout<<matriz[i][j]<<"|";
        }
        cout<<endl;
    }

    //mostramos por pantalla 
    //7La matriz
    imprimir_matriz(matriz,5,4);
    //suma de la matriz.
    int sum = suma_matriz(matriz,5,4);
   
    cout<<"La suma es = "<<sum;
    cout<<endl;
    
    sumar_filas(matriz,5,4);
    
    sumar_columnas(matriz,5,4);
    //el promedio de la suma de todos los valores de la matriz.

    int mayor = valor_maximo(matriz,5,4);
    cout<<"\nEl maximo valor de la matriz es = "<< mayor;
    cout<<endl;
    int menor = valor_minimo(matriz,5,4);
    cout<<"\nEl minimo valor de la matriz es = "<< menor;
    cout<<endl;
    promedio_matriz(matriz,5,4);
    cout<<endl;
    promedio_filas(matriz,5,4);
    cout<<endl;
    promedio_columnas(matriz,5,4);
    cout<<endl;
    cout<<"LA NUEVA FORMA DE LA MATRIZ INVERTIDA "<< endl;
    imprimir_matriz(matriz,4,5);

    return 0;   
}