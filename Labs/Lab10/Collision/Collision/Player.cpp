/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:		22 Dez 2012
// Atualiza��o:	11 Mar 2016
// Compilador:	Visual C++ 14
//
// Descri��o:	Player do jogo Breakout
//
**********************************************************************************/

#include "Breakout.h"
#include "Player.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
	// tamanho do player � 100x20
	bbox = new Rect(0, 0, 99, 19);

	//Mixed * mixed = new Mixed();
	//
	//Circle * cLeft = new Circle(10.0f);
	//cLeft->MoveTo(0.0f, 0.0f);

	//Circle * cRight = new Circle(10.0f);
	//cRight->MoveTo(80.0f, 0.0f);

	//Rect * rect = new Rect(0.0f, 0.0f, 80.0f, 20.0f);
	//rect->MoveTo(10, 0);
	//
	//mixed->Insert(cLeft);
	//mixed->Insert(cRight);
	//mixed->Insert(rect);
	//
	//bbox = mixed;

	sprite = new Sprite("Resources/Player.png");
	MoveTo(window->CenterX() - sprite->Width() / 2.0f, window->Height() - 30.0f, Layer::FRONT);
	state = STOPED;
	type = PLAYER;
	vel = 500;	
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete sprite;
	delete bbox;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
	// bola colidiu com o player
	if (obj->Type() == BALL)
	{
		Ball * ball = (Ball*)obj;
		ball->velY = -ball->velY;
	}	
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	// inicia o jogo com barra de espa�o
	if (state == STOPED && window->KeyDown(VK_SPACE))
		state = PLAYING;

	// desloca jogador horizontalmente
	if (window->KeyDown(VK_RIGHT))
		Translate(vel * gameTime, 0);
	if (window->KeyDown(VK_LEFT))
		Translate(-vel * gameTime, 0);

	// mant�m jogador dentro da janela (tam. da barra: 100x20)
	if (x < 0)
		MoveTo(0.0f, y);
	if (x + sprite->Width() > window->Width())
		MoveTo(float(window->Width() - sprite->Width()), y);
}

// ---------------------------------------------------------------------------------
