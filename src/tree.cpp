#include "tree.h"

Tree::Tree(ofVec4f vi, ofVec4f vf, float angle, int id, ofColor vcolor, float linewidth) {

	//id
	m_id = id;
	//bind le nouvel angle
	m_angle = angle;

	v1 = vi;
	v2 = vf;
	v0011.set(0, 0, 1, 1);

	m_vcolor.r = vcolor.r;
	m_vcolor.g = vcolor.g;
	m_vcolor.b = vcolor.b;
	m_vcolor.a = vcolor.a;
	m_linewidth = linewidth;
}

void Tree::modifier_branche(ofVec4f vi, ofVec4f vf, float angle, float scale) {
	//mettre à jour le nouvel angle
	m_angle = angle;

	//matrice de rotation et de translation
	m.set(
		scale * cos(angle), scale * sin(angle), 0, 0,
		scale * -sin(angle), scale * cos(angle), 0, 0,
		0, 0, 1, 0,
		vf.x, vf.y, 0, 1
	);

	//vecteur réel (à partir de (0,0))
	ofVec4f v = vf - vi;
	v += v0011;

	//scale, rotation et translation
	v3 = v * m;

	//mettre à jour les vi et vf
	v1 = vf;
	v2 = v3;
}

void Tree::modifier_couleur(ofColor vcolor)
{
	m_vcolor = vcolor;
}

void Tree::modifier_epaisseur(float linewidth) {
	m_linewidth = linewidth;
}

void Tree::dynamic_random_color() {
	unsigned int r = rand() % 256;
	unsigned int g = rand() % 256;
	unsigned int b = rand() % 256;
	m_vcolor.r = r;
	m_vcolor.g = g;
	m_vcolor.b = b;
	m_vcolor.a = 255;
}

void Tree::static_random_color() {
	m_vcolor.r = R;
	m_vcolor.g = G;
	m_vcolor.b = B;
	m_vcolor.a = 255;
}

Tree Tree::branche(float angle, float scale, int id, ofColor vcolor, float linewidth) {

	//matrice de rotation et de translation
	m.set(
		scale * cos(angle), scale * sin(angle), 0, 0,
		scale * -sin(angle), scale * cos(angle), 0, 0,
		0, 0, 1, 0,
		v2.x, v2.y, 0, 1
	);

	//vecteur réel (à partir de (0,0))
	ofVec4f v = v2 - v1;
	v += v0011;
	
	//scale, rotation, translation
	v3 = v * m;

	//création d'une nouvelle branche avec les nouvelles données
	Tree branche(v2, v3, angle, id, vcolor, linewidth);

	return branche;
}

void Tree::showLine() {
	ofFill();
	ofSetLineWidth(m_linewidth);
	ofSetColor(m_vcolor.r, m_vcolor.g, m_vcolor.b, m_vcolor.a);
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
	//ofLog() << "objet détruit";
};