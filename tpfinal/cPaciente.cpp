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
void cPaciente:: set_nombrecentro(string centro_salud) {
    this->centro_salud = centro_salud;
    return;
}
void cPaciente::elegircentrodesalud(list<cCentro_de_salud*>centro) {
    int valor = 0;//el valor que debe ingresar
    cout << "Lista de nombres de centros de salud:" << endl;
    for (list<cCentro_de_salud*>::iterator it = centro.begin(); it != centro.end(); ++it){
        cout << "ingrese " <<valor++ <<"si desea ir a"<<(*it)->get_nombre() << endl;
    }
    cout << "ingrese" << valor << "si desea salir" << endl;
    int valorquedesea;
    cin >> valorquedesea;
    if (valorquedesea == valor) {
        return;
    }
   
     list<cCentro_de_salud*>::iterator it = centro.begin();
     for (int i = 1; i < valorquedesea && it != centro.end(); ++i) {
         ++it;
     }
     this->centro_salud = (*it)->get_nombre();
     return;
}

cPaciente::~cPaciente(){
}