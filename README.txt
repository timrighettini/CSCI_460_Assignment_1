Name:  Tim Righettini
USC ID: 9445525333

-- CSCI 460 Assignment #1 README --

Hello,

This document will go over three key points: The design/structure behind the program, instructions on compilation, and any issues that might come up when running the program.

----- 1. Program Structure & Design -----

Essentially, the program works as described in the assignment doc.  First, the tree is set up in main(), according to the specifications of the Egyptian Map we were given.  After that, the GeneralSearch() function is called after Alexandria is placed into the currentNodes queue.  

As requested, only line you have to change in the doc is the queuing function call in the General Search Loop.  These there methods are called:

EnqueueBFS(...); // Breadth First Search (BFS)
EnqueueDFS(...); // Depth First Search (DFS)
EnqueueUCS(...); // Uniform COst Search (UCS)

Comment the appropriate functions and everything should work accordingly in GeneralSearch().  Of course, only one of these functions should be run at any given time, or else they will get in each other's way (and that will not be very helpful, will it?).

Besides for the commenting (which you already know about, of course), there is nothing out of the ordinary to be wary of.

----- 2. Instructions for Compilation/Execution -----

Go on aludra (after copying main.cpp to it) and then run the following commands:

g++ -g -o assign1 main.cpp

./assign1

This will compile the file and run it, assuming all commenting for the Queuing Functions is completed accordingly.

Have a nice day.

Tim
Bloomthegame.com