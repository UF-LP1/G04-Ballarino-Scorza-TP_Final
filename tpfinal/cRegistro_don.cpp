//NUEVO
#include"cRegistro_don.h"


cRegistro_don::cRegistro_don(string fluido_donado, tm fecha_de_extraccion, string centro_de_extraccion) {
	
	this->fluido_donado = fluido_donado;
	this->fecha_de_extraccion = fecha_de_extraccion;
	this->centro_de_extraccion = centro_de_extraccion;

}
void cRegistro_don::set_fluido_donad(string fluido_donado) {
	this->fluido_donado = fluido_donado;
}
void cRegistro_don::set_fecha_don(tm fecha_de_extraccion) {
	this->fecha_de_extraccion = fecha_de_extraccion;
}

void cRegistro_don::set_centro_don(string centro_de_extraccion) {
	this->centro_de_extraccion = centro_de_extraccion;
}

cRegistro_don::~cRegistro_don() {
}
//NUEVO
