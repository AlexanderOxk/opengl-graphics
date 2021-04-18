
build/app: src/Application.cpp
	g++ -o build/app src/Application.cpp `pkg-config --static --cflags --libs glfw3 gl`