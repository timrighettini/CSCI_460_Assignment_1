// CSCI_460_Assignment_1.cpp : Defines the entry point for the console application.
//

#include <map>
#include <iostream>
#include <vector>

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


// Globals to be used for the program
struct node
{
	std::string name; // Name of the node
	int relativeCost; // Cost of the node itself

	// To be used for Uniform Cost Search
	// Will be used for the cost up to this node,
	// and can be made smaller and smaller as time goes on
	int totalCost;

	std::vector<std::string> children; // List of decendants
	bool isExpanded; // If the node is expanded, this will be true, will prevent loops
};

int main(int argc, char* argv[])
{
	// Instantiate the map

	// Build the tree

	// Test that the tree works from going to Alexandria to Luxor

	// Run the Search Function

	std::cout << "Test" << std::endl;

	return 0;
}
