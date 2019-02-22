#pragma once

#include <iostream>


template<class T>
class AutoPointer {
private:
	T* ptr;

public:
	AutoPointer(T* ptr = nullptr) : ptr(ptr) {}

	AutoPointer(const T& other) {
		std::cout << "Entered copy constructor !\n";
		// use copy operator defined here
		*this = other;
	}

	AutoPointer & operator=(const AutoPointer & other) {
		std::cout << "Entered copy operator !\n";
		*ptr = *other->ptr;
	}

	AutoPointer(AutoPointer && other) noexcept {
		std::cout << "Entered move constructor !\n";
		ptr = other.ptr;
		other.ptr = nullptr;
	}

	AutoPointer & operator=(AutoPointer && other) noexcept {
		std::cout << "Entered move operator !\n";
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;

		return *this;
	}

	~AutoPointer() { delete ptr; }

	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }

	bool isNull() const {
		return ptr == nullptr;
	}
};


class Resource {
public:
	Resource() { std::cout << "Resource acquired!" << std::endl; }
	~Resource() { std::cout << "Resource destroyed!" << std::endl; }

	inline void sayHi() const {
		std::cout << "Hi!" << std::endl;
	}
};

namespace AutoPointerExampleNs {

	AutoPointer<Resource> takeOwnerhipAndReturn(AutoPointer<Resource> res) {
		return res;
	}

	AutoPointer<Resource> generateResource() {
		AutoPointer<Resource> res{ new Resource {} };
		return res;
	}

	void executeExample() {
		AutoPointer<Resource> res1{ new Resource{} };
		AutoPointer<Resource> res2;

		AutoPointer<Resource> res3 = generateResource();

		AutoPointer<Resource> res4 = takeOwnerhipAndReturn(std::move(res3));

		std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
		std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

		res2 = std::move(res1); // res2 assumes ownership, res1 is set to null
		// nice, if the copy operator is set unusable by the = delete syntax then the only option
		// we have is to explicitly use the std::move() function

		std::cout << "Ownership transfered\n";

		std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
		std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
	}
}

