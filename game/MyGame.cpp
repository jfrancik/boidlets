#include "stdafx.h"
#include "MyGame.h"
#include "Boid.h"

CMyGame::CMyGame(void)
{
	// TODO: add initialisation here
}

CMyGame::~CMyGame(void)
{
	// TODO: add destruction code here
}

/////////////////////////////////////////////////////
// Per-Frame Callback Funtions (must be implemented!)

void CMyGame::OnUpdate()
{
	for each (CBoid *pBoid in m_boids)
	{
		pBoid->Update(GetTime());
		if (pBoid->GetX() < 0) 
			pBoid->SetX(1023);
		if (pBoid->GetX() > 1023) 
			pBoid->SetX(0);
		if (pBoid->GetY() < 0) 
			pBoid->SetY(767);
		if (pBoid->GetY() >767) 
			pBoid->SetY(0);
	}
}

void CMyGame::OnDraw(CGraphics* g)
{
	for each (CBoid *pBoid in m_boids)
		pBoid->Draw(g);
}

/////////////////////////////////////////////////////
// Game Life Cycle

// one time initialisation
void CMyGame::OnInitialize()
{
}

// called at the start of a new game - display menu here
void CMyGame::OnDisplayMenu()
{
	StartGame();	// this allows to start the game immediately
}

// called when Game Mode entered
void CMyGame::OnStartGame()
{
	for each (CBoid *pBoid in m_boids)
		delete pBoid;
	m_boids.clear();

	for (int i = 0; i < BOIDNUM; i++)
	{
		CBoid *pBoid = new CBoid(rand() % GetWidth(), rand() % GetHeight(), GetTime(), m_boids);
//		CBoid *pBoid = new CBoid(350, 368, GetTime(), m_boids);
		pBoid->SetDirection(rand() % 360);
		pBoid->SetSpeed(100);
		m_boids.push_back(pBoid);
	}
}

// called when Game is Over
void CMyGame::OnGameOver()
{
}

// one time termination code
void CMyGame::OnTerminate()
{
}

/////////////////////////////////////////////////////
// Keyboard Event Handlers

void CMyGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_F4 && (mod & (KMOD_LALT | KMOD_RALT)))
		StopGame();
	if (sym == SDLK_SPACE)
		PauseGame();
	if (sym == SDLK_F2)
		NewGame();
}

void CMyGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
}


/////////////////////////////////////////////////////
// Mouse Events Handlers

void CMyGame::OnMouseMove(Uint16 x,Uint16 y,Sint16 relx,Sint16 rely,bool bLeft,bool bRight,bool bMiddle)
{
}

void CMyGame::OnLButtonDown(Uint16 x,Uint16 y)
{
	CBoid *pBoid = new CBoid(x, y, GetTime(), m_boids);
	pBoid->SetDirection(rand() % 360);
	pBoid->SetSpeed(100);
	m_boids.push_back(pBoid);
}

void CMyGame::OnLButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonUp(Uint16 x,Uint16 y)
{
}
