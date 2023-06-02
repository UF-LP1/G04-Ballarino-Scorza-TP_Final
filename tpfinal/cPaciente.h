#pragma once
#include <string>
#include<iostream>
using namespace std;

class cPaciente {
protected:
	string nombre;
	ctime fechanac;
	char sexo;
	string peso;
	string tipos_sangre;
	string centro_salud;
public:
	cPaciente(string nombre, ctime fechanac, char sexo, string peso, string tipos_sangre, string centro_salud);
	~cPaciente();
};
