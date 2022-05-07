#include<iostream>
#include<string>
#include<mysql.h>
#include<sstream>
#include "Persona.h"
#include "conector.h"
using namespace std;

class Estudiante :Persona {

protected: int buscar = 0, idestudiante = 0;

public:
	Estudiante() {}

	Estudiante(string car, string nom, string ap, string dir, int tel, int gen, string em, string fec, int bus, int id) : Persona(car, nom, ap, dir, tel, gen, em, fec) {

		buscar = bus;
		idestudiante = id;
	}

	void setId(int id) { idestudiante = id; }
	void setCarnet(string car) { carnet = car; }
	void setNombre(string nom) { nombres = nom; }
	void setApellido(string ap) { apellidos = ap; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(int gen) { genero = gen; }
	void setEmail(string em) { email = em;}
	void setFechaNac(string fec) { fechanac = fec; }
	void setBuscar(int bus) { buscar = bus; }
	
	int getId() { return idestudiante; }
	string getCarnet() { return carnet; }
	string getNombre() { return nombres; }
	string getApellido() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	int getGenero() { return genero; }
	string getEmail() { return email; }
	string getFechaNac() { return fechanac; }
	int getBuscar() { return buscar; }



	void crear() {
		int q_estado;

		Conector cn = Conector();

		cn.abrir_coneccion();

		if (cn.getConectar()) {
			system("cls");

			string tel = to_string(telefono);
			string gen = to_string(genero);

			string insert="INSERT INTO escuela.estudiante(carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento) VALUES ('"+carnet+"','"+nombres+"','"+apellidos+"','"+direccion+"',"+tel+","+gen+",'"+email+"','"+fechanac+"')"; 
			const char* i = insert.c_str();

			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}

		}
		else {
			system("cls");
			cout << "****** ERROR DE CONECCION *******" << endl;
		}
	}

	void leer() {

		int q_estado;
		Conector cn = Conector();

		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;

		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM escuela.estudiante";
			const char* i = consulta.c_str();

			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());
				cout << "  ************* BASE DE DATOS ESTUDIANTES ****************" << endl;
				cout << "ID    |  CARNET  |     NOMBRES   |      APELLIDOS    |       DIRECCION		| TELEFONO	| GENERO |    EMAIL		| FECHA DE NACIMIENTO |" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << " " << fila[0] << " " << fila[1] << " " << fila[2] << " " << fila[3] << " " << fila[4] << " " << fila[5] << " " << fila[6] << " " << fila[7] << " " << fila[8] << endl;
				}

			}
			else {
				system("cls");
				cout << "****** ERROR DE CONECCION *******" << endl;
			}


		}
		else {
			system("cls");
			cout << "****** ERROR DE CONECCION *******" << endl;
		}

	}

	void actualizar() {

		int q_estado;
		int men = 0;
		Conector cn = Conector();

		cn.abrir_coneccion();

		if (cn.getConectar()) {
			
			string id = to_string(idestudiante);


			system("cls");
			cout << "   ********** MENU ACTUALIZAR ********** " << endl;
			cout << " 1. CARNET DEL ESTUDIANTE " << endl;
			cout << " 2. NOMBRES DEL ESTUDIANTE" << endl;
			cout << " 3. APELLIDOS DEL ESTUDIANTE" << endl;
			cout << " 4. DIRECCION DEL ESTUDIANTE" << endl;
			cout << " 5. TELEFONO DEL ESTUDIANTE" << endl;
			cout << " 6. GENERO DEL ESTUDIANTE" << endl;
			cout << " 7. EMAIL DEL ESTUDIANTE" << endl;
			cout << " 8. FECHA DE NACIMIENTO DEL ESTUDIANTE" << endl;
			cout << " 9. MODIFICAR TODOS LOS CAMPOS" << endl;
			cout << " QUE CAMPO DESEA MODIFICAR:  ";
			cin >> men;
			cin.ignore();
			system("cls");
			cout << "******* MENU ACTUALIZACION **************" << endl;

			if (men == 1) {

				cout << " INGRESE CARNET:   ";
				getline(cin, carnet);

				string update = "UPDATE escuela.estudiante SET carnet = '" + carnet + "' WHERE(idEstudiante= "+id+")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				
				if (!q_estado) {

					cout << "INGRESADO CON EXITO .... \n";

				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}

			}
			else if (men == 2) {

				cout << "INGRESE NOMBRE:   ";
				getline(cin, nombres);

				string update = "UPDATE escuela.estudiante SET nombres= '" + nombres + "' WHERE(idEstudiante="+id+");";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {

					cout << "INGRESADO CON EXITO .... \n";

				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}

			}

			else if (men == 3) {

				cout << "INGRESE APELLIDOS:   ";
				getline(cin, apellidos);

				string update = "UPDATE escuela.estudiante SET apellidos= '" + apellidos + "' WHERE(idEstudiante=" + id + ");";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {

					cout << "INGRESADO CON EXITO .... \n";

				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}

			}
			else if (men == 4) {

				cout << "INGRESE DIRECCION:   ";
				getline(cin, direccion);

				string update = "UPDATE escuela.estudiante SET direccion= '" + direccion + "' WHERE(idEstudiante=" + id + ");";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {

					cout << "INGRESADO CON EXITO .... \n";

				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}

			}
			else if (men == 5) {

				cout << "INGRESE TELEFONO:   ";
				cin >> telefono;
				cin.ignore();
				string tel = to_string(telefono);
				string update = "UPDATE escuela.estudiante SET telefono= " + tel + " WHERE(idEstudiante=" + id + ");";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {

					cout << "INGRESADO CON EXITO .... \n";

				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}

			}
			else if (men == 6) {

				cout << "INGRESE GENERO:   ";
				cin>> genero;
				cin.ignore();

				string gen = to_string(genero);

				string update = "UPDATE escuela.estudiante SET genero= " + gen + " WHERE(idEstudiante=" + id + ");";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);

				if (!q_estado) {

					cout << "INGRESADO CON EXITO .... \n";

				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}

			}

			else if (men == 7) {

			cout << "INGRESE EMAIL:   ";
			getline(cin, email);

			string update = "UPDATE escuela.estudiante SET email= '" + email + "' WHERE(idEstudiante=" + id + ");";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}

			}
			else if (men == 8) {

			cout << "INGRESE FECHA DE NACIMIENTO (AAAA-MM-DD):   ";
			getline(cin, fechanac);

			string update = "UPDATE escuela.estudiante SET fecha_nacimiento= '" + fechanac + "' WHERE(idEstudiante=" + id + ");";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}

			}
			else if (men == 9) {

			cout << "************* DATOS DEL ESTUDIANTE ***************" << endl;
			cout << " INGRESE CARNET:                ";
			getline(cin, carnet);
			cout << " INGRESE NOMBRES:               ";
			getline(cin, nombres);
			cout << " INGRESE APELLIDOS:             ";
			getline(cin, apellidos);
			cout << " INGRESE DIRECCION:             ";
			getline(cin, direccion);
			cout << " INGRESE NUMERO DE TELEFONO:    ";
			cin >> telefono;
			cin.ignore();
			cout << " INGRESE GENERO( 0: Femenino / 1: Masculino):    ";
			cin >> genero;
			cin.ignore();
			cout << " INGRESE EMAIL:                 ";
			getline(cin, email);
			cout << " INGRESE FECHA DE NACIMIENTO (AAAA-MM-DD):   ";
			getline(cin, fechanac);

			string tel = to_string(telefono);
			string gen = to_string(genero);


			string update = "UPDATE escuela.estudiante SET carnet='"+carnet+"', nombres= '" + nombres + "', apellidos='"+apellidos+"', direccion='"+direccion+"', telefono="+tel+", genero="+gen+", email='"+email+"', fecha_nacimiento='"+fechanac+"'        WHERE(idEstudiante=" + id + ")";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}

			}




		}
		else {
			system("cls");
			cout << "****** ERROR DE CONECCION *******" << endl;
		}

		system("pause");
	}

	void eliminar() {

		int q_estado, q_stado;
		int c = 1, r = 0, im = 0;
		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;

		cn.abrir_coneccion();
		string id = to_string(idestudiante); 
		if (cn.getConectar()) {

			string delite = "DELETE FROM escuela.estudiante WHERE idEstudiante= " + id + "";

			const char* i = delite.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";


				string consulta = "SELECT * FROM escuela.estudiante";
				const char* j = consulta.c_str();
				q_stado = mysql_query(cn.getConectar(), j);
				string cc = to_string(c);
				if (!q_stado) {
					resultado = mysql_store_result(cn.getConectar());

					while (fila = mysql_fetch_row(resultado)) {

						string imm = to_string(im);
						imm = fila[0];
						istringstream(imm) >> im;
						int ii = idestudiante;

						if (c == im) {
							c++;
							cc = to_string(c);
						}
						else {
							r = im - 1;
							string rr = to_string(r);
							string mod = "UPDATE escuela.estudiante SET idEstudiante = " + rr + " WHERE(idEstudiante = " + imm + ")";
							const char* m = mod.c_str();
							q_stado = mysql_query(cn.getConectar(), m);

							c++;
							cc = to_string(c);

						}

					}
					
					string auto_inc = "alter table estudiante auto_increment = " + cc + "";
					const char* a = auto_inc.c_str();
					q_stado = mysql_query(cn.getConectar(), a);
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccion();


	}



};

