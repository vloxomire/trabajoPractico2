#pragma once
#include"Cliente.h"
//Declaraciones nomas
enum class Proponer { ACEPTAR, NEGOCIAR, RECHAZAR };
class GestorClientes
{
private:
	Proponer propon;
	Cliente cliente;
	short indice;
	Cliente arrayClientes[];
	
public:
	GestorClientes();
	void Iniciar();
	void ProponerPrecio();
	//Getter
	Proponer GetPropon();
	//Setter
	void SetPropon(Proponer propon);

	void VendernosAlgo();
};

