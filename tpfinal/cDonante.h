#pragma once
//nuevo
#include "cPaciente.h"
#include "cRegistro_don.h"
#include <list>
#include <ctime>
#include<sstream>
class cDonante :public cPaciente {
private:
	list<cRegistro_don*> registro_de_donaciones;
	bool enfermedades;
	bool tatuaje;
	bool donacion;
	tm fecha_de_donacion;//ESTA FECHA ES PARA VER HACE CUANTO ESTA EL ORGANO
public:
	cDonante(const string id, string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_elegido, string partido, string provincia, bool enfermedades, bool tatuaje, bool donacion, tm fecha_de_donacion);
	void setFluido(string& fluido_elegido) override;
	void set_enfermedades(bool& enfermedades);
	void set_tatuaje(bool& tatuaje);
	void set_donacion(bool& donacion);
	bool get_enfermedades();
	bool get_tatuaje();
	bool get_donacion();
	void set_fecha_de_donacion(tm fecha_de_donacion);
	void set_registro_de_donaciones();
	string to_string();
	tm get_fecha_de_donacion();
	~cDonante();
};
//NUEVO 