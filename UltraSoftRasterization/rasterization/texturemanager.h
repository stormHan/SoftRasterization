#pragma once
// ----------- Texture Memory Manager -----------
// Author: stormhan
// Date: 2021/01/23

#ifndef __TEXTURE_MANAGER__
#define __TEXTURE_MANAGER__

namespace rasterization
{
	class TextureManager
	{
	public:
		static TextureManager* getInstance();

		TextureManager(const TextureManager& rhs) = delete;

		TextureManager& operator= (const TextureManager& rhs) = delete;

	private:
		static TextureManager* _instance;
		TextureManager();
		~TextureManager();
	};
}

#endif // __TEXTURE_MANAGER__