#include "Hangman.h"

// Constructor
Hangman::Hangman()
{
    currentUser = "";												// Iniciar usuario actual como empty string
    currentPuntacion = 0;											// Iniciar puntuacion en 0
    // For loop para iniciar lista de jugadores con empty strings y puntaciones con 0
    for (int i = 0; i < totTopScores; i++)
    {
        topPlayers[i] = "";
        topScores[i] = 0;
    }
	srand((unsigned)time(0));
}   // Fin de constructor

Hangman::~Hangman()
{
    // Destructor for Hangman object
    currentUser = "";
    currentPuntacion = 0;
    for (int i = 0; totTopScores; i++)
    {
        topPlayers[i] = "";
        topScores[i] = 0;
    }
	delete topPlayers;
	delete topScores;

}   // Fin del destructor

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
		//system("cls");
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
				std::cout << "4) No se permite ayuda de alguien mas" << std::endl;
				std::cout << std::endl;

				break;

				// El case 3 representara la opcion de ver los puntajes de cada jugador.
			case '3':
				std::cout << "Puntuaciones mas Altas" << std::endl;
				for (int i = 0; i < totTopScores; i++) {
					int tempScore = topScores[i];
					if (tempScore != 0) {
						std::string tempUser = topPlayers[i];
						std::cout << tempUser << ": " << tempScore << std::endl;

					}
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
	//randNum = 5;
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
	int contadorMalas = 0;														// Para llevar conteo de intentos incorrectos del jugador
	int oportRestantes = maxOportunidades;
	std::string palabraLineas = "";
	for (int i = 0; i < palabra.size(); i++) {									// Creando string con lineas del mismo tamaño de la palabra
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
			std::cout << "\n\n\t\tGanaste Prrin" << std::endl;
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
			for (int i = 0; i < palabraUpper.length(); i++) {					// Reemplazamos los guiones bajos por la letra correcta
				if (palabraUpper[i] == tempLetra) {
					palabraLineas[i] = tempLetra;
				}
			}
		}
	}	
}