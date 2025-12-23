/*
 * Nombres-Apellidos: Victor Andres Maldonado Arias
 * Cedula: 32372568
 * Seccion: 7
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre, nombre_mayor_edad;
    char genero, genero_mayor_edad, respuesta_continuar_registro;
    int edad,vacunado, personas_vacunadas = 0 , contador_hombres = 0, persona_mayor_edad = -1;
    float promedio, acumulador_edades = 0;
    bool esta_vacunado, continuar_registro = true;


    while (continuar_registro) {
        cout<<"Ingrese el nombre de la persona a registrar:"<<endl;
        cin>>nombre;
        cout<<"Ingrese la edad de la persona a registrar:"<<endl;
        cin>>edad;
        cout<<"Ingrese el genero de la persona a registrar: ('M' Para Hombre y 'F' para mujer)"<<endl;
        cin>>genero;
        cout<<"La persona a registrar se encuentra vacunada: (1 para Si y 0 para No)"<<endl;
        cin>>vacunado;

        if (vacunado == 1) {
            esta_vacunado = true;
        }
        else {
            esta_vacunado = false;
        }

        if (esta_vacunado) {
            personas_vacunadas++;
        }

        if ((genero == 'M'||genero== 'm') && edad > 25 ) {
            contador_hombres++;
            acumulador_edades += edad;
        }

        if (edad > persona_mayor_edad && esta_vacunado) {
            nombre_mayor_edad = nombre;
            persona_mayor_edad = edad;
            genero_mayor_edad = genero;
        }

        cout<<"Desea Registrar otra persona: ('S' para continuar' y 'N' para salir)"<<endl;
        cin>>respuesta_continuar_registro;

        if (respuesta_continuar_registro == 'N' || respuesta_continuar_registro == 'n') {
            continuar_registro = false;
        }

    }

    cout << "Total de personas vacunadas: "<< personas_vacunadas << endl;
    if (contador_hombres > 0) {
        promedio = acumulador_edades/contador_hombres;
        cout << "Promedio de edad de personas mayores a 25 años de genero masculino: " << promedio << " años de edad" << endl;
    }

    cout << "Datos de la persona vacunada de mayor edad:" << endl;
    cout << nombre_mayor_edad << endl;
    cout << "edad: " << persona_mayor_edad << endl;
    if (genero_mayor_edad == 'M'|| genero_mayor_edad == 'm') {
        cout << "Genero: Masculino" << endl;
    }
    else {
        cout << "Genero: Femenino" << endl;
    }

    return 0;
}