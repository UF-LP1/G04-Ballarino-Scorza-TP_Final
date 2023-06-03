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

cBSA::~cBSA(){
}