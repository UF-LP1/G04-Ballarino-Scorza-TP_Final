#include "cMedula_osea.h"

cMedula_osea::cMedula_osea(string estado,string color) :cFluido( estado) {
	this->color = color;
}
string cMedula_osea::getTipoFluido() {
	return "Medula osea";
}
bool cMedula_osea::VerificarFechaMaxima(tm fecha) {
	time_t timer;
	time(&timer);   //usamos el timer para tener la fecha y hora actual 
	time_t fecha_ = mktime(&fecha);//el mktime nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	double  dist_fecha = 0;
	if (fecha_ != (time_t)(-1) && timer != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		dist_fecha = difftime(timer, fecha_); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por anio.
	}
	if (dist_fecha < 86400) //ahora tengo cuantos anios tiene la persona en segundos, lo pasamos a anios y lo retornamos;
		return true;
	else
		return false;
}
cMedula_osea::~cMedula_osea(){}