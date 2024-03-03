#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "C\n";
}

void identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch (std::bad_cast&) {}
	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "B\n";
	} catch (std::bad_cast&) {}
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "C\n";
	} catch (std::bad_cast&) {}
}

int main() {
	Base* object;
	std::srand(static_cast<unsigned int>(std::time(0)));
	int random = std::rand() % 3;
	if (random == 0) {
		object = new A();
	} else if (random == 1) {
		object = new B();
	} else {
		object = new C();
	}
	std::cout << "  Pointer: ";
	identify(object);
	std::cout << "Reference: ";
	identify(*object);
	return 0;
}
