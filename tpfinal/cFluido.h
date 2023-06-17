#pragma once
#include <string>
#include<iostream>
#include<ctime>
using namespace std;

class cFluido {
protected:
	string estado;
public:
	cFluido(string estado);
	/* COMO TENEMOS QUE HACER UN METODO VIRTUAL PORQUE DEBEMOS HACER DYNAMIC CAST, VAMOS A HACER UN GET TIPO DE FLUIDO, ESTE SERA VIRTUAL PURO,
Y ESTA REDEFINIDO EN CADA CLASE INDICANDO EL FLUIDO DE CADA CLASE 
 */
	virtual string getTipoFluido() = 0;
	virtual bool VerificarFechaMaxima(tm fecha)=0;//La idea es que cada organo devuelva true o false, esto sera a partir de la fecha que se realizo la donacion,
 ~cFluido();

};
