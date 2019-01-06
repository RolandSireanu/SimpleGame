CPP_SOURCE_FILES=main.cpp 
CPP_SOURCE_FILES += IOSubject.cpp
CPP_SOURCE_FILES += Display.cpp


all :
	 g++ $(CPP_SOURCE_FILES) -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lOpenGL

debug:
	g++ $(CPP_SOURCE_FILES) -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lOpenGL -DDEBUG

run : all
	./sfml-app

runDebug: debug
	./sfml-app
	
clean :
	rm sfml-app