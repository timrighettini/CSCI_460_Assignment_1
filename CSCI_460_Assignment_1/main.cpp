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
#include <map>
#include <algorithm>

// NOTE: -std=gnu++0x or -std=c++0x must be enabled for c++ 2011 stuff to work

// Globals to be used for the program

struct ConnectedNode // Will be a struct used for children to expand from
{
    std::string name;
    int cost; // Cost between this Node and the Node it is attached to

    ConnectedNode(std::string name, int cost)
    {
        this->name = name;
        this->cost = cost;
    }
};

struct Node
{
    std::vector<ConnectedNode> children; // List of descendants
    std::string name; // Name of the Node

    // To be used for Uniform Cost Search
    // Will be used for the cost up to this Node,
    // and can be made smaller and smaller as time goes on
    int totalCost;

    bool isQueued; // If the Node is expanded, this will be true, will prevent loops
};

// Used for a aorting comparison
struct FunctorUCS
{
        // Overloading () operators for std::sort()
    bool operator ()(Node *a, Node *b)
    {
        if (a->totalCost < b->totalCost) return true;
        if (a->totalCost > b->totalCost) return false;

        if (a->name < b->name) return true;
        if (a->name > b->name) return false;

        return false;
    }
} functorUCS;

bool isUCS = false;

// Function Prototypes
void GeneralSearch(std::map<std::string, Node*>&, std::vector<Node*> &, std::vector<Node*> &, Node *);
void EnqueueBFS(std::map<std::string, Node*>&, std::vector<Node*> &, Node *);
void EnqueueDFS(std::map<std::string, Node*>&, std::vector<Node*> &, Node *);
void EnqueueUCS(std::map<std::string, Node*>&, std::vector<Node*> &, Node *);
bool GoalTest(Node *, Node* );

int main(int argc, char* argv[])
{
    // Instantiate the map
    std::map<std::string, Node*> cityNodes;
    std::vector<Node*> currentNodes; // Will be the vector used for Queuing for the three Queuing functions
    std::vector<Node*> exploredNodes; // Will be the vector used for keeping track of what has been found so far
    // NOTE: I use this vector as a queue. stack, and priority queue all at once to save on instantiating different lists

    // Build the tree

    // Alexandria Node
    Node* n = new Node();

    n->name = "Alexandria";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Matruh", 159));
    n->children.push_back(ConnectedNode("Cairo", 112));
    n->children.push_back(ConnectedNode("Nekhel", 245));

    cityNodes[n->name] = n;

    // Nekhel Node
    n = new Node();

    n->name = "Nekhel";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Alexandria", 245));
    n->children.push_back(ConnectedNode("Suez", 72));
    n->children.push_back(ConnectedNode("Quseir", 265));

    cityNodes[n->name] = n;

    // Suez Node
    n = new Node();

    n->name = "Suez";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Nekhel", 72));

    cityNodes[n->name] = n;

    // Quseir Node
    n = new Node();

    n->name = "Quseir";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Sohag", 163));
    n->children.push_back(ConnectedNode("Nekhel", 265));

    cityNodes[n->name] = n;

    // Sohag Node
    n = new Node();

    n->name = "Sohag";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Mut", 184));
    n->children.push_back(ConnectedNode("Qena", 69));
    n->children.push_back(ConnectedNode("Quseir", 163));

    cityNodes[n->name] = n;

    // Qena Node
    n = new Node();

    n->name = "Qena";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Luxor", 33));
    n->children.push_back(ConnectedNode("Sohag", 69));

    cityNodes[n->name] = n;

    // Luxor Node
    n = new Node();

    n->name = "Luxor";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Qena", 33));

    cityNodes[n->name] = n;

    // Kharga Node
    n = new Node();

    n->name = "Kharga";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Mut", 98));

    cityNodes[n->name] = n;

    // Mut Node
    n = new Node();

    n->name = "Mut";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Qasr Farafra", 126));
    n->children.push_back(ConnectedNode("Sohag", 184));
    n->children.push_back(ConnectedNode("Kharga", 98));

    cityNodes[n->name] = n;

    // Qasr Farafra Node
    n = new Node();

    n->name = "Qasr Farafra";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Bawiti", 104));
    n->children.push_back(ConnectedNode("Mut", 126));

    cityNodes[n->name] = n;

    // Bawiti Node
    n = new Node();

    n->name = "Bawiti";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Siwa", 210));
    n->children.push_back(ConnectedNode("Cairo", 186));
    n->children.push_back(ConnectedNode("Qasr Farafra", 104));

    cityNodes[n->name] = n;

    // Cairo Node
    n = new Node();

    n->name = "Cairo";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Bawiti", 186));
    n->children.push_back(ConnectedNode("Alexandria", 112));
    n->children.push_back(ConnectedNode("Asyut", 198));

    cityNodes[n->name] = n;

    // Asyut Node
    n = new Node();

    n->name = "Asyut";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Cairo", 198));

    cityNodes[n->name] = n;

    // Siwa Node
    n = new Node();

    n->name = "Siwa";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Matruh", 181));
    n->children.push_back(ConnectedNode("Bawiti", 210));

    cityNodes[n->name] = n;

    // Matruh Node
    n = new Node();

    n->name = "Matruh";
    n->isQueued = false;
    n->totalCost = 0;
    n->children.push_back(ConnectedNode("Siwa", 159));
    n->children.push_back(ConnectedNode("Bawiti", 210));

    cityNodes[n->name] = n;

    // Test that the tree works from going to Alexandria to Luxor

    /*
    Node* test = cityNodes["Alexandria"];
    std::cout << "A Test from Getting to Luxor from Alexandria" << std::endl;

    std::cout << test->name << std::endl;
    test = cityNodes[test->children[2].name]; // Go to Nekhel

    std::cout << test->name << std::endl;
    test = cityNodes[test->children[2].name]; // Go to Quseir

    std::cout << test->name << std::endl;
    test = cityNodes[test->children[0].name]; // Go to Sohag

    std::cout << test->name << std::endl;
    test = cityNodes[test->children[1].name]; // Go to Qeua

    std::cout << test->name << std::endl;
    test = cityNodes[test->children[0].name]; // Go to Luxor

    std::cout << test->name << std::endl;

    std::cout << "END TEST" << std::endl;
    */

    // Add Alexandria to the starting set of nodes for GeneralSearch()
    currentNodes.push_back(cityNodes["Alexandria"]);
    currentNodes[0]->isQueued = true;

    // Run the Search Function
    // Argument 0 = map of all nodes
    // Argument 1 = queue of expanded nodes
    // Argument 2 = Goal Node
    GeneralSearch(cityNodes, currentNodes, exploredNodes, cityNodes["Luxor"]);

    // Make sure to deallocate everything on the heap
    std::map<std::string, Node*>::iterator mapIterator = cityNodes.begin();

    for (mapIterator = cityNodes.begin(); mapIterator != cityNodes.end(); ++mapIterator)
    {
        delete mapIterator->second;
    }
    cityNodes.clear();
    currentNodes.clear();

    // Exit

    std::cout << "Exiting..." << std::endl;

    return 0;
}

void GeneralSearch(std::map<std::string, Node*> &cityNodes, std::vector<Node*> &currentNodes, std::vector<Node*> &exploredNodes, Node *goalNode)
{
    while (true)
    {
        // If nothing left to search, then exit
        if (currentNodes.size() == 0)
        {
            std::cerr << "ERROR: Path to Goal not found: " << goalNode->name << std::endl;
            return;
        }

        // Goal Test
        Node* nodeToTest = currentNodes[0];
        currentNodes.erase(currentNodes.begin());

        if (GoalTest(nodeToTest, goalNode))
        {
            // Output the list of cities searched here
            std::cout << "Found GOAL!!!!! -> " << goalNode->name << std::endl;
            std::cout << "Order of cities traversed: " << std::endl;
            for (unsigned int i = 0; i < exploredNodes.size(); i++)
            {
                std::cout << exploredNodes[i]->name;
                if (i != exploredNodes.size() - 1)
                {
                    std::cout << ", ";
                }
                else
                {
                    std::cout << ", " << goalNode->name << std::endl;
                }

            }
            return;
        }

        // Queuing Function
        //EnqueueBFS(cityNodes, currentNodes, nodeToTest); // Breadth First Search (BFS)
        //EnqueueDFS(cityNodes, currentNodes, nodeToTest); // Depth First Search (DFS)
        EnqueueUCS(cityNodes, currentNodes, nodeToTest); // Uniform COst Search (UCS)
        exploredNodes.push_back(nodeToTest);

        /*
        std::cout << std::endl << nodeToTest->name << std::endl;

        // Debug -> Print out contents of currentNodes list
        for (int i = 0; i < currentNodes.size(); i++)
        {
            std::cout << currentNodes[i]->name << " ";
        }
        std::cout << std::endl;
        */
    }
}

void EnqueueBFS(std::map<std::string, Node*> &cityNodes, std::vector<Node*> &currentNodes, Node *nodeToTest)
{
    // Add values from expanded node into a temp vector
    std::vector<std::string> expandedNames;

    for (unsigned int i = 0; i < nodeToTest->children.size(); i++)
    {
        if (!cityNodes[nodeToTest->children[i].name]->isQueued) // Check to see if the node has already been expanded
        {
            expandedNames.push_back(nodeToTest->children[i].name);
        }
    }

    // Sort Them
    std::sort(expandedNames.begin(), expandedNames.end());

    // Add them into the currentNodes Queue
    while (!expandedNames.empty())
    {
        currentNodes.push_back(cityNodes[expandedNames[0]]);
        cityNodes[expandedNames[0]]->isQueued = true;
        expandedNames.erase(expandedNames.begin());
    }
}

void EnqueueDFS(std::map<std::string, Node*> &cityNodes, std::vector<Node*> &currentNodes, Node *nodeToTest)
{
    // Add values from expanded node into a temp vector
    std::vector<std::string> expandedNames;

    for (unsigned int i = 0; i < nodeToTest->children.size(); i++)
    {
        if (!cityNodes[nodeToTest->children[i].name]->isQueued) // Check to see if the node has already been expanded
        {
            expandedNames.push_back(nodeToTest->children[i].name);
        }
    }

    // Sort Them
    std::sort(expandedNames.begin(), expandedNames.end());

    // Add them into the currentNodes Stack in reverse order
    while (!expandedNames.empty())
    {
        currentNodes.insert(currentNodes.begin(), cityNodes[expandedNames[expandedNames.size() - 1]]);
        cityNodes[expandedNames[expandedNames.size() - 1]]->isQueued = true;
        expandedNames.erase(expandedNames.end());
    }
}

void EnqueueUCS(std::map<std::string, Node*> &cityNodes, std::vector<Node*> &currentNodes, Node *nodeToTest)
{
    isUCS = true;
    for (unsigned int i = 0; i < nodeToTest->children.size(); i++)
    {
        if (!cityNodes[nodeToTest->children[i].name]->isQueued) // Check to see if the node has already been expanded
        {
            currentNodes.push_back(cityNodes[nodeToTest->children[i].name]);
            currentNodes[currentNodes.size() - 1]->totalCost = nodeToTest->totalCost + nodeToTest->children[i].cost;
            currentNodes[currentNodes.size() - 1]->isQueued = true;
        }
        // Check where the cost for something to a node is less than another way, and overwrite the more expensive cost
        else if (nodeToTest->totalCost + nodeToTest->children[i].cost < cityNodes[nodeToTest->children[i].name]->totalCost)
        {
            // This is why I like pointers -> I do not need to loop again to find what I need to change
            cityNodes[nodeToTest->children[i].name]->totalCost = nodeToTest->totalCost + nodeToTest->children[i].cost;
        }
    }

    // Sort Them -> First based upon cost, and if they are the same, then by name
    // Refer to functorUCS for the specific comparison used for std::sort()
    std::sort(currentNodes.begin(), currentNodes.end(), functorUCS);
}

bool GoalTest(Node *nodeToTest, Node *goalNode)
{
    if (!isUCS) // If the Test is for BFS or DFS
    {
        if (nodeToTest->name == goalNode->name)
        {
            return true;
        }
    }
    else // The test is for UCS, and it is much different
    {
        if (nodeToTest->name == goalNode->name) // Should I stop on first hit or not?
        {
            std::cout << "Cost to get to GoalNode: " << goalNode->totalCost << std::endl;
            return true;
        }
    }
    return false;
}
