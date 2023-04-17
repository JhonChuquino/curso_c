//09/03/2023
//HACER UN PROGRAMA DONDE DECLARAMOS UN VECTOR DE 5 ELEMENTOS Y PIDA AL USUARIO QUE INGRESE LOS PRECIO Y LOS MOSTRAMOS POR 
//PANTALLA EL PRODUCTO Y EL PRECIO

#include <iostream>
using namespace std;
int main(){
    system("cls"); //limpiar pantalla
    //declaramos el arreglo string 
    string productos[5] = {"pollo", "aceite", "arroz", "atun", "sal"};
    int precio[5];
    int tamaño = sizeof(productos)/ sizeof(productos[0]);
    //usamos este ciclo para pedir los precios de cada producto y almacenarla en el arreglo precio[i]
    for(int i = 0; i < tamaño; i++){
        cout<<"\n"<< "ingrese el precio del producto["<<i<<"]";
        cin>>precio[i];
    }
    for(int i=0; i<tamaño; i++)
    {
        //mostramos por pantalla los productos y su precio
        cout<<"\n"<<productos[i] << " = " << precio[i];
    }
    return 0;
}
