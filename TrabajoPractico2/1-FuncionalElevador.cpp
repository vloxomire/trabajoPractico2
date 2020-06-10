/*Para hacer la situación un poco más visible, vamos a graficar lo que está sucediendo de  la siguiente forma:*/
/*● Un ​I​ representa el cable del ascensor en un piso.  ● A ​representa el ascensor.    De contar con 5 pisos y estar en el 2,
la situación se vería así:  I  I  A  I  I    Debemos ir actualizando la posición del ascensor paso a paso tal como hacíamos antes
y seguir indicando antes o después del gráfico mediante texto donde se encuentra el  ascensor.*/
#include<iostream>
#include<stdio.h>
#include<time.h>
struct Edificio
{
	short pisosFinal = 5;
	short pisoInicial = 0;
	short pisoActual = 0;
	short rangoAscensor = 2;
	short menu = 0;
};
void PisoRandom(Edificio e);
void Grafico(Edificio e);

int
main()
{
	
	
	Edificio edificio;
	std::cout << "Ingrese la cantidad de pisos\n";
	//std::cin >> pisos;
	std::cout << "Ingrese el rango del ascensor\n";
	//std::cin >> rangoAsc;

	int pisoInicial;
	
/*	
	do
	{
		std::cout << "piso actual " << pisoInicial << std::endl;
		if (pisoInicial == 0)
		{
			std::cout << "puede subir " << std::endl;
			std::cout << "pisos"<<std::endl;
		
			std::cout << "\n";
			for (short i = pisosTotal-rangoAsc; i >=pisoInicial; i--)
	{
		if (i<=rangoAsc)
		{
			if (i == 0)
			{
				std::cout << i + pisoInicial << " A" << std::endl;
			}
			else
			{
				std::cout << i + pisoInicial << " |" << std::endl;
			}
		}
	}
			std::cin >> menu;
			menu = pisoInicial;
		}
		//PISO FINAL
		if (pisoInicial == pisosTotal)
		{
			std::cout << "puede bajar " << std::endl;
			for (short i = 10; i > pisosTotal - rangoAsc; i--)
			{
				std::cout << i - 1 << ",";
			}
			std::cout << "\n";
			for (short i = pisosTotal - rangoAsc; i >= pisoInicial; i--)
			{
				if (i <= rangoAsc)
				{
					if (i == 0)
					{
						std::cout << i + pisoInicial << " A" << std::endl;
					}
					else
					{
						std::cout << i + pisoInicial << " |" << std::endl;
					}
				}
			}
			std::cin >> menu;
			pisoInicial = menu;
		}
		//ENTRE PISOS
		else if (pisoInicial < pisosTotal || pisoInicial > 0)
		{
			std::cout << "puede subir  " << std::endl;
			for (short i = pisoInicial + 1; i <= pisosTotal; i++)
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
				if (i > 0)
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

	for (short i = pisosTotal-rangoAsc; i >=pisoInicial; i--)
	{
		if (i<=rangoAsc)
		{
			if (i == 0)
			{
				std::cout << i + pisoInicial << " A" << std::endl;
			}
			else
			{
				std::cout << i + pisoInicial << " |" << std::endl;
			}
		}
	}*/
	PisoRandom(edificio);
	return 0;
}

void Grafico(Edificio e)
{
	for (size_t i = e.pisosFinal; i > e.pisoInicial; i--)
	{
		if (i==e.pisoActual)
		{
			std::cout<<i<<")"<< 'A' << std::endl;
		}
		else 
		{
			std::cout << i << ")" << 'I' << std::endl;
		}
	}
}
void PisoRandom(Edificio e) 
{
	srand(time(NULL));
	e.pisoActual=rand() % e.pisosFinal+1;
	std::cout << "Piso Actual "<< e.pisoActual << std::endl;
	Grafico(e);
};