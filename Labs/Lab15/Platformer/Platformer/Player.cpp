/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:		20 Abr 2012
// Atualiza��o:	11 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
	tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
	anim = new Animation(tileset, 0.120f, true);

	// seq��ncias de anima��o do player
	uint invert[4] = {6,7,8,9};
	uint normal[4] = {1,2,3,4};

	anim->Add(INVERTED, invert, 4);
	anim->Add(NORMAL, normal, 4);

	// cria bounding box
	bbox = new Rect(
		x - tileset->TileWidth() / 2.0f, 
		y - tileset->TileHeight() / 2.0f, 
		x + tileset->TileWidth() / 2.0f,
		y + tileset->TileHeight() / 2.0f);
	
	// inicializa estado do player
	gravity = NORMAL;
	keyCtrl = false;	

	// posi��o inicial
	MoveTo(float(window->CenterX()), 24.0f, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete bbox;
	delete anim;
	delete tileset;	
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
	// mant�m personagem na posi��o correta em cima da plataforma
	if (gravity == NORMAL)
		MoveTo(float(window->CenterX()), obj->Y() - 32);
	else
		MoveTo(float(window->CenterX()), obj->Y() + 32);

	// ----------------------------------------------------------
	// Processa teclas pressionadas
	// ----------------------------------------------------------
	// jogador s� pode alterar a gravidade enquanto estiver
	// em cima de uma plataforma, n�o � poss�vel a mudan�a no ar

	if (window->KeyUp(VK_SPACE))
		keyCtrl = true;

	if (keyCtrl && window->KeyDown(VK_SPACE))
	{
		keyCtrl = false;
		gravity = !gravity;

		// tira player da plataforma para evitar 
		// detec��o de colis�o no quadro seguinte
		if (gravity == NORMAL)
			Translate(0, 12);
		else
			Translate(0 , -12);
	}
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	// ----------------------------------------------------
	// a��o da gravidade sobre o personagem
	// ----------------------------------------------------
	if (gravity == NORMAL)	
		Translate(0, 300 * gameTime);
	else
		Translate(0, -300 * gameTime);

	// atualiza anima��o
	anim->Select(gravity);
	anim->NextFrame();
}

// ---------------------------------------------------------------------------------