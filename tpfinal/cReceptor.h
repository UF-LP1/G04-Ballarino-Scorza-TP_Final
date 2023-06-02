#pragma once

#include "cPaciente.h"

class cReceptor :public cPaciente {
public:
	enum class estado { estable, inestable, recuperado };

private:
	ctime fecha_agreado_espera;
	unsigned int prioridad;
	estado estado_pac;
public:
	cReceptor(string nombre, ctime fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, ctime fecha_agreado_espera, unsigned int prioridad, estado estado_pac);
	~cReceptor();
};
