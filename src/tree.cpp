#include "tree.h"

Tree::Tree(ofVec4f vi, ofVec4f vf, float angle, int id) {

	//id
	m_id = id;
	//bind le nouvel angle
	m_angle = angle;

	v1 = vi;
	v2 = vf;
	v0011.set(0, 0, 1, 1);
}

void Tree::modifier_branche(ofVec4f vi, ofVec4f vf, float angle, float scale) {
	//mettre � jour le nouvel angle
	m_angle = angle;

	//matrice de rotation et de translation
	m.set(
		scale * cos(angle), scale * sin(angle), 0, 0,
		scale * -sin(angle), scale * cos(angle), 0, 0,
		0, 0, 1, 0,
		vf.x, vf.y, 0, 1
	);

	//vecteur r�el (� partir de (0,0))
	ofVec4f v = vf - vi;
	v += v0011;

	//scale, rotation et translation
	v3 = v * m;

	//mettre � jour les vi et vf
	v1 = vf;
	v2 = v3;

}

Tree Tree::branche(float angle, float scale, int id) {
	
	//matrice de rotation et de translation
	m.set(
		scale * cos(angle), scale * sin(angle), 0, 0,
		scale * -sin(angle), scale * cos(angle), 0, 0,
		0, 0, 1, 0,
		v2.x, v2.y, 0, 1
	);

	//vecteur r�el (� partir de (0,0))
	ofVec4f v = v2 - v1;
	v += v0011;
	
	//scale, rotation, translation
	v3 = v * m;

	//cr�ation d'une nouvelle branche avec les nouvelles donn�es
	Tree branche(v2, v3, angle, id);

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
	//ofLog() << "objet d�truit";
};