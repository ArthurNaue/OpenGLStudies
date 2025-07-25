#include "models/blueprint/models_blueprint.hpp"

float cube[] =
{
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

size_t cubeSize = sizeof(cube);

float cone[] =
{
    -0.5f, 0.0f, -0.5f,  0.0f, 0.0f,
     0.5f, 0.0f, -0.5f,  1.0f, 0.0f,
     0.5f, 0.0f,  0.5f,  1.0f, 1.0f,

     0.5f, 0.0f,  0.5f,  1.0f, 1.0f,
    -0.5f, 0.0f,  0.5f,  0.0f, 1.0f,
    -0.5f, 0.0f, -0.5f,  0.0f, 0.0f,

    -0.5f, 0.0f,  0.5f,  0.0f, 0.0f,
     0.5f, 0.0f,  0.5f,  1.0f, 0.0f,
     0.0f, 0.8f,  0.0f,  0.5f, 1.0f,

     0.5f, 0.0f,  0.5f,  0.0f, 0.0f,
     0.5f, 0.0f, -0.5f,  1.0f, 0.0f,
     0.0f, 0.8f,  0.0f,  0.5f, 1.0f,

     0.5f, 0.0f, -0.5f,  0.0f, 0.0f,
    -0.5f, 0.0f, -0.5f,  1.0f, 0.0f,
     0.0f, 0.8f,  0.0f,  0.5f, 1.0f,

    -0.5f, 0.0f, -0.5f,  0.0f, 0.0f,
    -0.5f, 0.0f,  0.5f,  1.0f, 0.0f,
     0.0f, 0.8f,  0.0f,  0.5f, 1.0f
};

size_t coneSize = sizeof(cone);
