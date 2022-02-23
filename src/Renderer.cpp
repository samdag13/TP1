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
		gui.draw();
	
	else if (mode == 1)
	{
		gui1.draw();
	}
		
	else if (mode == 2)
	{
		gui2.draw();
	}
		
	else if (mode == 3)
	{
		gui3.draw();
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

	gui.add(cmode.setup("Current mode ", "None"));
	gui.add(dessin2d.setup("1 ", "Dessin 2D"));
	gui.add(arbrefractal.setup("2 ", "Arbre fractal"));
	gui.add(modele3d.setup("3 ", "Modele 3D"));
	gui.add(imageexport.setup("S ", "Screenshot"));
	gui.add(imageimport.setup("I ", "Importer une image"));
}

void Renderer::GUI1Setup() {
	gui1.setup();
	gui1.setDefaultHeight(20);
	gui1.setDefaultWidth(250);
	gui1.setSize(250, 400);

	gui1.add(cmode_1.setup("Current mode ", "None"));
	gui1.add(dessin2d_1.setup("1 ", "Dessin 2D"));
	gui1.add(arbrefractal_1.setup("2 ", "Arbre fractal"));
	gui1.add(modele3d_1.setup("3 ", "Modele 3D"));
	gui1.add(imageexport_1.setup("S ", "Screenshot"));
	gui1.add(imageimport_1.setup("I ", "Importer une image"));
}

void Renderer::GUI2Setup() {
	gui2.setup();
	gui2.setDefaultHeight(20);
	gui2.setDefaultWidth(250);
	gui2.setSize(250, 400);

	gui2.add(cmode_2.setup("Current mode ", "None"));
	gui2.add(dessin2d_2.setup("1 ", "Dessin 2D"));
	gui2.add(arbrefractal_2.setup("2 ", "Arbre fractal"));
	gui2.add(modele3d_2.setup("3 ", "Modele 3D"));
	gui2.add(imageexport_2.setup("S ", "Screenshot"));
	gui2.add(imageimport_2.setup("I ", "Importer une image"));

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

void Renderer::GUI3Setup() {
	gui3.setup();
	gui3.setDefaultHeight(20);
	gui3.setDefaultWidth(250);
	gui3.setSize(250, 400);

	gui3.add(cmode_3.setup("Current mode ", "None"));
	gui3.add(dessin2d_3.setup("1 ", "Dessin 2D"));
	gui3.add(arbrefractal_3.setup("2 ", "Arbre fractal"));
	gui3.add(modele3d_3.setup("3 ", "Modele 3D"));
	gui3.add(imageexport_3.setup("S ", "Screenshot"));
	gui3.add(imageimport_3.setup("I ", "Importer une image"));
}


//updates
void Renderer::updateGUI1Parameters(){
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

	cmode.setup("Current mode ", current_mode);
}

void Renderer::updateGUI3Parameters() {

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

}


