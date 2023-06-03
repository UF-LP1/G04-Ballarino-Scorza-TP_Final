#pragma once
#include <string>
#include<iostream>
#include <ctime>
#include "cFluido.h"
#include"cSangre.h"
using namespace std;

class cPaciente {
protected:
	string nombre;
	tm fechanac;
	char sexo;
	string peso;
	string centro_salud;
	string tipos_sangre;
	string rh;
	string fluido_elegido;//Este sera una atributo que en los receptores sera el que quieren recibir, y en los donantes el que van a donar
//para esto, hacemos un metodo virtual puro llamado elegir fluido, donde en las clases hijas varia si es del donante o del receptor
public:
	cPaciente(string nombre,tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud,string rh, string fluido_elegido);
	void set_tipo_de_Sangre_y_rh(cFluido& fluido);//HACEMOS UN SET DE LOS DOS, YA QUE EN LA VIDA REAL CUANDO SE INDICA LAS SABRE SE INDICA A PARTIR DEL TIPO Y DEL FACTOR RH
	
	virtual void setFluido(string& fluido_elegido) = 0;  //EL METODO ABSTRACTO QUE IMPLEMENTAREMOS VA A SER ELELGIR FLUIDO, POR UN LADO LOS RECEPTORES ELEGIRIAN QUE RECIBIR, Y LOS PACIENTES QUE DONAR
	
	~cPaciente();
};
