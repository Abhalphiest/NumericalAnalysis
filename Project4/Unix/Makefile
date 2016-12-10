
all: fftOcean

fftOcean: main.cpp FFT.cpp obj.cpp complex.cpp objects.cpp ocean.cpp random.cpp shader.cpp skybox.cpp vector.cpp
	g++ -std=c++11 -o fftOcean.exe *.cpp -lgsl -lgslcblas -lSOIL -lglut -lGL -lm -lGLEW
