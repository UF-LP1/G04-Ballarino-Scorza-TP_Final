#include"cDonante.h"

cDonante::cDonante(string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, list<cRegistro_don*>registro_de_donaciones, bool enfermedades, bool tatuaje, bool donacion):registro_de_donaciones(registro_de_donaciones.begin(), registro_de_donaciones.end()),cPaciente(nombre, fechanac, sexo, peso, tipos_sangre, centro_salud) {
	this->enfermedades = enfermedades;
	this->tatuaje = tatuaje;
	this->donacion = donacion;
}
cDonante::~cDonante() {}