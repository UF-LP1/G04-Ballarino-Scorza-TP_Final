#pragma once
#include <string>
#include<iostream>
#include <list>
using namespace std;
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

	~cBSA();

};