/*int valor = 0;//el valor que debe ingresar
cout << "Lista de nombres de centros de salud:" << endl;
for (list<cCentro_de_salud*>::iterator it = centro.begin(); it != centro.end(); ++it) {
    cout << "ingrese " << valor << "si desea ir a" << (*it)->get_nombre() << endl;
    valor++;
}
cout << "ingrese" << valor << "si desea salir" << endl;
int valorquedesea;
cin >> valorquedesea;
if (valorquedesea == valor) {
    return;
}

list<cCentro_de_salud*>::iterator it = centro.begin();
for (int i = 1; i < valorquedesea && it != centro.end(); ++i) {
    ++it;
}
this->centro_salud = (*it)->get_nombre();
return;
}
*///EN EL MAIN ELIJE FLUIDO