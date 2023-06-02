#include"cRegistro_don.h"


cRegistro_don::cRegistro_don(string fluido_donado, tm fecha_de_extraccion,string volumen, string centro_de_extraccion) {
	this->fluido_donado=fluido_donado;
	this->fecha_de_extraccion = fecha_de_extraccion;
	this->volumen = volumen;
	this->centro_de_extraccion = centro_de_extraccion;

}
cRegistro_don::~cRegistro_don(){
}