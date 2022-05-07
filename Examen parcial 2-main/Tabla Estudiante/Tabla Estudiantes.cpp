#include <iostream>
#include <string>
#include"Estudinate.h"
using namespace std;

int main() {
	
    int selec = 0, bus = 0, id = 0, tel=0, gen=0;
    char op = 's';
    string car, nom, ap, dir, em, fec;

    do {
        system("cls");
        cout << "   Estudiantes" << endl;
        cout << "___________________________________________________________" << endl;
        cout << "     1. AGREGAR UN NUEVO ESTUDIANTE" << endl;
        cout << "     2. CONSULTAR BASE DE DATOS" << endl;
        cout << "     3. EDITAR DATOS DEL ESTUDIANTE" << endl;
        cout << "     4. ELIMINAR ESTUDIANTE" << endl;
        cout << "     0. SALIR" << endl;
        cin >> selec;
        cin.ignore();

        if (selec == 1) {
            char op = 's';
            system("cls");

            do {

                cout << "AGREGAR DATOS DEL ESTUDIANTE " << endl;
                cout << " INGRESE NUMERO CARNET:                ";
                getline(cin, car);
                cout << " INGRESE EL NOMBRE:               ";
                getline(cin, nom);
                cout << " INGRESE EL APELLIDO:             ";
                getline(cin, ap);
                cout << " INGRESE LA DIRECCION:             ";
                getline(cin, dir);
                cout << " INGRESE NUMERO TELEFONICO:    ";
                cin >> tel;
                cin.ignore();
                cout << " SELECCIONE GENERO( 0: Femenino / 1: Masculino):   ";
                cin>> gen;
                cin.ignore();
                cout << " INGRESE CORRREO ELECTRONICO:                 ";
                getline(cin, em);
                cout << " INGRESE FECHA DE NACIMIENTO:   ";
                getline(cin, fec);

                Estudiante es = Estudiante(car, nom, ap, dir, tel, gen, em, fec, bus, id);
                es.crear();
                cout << endl << "DESEA INGRESAR OTRO ESTUDIANTE (s/n):  ";
                cin >> op;
                cin.ignore();
            } while (op == 's' || op == 'S');
        }

        else if (selec == 2) {

            Estudiante es = Estudiante();
            es.leer();

            system("pause");
        }

        else if (selec == 3) {
            system("cls");
            char b = 's';
            

            do {
            cout << " INGRESE EL CODIGO DEL ESTUDIANTE A MODIFICAR:   ";
            cin >> id;

            Estudiante es = Estudiante(car,nom,ap,dir,tel,gen,em,fec,bus,id);
            es.actualizar();

            system("cls");
            cout << "MODIFICAR OTRO ESTUDIANTE (y/n): ";
            cin >> b;
            cin.ignore();

            } while (b == 'y' || b == 'Y');

        }

        else if (selec == 4) {

            system("cls");
            cout << "INGRESE EL ID DEL ESTUDIANTE QUE DESEA ELIMINAR: ";
            cin >> id;
            cin.ignore();

            Estudiante es = Estudiante(car, nom, ap, dir, tel, gen, em, fec, bus, id);
            es.eliminar();
            system("pause");

        }


    } while (selec != 0);
	



	return 0;
}