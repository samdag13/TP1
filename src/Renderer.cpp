#include "Renderer.h"

void Renderer::setup() {
	ofBackground(50);
	ofSetFrameRate(90);

	GUISetup();
	GUI1Setup();
	GUI2Setup();
	GUI3Setup();
}

void Renderer::update() {

	switch (mode)
	{
	case 1:
		updateGUI1Parameters();
		modeDessin2D();
		break;

	case 2:
		updateGUI2Parameters();
		modeArbreFractal();
		break;

	case 3:
		updateGUI3Parameters();
		modeModele3D();
		break;

	default:
		break;
	}
}

void Renderer::draw() {
	if (mode == 0)
	{
		ofDisableDepthTest();
		ofDisableLighting();
		gui.draw();
	}
	
	else if (mode == 1)
	{
		paint.draw();
		ofDisableDepthTest();
		ofDisableLighting();
		gui1.draw();
		prim_choice.draw();
	}
		
	else if (mode == 2)
	{
		ofDisableDepthTest();
		ofDisableLighting();
		gui2.draw();
	}
		
	else if (mode == 3)
	{
		ofDisableDepthTest();
		ofDisableLighting();

		gui3.draw();

		ofEnableDepthTest();
		ofEnableLighting();
	}

	switch (mode)
	{
	//dessin 2D
	case 1:
		break;

	//arbre fractal
	case 2:

		//déplacer le centre ;
		ofTranslate(depart_x, depart_y);

		for (int j = arbre.size() - 1; j >= 0; j--)
		{
			arbre[j].showLine();
		}
		break;

	//modele 3D
	case 3:
		ofTranslate(center_x, center_y,0.0f);

		alien.setPosition(0, 0, 0);
		car.setPosition(0, 0, 0);
		piano.setPosition(0, 0, 0);

		switch (modele)
		{
		case 1:
			alien.draw(OF_MESH_FILL);
			break;
		case 2:
			car.draw(OF_MESH_FILL);
			break;
		case 3:
			piano.draw(OF_MESH_FILL);
			break;
		}

		// activer la caméra
		camera->begin();

		camera->end();
		
		break;

	default:
		break;
	}
}

void Renderer::image_export()
{
	ofImage image;

	// extraire des données temporelles formatées
	string time_stamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");

	// générer un nom de fichier unique et ordonné
	string file_name = "Capture" + time_stamp + ".png";

	// capturer le contenu du framebuffer actif
	image.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	//sauvegarder le fichier image
	image.save(file_name);

	ofLog() << "<export image: " << file_name << ">";

}

void Renderer::image_import()
{

}


//menus
void Renderer::GUISetup() {
	gui.setup();
	gui.setDefaultHeight(20);
	gui.setDefaultWidth(250);
	gui.setSize(250, 400);

	gui.add(cmode.setup("Current mode ", current_mode));
	gui.add(dessin2d.setup("1 ", "Dessin 2D"));
	gui.add(arbrefractal.setup("2 ", "Arbre fractal"));
	gui.add(modele3d.setup("3 ", "Modele 3D"));
	gui.add(imageexport.setup("u ", "Screenshot"));
	gui.add(imageimport.setup("i ", "Importer une image"));
}

//Dessin2D
void Renderer::GUI1Setup() {
	gui1.setup("Proprietes");
	gui1.setDefaultHeight(20);
	gui1.setDefaultWidth(250);
	gui1.setSize(250, 400);

	indications.setup("Indications");
	indications.add(cmode_1.setup("Current mode ", current_mode));
	indications.add(dessin2d_1.setup("1 ", "Dessin 2D"));
	indications.add(arbrefractal_1.setup("2 ", "Arbre fractal"));
	indications.add(modele3d_1.setup("3 ", "Modele 3D"));
	indications.add(imageexport_1.setup("u ", "Screenshot"));
	indications.add(imageimport_1.setup("i ", "Importer une image"));
	gui1.add(&indications);

	stroke_color_2D.set("Couleur du trait", ofColor(120), ofColor(0, 0), ofColor(255, 255, 255));
	fill_color_2D.set("Couleur de remplissage", ofColor(255), ofColor(0, 0), ofColor(255, 255, 255));
	stroke_width_2D.set("Epaisseur du trait", 5.0f, 0.0f, 10.0f);

	gui1.add(stroke_color_2D);
	gui1.add(fill_color_2D);
	gui1.add(stroke_width_2D);

	prim_choice.setup("Choix de primitive");
	prim_choice.setPosition(ofGetWidth() - 260, 10);
	b_line.setup("Ligne");
	b_ell.setup("Ellipse");
	b_tri.setup("Triangle");
	b_point.setup("Cercle");
	b_rect.setup("Rectangle");

	prim_choice.add(&b_line);
	prim_choice.add(&b_ell);
	prim_choice.add(&b_rect);
	prim_choice.add(&b_point);
	prim_choice.add(&b_tri);

}

//Arbre Fractal
void Renderer::GUI2Setup() {
	gui2.setup();
	gui2.setDefaultHeight(20);
	gui2.setDefaultWidth(250);
	gui2.setSize(250, 400);

	gui2.add(cmode_2.setup("Current mode ", current_mode));
	gui2.add(dessin2d_2.setup("1 ", "Dessin 2D"));
	gui2.add(arbrefractal_2.setup("2 ", "Arbre fractal"));
	gui2.add(modele3d_2.setup("3 ", "Modele 3D"));
	gui2.add(imageexport_2.setup("u ", "Screenshot"));
	gui2.add(imageimport_2.setup("i ", "Importer une image"));

	gui2.add(intSlider.setup("Nombre d'etages", 0, 0, 7));
	gui2.add(floatSlider1.setup("Angle", PI / 4, 0.0, 2 * PI));
	gui2.add(floatSlider2.setup("Scale", 0.5, 0.0, 2));
	gui2.add(floatSlider3.setup("Epaisseur", 2, 0.0, 5));

	gui2.add(togglestatic.setup("Static random colors", false));
	gui2.add(toggledynamic.setup("Dynamic random colors", false));

	gui2.add(vec3Slider.setup("RGB Color", ofVec3f(255, 255, 255), ofVec3f(0, 0, 0), ofVec3f(255, 255, 255)));


	depart_x = ofGetWindowWidth() / 2;
	depart_y = ofGetWindowHeight();
	longueurLigne = 300;
	count = 0;

	v1.set(0, 0, 1, 1);
	v2.set(0, -longueurLigne, 1, 1);
	v.set(vec3Slider.getParameter().cast<ofVec3f>());
}

//Modele 3D
void Renderer::GUI3Setup() {
	
	gui3.setup();
	gui3.setDefaultHeight(20);
	gui3.setDefaultWidth(250);
	gui3.setSize(250, 400);

	gui3.add(cmode_3.setup("Current mode ", current_mode));
	gui3.add(dessin2d_3.setup("1 ", "Dessin 2D"));
	gui3.add(arbrefractal_3.setup("2 ", "Arbre fractal"));
	gui3.add(modele3d_3.setup("3 ", "Modele 3D"));
	gui3.add(imageexport_3.setup("u ", "Screenshot"));
	gui3.add(imageimport_3.setup("i ", "Importer une image"));

	gui3.add(camSlider.setup("Camera", 0, 0, 5));

	gui3.add(l_alien.setup("z ", "Alien"));
	gui3.add(l_car.setup("x ", "Car"));
	gui3.add(l_piano.setup("c ", "Piano"));

	alien.loadModel("alien.obj");
	car.loadModel("car.obj");
	piano.loadModel("piano.obj");

	light.setAmbientColor(ofColor(255, 0, 0));
	light.setDiffuseColor(ofColor(255));
	light.setPosition(0.0f,0.0f,1000.0f);
	light.enable();

	center_x = ofGetWindowWidth() / 2;
	center_y = 2*ofGetWindowHeight()/3;

	camera_position = { 0.0f, 0.0f, 0.0f };
	camera_target = { 0.0f, 0.0f, 0.0f };

	camera_near = 50.0f;
	camera_far = 1750.0f;

	camera_fov = 60.0f;
	camera_fov_delta = 16.0f;

	speed_delta = 250.0f;

	is_camera_move_left = false;
	is_camera_move_right = false;
	is_camera_move_up = false;
	is_camera_move_down = false;
	is_camera_move_forward = false;
	is_camera_move_backward = false;

	is_camera_tilt_up = false;
	is_camera_tilt_down = false;
	is_camera_pan_left = false;
	is_camera_pan_right = false;
	is_camera_roll_left = false;
	is_camera_roll_right = false;

	is_camera_fov_narrow = false;
	is_camera_fov_wide = false;

	is_camera_perspective = true;

	setup_camera();
}


//updates
void Renderer::updateGUI1Parameters(){
	paint.fill_color = fill_color_2D;
	paint.stroke_color = stroke_color_2D;
	paint.stroke_width = stroke_width_2D;
	
	if (b_line) paint.shape_mode = Primitive2D::line;
	if (b_point) paint.shape_mode = Primitive2D::point;
	if (b_ell) paint.shape_mode = Primitive2D::ellipse;
	if (b_rect) paint.shape_mode = Primitive2D::rectangle;
	if (b_tri) paint.shape_mode = Primitive2D::triangle;

}

void Renderer::updateGUI2Parameters() {
	//convertir toutes les valeurs :
	p_previous = p;
	p = intSlider.getParameter().cast<int>();

	a_previous = a;
	a = floatSlider1.getParameter().cast<float>();

	s_previous = s;
	s = floatSlider2.getParameter().cast<float>();

	e_previous = e;
	e = floatSlider3.getParameter().cast<float>();

	v_previous = v;
	v = vec3Slider.getParameter().cast<ofVec3f>();

	cmode_2.setup("Current mode ", current_mode);
}

void Renderer::updateGUI3Parameters() {
	c_previous = c;
	c = camSlider.getParameter().cast<int>();

	cmode_3.setup("Current mode ", current_mode);
}


//modes
void Renderer::modeDessin2D() {
}

void Renderer::modeArbreFractal() {

	//couhes
	if (p < p_previous)
	{
		int nbrEnlever;

		for (int i = p_previous; i != p; i--) {

			nbrEnlever = pow(4, count - 1);
			for (int i = 0; i < nbrEnlever; i++)
			{
				arbre.pop_back();
			}
			count--;

		}

		int j = arbre.size() - 1;

		int nbrtroncfalse = pow(4, count - 1);
		for (int i = 0; i < nbrtroncfalse; i++)
		{
			arbre[j].finished = false;
			j--;

		}
	}
	else
		if (p > p_previous)
		{
			if (count == 0)
			{
				//premiere branche
				Tree tree(v1, v2, 0, 0, v, e);
				arbre.push_back(tree);
				count++;
			}
			else
				for (int i = p_previous; i != p; i++) {
					for (int j = arbre.size() - 1; j >= 0; j--)
					{
						if (!arbre[j].finished)
						{
							arbre.push_back(arbre[j].branche(-a, s, 1, v, e));
							arbre.push_back(arbre[j].branche(-a / 2, s, 2, v, e));
							arbre.push_back(arbre[j].branche(a / 2, s, 3, v, e));
							arbre.push_back(arbre[j].branche(a, s, 4, v, e));
							arbre[j].finished = true;
						}

					}
					count++;
				}
		}

	//l'angle
	if (a != a_previous)
	{
		int ecart_avec_tronc = 1;
		for (int j = 1; j < arbre.size(); j++)
		{
			int id = arbre[j].m_id;

			switch (id) {
			case 0:
				break;

			case 1:
				arbre[j].modifier_branche(arbre[j - ecart_avec_tronc].v1, arbre[j - ecart_avec_tronc].v2, -a, s);
				ecart_avec_tronc++;
				break;

			case 2:
				arbre[j].modifier_branche(arbre[j - ecart_avec_tronc].v1, arbre[j - ecart_avec_tronc].v2, -a / 2, s);
				ecart_avec_tronc++;
				break;

			case 3:
				arbre[j].modifier_branche(arbre[j - ecart_avec_tronc].v1, arbre[j - ecart_avec_tronc].v2, a / 2, s);
				ecart_avec_tronc++;
				break;

			case 4:
				arbre[j].modifier_branche(arbre[j - ecart_avec_tronc].v1, arbre[j - ecart_avec_tronc].v2, a, s);
				break;

			default:
				break;

			}
		}
	}

	//scale
	if (s != s_previous)
	{
		int ecart_avec_tronc = 1;
		for (int j = 0; j < arbre.size(); j++)
		{
			int id = arbre[j].m_id;

			switch (id) {
			case 0:
				break;

			case 1:
				arbre[j].modifier_branche(arbre[j - ecart_avec_tronc].v1, arbre[j - ecart_avec_tronc].v2, arbre[j].m_angle, s);
				ecart_avec_tronc++;
				break;

			case 2:
				arbre[j].modifier_branche(arbre[j - ecart_avec_tronc].v1, arbre[j - ecart_avec_tronc].v2, arbre[j].m_angle, s);
				ecart_avec_tronc++;
				break;

			case 3:
				arbre[j].modifier_branche(arbre[j - ecart_avec_tronc].v1, arbre[j - ecart_avec_tronc].v2, arbre[j].m_angle, s);
				ecart_avec_tronc++;
				break;

			case 4:
				arbre[j].modifier_branche(arbre[j - ecart_avec_tronc].v1, arbre[j - ecart_avec_tronc].v2, arbre[j].m_angle, s);
				break;

			default:
				break;

			}
		}
	}

	//epaisseur
	if (e != e_previous)
		for (int j = 0; j < arbre.size(); j++)
			arbre[j].modifier_epaisseur(e);


	//couleur
	if (v.get().x != v_previous.x || v.get().y != v_previous.y || v.get().z != v_previous.z)
		for (int j = 0; j < arbre.size(); j++)
			arbre[j].modifier_couleur(v);

	//static/dynamic random colors (static est prioritaire)
	if (togglestatic)
		for (int j = 0; j < arbre.size(); j++)
			arbre[j].static_random_color();
	else if (toggledynamic) {
		Sleep(1000);
		for (int j = 0; j < arbre.size(); j++)
			arbre[j].dynamic_random_color();
	}
	else
		for (int j = 0; j < arbre.size(); j++)
			arbre[j].modifier_couleur(v);


}

void Renderer::modeModele3D() {

	time_current = ofGetElapsedTimef();
	time_elapsed = time_current - time_last;
	time_last = time_current;

	speed_translation = speed_delta * time_elapsed;
	speed_rotation = speed_translation / 8.0f;

	if (is_camera_move_left)
		camera->truck(-speed_translation);
	if (is_camera_move_right)
		camera->truck(speed_translation);

	if (is_camera_move_up)
		camera->boom(speed_translation);
	if (is_camera_move_down)
		camera->boom(-speed_translation);

	if (is_camera_move_forward)
		camera->dolly(-speed_translation);
	if (is_camera_move_backward)
		camera->dolly(speed_translation);

	if (is_camera_tilt_up)
		camera->tiltDeg(-speed_rotation);
	if (is_camera_tilt_down)
		camera->tiltDeg(speed_rotation);

	if (is_camera_pan_left)
		camera->panDeg(speed_rotation);
	if (is_camera_pan_right)
		camera->panDeg(-speed_rotation);

	if (is_camera_roll_left)
		camera->rollDeg(-speed_rotation);
	if (is_camera_roll_right)
		camera->rollDeg(speed_rotation);

	if (is_camera_perspective)
	{
		if (is_camera_fov_narrow)
		{
			camera_fov = std::max(camera_fov -= camera_fov_delta * time_elapsed, 0.0f);
			camera->setFov(camera_fov);
		}

		if (is_camera_fov_wide)
		{
			camera_fov = std::min(camera_fov += camera_fov_delta * time_elapsed, 180.0f);
			camera->setFov(camera_fov);
		}
	}
}


//camera
void Renderer::setup_camera() {
	if (c != c_previous)
		camera_active = c;

	switch (camera_active)
	{
	case 0:
		camera = &camera_front;
		camera_name = "avant";
		break;

	case 1:
		camera = &camera_back;
		camera_name = "arrière";
		break;

	case 2:
		camera = &camera_left;
		camera_name = "gauche";
		break;

	case 3:
		camera = &camera_right;
		camera_name = "droite";
		break;

	case 4:
		camera = &camera_top;
		camera_name = "haut";
		break;

	case 5:
		camera = &camera_down;
		camera_name = "bas";
		break;

	default:
		break;
	}

	camera_position = camera->getPosition();
	camera_orientation = camera->getOrientationQuat();

	// mode de projection de la caméra
	if (is_camera_perspective)
	{
		camera->disableOrtho();
		camera->setupPerspective(false, camera_fov, camera_near, camera_far, ofVec2f(0, 0));
		camera_projection = "perspective";
	}
	else
	{
		camera->enableOrtho();
		camera_projection = "orthogonale";
	}

	camera->setPosition(camera_position);
	camera->setOrientation(camera_orientation);

	ofLog() << "<setup camera: " << camera_name << ">";
}


