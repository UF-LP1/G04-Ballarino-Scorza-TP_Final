#include "cPlasma.h"

cPlasma::cPlasma(string estado, string tipo_de_plasma) :cFluido(estado) {
	this->tipo_de_plasma = tipo_de_plasma;
}
cPlasma::~cPlasma(){}