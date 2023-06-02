#pragma once
#include "cFluido.h"

class cPlasma :cFluido {
private:
	string tipo_de_plasma;
public:
	cPlasma(string estado, string tipo_de_plasma);
	~cPlasma();
};