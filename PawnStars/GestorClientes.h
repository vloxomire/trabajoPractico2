#pragma once
#include"Cliente.h"
//Declaraciones nomas
enum class Proponer { ACEPTAR, NEGOCIAR, RECHAZAR };
class GestorClientes
{
private:
	Proponer propon;
public:
	GestorClientes();
	void Iniciar();
	void ProponerPrecio();
	void SetPropon(Proponer propon);
	Proponer GetPropon();
};

