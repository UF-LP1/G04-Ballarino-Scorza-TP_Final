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
bool cSangre:: VerificarFechaMaxima(tm fecha) {
	time_t timer;
	time(&timer);   //usamos el timer para tener la fecha y hora actual 
	time_t fecha_ = mktime(&fecha);//el mktime nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	double  dist_fecha = 0;
	if (fecha_ != (time_t)(-1) && timer != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		dist_fecha = difftime(timer, fecha_); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por anio.
	}
	if (dist_fecha < (42 * 86400)) //ahora tengo cuantos anios tiene la persona en segundos, lo pasamos a anios y lo retornamos;
		return true;
	else
		return false;
}
cSangre::~cSangre(){}