#include <iostream>
using namespace std;
int main()
{
    system("cls"); //limpiar pantalla
    string libros[5]; //le damos un valor maximo al string
    int tamaño= sizeof(libros)/ sizeof(libros[0]);
    //usamos el ciclo for para pedir ingresar los nombres de los libros 
    for(int i=0; i<tamaño; i++)
    {
        //pedimos al usuario que ingrese cada libro 
        cout<<"\n"<< "ingrese el libro["<<i<<"]";
        cin>>libros[i];
    }
    for(int i=0; i<tamaño; i++)
    {
        //mostramos por pantalla los vectores libro y su posicion
        cout<<"\n"<<"el libro["<<i<<"] = "<<libros[i];
    }
    return 0;
}