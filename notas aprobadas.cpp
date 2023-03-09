#include<iostream>
using namespace std;
float calcular_prom(float not1, float not2, float not3)
{
	int prom = 0;
	prom= (not1+not2+not3)/3;
	return prom;
}
int main()
{
    float not1 = 0, not2 = 0, not3 = 0;
	int valor ,prom = 0;
    cout << "ingrese sus notas " << endl;
	cin >> not1 ;
	cin >> not2 ;
	cin >> not3 ;
	prom = calcular_prom( not1, not2, not3);
    if(prom>=18){valor = 1;}

    if(prom <18 & prom >15){valor = 2;}

    if(prom < 15 & prom > 11){; valor = 3;}

    if(prom  < 11 & prom > 5){; valor = 4;}

    if(prom < 5){ valor = 5;}

    switch(valor)
    {
        case 1:
        cout << prom << endl;
        cout <<"A"; break;

        case 2:
        cout << prom << endl;
        cout <<"B"; break;

        case 3:
        cout << prom << endl;
        cout <<"C"; break;

        case 4:
        cout << prom << endl;
        cout <<"F"; break;
        
        case 5:
        cout << prom << endl;
        cout <<"ERES MUY MALO "; break;
    }

    return 0;
}