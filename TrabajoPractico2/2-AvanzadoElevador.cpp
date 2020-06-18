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

using namespace std;

struct EDIFICIO
{
	short pisoFinal = 10;
	short pisoInicial = 0;
	short pEstaAscensor = 0;
};
struct EPERSONA 
{
	short dondeEsta = 0;
	short dondeVa = 0;
};

void SetPersona(EPERSONA& per,EDIFICIO e);
void DondeEstaPj(EPERSONA& per, EDIFICIO edif);
void DondeVaPj(EPERSONA& per, EDIFICIO edif);
void SetEdificio(EDIFICIO& edi);
void ApareceAscensor(EDIFICIO& e);
void Grafico(EDIFICIO e, EPERSONA p);
void Mover(EDIFICIO e, short, EPERSONA p);
short Inicio(EDIFICIO e, short& m, EPERSONA p);
short Tope(EDIFICIO e, short& m, EPERSONA p);
short Intermedio(EDIFICIO e, short& m, EPERSONA p);

int
main()
{
	srand(time(NULL));
	short aux = 0;
	EDIFICIO edificio;
	EPERSONA estPer;
	
	SetPersona(estPer,edificio);
	SetEdificio(edificio);
	Grafico(edificio,estPer);
	Mover(edificio, aux,estPer);//ver mover q onda?
	return 0;
}

void SetPersona(EPERSONA& per,EDIFICIO edif) 
{
	DondeEstaPj(per,edif);
	DondeVaPj(per,edif);
	cout << "La persona se encuentra en el piso: " << per.dondeEsta << endl;
	cout << "El piso de destino es: " << per.dondeVa << endl;
};

 void DondeEstaPj(EPERSONA& per,EDIFICIO edif)
{
	 //Setea el piso al q aparece la persona
	per.dondeEsta = rand() % edif.pisoFinal+1;
};

 void DondeVaPj(EPERSONA& pe, EDIFICIO edi)
 {
	 pe.dondeVa = rand() % edi.pisoFinal;
	 while (pe.dondeVa == pe.dondeEsta)
	 {
		 pe.dondeVa = rand() % edi.pisoFinal;
	 }
 };

 void SetEdificio(EDIFICIO& edi)
 {
	 ApareceAscensor(edi);
	 cout << "El ascensor esta en el piso: " << edi.pEstaAscensor << endl;
 };

 void ApareceAscensor(EDIFICIO& edi)
 {
	 edi.pEstaAscensor = rand() % edi.pisoFinal;
 };

void Grafico(EDIFICIO e,EPERSONA p)
{//Con un for reccorro del final al comienzo
	for (short i = e.pisoFinal; i >= e.pisoInicial; i--)
	{
		if (i<10)
		{
			if (i == e.pEstaAscensor)
			{
				cout<<'0' << i << ")" << 'A';

				if (i == p.dondeEsta)//Pregunta por la persona
				{
					cout << " " << 'P';
				}
				cout << endl;
			}
			else
			{
				cout << '0' << i << ")" << 'I';
				if (i == p.dondeEsta)
				{
					cout << " " << 'P';
				}
				if (i == p.dondeVa)
				{
					cout << " " << 'D';
				}
				cout << endl;
			}
		}
		else 
		{
			if (i == e.pEstaAscensor)
			{
				cout << i << ")" << 'A';

				if (i == p.dondeEsta)//Pregunta por la persona
				{
					cout << " " << 'P';
				}
				cout << endl;
			}
			else
			{
				cout << i << ")" << 'I';
				if (i == p.dondeEsta)
				{
					cout << " " << 'P';
				}
				if (i == p.dondeVa)
				{
					cout << " " << 'D';
				}
				cout << endl;
			}
		}

	}
}

void Mover(EDIFICIO e, short a,EPERSONA p)
{
	short menu = 0;
	a = e.pEstaAscensor;
	do
	{
		e.pEstaAscensor = Inicio(e, menu, p);
		e.pEstaAscensor = Tope(e, menu,  p);
		e.pEstaAscensor = Intermedio(e,menu, p);
	} while (e.pEstaAscensor != 0);
}




short Inicio(EDIFICIO e, short& m, EPERSONA p)
{
	short menu = m;
	if (e.pEstaAscensor == 0)
	{//muestra los pisos a subir
		std::cout << "puede subir " << std::endl;
		std::cout << " A los pisos ";
		//me da los pisos
		/*for (short i = e.pisoInicial + 1; i <= e.rangoAscensor; i++)//0<2
		{
			std::cout << i << ",";
		}
		std::cout << "\n";
		//valores validos
		do
		{
			std::cin >> menu;
		} while (e.pisoInicial > menu && e.rangoAscensor < menu);*/
		e.pEstaAscensor = menu;
		Grafico(e,p);
		//falta retornar un valor para q lo agarre el otro
	}
	return e.pEstaAscensor;
};
short Tope(EDIFICIO e, short& m, EPERSONA p)
{
	short menu = m;
	if (e.pEstaAscensor == e.pisoFinal)
	{//muestra los pisos a subir
		std::cout << "puede bajar " << std::endl;
		std::cout << " A los pisos ";
		//me da los pisos
		/*for (short i = e.pisoFinal; i > e.pisoFinal - e.rangoAscensor; i--)
		{
			std::cout << i - 1 << ",";
		}*/
		std::cout << "\n";
		//valores validos
		/*do
		{
			std::cin >> menu;
		} while (menu > e.pisoFinal && menu < e.pisoFinal - e.rangoAscensor);*/
		e.pEstaAscensor = menu;
		Grafico(e,p);
	}
	return e.pEstaAscensor;
};
short Intermedio(EDIFICIO e, short& m, EPERSONA p)
{
	short menu = m;
	if (e.pEstaAscensor > e.pisoInicial && e.pEstaAscensor < e.pisoFinal)
	{
		std::cout << "puede subir " << std::endl;
		std::cout << " A los pisos ";
		for (short i = e.pEstaAscensor + 1; i <= e.pisoFinal; i++)
		{
			/*if (i <= e.pisoActual + e.rangoAscensor)
			{
				std::cout << i << ",";
			}*/
		}
		std::cout << "\n";
		std::cout << "o bajar " << std::endl;
		std::cout << " A los pisos ";
		/*for (short i = e.pisoActual; i > e.pisoActual - e.rangoAscensor; i--)//3>=(3-2)
		{
			if (i >= e.pisoInicial)
			{
				std::cout << i << ",";
			}
		}*/
		std::cout << "\n";
		do
		{
			std::cin >> menu;
		} while (menu<e.pisoInicial && menu>e.pisoFinal);
		e.pEstaAscensor = menu;
		Grafico(e,p);
	}
	return e.pEstaAscensor;
};