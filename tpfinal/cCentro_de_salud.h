#pragma once
#include <string>
#include<iostream>
using namespace std;

class cCentro_de_Salud {
private:
	string nombre;
	string partido;
	string provincia;
	string direccion;
	string telefono;
public:
	cCentro_de_Salud(string nombre, string partido, string provincia, string direccion, string telefono);
	~cCentro_de_Salud();
};
