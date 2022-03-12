#include "Dessin3D.h"
void Dessin3D::add_modele() {
	ModeleProperties modele;
	modele.type = mode;
	modele.scale = scale_modele;
	modele.x = x;
	modele.y = -y;
	modele.z = -z;
	modele.color = color;
	modele.is_filled = is_filled;

	modeles.push_back(modele);

}
void Dessin3D::draw() {
	for (ModeleProperties modele: modeles) {

		ofVec3f pos(modele.x, modele.y, modele.z);

		switch (modele.type)
		{
		case TypeModele::sphere:
			sphere(modele.is_filled, modele.color, pos, modele.scale);
			break;

		case TypeModele::cube:
			cube(modele.is_filled, modele.color, pos, modele.scale);
			break;
		}
	}
}
void Dessin3D::clear_modeles() {
	modeles.clear();
}
void Dessin3D::undo() {
	if (modeles.size() > 0)
	{
		backups.push_back(modeles[modeles.size() - 1]);
		modeles.pop_back();
	}
}

void Dessin3D::redo() {
	if (backups.size() > 0)
	{
		modeles.push_back(backups[backups.size() - 1]);
		backups.pop_back();
	}

}

void Dessin3D::cube(bool p_filled, ofColor p_color, ofVec3f pos, float p_scale) const {
	p_filled ? ofFill() : ofNoFill();
	ofSetColor(p_color);
	ofDrawBox(pos, p_scale);
}
void Dessin3D::sphere(bool p_filled, ofColor p_color, ofVec3f pos, float p_scale) const {
	p_filled ? ofFill() : ofNoFill();
	ofSetColor(p_color);
	ofDrawSphere(pos, p_scale);
}