/*Se debe indicar al comienzo la cantidad de pisos ​totales ​y el ​rango ​del ascensor.  A continuación,
el ascensor comenzará en un piso al azar y podrá moverse  verticalmente la cantidad de pisos que lo permita su rango.
Por ejemplo, si contamos con 10 pisos, el rango es de 2, y me encuentro en el piso 5,  puedo desplazarme hasta el piso 3, 4 o 6, 7.
Al seleccionar una opción queremos mostrar en pantalla en qué piso se encuentra  actualmente el ascensor
e ir avanzando presionando una tecla.
El simulador termina si el usuario elige y llega al piso 0.
Se debe limitar el input a los pisos posibles dentro del rango ingresado. 
*/
/*#include<iostream>
#include<stdio.h>
#include<time.h>
int
main()
{
	short pisos = 10;
	short piso = 0;
	short rangoAsc = 3;
	short menu = 0;

	std::cout << "Ingrese la cantidad de pisos\n";
	std::cin >> pisos;
	std::cout << "Ingrese el rango del ascensor\n";
	std::cin >> rangoAsc;

	int pisoInicial;
	srand(time(NULL));
	pisoInicial =rand()%pisos;
	do
	{
		std::cout << "piso actual " << pisoInicial << std::endl;
		if (pisoInicial == 0)
		{
			std::cout << "puede subir " << std::endl;
			std::cout << "pisos";
			for (short i = 1; i <= rangoAsc; i++)
			{
				std::cout << i + pisoInicial << ",";
			}
			std::cout << "\n";
			std::cin >> menu;
			menu = pisoInicial;
		}
		//PISO FINAL
		if (pisoInicial == pisos)
		{
			std::cout << "puede bajar " << std::endl;
			for (short i = 10; i > pisos - rangoAsc; i--)
			{
				std::cout << i - 1 << ",";
			}
			std::cout << "\n";
			std::cin >> menu;
			pisoInicial = menu;
		}
		//ENTRE PISOS
		else if (pisoInicial < pisos || pisoInicial > 0)
		{
			std::cout << "puede subir  " << std::endl;
			for (short i = pisoInicial+1; i <= pisos; i++)
			{
				if (i <= pisoInicial + rangoAsc) 
				{
					std::cout << i << ",";
				}	
			}
			std::cout << "\n";
			std::cout << "o bajar\n";
			for (short i = pisoInicial; i > pisoInicial - rangoAsc; i--)
			{
				if (i>0)
				{
					std::cout << i - 1 << ",";
				}
			}
			std::cout << "\n";
			std::cin >> menu;
			pisoInicial = menu;
		}
		system("CLS");
	} while (pisoInicial != 0);
	return 0;
}*/