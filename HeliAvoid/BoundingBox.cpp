#include "BoundingBox.h"
#include <iostream>
#include <array>

BoundingBox::BoundingBox()
	:m_minVertex(0,0,0)
	,m_maxVertex(0,0,0)
{}
BoundingBox::BoundingBox(std::array<float,3> maxPoint, std::array<float,3> minPoint)
	:m_minVertex(minPoint)
	,m_maxVertex(maxPoint)
{
	sideStrings[0] = "None";
	sideStrings[1] = "Front";
	sideStrings[2] = "Back";
	sideStrings[3] = "Top";
	sideStrings[4] = "Bottom";
	sideStrings[5] = "Left";
	sideStrings[6] = "Right";
}
BoundingBox::BoundingBox(float length,float width, float height,float cenX, float cenY, float cenZ) 
	:m_minVertex(-length/2 + cenX,-width/2 + cenY,-height/2 + cenZ)
	,m_maxVertex(length/2 + cenX,width/2 + cenY,height/2 + cenZ)
{
	sideStrings[0] = "None";
	sideStrings[1] = "Front";
	sideStrings[2] = "Back";
	sideStrings[3] = "Top";
	sideStrings[4] = "Bottom";
	sideStrings[5] = "Left";
	sideStrings[6] = "Right";
}

BoundingBox::~BoundingBox(void) {
}

Sides BoundingBox::isIntersecting(BoundingBox &otherBox) {
	//not inside

	if (m_minVertex.getX() > otherBox.m_maxVertex.getX() ||
		m_minVertex.getY() > otherBox.m_maxVertex.getY() ||
		m_minVertex.getZ() > otherBox.m_maxVertex.getZ() ||

		m_maxVertex.getX() < otherBox.m_minVertex.getX() ||
		m_maxVertex.getY() < otherBox.m_minVertex.getY() ||
		m_maxVertex.getZ() < otherBox.m_minVertex.getZ()
		) {intersection = Sides::None;}else{
			//if (m_minVertex.getX() < otherBox.m_maxVertex.getX()){intersection = Sides::Right;}
			//if (m_minVertex.getY() < otherBox.m_maxVertex.getY()){intersection = Sides::Bottom;}
			//if (m_minVertex.getZ() < otherBox.m_maxVertex.getZ()){intersection = Sides::Back;}

			//if (m_maxVertex.getX() > otherBox.m_minVertex.getX()){intersection = Sides::Left;}
			//if (m_maxVertex.getZ() > otherBox.m_minVertex.getZ()){intersection = Sides::Front;}
			//if (m_maxVertex.getY() > otherBox.m_minVertex.getY()){intersection = Sides::Top;}
			intersection = Sides::Top;
	}
	return intersection;
}
bool BoundingBox::isBehind(BoundingBox &otherBox) {

	if (m_maxVertex.getZ() < otherBox.m_minVertex.getZ()) {
		std::cout << "behind"<<std::endl;
		return true;
	}
	return false;
}
bool BoundingBox::isInside(BoundingBox &otherBox) {
		/*if (m_maxVertex < otherBox.m_maxVertex &&
		m_minVertex > otherBox.m_minVertex)*/

		if (m_maxVertex.getX() < otherBox.m_maxVertex.getX() &&
		m_maxVertex.getY() < otherBox.m_maxVertex.getY() &&

		m_minVertex.getX() > otherBox.m_minVertex.getX() &&
		m_minVertex.getY() > otherBox.m_minVertex.getY() 

		){
		return true;
	}
	return false;
}
void BoundingBox::updateAdd(float x, float y, float z) {
	m_maxVertex.update(m_maxVertex.getX() + x, m_maxVertex.getY() + y, m_maxVertex.getZ() + z);
	m_minVertex.update(m_minVertex.getX() + x, m_minVertex.getY() + y, m_minVertex.getZ() + z);
}
int BoundingBox::size() {

	return m_maxVertex.size();
}