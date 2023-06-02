#pragma once
#include "cFluido.h"

class cSangre : public cFluido {
public:
	enum class tipo_d_sangre { A, B, AB, CERO };
	enum class Rh { positivo, negativo };
private:
	tipo_d_sangre tipo_de_sangre;
	Rh rh;
public:
	cSangre(string estado, tipo_d_sangre tipo_de_sangre, Rh rh);
	~cSangre();
};
