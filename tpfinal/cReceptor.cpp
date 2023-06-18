#include"cReceptor.h"

cReceptor::cReceptor(const string id,string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_recibe, string partido, string provincia,tm fecha_agregado_espera, unsigned int prioridad , estado estado_pac) :cPaciente(id, nombre, fechanac, sexo, peso, tipos_sangre, centro_salud,rh, fluido_elegido,partido, provincia) {
	this->fecha_agregado_espera = fecha_agregado_espera;
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
void cReceptor::set_estado(estado estado_pac) {
	this->estado_pac = estado_pac;
}
enum class cReceptor::estado cReceptor::get_estado() {
	return this->estado_pac;
}
void cReceptor::set_fecha_agregado_espera(tm fecha_agregado_espera) {
	this->fecha_agregado_espera = fecha_agregado_espera;
}
tm cReceptor::get_fecha_agregado_espera() {
return this->fecha_agregado_espera;
}
cReceptor::~cReceptor(){
}
