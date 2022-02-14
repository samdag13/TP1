#include "Renderer.h"

void Renderer::setup() {
	gui.setup();

	gui.add(intSlider.setup("int slider", 1, 0, 6));
	gui.add(floatSlider.setup("float slider", 0.0, 0.0, 2 * PI));

	//convertir la value du intSlider en int
	ofParameter<int> p = intSlider.getParameter().cast<int>();
	nbrIntSlider = p;

	ofBackground(50);
	//ofSetFrameRate(1);

	depart_x = ofGetWindowWidth() / 2;
	depart_y = ofGetWindowHeight();
	longueurLigne = 300;
	count = 0;

	v1.set(0, 0, 1, 1);
	v2.set(0, -longueurLigne, 1, 1);

	//premiere branche
	Tree tree(v1, v2);
	//int size = sizeof(Tree);
	//ofLog() << size;
	arbre.push_front(tree);
	
	//les autres branches
	for (int i = 0; i < p; i++)
	{
		for (it = arbre.begin(); it != arbre.end(); it++)
		{
			if (!it->finished)
			{
				arbre.push_front(it->branche(angle1, scale));
				arbre.push_front(it->branche(angle2, scale));
				arbre.push_front(it->branche(angle3, scale));
				arbre.push_front(it->branche(angle4, scale));
				it->finished = true;
			}
			
		}
		count++;

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


	if (p < p_previous)
	{
		int nbrEnlever = 0;
		//ofLog() << "entr� dans le pop";
		for (int i = p_previous; i != p; i--) {
			int nbrEnlever = pow(4, count);
			for (int i = 0; i < nbrEnlever; i++)
			{
				arbre.pop_front();
			}
			count--;

		}

		it = arbre.begin();

		nbrEnlever = pow(4, count);
		for (int i = 0; i < nbrEnlever; i++)
		{
			it->finished = false;
			it++;

		}
	}
	else
		if (p > p_previous)			
		{
			ofLog() << "entr� dans le push";
			for (int i = p_previous; i != p; i++) {
				for (it = arbre.begin(); it != arbre.end(); it++)
				{
					ofLog() << it->finished;

					if (!it->finished)
					{
						arbre.push_front(it->branche(angle1, scale));
						arbre.push_front(it->branche(angle2, scale));
						arbre.push_front(it->branche(angle3, scale));
						arbre.push_front(it->branche(angle4, scale));
						it->finished = true;
					}	

				}
				count++;
			}
		}

}

void Renderer::draw() {
	gui.draw();

	//d�placer le centre ;
	ofTranslate(depart_x, depart_y);

	for (it = arbre.begin(); it != arbre.end(); it++)
	{		
		it->showLine();
		
		//it->showellipse();
	}

	//voir les feuilles
	//for (it = feuilles.begin(); it != feuilles.end(); it++)
	//{
	//	it->showellipse();
	//}
}
