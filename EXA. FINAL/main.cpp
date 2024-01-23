#include <iostream>
#include <fstream>
#include <string>
#include "repuestos.cpp"
#include "serviciotaller.cpp"
#include "cliente.cpp"

using namespace std;

// Función para imprimir los datos de los repuestos
void imprimirDatosRepuestos(ofstream& archivo)
{
    // Redirigir la salida estándar hacia el archivo
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(archivo.rdbuf());

    TiendaRepuestos tienda;

    // Agregar algunos repuestos a la tienda
    tienda.agregarRepuesto("Llanta", "LL001", 100.0, 5,"12/08/2023","Neumaticos");
    tienda.agregarRepuesto("Aceite de motor", "AM002", 50.0, 10,"3/09/2023", "Lubricante");
    tienda.agregarRepuesto("Filtro de aire", "FA003", 20.0, 8,"22/08/2023", "Lubricante");

    // Mostrar el stock de productos por fecha de registro
    tienda.mostrarStockPorFecha();
    tienda.mostrarRepuestosNoVendidos();
    

    // Restaurar la salida estándar
    cout.rdbuf(coutbuf);
}

// Función para obtener los datos de los servicios y empleados
void obtenerDatosServicios(ofstream& archivo)
{
    // Redirigir la salida estándar hacia el archivo
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(archivo.rdbuf());

    // Crear servicios
    ServicioTaller servicio1("Cambio de aceite", "Realizar el cambio de aceite del motor", 1, "03/2/2023");
    ServicioTaller servicio2("Reparación de frenos", "Reparar o reemplazar los componentes del sistema de frenos", 2,"04/05/2023");
    ServicioTaller servicio3("Mantenimiento de suspensión", "Realizar el mantenimiento y ajuste de la suspensión", 3,"24/01/2023");

    // Crear empleados
    Empleado empleado1("Juan", "González", "Mecánico", 5);
    Empleado empleado2("Marco", "López", "Electricista", 3);

    // Asignar servicios a los empleados
    empleado1.asignarServicio(servicio1);
    empleado1.asignarServicio(servicio2);
    empleado2.asignarServicio(servicio3);

    // Mostrar servicios asignados y tiempo total por empleado
    empleado1.mostrarServiciosAsignados();
    cout << "Tiempo total para " << empleado1.getNombre() << " " << empleado1.getApellidos() << ": " << empleado1.calcularTiempoTotal() << " horas" << endl;
    cout << endl;
    empleado2.mostrarServiciosAsignados();
    cout << "Tiempo total para " << empleado2.getNombre() << " " << empleado2.getApellidos() << ": " << empleado2.calcularTiempoTotal() << " horas" << endl;

    // Restaurar la salida estándar
    cout.rdbuf(coutbuf);
}

// Función para obtener los datos de los clientes
void obtenerDatosClientes(ofstream& archivo)
{
    // Redirigir la salida estándar hacia el archivo
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(archivo.rdbuf());


    // Crear clientes
    Cliente cliente1("Carlos", "González", "Av. Raymondi, Lima", "123456789","12/03/2023");
    Cliente cliente2("Marta", "López", "Av. Canada, Lima", "987654321", "11/01/2023");
    Cliente cliente3("Jose", "Rodríguez", "Av. Brasil, Lima", "456789123", "30/04/2023");

    // Registrar servicios para cada cliente
    cliente1.registrarServicio("Cambio de aceite");
    cliente1.registrarServicio("Reparación de frenos");
    cliente2.registrarServicio("Mantenimiento de suspensión");
    cliente2.registrarServicio("Cambio de batería");
    cliente2.registrarServicio("Alineación y balanceo");
    cliente3.registrarServicio("Reparación de motor");

    // Mostrar servicios realizados para cada cliente
    cliente1.mostrarServiciosRealizados();
    cout << endl;
    cliente2.mostrarServiciosRealizados();
    cout << endl;
    cliente3.mostrarServiciosRealizados();

    // Identificar clientes más frecuentes
    map<string, int> frecuenciaClientes;
    frecuenciaClientes[cliente1.getNombre()]++;
    frecuenciaClientes[cliente2.getNombre()]++;
    frecuenciaClientes[cliente2.getNombre()]++;

    cout << "Clientes más frecuentes:" << endl;
    for (const auto& pair : frecuenciaClientes)
    {
        cout << "Cliente: " << pair.first << ", frecuencia: " << pair.second << endl;
    }

    // Restaurar la salida estándar
    cout.rdbuf(coutbuf);
}

// Función para imprimir texto en un color específico
void printInColor(const std::string& text, int colorCode)
{
    std::cout << "\033[" << colorCode << "m" << text << "\033[0m";
}

int main()
{
    int opcion;

    ofstream archivo("Reporte.txt"); // Abre el archivo

    do
    {
        cout << endl << endl;
        cout << "BIENVENIDOS " << endl;
        cout << endl << endl;
        // Imprimir la palabra "MOTORIN" en colores
        printInColor("M   M   OOO   TTTTT  OOO   RRRR   II   N   N\n", 31); // Rojo
        printInColor("MM MM  O   O    T   O   O  R   R  II   NN  N\n", 32); // Verde
        printInColor("M M M  O   O    T   O   O  RRRR   II   N N N\n", 33); // Amarillo
        printInColor("M   M  O   O    T   O   O  R  R   II   N  NN\n", 34); // Azul
        printInColor("M   M   OOO     T    OOO   R   R  II   N   N\n", 35); // Morado

        cout << endl << endl;

        cout << "MENU" << endl;
        cout << "1. Mostrar datos de los productos" << endl;
        cout << "2. Mostrar datos de los servicios y empleados" << endl;
        cout << "3. Mostrar datos de los clientes" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            //los datos capturados se muestran en el archivo txt
            imprimirDatosRepuestos(archivo);
            break;
        case 2:
            obtenerDatosServicios(archivo);
            break;
        case 3:
            obtenerDatosClientes(archivo);
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
            break;
        }

        cout << endl;
      //el bucle se repetira hasta mientras el numero sea diferente de las opciones
    } while (opcion != 4);

    archivo.close(); // Cierra el archivo

    return 0;
}
