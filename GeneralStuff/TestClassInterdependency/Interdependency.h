#pragma once

#include <string>
#include <iostream>

class A
{
private:
	int id;
	std::string name;

public:
	A(int id, std::string name) : id(id), name(name) {}
	A(const A &other) : id(other.id), name(other.name) {
		std::cout << "A copy constructor" << std::endl;
	}

	int GetId();
	std::string GetName();

	void SetId(int id);
	void SetName(std::string& name);

	
	A(A && other) : id(other.id), name(std::move(other.name)) {
		std::cout << "A move constructor" << std::endl;
	}
};

class B
{
	// no pointer used
private:
	A dependency;

public:
	B(const A &dependency) : dependency(dependency) {}

	A& GetDependancy();
};

class C
{
	// use pointer to for dependency
private:
	A* dependency;

public:
	C(A* const dependency) : dependency(dependency) {}

	A*& GetDependancy();

};