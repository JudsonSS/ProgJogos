/**********************************************************************************
// Platformer (Arquivo de Cabe�alho)
// 
// Cria��o:		05 Out 2011
// Atualiza��o:	04 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Jogo estilo platformer usando a engine do curso
//
**********************************************************************************/

#ifndef _GRAVITYGUY_H_
#define _GRAVITYGUY_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

enum Sounds {MENU, MUSIC, TRANSITION};

// ------------------------------------------------------------------------------

class GravityGuy : public Game
{
private:
	static Game * level;			// n�vel atual do jogo

public:
	static Audio * audio;			// sistema de �udio
	static bool  viewBBox;			// visualiza bounding box
	
	template<class T>
	static void NextLevel()			// muda para pr�ximo n�vel do jogo
	{
		if (level)
		{
			level->Finalize();
			delete level;
			level = new T();
			level->Init();
		}
	};

	void Init();					// inicializa jogo
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif