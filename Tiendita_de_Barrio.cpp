#include <iostream>
using namespace std;

int menu;
int cantidad;
double precio;
double subtotal;
double Descuento;
double IVA;
double Cambio;
double Total;
double Pago;
double total_vendido;
double venta_mayor;
double venta_menor;
double total_descuentos;
int contador_ventas;
double promediov;


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
                contador_ventas = contador_ventas + 1;
                total_vendido = total_vendido + Total;
                total_descuentos = total_descuentos + Descuento;
                if (contador_ventas == 1)
                {
                    venta_menor = Total;
                    venta_mayor = Total;
                }
                else 
                {
                    if (venta_mayor < Total)
                    {
                        venta_mayor = Total; 
                    }
                    if (venta_menor > Total)
                    {
                        venta_menor = Total;
                    }
                }
            }
            else 
            {
                cout << "No se registraron ventas \n";
            }
            
                break;
            }
            case 2:
            {
                if (contador_ventas > 0)
                {
                    promediov = total_vendido / contador_ventas;
                    cout << "Ventas hechas en el dia: \n" << contador_ventas << "\n";
                    cout << "Total vendido en el dia: \n" << total_vendido << "\n";
                    cout << "Venta mayor del dia: \n" << venta_mayor <<  "\n";
                    cout << "Venta menor del dia: \n" << venta_menor << "\n";
                    cout << "Promedio por venta: \n" << promediov << "\n";
                    cout << "Descuentos totales aplicados: \n" << total_descuentos << "\n";
                } 
                else 
                {
                    cout << "No se han registrado ventas \n";
                }
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