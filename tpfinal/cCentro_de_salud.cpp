#include "cCentro_de_salud.h"

cCentro_de_salud::cCentro_de_salud(string nombre, string partido, string provincia, string direccion, string telefono) {
	this->nombre = nombre;
	this->partido = partido;
	this->provincia = provincia;
	this->direccion = direccion;
	this->telefono = telefono;

}
string cCentro_de_salud::get_nombre() {
	return this->nombre;
}
cCentro_de_salud::~cCentro_de_salud() {

}