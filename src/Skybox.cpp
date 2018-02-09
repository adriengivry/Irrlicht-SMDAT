#include "Skybox.h"
#include "Window.h"
#include "Scene.h"

Skybox::Skybox(SharedContext* p_sharedContext)
{
	irr::video::ITexture* up = p_sharedContext->window->GetDriver()->getTexture("../assets/textures/skybox/up.tga");
	irr::video::ITexture* dn = p_sharedContext->window->GetDriver()->getTexture("../assets/textures/skybox/dn.tga");
	irr::video::ITexture* lf = p_sharedContext->window->GetDriver()->getTexture("../assets/textures/skybox/lf.tga");
	irr::video::ITexture* rt = p_sharedContext->window->GetDriver()->getTexture("../assets/textures/skybox/rt.tga");
	irr::video::ITexture* ft = p_sharedContext->window->GetDriver()->getTexture("../assets/textures/skybox/ft.tga");
	irr::video::ITexture* bk = p_sharedContext->window->GetDriver()->getTexture("../assets/textures/skybox/bk.tga");

	m_skyboxNode = p_sharedContext->scene->GetSceneManager().addSkyBoxSceneNode(up, dn, lf, rt, ft, bk, nullptr);

	p_sharedContext->scene->GetSceneManager().setAmbientLight(irr::video::SColorf(0.2f, 0.2f, 0.2f, 0.0));
}
