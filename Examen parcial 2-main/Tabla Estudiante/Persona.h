#include<iostream>
using namespace std;

class Persona{

protected: string carnet, nombres, apellidos, direccion, email, fechanac;
		   int telefono, genero;

protected: 
	Persona(){}
	Persona(string car, string nom, string ap, string dir, int tel, int gen, string em, string fec) { 
	
		carnet = car;
		nombres = nom;
		apellidos = ap;
		direccion = dir;
		telefono = tel;
		genero = gen;
		email = em;
		fechanac = fec;
	
	}

};

