//nuevo
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
	const string id;
	string nombre;
	tm fechanac;
	char sexo;
	string peso;
	string centro_salud;//nombre del centro de salud, centro salud asociado, lo elije en el main, ya que los metodos no pueden tener ni cout ni cin
	string tipos_sangre;
	string rh;
	string fluido_elegido;
	string partido;
	string provincia;
public:
	cPaciente(const string id, string nombre, tm fechanac, char sexo, string peso, string tipos_sangre, string centro_salud, string rh, string fluido_elegido, string partido, string provincia);

	void set_tipo_de_Sangre_y_rh(cSangre* sangre);//HACEMOS UN SET DE LOS DOS, YA QUE EN LA VIDA REAL CUANDO SE INDICA LAS SABRE SE INDICA A PARTIR DEL TIPO Y DEL FACTOR RH
	string get_tipos_sangre();
	string get_rh();
	virtual void setFluido(string& fluido_elegido) = 0;  //EL METODO ABSTRACTO QUE IMPLEMENTAREMOS VA A SER ELELGIR FLUIDO, POR UN LADO LOS RECEPTORES ELEGIRIAN QUE RECIBIR, Y LOS PACIENTES QUE DONAR

	void set_centro_saludd(string& centro_salud);
	string get_centro_salud();
	void set_peso(string& peso);
	string get_peso();
	void set_fechanac(tm& fechanac);
	tm get_fechanac();
	string getFluido();
	string getpartido();
	void set_partido(string& partido);
	string getprovincia();
	void set_provincia(string& provincia);
	string get_id();
	void set_nombre(string& nombre);
	string get_nombre();
	~cPaciente();
};

//NUEVO