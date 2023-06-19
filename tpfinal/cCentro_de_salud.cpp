#include "cCentro_de_salud.h"
//nuevo
cCentro_de_salud::cCentro_de_salud(string nombre, string partido, string provincia, string direccion, string telefono) {
    this->nombre = nombre;
    this->partido = partido;
    this->provincia = provincia;
    this->direccion = direccion;
    this->telefono = telefono;


}
void cCentro_de_salud::set_nombre(string& nombre) {
    this->nombre = nombre;
}
string cCentro_de_salud::get_nombre() {
    return this->nombre;
}

void cCentro_de_salud::set_pacientes_del_centro(list<cPaciente*>& pacientes) {
    list<cPaciente*>::iterator it = pacientes.begin();

    while (it != pacientes.end()) {
        if ((*it)->get_centro_salud() == this->nombre) {
            this->pacientes_del_centro = this->pacientes_del_centro + *it;//sobrebarga agregar
            (*it)->set_partido(this->partido);//seteo provincia de los donantes
            (*it)->set_provincia(this->provincia);
        }

        it++;
    }
}
list<cPaciente*> cCentro_de_salud::get_pacientes_del_centro() {
    return this->pacientes_del_centro;
}

void cCentro_de_salud::protocolo_de_transplante_final(cReceptor* receptor_seleccionado, cDonante* donante_seleccionado, list<cReceptor*> receptores) {

    cSangre* sangre = new cSangre("liquido", cSangre::tipo_d_sangre::A, cSangre::Rh::negativo);
    cPlasma* plasma = new cPlasma("plasma", "frio");
    cMedula_osea* medula_osea = new cMedula_osea("esponjoso", "rojo");
    int exito = consrandom();
    if ((donante_seleccionado->getFluido() == sangre->getTipoFluido() && sangre->VerificarFechaMaxima(donante_seleccionado->get_fecha_de_donacion())) ||
        donante_seleccionado->getFluido() == medula_osea->getTipoFluido() && medula_osea->VerificarFechaMaxima(donante_seleccionado->get_fecha_de_donacion()) ||
        donante_seleccionado->getFluido() == plasma->getTipoFluido() && plasma->VerificarFechaMaxima(donante_seleccionado->get_fecha_de_donacion())) {
        //condicion para el trasplante, determinamos si es existoso con random equiprobable
        //SI ES 2 ES EXITOSO, SI ES 1 HUBO COMPLICACIONES
        if (exito == 2) {
            receptores - receptor_seleccionado;//SOBRECARGA DE-
        }
        if (exito == 1) {
            unsigned int maxprioridad = 5;
            receptor_seleccionado->set_prioridad(maxprioridad);
            receptor_seleccionado->set_estado(cReceptor::estado::inestable);
        }
    }

}

cCentro_de_salud::cCentro_de_salud() {

}
cCentro_de_salud::~cCentro_de_salud() {

}

int consrandom()
{
    int valor = rand() % (2 - 1) + 1;
    return valor;

}

list<cReceptor*> operator-(list<cReceptor*>& receptores, cReceptor* receptor_seleccionado) {
    list<cReceptor*>::iterator it = receptores.begin();

    while (it != receptores.end()) {
        if ((*it)->get_id() == receptor_seleccionado->get_id()) {
            it = receptores.erase(it);
        }
        else {
            it++;
        }
    }

    return receptores;
}
bool operator==(list<cPaciente*> pacientes, cPaciente* paciente) {//devuelve true si esta en la lista
    list<cPaciente*>::iterator it = pacientes.begin();

    while (it != pacientes.end()) {
        if ((*it)->get_id() == paciente->get_id()) {
            return true;
        }
        else {
            it++;
        }
    }

    return false;
}
list<cPaciente*> operator+(list<cPaciente*>& pacientes, cPaciente* paciente) {
    if (paciente != nullptr) {
        pacientes.push_back(paciente);
    }
    return pacientes;
}
//NUEVO