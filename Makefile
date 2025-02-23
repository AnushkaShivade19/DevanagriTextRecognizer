all: recognizer

recognizer:
	@g++ -fsanitize=address -g -o recognizer recognizer.cpp main.cpp `pkg-config --cflags --libs opencv4`

clean:
	rm -rf recognizer