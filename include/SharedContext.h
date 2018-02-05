#pragma once
#include "GameInfo.h"

class Window;
class EventManager;

typedef irr::scene::ISceneManager SceneManager;

struct SharedContext
{
	GameInfo		gameInfo;
	Window*			window;
	SceneManager*	sceneManager;
	EventManager*	eventManager;
};
