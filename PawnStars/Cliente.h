#pragma once
#include<iostream>
#include<stdio.h>/* NULL */
#include<stdlib.h>/* srand, rand */
#include<time.h>/* time */
enum class Rareza { BASURA, NORMAL, RARO };
class Cliente
{
	//ATRIBUTOS DE LA CLASE
private:
	//Ojo los cliente van a ser random en inicializarlos
	short cantidadClientes;
	short precio;
	Rareza rareza;

public:
	Cliente();
	//Getter
	short GetCantidadCliente();
	short GetPrecio();
	Rareza GetRareza();
	//Setter
	void SetCantidadCliente();
	void SetPrecio();
	void SetRareza(Rareza rareza);

	void GenerarItem();
};

