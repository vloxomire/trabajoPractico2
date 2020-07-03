#include"Cliente.h"

using namespace std;
Cliente::Cliente()
{
	srand(time(NULL));
	this->cantidadClientes =cantidadClientes;/*Random*/
	this->precio = precio;
	this->rareza = rareza;
}
//Getter
short Cliente::GetCantidadCliente()
{
	return cantidadClientes;
}
short Cliente::GetPrecio()
{
	return precio;
}
Rareza Cliente::GetRareza()
{
	return rareza;
}
//Setter
void Cliente::SetCantidadCliente()
{
	this->cantidadClientes = rand() % 5 + 1;
}
void Cliente::SetPrecio()
{
	this->precio = rand()%100+50;
}
void Cliente::SetRareza(Rareza rareza)
{
	this->rareza = rareza;
}

void Cliente::GenerarItem()
{
	cout << "Precio: " << GetPrecio() << endl;
	GetRareza();
}



