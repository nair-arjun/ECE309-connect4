# ECE309-connect4
Game Description:
  A game in which 2 players, human or CPU, will engage in the classic game of _Connect Four_.
  The goal is for the player to have their pieces connect 4 times either horizontally, vertically, or diagonally.
  The game ends when a player wins, or when the board is full of pieces.
  When a game ends, the players can opt to play another game or end their session.
  If they choose to play again, they must choose how many humans are playing and they will be assigned new player IDs.

How to Run:
  The game can be run using any kind of C++ compiler.

Unique Features:
  When the player ID reaches 10 (at game 5), the counter for empty space (0) will be doubled to keep the board stabilized according to the number of players.

Known Bugs:
  There is no player ID for 9. As of now this is intended, as implementing 9 coupled with 10 can make it visually difficult to find their pieces among the various 0's.


*Changelog:*
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
