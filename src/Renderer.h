#pragma once

#include "ofMain.h"
#include "tree.h"
#include "ofxGui.h"
#include <list>


class Renderer
{
public:
	int depart_x;
	int depart_y;
	int longueurLigne;

	int p_previous;
	ofParameter<int> p = 1;
	float a_previous;
	ofParameter<float> a = PI / 4;
	float s_previous;
	ofParameter<float> s = 0.5;

	//compter le nombre d'étages
	int count;

	//angles
	float angle1 = -PI / 4;
	float angle2 = -PI / 8;
	float angle3 = PI / 8;
	float angle4 = PI / 4;

	//vecteurs pour commencer la première branche
	ofVec4f v1;
	ofVec4f v2;
	
	//liste de tous les branches en objets
	std::vector<Tree> arbre;

	//liste de tous les feuilles en objets
	std::vector<Tree> feuilles;

	//itérateur pour parcourir une liste Tree
	std::vector<Tree>::iterator it;

	void setup();

	void update();

	void draw();

	//interface
	ofxPanel gui;

	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider2;
	ofxFloatSlider floatSlider1;
};

