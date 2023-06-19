#pragma once
#include "cFluido.h"
#include<sstream>
//nuevo
class cMedula_osea :public cFluido {
private:
	string color;
public:
	cMedula_osea(string estado, string color);
	string getTipoFluido() override;//override, estás indicando de manera explícita que estás sobrescribiendo un método de la clase base
	bool VerificarFechaMaxima(tm fecha) override;
	string to_string();
	~cMedula_osea();
	cMedula_osea();
};
//NUEVO