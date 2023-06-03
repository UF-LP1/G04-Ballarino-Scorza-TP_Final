#pragma once
#include <string>
#include<iostream>
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
 ~cFluido();

};
