#include "Tear.h"

Tear::Tear() : Tear(ofVec3f(0, 0, 0)) {
}

Tear::Tear(ofVec3f location){
	this->location = location;
	this->body_color_value = ofRandom(255);
	this->speed = ofRandom(2, 8);
}

Tear::~Tear() {

}

void Tear::update() {
	this->location = this->location - ofVec3f(0, speed, 0);
	if (this->location.y < -ofGetHeight() / 2)
	{
		this->location.y = ofGetHeight() / 2;
	}
}

void Tear::draw() {

	ofColor c;
	c.setHsb(this->body_color_value, 255, 255);
	ofSetColor(c);

	ofPushMatrix();
	ofTranslate(this->location);
	
	ofMesh mesh;

	mesh.addVertex(ofVec3f(5, 0, 0));
	mesh.addVertex(ofVec3f(-5, 0, 0));

	mesh.addVertex(ofVec3f(0, 0, 5));
	mesh.addVertex(ofVec3f(0, 0, -5));

	mesh.addVertex(ofVec3f(0, speed * 3, 0));


	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(2);

	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(3);

	mesh.addIndex(0);
	mesh.addIndex(2);
	mesh.addIndex(4);

	mesh.addIndex(0);
	mesh.addIndex(2);
	mesh.addIndex(4);

	mesh.addIndex(1);
	mesh.addIndex(2);
	mesh.addIndex(4);

	mesh.addIndex(1);
	mesh.addIndex(3);
	mesh.addIndex(4);

	mesh.addIndex(0);
	mesh.addIndex(3);
	mesh.addIndex(4);

	mesh.draw();
	ofSphere(5);
	ofPopMatrix();
}