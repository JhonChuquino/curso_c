#include <iostream>
using namespace std;
int main()
{
    system("cls"); //limpiar pantallla
    //declaracion de variables
    int numero;
    int *p ; // declaramos el puntero
    p = &numero; // almacenamos en el puntero la direccion de memorias
    cout << "ingrese un numero " << "\n" ; //ingrese por pantalla la variable
    cin >> numero;
    if(numero%2==0) // la condicinal para saber si es par o impar
    {
        cout << "es un numero par " << "\n";
    } else {
        cout << "es un numero impar " << "\n";
    }
    cout << p; //nos nuestra por pantalla la direccion de memoria
}