files=engine/engine.cpp engine/animation/animation.cpp engine/animation/spin_transformation.cpp engine/animation/generic_transformation.cpp engine/scene/scene.cpp models/square.cpp setup/setup.cpp test.cpp

all:
	g++ -o Game -lGL -lglfw -lGLEW $(files)

debug:
	g++ -o Game-debug -g -lGL -lglfw -lGLEW $(files)