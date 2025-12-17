/*
 * Nombres-Apellidos: Victor Andres Maldonado Arias
 * Cedula: 32372568
 * Seccion: 7
*/

#include <iostream>
#define MAX_ESTUDIANTES 1000

using namespace std;

int main() {

    int num_estudiantes = 0;
    int genero_receptor;

    string nombre_profesor, apellido_profesor, nombre_estudiante;

    char genero_estudiante, tipo_regalo, opcion_continuar;
    bool registrar_siguiente = true;
    bool es_prof_jhonny;

    int regalos_nuevos_hombres_ninos = 0;
    int regalos_prof_jhonny_mujer_ninas = 0;

    while (num_estudiantes <= MAX_ESTUDIANTES && registrar_siguiente == true) {
        cout << "1. Ingrese el Nombre del Estudiante:" << endl;
        cin>>nombre_estudiante;

        cout << "2. Ingrese el Genero del estudiante: (M para Hombre y F para Mujer)"<< endl;
        cin>>genero_estudiante;

        cout << "3. Ingrese el Nombre y Apellido del Profesor al que el alumno representa en la entrega del regalo: (Debe ingresar el nombre y el apellido)" << endl;
        cin >> nombre_profesor >> apellido_profesor;

        cout << "4. Ingrese el tipo de regalo que el estudiante entregara: ('N' para regalos nuevos y 'U' para regalos usados)" << endl;
        cin >> tipo_regalo;

        cout << "5. Ingrese el genero de la persona que deberia recibir el regalo: ('1' para regalos de Niño y '2' para regalos de Niña)"<< endl;
        cin >> genero_receptor;

        if (num_estudiantes<MAX_ESTUDIANTES) {
            cout << "6. ¿Desea registrar otro regalo? ('S' para continuar y 'N' para finalizar)" << endl;
            cin >> opcion_continuar;
        }

        if ((genero_estudiante == 'M' || genero_estudiante == 'm') &&
            (tipo_regalo == 'N' || tipo_regalo == 'n') && (genero_receptor == 1)) {
            regalos_nuevos_hombres_ninos++;
        }

        es_prof_jhonny = (nombre_profesor == "Jhonny" || nombre_profesor ==  "jhonny") && (apellido_profesor == "Zambrano" || apellido_profesor == "zambrano");

        if ((genero_estudiante == 'F' || genero_estudiante == 'f') && es_prof_jhonny && (genero_receptor == 2)) {
            regalos_prof_jhonny_mujer_ninas++;
        }

        if (opcion_continuar == 'N' || opcion_continuar == 'n') {
            registrar_siguiente = false;
        }

        num_estudiantes++;
    }

    cout << "Resultados:" << endl;

    if (num_estudiantes>0) {
        cout<<"1. Total de estudiantes Hombres que entregaron regalos nuevos para niños: "<< regalos_nuevos_hombres_ninos << endl;
        cout<<"2. Porcentaje total de regalos para niñas que han entregado damas y son alumnas del profesor Jhonny Zambrano: "<< ((regalos_prof_jhonny_mujer_ninas * 100.00)/ num_estudiantes) <<"%" << endl;
    }

}
