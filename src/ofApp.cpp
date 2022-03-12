#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
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
				renderer.is_camera_move_right = true;
			break;
		case OF_KEY_UP:
				renderer.is_camera_move_down = true;
			break;
		case OF_KEY_RIGHT:
				renderer.is_camera_move_left = true;
			break;
		case OF_KEY_DOWN:
				renderer.is_camera_move_up = true;
			break;
		case 'q':
				renderer.is_camera_move_forward = true;
			break;
		case 'w':
				renderer.is_camera_move_backward = true;
			break;
		case 'a':
				renderer.is_camera_tilt_up = true;
			break;
		case 's':
				renderer.is_camera_tilt_down = true;
			break;
		case 'e':
				renderer.is_camera_pan_right = true;
			break;
		case 'r':
				renderer.is_camera_pan_left = true;
			break;
		case 'd':
				renderer.is_camera_roll_left = true;
			break;
		case 'f':
				renderer.is_camera_roll_right = true;
			break;
		case 't':
				renderer.is_camera_fov_narrow = true;
			break;
		case 'y':
				renderer.is_camera_fov_wide = true;
			break;
		}
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
		renderer.setup_camera();
		break;

		//images
	case 'u':
		renderer.image_export();
		break;	
	
	case 'i':
		if(renderer.mode == 2) renderer.paint.add_bg_image();
		break;

	case 'h':
		renderer.gui_hidden = !renderer.gui_hidden;
		break;


		//different 3D modeles
	
	}
	//camera
	if (renderer.mode == 3)
	{
		switch (key)
		{
		case'z':
				renderer.modele = 1;
			break;
		case'x':
				renderer.modele = 2;
			break;
		case'c':
				renderer.modele = 3;
			break;
		case'v':
				renderer.modele = 4;
			break;
		case'b':
				renderer.modele = 5;
			break;
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
			renderer.is_camera_move_right = false;
			break;
		case OF_KEY_UP:
			renderer.is_camera_move_down = false;
			break;
		case OF_KEY_RIGHT:
			renderer.is_camera_move_left = false;
			break;
		case OF_KEY_DOWN:
			renderer.is_camera_move_up = false;
			break;
		case 'q':
			renderer.is_camera_move_forward = false;
			break;
		case 'w':
			renderer.is_camera_move_backward = false;
			break;
		case 'a':
			renderer.is_camera_tilt_up = false;
			break;
		case 's':
			renderer.is_camera_tilt_down = false;
			break;
		case 'e':
			renderer.is_camera_pan_right = false;
			break;
		case 'r':
			renderer.is_camera_pan_left = false;
			break;
		case 'd':
				renderer.is_camera_roll_left = false;
			break;
		case 'f':
			renderer.is_camera_roll_right = false;
			break;
		case 't':
			renderer.is_camera_fov_narrow = false;
			break;
		case 'y':
			renderer.is_camera_fov_wide = false;
			break;
		}

	}
	else if (renderer.mode == 1) {
		switch (key)
		{
		case 'i':
			renderer.image_import();
		break;
		}
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
void ofApp::windowResized(int w, int h) {

	if (renderer.mode==1) {

		renderer.primitive_choice.setPosition(ofGetWindowWidth() - 300, 10);
		renderer.img_start_x.set("x start position", 100, 0, ofGetWindowWidth());
		renderer.img_start_y.set("y start position", 100, 0, ofGetWindowHeight());
		renderer.img_end_x.set("x end position", 500, 0, ofGetWindowWidth());
		renderer.img_end_y.set("y end position", 500, 0, ofGetWindowHeight());
	}
	else if (renderer.mode == 2) {

		renderer.intSlider_trans_x.set("Translation X", renderer.depart_x, 0, ofGetWindowWidth());
		renderer.intSlider_trans_y.set("Translation Y", renderer.depart_y, 0, ofGetWindowHeight());
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
