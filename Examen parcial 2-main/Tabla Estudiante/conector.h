#include<iostream>
#include<mysql.h>
#include<string>

using namespace std;

class Conector {

private: MYSQL* conectar;

public:

	void abrir_coneccion() {

		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "Morataya22", "escuela", 3306, NULL, 0);
	}
	MYSQL* getConectar() { return conectar; }

	void cerrar_coneccion() {
		mysql_close(conectar);
	}


};

