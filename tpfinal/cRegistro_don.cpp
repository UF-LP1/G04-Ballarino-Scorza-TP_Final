//NUEVO
#include"cRegistro_don.h"


cRegistro_don::cRegistro_don(string nombre, string fluido_donado, tm fecha_de_extraccion, string volumen, string centro_de_extraccion) {
	this->nombre = nombre;
	this->fluido_donado = fluido_donado;
	this->fecha_de_extraccion = fecha_de_extraccion;
	this->volumen = volumen;
	this->centro_de_extraccion = centro_de_extraccion;

}
string cRegistro_don::get_nombre() {
	return this->nombre;
}
cRegistro_don::~cRegistro_don() {
}
//NUEVO
