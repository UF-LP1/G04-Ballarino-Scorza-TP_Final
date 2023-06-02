#include "cPaciente.h"

cPaciente::cPaciente(string nombre, ctime fechanac,char sexo, string peso, string tipos_sangre,string centro_salud) {
	this->nombre = nombre;
	this->sexo = sexo;
	this->peso = peso;
	this->tipos_sangre = tipos_sangre;
	this->centro_salud = centro_salud;
}
cPaciente::~cPaciente(){
}