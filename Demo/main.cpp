#include <iostream>
#include <memory>
#include "UniquePtr.h"
#include "SharedPtr.h"
#include "Point.h"

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

	std::cout << "Shared" << std::endl;
	auto shared { std::make_shared<point::Point>() };
	point::Point point{};
	SharedPtr<point::Point> myShared(point);
	SharedPtr<int> i(1);

	std::cout << shared.get()->ToString() << std::endl;
	auto x = myShared.Get();
	std::cout << x.ToString() << std::endl;

	auto y = SharedPtr<point::Point>::MakeShared(point::Point());
	auto s = y.Get();
	s.x = 1;
	s.y = 2;

	return 0;
}