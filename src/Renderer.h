#pragma once

#include "ofMain.h"
#include "tree.h"
#include "ofxGui.h"


class Renderer
{
public:
	int depart_x;
	int depart_y;
	int longueurLigne;

	//compter le nombre d'�tages
	int count;

	//avoir acces au nombre dans le intSlider
	int nbrIntSlider;

	//angles
	float angle1 = -PI / 4;
	float angle2 = -PI / 8;
	float angle3 = PI / 8;
	float angle4 = PI / 4;

	float scale = 0.5;

	//vecteurs pour commencer la premi�re branche
	ofVec4f v1;
	ofVec4f v2;
	
	//liste de tous les branches en objets
	std::list<Tree> arbre;

	//liste de tous les feuilles en objets
	std::list<Tree> feuilles;

	//it�rateur pour parcourir une liste Tree
	std::list<Tree>::iterator it;

	void setup();

	void update();

	void draw();

	//interface
	ofxPanel gui;

	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider;
};

