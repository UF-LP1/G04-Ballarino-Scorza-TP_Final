#pragma once
#include <string>
#include<iostream>
#include <ctime>
#include "cFluido.h"
#include"cPlasma.h" 
#include "cMedula_osea.h"
#include"cSangre.h"
#include<list>
using namespace std;
class cCentro_de_salud;/* no se puede agregar al encabezado #include cCentro_de_salud, ya que se crea un bucle (porque cPaciente ya esta llamado en cliente,
 y encontramos en la seccion foward declaration de cpp.reference que se resuelve asi, y se llama identificador de atributo de clave de clase */


class cPaciente {
protected:
	string nombre;
	tm fechanac;
	char sexo;
	string peso;
	string centro_salud;//nombre del centro de salud, centro salud asociado, lo elije en el main, ya que los metodos no pueden tener ni cout ni cin
	string tipos_sangre;
	string rh;
	string fluido_elegido;//Este sera una atributo que en los receptores sera el que quieren recibir, y en los donantes el que van a donar
//para esto, hacemos un metodo virtual puro llamado elegir fluido, donde en las clases hijas varia si es del donante o del receptor
public:
	cPaciente(string nombre,tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud,string rh, string fluido_elegido);
	
	void set_tipo_de_Sangre_y_rh(cFluido& fluido);//HACEMOS UN SET DE LOS DOS, YA QUE EN LA VIDA REAL CUANDO SE INDICA LAS SABRE SE INDICA A PARTIR DEL TIPO Y DEL FACTOR RH
	virtual void set_centro_de_salud(string& centro_salud) = 0;
	virtual void setFluido(string& fluido_elegido) = 0;  //EL METODO ABSTRACTO QUE IMPLEMENTAREMOS VA A SER ELELGIR FLUIDO, POR UN LADO LOS RECEPTORES ELEGIRIAN QUE RECIBIR, Y LOS PACIENTES QUE DONAR
	
	void set_centro_salud(string &centro_salud);
	string get_centro_salud();
	void set_peso(string &peso);
	string get_peso();
	void set_fechanac(tm fechanac);
	tm get_fechanac();
	string getFluido();
	~cPaciente();
};
