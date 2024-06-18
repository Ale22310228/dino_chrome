bin/cow : src/cow.cpp include/*
	c++ src/cow.cpp -o bin/cow -lcurses -I include

run : bin/cow
	./bin/cow
