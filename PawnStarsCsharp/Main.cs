using System;
namespace PawnStars
{
    class ProgramMain 
    {
        public static void Main()
        {
            GestorCliente gestorCliente = new GestorCliente();
            gestorCliente.Iniciar();
            Console.ReadKey();
        }
    }
}
