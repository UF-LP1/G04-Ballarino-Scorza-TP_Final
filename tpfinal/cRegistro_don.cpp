#include"cRegistro_don.h"


cRegistro_don::cRegistro_don(string fluido_donado, ctime fecha_d_extraccion,string volumen, string centro_de_extraccion) {
	this->fluido_donado=fluido_donado;
	this->volumen = volumen;
	this->centro_de_extraccion = centro_de_extraccion;

}
cRegistro_don::~cRegistro_don(){
}