#include "cMedula_osea.h"

cMedula_osea::cMedula_osea(string estado,string color) :cFluido( estado) {
	this->color = color;
}
string cMedula_osea::getTipoFluido() {
	return "Medula Osea";
}
cMedula_osea::~cMedula_osea(){}