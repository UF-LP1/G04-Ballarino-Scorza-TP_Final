//NUEVO
#pragma once
#include <string>
#include<iostream>
#include <ctime>
using namespace std;

class cRegistro_don {
private:
	
	string fluido_donado;
	tm fecha_de_extraccion;
	string centro_de_extraccion;
public:
	cRegistro_don( string fluido_donado, tm fecha_de_extraccion, string centro_de_extraccion);
	void set_fluido_donad(string fluido_donado);
	void set_fecha_don(tm fecha_de_extraccion);
	void set_centro_don(string centro_de_extraccion);
	~cRegistro_don();
};
//nuevo