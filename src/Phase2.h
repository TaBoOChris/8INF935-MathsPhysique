#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>	
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

#include "maths/Vecteur3D.h"
#include "maths/Particule.h"
#include "maths/Matrix3.h"
#include "maths/Matrix4.h"

#include "maths/force/RegistreForces.h"
#include "maths/force/BungeeString.h"
#include "maths/force/DragGenerator.h"
#include "maths/force/GravityGenerator.h"
#include "maths/force/ParticleAnchoredSpring.h"
#include "maths/force/ParticleBuoyancy.h"
#include "maths/force/ParticleSpring.h"

#include "maths/contact/ParticleContactResolver.h"
#include "maths/contact/ParticleLink.h"
#include "maths/contact/ParticleRod.h"
#include "maths/contact/ParticleCable.h"

#include "opengl/Model.h"
#include "opengl/UserInterface.h"
#include "opengl/MoteurPhysique.h"


#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

class Phase2
{
public :

	Phase2();
	void run();
};

