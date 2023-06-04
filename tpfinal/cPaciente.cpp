#include "cPaciente.h"

cPaciente::cPaciente(string nombre, tm fechanac,char sexo, string peso, string tipos_sangre,string centro_salud,string rh, string fluido_elegido) {
	this->nombre = nombre;
	this->fechanac = fechanac;
	this->sexo = sexo;
	this->peso = peso;
	this->tipos_sangre = tipos_sangre;
	this->centro_salud = centro_salud;
    this->rh = rh;
    this->fluido_elegido = fluido_elegido;
}
void cPaciente:: set_tipo_de_Sangre_y_rh(cFluido& fluido) 
{
	cSangre* sangre = dynamic_cast< cSangre*>(&fluido);
	if(sangre!=NULL)
        switch (sangre->get_tipo_de_sangre()) {
        case cSangre::tipo_d_sangre ::A:
            tipos_sangre = "A";
            break;
        case  cSangre::tipo_d_sangre::B:
            tipos_sangre = "B";
            break;
        case  cSangre::tipo_d_sangre::AB:
            tipos_sangre = "AB";
            break;
        case  cSangre::tipo_d_sangre::CERO:
            tipos_sangre = "CERO";
            break;
        }

    switch (sangre->get_rh()) {
    case cSangre::Rh::positivo:
        rh = "Positivo";
        break;
    case cSangre::Rh::negativo:
        rh = "Negativo";
        break;
    }
}

void cPaciente::set_centro_salud(string centro_salud) {
    this->centro_salud = centro_salud;
}
string cPaciente::get_centro_salud() {
    return this->centro_salud;
}
cPaciente::~cPaciente(){
}