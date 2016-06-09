#include "soldado.h"
#include "mago.h"
#include "magia.h"
#include "string"
#include "sstream"

using std::string;
using std::stringstream;

mago::mago(string name, const magia& magic,const armadura& armor,double& hp):soldado(name,magic,armor,hp){
}

mago::mago(const mago& m){
	this->name=n.name;
	this->arma->m.arma;
}

