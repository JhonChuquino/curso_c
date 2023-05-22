#include <iostream>
#include <string>

#include "estudianteempleado.cpp"

using namespace std;

int main()
{
    EstudianteEmpleado e;

    e.setDatosPersona("Jose", "rodriguez", 25);

    cout<< e.getDataPersona();
    return 0;
}