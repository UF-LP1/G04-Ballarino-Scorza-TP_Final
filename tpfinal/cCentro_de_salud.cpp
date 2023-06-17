#include "cCentro_de_salud.h"

cCentro_de_salud::cCentro_de_salud(string nombre, string partido, string provincia, string direccion, list<cPaciente*> pacientes_del_centro, string telefono): pacientes_del_centro(pacientes_del_centro.begin(), pacientes_del_centro.end()) {
	this->nombre = nombre;
	this->partido = partido;
	this->provincia = provincia;
	this->direccion = direccion;
	this->telefono = telefono;

}
void cCentro_de_salud::set_nombre(string &nombre) {
	this->nombre = nombre;
}
string cCentro_de_salud::get_nombre() {
	return this->nombre;
}

void cCentro_de_salud::set_pacientes_del_centro(list<cPaciente*>& pacientes) {
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
void cCentro_de_salud:: agregar_pac(cPaciente* nuevoPaciente) {//
	list<cPaciente*>::iterator it = pacientes_del_centro.begin();
	int cantidad = count(it, pacientes_del_centro.end(), nuevoPaciente);//count devuelve la cantidad de veces que se repite un lo que le pasas
	if (cantidad == 1)
	{
		pacientes_del_centro.push_back((nuevoPaciente));
	}
}
void cCentro_de_salud::protocolo_de_transplante_final(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado) {
	
	if(donante_seleccionado->getFluido() == "Plasma" && (tiempo_organos(donante_seleccionado->get_fecha_de_donacion()) < (86400 * 365.25) ||
		donante_seleccionado->getFluido() == "Medula osea" && tiempo_organos(donante_seleccionado->get_fecha_de_donacion()) < 86400 ||
			donante_seleccionado->getFluido() == "Sangre" && tiempo_organos(donante_seleccionado->get_fecha_de_donacion()) < (42 * 86400))) {
//condicion para el trasplante, determinamos si es existoso con random equiprobable
		int exito = consrandom();//SI ES 2 ES EXITOSO, SI ES 1 HUBO COMPLICACIONES
		if (exito == 2) {
			list<cReceptor*>::iterator it;
			it = receptores.begin();
			while (it != receptores.end()) {
				if (*it == receptor_seleccionado) {
					delete* it;
					receptores.erase(it);//borro elemento de la lista
					break;
				}
				it++;
			}
			list<cPaciente*>::iterator it2;
			it2 = lista_de_fluido.begin();
			while (it2 != lista_de_fluido.end()) {
				cReceptor* receptor = dynamic_cast<cReceptor*>(*it2);
				if (receptor != nullptr && *it2 == receptor_seleccionado) {
					delete* it2;
					lista_de_fluido.erase(it2);//borro elemento de la lista
					break;
				}
				it2++;
			}
			
		}
		else if (exito == 1) {
			unsigned int maxprio = 5;
			receptor_seleccionado->set_prioridad(maxprio);
			receptor_seleccionado->set_estado(cReceptor::estado::inestable);
		}
	}

}
cCentro_de_salud::cCentro_de_salud() {

}
cCentro_de_salud::~cCentro_de_salud() {

}

double tiempo_organos(tm fecha) {//DEVOLVERA DIFERENCIA DE HOY EN SEGUNDOS
	time_t timer;
	time(&timer);   //usamos el timer para tener la fecha y hora actual 
	time_t fecha_ = mktime(&fecha);//el mktime nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	double  dist_fecha = 0;
	if (fecha_ != (time_t)(-1) && timer != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		dist_fecha = difftime(timer, fecha_); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por anio.
	}
	//ahora tengo cuantos anios tiene la persona en segundos, lo pasamos a anios y lo retornamos;
	return dist_fecha;
}

 int consrandom()
{
	srand(time(NULL));
	 int valor = rand() % (2 - 1) + 1;
	return valor;

}