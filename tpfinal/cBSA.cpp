

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
				receptor->set_fecha_agregado_espera(setear_fecha_ingreso_espera());//SETEO LA FECHA DE INGRESO DEL RECEPTOR CON LA DE HOY QUE SERIA CUANDO ENTRO
				receptores.push_back(receptor);
			}
			else if (cDonante* donante = dynamic_cast<cDonante*>(*it2)) {
				if (distancia_fechas(donante->get_fechanac())> 18 && distancia_fechas(donante->get_fechanac()) < 65 && donante->get_peso() > "50" 
					&& donante->get_enfermedades() == false && donante->get_tatuaje() == false && donante->get_donacion() == false) {
					donantes.push_back(donante);
				}
			}
			}

	}
}
void cBSA::separar_segun_fluido(list<cReceptor*> receptores, list<cDonante*> donantes) {
	list<cReceptor*>::iterator it;
	for (it = receptores.begin(); it != receptores.end(); it++) {
		if ((*it)->getFluido()=="Plasma") {
			recp_y_don_plasma.push_back((*it));
		}
		else if((*it)->getFluido() == "Sangre")
		{
			recp_y_don_sangre.push_back((*it));
		}
		else if((*it)->getFluido() == "Medula osea")
		{
			recp_y_don_medula_osea.push_back((*it));
		}
	}
	list<cDonante*>::iterator it2;

	for (it2 = donantes.begin(); it2 != donantes.end(); it++) {
		if ((*it2)->getFluido() == "Plasma") {
			recp_y_don_plasma.push_back((*it2));
		}
		else if ((*it2)->getFluido() == "Sangre")
		{
			recp_y_don_sangre.push_back((*it2));
		}
		else if ((*it2)->getFluido() == "Medula osea")
		{
			recp_y_don_medula_osea.push_back((*it2));
		}
	}
	return;
}

cReceptor* cBSA::elegir_receptor(string& fluido) {// DEVOLVEMOS CRECEPTOR YA QUE LA PRIORIDAD LA TIENEN RECEPTORES
	cReceptor* receptor_seleccionado = nullptr;

	if (fluido == "Plasma") {
		list<cPaciente*>::iterator itReceptores; 
	
		for (itReceptores = recp_y_don_plasma.begin(); itReceptores != recp_y_don_plasma.end(); ++itReceptores) {
			cReceptor* receptor = dynamic_cast<cReceptor*>(*itReceptores);
			if (receptor != nullptr) {
				if (receptor_seleccionado == nullptr ||
					receptor->get_prioridad() > receptor_seleccionado->get_prioridad() ||
					(receptor->get_prioridad() == receptor_seleccionado->get_prioridad() &&
						(receptor->get_estado() < receptor_seleccionado->get_estado() ||
							distancia_fechas(receptor->get_fecha_agregado_espera()) > 	distancia_fechas(receptor_seleccionado->get_fecha_agregado_espera())))) {
					receptor_seleccionado = receptor;
				}
			}
		}
	}
	else if (fluido == "Sangre") {
		// Lógica similar para la lista recp_y_don_sangre
	}
	else if (fluido == "Medula osea") {
		// Lógica similar para la lista recp_y_don_medula_osea
	}

	return receptor_seleccionado;
}





cBSA::~cBSA(){
}


double distancia_fechas(tm fecha) {
	time_t timer;
	time(&timer);   //usamos el timer para tener la fecha y hora actual 
	time_t fecha_ = mktime(&fecha);//el mktime nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	double  dist_fecha=0;
	if (fecha_ != (time_t)(-1) && timer != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		dist_fecha = difftime(timer,fecha_) / (86400*365.25); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por anio.
	}
	//ahora tengo cuantos anios tiene la persona en segundos, lo pasamos a anios y lo retornamos;
	return dist_fecha;
}

tm setear_fecha_ingreso_espera() {
	time_t hoy = time(nullptr);// Obtener la fecha y hora actual en segundos desde la Época Unix

	tm hoy_;
	localtime_s(&hoy_, &hoy);// Recibe mi variable hoy de tipo time_t y localtimes_s te la devuelve de tipo tm,	que es lo que quiere devolver esta funcion 

	return hoy_;
}