#include <iostream>
#include <memory>
#include "UniquePtr.h"

using namespace SmartPtr;
int main()
{
	const int value = 42;
	const int value2 = 1;
	auto q = new int{ value };

	UniquePtr<int> ptr{ value };
	UniquePtr<int> ptr2{ value2 };
	std::cout << ptr.Get() << " " << ptr2.Get() << std::endl;
	ptr.Swap(ptr2);
	std::cout << ptr.Get() << " " << ptr2.Get() << std::endl;

	ptr.Reset(ptr2);
	std::cout << ptr.Get() << std::endl;
	delete q;

	//std::unique_ptr<int> u_ptr1{ std::make_unique<int>(value) };
	//std::cout << *u_ptr1.get() << std::endl;
	return 0;
}