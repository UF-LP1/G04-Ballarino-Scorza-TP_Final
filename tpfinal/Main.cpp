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

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;



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


    list<cDonante*>donantes;/* cDonante(const string id,string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh,string fluido_elegido ,string partido,string provincia, bool enfermedades, bool tatuaje, bool donacion, tm fecha_de_donacion)
    :cPaciente(id, nombre, fechanac, sexo, peso, tipos_sangre, centro_salud,rh,fluido_elegido, partido, provincia) {*/

    donantes.push_back(new cDonante("42356756", "pepe", obtenerFecha("12/3/2000"), 'm', "90kg", "A", "Hospital Italiano", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, false, obtenerFecha("12/3/2006")));
    donantes.push_back(new cDonante("52356756", "juan", obtenerFecha("4/7/1998"), 'm', "70kg", "B", "Hospital Italiano", "Negativo", "Sangre", "CABA", "Buenos Aires", true, false, true, obtenerFecha("10/9/2022")));
    donantes.push_back(new cDonante("62356756", "lucas", obtenerFecha("2/5/1995"), 'm', "80kg", "O", "Hospital Provincial", "Positivo", "Medula osea", "Catamarca", "Catamarca", false, false, true, obtenerFecha("18/7/2021")));
    donantes.push_back(new cDonante("72356756", "laura", obtenerFecha("15/9/1990"), 'f', "65kg", "AB", "Hospital Provincial", "Negativo", "Plasma", "Catamarca", "Catamarca", false, true, false, obtenerFecha("22/11/2022")));
    donantes.push_back(new cDonante("82356756", "carlos", obtenerFecha("10/12/1988"), 'm', "75kg", "B", "Hospital de Clínicas", "Positivo", "Medula osea", "Córdoba", "Córdoba", true, false, true, obtenerFecha("30/4/2023")));
    donantes.push_back(new cDonante("92356756", "maria", obtenerFecha("25/6/1993"), 'f', "60kg", "A", "Hospital de Clínicas", "Negativo", "Sangre", "Córdoba", "Córdoba", false, true, false, obtenerFecha("11/9/2021")));
    donantes.push_back(new cDonante("10356756", "luis", obtenerFecha("7/11/1997"), 'm', "70kg", "AB", "Hospital del Milagro", "Positivo", "Medula osea", "Salta", "Salta", true, false, true, obtenerFecha("5/2/2022")));
    donantes.push_back(new cDonante("11356756", "carolina", obtenerFecha("14/2/1992"), 'f', "55kg", "O", "Hospital del Milagro", "Negativo", "Sangre", "Salta", "Salta", false, true, false, obtenerFecha("17/6/2023")));
    donantes.push_back(new cDonante("12356756", "fernando", obtenerFecha("9/8/1994"), 'm', "85kg", "B", "Hospital Regional Resistencia", "Positivo", "Medula osea", "Resistencia", "Chaco", false, false, true, obtenerFecha("8/1/2022")));
    donantes.push_back(new cDonante("13356756", "sofia", obtenerFecha("22/4/1989"), 'f', "65kg", "A", "Hospital Regional Resistencia", "Negativo", "Plasma", "Resistencia", "Chaco", true, true, false, obtenerFecha("27/7/2022")));
    donantes.push_back(new cDonante("14356756", "rodrigo", obtenerFecha("17/6/1991"), 'm', "75kg", "O", "Hospital Ramos Mejía", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("19/10/2022")));
    donantes.push_back(new cDonante("15356756", "lucia", obtenerFecha("29/10/1996"), 'f', "60kg", "AB", "Hospital Ramos Mejía", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("2/4/2022")));
    donantes.push_back(new cDonante("16356756", "oscar", obtenerFecha("3/12/1998"), 'm', "80kg", "B", "Hospital de Niños", "Positivo", "Medula osea", "La Plata", "Buenos Aires", false, false, true, obtenerFecha("20/3/2023")));
    donantes.push_back(new cDonante("17356756", "camila", obtenerFecha("16/1/1993"), 'f', "55kg", "O", "Hospital de Niños", "Negativo", "Sangre", "La Plata", "Buenos Aires", true, true, false, obtenerFecha("11/8/2022")));
    donantes.push_back(new cDonante("18356756", "nicolas", obtenerFecha("9/7/1995"), 'm', "70kg", "A", "Hospital Alemán", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("29/11/2022")));
    donantes.push_back(new cDonante("19356756", "valentina", obtenerFecha("12/10/1990"), 'f', "65kg", "B", "Hospital Alemán", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("4/5/2022")));
    donantes.push_back(new cDonante("20356756", "julian", obtenerFecha("21/2/1988"), 'm', "80kg", "AB", "Hospital Pirovano", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("1/1/2023")));
    donantes.push_back(new cDonante("21356756", "soledad", obtenerFecha("14/5/1993"), 'f', "60kg", "O", "Hospital Pirovano", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("8/7/2022")));
    donantes.push_back(new cDonante("22356756", "lucas", obtenerFecha("30/9/1997"), 'm', "70kg", "A", "Hospital Durand", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("25/11/2022")));
    donantes.push_back(new cDonante("23356756", "mariana", obtenerFecha("18/3/1992"), 'f', "55kg", "B", "Hospital Durand", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("14/6/2022")));
    donantes.push_back(new cDonante("24356756", "martin", obtenerFecha("11/7/1995"), 'm', "75kg", "AB", "Hospital Argerich", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("21/2/2023")));
    donantes.push_back(new cDonante("25356756", "natalia", obtenerFecha("23/12/1990"), 'f', "65kg", "O", "Hospital Argerich", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("3/7/2022")));
    donantes.push_back(new cDonante("26356756", "diego", obtenerFecha("9/11/1994"), 'm', "80kg", "A", "Hospital Británico", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("29/10/2022")));
    donantes.push_back(new cDonante("27356756", "romina", obtenerFecha("2/5/1989"), 'f', "60kg", "B", "Hospital Británico", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("7/6/2022")));
    donantes.push_back(new cDonante("28356756", "matias", obtenerFecha("17/3/1993"), 'm', "70kg", "AB", "Hospital Austral", "Positivo", "Medula osea", "Pilar", "Buenos Aires", false, false, true, obtenerFecha("26/11/2022")));
    donantes.push_back(new cDonante("29356756", "ana", obtenerFecha("14/9/1988"), 'f', "55kg", "O", "Hospital Austral", "Negativo", "Sangre", "Pilar", "Buenos Aires", true, true, false, obtenerFecha("5/6/2022")));
    donantes.push_back(new cDonante("30356756", "roberto", obtenerFecha("28/1/1997"), 'm', "75kg", "A", "Hospital Español", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("14/12/2022")));
    donantes.push_back(new cDonante("31356756", "mariana", obtenerFecha("22/5/1992"), 'f', "60kg", "B", "Hospital Español", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("11/7/2022")));
    donantes.push_back(new cDonante("32356756", "francisco", obtenerFecha("10/8/1995"), 'm', "80kg", "AB", "Hospital Italiano", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("30/11/2022")));
    donantes.push_back(new cDonante("33356756", "rocio", obtenerFecha("13/2/1990"), 'f', "65kg", "O", "Hospital Italiano", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("2/5/2022")));
    donantes.push_back(new cDonante("34356756", "gaston", obtenerFecha("6/11/1994"), 'm', "75kg", "A", "Hospital Provincial", "Positivo", "Medula osea", "Catamarca", "Catamarca", false, false, true, obtenerFecha("10/10/2022")));
    donantes.push_back(new cDonante("35356756", "ana", obtenerFecha("19/7/1989"), 'f', "60kg", "B", "Hospital Provincial", "Negativo", "Plasma", "Catamarca", "Catamarca", true, true, false, obtenerFecha("17/3/2022")));
    donantes.push_back(new cDonante("36356756", "mauro", obtenerFecha("2/4/1993"), 'm', "70kg", "AB", "Hospital del Milagro", "Positivo", "Medula osea", "Salta", "Salta", false, false, true, obtenerFecha("29/8/2022")));
    donantes.push_back(new cDonante("37356756", "soledad", obtenerFecha("25/8/1988"), 'f', "55kg", "O", "Hospital del Milagro", "Negativo", "Sangre", "Salta", "Salta", true, true, false, obtenerFecha("5/4/2022")));
    donantes.push_back(new cDonante("38356756", "luciano", obtenerFecha("20/2/1992"), 'm', "80kg", "A", "Hospital Regional Resistencia", "Positivo", "Medula osea", "Resistencia", "Chaco", false, false, true, obtenerFecha("12/7/2022")));
    donantes.push_back(new cDonante("39356756", "julieta", obtenerFecha("15/11/1997"), 'f', "65kg", "B", "Hospital Regional Resistencia", "Negativo", "Plasma", "Resistencia", "Chaco", true, true, false, obtenerFecha("9/3/2022")));
    donantes.push_back(new cDonante("40356756", "pablo", obtenerFecha("10/7/1990"), 'm', "75kg", "AB", "Hospital Ramos Mejía", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("18/12/2022")));
    donantes.push_back(new cDonante("41356756", "andrea", obtenerFecha("3/4/1995"), 'f', "60kg", "O", "Hospital Ramos Mejía", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("6/8/2022")));
    donantes.push_back(new cDonante("42356756", "daniel", obtenerFecha("16/12/1999"), 'm', "70kg", "A", "Hospital de Niños", "Positivo", "Medula osea", "La Plata", "Buenos Aires", false, false, true, obtenerFecha("23/11/2022")));
    donantes.push_back(new cDonante("43356756", "mariana", obtenerFecha("29/5/1994"), 'f', "55kg", "B", "Hospital de Niños", "Negativo", "Plasma", "La Plata", "Buenos Aires", true, true, false, obtenerFecha("18/5/2022")));
    donantes.push_back(new cDonante("44356756", "gabriel", obtenerFecha("7/9/1996"), 'm', "75kg", "O", "Hospital Alemán", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("4/12/2022")));
    donantes.push_back(new cDonante("45356756", "romina", obtenerFecha("11/3/1991"), 'f', "65kg", "A", "Hospital Alemán", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("7/7/2022")));
    donantes.push_back(new cDonante("46356756", "luis", obtenerFecha("14/6/1993"), 'm', "70kg", "AB", "Hospital Pirovano", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("15/11/2022")));
    donantes.push_back(new cDonante("47356756", "mariana", obtenerFecha("9/11/1998"), 'f', "60kg", "O", "Hospital Pirovano", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("22/6/2022")));
    donantes.push_back(new cDonante("48356756", "matias", obtenerFecha("22/4/1989"), 'm', "75kg", "A", "Hospital Durand", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("2/12/2022")));
    donantes.push_back(new cDonante("49356756", "sofia", obtenerFecha("17/10/1992"), 'f', "55kg", "B", "Hospital Durand", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("21/7/2022")));
    donantes.push_back(new cDonante("50356756", "lucas", obtenerFecha("30/6/1997"), 'm', "70kg", "O", "Hospital Argerich", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("10/11/2022")));
    donantes.push_back(new cDonante("51356756", "maria", obtenerFecha("13/1/1992"), 'f', "60kg", "A", "Hospital Argerich", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("8/6/2022")));
    donantes.push_back(new cDonante("52356756", "julian", obtenerFecha("26/3/1995"), 'm', "80kg", "AB", "Hospital Británico", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("27/10/2022")));
    donantes.push_back(new cDonante("53356756", "camila", obtenerFecha("29/9/1990"), 'f', "65kg", "O", "Hospital Británico", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("14/5/2022")));
    donantes.push_back(new cDonante("54356756", "juan", obtenerFecha("2/11/1994"), 'm', "75kg", "A", "Hospital Austral", "Positivo", "Medula osea", "Pilar", "Buenos Aires", false, false, true, obtenerFecha("23/12/2022")));
    //





    list<cReceptor*>receptores;
 receptores.push_back(new cReceptor("42356758", "pepe", obtenerFecha("12/3/2000"), 'm', "90kg", "A", "Hospital Italiano", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, false, obtenerFecha("12/3/2006")));
 receptores.push_back(new cReceptor("52356758", "juan", obtenerFecha("4/7/1998"), 'm', "70kg", "B", "Hospital Italiano", "Negativo", "Sangre", "CABA", "Buenos Aires", true, false, true, obtenerFecha("10/9/2022")));
 receptores.push_back(new cReceptor("62356758", "lucas", obtenerFecha("2/5/1995"), 'm', "80kg", "O", "Hospital Provincial", "Positivo", "Medula osea", "Catamarca", "Catamarca", false, false, true, obtenerFecha("18/7/2021")));
 receptores.push_back(new cReceptor("72356758", "laura", obtenerFecha("15/9/1990"), 'f', "65kg", "AB", "Hospital Provincial", "Negativo", "Plasma", "Catamarca", "Catamarca", false, true, false, obtenerFecha("22/11/2022")));
 receptores.push_back(new cReceptor("82356756", "carlos", obtenerFecha("10/12/1988"), 'm', "75kg", "B", "Hospital de Clínicas", "Positivo", "Medula osea", "Córdoba", "Córdoba", true, false, true, obtenerFecha("30/4/2023")));
 receptores.push_back(new cReceptor("92356758", "maria", obtenerFecha("25/6/1993"), 'f', "60kg", "A", "Hospital de Clínicas", "Negativo", "Sangre", "Córdoba", "Córdoba", false, true, false, obtenerFecha("11/9/2021")));
 receptores.push_back(new cReceptor("10356758", "luis", obtenerFecha("7/11/1997"), 'm', "70kg", "AB", "Hospital del Milagro", "Positivo", "Medula osea", "Salta", "Salta", true, false, true, obtenerFecha("5/2/2022")));
 receptores.push_back(new cReceptor("11356758", "carolina", obtenerFecha("14/2/1992"), 'f', "55kg", "O", "Hospital del Milagro", "Negativo", "Sangre", "Salta", "Salta", false, true, false, obtenerFecha("17/6/2023")));
 receptores.push_back(new cReceptor("12356758", "fernando", obtenerFecha("9/8/1994"), 'm', "85kg", "B", "Hospital Regional Resistencia", "Positivo", "Medula osea", "Resistencia", "Chaco", false, false, true, obtenerFecha("8/11/2022")));
receptores.push_back(new cReceptor("13356758", "sofia", obtenerFecha("22/4/1989"), 'f', "65kg", "A", "Hospital Regional Resistencia", "Negativo", "Plasma", "Resistencia", "Chaco", true, true, false, obtenerFecha("27//2022"))); receptores.push_back(new cReceptor("14356756", "rodrigo", obtenerFecha("17/6/1991"), 'm', "75kg", "O", "Hospital Ramos Mejía", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("19/10/2022")));
receptores.push_back(new cReceptor("15356758", "lucia", obtenerFecha("29/10/1996"), 'f', "60kg", "AB", "Hospital Ramos Mejía", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("/4/2022"));
receptores.push_back(new cReceptor("16356758", "oscar", obtenerFecha("3/12/1998"), 'm', "80kg", "B", "Hospital de Niños", "Positivo", "Medula osea", "La Plata", "Buenos Aires", false, false, true, obtenerFecha("20/3/203")));
receptores.push_back(new cReceptor("17356758", "camila", obtenerFecha("16/1/1993"), 'f', "55kg", "O", "Hospital de Niños", "Negativo", "Sangre", "La Plata", "Buenos Aires", true, true, false, obtenerFecha("11/8/202")));
receptores.push_back(new cReceptor("18356758", "nicolas", obtenerFecha("9/7/1995"), 'm', "70kg", "A", "Hospital Alemán", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("29/11/202")));
receptores.push_back(new cReceptor("19356758", "valentina", obtenerFecha("12/10/1990"), 'f', "65kg", "B", "Hospital Alemán", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("4/5/2022"));
receptores.push_back(new cReceptor("20356758", "julian", obtenerFecha("21/2/1988"), 'm', "80kg", "AB", "Hospital Pirovano", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("1/1/2023")));
receptores.push_back(new cReceptor("21356756", "soledad", obtenerFecha("14/5/1993"), 'f', "60kg", "O", "Hospital Pirovano", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("8/7/2022"));
receptores.push_back(new cReceptor("22356758", "lucas", obtenerFecha("30/9/1997"), 'm', "70kg", "A", "Hospital Durand", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("25/11/202")));
receptores.push_back(new cReceptor("23356758", "mariana", obtenerFecha("18/3/1992"), 'f', "55kg", "B", "Hospital Durand", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("14/6/2022")));
receptores.push_back(new cReceptor("24356758", "martin", obtenerFecha("11/7/1995"), 'm', "75kg", "AB", "Hospital Argerich", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("21/2/223")));
receptores.push_back(new cReceptor("25356758", "natalia", obtenerFecha("23/12/1990"), 'f', "65kg", "O", "Hospital Argerich", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("3/7/2022")));
receptores.push_back(new cReceptor("26356758", "diego", obtenerFecha("9/11/1994"), 'm', "80kg", "A", "Hospital Británico", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("29/10/2022")));
receptores.push_back(new cReceptor("27356758", "romina", obtenerFecha("2/5/1989"), 'f', "60kg", "B", "Hospital Británico", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("7/6/202")));
receptores.push_back(new cReceptor("28356758", "matias", obtenerFecha("17/3/1993"), 'm', "70kg", "AB", "Hospital Austral", "Positivo", "Medula osea", "Pilar", "Buenos Aires", false, false, true, obtenerFecha("2/11/2022")));
receptores.push_back(new cReceptor("29356758", "ana", obtenerFecha("14/9/1988"), 'f', "55kg", "O", "Hospital Austral", "Negativo", "Sangre", "Pilar", "Buenos Aires", true, true, false, obtenerFecha("5/6/2022")));
receptores.push_back(new cReceptor("30356758", "roberto", obtenerFecha("28/1/1997"), 'm', "75kg", "A", "Hospital Español", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("14/12/2022"))); receptores.push_back(new cReceptor("32356756", "francisco", obtenerFecha("10/8/1995"), 'm', "80kg", "AB", "Hospital Italiano", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("0/11/2022")));
receptores.push_back(new cReceptor("33356758", "rocio", obtenerFecha("13/2/1990"), 'f', "65kg", "O", "Hospital Italiano", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("2/5/2022"));
receptores.push_back(new cReceptor("34356758", "gaston", obtenerFecha("6/11/1994"), 'm', "75kg", "A", "Hospital Provincial", "Positivo", "Medula osea", "Catamarca", "Catamarca", false, false, true, obtenerFecha("10/10/2022")));
receptores.push_back(new cReceptor("35356758", "ana", obtenerFecha("19/7/1989"), 'f', "60kg", "B", "Hospital Provincial", "Negativo", "Plasma", "Catamarca", "Catamarca", true, true, false, obtenerFecha("17/3/2022")));
receptores.push_back(new cReceptor("36356758", "mauro", obtenerFecha("2/4/1993"), 'm', "70kg", "AB", "Hospital del Milagro", "Positivo", "Medula osea", "Salta", "Salta", false, false, true, obtenerFecha("29/8/2022")));
receptores.push_back(new cReceptor("37356758", "soledad", obtenerFecha("25/8/1988"), 'f', "55kg", "O", "Hospital del Milagro", "Negativo", "Sangre", "Salta", "Salta", true, true, false, obtenerFecha("5/4/2022")));
receptores.push_back(new cReceptor("38356788", "luciano", obtenerFecha("20/2/1992"), 'm', "80kg", "A", "Hospital Regional Resistencia", "Positivo", "Medula osea", "Resistencia", "Chaco", false, false, true, obtenerFecha("12/7/2022")));
receptores.push_back(new cReceptor("39356758", "julieta", obtenerFecha("15/11/1997"), 'f', "65kg", "B", "Hospital Regional Resistencia", "Negativo", "Plasma", "Resistencia", "Chaco", true, true, false, obtenerFecha("9/3/2022")));
receptores.push_back(new cReceptor("40356758", "pablo", obtenerFecha("10/7/1990"), 'm', "75kg", "AB", "Hospital Ramos Mejía", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("18/12/2022")));
receptores.push_back(new cReceptor("41356758", "andrea", obtenerFecha("3/4/1995"), 'f', "60kg", "O", "Hospital Ramos Mejía", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("6/8/2022")));
receptores.push_back(new cReceptor("42356758", "daniel", obtenerFecha("16/12/1999"), 'm', "70kg", "A", "Hospital de Niños", "Positivo", "Medula osea", "La Plata", "Buenos Aires", false, false, true, obtenerFecha("23/11/2022")));
receptores.push_back(new cReceptor("43356758", "mariana", obtenerFecha("29/5/1994"), 'f', "55kg", "B", "Hospital de Niños", "Negativo", "Plasma", "La Plata", "Buenos Aires", true, true, false, obtenerFecha("18/5/2022")));
receptores.push_back(new cReceptor("44356758", "gabriel", obtenerFecha("7/9/1996"), 'm', "75kg", "O", "Hospital Alemán", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("4/12/2022")));
receptores.push_back(new cReceptor("45356758", "romina", obtenerFecha("11/3/1991"), 'f', "65kg", "A", "Hospital Alemán", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("7/7/2022")));
receptores.push_back(new cReceptor("46356758", "luis", obtenerFecha("14/6/1993"), 'm', "70kg", "AB", "Hospital Pirovano", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("15/11/2022")));
receptores.push_back(new cReceptor("47356758", "mariana", obtenerFecha("9/11/1998"), 'f', "60kg", "O", "Hospital Pirovano", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("22/6/2022")));
receptores.push_back(new cReceptor("48356758", "matias", obtenerFecha("22/4/1989"), 'm', "75kg", "A", "Hospital Durand", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("2/12/2022")));
receptores.push_back(new cReceptor("49356758", "sofia", obtenerFecha("17/10/1992"), 'f', "55kg", "B", "Hospital Durand", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("21/7/2022")));
receptores.push_back(new cReceptor("50356758", "lucas", obtenerFecha("30/6/1997"), 'm', "70kg", "O", "Hospital Argerich", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("10/11/2022")));
receptores.push_back(new cReceptor("51356758", "maria", obtenerFecha("13/1/1992"), 'f', "60kg", "A", "Hospital Argerich", "Negativo", "Plasma", "CABA", "Buenos Aires", true, true, false, obtenerFecha("8/6/2022")));
receptores.push_back(new cReceptor("52356758", "julian", obtenerFecha("26/3/1995"), 'm', "80kg", "AB", "Hospital Británico", "Positivo", "Medula osea", "CABA", "Buenos Aires", false, false, true, obtenerFecha("27/10/2022")));
receptores.push_back(new cReceptor("53356758", "camila", obtenerFecha("29/9/1990"), 'f', "65kg", "O", "Hospital Británico", "Negativo", "Sangre", "CABA", "Buenos Aires", true, true, false, obtenerFecha("14/5/2022")));
receptores.push_back(new cReceptor("54356758", "juan", obtenerFecha("2/11/1994"), 'm', "75kg", "A", "Hospital Austral", "Positivo", "Medula osea", "Pilar", "Buenos Aires", false, false, true, obtenerFecha("23/12/2022")));
        
tm obtenerFecha(const string & fechaString) {
        tm fecha = {};
        istringstream ss(fechaString);
        ss >> std::get_time(&fecha, "%d/%m/%Y");
        if (ss.fail()) {
            // Error al analizar la cadena de fecha
            std::cout << "Error al analizar la fecha: " << fechaString << std::endl;
        }
        return fecha;
    }