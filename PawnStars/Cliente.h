#include<iostream>
#include<stdio.h>/* NULL */
#include<stdlib.h>/* srand, rand */
#include<time.h>/* time */

class Cliente
{
	//ATRIBUTOS DE LA CLASE
private:
	//Ojo los cliente van a ser random en inicializarlos
	short cantidadClientes;
	short precio;
	enum class Rareza { BASURA, NORMAL, RARO };

public:
	Cliente()
	{
		srand(time(NULL));
		cantidadClientes = rand();/*Random*/
		precio = 0;
	};
	void VerVariables();
};

void Cliente::VerVariables()
{

};

