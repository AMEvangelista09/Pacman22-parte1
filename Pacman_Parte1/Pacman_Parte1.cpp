// Pacman_Parte1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#define MAP_VERTICAL 29
#define MAP_HORIZONTAL 120
#define PERSONAJE 'O'
enum TILES { EMPTY = ' ', WALL = '#', POINT = '.' };
TILES map[MAP_VERTICAL][MAP_HORIZONTAL];
bool run = true;

enum INPUT { QUIT, UP, DOWN, LEFT, RIGHT, UNKNOWN };
INPUT currentInput = INPUT::UNKNOWN;

int personaje_x;
int personaje_y;
int Puntuacion_Actual = 0;
int puntuacion_Total;

void Setup() {
	personaje_x = MAP_HORIZONTAL / 2;
	personaje_y = MAP_VERTICAL / 2;
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == 0 || j == 0 || i == MAP_VERTICAL - 1 || j == MAP_HORIZONTAL - 1) {
				map[i][j] = TILES::WALL;
			}
			else {
				map[i][j] = TILES::EMPTY;
			}
		}
	}


	map[10][10] = TILES::POINT;
	map[10][11] = TILES::POINT;
	map[10][12] = TILES::POINT;

	map[10][0] = TILES::POINT;
	map[11][0] = TILES::POINT;
	map[12][0] = TILES::POINT;
	map[13][0] = TILES::POINT;

	map[10][MAP_HORIZONTAL - 1] = TILES::POINT;
	map[11][MAP_HORIZONTAL - 1] = TILES::POINT;
	map[12][MAP_HORIZONTAL - 1] = TILES::POINT;
	map[13][MAP_HORIZONTAL - 1] = TILES::POINT;

	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (map[i][j] == TILES::POINT)
			{
				puntuacion_Total++;
			}
		}
	}
}
void Input() {

	char input;
	std::cin >> input;

	switch (input)
	{
	case 'w':
	case 'W':
		currentInput = INPUT::UP;
		break;
	case 's':
	case 'S':
		currentInput = INPUT::DOWN;
		break;
	case 'a':
	case 'A':
		currentInput = INPUT::LEFT;
		break;
	case 'd':
	case 'D':
		currentInput = INPUT::RIGHT;
		break;
	case 'q':
	case 'Q':
		currentInput = INPUT::QUIT;
		break;
	default:
		currentInput = INPUT::UNKNOWN;
		break;
	}
}
void Logic() {

	int personaje_y_new = personaje_y;
	int personaje_x_new = personaje_x;


	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		personaje_y_new--;
		break;
	case DOWN:
		personaje_y_new++;
		break;
	case LEFT:
		personaje_x_new--;
		break;
	case RIGHT:
		personaje_x_new++;
		break;
	}

	if (personaje_x_new < 0)
	{
		personaje_x_new = MAP_HORIZONTAL - 1;
	}

	personaje_x_new = personaje_x_new % MAP_HORIZONTAL;


	switch (map[personaje_y_new][personaje_x_new])
	{
	case TILES::WALL:
		break;
	case TILES::POINT:
		Puntuacion_Actual++;
		map[personaje_y_new][personaje_x_new] = TILES::EMPTY;
	default:
		personaje_x = personaje_x_new;
		personaje_y = personaje_y_new;
		break;
	}



}
void Draw() {
	system("CLS");
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == personaje_y && j == personaje_x)
			{
				std::cout << PERSONAJE;
			}
			else {
				std::cout << (char)map[i][j];
			}

		}
		std::cout << std::endl;
	}
	std::cout << Puntuacion_Actual << '/' << puntuacion_Total;
}

int main()
{
	Setup();
	Draw();
	while (run) {
		Input();
		Logic();
		Draw();
	}
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
