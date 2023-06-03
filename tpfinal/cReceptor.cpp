#include"cReceptor.h"

cReceptor::cReceptor(string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_recibe,tm fecha_agregado_espera, unsigned int prioridad , estado estado_pac) :cPaciente(nombre, fechanac, sexo, peso, tipos_sangre, centro_salud,rh, fluido_elegido) {
	this->fecha_agregado_espera = fecha_agregado_espera;
	this->prioridad = prioridad;
	this->estado_pac = estado_pac;
}
void cReceptor::setFluido(string& fluido_elegido) {
	this->fluido_elegido = fluido_elegido;
}
cReceptor::~cReceptor(){
}