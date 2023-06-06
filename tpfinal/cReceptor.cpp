#include"cReceptor.h"

cReceptor::cReceptor(string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_recibe,tm fecha_agregado_espera, unsigned int prioridad , estado estado_pac) :cPaciente(nombre, fechanac, sexo, peso, tipos_sangre, centro_salud,rh, fluido_elegido) {
	*this->fecha_agregado_espera = fecha_agregado_espera;
	this->prioridad = prioridad;
	this->estado_pac = estado_pac;
}
void cReceptor::setFluido(string& fluido_elegido) {//el get esta en cPaciente
	this->fluido_elegido = fluido_elegido;
}
void cReceptor::set_prioridad(unsigned int &prioridad) {
	this->prioridad = prioridad;
}
unsigned int cReceptor::get_prioridad() {
	return this->prioridad;
}
enum class cReceptor::estado cReceptor::get_estado() {
	return this->estado_pac;
}
void cReceptor::set_fecha_agregado_espera(tm fecha_agregado_espera) {
	*this->fecha_agregado_espera = fecha_agregado_espera;
}
tm cReceptor::get_fecha_agregado_espera() {
return *this->fecha_agregado_espera;
}
cReceptor::~cReceptor(){
}