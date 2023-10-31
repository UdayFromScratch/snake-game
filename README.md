# snake-game
Snake game in C
To run this C code, you will need a C compiler. If you are using a Linux or MacOS system, you likely already have the gcc compiler installed. If you are on Windows, you might need to install a software like MinGW which provides the necessary tools to compile and run C programs.

Here are the steps to compile and run the program:

Save the code: Copy the code into a text file and save it with a .c extension, for example snake_game.c.

Compile the code: Open a terminal window, navigate to the directory where you saved the file and type gcc snake_game.c -o snake_game. This will compile your C code into an executable file named snake_game.

Run the program: In the terminal, type ./snake_game to run the program.

Please note that this game runs in a terminal window and uses WASD keys for navigation (W for up, A for left, S for down, D for right). Press ‘x’ to quit the game.

If you encounter any errors during compilation or execution, they are likely due to differences in development environments or missing libraries. The provided code uses functions like _kbhit() and _getch() which are part of conio.h, and this library is not available on some systems (like Linux and MacOS). You might need to modify the code or install additional libraries depending on your system.
