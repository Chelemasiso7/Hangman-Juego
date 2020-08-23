#include "Hangman.h"

// Constructor
Hangman::Hangman()
{
    // For loop para iniciar lista de jugadores con empty strings y puntaciones con 0
    for (int i = 0; i < totTopScores; i++)
    {
        topPlayers[i] = "";
        topScores[i] = 0;
    }
	srand((unsigned)time(0));
}   // Fin de constructor

char Hangman::menu()
{
    // Funcion outputs el menu principal del juego y returns la opcion que escoga el usuario
    char option;														// Esta la variable que vamos a return al final de la funcion

    std::cout << "\n\t+-+-+-+Bienvenido al Juego Ahorcado!+-+-+-+\n\n\n" << std::endl;
    std::cout << "1) Jugar\n" << std::endl;
    std::cout << "2) Ver Reglas y Tipos de Juego\n" << std::endl;
    std::cout << "3) Ver Puntajes de Jugadores\n" << std::endl;
    std::cout << "4) Salir\n" << std::endl;

    std::cout << "\t\tIngrese una Opcion: ";
    std::cin >> option;												// Salvar la decision del jugador en la variable opcion

    return option;													// Return la opcion que eligio el jugador
}   // Fin de funcion menu()

void Hangman::iniciarJuego()
{
    int opcionSel = 0;												// Record de la opcion que el usuario elige
	while (true)													// Mientras el jugador no eliga la opcion 4, de exit, seguimos jugando
	{
		opcionSel = menu();											// Mostramos menu principal y le pedimos input al user
		system("cls");
		if (opcionSel == '4') {
			std::cout << "Saliendo del juego" << std::endl;
			break;
		}
		else {
			switch (opcionSel) {

				// Si el jugador decide o escoge la opcion de Jugar.
			case '1':
				std::cout << "\n\t+-+-+-+Seleccione la tematica del juego+-+-+-+\n\n\n" << std::endl;
				std::cout << "1) Deportes\n" << std::endl;
				std::cout << "2) Peliculas\n" << std::endl;
				std::cout << "3) Ciencias Sociales\n\n\n" << std::endl;

				std::cout << "\t\tIngrese una Opcion: ";
				std::cin >> opcionSel;

				char comenzar;
				std::cout << "\n\n\t\tComenzar (S/N): ";
				std::cin >> comenzar;
				comenzar = toupper(comenzar);

				if (comenzar == 'S') {
					tematicaJuego(opcionSel);
				}
				else
					continue;

				break;

				// El case 2 va a representar la opcion de ver Reglas y tipos de Juegos.
			case '2':
				std::cout << "\t\t\tReglas del Juego\n" << std::endl;
				std::cout << "1) Maxima Cantidad de Errores son 6" << std::endl;
				std::cout << "2) Temas: Deportes, Peliculas, Ciencias Sociales" << std::endl;
				std::cout << "3) Cada Respuesta (Letra) Adivinada Correctamente tiene un valor de 10 Puntos" << std::endl;
				std::cout << "4) Se agregan 100 puntos si adivinan la palabra al puntaje final" << std::endl;
				std::cout << "5) No se permite ayuda de alguien mas" << std::endl;
				std::cout << "6) Repetir letra que no esta en la palabra resulta como nueva incorrecta" << std::endl;
				std::cout << std::endl;

				break;

				// El case 3 representara la opcion de ver los puntajes de cada jugador.
			case '3':
				std::cout << "Puntuaciones mas Altos" << std::endl;
				for (int i = totTopScores - 1; i >= 0; i--) {
					// Salvamos como variable el nombre y puntaje del elemento actual en el array
					int tempScore = topScores[i];
					std::string tempNombre = topPlayers[i];
					if (tempScore != 0) 											// Si hay un puntaje dentro del elemento actual del array
						std::cout << tempNombre << ": " << tempScore << std::endl;	// Imprimimos el nombre y puntaje de la persona
					else															// Else no hay puntaje ni nombre en este index del array
						continue;													// No imprimimos nada solamente avanzamos al siguiente index
				}
				break;

			default:
				std::cout << "Error Opcion Equivocada" << std::endl;
			}
		}
    }   // End of while-loop
}

void Hangman::tematicaJuego(int opcionSel) {
	int randNum = rand() % numeroPalabras;
	switch (opcionSel) {
	// Deportes
    case 1:
		sesionJuego(deportesPalabras[randNum], deportesTips[randNum]);
		break;
	// Peliculas
	case 2:
		sesionJuego(peliculasPalabras[randNum], peliculasTips[randNum]);
		break;
	// Cultura General
	case 3:
		sesionJuego(culturaGeneralPalabras[randNum], culturaGeneralTips[randNum]);
		break;
	default:
		std::cerr << "Error! Opcion Equivocada porfavor elegir una opcion correcta" << std::endl;
	}
}

void Hangman::figura(int oportunidades) {
	if (oportunidades == 5) {
		std::cout << "______________" << "\n";
		std::cout << "       |      " << "\n";
		std::cout << "              " << "\n";
		std::cout << "              " << "\n";
		std::cout << "              " << "\n";
		std::cout << "              " << "\n";
		std::cout << "              " << "\n";
		std::cout << "              " << "\n";
		std::cout << "              " << "\n";
		std::cout << "--------------" << "\n";
	}
	else if (oportunidades == 4) {
		std::cout << "______________" << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "--------------" << "\n";
	}
	else if (oportunidades == 3) {
		std::cout << "______________" << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|     (X-X)   " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "--------------" << "\n";
	}
	else if (oportunidades == 2) {
		std::cout << "______________" << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|     (X-X)   " << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "--------------" << "\n";
	}
	else if (oportunidades == 1) {
		std::cout << "______________" << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|     (X-X)   " << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|      /|\\   " << "\n";
		std::cout << "|     / | \\   " << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "|             " << "\n";
		std::cout << "--------------" << "\n";
	}
	else if (oportunidades == 0) {
		std::cout << "______________" << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|     (X-X)   " << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|      /|\\    " << "\n";
		std::cout << "|     / | \\   " << "\n";
		std::cout << "|       |     " << "\n";
		std::cout << "|      / \\    " << "\n";
		std::cout << "|     /   \\   " << "\n";
		std::cout << "--------------" << "\n";
	}
}

void Hangman::sesionJuego(std::string palabra, std::string tip) {
	std::string letrasIngresadas = "";											// Vamos a append las letras que el usuario vaya ingresando
	int contadorMalas = 0;														// Para llevar conteo de intentos incorrectos del jugador
	int oportRestantes = maxOportunidades;
	int puntaje = 0;															// Para llevar el puntaje del jugador
	bool ganaste = false;														// Para saber si el jugador gano o no el juego para output mensaje al final
	std::string palabraLineas = "";
	for (int i = 0; i < palabra.size(); i++) {									// Creando string con lineas del mismo tama�o de la palabra
		if (palabra[i] == ' ')													// Si la letra es un espacio no la hacemos un guion bajo
			palabraLineas += ' ';
		else
			palabraLineas += '_';
	}

	std::string palabraUpper = palabra;											// Para que no importe si escriben minuscula o mayuscula
	for (int i = 0; i < palabraUpper.length(); i++)
		palabraUpper[i] = toupper(palabraUpper[i]);

	system("cls");

	while (oportRestantes != 0) {												// Hasta que el jugador se quede sin oportunidades
		system("cls");
		std::cout << tip << std::endl;
		std::cout << "\n\n\n\n\t"; 
		for (int i = 0; i < palabraLineas.length(); i++)
			std::cout << palabraLineas[i] << " ";

		if (palabraUpper == palabraLineas) {									// Si el jugador ya adfivino la palabra 
			ganaste = true;
			puntaje += 100;														// Le damos 100 puntos por ver completado la palabra
			break;
		}		

		std::cout << "\nIntentos: " << oportRestantes << std::endl;
		figura(oportRestantes);

		char tempLetra; 
		std::cout << "Ingrese una letra: ";
		std::cin >> tempLetra;
		tempLetra = toupper(tempLetra); 

		// Ahora crear un whileloop usando string.find para encontrar cada locacion de la letra en la palabra
		int indexLetra = palabraUpper.find(tempLetra);
		if (indexLetra == -1) {
			// Si el jugador nos da una letra mala se comienza a formar la figura y el conteo de oportunidades disminuye
			contadorMalas++;
			oportRestantes = oportRestantes - 1;
		}
		else {																	// El jugador nos dio una letra correcta
			// Revisamos si la letra ya fue ingresada en el pasado
			bool letraIngresada = false;
			for (int i = 0; i < letrasIngresadas.size(); i++)
			{
				char tempC = letrasIngresadas[i];
				if (tempC == tempLetra)											// Si la letra ya fue ingresada en el pasado
				{
					letraIngresada = true;										// Marcamos la variable letraIngresada a true
					break;														// Y salimos del for-loop
				}
				else
					continue;
			}

			if (!letraIngresada)												// Si la letra no ha sido ingresada
			{
				letrasIngresadas.push_back(tempLetra);							// Salvamos la nueva letra en el string de letras ingresadas
				for (int i = 0; i < palabraUpper.length(); i++) {				// Reemplazamos los guiones bajos por la letra correcta
					if (palabraUpper[i] == tempLetra) {
						palabraLineas[i] = tempLetra;
						puntaje += 10;											// Agregamos 10 puntos por cada letra correcta dentro de la palabra
					}
				}
			}
		}
	}	
	system("cls");
	figura(oportRestantes);
	if (ganaste)
	{
		std::cout << "\n\n\t\tGanaste Prrin" << std::endl;
	}
	else
	{
		std::cout << "\n\n\t\tPerdiste perrin, F" << std::endl;
	}
	
	// Ahora le pedimos el nombre al usuario para revisar al salvarlo
	std::string nombre;
	std::cout << "Ingresa tu nombre: ";
	std::cin >> nombre;
	agregarJugador(nombre, puntaje);
}

void Hangman::agregarJugador(std::string user, int puntaje) {
	int puntajeMasBajo = topScores[0];											// Hagarramos el puntaje mas bajo del Top 10 actual
	if (puntaje > puntajeMasBajo)												// Si el puntaje del usuario es mas alto que el utlimo del Top 10
	{
		// Vamos a remplazar el ultimo puntaje por el del usuario actual
		topScores[0] = puntaje;													// Insertamos el puntaje del usuario al final de la lista de top 10 puntajes
		topPlayers[0] = user;													// Insertamos el nombre del usuario al final de la lista de top jugadores
		sortTopScores();														// Llamamos a la funcion sortTopScores para hacer bubble sort con el nuevo puntaje
	}
	else																		// Else el jugador no tuvo un puntaje sufientemente alto para estar en el top 10
	{
		std::cout << "Tu puntaje no es lo suficiente para estar en el Top 10, trata un nuevo juego!" << std::endl;
	}
}

void Hangman::sortTopScores()
{
	// Funcion hace un bubble sort para arreglar el order de la lista de top scores
	int n = totTopScores;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (topScores[j] > topScores[j+1])
			{
				// Hacemos swap en la lista de puntajes
				int tempPuntaje = topScores[j];
				topScores[j] = topScores[j+1];
				topScores[j+1] = tempPuntaje;

				// Hacemos swap en la lista de nombres/usarios
				std::string tempNombre = topPlayers[j];
				topPlayers[j] = topPlayers[j+1];
				topPlayers[j+1] = tempNombre;
			}
		}
	}

}