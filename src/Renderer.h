#pragma once

#include "ofMain.h"
#include "tree.h"
#include "Dessin2D.h"
#include "ofxGui.h"

class Renderer
{
public:
	int depart_x;
	int depart_y;
	int longueurLigne;

	Dessin2D paint;

	//mode
	//mode
	int mode = 0;
	std::string current_mode;

	ofVec3f v_previous;
	ofParameter<ofVec3f> v;  
	int p_previous;
	ofParameter<int> p = 0;
	float a_previous;
	ofParameter<float> a = PI / 4;
	float s_previous;
	ofParameter<float> s = 0.5;
	float e_previous;
	ofParameter<float> e = 2;

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

	//interface
	ofxPanel gui;
	ofxPanel gui1;
	ofxPanel prim_choice;
	ofxPanel gui2;
	ofxPanel gui3;
	ofxGuiGroup indications;


	//indications pour mode 0
	ofxLabel cmode;
	ofxLabel dessin2d;
	ofxLabel arbrefractal;
	ofxLabel modele3d;
	ofxLabel imageexport;
	ofxLabel imageimport;

	//indications pour mode 1
	ofxLabel cmode_1;
	ofxLabel dessin2d_1;
	ofxLabel arbrefractal_1;
	ofxLabel modele3d_1;
	ofxLabel imageexport_1;
	ofxLabel imageimport_1;

		//input mode 1
	ofParameter<ofColor> stroke_color_2D;
	ofParameter<ofColor> fill_color_2D;
	ofParameter<float> stroke_width_2D;

	ofxButton b_line;
	ofxButton b_point;
	ofxButton b_ell;
	ofxButton b_rect;
	ofxButton b_tri;


	//indications pour mode 2
	ofxLabel cmode_2;
	ofxLabel dessin2d_2;
	ofxLabel arbrefractal_2;
	ofxLabel modele3d_2;
	ofxLabel imageexport_2;
	ofxLabel imageimport_2;
		//input mode 2
	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider1;
	ofxFloatSlider floatSlider2;
	ofxFloatSlider floatSlider3;
	ofxToggle togglestatic;
	ofxToggle toggledynamic;
	ofxVec3Slider vec3Slider;

	//indications pour mode 3
	ofxLabel cmode_3;
	ofxLabel dessin2d_3;
	ofxLabel arbrefractal_3;
	ofxLabel modele3d_3;
	ofxLabel imageexport_3;
	ofxLabel imageimport_3;

	void setup();
	void update();
	void draw();

	void modeDessin2D();
	void modeArbreFractal();
	void modeModele3D();
	void image_export();
	void image_import();

	void GUISetup();

	void GUI1Setup();
	void updateGUI1Parameters();

	void GUI2Setup();
	void updateGUI2Parameters();

	void GUI3Setup();
	void updateGUI3Parameters();
};

