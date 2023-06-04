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
	//QUE YA ESTA CONTENIDO EN LA CLASE
	~cBSA();

};