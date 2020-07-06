using System;
namespace PawnStars
{
    enum Rareza { BASURA, NORMAL, RARO };
    class Cliente
    {
		//Ojo los cliente van a ser random en inicializarlos
		
		private int precio;
		private Rareza rareza;
		public Random random;
		public Cliente()
		{
			random=new Random();
			this.precio = precio;
			this.rareza = rareza;
		}
	//Getter
	public int GetPrecio()
	{
		return precio;
	}
	public Rareza GetRareza()
	{
		return rareza;
	}
	//Setter
	public void SetPrecio()
	{
			this.precio = random.Next(25, 100);
	}
	public void SetRareza()
	{
			//switch con un random
			int valor = random.Next(1, 3);
            switch (valor)
            {
				case 1:
					rareza = Rareza.BASURA;
					break;
				case 2:
					rareza = Rareza.NORMAL;
					break;
				case 3:
					rareza = Rareza.RARO;
					break;
				default:
					rareza = Rareza.BASURA;
					break;
            }
		}

	public void GenerarItem()
	{
			SetRareza();
			SetPrecio();
	}
	}
}