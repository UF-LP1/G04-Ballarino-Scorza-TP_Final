#pragma once
#include "cFluido.h"
#include<sstream>
//nuevo
class cMedula_osea :public cFluido {
private:
	string color;
public:
	cMedula_osea(string estado, string color);
	string getTipoFluido() override;//override, est�s indicando de manera expl�cita que est�s sobrescribiendo un m�todo de la clase base
	bool VerificarFechaMaxima(tm fecha) override;
	string to_string();
	~cMedula_osea();
	cMedula_osea();
};
//NUEVO