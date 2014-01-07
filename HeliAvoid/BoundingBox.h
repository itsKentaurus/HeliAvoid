#ifndef BoundingBox_H
#define BoundingBox_H
#include <array>
#include "Vertex.h"


//enum Shapes
//{
//	Square    //length
//	,Rectangle//length,width,depth
//	,Sphere   //radius
//	,Cylinder //radiusBase,radiusTop,Length
//};
enum Sides {
	None
	,Top
	,Bottom
	,Front
	,Back
	,Left
	,Right
};
class BoundingBox
{
private:
	std::string sideStrings[7];
	bool front,left,right,top,bottom;//rear doesnt matter
	Sides intersection;
public:
	BoundingBox();
	BoundingBox(std::array<float,3> maxPoint, std::array<float,3> minPoint);
	BoundingBox(float length,float width, float height,float cenX, float cenY, float cenZ);
	~BoundingBox(void);
	//
	BoundingBox mergeBBox(const BoundingBox &otherBox);
	Sides isIntersecting(BoundingBox &otherBox);
	bool isInside(BoundingBox &otherBox);
	bool isBehind(BoundingBox &otherBox);

	Vertex m_minVertex;
	Vertex m_maxVertex;

	std::string getIntersection(){return sideStrings[(int)intersection];};

	void updateAdd(float x, float y, float z);
	int size();
	
};
#endif