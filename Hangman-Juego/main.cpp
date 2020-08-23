//Autores: Dervin J Paz, Allan Garcia, Jose

#include "Hangman.h"


int main()
{
	Hangman* juego = new Hangman();
	juego->iniciarJuego();
	delete juego;
}
