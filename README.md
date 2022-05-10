# Terminal implemented Quoridor with AI based on minimax with A-B pruning

Wiki: https://en.wikipedia.org/wiki/Quoridor


# *Default settings*:
  By default quoridor is played on a 9x9 game board and each player starts with 10 walls. However, the game can also be played in different boardsizes with a different number of starting walls which can be set at the start of the game with the commands below.

# *Game rules*:

 1)Each player is represented by a pawn (black or white) which begins at the center space of his baseline.
 2)The black Player starts first, then players alternate turn. Each player in turn, chooses to move his pawn or to put up one of his fences. When he has run out of fences, the player must move his pawn.
 3)The pawns are moved one square at a time, horizontally or vertically, forwards or backwards. The pawns must get around the fences. When two pawns face each other on neighboring squares which are not separated by a fence, the player whose turn it is can jump the opponent's pawn (and place himself behind him), thus advancing an extra square. If there is a fence behind the said pawn, or the square behind him is out of the board, the player can place his pawn to the left or the right of the other pawn.
 4)Walls are flat two-cell-wide pieces which can be placed between 2 sets of 2 squares. The fences can be used to facilitate the player's progress or to impede that of the opponent, however, an access to the goal line must always be left open.
 5)The first player who reaches any of the squares opposite his baseline is the winner.

# *Usage/Commands*:
* **playmove** player position <br/>

  example: playmove white(OR w) e2 - moves white to E2
  
* **playwall** player position orientation <br/>

  examples:<br/>
  playwall black(OR b) a3 horizontal(OR h) - black places a horizontal wall starting at A3 <br/>
  playwall white(OR w) b4 vertical(OR v) - white places a vertical wall starting at B4 <br/>
  
* **genmove** player <br/>

  example: genmove white - engine plays a move for the given player.
 
* **showboard** <br/>

  Draw the board with current configuration.
  
* **quit** <br/>

  Exit the game.
  
* **undo** n <br/>

  The game goes n moves back.
  
* **boardsize** n <br/>

  The board size is changed to n (n must be odd and not bigger than 25).
  
* **walls** n <br/>

  The number of walls for each player is changed to n.
  
* **list_commands** <br/>

  List all commands


# *AI engine*:
  The AI engine uses minimax with A-B pruning and the depth is dependent on the current boardsize. The engine checks and executes the given move and undoes it before moving to the next branch of this depth level. When the depth reaches zero the engine evaluates the current boardsize by evaluating both players shortest paths to their equivalent winning row. The egnine considere's positive evaluations to benefit white player and negative evaluations to benefit black.


# *Disclaimers*:
  This project was a bit rushed because of the deadline of the assignement.
  A lot of changes could have been made in order to organize the poject better. For example some functions could have been more modular, other modifications could have made the program faster, and more economic in terms of memory, the evaluation of the AI engine could check more parameters for better results and the engine itself could simulate themoves instead of executing them and continually checking if they are legal.
  Despite all these the two of us did our best given the short time we had and the fact that this was our first project of this magnitude.

Assignment 4, Semester 1, Department of Informatics and Telecommunications - UoA (2022)
Project made by Argirios Lazaridis (sdi2100083) and Konstantinos Dimitropoulos (sdi2100033)
