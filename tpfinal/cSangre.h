//NUEVO
#pragma once
#include "cFluido.h"

class cSangre : public cFluido {
public:
	enum class tipo_d_sangre { A, B, AB, CERO };// Ponemos ENUM CLASS ya que nos tira la advertencia de "enum type is unscoped,prefer ENUM CLASS over ENUM"
	enum class Rh { positivo, negativo };
private:
	tipo_d_sangre tipo_de_sangre;
	Rh rh;
public:
	cSangre(string estado, tipo_d_sangre tipo_de_sangre, Rh rh);
	~cSangre();
	cSangre();
	tipo_d_sangre get_tipo_de_sangre();
	string getTipoFluido() override;
	bool VerificarFechaMaxima(tm fecha) override;
	Rh get_rh();
};
//nuevo