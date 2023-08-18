#pragma once

class Game {
private:
public:
	void init(int, int, const char*);
	void handleEvent();
	void update();
	void render();
	void clean();
};