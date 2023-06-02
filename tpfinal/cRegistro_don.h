#pragma once
#include <string>
#include<iostream>
#include <ctime>
using namespace std;

class cRegistro_don {
private:
	string fluido_donado;
	tm fecha_de_extraccion;
	string volumen;
	string centro_de_extraccion;
public:
	cRegistro_don(string fluido_donado, tm fecha_de_extraccion, string volumen, string centro_de_extraccion);
	~cRegistro_don();
};
