using System;
namespace PawnStars
{
    enum Proponer { ACEPTAR, NEGOCIAR, RECHAZAR };
    class GestorCliente
    {
        private Proponer propon = Proponer.RECHAZAR;
        private Cliente cliente;
        private static short indice = 3;
        private Cliente[] arrayClientes = new Cliente[indice];
        private int cantidadClientes;
        Random random;

        public GestorCliente()
        {
            random = new Random();
            cliente = new Cliente();
            this.propon = propon;
            this.cantidadClientes = cantidadClientes;
        }

        public void Iniciar()
        {
            SetCantidadCliente();
            Console.WriteLine("Tiene tantos clientes " + GetCantidadCliente());
            InstanciarClientes();
            do
            {
                VendernosAlgo();//Se pondra un precio
            } while (3 != GetCantidadCliente()); ;

            
        }

        public void ProponerPrecio()
        {

        }

        //Getter
        public int GetCantidadCliente()
        {
            return cantidadClientes;
        }
        public Proponer GetPropon()
        {
            return propon;
        }
        //Setter
        public void SetCantidadCliente()
        {
            this.cantidadClientes = random.Next(1, 5);
        }
        public void SetPropon(Proponer propon)
        {
            this.propon = propon;
        }
        public void VendernosAlgo()
        {
            for (int i = 0; i < GetCantidadCliente(); i++)
            {
                Console.WriteLine("El cliente: " + i);
                Console.WriteLine("Precio: " +arrayClientes[i].GetPrecio());
                ComprarSioNo();
            }
        }
        public bool ComprarSioNo() 
        {
            //preguntar si lo quiere comprar
            return true;
        }
        public void InstanciarClientes()
        {
            for (short i = 0; i < GetCantidadCliente(); i++)
            {
                arrayClientes[i] = new Cliente();
                arrayClientes[i].GenerarItem();
            }
        }
    }
}
