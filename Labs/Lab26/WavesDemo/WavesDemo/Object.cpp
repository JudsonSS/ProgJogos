/**********************************************************************************
// Object (C�digo Fonte)
//
// Cria��o:		01 Out 2007
// Atualiza��o:	02 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Essa � a classe base para todos objetos do jogo.
//
//				Um objeto do jogo � qualquer coisa que poss�mos querer desenhar
//				ou interagir dentro do jogo. Por exemplo, um soldado, um pr�dio,
//				um proj�til, uma forma geom�trica, etc.
//
**********************************************************************************/

#include "Object.h"
#include "Engine.h"

// -------------------------------------------------------------------------------
// Inicializa��o de vari�veis est�ticas da classe

Window* & Object::window = Engine::window;			// ponteiro para a janela
Game*   & Object::game = Engine::game;				// ponteiro para o jogo
float   & Object::gameTime = Engine::frameTime;		// tempo do �ltimo quadro

// -------------------------------------------------------------------------------

Object::Object()
{
	// posi��o do objeto
	x = y = 0.0f;

	// profundidade do objeto
	z = 0.5f;

	// escala do objeto
	scale = 1.0f;

	// rota��o do objeto
	rotation = 0.0f;

	//tipo do objeto
	type = 0;

	// bounding box do objeto
	bbox = nullptr;
}

// -------------------------------------------------------------------------------

Object::~Object()
{
}

// -------------------------------------------------------------------------------

void Object::Translate(float dx, float dy, float dz)
{
	x += dx;
	y += dy;
	z += dz;

	if (bbox)
		bbox->Translate(dx, dy);
}

// -------------------------------------------------------------------------------

void Object::MoveTo(float px, float py, float pz)
{
	x = px;
	y = py;
	z = pz;

	if (bbox)
		bbox->MoveTo(px, py);
}

// -------------------------------------------------------------------------------

void Object::MoveTo(float px, float py)
{
	x = px;
	y = py;

	if (bbox)
		bbox->MoveTo(px, py);
}

// -------------------------------------------------------------------------------

void Object::Scale(float factor)
{
	scale *= factor;

	if (bbox)
		bbox->Scale(factor);
}

// -------------------------------------------------------------------------------

void Object::ScaleTo(float factor)
{
	scale = factor;

	if (bbox)
		bbox->ScaleTo(factor);
}

// -------------------------------------------------------------------------------

void Object::Rotate(float angle)
{
	rotation += angle;

	if (bbox)
		bbox->Rotate(angle);
}

// -------------------------------------------------------------------------------

void Object::RotateTo(float angle)
{
	rotation = angle;

	if (bbox)
		bbox->RotateTo(angle);
}

// -------------------------------------------------------------------------------

void Object::OnCollision(Object* obj)
{
}

// -------------------------------------------------------------------------------