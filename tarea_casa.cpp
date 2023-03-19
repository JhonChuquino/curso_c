#include<iostream>
using namespace std;
int main()
{
    system("cls");
    int numeros[5]; //le damos una cantidad definida de arreglos.
    //nos muestra el almacenamiento en bytes.
    int tamaño = sizeof(numeros)/ sizeof(numeros[0]);
    //usamos el ciclo para pedir al usuario que ingrese los valores de cada posicion del arreglo.
    for(int i = 0; i < tamaño; i++){
        cout<<"\n"<< "ingrese el valor del numero["<<i<<"]";
        cin>>numeros[i]; //capturamos los valores asigados.
    }
    //usamos un 2do ciclo para mostrar por pantalla los valores de cada posición.
    for(int i=0; i<tamaño; i++)
    {
        
        cout<<"\n"<<"el valor del numero["<<i<<"] es : "<< numeros[i] << endl;
    }

    //Mostrar el numero mayor.

    //Declaramos una variable entero con nombre mayor, que inicia en la posicion 0.
    int mayor = numeros[0];
    for (int i = 1; i < tamaño; i++)
    {   //usamos el ciclo para hacer la comparacion del valor de la posicion 0 con cada posicion restante.
        //si el valor de las posiciones es mayor a la anterior , se sigue ejecutando hasta hallar el mayor.
        if(numeros[i] > mayor)
        {   //capturamos el mayor numero despues de las comparaciones y la guardamos en la variable mayor.
            mayor = numeros[i];
        }
    }
    cout<<"\n"<<"el numero mayor es: "<< mayor;
    cout<<"\n";

    //Mostrar el numero menor.

    //Declaramos una variable entera menor, que inicia en la posicion 0.
    int menor = numeros[0];
    //usamos el ciclo para poder hacer las comparaciones del valor de cada posición.
    for (int i = 1; i < tamaño; i++)
    {   //usamos el ciclo para hacer la comparacion del valor de la posicion 0 con cada posicion restante.
        if (numeros[i] < menor)
        {   //capturamos el menor numero despues de las comparaciones y la guardamos en la variable menor.
            menor = numeros[i];
        }
    } 
    cout<<"\n"<<"el numero menor es: "<< menor;
    cout<<"\n";

    //Hallar si un numero se repite y cuantas veces.

    //Declaramos variables y las inicializamos.
    int repite=0;
    int informacion=0,contador=0;
    //usamos un for aninado para realizar el recorrido.
    for(int i=0;i<tamaño;i++)         // 0 1 2 2 5  datos
    {                                  // 0 1 2 3 4  posiciones
        int veces_repetidas=1;
        int numero_a_comparar=numeros[i];

        for (int y=i+1; y<=tamaño; y++)
        {   //Usamos una condicional para realizar comparaciones entre la variable  y los valores del arreglo.
            if(numero_a_comparar==numeros[y])   
            {   //Guardamos los valores halladas
                veces_repetidas = veces_repetidas + 1;

                repite=numeros[y];
            }
        }
        //Usamos la condicional para saber la cantidad de veces que se repite
        if(veces_repetidas>1)
        {   //Realizamos la operacion.
            informacion=informacion + (contador + veces_repetidas);
            //Mostramos por pantalla los resultados.
            cout<<endl<<"El numero "<<repite<<" se repite "<<veces_repetidas<<" veces";
            i=informacion-1;
        }
        else
        {  //En caso no se cumpla la condicion no mostramos nada.
            contador = contador + 1;
        }
    } cout<<endl;

    //Ordenar de mayor a menor.

    int descendente=0;
    cout<<"EL ORDEN DESCENDENTE ES: ";
    //Usamos un ciclo for aninado para hacer el recorrido y las comparaciones.
    for(int i=0;i<tamaño;i++)                       
    {                           
        for(int y=i+1;y<tamaño;y++)
        {   //usamos una condicional simple para hallar los numeros mayores al anterior e ir guardandolas
            if(numeros[i] < numeros[y])
            {   //reamplazamos los valores de cada varible igualandola a otra.
                descendente=numeros[i]; 
                numeros[i]=numeros[y];
                numeros[y]=descendente;  
            }
        }
    }
    //Mostramos por pantalla el orden.
    for(int i=0;i<tamaño;i++)
    {
        cout<<"  "<<numeros[i];
    }
    cout<<"\n";

    //Ordenar de menor a mayor.

    //Declaramos una variable y la inicializamos en 0.
    int ascendente=0;
    cout<<"EL ORDEN ASCENDENTE ES: ";
    //Usamos un ciclo for aninado para hacer el recorrido y las comparaciones.
    for(int i=0;i<tamaño;i++)
    {
        for(int y=i+1;y<tamaño;y++)
        {   //usamos una condicional simple para hallar los numeros mayores al anterior e ir guardandolas
            if(numeros[i]>numeros[y])
            {   //cambiamos los valores de cada variable
                ascendente=numeros[i];
                numeros[i]=numeros[y];
                numeros[y]=ascendente;  
            }
        }
    } //Mostramos por pantalla orden.
    for(int i=0;i<tamaño;i++)
    {
        cout<<"  "<<numeros[i];
    }
    cout<<"\n";

    //Hallar la suma de los valores del arreglo.

    //Declaramos la variable suma_total y la inicializamos en 0.
    int suma_total = 0;
    //Usamos un ciclo para realizar todas las pasadas de los valores.
    for(int i = 0; i < tamaño; i++){
        //Realizamos la suma de cada valor de un vector con el anterior.
        suma_total = suma_total + numeros[i];
    } 
    cout<<"\n"<<"la suma total es:" << suma_total;
    cout<<"\n";

    //Hallar el promedio.

    //Declaramos una variable y la inicializamos en 0.
    double promedio = 0;
    //Aprovechamos que ya tenemos la suma y solo la dividimos entre el total de arreglos.
    promedio = (suma_total)/5;
    cout<<"\n"<<"el promedio es: "<<promedio;
    cout<<"\n";

    
    cout<<"Reemplazamos el valor de la posicion 2 por 25";
    //usamos un ciclo para mostrar nuevamente los valores que ingresamos por pantalla
    //cambiamos el valor de la posicion medio por el valor de 25.
    for(int i=0; i<tamaño; i++)
    {   //usamos la condicional para hallar la posicion 2
        if(i == 2)
        {   //cambiamos su valor y le asignamos el valor de 25
            numeros[i] = 25;
        }
        //Mostramos por pantalla las posiciones del vector y sus valores
        cout<<"\n"<<"el valor del numero["<<i<<"] es : "<< numeros[i] << endl;
    }


    return 0;

}