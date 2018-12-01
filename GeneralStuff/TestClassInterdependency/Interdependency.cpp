#include "Interdependency.h"

int A::GetId()
{
	return id;
}

std::string A::GetName()
{
	return name;
}

void A::SetId(int id)
{
	this->id = id;
}

void A::SetName(std::string & name)
{
	this->name = name;
}

A& B::GetDependancy()
{
	return dependency;
}

A *& C::GetDependancy()
{
	return dependency;
}
