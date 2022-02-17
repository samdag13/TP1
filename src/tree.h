#pragma once
#include "ofMain.h"
#include <math.h>

class Tree
{
public:
	//constructeur
	Tree(ofVec4f vi, ofVec4f vf, float angle, int id);

	//id pour savoir quelle branche on a
	int m_id;
	float m_angle;

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
	int R1 = rand() % 256;
	int R2 = rand() % 256;
	int R3 = rand() % 256;

	void showLine();

	//afficher des feuilles
	void showellipse();

	void modifier_branche(ofVec4f vi, ofVec4f vf, float angle, float scale);

	Tree branche(float angle, float scale, int id);

	~Tree();

};

