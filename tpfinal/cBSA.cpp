#include "cBSA.h"

cBSA::cBSA(list<cReceptor*>receptores, list<cDonante*>donantes, list<cCentro_de_salud*>centros_de_salud)
	: receptores(receptores.begin(), receptores.end()),donantes(donantes.begin(), donantes.end()),
centros_de_salud(centros_de_salud.begin(), centros_de_salud.end()) {

}
void cBSA::set_lista_de_centros(list<cCentro_de_salud*> centros_de_salud) {
	this->centros_de_salud = centros_de_salud;
}
list<cCentro_de_salud*> cBSA::get_lista_de_centros() {
	return this->centros_de_salud;
}
void cBSA::set_receptores_y_donantes()
{
	// recorremos cada lista de centros, y de cada lista de centros, los pacientes asociados
	list<cCentro_de_salud*>::iterator it;
	for (it = this->centros_de_salud.begin(); it != this->centros_de_salud.end(); it++) {//RECORRO LOS CENTROS
		list<cPaciente*>::iterator it2;
		for (it2=((*it)->get_pacientes_del_centro().begin());it2!=((*it)->get_pacientes_del_centro().end());it2++)//AHORA DEL PRIMERO CENTRO, RECORRO LA LISTA DE PACIENTES ASOCIADOS AL CENTRO
			{
			if (cReceptor* receptor = dynamic_cast<cReceptor*>(*it2)) {//DYNAMIC CAST PARA VER SI EL PUNTERO DE PACIENTE ES RECEPTOR O DONANTE
				receptores.push_back(receptor);
			}
			else if (cDonante* donante = dynamic_cast<cDonante*>(*it2)) {
				if (*(it2)->*(it2)->*(it2)->*(it2)->*(it2)->*(it2)->) {
					donantes.push_back(donante);
				}
			}
			}

	}
}
cBSA::~cBSA(){
}