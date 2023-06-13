#pragma once
#include <string>
#include<iostream>
#include "cPaciente.h"
#include<list>
#include "cDonante.h"
#include"cReceptor.h"
using namespace std;
class cBsa;
class cCentro_de_salud {
private:
	string nombre;
	string partido;
	string provincia;
	string direccion;
	string telefono;
	list<cPaciente*> pacientes_del_centro;/* MI CENTRO VA A TENER SU PROPIA LISTA DE PACIENTES ASOCIADOS. ESTA SE VA A CARGAR DESDE EL MAIN,
luego en un metodo vamoa a ir COMPARANDO LOS NOMBRES DE LOS CENTROS DE CADA PACIENTE,Luego esta nueva lista de paciente asociados,Se la vamos a pasar a mi centro de salud */
public:
	cCentro_de_salud(string nombre, string partido, string provincia, string direccion, list<cPaciente*> pacientes_del_centro, string telefono);
	~cCentro_de_salud();
	void set_nombre(string &nombre);
	string get_nombre();
	void set_pacientes_del_centro(list<cPaciente*>& pacientes);
	list<cPaciente*> get_pacientes_del_centro();
	 void protocolo_de_transplante_final(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado);
	 friend class cBSA;
	 cCentro_de_salud();
};