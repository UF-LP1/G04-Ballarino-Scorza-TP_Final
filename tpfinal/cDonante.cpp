#include"cDonante.h"
//nuevo
cDonante::cDonante(const string id, string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_elegido, string partido, string provincia, bool enfermedades, bool tatuaje, bool donacion, tm fecha_de_donacion) :cPaciente(id, nombre, fechanac, sexo, peso, tipos_sangre, centro_salud, rh, fluido_elegido, partido, provincia) {
	this->enfermedades = enfermedades;
	this->tatuaje = tatuaje;
	this->donacion = donacion;
	this->fecha_de_donacion = fecha_de_donacion;
}
void cDonante::setFluido(string& fluido_elegido) {
	this->fluido_elegido = fluido_elegido;
}
void cDonante::set_enfermedades(bool& enfermedades) {
	this->enfermedades = enfermedades;
}
void cDonante::set_tatuaje(bool& tatuaje) {
	this->tatuaje = tatuaje;
}
void cDonante::set_donacion(bool& donacion) {
	this->donacion = donacion;
}
bool cDonante::get_enfermedades() {
	return this->enfermedades;
}
bool cDonante::get_tatuaje() {
	return this->tatuaje;
}
bool cDonante::get_donacion() {
	return this->donacion;
}
void cDonante::set_fecha_de_donacion(tm fecha_de_donacion) {
	this->fecha_de_donacion = fecha_de_donacion;
}
tm cDonante::get_fecha_de_donacion() {
	return this->fecha_de_donacion;
}
void cDonante::set_registro_de_donaciones() {
	cRegistro_don* nuevo_registro = new cRegistro_don(fluido_elegido, fecha_de_donacion, centro_salud);

	// Agregamos el nuevo registro a la lista de donaciones del donante
	registro_de_donaciones.push_back(nuevo_registro);
}

string cDonante::to_string() {
	stringstream s;
	s << "Atributos del donante: " << "ID: " << id << ", " << "Nombre: " << nombre << ", " << "Sexo: " << sexo << ", " << "Peso: " << peso << ", "
		<< "Centro de salud: " << centro_salud << ", " << "Tipo de sangre: " << tipos_sangre << ", " << "RH: " << rh << ", " << "Fluido elegido: " << fluido_elegido << ", " << "partido" << partido << "," << "provincia" << provincia<<endl;
	return s.str();
}

cDonante::~cDonante() {

	list<cRegistro_don*>::iterator it;
	for (it = registro_de_donaciones.begin(); it != registro_de_donaciones.end(); ++it) {
		delete (*it);
	}

}
//NUEVO