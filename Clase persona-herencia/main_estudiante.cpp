#include<iostream>
#include<string>

#include "Estudiante.cpp"
using namespace std;

int main(){

    Estudiante est("2023000001","FIIS", "juanito.perez@unas.edu.pe","perez", "juanito", "44444444");
    Estudiante est_1("20220456", "FIA", "jose.caldas@unas.edu.pe" ," jose", "caldas", "234567");
    Estudiante est_2("20223457", "FACEA", "carlos.solar@unas.edu.pe", " carlos", "solar", "345678");
    Estudiante est_3("20223412", "FIA", "marco.palacios@unas.edu.pe", "marco", "palacios", "3457177");

    cout<<"Estudiantes : \n";
    est.getDatos();
    cout<<"\n";
    est_1.getDatos();
    cout<<"\n";
    est_2.getDatos();
    cout<<"\n";
    est_3.getDatos();

    return 0;

}


