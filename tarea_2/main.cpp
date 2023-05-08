//implementar un metodo para imprimir un reporte con la siguiente estructura
//nombre de la tienda, lista de automoviles a detalle y lista motocicletas

#include<iostream>
#include<string>
#include <fstream>
#include "transporte.cpp"
#include "automoviles.cpp"
#include "motocicleta.cpp"

using namespace std;

int main(){
    system("csl");
    // Crear arreglo de automóviles
    Automoviles auto_1("Rojo", "Toyota", 1500, 5, 4, 4, true);
    Automoviles auto_2("Honda", "Azul",2000, 4, 4, 2, true);
    Automoviles auto_3("Ford", "Negro",1800, 5, 4, 4, true );
    Automoviles auto_4("Chevrolet", "Blanco",2500, 6, 4, 4, true);
    Automoviles auto_5("Nissan", "Gris",1900, 5, 4, 4, true);
    Automoviles auto_6("Mercedes-Benz", "Plata",3000, 7, 4, 4, true);
    Automoviles auto_7("Ford", "Negro",1800, 5, 4, 4, true );
    Automoviles auto_8("Chevrolet", "Blanco",2500, 6, 4, 4, true);
    Automoviles auto_9("Nissan", "Gris",1900, 5, 4, 4, true);
    Automoviles auto_10("Mercedes-Benz", "Plata",3000, 7, 4, 4, true);


    Motocicleta mot_1("Rojo", "Honda", 250, 2, 2, 0, true);
    Motocicleta mot_2("Negro", "Kawasaki", 650, 2, 2, 0, true);
    Motocicleta mot_3("Verde", "Suzuki", 750, 2, 2, 0, true );
    Motocicleta mot_4("Blanco", "Harley Davidson", 500, 2, 2, 0, true);
    Motocicleta mot_5("Azul", "Yamaha", 150, 2, 2, 0, true);

    Automoviles autos[10] = {auto_1,auto_2,auto_3,auto_4,auto_5,auto_6,auto_7,auto_8,auto_9,auto_10};
    Motocicleta motos[5] = {mot_1, mot_2, mot_3, mot_4, mot_5};

    ofstream archivo("Reporte de productos.txt");

    // Verificamos si el archivo se abrió correctamente
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    archivo << "REPORTE DE PRODUCTOS DE VENTA\n";
    archivo << "AUTOMOVILES \n";
    for (int i = 0; i < 10; i++)
    {
        archivo << 1 + i << " >> " << autos[i].toString() << "\n";
        archivo << endl << endl;
    }
    archivo << "MOTOCICLETAS \n";
    for (int i = 0; i < 5; i++)
    {
        archivo << 1 + i << " >> " << motos[i].toString2() << "\n";
        archivo << endl;
    }
    archivo.close();

    system("pause");
    return 0;
};