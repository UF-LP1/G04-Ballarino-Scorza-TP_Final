#include "cSangre.h"

cSangre:: cSangre(string estado, tipo_d_sangre tipo_de_sangre, Rh rh) :cFluido(estado) ,tipo_de_sangre (tipo_de_sangre), rh(rh) {
}
enum class cSangre::tipo_d_sangre cSangre::get_tipo_de_sangre() {
	return tipo_de_sangre;
}
	enum class cSangre::Rh cSangre::get_rh() {
		return rh;
}
string cSangre::getTipoFluido() {
		return "Sangre";
	}
cSangre::~cSangre(){}