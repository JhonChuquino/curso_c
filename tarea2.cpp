#include <iostream>
using namespace std;
int main()
{
    system("cls"); // limpiar pantalla
    //declaración de variables
    int num = 13, i;
    //declaracion del memoria
    int *pnum= &num; //Quiero imprimir la dirección de memoria de numero 
                          
    if(num==1)  //si se lee un 1, se imprime directamente que no es primo                                           
    {
        cout << "\nNo es primo" << endl;
    }
    else
    {
        i=2;          //i es el divisor
        while(num%i!=0) //mientras el número sea divisible por el divisor
        {
            i++;      //siguiente divisor
        }
        //cuando sale del while, si el divisor es el propio número
        //entonces el número es primo
        if(i==num)      
            cout << "\nPrimo" << endl;   
        else
            cout << "\nNo es primo" << endl; 
    }
    cout << pnum << "\n" ; // mostramos por pantalla la direccion de memoria que le asignamos a numero
    
}