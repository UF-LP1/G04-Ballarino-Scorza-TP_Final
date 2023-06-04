#include"cDonante.h"

cDonante::cDonante(string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh,string fluido_elegido ,list<cRegistro_don*>registro_de_donaciones, bool enfermedades, bool tatuaje, bool donacion):registro_de_donaciones(registro_de_donaciones.begin(), registro_de_donaciones.end()),cPaciente(nombre, fechanac, sexo, peso, tipos_sangre, centro_salud,rh,fluido_elegido) {
	this->enfermedades = enfermedades;
	this->tatuaje = tatuaje;
	this->donacion = donacion;
}
void cDonante::setFluido(string& fluido_elegido) {
	this->fluido_elegido = fluido_elegido;
}
cDonante::~cDonante() {
	
}