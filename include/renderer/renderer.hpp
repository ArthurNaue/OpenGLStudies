#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "models/models.hpp"

class Renderer
{
	public:
		Renderer(void);

		void Update(void);
		void Delete(void);
	private:
		unsigned int VBO, VAO;	
};

#endif
