#pragma once
#include <string>
#include<iostream>
#include <list>
#include<sstream>
using namespace std;
#include"cPaciente.h"
#include "cReceptor.h"
#include "CDonante.h"
#include "cCentro_de_salud.h"

struct DonacionesProvincia {
	string provincia;
	int cantidad;
};
class cBSA {
private:

	list<cReceptor*> receptores;
	list<cDonante*> donantes;
	list<cCentro_de_salud*> centros_de_salud;
	list<DonacionesProvincia*> donacionesPorProvincia;
	
public:
	cBSA(list<cReceptor*> receptores, list<cDonante*> donantes, list<cCentro_de_salud*> centros_de_salud);
	void set_lista_de_centros(list<cCentro_de_salud*> centros_de_salud);
	list<cCentro_de_salud*> get_lista_de_centros();
	/*QUEREMOS QUE LAS LISTAS DE RECEPTORES Y DONANTES DE MI CLASE BSA SE CARGUE, ENTONCES A TRAVES DE UN METODO QUE RECORRE 
	TODA LAS LISTA DEL CENTROS DE SALUD Y A SU VEZ, LA LISTA DE PACIENTES, DENTRO DE CADA CENTRO DE SALUD,
	Y SEPARANDOLOS EN RECEPTORES Y DONANTES, SEGUN LAS CONDICIONES	
	*/
	void set_receptores_y_donantes();//IMPORTANTE REMARCAR QUE EL SET NO RECIBE NADA YA QUE SE CARGAN A PARTIR DEL ATRIBUTO CENTRO DE SALUD
	//QUE YA ESTA CONTENIDO EN LA CLASE, ESTE TIENE SUS LISTAS DE PACIENTES
	list<cPaciente*>& separar_segun_fluido(cDonante* donante);
	
	cReceptor* match(cDonante* donante);//LA IDEA ES ENCONTRAR UN RECPTOR AL DONANTE
	list<cPaciente*>& ordenar_por_prioridad(list<cPaciente*>& listafluido_recp);//Ordena por prioridad
	cReceptor* buscar_receptor_compatibles_sangre(cDonante* donante_seleccionado, list<cPaciente*>& listafluido_recp);
	bool verificar_compatibilidad_sangre(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado);
	bool protocolo_transplante_inicio(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado);
	list<cReceptor*>& get_receptores();
	list<cReceptor*> receptores_de_un_centro(string centro_de_salud);
	unsigned int prioridad_de_receptor(cReceptor* receptor_seleccionado);
	string to_string();
	void imprimir(cBSA* cbsa);
	friend ostream& operator <<(ostream& out, cBSA* bsa);
	void generarInformeDonacionesPorProvincia();
	~cBSA();

};
double distancia_fechas(tm fecha);//LA USAMOS PARA COMPARAR LAS DISTANCIAS RESPECTO A LA FECHA DE HOY, COMO LA EDAD, FECHAS DE INGRESO.
tm setear_fecha_ingreso_espera();//	SETEO LA FECHA DE INGRESO CON LA FECHA DE HOY, EN EL SENTIDO QUE SERIA EL DIA QUE LLEGO
bool operator==(cReceptor& receptor,cDonante& donante);
