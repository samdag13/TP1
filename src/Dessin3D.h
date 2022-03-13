#pragma once
#include "ofMain.h"



enum class TypeModele {sphere, cube};
struct ModeleProperties {
	float x;
	float y;
	float z;

	float scale;
	bool is_filled;

	ofColor color;
	TypeModele type;

};
class Dessin3D
{

public:
	std::vector<ModeleProperties> modeles;
	std::vector<ModeleProperties> backups;
	TypeModele mode;
	ofColor color;
	bool is_filled = false;
	//Valeur qui sert de hauteur/profondeur/largeur du cube et de rayon de la sphere
	float scale_modele;

	//Valeurs obtenu par les sliders du gui
	float x;
	float y;
	float z;

	void add_modele();
	void draw();
	void clear_modeles();
	void undo();
	void redo();
	void cube(bool p_filled, ofColor p_color, ofVec3f pos, float p_scale) const;
	void sphere(bool p_filled, ofColor p_color, ofVec3f pos, float p_scale) const;
};

