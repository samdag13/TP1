#include "tree.h"

Tree::Tree(ofVec4f vi, ofVec4f vf, float angle, int id, ofVec3f vcolor) {

	//id
	m_id = id;
	//bind le nouvel angle
	m_angle = angle;

	v1 = vi;
	v2 = vf;
	v0011.set(0, 0, 1, 1);

	m_vcolor.x = vcolor.x;
	m_vcolor.y = vcolor.y;
	m_vcolor.z = vcolor.z;
	m_linewidth = 2;
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

void Tree::modifier_couleur(ofVec3f vcolor)
{
	m_vcolor = vcolor;
}

void Tree::dynamic_random_color() {
	unsigned int r = rand() % 256;
	unsigned g = rand() % 256;
	unsigned b = rand() % 256;
	m_vcolor.x = r;
	m_vcolor.y = g;
	m_vcolor.z = b;
}

void Tree::static_random_color() {
	m_vcolor.x = R;
	m_vcolor.y = G;
	m_vcolor.z = B;
}

Tree Tree::branche(float angle, float scale, int id, ofVec3f vcolor) {

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
	Tree branche(v2, v3, angle, id, vcolor);

	return branche;
}

void Tree::showLine() {
	ofFill();
	ofSetLineWidth(m_linewidth);
	ofSetColor(m_vcolor.x, m_vcolor.y, m_vcolor.z);
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