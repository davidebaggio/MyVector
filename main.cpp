#include "MyVector.h"
#include <iostream>

int main()
{
	MyVector vector(2);
	vector.push_back(4.0);
	vector.push_back(7.0);
	vector.push_back(3.0);
	for (int i = 0; i < vector.getSize(); i++)
		std::cout << vector[i] << "\n";
	std::cout << "Size = " << vector.getSize() << "\n"
			  << "Buffer = " << vector.getBuffer();
}
