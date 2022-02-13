#pragma once
#include "ofMain.h"
#include <math.h>

class Tree
{
public:
	//constructeur
	Tree(ofVec4f vi, ofVec4f vf);

	//pour avoir acces � vi et vf en tout temps
	ofVec4f v1;
	ofVec4f v2;

	//pour avoir acces � l'angle et au scale en tout temps
	float angle1;
	float scale1;

	//transformer les v4 (debut et fin) en v2 pour etre capable de dessiner
	ofVec2f vi2;
	ofVec2f vf2;

	//ajouter "1" � z et w pour etre capable de translate. z ou w aurait suffit en 2D. z et w oblig� en 3D
	ofVec4f v0011;

	//pour les r�sultats interm�diaire (apres les mutliplications avec les matrices de scale et rotation/translation
	ofVec4f v3;
	ofVec4f v4;
	
	//matrice de transformations
	ofMatrix4x4 mr;
	ofMatrix4x4 ms;
	

	//savoir si la branche a d�j� �t� cr�� pour ne pas la cr�er plusieurs fois (optimisation)
	bool finished = false;

	//pour avoir des couleurs random
	int R1 = rand() % 256;
	int R2 = rand() % 256;
	int R3 = rand() % 256;

	void showLine();

	//afficher des feuilles
	void showellipse();

	Tree branche(float angle, float scale);

	~Tree();

};

