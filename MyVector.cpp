#include "MyVector.h"

int MyVector::reserve(int buff)
{
	if (buff < 100)
		return 100;
	else
		return buff;
}

MyVector::MyVector(int buff)
{
	size = 0;
	buffer = reserve(buff);
	element = new double(buffer);
}

MyVector::MyVector(const MyVector &arg)
{
	size = arg.size;
	buffer = arg.buffer;
	element = copy(arg.size, 0, arg.element);
}

void MyVector::at(int index, double el)
{
	if (index < 0 || index >= size)
		throw OutOfBoundException{};
	else
	{
		if (element[index] != 0)
			std::cout << "E' gia' presente un elemento che verrà rimosso: " << element[index] << "\n";
		element[index] = el;
	}
}

double MyVector::at(int index)
{
	if (index < 0 || index >= size)
		throw OutOfBoundException{};
	else
		return element[index];
}

double MyVector::operator[](int index)
{
	return element[index];
}

void MyVector::push_back(double el)
{
	if (size < buffer)
	{
		element[size] = el;
		size++;
	}
	else
	{
		int off = 100;
		double *temp = copy(size, off, element);
		temp[size] = el;
		delete[] element;
		buffer += off;
		element = temp;
		size++;
	}
}

double MyVector::pop_back()
{
	if (size == 0)
		throw EmptyVectorException{};
	else
	{
		double temp = element[size - 1];
		element[size - 1] = 0;
		size--;
		return temp;
	}
}

double *copy(int sz, int offset, double *src)
{
	double *dest = new double(sz + offset);
	for (int i = 0; i <= sz; i++)
	{
		dest[i] = src[i];
	}
	return dest;
}