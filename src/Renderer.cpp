#include "Renderer.h"

void Renderer::setup() {


	ofBackground(50);
	ofSetFrameRate(60);

	GUIMenusSetup();

	depart_x = ofGetWindowWidth() / 2;
	depart_y = ofGetWindowHeight();
	longueurLigne = 300;
	count = 0;

	v1.set(0, 0, 1, 1);
	v2.set(0, -longueurLigne, 1, 1);
	v.set(vec3Slider.getParameter().cast<ofVec3f>());	
}

void Renderer::update() {

	updateGUIParameters();

	//bouton 1 (Dessin vectoriel)
	if (toggle1)
	{
		modeDessin2D();
	}

	//bouton 2 (arbre fractal)	
	else if (toggle2)
	{
		modeArbreFractal();
	}

	//bouton 1 (Modele 3D)
	else if (toggle3)
	{

	}

	//bouton 1 (Screenshot)
	else if (bouton4)
	{


		ofImage image;

		// extraire des données temporelles formatées
		string time_stamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");

		// générer un nom de fichier unique et ordonné
		string file_name = "Capture" + time_stamp + ".png";

		// capturer le contenu du framebuffer actif
		image.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

		// sauvegarder le fichier image
		image.save(file_name);

		ofLog() << "<export image: " << file_name << ">";
	}

	//bouton 1 (Importer image)
	else if (bouton5)
	{

	}
}

void Renderer::draw() {
	gui.draw();

	//déplacer le centre ;
	ofTranslate(depart_x, depart_y);

	if(toggle2)
	for (int j = arbre.size()-1; j >= 0; j--)
	{		
		arbre[j].showLine();
	}
}


void Renderer::modeDessin2D() {}

void Renderer::modeArbreFractal() {

	updateProfondeurArbre();
	updateAngleArbre();
	updateScaleArbre();
	updateEpaisseurArbre();
	updateCouleurArbre();


}

void Renderer::GUIMenusSetup() {
	gui.setup();

	gui.add(intSlider.setup("Nombre d'etages", 0, 0, 7));
	gui.add(floatSlider1.setup("Angle", PI / 4, 0.0, 2 * PI));
	gui.add(floatSlider2.setup("Scale", 0.5, 0.0, 2));
	gui.add(floatSlider3.setup("Epaisseur", 2, 0.0, 5));

	gui.add(togglestatic.setup("Static random colors", false));
	gui.add(toggledynamic.setup("Dynamic random colors", false));

	gui.add(vec3Slider.setup("RGB Color", ofVec3f(255, 255, 255), ofVec3f(0, 0, 0), ofVec3f(255, 255, 255)));

	//togglegroup.setup("Switch pages");
	gui.add(toggle1.setup("Dessin vectoriel", false));
	gui.add(toggle2.setup("Arbre fractal", false));
	gui.add(toggle3.setup("Modele 3D", false));
	gui.add(bouton4.setup("Screenshot"));
	gui.add(bouton5.setup("Importer une image"));

	//toggle group marche pas:(((((((
	//gui.add(togglegroup.setup("Switch pages"));
}

void Renderer::updateProfondeurArbre() {
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
}

void Renderer::updateAngleArbre() {
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
}

void Renderer::updateEpaisseurArbre() {
	//epaisseur
	if (e != e_previous)
		for (int j = 0; j < arbre.size(); j++)
			arbre[j].modifier_epaisseur(e);
}

void Renderer::updateScaleArbre() {

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
}

void Renderer::updateCouleurArbre() {

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

void Renderer::updateGUIParameters() {
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
}