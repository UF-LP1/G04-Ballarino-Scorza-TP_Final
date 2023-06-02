#pragma once
#include <string>
#include<iostream>
#include <ctime>
using namespace std;

class cPaciente {
protected:
	string nombre;
	tm fechanac;
	char sexo;
	string peso;
	string tipos_sangre;
	string centro_salud;
public:
	cPaciente(string nombre,tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud);
	~cPaciente();
};
