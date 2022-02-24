#pragma once

#include "ofMain.h"
#include "Renderer.h"

class ofApp : public ofBaseApp{

	public:

		Renderer renderer;

		//camera mouvements
		bool is_key_press_up;
		bool is_key_press_down;
		bool is_key_press_left;
		bool is_key_press_right;

		bool is_key_press_q;
		bool is_key_press_w;
		bool is_key_press_a;
		bool is_key_press_s;
		bool is_key_press_e;
		bool is_key_press_r;
		bool is_key_press_d;
		bool is_key_press_f;
		bool is_key_press_t;
		bool is_key_press_y;
		bool is_key_press_o;
		bool is_key_press_p;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
};
