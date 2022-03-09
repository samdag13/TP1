#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	is_key_press_up = false;
	is_key_press_down = false;
	is_key_press_left = false;
	is_key_press_right = false;

	is_key_press_q = false;
	is_key_press_w = false;
	is_key_press_a = false;
	is_key_press_s = false;
	is_key_press_e = false;
	is_key_press_r = false;
	is_key_press_d = false;
	is_key_press_f = false;
	is_key_press_t = false;
	is_key_press_y = false;
	is_key_press_o = false;
	is_key_press_p = false;
	
	renderer.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	renderer.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	renderer.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if(renderer.mode==3){
		switch (key)
		{
			//camera mouvements
		case OF_KEY_LEFT:
			if (renderer.mode == 3)
				is_key_press_right = true;
			break;
		case OF_KEY_UP:
			if (renderer.mode == 3)
				is_key_press_up = true;
			break;
		case OF_KEY_RIGHT:
			if (renderer.mode == 3)
				is_key_press_left = true;
			break;
		case OF_KEY_DOWN:
			if (renderer.mode == 3)
				is_key_press_down = true;
			break;
		case 'q':
			if (renderer.mode == 3)
				is_key_press_q = true;
			break;
		case 'w':
			if (renderer.mode == 3)
				is_key_press_w = true;
			break;
		case 'a':
			if (renderer.mode == 3)
				is_key_press_a = true;
			break;
		case 's':
			if (renderer.mode == 3)
				is_key_press_s = true;
			break;
		case 'e':
			if (renderer.mode == 3)
				is_key_press_e = true;
			break;
		case 'r':
			if (renderer.mode == 3)
				is_key_press_r = true;
			break;
		case 'd':
			if (renderer.mode == 3)
				is_key_press_d = true;
			break;
		case 'f':
			if (renderer.mode == 3)
				is_key_press_f = true;
			break;
		case 't':
			if (renderer.mode == 3)
				is_key_press_t = true;
			break;
		case 'y':
			if (renderer.mode == 3)
				is_key_press_y = true;
			break;
		}

		renderer.is_camera_move_forward = is_key_press_q;
		renderer.is_camera_move_backward = is_key_press_w;

		renderer.is_camera_move_left = is_key_press_left;
		renderer.is_camera_move_right = is_key_press_right;

		renderer.is_camera_move_up = is_key_press_down;
		renderer.is_camera_move_down = is_key_press_up;

		renderer.is_camera_tilt_up = is_key_press_a;
		renderer.is_camera_tilt_down = is_key_press_s;

		renderer.is_camera_pan_left = is_key_press_r;
		renderer.is_camera_pan_right = is_key_press_e;

		renderer.is_camera_roll_left = is_key_press_d;
		renderer.is_camera_roll_right = is_key_press_f;

		renderer.is_camera_fov_narrow = is_key_press_t;
		renderer.is_camera_fov_wide = is_key_press_y;
	}

}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key)
	{
		//modes
	case '1':
		renderer.mode = 1;
		renderer.current_mode = "Dessin 2D";
		break;
	case '2':
		renderer.mode = 2;
		renderer.current_mode = "Arbre fractal";
		break;
	case '3':
		renderer.mode = 3;
		renderer.current_mode = "Modele 3D";
		renderer.update();
		renderer.setup_camera();
		break;

		//images
	case 'u':
		renderer.image_export();
		break;
	case 'i':
		renderer.image_import();
		break;

		//different 3D modeles
	case'z':
		if (renderer.mode == 3)
			renderer.modele = 1;
		break;
	case'x':
		if (renderer.mode == 3)
			renderer.modele = 2;
		break;
	case'c':
		if (renderer.mode == 3)
			renderer.modele = 3;
		break;
	}
	//camera
	if (renderer.mode == 3)
	{
		switch (key)
		{
		case 'o':
			renderer.is_camera_perspective = false;
			renderer.setup_camera();
			ofLog() << "<orthographic projection>";
			break;

		case 'p':
			renderer.is_camera_perspective = true;
			renderer.setup_camera();
			ofLog() << "<perpective projection>";
			break;
			//camera mouvements
		case OF_KEY_LEFT:
				is_key_press_right = false;
			break;
		case OF_KEY_UP:
				is_key_press_up = false;
			break;
		case OF_KEY_RIGHT:
				is_key_press_left = false;
			break;
		case OF_KEY_DOWN:
				is_key_press_down = false;
			break;
		case 'q':
				is_key_press_q = false;
			break;
		case 'w':
				is_key_press_w = false;
			break;
		case 'a':
				is_key_press_a = false;
			break;
		case 's':
				is_key_press_s = false;
			break;
		case 'e':
				is_key_press_e = false;
			break;
		case 'r':
				is_key_press_r = false;
			break;
		case 'd':
				is_key_press_d = false;
			break;
		case 'f':
				is_key_press_f = false;
			break;
		case 't':
				is_key_press_t = false;
			break;
		case 'y':
				is_key_press_y = false;
			break;
		}

		renderer.is_camera_move_forward = is_key_press_q;
		renderer.is_camera_move_backward = is_key_press_w;

		renderer.is_camera_move_left = is_key_press_left;
		renderer.is_camera_move_right = is_key_press_right;

		renderer.is_camera_move_up = is_key_press_down;
		renderer.is_camera_move_down = is_key_press_up;

		renderer.is_camera_tilt_up = is_key_press_a;
		renderer.is_camera_tilt_down = is_key_press_s;

		renderer.is_camera_pan_left = is_key_press_r;
		renderer.is_camera_pan_right = is_key_press_e;

		renderer.is_camera_roll_left = is_key_press_d;
		renderer.is_camera_roll_right = is_key_press_f;

		renderer.is_camera_fov_narrow = is_key_press_t;
		renderer.is_camera_fov_wide = is_key_press_y;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	if (renderer.mode == 1) {
		renderer.paint.mouse_current_x = x;
		renderer.paint.mouse_current_y = y;
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (renderer.mode == 1) {
		renderer.paint.mouse_current_x = x;
		renderer.paint.mouse_current_y = y;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (renderer.mode == 1) {
		renderer.paint.mouse_press = true;
		renderer.paint.mouse_press_x = x;
		renderer.paint.mouse_press_y = y;
		renderer.paint.mouse_current_x = x;
		renderer.paint.mouse_current_y = y;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	if (renderer.mode == 1) {
		renderer.paint.mouse_press = false;
		renderer.paint.mouse_current_x = x;
		renderer.paint.mouse_current_y = y;

		renderer.paint.add_shape(renderer.paint.shape_mode);

		/*
		ofFileDialogResult result = ofSystemLoadDialog("Choisissez une image");
		if (result.bSuccess) { ofLog() << result.filePath; }
		*/
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (renderer.mode == 1) {
		renderer.paint.mouse_current_x = x;
		renderer.paint.mouse_current_y = y;
	}
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

	if (renderer.mode == 1) {
		renderer.paint.mouse_current_x = x;
		renderer.paint.mouse_current_y = y;
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
