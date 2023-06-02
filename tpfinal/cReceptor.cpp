#include"cReceptor.h"

cReceptor::cReceptor(string nombre, ctime fechanac, char sexo, string peso, string tipos_sangre, string centro_salud,ctime fecha_agregado_espera, undigned int prioridad , estado estado_pac) :cPaciente(nombre, fechanac, sexo, peso, tipos_sangre, centro_salud) {
	this->prioridad = prioridad;
	this->estado_pac = estado_pac;
}
cReceptor::cReceptor(){}