#pragma once

#include <string>

class A
{
private:
	int id;
	std::string name;

public:
	A(int id, std::string name) : id(id), name(name) {}
	A(const A &other) : id(other.id), name(other.name) {}

	int GetId();
	std::string GetName();

	void SetId(int id);
	void SetName(std::string& name);
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