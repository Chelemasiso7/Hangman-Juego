#pragma once

#include <string>                                                       // Para poder usar Strings
#include <iostream>                                                     // Output y Inputs
#include <stdlib.h>                                                     // Para poder limpiar la pantalla
#include <time.h>                                                       // Para poder crear un numero aleatorio

#define totTopScores 10
#define maxOportunidades 6
#define numeroPalabras 10

class Hangman
{
private:
    // Banco de palabras para deportes
    std::string deportesPalabras[numeroPalabras] = { "Italia", "Brazil", "Honduras", "Mexico", "Azteca", "Champions League", "Copa America", "FIFA", "FENAFUTH", "Olimpia" };

    std::string deportesTips[numeroPalabras] = { "Seleccion de futbol con 4 titulos del mundial de la FIFA, ultimo campeonato obtenido en el mundial 2006",
                                "Seleccion de futbol con mas titulos del mundial de la FIFA", "Seleccion de Centro America que clasifico al mundial 1982,2010,2014",
                                "Seleccion con mas titulos de Copa Oro","Cual es el Estadio mas Grande de Mexico", "Competicion de futbol mas famosa de Europa",
                                "Competicion mas famosa de America", "Organizacion mundial del futbol", "Organizacion que regula el futbol de Honduras",
                                "Equipo con mas copas de liga de Honduras"};

    // Banco de palabras para Peliculas
     std::string peliculasPalabras[numeroPalabras] = { "Endgame", "Antman", "George Lucas", "Scarlett Johansson", "Piratas", "Josh Brolin", "Power range rojo", "Monsters INC",
                                                        "Netflix", "Hulk" };

     std::string peliculasTips[numeroPalabras] = { "Pelicula mas taquillera de la historia", "Pelicula que su poder es hacerse bien pequeno", "Escritor de la saga de Star Wars",
                                                    "Como se llama la actriz que interpreta Black Widow","_ _ _ _ _ _ _ del Caribe",
                                                    "Actor que interpreta a Thanos en Infinity War y Endgame",
                                                    "Color del power ranger lider", "En que pelicula aparece Mike Wazowsky", "Aplicacion para ver peliculas comienza con N",
                                                    "Como se llama el Personaje verde de la saga de Marvel"};

    // Banco de palabras para Cultura General
     std::string culturaGeneralPalabras[numeroPalabras] = { "Juan Orlando","Maya", "Honduras", "Rusia", "Alaska", "Donald Trump", "Puerto Castilla", "Rio Amazonas", 
                                                             "Miguel de Cervantes", "Tierra"};

     std::string culturaGeneralTips[numeroPalabras] = { "Presidente de Honduras", "Cultura que usaba el cacao como moneda", "Pais de C.A con 5 estrellas en la bandera",
                                "Paiz mas extenso del Mundo", "Estado de U.S.A mas extenso", "Presidente de U.S.A", "Puerto maritimo ubicado en Trujillo",
                                "Rio mas largo del mundo", "Quien es el autor de el Quijote", 
                                "Cual es el tercer planeta del sistema solar" };
    
    // Variables
    std::string topPlayers[totTopScores];                               // Lista de los 10 ultimos jugaodres
    int topScores[totTopScores];                                        // Lista de los 10 ultimos Puntajes

    // Metodos
    char menu();                                                        // Menu del juego y para seleccionar la opcion que quiera el usuario
    void tematicaJuego(int opcionSel);                                  // Funcion maneja que tematica eligio el jugador
    void figura(int oportunidades);                                     // Imprime el muneco de hangman dependiendo de las oportunidades
    void sortTopScores();                                               // Funcion para ordenar la lista de puntajes de cada jugador
    void sesionJuego(std::string palabra,std::string tip);
    void agregarJugador(std::string user, int puntaje);

public:
    Hangman();                                                          // Constructor

    // Metodos
    void iniciarJuego();                                                // Iniciador de Juego
};

