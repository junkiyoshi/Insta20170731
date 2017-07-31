#pragma once

#include "ofMain.h"

class Tear {
public:
	Tear();
	Tear(ofVec3f location);
	~Tear();

	void update();
	void draw();

private:
	float speed;
	float body_color_value;
	ofVec3f location;
};