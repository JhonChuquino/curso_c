//cree una clase departamento con los atributos de nombre_dep y siglas que contenga un arreglo de 10 empleados 
//registrados 
//imprima un reporte de departamento y sus empleados en txt 
#include<iostream>
#include<string>
#include "empleado.cpp"

using namespace std;
class Departamento {
protected:
    string nombre_dep;
    string siglas;
    Empleado empleados[10];
    int numEmpleados;

public:
    Departamento(string _nombre_dep, string _siglas)
    {
        nombre_dep = _nombre_dep;
        siglas = _siglas;
        
    }

    string getNombre_dep(){
        return nombre_dep;
    }
    void setNombre_dep(string _nombre_dep){
        nombre_dep = _nombre_dep;
    }
    

    string getSiglas(){
        return siglas;
    }
    void setSiglas(string _siglas){
        siglas = _siglas;
    } 

    void agregarEmpleado(Empleado empleado) {
        if (numEmpleados < 10) {
            empleados[numEmpleados] = empleado;
            numEmpleados++;
        } else {
            cout << "Error: No se puede agregar más empleados al departamento" << endl;
        }
    }

    /*void mostrarEmpleados() const {
        for (int i = 0; i < numEmpleados; i++) {
            cout << empleados[i].getNombre_deps() << " " << empleados[i].getApellidos() << " - " << empleados[i].getPuesto() << endl;
        }
    }*/
};

