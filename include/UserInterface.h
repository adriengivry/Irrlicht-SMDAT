#pragma once

#include <irrlicht.h>
#include "SharedContext.h"

class UserInterface
{
public:
	UserInterface(SharedContext* p_sharedContext);
	~UserInterface();

	void Draw();

	void Update();

private:
	SharedContext*					m_sharedContext;
	irr::video::ITexture*			m_crosshair;

	irr::gui::IGUIEnvironment*		m_gui;
	irr::gui::IGUIFont*				m_font;
	irr::scene::ITextSceneNode*		m_text;
	irr::scene::ISceneManager*		m_smgr;

};