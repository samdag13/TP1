#include "tree.h"

Tree::Tree(ofVec4f vi, ofVec4f vf) {

	v1 = vi;
	v2 = vf;
	v0011.set(0, 0, 1, 1);
}

Tree Tree::branche(float angle, float scale) {

	angle1 = angle;
	scale1 = scale;

	//matrice de rotation et de translation
	mr.set(
		cos(angle), sin(angle), 0, 0,
		-sin(angle), cos(angle), 0, 0,
		0, 0, 1, 0,
		v2.x, v2.y, 0, 1
	);

	//matrice de scale
	ms.set(
		scale, 0, 0, 0,
		0, scale, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	//vecteur réel (à partir de (0,0))
	ofVec4f v = v2 - v1;
	v += v0011;
	
	//scaling
	v3 = v * ms;

	//rotation et translation
	v4 = v3 * mr;

	//création d'une nouvelle branche avec les nouvelles données
	Tree branche(v2, v4);

	return branche;
}

void Tree::showLine() {
	ofFill();
	ofSetLineWidth(2);
	ofSetColor(R1,R2,R3);
	vi2 = v1;
	vf2 = v2;
	ofDrawLine(vi2, vf2);
}

void Tree::showellipse() {
	ofFill();
	ofSetLineWidth(0);
	ofSetColor(255,0,0,100);
	vi2 = v1;
	vf2 = v2;
	ofDrawEllipse(vf2, 10,50);
}

Tree::~Tree() {
	ofLog() << "objet détruit";
};