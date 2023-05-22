#include <iostream>
#include <string>
#include <fstream> //libreira para archivos
// #include "facultad_01.cpp"
#include "estudiante.cpp"

using namespace std;
int main(){

    Facultad facu1("001", "Facultad de Ingenieria en Informatica y Sistemas", "FIIS");
    Facultad facu2("002", "Facultad de de Zootecnia", "FZ");
   
   // Estudiantes de FIIS
    Estudiante est1("2023000001", "juanito.perez@unas.edu.pe", "perez", "juanito", "44444444");
    est1.setFacultad(facu1);
    Estudiante est2("20220456", "jose.caldas@unas.edu.pe", " jose", "caldas", "234567");
    est2.setFacultad(facu1);
    Estudiante est3("20223457", "carlos.solar@unas.edu.pe", " carlos", "solar", "345678");
    est3.setFacultad(facu1);
    Estudiante est4("20223412", "marco.palacios@unas.edu.pe", "marco", "palacios", "3457177");
    est4.setFacultad(facu1);
    // Estudiantes de ZOOTECNIA
    Estudiante est5("2020007", "manuel.lopez@unas.edu.pe", "lopez", "manuel", "20458771");
    est5.setFacultad(facu2);
    Estudiante est6("2000485", "therry.exaltacion@unas.edu.pe", "exaltacion", "therry", "2024575");
    est6.setFacultad(facu2);
    Estudiante est7("20220050", "krystal.exaltacion@unas.edu.pe", "exaltacion", "krystal", "87541558");
    est7.setFacultad(facu2);
    Estudiante est8("2022002", "jose.martinez@unas.edu.pe", "mantinez", "jose", "73463283");
    est8.setFacultad(facu2);

    // crear cursos
    Curso curs_1("0001", "Programacion Basica", 4);
    Curso curs_2("0002", "Diseño de BD", 3);
    Curso curs_3("0003", "Sotfware I", 3);
    Curso curs_4("0004", "Sotfware II", 4);
    Curso curs_5("0005", "Gestion de procesos", 4);
    //cursos para zoo
    Curso curs_6("0006", "Platano I", 4);
    Curso curs_7("0007", "Arroz I", 3);
    Curso curs_8("0008", "Matematica Basica", 3);
    Curso curs_9("0009", "BIO II", 4);
    Curso curs_10("00010", "Lenguaje", 4);

    //creamos nuestros arreglos que vamos a usar

    Estudiante list_est[8] = {est1,est2, est3,est4,est5,est6,est7,est8};
    Curso cursos[10] = {curs_1,curs_2,curs_3,curs_4,curs_5,curs_6,curs_7,curs_8,curs_9,curs_10};
    Facultad facultad[2] = {facu1, facu2};

    //funcion para que ingresar las notas

    float nota1 = 0, nota2 = 0, nota3 = 0;
        if (sizeof(cursos) / sizeof(cursos[0]) != 0)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << "--------------------------------";
                cout << "\n";
                cout << cursos[i].getCodigo() << "---" << cursos[i].getDescripcion();
                cout << "\n";
                cout << "--------------------------------";
                cout << "\n";
                nota1 = 0;
                nota2 = 0;
                nota3 = 0;
                cout << "Ingrese la nota 1 :";
                cin >> nota1;
                cout << "\n";
                cout << "Ingrese la nota 2 :";
                cin >> nota2;
                cout << "\n";
                cout << "Ingrese la nota 3:";
                cin >> nota3;
                cout << "\n";
                cursos[i].setNota1(nota1);
                cursos[i].setNota2(nota2);
                cursos[i].setNota3(nota3);
                cout << "\n";
            }
        }

    ofstream archivo("estudiante.txt");

    // Verificamos si el archivo se abrió correctamente
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    archivo << "Datos , Cursos y notas \n";
    //para que nos muestra la facultad de los 2 estudiantes
    archivo << facultad[0].toString() <<"\n";
    //archivo <<endl;
    //recorrera a 2 estudiantes de la fiss
    for(int i = 0; i < 2; i++){
        if(list_est[i].getFacultad().getSigla() == "FIIS"){ 
            archivo << endl;
            //imprimira los datos de 2 estudiantes
            archivo << list_est[i].toString2()<<"\n";
            archivo << endl;
        }
        // hara un recorrido por los 5 cursos de las Fiss
        for (int j = 0; j< 5; j++)
        {
            if(list_est[i].getFacultad().getSigla() == "FIIS"){
                //si es de la Fiss recorrera sus cursos y mostrara sus notas ingresado por pantalla
                archivo << cursos[j].toString2() << "\n";
            }
        } 
    }
    archivo.close();
    return 0;
}