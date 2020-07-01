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
#include<Windows.h>

using namespace std;

struct EDIFICIO
{
	short pisoFinal = 10;
	short pisoInicial = 0;
	short pisoActual = 0;
};
struct EPERSONA 
{
	short dondeEsta = 0;
	short destino = 0;
};

void SetPersona(EPERSONA& per,EDIFICIO e);
void DondeEstaPj(EPERSONA& per, EDIFICIO edif);
void DondeVaPj(EPERSONA& per, EDIFICIO edif);
void SetEdificio(EDIFICIO& edi);
void ApareceAscensor(EDIFICIO& e);
void Grafico(EDIFICIO e, EPERSONA p);
void Mover(EDIFICIO e, short, EPERSONA p);

int
main()
{
	srand(time(NULL));
	short aux = 0;
	short contadorGaux = 0;
	EDIFICIO edificio;
	EPERSONA estPer;
	do
	{
		SetPersona(estPer, edificio);
		SetEdificio(edificio);
		Grafico(edificio, estPer);
		Mover(edificio, aux, estPer);
		contadorGaux++;
	} while (contadorGaux!=2);
	return 0;
}

void SetPersona(EPERSONA& per,EDIFICIO edif) 
{
	DondeEstaPj(per,edif);
	DondeVaPj(per,edif);
	cout << "La persona se encuentra en el piso: " << per.dondeEsta << endl;
	cout << "El piso de destino es: " << per.destino << endl;
};

 void DondeEstaPj(EPERSONA& per,EDIFICIO edif)
{
	 //Setea el piso al q aparece la persona
	per.dondeEsta = rand() % edif.pisoFinal+1;
};

 void DondeVaPj(EPERSONA& pe, EDIFICIO edi)
 {
	 pe.destino = rand() % edi.pisoFinal;
	 while (pe.destino == pe.dondeEsta)
	 {
		 pe.destino = rand() % edi.pisoFinal;
	 }
 };

 void SetEdificio(EDIFICIO& edi)
 {
	 ApareceAscensor(edi);
	 cout << "El ascensor esta en el piso: " << edi.pisoActual << endl;
 };

 void ApareceAscensor(EDIFICIO& edi)
 {
	 edi.pisoActual = rand() % edi.pisoFinal;
 };

void Grafico(EDIFICIO ascensor,EPERSONA p)
{//Con un for reccorro del final al comienzo
	for (short i = ascensor.pisoFinal; i >= ascensor.pisoInicial; i--)
	{
		if (i<10)
		{
			Sleep(200);
			if (i == ascensor.pisoActual)
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
				if (i == p.dondeEsta && i!=ascensor.pisoActual)
				{
					cout << " " << 'P';
				}
				if (i == p.destino)
				{
					cout << " " << 'D';
				}
				cout << endl;
			}
		}
		else 
		{
			if (i == ascensor.pisoActual)
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
				if (i == p.destino)
				{
					cout << " " << 'D';
				}
				cout << endl;
			}
		}
	}
	cout << "****************************" << endl;
}

void Mover(EDIFICIO stEdificio, short a,EPERSONA stPersona)
{
	/*El ascensor se va a mover a buscara la persona
	luego la lleva a su destino*/
	stEdificio.pisoActual;
	do
	{
		//system("PAUSE");
		//Buscar a la persona
		if (stPersona.dondeEsta> stEdificio.pisoActual)
		{
			stEdificio.pisoActual++;
		}
		else
		{
			stEdificio.pisoActual--;
		}
		Grafico(stEdificio,stPersona);
	} while (stEdificio.pisoActual!=stPersona.dondeEsta);
	cout << "A subido la persona al ascensor" << endl;
	//LLevar a destino
	do
	{
		if (stEdificio.pisoActual<stPersona.destino)
		{
			stEdificio.pisoActual++;
			stPersona.dondeEsta = stEdificio.pisoActual;
		}
		else
		{
			stEdificio.pisoActual--;
			stPersona.dondeEsta = stEdificio.pisoActual;
		}
		Grafico(stEdificio, stPersona);
	} while (stEdificio.pisoActual != stPersona.destino);
	cout << "Se a dejado a la persona en el piso de destino "<< stPersona.destino << endl;
}