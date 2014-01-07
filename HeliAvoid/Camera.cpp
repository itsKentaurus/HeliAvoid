#include "Camera.h"

Camera::Camera() {
}
void Camera::initialized() {
	dz = distance = 19;
	dx = dy = ex = ez = ey = 0;
	longitude = latitude = 0;
	person = 3;
	eLongitude = eLatitude = 0;
	moveCamUp();
	moveCamUp();
}
/*	void moveCamera(unsigned char key)
	this functions takes in a char
	and moves the camera away or towards the object
	by using the proportion of the movement
*/
void Camera::moveCamera(unsigned char key) {
	float oDistance;		// Old distance
	float nDistance;		// New distance
	nDistance = oDistance = distance;	// set the current distance

	if ( key == '+')		nDistance = --distance;		// If statement determines if going forwards
	else if (key == '-')	nDistance = ++distance;		// or backwards
	else if (key == '1') 
						{	savedDistance = distance;
							person = 1;}
	else if (key == '3')
						{	distance = savedDistance;
							person = 3;}
	update();
}
void Camera::modLatitude(float y) {
	latitude += y;
	update();
}
void Camera::modLongitude(float x) {
	longitude += x;
	update();
}
void Camera::modeLatitude(float y) {
	eLatitude += y;
	update();
}
void Camera::modeLongitude(float x) {
	eLongitude += x;
	update();
}
void Camera::reset() {
	dx = dy = dz = ex = ey = ez = 0;
}
bool Camera::isFirstPerson() {
	return (person == 1);
}
bool Camera::isThirdPerson() {
	return (person == 3);
}
void Camera::updateLook() {
	gluLookAt(dx,dy,dz,ex,ey,ez,0,1,0);
}
void Camera::update() {

	if (latitude >= 1.5)				// Sets the limit to how high the camera can go
		latitude = 1.4;					
	if (latitude <= -1.5)				// Sets the limit to how low the camera can go
		latitude = -1.4;

	if (eLatitude > 1.5)
		eLatitude = 1.5;
	if (eLatitude < -1.5)
		eLatitude = -1.5;
	if (eLongitude > 1.5)
		eLongitude = 1.5;
	if (eLongitude < -1.5)
		eLongitude = -1.5;

	if (isFirstPerson()) {
		ez = -cos(eLatitude)*cos(eLongitude) + tz;
		ex = -cos(eLatitude)*sin(eLongitude) + tx;
		ey = -sin(eLatitude) + ty;
	}
	if (isThirdPerson()) {
		dz = distance*cos(latitude)*cos(longitude) + tz;
		dx = distance*cos(latitude)*sin(longitude) + tx;
		dy = distance*sin(latitude) + ty;
	}
		gluLookAt(dx,dy,dz,ex,ey,ez,0,1,0);

}
void Camera::moveCamLeft() {
	if (isFirstPerson())		modeLongitude(0.1);
	else if (isThirdPerson())	modLongitude(-0.1);
}
void Camera::moveCamRight() {
	if (isFirstPerson())		modeLongitude(-0.1);
	else if (isThirdPerson())	modLongitude(0.1);
}
void Camera::moveCamUp() {
	if (isFirstPerson())		modeLatitude(-0.1);
	else if (isThirdPerson())	modLatitude(0.1);
}
void Camera::moveCamDown() {
	if (isFirstPerson())		modeLatitude(0.1);
	else if (isThirdPerson())	modLatitude(-0.1);
}

void Camera::updateLook(Model m) {
	if (isThirdPerson()) {
		tx = ex = m.getX();
		ty = ey = m.getY();
		tz = ez = m.getZ();
	}
	if (isFirstPerson()) {
		tx = dx = m.getX();
		ty = dy = m.getY();
		tz = dz = m.getZ();
	}
	update();


}

void Camera::updateLook(float x, float y, float z) {
	if (isThirdPerson()) {
		tx = ex = x;
		ty = ey = y;
		tz = ez = z;
	}
	if (isFirstPerson()) {
		tx = dx = x;
		ty = dy = y;
		tz = dz = z;
	}
	update();
}

void Camera::moveRight(float i) {
	
}
void Camera::moveLeft(float i) {
}

void Camera::moveUp(float i) {
}

void Camera::moveDown(float i) {
}

