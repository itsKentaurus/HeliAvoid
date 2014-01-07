#ifndef VIEW_H
#define VIEW_H
#include <string>
#include <stdlib.h>
#include <GL/glut.h> 

class View {
private:
	float ZoomConstant;
	float zoomFactor;
	float farv;
	float nearv;
	float viewWindowLeft, viewWindowRight;
	float viewWindowBottom, viewWindowTop, fovy;
	float width;
	float height;
	int projType;

	void update();

public:
	View();
	View(float width, float height);
	void initialized();
	void setView(float width = 0, float height = 0);
	void toggleOrtho();
	void togglePers();
	void zoom(unsigned char key);
	std::string getProjection();
};

#endif