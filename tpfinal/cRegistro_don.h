#pragma once
#include <string>
#include<iostream>

using namespace std;

class cRegistro_don {
private:
	string fluido_donado;
	ctime fecha_de_extraccion;
	string volumen;
	string centro_de_extraccion;
public:
	cRegistro_don(string fluido_donado, string ctime fecha_de_extraccion, string volumen, string centro_de_extraccion);
	~cRegistro_don();
};
