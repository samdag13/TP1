#include "Renderer.h"

void Renderer::setup() {
	gui.setup();

	gui.add(intSlider.setup("Nombre de couches", 1, 0, 6));
	gui.add(floatSlider1.setup("Angle", PI/4, 0.0, 2 * PI));
	gui.add(floatSlider2.setup("Scale", 0.5, 0.0, 2));

	//conversion
	p = intSlider.getParameter().cast<int>();
	a = floatSlider1.getParameter().cast<float>();
	s = floatSlider2.getParameter().cast<float>();

	ofBackground(50);
	//ofSetFrameRate(1);

	depart_x = ofGetWindowWidth() / 2;
	depart_y = ofGetWindowHeight();
	longueurLigne = 300;
	count = 0;

	v1.set(0, 0, 1, 1);
	v2.set(0, -longueurLigne, 1, 1);

	//premiere branche
	Tree tree(v1, v2, 0);
	arbre.push_back(tree);

	ofLog() << "un tree en octet : " << sizeof(tree);
	ofLog() << "debut list : " << &arbre.begin();
	ofLog() << "fin list : " << &arbre.end();
	ofLog() << "size vect : " << arbre.size();
	//les autres branches
	for (int i = 0; i < p; i++)
	{
		for (int j = arbre.size()-1; j >= 0; j--)
		{
			if (!arbre[j].finished)
			{
				arbre.push_back(arbre[j].branche(-a, s, 1));
				arbre.push_back(arbre[j].branche(-a/2, s, 2));
				arbre.push_back(arbre[j].branche(a/2, s, 3));
				arbre.push_back(arbre[j].branche(a, s, 4));
				arbre[j].finished = true;
			}
			
		}
		count++;
		//ofLog() << "fin list : " << &arbre.end();
		//mettre des feuilles au bouts de chaque branche si count = 5 (ne fonctionne pas correctement)
		//if (count == 5)
		//{
		//	for (it = arbre.begin(); it != arbre.end(); it++)
		//	{
		//		Tree feuille(it->v1, it->v2);
		//		feuilles.push_front(feuille);
		//	}
		//}
	}
	
}

void Renderer::update() {
	//convertir la value du intSlider en int
	 p_previous = p;
	 p = intSlider.getParameter().cast<int>();
	 

	//ofLog() << "p : " << p;
	//ofLog() << "p_previous : " <<p_previous;

	//pour les couhes
	if (p < p_previous)
	{
		int nbrEnlever;

		for (int i = p_previous; i != p; i--) {
			nbrEnlever = pow(4, count);

			for (int i = 0; i < nbrEnlever; i++)
			{
				arbre.pop_back();
			}
			count--;

		}

		int j = arbre.size()-1;

		int nbrtroncfalse = pow(4, count);
		for (int i = 0; i < nbrtroncfalse; i++)
		{
			arbre[j].finished = false;
			j--;

		}
	}
	else
		if (p > p_previous)			
		{
			for (int i = p_previous; i != p; i++) {
				for (int j = arbre.size()-1; j >= 0; j--)
				{
					if (!arbre[j].finished)
					{
						arbre.push_back(arbre[j].branche(-a, s, 1));
						arbre.push_back(arbre[j].branche(-a / 2, s, 2));
						arbre.push_back(arbre[j].branche(a / 2, s, 3));
						arbre.push_back(arbre[j].branche(a, s, 4));
						arbre[j].finished = true;
					}

				}
				count++;
			}
		}

	//l'angle (doit etre par rapport à lui meme)
	a_previous = a;
	a = floatSlider1.getParameter().cast<float>();
	if (a != a_previous)
	{
		for (int j = arbre.size()-1; j >= 0; j--)
		{
			int id = arbre[j].m_id;

			switch (id) {
			case 0:
				break;

			case 1: //le plus pres (-1)			
				arbre[j].modifier_branche(arbre[j - 1].v1, arbre[j - 1].v1, a, 1);
				break;

			case 2:
				arbre[j].modifier_branche(arbre[j - 2].v1, arbre[j - 2].v1, a, 1);
				break;

			case 3:
				arbre[j].modifier_branche(arbre[j - 3].v1, arbre[j - 3].v1, a, 1);
				break;

			case 4: //le plus loin du tronc (-4)
				arbre[j].modifier_branche(arbre[j - 4].v1, arbre[j - 4].v1, a, 1);
				break;

			default:
				break;

			}
		}
	}
	//scale (doit etre par rapport à la branche mère)
	s_previous = s;
	s = floatSlider2.getParameter().cast<float>();
	if (s != s_previous)
	{
		for (int j = arbre.size()-1; j >= 0; j--)
		{
			int id = arbre[j].m_id;

			switch (id) {
			case 0:
				break;

			case 1: //le plus pres (-1)			
				arbre[j].modifier_branche(arbre[j - 1].v1, arbre[j - 1].v1, 0, s);
				break;

			case 2:
				arbre[j].modifier_branche(arbre[j - 2].v1, arbre[j - 2].v1, 0, s);
				break;

			case 3:
				arbre[j].modifier_branche(arbre[j - 3].v1, arbre[j - 3].v1, 0, s);
				break;

			case 4: //le plus loin du tronc (-4)
				arbre[j].modifier_branche(arbre[j - 4].v1, arbre[j - 4].v1, 0, s);
				break;

			default:
				break;

			}
		}
	}

}

void Renderer::draw() {
	gui.draw();

	//déplacer le centre ;
	ofTranslate(depart_x, depart_y);

	for (int j = arbre.size()-1; j >= 0; j--)
	{		
		arbre[j].showLine();
		
		//it->showellipse();
	}

	//voir les feuilles
	//for (it = feuilles.begin(); it != feuilles.end(); it++)
	//{
	//	it->showellipse();
	//}
}
