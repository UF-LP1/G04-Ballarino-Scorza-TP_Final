#pragma once
#include <string>
#include<iostream>
#include <list>
using namespace std;
#include"cPaciente.h"
#include "cReceptor.h"
#include "CDonante.h"
#include "cCentro_de_salud.h"


class cBSA {
private:

	list<cReceptor*> receptores;
	list<cPaciente*>recp_y_don_plasma;
    list<cPaciente*>recp_y_don_sangre;
    list<cPaciente*>recp_y_don_medula_osea;
	list<cDonante*> donantes;
	list<cCentro_de_salud*> centros_de_salud;
	
	
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
	void separar_segun_fluido(list<cReceptor*> receptores, list<cDonante*> donantes);
	
	cReceptor* match(string& fluido);//LA IDEA ES QUE EL BANCO DE SANGRE SELECCIOENE EL FLUIDO QUE QUIERA HACER EL MATCH

	cReceptor* receptor_prioridad(list<cPaciente*>& lista_receptores, cReceptor* receptor_seleccionado);
	cDonante* buscar_donante_compatibles(list<cPaciente*>& lista_donante, cDonante* donante_seleccionado);
	~cBSA();

};
double distancia_fechas(tm fecha);//LA USAMOS PARA COMPARAR LAS DISTANCIAS RESPECTO A LA FECHA DE HOY, COMO LA EDAD, FECHAS DE INGRESO.
tm setear_fecha_ingreso_espera();//	SETEO LA FECHA DE INGRESO CON LA FECHA DE HOY, EN EL SENTIDO QUE SERIA EL DIA QUE LLEGO
