#include "renderer/renderer.hpp"

Renderer::Renderer(void)
{
	RegisterModel(CUBE, cube, cubeSize, 36);
	RegisterModel(CONE, cone, coneSize, 18);
}

void Renderer::RegisterModel(ModelType type, float* vertices, size_t size, int count)
{
	ModelData data;
	data.vertices = vertices;
	data.vertexSize = size;
	data.vertexCount = count;

	glGenVertexArrays(1, &data.VAO);
	glGenBuffers(1, &data.VBO);

	glBindVertexArray(data.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, data.VBO);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	modelDataMap[type] = data;
}	

void Renderer::AddInstance(Model model)
{
	modelDataMap[model.GetType()].instances.push_back(model);
}

void Renderer::DrawAll(Shader& shader)
{
	for(auto& [type, data] : modelDataMap)
	{
		glBindVertexArray(data.VAO);
		for(auto& instance : data.instances)
		{
			instance.GetTex().SetActiveTexture();

			glm::mat4 modelMat = glm::mat4(1.0f);
			modelMat = glm::translate(modelMat, instance.GetPos());
			shader.SetMat4("model", modelMat);

			glDrawArrays(GL_TRIANGLES, 0, data.vertexCount);
		}
	}
}

void Renderer::Delete(void)
{
	for(auto& [_, data] : modelDataMap)
	{
		glDeleteVertexArrays(1, &data.VAO);
		glDeleteBuffers(1, &data.VBO);
	}
}
