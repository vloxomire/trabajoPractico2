/*Para hacer la situación un poco más visible, vamos a graficar lo que está sucediendo de  la siguiente forma:*/
/*● Un ​I​ representa el cable del ascensor en un piso.  ● A ​representa el ascensor.    De contar con 5 pisos y estar en el 2,
la situación se vería así:  I  I  A  I  I    Debemos ir actualizando la posición del ascensor paso a paso tal como hacíamos antes
y seguir indicando antes o después del gráfico mediante texto donde se encuentra el  ascensor.*/
#include<iostream>
#include<stdio.h>
#include<time.h>
struct Edificio
{
	short pisoFinal = 5;
	short pisoInicial = 0;
	short pisoActual = 0;
	short pisoRandom = 0;
	short rangoAscensor = 2;
	short menu = 0;
};
short PisoRandom(Edificio e);
void Grafico(Edificio e);
void Mover(Edificio e,short);
void Inicio(Edificio e, short);

int
main()
{
	short aux = 0;
	Edificio edificio;
	std::cout << "Ingrese la cantidad de pisos\n";
	//std::cin >> pisos;
	std::cout << "Ingrese el rango del ascensor\n";
	//std::cin >> rangoAsc;

	int pisoInicial;
	aux=PisoRandom(edificio);
	Mover(edificio,aux);
	return 0;
}

void Grafico(Edificio e)
{
	for (short i = e.pisoFinal; i >= e.pisoInicial; i--)
	{
		if (i == e.pisoActual)
		{
			std::cout << i << ")" << 'A' << std::endl;
		}
		else
		{
			std::cout << i << ")" << 'I' << std::endl;
		}
	}
}
void Mover(Edificio e,short a)
{
	short menu = 0;
	a = e.pisoActual;
	do
	{
		//piso en 0
		Inicio(e,menu);

		//PISO FINAL
		if (e.pisoActual == e.pisoFinal)
		{//muestra los pisos a subir
			std::cout << "puede bajar " << std::endl;
			std::cout << " A los pisos ";
			//me da los pisos
			for (short i = e.pisoFinal; i > e.pisoFinal - e.rangoAscensor; i--)
			{
				std::cout << i - 1 << ",";
			}
			std::cout << "\n";
			//valores validos
			do
			{
				std::cin >> menu;
			} while (menu>e.pisoFinal && menu< e.pisoFinal - e.rangoAscensor);
			e.pisoActual = menu;
			Grafico(e);
		}
		//ENTRE PISOS
		else
		{
			std::cout << "puede subir " << std::endl;
			std::cout << " A los pisos ";
			for (short i = e.pisoActual + 1; i <= e.pisoFinal; i++)
			{
				if (i <= e.pisoActual+ e.rangoAscensor)
				{
					std::cout << i << ",";
				}
			}
			std::cout << "\n";
			std::cout << "o bajar " << std::endl;
			std::cout << " A los pisos ";
			for (short i = e.pisoActual; i > e.pisoActual - e.rangoAscensor; i--)//3>=(3-2)
			{
				if (i >= e.pisoInicial)
				{
					std::cout << i << ",";
				}
			}
			std::cout << "\n";
			do
			{
				std::cin >> menu;
			} while (menu<e.pisoInicial && menu>e.pisoFinal);
			e.pisoActual = menu;
			Grafico(e);
		}
	} while (e.pisoActual != 0);
}
short PisoRandom(Edificio e)
{
	short aux = 0;
	srand(time(NULL));
	e.pisoRandom = rand() % e.pisoFinal;
	aux = e.pisoRandom;
	std::cout << "Piso Actual " << e.pisoActual << std::endl;
	Grafico(e);
	return aux;
};
void Inicio(Edificio e, short m) 
{
	short menu = m;
	if (e.pisoActual == 0)
	{//muestra los pisos a subir
		std::cout << "puede subir " << std::endl;
		std::cout << " A los pisos ";
		//me da los pisos
		for (short i = e.pisoInicial + 1; i <= e.rangoAscensor; i++)//0<2
		{
			std::cout << i << ",";
		}
		std::cout << "\n";
		//valores validos
		do
		{
			std::cin >> menu;
		} while (e.pisoInicial > menu && e.rangoAscensor < menu);
		e.pisoActual = menu;
		Grafico(e);
	}
};
void Tope(Edificio e)
{

};
void Intermedio(Edificio e) 
{

};