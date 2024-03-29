//nuevo
#pragma once
#include <string>
#include<iostream>
#include "cPaciente.h"
#include<list>
#include "cDonante.h"
#include"cReceptor.h"
#include<algorithm>
#include "cBSA.h"
#include <cstdlib>
#include "cFluido.h"
#include"cSangre.h"
#include"cMedula_osea.h"
#include "cPlasma.h"
#include<sstream>
using namespace std;
class cBSA;
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
	cCentro_de_salud(string nombre, string partido, string provincia, string direccion, string telefono);
	~cCentro_de_salud();
	void set_nombre(string& nombre);
	string get_nombre();
	void set_pacientes_del_centro(list<cPaciente*>& pacientes);//AGREGO PACIENTES A LA LISTA
	list<cPaciente*> get_pacientes_del_centro();
	void protocolo_de_transplante_final(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado, list<cReceptor*> receptores);
	friend class cBSA;
	string to_string();
	cCentro_de_salud();
};

int consrandom();

list<cReceptor*> operator-(list<cReceptor*>& receptores, cReceptor* receptor_seleccionado);
bool operator==(list<cPaciente*> pacientes, cPaciente* paciente);
list<cPaciente*> operator+(list<cPaciente*>& pacientes, cPaciente* paciente);
//nuevo