//09/03/2023
//HACER UN ARREGLO DE 5 ELEMENTOS Y MOSTRAMOS POR PANTALLA EL PRODUCTO Y SU POSICIOC

#include <iostream>
using namespace std;
int main()
{
    system("cls"); // limpiar pantalla
    // declaramos los arreglos del producto
    string productos[5] = {"lupa", "Galleta", "Luces", " jarra", "correa"}; 
    productos [2] = "computadora" ; //reemplazamos el producto de la posicion 3
    for(int i=0; i < 5; i++)
    {
        //mostramos por pantalla los vectores productos y su posicion
        cout <<"\n"<<"el valor del vector productos["<<i<<"]" << productos[i];
    }
}
