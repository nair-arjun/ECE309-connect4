# ECE309-connect4
Game Description:
  A game in which 2 players, human or CPU, will engage in the classic game of _Connect Four_.
  The goal is for the player to have their pieces connect 4 times either horizontally, vertically, or diagonally.
  The game ends when a player wins, or when the board is full of pieces.
  When a game ends, the players can opt to play another game or end their session.
  If they choose to play again, they must choose how many humans are playing and they will be assigned new player IDs.
  It is possible for a person to play against a computer, or allow a computer to play against another computer.

How to Run:
  The game can be run using any kind of C++ compiler.

Unique Features:
  When the player ID reaches 10 (at game 5), the counter for empty space (0) will be doubled to keep the board stabilized according to the number of players.

Known Bugs:
  There is no player ID for 9. As of now this is intended, as implementing 9 coupled with 10 can make it visually difficult to find their pieces among the various 0's.


*Changelog:*

  Version 1.6:
    ASCII art is displayed when the game is first ran. - asnair2
  
  Version 1.5:
    Added a delay between CPU inputs for CPU v CPU play. This allows for time for the player to see each move that each CPU makes until a winner is decided. - zainj 

  Version 1.4:
    Added CPU v CPU inherited class that allows two CPU's to play each other. Implemented CPU v CPU selection into main function to allow user to select 0 human mode
    - asnair2
    
  Version 1.3:
    Added Human v CPU inherited class that allows a player to play against a CPU. This class begins to run if the player says that 1 human is playing. As of now, the CPU intelligence is very primitive. - zainj & gittc

  Version 1.2:
    A new version of the game where the player is allowed to call for a number of humans playing (not implemented yet) and to ask to play again (implemented).
    When they play again, they will be assigned a new player ID.
    Ex) Game 1 will have players 1 & 2. Game 2 will have players 3 & 4. This will continue forever, with the board changing to accomodate the number of digits at game 5.
    - gittc
  
  Version 1.1:
    The coding is granted comments and optimizations. Quality of life changes for the user interface.
    - gittc

  Version 1.0:
    The game is created, allowing for 2 players to play the game of Connect 4.
    It is a static 7x6 grid, which waits for 2 players to provide inputs, and then the program ceases running once a winner is decided.
    - zainj
