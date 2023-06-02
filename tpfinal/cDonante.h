#pragma once

#include "cPaciente.h"
#include "cRegistro_don.h"
#include <list>
class cDonante {
private:
	list<cRegistro_don> registro_de_donaciones;
	bool enfermedades;
	bool tatuaje;
	bool donacion;
public:
	cDonante(string nombre, ctime fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, list<cRegistro_don*> registro_de_donaciones, bool enfermedades, bool tatuaje, bool donacion);
	~cDonante();
};