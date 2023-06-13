#include "cCentro_de_salud.h"

cCentro_de_salud::cCentro_de_salud(string nombre, string partido, string provincia, string direccion, list<cPaciente*> pacientes_del_centro, string telefono): pacientes_del_centro(pacientes_del_centro.begin(), pacientes_del_centro.end()) {
	this->nombre = nombre;
	this->partido = partido;
	this->provincia = provincia;
	this->direccion = direccion;
	this->telefono = telefono;

}
void cCentro_de_salud::set_nombre(string &nombre) {
	this->nombre = nombre;
}
string cCentro_de_salud::get_nombre() {
	return this->nombre;
}

void cCentro_de_salud::set_pacientes_del_centro(list<cPaciente*>& pacientes) {
	list<cPaciente*>::iterator it = pacientes.begin();

	while (it != pacientes.end()) {
		if ((*it)->get_centro_salud() == this->nombre) {
			pacientes_del_centro.push_back(*it);// CADA CENTRO DE SALUD TENDRA SU PROPIA LISTA DE PACIENTES
			(*it)->set_partido(this->partido);
			(*it)->set_provincia(this->provincia);
		}

		it++;
	}
}
list<cPaciente*> cCentro_de_salud::get_pacientes_del_centro() {
	return this->pacientes_del_centro;
}
void cCentro_de_salud::protocolo_de_transplante_final(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado) {

}
cCentro_de_salud::cCentro_de_salud() {

}
cCentro_de_salud::~cCentro_de_salud() {

}