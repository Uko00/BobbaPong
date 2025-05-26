#include <stdio.h>
#include "raylib.h"
#include "utils.h"
#include "utils.c"

int main(void) {
	int targetFPS = 60;
	enum GAMES GAME_SCENE = PAUSE; // O jogo já inicia no menu principal

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Little Game");
	SetTargetFPS(targetFPS);

	while(!WindowShouldClose()) {

		switch (GAME_SCENE) {


			case MAIN_MENU:
				if (checkRectangleClick(buttonStartGame)) {
					GAME_SCENE = GAME;
				};

				BeginDrawing();
					ClearBackground(BLACK);

					DrawMainMenu();

				EndDrawing();
				break;

			case GAME:
				sprintf(strPontuacaoPlayers, "%d %d", pontuacaoPlayer1, pontuacaoPlayer2); // Cria a string que fica a pontuação dos players

				if (IsKeyDown(KEY_P)) GAME_SCENE = PAUSE;
				
				ballMotion(&ballCenter, &ballVelocity); // Movimento da bolinha
				movePlayer1(&player1); // Logica de movimento p1
				movePlayer2(&player2); // Logica de movimento p2
				if (CheckCollisionCircleRec(ballCenter, 20, worldLimits[1])) ballVelocity.y *= -1;
				if (CheckCollisionCircleRec(ballCenter, 20, worldLimits[0])) ballVelocity.y *= -1;
				if (CheckCollisionCircleRec(ballCenter, 20, player1)) ballVelocity.x *= -1;
				if (CheckCollisionCircleRec(ballCenter, 20, player2)) ballVelocity.x *= -1;

				BeginDrawing();
					ClearBackground(BLACK);
					renderWorldLimits(worldLimits);
					DrawRectangleRec((Rectangle){ (SCREEN_WIDTH/2)-3, 0, 6, 450 }, GRAY);
					DrawCircleV((Vector2){ SCREEN_WIDTH/2, SCREEN_HEIGHT/2 }, 10.0f, GRAY);
					DrawCircleV(ballCenter, 20, RAYWHITE); // A bolinha 
					DrawRectangleRec(player1, RAYWHITE); // Render player1
					DrawRectangleRec(player2, RAYWHITE); // Render player2
					DrawText(strPontuacaoPlayers, SCREEN_WIDTH/2.0f-(MeasureText(strPontuacaoPlayers, 40)/2.0f), 10, 40, RED);
				EndDrawing();
				break;
			case PAUSE:
				if (IsKeyDown(KEY_R)) GAME_SCENE = GAME;
				BeginDrawing();
					ClearBackground(GRAY);
					DrawText("PAUSED", 10, 10, 50, RAYWHITE);
					DrawText("Click R to resume", 10, 60, 30, RAYWHITE);
				EndDrawing();
				break;

		};
	 };

	CloseWindow();

	return 0;
};
