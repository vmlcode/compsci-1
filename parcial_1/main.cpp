/*
 * Nombres-Apellidos: Victor Andres Maldonado Arias
 * Cedula: 32372568
 * Seccion: 7
 */

#include <iostream>
using namespace std;

int main() {
    string nombre, nombre_mayor_edad;
    char genero, vacunado, genero_mayor_edad, respuesta_continuar_registro;
    int edad, personas_vacunadas = 0 , acumulador_edades = 0, contador_hombres = 0, persona_mayor_edad = -1;
    bool esta_vacunado, continuar_registro = true, vacunado_mayor_edad;


    while (continuar_registro) {
        cout<<"Ingrese el nombre de la persona a registrar:"<<endl;
        cin>>nombre;
        cout<<"Ingrese la edad de la persona a registrar:"<<endl;
        cin>>edad;
        cout<<"Ingrese el genero de la persona a registrar: ('M' Para Hombre y 'F' para mujer)"<<endl;
        cin>>genero;
        cout<<"La persona a registrar se encuentra vacunada: ('S' para Si y 'N' para No)"<<endl;
        cin>>vacunado;

        if (vacunado == 'S') {
            esta_vacunado = true;
        }
        else {
            esta_vacunado = false;
        }

        if (esta_vacunado) {
            personas_vacunadas++;
        }

        if (genero == 'M' && edad > 25 ) {
            contador_hombres++;
            acumulador_edades += edad;
        }

        if (edad > persona_mayor_edad && esta_vacunado) {
            nombre_mayor_edad = nombre;
            persona_mayor_edad = edad;
            genero_mayor_edad = genero;
            vacunado_mayor_edad = esta_vacunado;
        }

        cout<<"Desea Registrar otra persona: ('S para continuar' y 'N' para salir)"<<endl;
        cin>>respuesta_continuar_registro;

        if (respuesta_continuar_registro == 'N') {
            continuar_registro = false;
        }

    }

    cout << "Se han vacunado: "<< personas_vacunadas <<" Personas"<< endl;
    if (contador_hombres > 0) {
        cout << "Promedio de personas mayores a 25 años de genero masculino: " << (acumulador_edades/contador_hombres) << "Años de edad" << endl;
    }

    cout << "Datos de la persona de mayor edad:" << endl;
    cout << nombre_mayor_edad << endl;


}