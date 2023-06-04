#include "cBSA.h"

cBSA::cBSA(list<cReceptor*>receptores, list<cDonante*>donantes, list<cCentro_de_salud*>centros_de_salud)
	: receptores(receptores.begin(), receptores.end()),donantes(donantes.begin(), donantes.end()),
centros_de_salud(centros_de_salud.begin(), centros_de_salud.end()) {

}
void cBSA::set_lista_de_centros(list<cCentro_de_salud*> centros_de_salud) {//list<cpacinete>sangre
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
				if (obtener_edad(donante->get_fechanac())> 18 && obtener_edad(donante->get_fechanac()) < 65 && donante->get_peso() > "50" 
					&& donante->get_enfermedades() == false && donante->get_tatuaje() == false && donante->get_donacion() == false) {
					donantes.push_back(donante);
				}
			}
			}

	}
}
cBSA::~cBSA(){
}
double obtener_edad(tm fechanac) {
	time_t timer;
	time(&timer);   //usamos el timer para tener la fecha y hora actual 
	time_t fecha_nacimiento = mktime(&fechanac);//el mktime nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	double  edad=0;
	if (fecha_nacimiento != (time_t)(-1) && timer != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		edad = difftime(timer,fecha_nacimiento) / (86400*365.25); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por anio.
	}
	//ahora tengo cuantos anios tiene la persona en segundos, lo pasamos a anios y lo retornamos;
	return edad;
}