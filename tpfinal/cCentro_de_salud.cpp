#include "cCentro_de_salud.h"

cCentro_de_salud::cCentro_de_salud(string nombre, string partido, string provincia, string direccion, string telefono) {
	this->nombre = nombre;
	this->partido = partido;
	this->provincia = provincia;
	this->direccion = direccion;
	this->telefono = telefono;

	srand(time(NULL));
}
void cCentro_de_salud::set_nombre(string &nombre) {
	this->nombre = nombre;
}
string cCentro_de_salud::get_nombre() {
	return this->nombre;
}

void cCentro_de_salud::set_pacientes_del_centro(list<cPaciente*>& pacientes) {//SE CARGAN DESDE EL MAIN
	list<cPaciente*>::iterator it = pacientes.begin();

	while (it != pacientes.end()) {
		if ((*it)->get_centro_salud() == this->nombre) {
			pacientes_del_centro.push_back(*it);// CADA CENTRO DE SALUD TENDRA SU PROPIA LISTA DE PACIENTES
			(*it)->set_partido(this->partido);//seteamos la provincia y el partido del paciente
			(*it)->set_provincia(this->provincia);
		}

		it++;
	}
}
list<cPaciente*> cCentro_de_salud::get_pacientes_del_centro() {
	return this->pacientes_del_centro;
}

void cCentro_de_salud::protocolo_de_transplante_final(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado, list<cReceptor*> receptores) {
	cSangre sangre;
	cPlasma plasma;
	cMedula_osea medula_osea;
	if ((donante_seleccionado->getFluido() == sangre.getTipoFluido() && sangre.VerificarFechaMaxima(donante_seleccionado->get_fecha_de_donacion())) ||
		(donante_seleccionado->getFluido() == plasma.getTipoFluido() && plasma.VerificarFechaMaxima(donante_seleccionado->get_fecha_de_donacion())) ||
		(donante_seleccionado->getFluido() == medula_osea.getTipoFluido() && medula_osea.VerificarFechaMaxima(donante_seleccionado->get_fecha_de_donacion())))
	{
//condicion para el trasplante, determinamos si es existoso con random equiprobable
		int exito = consrandom();//SI ES 2 ES EXITOSO, SI ES 1 HUBO COMPLICACIONES
		if (exito == 2) {
			receptores= receptores - receptor_seleccionado;//SOBRECARGA DE-
		}
		else if (exito == 1) {
			unsigned int maxprioridad = 5;
			receptor_seleccionado->set_prioridad(maxprioridad);
			receptor_seleccionado->set_estado(cReceptor::estado::inestable);
		}
	}

}


void cCentro_de_salud::agregar_paciente(cPaciente* paciente) {
	if (this->pacientes_del_centro == paciente)//este igual estara sobrecargado y devuelve true si esta
		return;
	else
		this->pacientes_del_centro=	this->pacientes_del_centro + paciente;
}
cCentro_de_salud::cCentro_de_salud() {

}
cCentro_de_salud::~cCentro_de_salud() {

}

 int consrandom()
{
	
	 int valor = rand() % (2 - 1) + 1;
	return valor;

}
 
 list<cReceptor*> operator-(list<cReceptor*> receptores, cReceptor* receptor_seleccionado) {
	 list<cReceptor*>::iterator it = receptores.begin();

	 while (it != receptores.end()) {
		 if ((*it)->get_id() == receptor_seleccionado->get_id()) {
			 it = receptores.erase(it);
		 }
		 else {
			 it++;
		 }
	 }

	 return receptores;
 }
 bool operator==(list<cPaciente*> pacientes, cPaciente* paciente) {//devuelve true si esta en la lista
	 list<cPaciente*>::iterator it = pacientes.begin();

	 while (it != pacientes.end()) {
		 if ((*it)->get_id() == paciente->get_id()) {
			 return true;
		 }
		 else {
			 it++;
		 }
	 }

	 return false;
 }
 list<cPaciente*> operator+(list<cPaciente*> pacientes, cPaciente* paciente) {
	 pacientes.push_back(paciente);//chequea arriba si esta
	 return pacientes;
 }
