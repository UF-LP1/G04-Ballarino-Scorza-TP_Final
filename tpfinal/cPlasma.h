//nuevo
#pragma once
#include "cFluido.h"

class cPlasma : public cFluido {
private:
	string tipo_de_plasma;
public:
	cPlasma(string estado, string tipo_de_plasma);
	string getTipoFluido() override;
	bool VerificarFechaMaxima(tm fecha) override;
	~cPlasma();
	cPlasma();
};
//NUEVO