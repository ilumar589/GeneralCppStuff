#pragma once

#include <vector>

struct Leaf {/**/ };
struct Branch {/**/ };

class OakTree {
private:
	std::vector<Leaf> leafs;
	std::vector<Branch> branches;

public:

	//OakTree& operator=(const OakTree& other) {
		//leafs = other.leafs;
		// If copying the branches throws an exception, only the leafs have been
		// copied and the OakTree is left in an invalid state
		//branches = other.branches;
	//}

	OakTree& operator=(const OakTree& other) {
		// This can be fixed by using an idiom called copy and swap
		// First create local copies without modifying the OakTree objects.
		// Copying may throw an exception but it's state will remain valid

		auto leafs = other.leafs;
		auto branches = other.branches;

		// No exceptions thrown, we can now safely modify
		// the state of this object by non-throwing swap
		std::swap(this->leafs, leafs);
		std::swap(this->branches, branches);

		return *this;
	}
};