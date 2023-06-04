#pragma once

#include "cPaciente.h"
#include "cRegistro_don.h"
#include <list>

class cDonante:public cPaciente {
private:
	list<cRegistro_don*> registro_de_donaciones;
	bool enfermedades;
	bool tatuaje;
	bool donacion;
public:
	cDonante(string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_elegido,list<cRegistro_don*> registro_de_donaciones, bool enfermedades, bool tatuaje, bool donacion);
	void setFluido(string& fluido_elegido) override;
	void set_enfermedades(bool &enfermedades);
	void set_tatuaje(bool &tatuaje);
	void set_donacion(bool &donacion);
	bool get_enfermedades();
	bool get_tatuaje();
	bool get_donacion();
~cDonante();
};