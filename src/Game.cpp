#include "Game.h"

Game::Game()
{
	m_eventManager = new EventManager(&m_sharedContext);
	m_sharedContext.eventManager = m_eventManager;

	m_window = new Window(m_eventManager);
	m_sharedContext.window = m_window;

	m_scene = new Scene(&m_sharedContext);
	m_sharedContext.scene = m_scene;

	m_scene->InitScene();
}

Game::~Game()
{
	delete m_scene;
	delete m_window;
}

void Game::UpdateDeltaTime()
{
	m_sharedContext.currentTime = m_window->GetDevice()->getTimer()->getTime();
	m_sharedContext.deltaTime = (m_sharedContext.currentTime - m_sharedContext.lastTime) / 1000.f;
	m_sharedContext.lastTime = m_window->GetDevice()->getTimer()->getTime();
}


void Game::Run()
{
	while (m_sharedContext.window->GetDevice()->run())
		Update();
}

void Game::Update()
{
	UpdateDeltaTime();

	m_window->GetDriver()->beginScene(true, true, m_window->GetBackgroundColor());

	irr::core::stringw titre(m_window->GetDriver()->getFPS());
	m_window->GetDevice()->setWindowCaption(titre.c_str());

	m_eventManager->Update();

	m_scene->Update();
	m_scene->GetSceneManager().drawAll();

	m_window->GetDriver()->endScene();

	
}
