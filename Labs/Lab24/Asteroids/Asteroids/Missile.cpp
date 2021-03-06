/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:		23 Nov 2011
// Atualiza��o:	19 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#include "Missile.h"
#include "Asteroids.h"
#include "Explosion.h"
#include "Ship.h"

// ------------------------------------------------------------------------------

Missile::Missile(Ship * ship)
{
	// cria sprite
	sprite = new Sprite("Resources/Missile.png");

	// bounding box
	bbox = new Point();

	// inicializa velocidade
	speed.angle = ship->direction.angle;
	speed.magnitude = 10.0f;
	
	// posi��o inicial do m�ssil
	MoveTo(ship->X() + 20 * cos(speed.Radians()), ship->Y() - 20 * sin(speed.Radians()));

	// rota��o do m�ssil
	rotation = ship->rotation;

	// tipo do objeto
	type = MISSILE;
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
	delete sprite;
	delete bbox;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
	// deslocamento padr�o
	float deltaT = 50 * gameTime;

	// move m�ssel usando o vetor
	Translate(speed.XCom() * deltaT, -speed.YCom() * deltaT);
	
	// destr�i m�ssil que sa� da tela
	if (X() > window->Width() || X() < 0 || Y() > window->Height() || Y() < 0)
	{
		Asteroids::scene->Delete();
	}
}

// -------------------------------------------------------------------------------

void Missile::Draw()
{
	sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------
