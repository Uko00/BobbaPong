#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

const char *startGameText = "Start Game";
const char *optionsGameText = "Options";
const char *quitGameText = "Exit Game";
const int baseSpacingOptionsGame = 100;

enum GAMES { // Acrônimos para GAMES STATUS
	MAIN_MENU = 0,
	GAME =      1,
	END_GAME =  2,
	PAUSE =     3
};

unsigned int pontuacaoPlayer1 = 0;
unsigned int pontuacaoPlayer2 = 0;
char strPontuacaoPlayers[40];

//Retangulos para Delimitar o Mundo do Jogo
Rectangle worldLimits[] = {
	{ 0,   0, 800, 5 }, // Limite da parte de cima  [0]
	{ 0, 445, 800, 5 }, // Limite da parte de baixo [1]
	{ 0,   0,   0, 0 }, // Limite da esquerda       [2]
	{ 0,   0,   0, 0 }  // Limite da direita        [3]
};

Vector2 ballCenter = { 800/2.0f, 450/2.0f }; // Define a posição do centro da bolinha
Vector2 ballVelocity = { 3.5f, 1.5f };       // Define a velocidade da bolinha
Vector2 velocityPlayers = { 0, 2.3f };       // Define uma única velocidade para os dois players
Rectangle player1 = { 10, 10, 25, 140 };     // Define o retângulo do player1
Rectangle player2 = { 760, 10, 25, 140 };    // Define o retângulo do player2

void ballMotion(Vector2 *ballCenter, Vector2 *ballVelocity); // Define o movimento da bolinha
void movePlayer1 (Rectangle *player); // Define a logica de controle do player1
void movePlayer2 (Rectangle *player); // Define a logica de controle do player2
void renderWorldLimits(Rectangle limits[]);

void DrawMainMenu(); // Desenha o menu principal
