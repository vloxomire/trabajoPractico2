#include "GestorClientes.h"

GestorClientes::GestorClientes()
{
	this->propon = Proponer::RECHAZAR;
};

void GestorClientes::Iniciar()
{

};

void GestorClientes::ProponerPrecio()
{

};

//Getter
Proponer GestorClientes::GetPropon() 
{
	return propon;
};
//Setter
void  GestorClientes::SetPropon(Proponer propon) 
{
	this->propon=propon;
};