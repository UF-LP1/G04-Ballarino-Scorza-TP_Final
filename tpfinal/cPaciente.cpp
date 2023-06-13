#include "cPaciente.h"

cPaciente::cPaciente(string nombre, tm fechanac,char sexo, string peso, string tipos_sangre,string centro_salud,string rh, string fluido_elegido,string partido,string provincia) {
	this->nombre = nombre;
	this->fechanac = fechanac;
	this->sexo = sexo;
	this->peso = peso;
	this->tipos_sangre = tipos_sangre;
	this->centro_salud = centro_salud;
    this->rh = rh;
    this->fluido_elegido = fluido_elegido;
    this->provincia = provincia;
    this->partido = partido;
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
string cPaciente::get_tipos_sangre() {
    return this->tipos_sangre;
}
string cPaciente::get_rh() {
    return  this->rh;
}
void cPaciente::set_centro_salud(string &centro_salud) {
    this->centro_salud = centro_salud;
}
string cPaciente::get_centro_salud() {
    return this->centro_salud;
}
void cPaciente::set_peso(string& peso) {
    this->peso = peso;
}
string cPaciente::get_peso() {
    return this->peso;
}
void cPaciente::set_fechanac(tm &fechanac) {
    this->fechanac = fechanac;
}
tm cPaciente::get_fechanac() {
    return this->fechanac;
}
string cPaciente::getFluido() {
    return this->fluido_elegido;
}
string cPaciente::getpartido() {
    return this->partido;
}
void cPaciente::set_partido(string& partido) {
    this->partido = partido;
    return;
}
string cPaciente::getprovincia() {
    return this->provincia;
}
void cPaciente::set_provincia(string& provincia) {
    this->provincia = provincia;
    return;
}
cPaciente::~cPaciente(){
}