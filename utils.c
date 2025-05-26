#include "raylib.h"

Rectangle buttonStartGame = { SCREEN_WIDTH/2.0f-250/2, baseSpacingOptionsGame*1-7, 250, 50 };

void ballMotion(Vector2 *ballCenter, Vector2 *ballVelocity) { // Define o movimento da bolinha
	ballCenter->x += ballVelocity->x;
	ballCenter->y += ballVelocity->y;
	if (ballCenter->x < 0) {
		ballVelocity->x *=-1;
		ballVelocity->y *=-1;
		pontuacaoPlayer2 +=1;
		ballCenter->x = SCREEN_WIDTH/2;
		ballCenter->y = SCREEN_HEIGHT/2;
	} else if (ballCenter->x > 800) {
		ballVelocity->x *=-1;
		ballVelocity->y *=-1;
		pontuacaoPlayer1 += 1; 
		ballCenter->x = SCREEN_WIDTH/2;
		ballCenter->y = SCREEN_HEIGHT/2;
	}; 
};

void movePlayer1 (Rectangle *player) {
	if ( IsKeyDown(KEY_W) && (player->y+player->height)>147 ) player->y -= velocityPlayers.y; 
	else if ( IsKeyDown(KEY_S) && (player->y-player->height<163) ) player->y += velocityPlayers.y;

};

void movePlayer2 (Rectangle *player) {
	if ( IsKeyDown(KEY_UP) && (player->y+player->height)>147 ) player->y -= velocityPlayers.y; 
	else if (IsKeyDown(KEY_DOWN) && (player->y-player->height<163) ) player->y += velocityPlayers.y;
};

void renderWorldLimits(Rectangle limits[]) {
	for (int i=0; i<4; i++) DrawRectangleRec(limits[i], GRAY);
}; 


void DrawMainMenu() {
	ClearBackground(BLACK);
	
	DrawRectangleRec(buttonStartGame, RAYWHITE);
	
	DrawText( startGameText,   (SCREEN_WIDTH/2.0f)-(MeasureText(startGameText, 30)/2),    baseSpacingOptionsGame*1, 30, GRAY );
};


bool checkRectangleClick(Rectangle rec) { // Verifica de o usuário clicou no botão
	Vector2 mp = GetMousePosition(); // Posição do mouse
	if (mp.x > rec.x && mp.x < (rec.x+rec.width) &&
		mp.y > rec.y && mp.y < (rec.y+rec.height) && 
		IsMouseButtonPressed(MOUSE_BUTTON_LEFT)	
	) {
		return true;
	};

	return false;
};
// É claro que a biblioteca tem um módulo para esse propósito, mas qual seria a graça?
