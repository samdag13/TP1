#pragma once

#include "ofMain.h"
#include "tree.h"
#include "Dessin2D.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"

class Renderer
{
public:
	int depart_x;
	int depart_y;

	int longueurLigne;

	Dessin2D paint;

	//mode
	int mode = 0;
	string current_mode = "None";

	int modele = 1;

	int camera_active = 0;

	ofColor v_previous;
	ofColor v;  
	int p_previous;
	ofParameter<int> p = 0;
	float a_previous;
	ofParameter<float> a = PI / 4;
	float s_previous;
	ofParameter<float> s = 0.5;
	float e_previous;
	ofParameter<float> e = 2;

	int c_previous;
	ofParameter<int> c = 0;

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
	ofxPanel gui2;
	ofxPanel gui3;
	ofxPanel prim_choice;

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
	ofxGuiGroup indications_1;

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
	ofxGuiGroup indications_2;
	ofxGuiGroup parametres;

	//input mode 2
	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider1;
	ofxFloatSlider floatSlider2;
	ofxFloatSlider floatSlider3;
	ofxToggle togglestatic;
	ofxToggle toggledynamic;
	ofParameter<ofColor> treeColor;

	//indications pour mode 3
	ofxLabel cmode_3;
	ofxLabel dessin2d_3;
	ofxLabel arbrefractal_3;
	ofxLabel modele3d_3;
	ofxLabel imageexport_3;
	ofxLabel imageimport_3;
	ofxGuiGroup indications_3;
	ofxGuiGroup commandes_camera;
	ofxGuiGroup types_objets;

	ofxAssimpModelLoader alien;
	ofxAssimpModelLoader car;
	ofxAssimpModelLoader piano;

	ofxLabel l_alien;
	ofxLabel l_car;
	ofxLabel l_piano;

	ofxLabel fleches;
	ofxLabel qw;
	ofxLabel as;
	ofxLabel er;
	ofxLabel df;
	ofxLabel ty;
	ofxLabel op;
	ofLight light;

	//camera

	ofxIntSlider camSlider;
	ofCamera camera_front;
	ofCamera camera_back;
	ofCamera camera_left;
	ofCamera camera_right;
	ofCamera camera_top;
	ofCamera camera_down;

	ofCamera* camera;

	ofQuaternion camera_orientation;

	string camera_name;
	string camera_projection;

	ofVec3f camera_position;
	ofVec3f camera_target;

	float camera_near;
	float camera_far;

	float camera_fov;
	float camera_fov_delta;

	float offset_camera;
	float offset_color;
	float offset_scene;
	float offset_objet;

	float speed_delta;
	float speed_translation;
	float speed_rotation;

	float time_current;
	float time_last;
	float time_elapsed;

	bool is_camera_move_left;
	bool is_camera_move_right;
	bool is_camera_move_up;
	bool is_camera_move_down;
	bool is_camera_move_forward;
	bool is_camera_move_backward;

	bool is_camera_tilt_up;
	bool is_camera_tilt_down;
	bool is_camera_pan_left;
	bool is_camera_pan_right;
	bool is_camera_roll_left;
	bool is_camera_roll_right;

	bool is_camera_fov_narrow;
	bool is_camera_fov_wide;

	bool is_camera_perspective;

	void setup();
	void update();
	void draw();

	void reset();
	void setup_camera();

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

