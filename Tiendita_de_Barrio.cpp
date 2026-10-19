#include <iostream>
using namespace std;

int menu;
int contador_ventas;
int cantidad;
float precio;
float resumen_precio;
float subtotal;
int main ()
{

do 
{
cout << "\nBuen dia, Que desea hacer? \n";   
cout << "1. Registrar Venta\n";
cout << "2. Ver resumen parcial del dia\n";
cout << "3. Cerrar caja y salir\n";
cin >> menu;
switch (menu) 
{
    case 1:
    {
        subtotal = 0;
        do {
        cout << "Ingrese el precio del producto o 0 para terminar: ";
        cin >> precio;
        if (precio < 0) 
        {
            cout <<"Error, ingrese un precio valido\n";
        }
        else 
        {
            if (precio > 0)
            {
               
                resumen_precio = resumen_precio + precio;
                cout << "Ingrese la cantidad del producto: ";
                cin >> cantidad;
                while (cantidad <1 || cantidad > 100)
                {
                    cout << "Error, la cantidad debe ser de 1 a 100\n";
                    cout << "Ingrese la cantidad del producto: ";
                    cin >> cantidad;
                }
                subtotal = subtotal + precio *cantidad ;
                cout << "El subtotal es: " << subtotal << "\n";
            
            }
        }
            }
            while (precio != 0);
        break;
        }

    case 2:
    {
        cout <<"Resumen parcial de ventas: \n";
        cout << "Precio del producto: " << resumen_precio << "\n";
        cout << "Cantidad del producto: " << cantidad << "\n";
        cout << "Subtotal vendido: " << subtotal << "\n";
        break;
    }
    case 3:
    {
        cout <<"Nos vemos";
        break;
    }

    default: 
    {
    cout << "Error, Elija una opcion de menu valida\n";
    break;
    }       
    }
}
while (menu != 3);
return 0;
}