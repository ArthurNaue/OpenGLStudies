#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb_image/stb_image.h>

class Texture
{
	public:
		Texture(const char* imagePath);

		void SetActiveTexture(void);
		unsigned int GetTextureID(void);
	private:
		unsigned int textureID;
};

#endif
