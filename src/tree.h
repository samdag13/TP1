#pragma once
#include "ofMain.h"
#include <math.h>

class Tree
{
public:
	//constructeur
	Tree(ofVec4f vi, ofVec4f vf, float angle, int id, ofColor vcolor, float linewidth);

	//id pour savoir quelle branche on a
	int m_id;
	float m_angle;
	float m_linewidth;

	//pour avoir acces à vi et vf en tout temps
	ofVec4f v1;
	ofVec4f v2;

	//transformer les v4 (debut et fin) en v2 pour etre capable de dessiner
	ofVec2f vi2;
	ofVec2f vf2;

	//ajouter "1" à z et w pour etre capable de translate. z ou w aurait suffit en 2D. z et w obligé en 3D
	ofVec4f v0011;

	//pour les résultats intermédiaire (apres les mutliplications avec les matrices de scale et rotation/translation
	ofVec4f v3;
	
	//matrice de transformations
	ofMatrix4x4 m;
	
	//savoir si la branche a déjà été créé pour ne pas la créer plusieurs fois (optimisation)
	bool finished = false;

	//pour avoir des couleurs random
	unsigned int R = rand() % 256;
	unsigned int G = rand() % 256;
	unsigned int B = rand() % 256;

	//vecteur contenant la couleur de la branche
	ofColor m_vcolor;

	void showLine();

	//afficher des feuilles
	void showellipse();

	void modifier_branche(ofVec4f vi, ofVec4f vf, float angle, float scale);

	void modifier_couleur(ofColor vcolor);

	void modifier_epaisseur(float linewidth);

	void modifier_trans(int x, int y);

	void dynamic_random_color();

	void static_random_color();

	Tree branche(float angle, float scale, int id, ofColor vcolor, float linewidth);

	~Tree();

};

