bin/Dino :  src/.cpp
	g++ src/Dino_chrome.cpp -o bin/Dino -I include -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

run : bin/Dino
	./bin/Dino

