#pragma once
#include "cFluido.h"

class cMedula_osea :public cFluido {
private:
	string color;
public:
	cMedula_osea(string estado, string color);
	~cMedula_osea();
};
