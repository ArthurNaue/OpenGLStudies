#ifndef MODELS_HPP
#define MODELS_HPP

#include <cstddef>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader/shader.hpp"
#include "texture/texture.hpp"
#include "models/blueprint/models_blueprint.hpp"

typedef enum ModelType{CUBE=0, CONE} ModelType;

class Model
{
	public:
		Model(ModelType model, Texture tex, glm::vec3 pos);

		ModelType GetType(void);
		Texture GetTex(void);
		glm::vec3 GetPos(void);
	private:
		ModelType model;
		Texture tex;
		glm::vec3 pos;
};
#endif
