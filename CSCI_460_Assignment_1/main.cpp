// CSCI_460_Assignment_1.cpp : Defines the entry point for the console application.
//

/*
NOTE:

There is a typo in the assignment.  The correct partial solution for BFS should read:

Alexandria, Cairo, Matruh, Nekhel, Asyut, Bawiti, Siwa, Quseir, Suez...Luxor

and NOT

Alexandria, Cairo, Matruh, Nekhel, Suez, Asyut, Bawiti,...,...etc, Luxor

Quiz 1 will be held Tuesday 2/11/2014 at 6 pm in class.
It is open book and open notes.
Topics include problem solving,
environment analysis, and blind search algorithms.
Questions will be strictly restricted to just these topics.
Please prepare by reading through the relevant lecture materials.

*/

#include <map>
#include <iostream>
#include <vector>
#include <unordered_map>

// NOTE: -std=gnu++0x or -std=c++0x must be enabled for c++11 stuff to work

// Globals to be used for the program
struct node
{
	std::string name; // Name of the node
	int relativeCost; // Cost of the node itself

	// To be used for Uniform Cost Search
	// Will be used for the cost up to this node,
	// and can be made smaller and smaller as time goes on
	int totalCost;

	std::vector<std::string> children; // List of descendants
	bool isExpanded; // If the node is expanded, this will be true, will prevent loops
};

int main(int argc, char* argv[])
{
	// Instantiate the map
    std::unordered_map<std::string, node*> cityNodes;

	// Build the tree

	// Test that the tree works from going to Alexandria to Luxor

	// Run the Search Function

	std::cout << "Test" << std::endl;

	return 0;
}
