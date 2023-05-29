# Project-Chess
This project is CUHK CSCI1120 final project which done on 13 Dec 2020

# Introduction
The objective of this project is to let you apply the OOP concepts learned, 
including inheritance and polymorphism, to programming through developing a game application – Chess – in C++.

Figure 1 shows the initial board configuration while Table 1 shows the label and score if each piece.

![Alt text](/README/Configuration.png "Figure 1 and Table 1")

All the rules are same as the Chess. Figure shows the Valid moves of each piece

![Alt text](/README/Valid_Move.png "Figure 2")

# Game Flow
The main() function in main.cpp creates a Game object and calls its run() method to start a chess game. The Game() constructor accepts a game mode parameter which can be one of the following: 

• Value 1 means “Human vs. Human”, i.e. two human players enter moves via console; 

• Value 2 means “Human vs. Machine”, i.e. one human player enters moves via console and the opponent player is the computer (which makes random moves on the game board); 

• Value 3 means “Machine vs. Machine”, two computer players make random moves in turns without human attention. 

When the Game object is being created, the constructor will create two Player objects of type (Human / Machine) according to the above mode setting, set game state as RUNNING (0) and create the Board object. The Board constructor will call Board::configure() method to set up the initial game board by filling the cells array with pointers to King, Queen, Bishop, … objects that are beingcreated in the method. The created pieces will be added to each player's list of pieces as well.

The Game object’s run() is the main loop of the program, which repeats calling the current player’s makeMove(board) function and printing the board. The current player is flipped in each iteration. For a Human player, its makeMove() will prompt the user for two cell addresses, e.g. A7 B8, with the former denoting the source cell and the latter denoting the destination cell on the board. These text based cell addresses will be translated to array indexes to access the Board object’s cells array.

For a Machine player, its makeMove() will make a random but valid move. To do so, first, pick a piecerandomly from the player's pieces vector and get its position (y1, x1). (This part has been done for you in the provided source machine.cpp). Then, generate a random target position (y2, x2) and try moving the piece from (y1, x1) to (y2, x2). If the move is invalid, repeat these steps until a valid move is resulted.

# Assumptions
• The board size is always 8x8. Still, we use two global constants H and W to represent the board’s height (number of rows) and width (number of columns). They are both set to 8.

• We assume that cell address inputs always follow the format of one letter (A-Z or a-z) plus one integer (1-26). Lowercase inputs like "a1", "h10", etc. will be accepted as normal. Except for "Z0" (case-sensitive) which is treated as a sentinel for game stop, you need NOT handle weird inputslike "AA1", "A01", "abc", "A3.14", "#a2", … for cell addresses and inputs like "-1", "6.28", "#$@", … for the number of pits. The behavior upon receiving these is unspecified, probably running into forever loop or program  crash.
