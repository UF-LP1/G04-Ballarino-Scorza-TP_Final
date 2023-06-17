#include <list>
#include<iostream>
#include"cBSA.h"
#include"cCentro_de_salud.h"
#include"cDonante.h"
#include"cReceptor.h"
#include"cSangre.h"
#include"cMedula_osea.h"
#include"cPlasma.h"
#include"cRegistro_don.h"

int main() {
	list<cCentro_de_salud*>Centrodesalud;
    //creo centro de salud 
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Italiano", "CABA", "Buenos Aires", "Potosí 4240", "011 4959-0200"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Provincial", "Catamarca", "Catamarca", "Av. Virgen del Valle 982", "0383 443-3322"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital de Clínicas", "Córdoba", "Córdoba", "Av. Enrique Barros S/N", "0351 433-4410"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital del Milagro", "Salta", "Salta", "Av. Bicentenario de la Batalla de Salta 1450", "0387 431-7000"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Regional Resistencia", "Resistencia", "Chaco", "Av. 9 de Julio 150", "0362 442-6400"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital San Bernardo", "Salta", "Salta", "Av. Venezuela 1650", "0387 431-9000"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Cullen", "Santa Fe", "Santa Fe", "Av. Gdor. Freyre 2150", "0800 555-6549"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Provincial Formosa", "Formosa", "Formosa", "Av. 9 de Julio 320", "0370 443-1240"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital de Alta Complejidad El Cruce", "Florencio Varela", "Buenos Aires", "Camino de Cintura y Calle 17", "011 4210-9900"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital de Clínicas", "Buenos Aires", "Buenos Aires", "Av. Córdoba 2351", "011 5950-8000"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital San Martín", "La Plata", "Buenos Aires", "Calle 1 y 70", "0221 453-7000"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Regional Ushuaia", "Ushuaia", "Tierra del Fuego", "San Martín 1052", "02901 422-222"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Público Materno Infantil", "Salta", "Salta", "Av. Juan Domingo Perón 1002", "0387 425-2444"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Rio Gallegos", "Río Gallegos", "Santa Cruz", "Pte. Raúl Alfonsín 355", "02966 42-0123"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Provincial", "La Rioja", "La Rioja", "Av. Ortiz de Ocampo 1050", "03822 42-1000"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Rawson", "Córdoba", "Córdoba", "Av. Ejército Argentino 1310", "0800 888-6864"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Garrahan", "CABA", "Buenos Aires", "Combate de los Pozos 1881", "011 4943-1000"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Austral", "Bahía Blanca", "Buenos Aires", "Colón 550", "0291 451-6500"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Quirurjico", "Comodoro Rivadavia", "Chubut", "Av. Rivadavia 460", "0800 999-5200"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital J. B. Iturraspe", "San Francisco", "Córdoba", "Av. Dr. Ignacio Crescenti 1461", "0800 555-6549"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital San Roque", "Paraná", "Entre Ríos", "Av. Ramírez 1999", "0343 420-9223"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Pasteur", "Villa María", "Córdoba", "Av. Perón 2222", "0353 453-3000"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital Santo Tomas", "Mendoza", "Mendoza", "Av. Acceso Este 1150", "0261 449-4000"));
    Centrodesalud.push_back(new cCentro_de_salud("Hospital de Alta Complejidad El Cruce", "Florencio Varela", "Buenos Aires", "Camino de Cintura y Calle 17", "011 4210-9900"));
    //
    list<cDonante*>Donantes;/* cDonante(const string id,string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh,string fluido_elegido ,string partido,string provincia, bool enfermedades, bool tatuaje, bool donacion, tm fecha_de_donacion)
    :cPaciente(id, nombre, fechanac, sexo, peso, tipos_sangre, centro_salud,rh,fluido_elegido, partido, provincia) {*/
    Donantes.push_back(new cDonante("42356756","pepe","12/3/2000",'m', "90kg", "A", "Hospital Italiano", "Positivo", "Sangre", "CABA", "Buenos Aires", false, false, false, "14/10/2021");

	return 0;
}