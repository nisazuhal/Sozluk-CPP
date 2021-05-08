#include "MyVector.h"

MyVector::MyVector()
{
}

MyVector::MyVector(int val)
{
	v.push_back(val);
}

MyVector::MyVector(int numberOfItems, int defaultValue)
{
	v = vector<int>(numberOfItems, defaultValue);
}

void MyVector::addNewItem(int value)
{
	this->v.push_back(value);
}

ostream & operator<<(ostream & outputStream, const MyVector & myVector)
{
	for (unsigned i = 0; i < myVector.v.size(); ++i)
		outputStream << myVector.v[i] << "\t";
	outputStream << endl;

	return outputStream;
}

const MyVector operator+(const MyVector & myVector1, const MyVector & myVector2)
{
	MyVector temp;

	if (myVector1.v.size() == myVector2.v.size())
		for (unsigned i = 0; i < myVector1.v.size(); ++i)
			temp.addNewItem(myVector1.v[i] + myVector2.v[i]);

	return temp;
}
