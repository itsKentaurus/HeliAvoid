#include "View.h"
View::View(float w, float h) {
	width = w;
	height = h;
}
View::View() {
}
void View::initialized() {
	height = 500;
	width = 600;
	ZoomConstant = .5;
	zoomFactor = 1.008;
	farv = 300;
	nearv = 1;
	fovy = 90;
	projType = 1;
	update();
}

void View::setView(float w, float h) {
	width = w;
	height = h;
	update();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(projType)	gluPerspective(fovy, (GLfloat )width/height, nearv, farv);
	else			glOrtho(viewWindowLeft, viewWindowRight, viewWindowBottom, viewWindowTop, nearv, farv );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void View::toggleOrtho() {
	projType = 0;
}

void View::togglePers() {
	projType = 1;
}

void View::update() {
	viewWindowLeft = -width/25;
	viewWindowBottom = -height/25; 
	viewWindowRight = width/25;
	viewWindowTop = height/25;
}
/*	void zoom(unsigned char key)
	This functions zooms in along the
	the perspective that is enabled
	wither it is orthoganol or
	perspective
*/
void View::zoom(unsigned char key) {
	if (key == '+') {
		viewWindowLeft += ZoomConstant;		// Increases the width and height
		viewWindowRight -= ZoomConstant;	// of the viewwing cube
		viewWindowBottom += ZoomConstant; 
		viewWindowTop -= ZoomConstant;
		fovy = fovy / zoomFactor;			// And decreses the fovy
	}
	else if (key == '-') {
		viewWindowLeft -= ZoomConstant;		// Decreases the width and height
		viewWindowRight += ZoomConstant;	// of the viewing cube
		viewWindowBottom -= ZoomConstant; 
		viewWindowTop += ZoomConstant;
		fovy = fovy * zoomFactor;			// And increases the fovy
	}
}
std::string View::getProjection() {
	if (!projType) return "Ortogonal";
	else	  return "Perspective";
}