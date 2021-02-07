
#include "texturemanager.h"

namespace rasterization
{
	TextureManager* TextureManager::_instance = nullptr;
	
	TextureManager* TextureManager::getInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new TextureManager();
		}
		return _instance;
	}

	TextureManager::TextureManager()
	{
	}

	TextureManager::~TextureManager()
	{
		if (_instance)
		{
			delete _instance;
			_instance = nullptr;
		}
	}
}