bin/Dino :src/Dino_chrome.cpp
	g++ src/Dino_chrome.cpp -o bin/Dino -l include -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

run : bin/Dino
	./bin/Dino
