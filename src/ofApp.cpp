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
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key)
	{
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
		break;

	case 's':
		renderer.image_export();
		break;

	case 'i':
		renderer.image_import();
		break;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
