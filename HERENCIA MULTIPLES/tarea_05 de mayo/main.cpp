#include<iostream>
#include<string>
#include <fstream>

#include "departamento.cpp"
using namespace std;

int main(){

    Empleado emp_1("Jorge","Martin","12345", "30/05/2000", 24, "Gerente", "2345", "6 años");
    Empleado emp_2("Maria", "Gonzalez", "87654321", "02/02/1995", 27, "Asistente", "2000", "2 años");
    Empleado emp_3("Carlos", "Lopez", "45678901", "03/03/2000", 22, "Analista", "3000", "1 año");
    Empleado emp_4("Laura", "Rodriguez", "10987654", "04/04/1985", 37, "Director", "8000", "8 años");
    Empleado emp_5("Pedro", "Gomez", "21098765", "05/05/1993", 29, "Consultor", "4000", "3 años");
    Empleado emp_6("Juan", "Perez", "12345678", "01/01/1990", 32, "Gerente", "5000", "5 años");
    Empleado emp_7("Jhon", "Oriuela", "12345678", "01/01/1992", 45, "Gerente", "5000", "5 años");
    Empleado emp_8("Jose", "Palacios", "12345678A", "01/01/1999",21, "Programador", "2000", "2 años");
    Empleado emp_9("Rosa", "Chavez", "3485960", "3/03/1990", 33, "secretaria", "2000", " 6 meses");
    Empleado emp_10("Roy", "Chacon", "1297660", "3/06/1997", 33, "seguridad", "2000", " 9 meses");

    Departamento dep_1("SYSTEMATEC CORPORATION", "SYC");

    Empleado empleado[10] = {emp_1, emp_2, emp_3, emp_4, emp_5, emp_6, emp_7,emp_8, emp_9, emp_10};
   
    int tamaño = sizeof(empleado)/ sizeof(empleado[0]);
    /*for(int i = 0; i < tamaño; i++){
        cout<< empleado[i].toString();
        cout<<endl;
    }*/
    ofstream archivo("empleados.txt");

    // Verificamos si el archivo se abrió correctamente
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    archivo << "Datos de los empleados \n";
    archivo << dep_1.getNombre_dep()<<"("<<dep_1.getSiglas()<<")";
    archivo << endl;
    for (int i = 0; i < tamaño; i++)
    {
        archivo << empleado[i].toString() << "\n";
    }
    archivo.close();

    return 0;
};