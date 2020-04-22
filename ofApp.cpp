#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();

	this->r_frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
	this->b_frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	this->r_frame.clear();
	this->b_frame.clear();

	float R = 350;
	float r = 50;

	
	for (int deg = 0; deg <= 360; deg += 1) {

		int index = this->r_frame.getNumVertices();

		this->r_frame.addVertex(this->make_point(R, r, deg * 8 + ofGetFrameNum(), deg));
		this->r_frame.addVertex(this->make_point(R, r, deg * 8 + ofGetFrameNum(), deg + 10));

		this->r_frame.addIndex(index + 0);
		this->r_frame.addIndex(index + 1);

		index = this->b_frame.getNumVertices();

		this->b_frame.addVertex(this->make_point(R, r, deg * 8 + ofGetFrameNum() + 180, deg));
		this->b_frame.addVertex(this->make_point(R, r, deg * 8 + ofGetFrameNum() + 180, deg + 10));

		this->b_frame.addIndex(index + 0);
		this->b_frame.addIndex(index + 1);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofSetColor(239, 39, 39);
	this->r_frame.drawWireframe();

	for (auto& location : this->r_frame.getVertices()) {

		ofDrawSphere(location, 2);
	}

	ofSetColor(39, 39, 239);
	this->b_frame.drawWireframe();

	for (auto& location : this->b_frame.getVertices()) {

		ofDrawSphere(location, 2);
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}