#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

class MyVector
{

private:
	int size;
	int buffer;
	double *element;

public:
	int reserve(int);
	MyVector(int);
	MyVector(const MyVector &);

	inline void setSize(int sz) { size = sz; }
	inline void setBuffer(int buff) { buffer = buff; }

	inline int getSize() { return size; }
	inline int getBuffer() { return buffer; }

	void at(int, double);
	double at(int);
	double operator[](int);
	void push_back(double);
	double pop_back();

	class EmptyVectorException
	{
	};
	class OutOfBoundException
	{
	};
};

double *copy(int, int, double *);

#endif //MYVECTOR_H