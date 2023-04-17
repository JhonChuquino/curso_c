//  05/03/2023
//HACER UN PROGRAMA QUE QUE TE MUESTRE EL MES DEL AÑO SEGUN EL NUMERO QUE INGRESE EL USUARIO

#include<iostream>
using namespace std; // nos permite usar el cin y cout.
int main()
{
int num_mes;
cout << "ingrese un numero";
cin >> num_mes; // capturando el primer dato

switch(num_mes){ // condicinal para analizar varios casos posibles
    case 1:
    cout<<"ENERO"; break; // para que ya no siga comporando los demas caso si es true
    case 2:
    cout<<"FEBRERO"; break;// para que ya no siga comporando los demas caso si es true
    case 3:
    cout<<"MARZO"; break; // para que ya no siga comporando los demas caso si es true
    case 4:
    cout<<"ABRIL"; break; // para que ya no siga comporando los demas caso si es true
    case 5:
    cout<<"MAYO"; break; // para que ya no siga comporando los demas caso si es true
    case 6:
    cout<<"JUNIO"; break; // para que ya no siga comporando los demas caso si es true
    case 7:
    cout<<"JULIO"; break; // para que ya no siga comporando los demas caso si es true
    case 8:
    cout<<"AGOSTO"; break; // para que ya no siga comporando los demas caso si es true
    case 9:
    cout<<"SETIEMBRE"; break; // para que ya no siga comporando los demas caso si es true
    case 10:
    cout<<"OCTUBRE"; break; // para que ya no siga comporando los demas caso si es true
    case 11:
    cout<<"NOVIEMBRE"; break; // para que ya no siga comporando los demas caso si es true
    case 12:
    cout<<"DICIEMBRE"; break; // para que ya no siga comporando los demas caso si es true

    default: cout << "valor incorrecto"; // caso que no se cumplan los casos.

}

return 0;
}
