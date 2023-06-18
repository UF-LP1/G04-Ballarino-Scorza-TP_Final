#pragma once

#include "cPaciente.h"

class cReceptor :public cPaciente {
public:
	enum class estado { inestable,estable, recuperado };

private:
	tm fecha_agregado_espera;//ESTE ATRIBUTO SE CARGA EN EL BSA, EL DIA QUE FUE AGREGADO
	unsigned int prioridad;
	estado estado_pac;
public:
	cReceptor(const string id,string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_elegido, string partido, string provincia, tm fecha_agregado_espera, unsigned int prioridad, estado estado_pac);
	void setFluido(string& fluido_elegido) override;
	void set_prioridad(unsigned int &prioridad);
	unsigned int get_prioridad();
	void set_estado(estado estado_pac);
	estado get_estado();
	void set_fecha_agregado_espera(tm fecha_agregado_espera);
	tm get_fecha_agregado_espera();
	~cReceptor();
};
