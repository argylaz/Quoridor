#include <stdio.h>
#include "Commands.h"
#include "utilities.h"
#include "pathfinder.h"

/* This is a minimax algorith with A-B pruning
   Maximizing player starts as 1 (true)
   Alpha starts as really small and beta really large */
int minimax(element **A, int N, int *pWW, int *pWB, char *pWinner,int depth, int alpha, int beta,
            int maximizingplayer, int possiblemoves, int *move, node **history, int *hSize) { 
    int i;
    int r,c;    // Child position
    int eval;   //evaluation of current move
    //char op = (p = 'W') ? 'B' : 'W'; // op = minimizing player
    
    // If depth has reached 0 process is over
    if(depth == 0 || *pWinner != '\0'){  // Look into winning condition
        return evaluation(A, N);
    }

    // Process for maximizing player
    if(maximizingplayer){
        int max_eval = -1000000;
        // For each hypothetical child (possible moves)
        for(i = 1; i <= possiblemoves;i++){
            // Find maximizing player's position
            find(A, N, 'W', &r, &c);  // White is the maximizing player

            // Execute and then undo the move so the next minimax call can have the proper board configuration
            execute(A, N, i, r, c, pWW, pWB, 'W', pWinner, history, hSize,0);

            // Maximizingplayer = false (other player's turn)
            eval = minimax(A, N, pWW, pWB, pWinner, depth - 1, alpha, beta, 0, possiblemoves, move, history, hSize);
            max_eval = max(max_eval, eval);

            // Changing max_eval means that a better move was found
            if(max_eval == eval && depth == 3) // We only care about the first level of the hypothetical tree(depth == 3)
                *move = i;
            
            // Undo the action executed earlier so the board returns to its original configuration
            undo(1, A, N, pWW, pWB, pWinner, history, hSize);

            // Prune if needed
            alpha = max(alpha,eval);
            if(beta <= alpha)
                break;
        }
        return max_eval;
    }

    // Process for minimizing player
    else{
        int min_eval = __INT_MAX__;
        for(i = 1; i <= possiblemoves;i++){
            // Find minimizing player's position
            find(A, N, 'B', &r, &c); //Black is the minimizing player

            // Same as above, for the second level of the tree which is the only level of the minimizing player
            execute(A, N, i, r, c, pWW, pWB, 'B', pWinner, history, hSize, 0);

            // Maximizing player = true (other player's turn)
            eval = minimax(A, N, pWW, pWB, pWinner, depth -1, alpha, beta, 1, possiblemoves, move, history, hSize);
            min_eval = min(min_eval, eval);

            // Return to original configuration
            undo(1, A, N, pWW, pWB, pWinner, history, hSize);

            // Prune if needed
            beta = min(beta, eval);
            if(beta <= alpha)
                break;
        }
        return min_eval;
    }
}

/* Evaluate move based on board orientation and differences to the path */
int evaluation(element **A, int N){
    // Evaluating according to the path
    // path(black) > path(white) returns a positive number (white has the advantage)
    // path(black) < path(white) returns a negative number (black has the advantage)
    return pathfinder(A, N, 'B', -1, -1) - pathfinder(A, N, 'W', -1, -1);
}