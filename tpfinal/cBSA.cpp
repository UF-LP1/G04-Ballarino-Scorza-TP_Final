

#include "cBSA.h"
#include "cCentro_de_salud.h"
#include <algorithm>

template<typename T>
void ordeno_punteros(T*& a, T*& b) {
	T* aux = a;
	a = b;
	b = aux;
}

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
			cReceptor* receptor = dynamic_cast<cReceptor*>(*it2);
			if (receptor!=nullptr) {//DYNAMIC CAST PARA VER SI EL PUNTERO DE PACIENTE ES RECEPTOR O DONANTE
				receptor->set_fecha_agregado_espera(setear_fecha_ingreso_espera());//SETEO LA FECHA DE INGRESO DEL RECEPTOR CON LA DE HOY QUE SERIA CUANDO ENTRO
				receptores.push_back(receptor);
			}
			cDonante* donante = dynamic_cast<cDonante*>(*it2);
			 if  (donante!=nullptr && (distancia_fechas(donante->get_fechanac())> 18 && distancia_fechas(donante->get_fechanac()) < 65 && donante->get_peso() > "50" 
					&& donante->get_enfermedades() == false && donante->get_tatuaje() == false && donante->get_donacion() == false)) {
					donantes.push_back(donante);
				}
			}
			}

	}
//Ya TENEMOS SEPARADOS LISTA DE DONANTES Y PACIENTES
list<cPaciente*>& cBSA::separar_segun_fluido(cDonante* donante) {
		list<cReceptor*>::iterator it;
		list<cPaciente*> listafluido_recp;
		for (it = receptores.begin(); it != receptores.end(); it++) {//ESTE METODO RECORRE LA LISTA DE RECEPTORES Y DEVUELVE CON LOS RECEPTORES DE ESE FLUIDO
			if (*(*it) == *donante) {  //SOBRECARGA DE OPERDOR == 
				listafluido_recp.push_back((*it));
			}
		}

		return ordenar_por_prioridad(listafluido_recp);
	}
//DEVUELVE LA LISTA DE RECEPTORES ORDENADA POR PRIORIDAD SEGUN FLUIDO DONANTE

list<cPaciente*>& cBSA::ordenar_por_prioridad(list<cPaciente*>& listafluido_recp) {
	for (list<cPaciente*>::iterator itReceptores = listafluido_recp.begin(); itReceptores != listafluido_recp.end(); ++itReceptores) {          //ordenamiento por burbuja
		for (list<cPaciente*>::iterator itSiguiente = next(itReceptores); itSiguiente != listafluido_recp.end(); ++itSiguiente) {
			cReceptor* receptorActual = dynamic_cast<cReceptor*>(*itReceptores);
			cReceptor* receptorSiguiente = dynamic_cast<cReceptor*>(*itSiguiente);

			if (receptorActual!=nullptr && receptorSiguiente!=nullptr) {
				if (receptorActual->get_prioridad() < receptorSiguiente->get_prioridad() ||//si la prioridad es mayor , es porque es mas urgente
					(receptorActual->get_prioridad() == receptorSiguiente->get_prioridad() &&
						(receptorActual->get_estado() > receptorSiguiente->get_estado() ||//se eel estado es menor es porque es mas urgente
							distancia_fechas(receptorActual->get_fecha_agregado_espera()) < distancia_fechas(receptorSiguiente->get_fecha_agregado_espera())))) {//si la espera es mayor, tiene prioridad

					ordeno_punteros(* itReceptores, * itSiguiente);
				}
			}
		}
	}

	return listafluido_recp;
}


cReceptor* cBSA::match(cDonante* donante) { //en el main recorro lista de donantes, y busco receptores para el mismo, ver pasa si no hay donante compatible 
	
	cReceptor* receptor_seleccionado = nullptr;
	bool protocolo;
	if (donante->getFluido() == "Plasma" || donante->getFluido() == "Medula Osea") {
		list<cPaciente*>::iterator it= (separar_segun_fluido(donante)).begin();//devuelvo receptore agarro el primero que ya esta ordenado
		cReceptor* receptor_seleccionado = dynamic_cast<cReceptor*>(*it);
     }
	if (receptor_seleccionado != nullptr) {
			protocolo = protocolo_transplante_inicio(receptor_seleccionado, donante);
		}	
	 if (donante->getFluido() == "Sangre")
	{
		 cReceptor* receptor_seleccionado =buscar_receptor_compatibles_sangre (donante, separar_segun_fluido(donante));//verifico compatibilidad

		 if (receptor_seleccionado != nullptr) {
			 protocolo = protocolo_transplante_inicio(receptor_seleccionado, donante);
		 }
		
	}
	return receptor_seleccionado;

}


cReceptor* cBSA:: buscar_receptor_compatibles_sangre(cDonante* donante_seleccionado, list<cPaciente*>& listafluido_recp) {
	list<cPaciente*>::iterator itpaciente= listafluido_recp.begin();
	while(itpaciente != listafluido_recp.end()) {
		cReceptor* receptor = dynamic_cast<cReceptor*>(*itpaciente);
		if (receptor != nullptr && verificar_compatibilidad_sangre(receptor, donante_seleccionado))
			return receptor;

		itpaciente++;
	}
	return nullptr;
}

bool  cBSA::verificar_compatibilidad_sangre(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado) {
	string tipoDonante = donante_seleccionado->get_tipos_sangre();
	string tipoReceptor = receptor_seleccionado->get_tipos_sangre();
	string rhDonante = donante_seleccionado->get_rh();
	string rhReceptor = receptor_seleccionado->get_rh();

	if (tipoDonante == "0" && (tipoReceptor == "0" || tipoReceptor == "A" || tipoReceptor == "B" || tipoReceptor == "AB") && rhDonante == rhReceptor) {
		return true;
	}
	else if (tipoDonante == "A" && (tipoReceptor == "A" || tipoReceptor == "AB") && (rhDonante == rhReceptor || rhDonante == "positivo")) {
		return true;
	}
	else if (tipoDonante == "B" && (tipoReceptor == "B" || tipoReceptor == "AB") && (rhDonante == rhReceptor || rhDonante == "positivo")) {
		return true;
	}
	else if (tipoDonante == "AB" && tipoReceptor == "AB" && rhDonante == rhReceptor) {
		return true;
	}
	else if (tipoDonante == "0" && tipoReceptor == "A" && rhDonante == rhReceptor) {
		return true;
	}
	else if (tipoDonante == "0" && tipoReceptor == "B" && rhDonante == rhReceptor) {
		return true;
	}
	else if (tipoDonante == "A" && tipoReceptor == "AB" && (rhDonante == rhReceptor || rhDonante == "positivo")) {
		return true;
	}
	else if (tipoDonante == "B" && tipoReceptor == "AB" && (rhDonante == rhReceptor || rhDonante == "positivo")) {
		return true;
	}
	else if (tipoDonante == "0" && tipoReceptor == "AB" && rhDonante == rhReceptor) {
		return true;
	}
	else if (tipoDonante == "AB" && (tipoReceptor == "A" || tipoReceptor == "B" || tipoReceptor == "AB") && (rhDonante == rhReceptor || rhDonante == "positivo")) {
		return true;
	}

	return false;
}

bool cBSA::protocolo_transplante_inicio(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado) {
	if (receptor_seleccionado->getprovincia() == donante_seleccionado->getprovincia() && receptor_seleccionado->getpartido() == donante_seleccionado->getpartido()) {
		cCentro_de_salud centro;
		centro.protocolo_de_transplante_final(receptor_seleccionado, donante_seleccionado, receptores);

		// Incrementar el contador de donaciones para la provincia correspondiente
		//por mas de que haya habido complicaciones, nosotros contamos las donaciones
		string provincia = receptor_seleccionado->getprovincia();
		list<DonacionesProvincia*>::iterator it = donacionesPorProvincia.begin();
		while (it != donacionesPorProvincia.end()) {
			if ((*it)->provincia == provincia) {
				// La provincia ya existe en la lista, incrementar el contador
				((*it)->cantidad)++;
				return true;
			}
			it++;
		}
		if (it == donacionesPorProvincia.end()) {
			// La provincia no existe en la lista, agregar una nueva entrada con valor 1
			donacionesPorProvincia.push_back(new DonacionesProvincia{ provincia, 1 });
		}
		return false;
	}
	else {
		return false;
	}
}
list<cReceptor*>& cBSA :: get_receptores() {
	return this->receptores;
}
list<cReceptor*> cBSA::receptores_de_un_centro(string centro_de_salud) {
	list<cReceptor*>::iterator it;
	list<cReceptor*> receptores_de_ese_centro;

	for (it = receptores.begin(); it != receptores.end(); it++) {
		if ((*it)->get_centro_salud() == centro_de_salud) {
			receptores_de_ese_centro.push_back(*it);
		}
	}

	return receptores_de_ese_centro;
}
unsigned int cBSA::prioridad_de_receptor(cReceptor* receptor_seleccionado) {
	list<cReceptor*>::iterator it = receptores.begin();

	while (it != receptores.end()) {
		if ((*it)->get_id() == receptor_seleccionado->get_id()) {
		return (receptor_seleccionado->get_prioridad());
		}
		else {
			it++;
		}
	}

	return 0;
}
string cBSA::to_string() {
	stringstream s;
	s << " Receptores de BSA:" << endl << endl;
	for (list<cReceptor*>::iterator it = receptores.begin(); it != receptores.end(); it++) {
		s << "nombre:" << (*it)->get_nombre() << " ,con id:" << (*it)->get_id() << ",quiere recibir " << (*it)->getFluido() << " y con prioridad " << (*it)->get_prioridad() << " ." << endl;
	}
	s << endl << endl;
	s << "Donantes de BSA:" << endl << endl;
	for (list<cDonante*>::iterator it = donantes.begin(); it != donantes.end(); it++) {
		s << "nombre:" << (*it)->get_nombre() << " ,con id:" << (*it)->get_id() << ",quiere donar " << (*it)->getFluido() << endl;
	}
	return s.str();
}
void cBSA::imprimir(cBSA* cbsa) {
	cout << cbsa;//SOBRECARGAMOS OPERADOR
}

void cBSA::generarInformeDonacionesPorProvincia() {
	list<string> nombresProvincias = {
		"Buenos Aires", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes",
		"Entre Ríos", "Formosa", "Jujuy", "La Pampa", "La Rioja", "Mendoza",
		"Misiones", "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis",
		"Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego",
		"Tucumán"
	};

	cout << "Informe de Donaciones por Provincia - [Mes, Año]" << endl;

	list<DonacionesProvincia*>::iterator it = donacionesPorProvincia.begin();
	for (list<string>::iterator provinciait = nombresProvincias.begin(); provinciait != nombresProvincias.end(); provinciait++) {
		 string& provincia = *provinciait;

		cout << "Provincia de " << provincia << ":" << endl;

		for (int mes = 0; mes < 12; mes++) {
			string nombreMes;

			switch (mes) {
			case 0: nombreMes = "Enero"; break;
			case 1: nombreMes = "Febrero"; break;
			case 2: nombreMes = "Marzo"; break;
			case 3: nombreMes = "Abril"; break;
			case 4: nombreMes = "Mayo"; break;
			case 5: nombreMes = "Junio"; break;
			case 6: nombreMes = "Julio"; break;
			case 7: nombreMes = "Agosto"; break;
			case 8: nombreMes = "Septiembre"; break;
			case 9: nombreMes = "Octubre"; break;
			case 10: nombreMes = "Noviembre"; break;
			case 11: nombreMes = "Diciembre"; break;
			}

			int cantidadDonaciones = 0;
			if (it != donacionesPorProvincia.end() && (*it)->provincia == provincia) {
				cantidadDonaciones = (*it)->cantidad;
				++it;
			}

			cout << nombreMes << ": " << cantidadDonaciones << " donaciones" << endl;
		}

	}
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

bool operator==( cReceptor& receptor,cDonante& donante) {
	return receptor.getFluido() == donante.getFluido();
}
ostream& operator <<(ostream& out, cBSA* bsa) {
	out << bsa->to_string();
	return out;
}