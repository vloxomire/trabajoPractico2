#include "GestorClientes.h"
using namespace std;

GestorClientes::GestorClientes()
{
	this->propon = Proponer::RECHAZAR;
	this->cliente = cliente;
	this->indice = cliente.GetCantidadCliente();
	this->arrayClientes[indice];
};

void GestorClientes::Iniciar()
{
	cout << "Tiene tantos clientes " << cliente.GetCantidadCliente() << endl;
	VendernosAlgo();
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
}
void GestorClientes::VendernosAlgo()
{
	for (size_t i = 0; i < indice; i++)
	{
		cout << "El cliente " << i << endl;
		arrayClientes[i].GenerarItem();
	}
}
;
