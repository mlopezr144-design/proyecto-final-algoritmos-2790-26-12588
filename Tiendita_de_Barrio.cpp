#include <iostream>
using namespace std;

int menu;
int contador_ventas;
int cantidad;
float precio;
float resumen_precio;
float subtotal;
float Descuento;
float IVA;
float Cambio;
float Total;
float Pago;

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
                do
                {
                    cout << "Ingrese el precio del producto o 0 para terminar: ";
                    cin >> precio;
                    if (precio < 0)
                    {
                        cout << "Error, ingrese un precio valido\n";
                    }
                    else
                    {
                        if (precio > 0)
                        {
                            resumen_precio = resumen_precio + precio;
                            cout << "Ingrese la cantidad del producto: ";
                            cin >> cantidad;
                            while (cantidad < 1 || cantidad > 100)
                            {
                                cout << "Error, la cantidad debe ser de 1 a 100\n";
                                cout << "Ingrese la cantidad del producto: ";
                                cin >> cantidad;
                            }
                            subtotal = subtotal + precio * cantidad;
                            cout << "El subtotal es: " << subtotal << "\n";
                        }
                    }
                }
                while (precio != 0);

                if (subtotal > 0)
                {

                Descuento = 0;
                if (subtotal >= 100 && subtotal < 500)
                {
                    Descuento = subtotal * 0.05;
                }
                else if (subtotal >= 500)
                {
                    Descuento = subtotal * 0.10;
                }
                subtotal = subtotal - Descuento;
                IVA = subtotal * 0.12;
                Total = subtotal + IVA;
                cout << "El total de la compra es: " << Total << "\n";

                do
                {
                    cout << "Ingrese el pago hecho por el cliente: ";
                    cin >> Pago;
                    if (Pago < Total)
                    {
                        cout << "Ingrese el monto correcto a pagar" << "\n";
                    }
                }
                while (Pago < Total);

                Cambio = Pago - Total;

                cout << "RECIBO\n";
                cout << "Subtotal: " << subtotal + Descuento << "\n";
                cout << "Descuento: " << Descuento << "\n";
                cout << "Subtotal con descuento: " << subtotal << "\n";
                cout << "IVA (12%): " << IVA << "\n";
                cout << "Total: " << Total << "\n";
                cout << "Pago: " << Pago << "\n";
                cout << "Cambio: " << Cambio << "\n";
                cout << "Gracias por su compra" << "\n";
            }
            else 
            {
                cout << "No se registraron ventas \n";
            }
            
                break;
            }
            case 2:
            {
                cout << "Resumen parcial de ventas: \n";
                cout << "Precio del producto: " << resumen_precio << "\n";
                cout << "Cantidad del producto: " << cantidad << "\n";
                cout << "Subtotal vendido: " << subtotal << "\n";
                break;
            }
            case 3:
            {
                cout << "Nos vemos";
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