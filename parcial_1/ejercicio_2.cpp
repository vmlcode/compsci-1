/*
* Nombres-Apellidos: Victor Andres Maldonado Arias
 * Cedula: 32372568
 * Seccion: 7
 */

#include <iostream>

#define GALPONES 10
#define MAX_POLLOS_POR_GALPON 50
#define MAX_VIDA_POLLO 90

using namespace std;

int main() {
    //Por Galpon
    int identificador_galpon, area_galpon, // Area es M^2
        identificador_menos_pollos , contador_pollos_jovenes,
        edad_minima_pollos = 1000;
    // Por Pollo
    int peso, edad_pollo_en_dias, pollos_marrones_limite_peso_tiempo = 0,
            pollos_blancos = 0, sum_edad_pollos_blancos = 0, sum_area_galpon = 0,
            menor_cantidad_pollos = 1000;
    char color_pollo, continuar_respuesta;
    bool continuar_registro = true;

    for (int i = 0, contador_pollos = 0; i < GALPONES; i++) {
        contador_pollos = 0;
        continuar_registro = true;
        contador_pollos_jovenes = 0;
        edad_minima_pollos = 1000;

        cout << "Registre el numero de identificacion del galpon: " << endl;
        cin >> identificador_galpon;

        cout << "Registre el numero de metros cuadrados que posee el galpon: " << endl;
        cin >> area_galpon;

        sum_area_galpon += area_galpon;

        while (continuar_registro && contador_pollos < MAX_POLLOS_POR_GALPON) {
            cout << "Galpon: " << identificador_galpon << " Pollo Numero: " << contador_pollos + 1 << endl;
            cout << "Ingrese el peso del pollo en KG: " << endl;
            cin >> peso;
            cout << "Ingrese la edad del pollo en dias: " << endl;
            cin >> edad_pollo_en_dias;
            while (edad_pollo_en_dias > MAX_VIDA_POLLO) {
                cout << "El pollo no puede tener mas de 90 dias en el galpon!" << endl;
                cout << "Ingrese la edad del pollo en dias: " << endl;
                cin >> edad_pollo_en_dias;
            }

            do {
                cout << "Ingrese el color del pollo: ('B' para blanco y 'M' para marron):" << endl;
                cin >> color_pollo;
            } while ((color_pollo != 'B' && color_pollo != 'b') && (color_pollo != 'M' && color_pollo != 'm'));

            contador_pollos++;

            if (peso > 2 && (MAX_VIDA_POLLO - edad_pollo_en_dias < 30) && (color_pollo == 'M' || color_pollo == 'm')) {
                pollos_marrones_limite_peso_tiempo++;
            }

            if (color_pollo == 'B' || color_pollo == 'b') {
                pollos_blancos++;
                sum_edad_pollos_blancos += edad_pollo_en_dias;
            }

            if (edad_pollo_en_dias < edad_minima_pollos) {
                edad_minima_pollos = edad_pollo_en_dias;
                contador_pollos_jovenes = 1;
            }
            else if (edad_minima_pollos == edad_pollo_en_dias) {
                contador_pollos_jovenes++;
            }

            cout << "Desea registrar otro pollo: (Presione 'N' para finalizar y cualquier otra tecla para continuar)" <<endl;
            cin >> continuar_respuesta;
            if (continuar_respuesta == 'N' || continuar_respuesta == 'n') {
                continuar_registro = false;
            }
        }

        if (contador_pollos < menor_cantidad_pollos) {
            identificador_menos_pollos = identificador_galpon;
            menor_cantidad_pollos = contador_pollos;
        }

        cout <<"Galpon " << identificador_galpon<< ": " << endl;
        cout<<"Pollos con menor tiempo de haber nacido: " << contador_pollos_jovenes << endl;

    }

    cout << "Resultados" << endl;
    cout << "Cantidad de Pollos marrones con menos de 30 dias para salir del galpon y que pese mas de 2KG: " <<
            pollos_marrones_limite_peso_tiempo << endl;
    if (pollos_blancos > 0) {
        cout << "Promedio de edad de los pollos de color blanco: " << (float) sum_edad_pollos_blancos / pollos_blancos <<endl;
    }
    else {
        cout << "No se registraron pollos de color blanco"<<endl;
    }
    cout << "Promedio de metros cuadrados que ocupan los galpones: " << (float) sum_area_galpon / GALPONES <<"m^2" << endl;
    cout << "Identificador del galpon con menos pollos albergados: " << identificador_menos_pollos << endl;
}