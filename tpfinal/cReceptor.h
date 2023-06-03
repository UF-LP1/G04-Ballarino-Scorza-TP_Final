#pragma once

#include "cPaciente.h"

class cReceptor :public cPaciente {
public:
	enum class estado { estable, inestable, recuperado };

private:
	tm fecha_agregado_espera;
	unsigned int prioridad;
	estado estado_pac;
public:
	cReceptor(string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_elegido, tm fecha_agregado_espera, unsigned int prioridad, estado estado_pac);
	void setFluido(string& fluido_elegido) override;
	~cReceptor();
};
