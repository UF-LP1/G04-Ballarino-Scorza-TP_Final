#include"cDonante.h"

cDonante::cDonante(const  int id,string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh,string fluido_elegido ,string partido,string provincia, bool enfermedades, bool tatuaje, bool donacion, tm fecha_de_donacion):cPaciente(id, nombre, fechanac, sexo, peso, tipos_sangre, centro_salud,rh,fluido_elegido, partido, provincia) {
	this->enfermedades = enfermedades;
	this->tatuaje = tatuaje;
	this->donacion = donacion;
	this->fecha_de_donacion = fecha_de_donacion;
}
void cDonante::setFluido(string& fluido_elegido) {
	this->fluido_elegido = fluido_elegido;
}
void cDonante::set_enfermedades(bool &enfermedades) {
	this->enfermedades = enfermedades;
}
void cDonante::set_tatuaje(bool &tatuaje) {
	this->tatuaje = tatuaje;
}
void cDonante::set_donacion(bool &donacion) {
	this->donacion = donacion;
}
bool cDonante::get_enfermedades() {
	return this->enfermedades;
}
bool cDonante::get_tatuaje() {
	return this->tatuaje;
}
bool cDonante::get_donacion() {
	return this->donacion;
}
void cDonante:: set_fecha_de_donacion(tm fecha_de_donacion){
	this->fecha_de_donacion = fecha_de_donacion;
}
tm cDonante::get_fecha_de_donacion() {
	return this->fecha_de_donacion;
}
void cDonante:: set_registro_dedonaciones(list<cRegistro_don*> &registro) {
	list<cRegistro_don*>::iterator it = registro.begin();

	while (it != registro.end()) {
		if ((*it)->get_nombre() == this->get_nombre()) {
			registro_de_donaciones.push_back(*it);// cada donante tiene su propio lista de refgistro, que sale de la misma lista para todos los pacientes
			
		}

		it++;
	}
}

cDonante::~cDonante() {
	
}