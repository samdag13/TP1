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
		renderer.update();
		break;

	case '2':
		renderer.mode = 2;
		renderer.current_mode = "Arbre fractal";
		renderer.update();
		break;

	case '3':
		renderer.mode = 3;
		renderer.current_mode = "Modele 3D";
		renderer.update();
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

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
