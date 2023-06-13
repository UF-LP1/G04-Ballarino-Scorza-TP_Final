#pragma once

#include "cPaciente.h"
#include "cRegistro_don.h"
#include <list>
#include <ctime>
class cDonante:public cPaciente {
private:
	list<cRegistro_don*> registro_de_donaciones;
	bool enfermedades;
	bool tatuaje;
	bool donacion;
	tm fecha_de_donacion;//ESTA FECHA ES PARA VER HACE CUANTO ESTA EL ORGANO
public:
	cDonante(string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_elegido,list<cRegistro_don*> registro_de_donaciones, string partido, string provincia, bool enfermedades, bool tatuaje, bool donacion, tm fecha_de_donacion);
	void setFluido(string& fluido_elegido) override;
	void set_enfermedades(bool &enfermedades);
	void set_tatuaje(bool &tatuaje);
	void set_donacion(bool &donacion);
	bool get_enfermedades();
	bool get_tatuaje();
	bool get_donacion();
	void set_fecha_de_donacion(tm fecha_de_donacion);
	tm get_fecha_de_donacion();
~cDonante();
};