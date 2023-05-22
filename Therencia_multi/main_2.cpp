#include <iostream>
#include <string>

#include "profesorinvestigador.cpp"

using namespace std;

int main()
{
    system("cls");
    Profesorinvestigador profe_inv_1("Jose", "234567", " Ingenieria en Informatica y de Sistemas");
    Profesorinvestigador profe_inv_2("Benjamin", " 203456", "  de Zootecnia");
    Profesorinvestigador profe_inv_3("Alvaro", "345677", " de Ingenieria Mecanica");
    Profesorinvestigador profe_inv_4("Marco", "2456778", " de Ingenieria Ambiental");
    Profesorinvestigador profe_inv_5("Luis", "345678", " de Ingenieria Forestal");
    Profesorinvestigador profe_inv_6("Gabriel", "986452", " de Rescursos Naturales");

    cout << "LOS DATOS DE LOS PROFESORES SON: \n";
    Profesorinvestigador profes[6] ={profe_inv_1, profe_inv_2, profe_inv_3, profe_inv_4, profe_inv_5, profe_inv_6};

    int tamaño = sizeof(profes)/ sizeof(profes[0]);

    for(int i = 0; i < tamaño; i++){
        cout <<" °|°|° "<< profes[i].getDataProfesor();
        cout<< "\n";
    }
}