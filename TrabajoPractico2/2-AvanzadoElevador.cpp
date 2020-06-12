/*Para poder realmente crear una simulación nos falta un paso fundamental, las personas  que digan a qué piso ir y
el ascensor respondiendo a la situación.Por lo que desde este momento y luego de indicar la cantidad de pisos, una persona
aparecerá en un piso al azar (indicada mediante una ​P​ en el gráfico, esta vez a la  derecha del dibujo del ascensor).
y automáticamente llamará el ascensor haciendo que  vaya hasta su piso para que pueda subir.
Mientras que la persona viaja en el ascensor, ​reemplazamos ​su gráfico A por  únicamente P.
La persona elegirá al azar un piso de destino y el ascensor la llevará hasta el punto  indicado.
Al llegar simplemente bajará y la secuencia comenzará devuelta con una nueva  persona.
Por último, para que la simulación avance por su cuenta queremos ir actualizando el  gráfico automáticamente con un pequeño delay.
Consejo: Investigar sobre ​ Sleep ​ y como funciona para manejar el delay*/
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
struct EstPersona 
{
	short persona = 0;
	short destino = 0;
};
short Persona(Edificio e, EstPersona p);
short PisoRandom(Edificio e, EstPersona p);
short PisoDestino(Edificio e, EstPersona p);
void Grafico(Edificio e, EstPersona p);
void Mover(Edificio e, short, EstPersona p);
short Inicio(Edificio e, short& m, EstPersona p);
short Tope(Edificio e, short& m, EstPersona p);
short Intermedio(Edificio e, short& m, EstPersona p);

int
main()
{
	short aux = 0;
	Edificio edificio;
	EstPersona estPer;
	std::cout << "Ingrese la cantidad de pisos\n";
	//std::cin >> pisos;
	std::cout << "Ingrese el rango del ascensor\n";
	//std::cin >> rangoAsc;

	Persona(edificio,estPer);
	aux = PisoRandom(edificio,estPer);
	Mover(edificio, aux,estPer);
	return 0;
}
 void Persona(Edificio e,EstPersona p) 
{
	 //Donde va a estar la persona
	p.persona = rand() % e.pisoFinal+1;
	std::cout << "La persona se encuentra en el piso "<<p.persona<<std::endl;
	//No me devuelve el piso de destino
	p.destino=PisoDestino(e,p.persona);
};
void Grafico(Edificio e,EstPersona p)
{
	for (short i = e.pisoFinal; i >= e.pisoInicial; i--)
	{
		if (i == e.pisoActual)
		{
			std::cout << i << ")" << 'A';
			if (i==p.persona)
			{
				std::cout<<" "<< 'P' << std::endl;
			}
			else 
			{
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << i << ")" << 'I';
			if (i == p.persona)
			{
				std::cout << " " << 'P' << std::endl;
			}
			if (i == p.destino)
			{
				std::cout << " " << 'D' << std::endl;
			}
			else
			{
				std::cout << std::endl;
			}
		}
	}
}
void Mover(Edificio e, short a,EstPersona p)
{
	short menu = 0;
	a = e.pisoActual;
	do
	{
		e.pisoActual = Inicio(e, menu, p);
		e.pisoActual = Tope(e, menu,  p);
		e.pisoActual = Intermedio(e,menu, p);
	} while (e.pisoActual != 0);
}

short PisoRandom(Edificio e,EstPersona p)
{
	srand(time(NULL));
	e.pisoRandom = rand() % e.pisoFinal;
	e.pisoActual = e.pisoRandom;
	std::cout << "Piso Actual " << e.pisoActual << std::endl;
	Grafico(e,p);
	return e.pisoActual;
};
short PisoDestino(Edificio e,EstPersona p)
{
	p.destino= rand() % e.pisoFinal;
	while (p.destino==p.persona)
	{
		p.destino = rand() % e.pisoFinal;
	}
	std::cout << "El piso de destino es "<< p.destino << std::endl;
	return p.destino;
};
short Inicio(Edificio e, short& m, EstPersona p)
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
		Grafico(e,p);
		//falta retornar un valor para q lo agarre el otro
	}
	return e.pisoActual;
};
short Tope(Edificio e, short& m, EstPersona p)
{
	short menu = m;
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
		} while (menu > e.pisoFinal && menu < e.pisoFinal - e.rangoAscensor);
		e.pisoActual = menu;
		Grafico(e,p);
	}
	return e.pisoActual;
};
short Intermedio(Edificio e, short& m, EstPersona p)
{
	short menu = m;
	if (e.pisoActual > e.pisoInicial && e.pisoActual < e.pisoFinal)
	{
		std::cout << "puede subir " << std::endl;
		std::cout << " A los pisos ";
		for (short i = e.pisoActual + 1; i <= e.pisoFinal; i++)
		{
			if (i <= e.pisoActual + e.rangoAscensor)
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
		Grafico(e,p);
	}
	return e.pisoActual;
};