#include "cPaciente.h"

cPaciente::cPaciente(string nombre,  tm fechanac,char sexo, string peso, string tipos_sangre,string centro_salud) {
	this->nombre = nombre;
	this->fechanac = fechanac;
	this->sexo = sexo;
	this->peso = peso;
	this->tipos_sangre = tipos_sangre;
	this->centro_salud = centro_salud;
}
cPaciente::~cPaciente(){
}