//implemente dos clases automoviles y motocicleta que 	hereden los atributos 
//de vehiculo, y contengan atributos de color y marca

#include<iostream>
#include<string>
#include "transporte.cpp"

using namespace std;

class Automoviles  : public Transporte
{
    protected:
    string color;
    string marca;
    
    public:
    Automoviles(string _color = "", string _marca = "", int _cilindrada = 0, int _asientos = 0, int _ruedas = 0, int _puertas = 0, bool _seguridad = "")  : Transporte(_cilindrada, _asientos, _ruedas, _puertas,_seguridad)
    {
        color = _color;
        marca = _marca;
    }

    string getColor(){
        return color;
    }
    void setColor(string _color){
        color = _color;
    }

    string getMarca(){
        return marca;
    }
    void setMarca(string _marca){
        marca = _marca;
    }

    string toString(){

        string resumen = "Color : " + color + " ---> Marca: " + marca + " ----> Cilindrada de motor: " + to_string(cilindradaMotor) + " ---> Número de asientos: " + to_string(numAsientos) + "\nNúmero de ruedas: " + to_string(numRuedas) + " ---> Número de puertas: " + to_string(numPuertas) + " ---> Certificación de seguridad: " + (tieneCertificacionSeguridad() ? "Sí" : "No");
        return resumen;
    }

    /*string toString(){
        string resumen ;
        // Imprimir reporte
        cout << "Nombre de la tienda: Mi Tienda de Vehículos\n\n";
        cout << "Automóviles:\n";
        for (int i = 0; i < 10; i++) {
         cout << "Automóvil " << i+1 << ":\n";
         cout << "Cilindrada de motor: " << autos[i].getCilindradaMotor() << endl;
         cout << "Número de asientos: " << autos[i].getNumAsientos() << endl;
         cout << "Número de ruedas: " << autos[i].getNumRuedas() << endl;
         cout << "Número de puertas: " << autos[i].getNumPuertas() << endl;
         cout << "Certificación de seguridad: " << (autos[i].tieneCertificacionSeguridad() ? "Sí" : "No") << endl;
         cout << "Color: " << autos[i].getColor() << endl;
         cout << "Marca: " << autos[i].getMarca() << endl << endl;
        }
    }*/

};
