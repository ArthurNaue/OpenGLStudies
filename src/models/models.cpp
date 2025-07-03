#include "models/models.hpp"

Model::Model(ModelType model, Texture tex, glm::vec3 pos) : model(model), tex(tex), pos(pos){}

ModelType Model::GetType(void)
{
	return model;
}

Texture Model::GetTex(void)
{
	return tex;
}

glm::vec3 Model::GetPos(void)
{
	return pos;
}
