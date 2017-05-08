# AI-Reversi
AI Bot for Reversi (Othello) game

Reversi is a strategy board game for two players, played on an 8×8 uncheckered board. There are sixty-four identical game pieces (disks) which are light on one side and dark on the other. Players take turns placing disks on the board with their assigned color facing up. 

# Choice of Heuristic
Heuristic is a function of three parameters.
        Heuristic Value = F (Cell Utility Value, Disk Parity, Mobility)  

1. Cell Utility Value: Every cell (square) is assigned a value depending upon the stability of the disks placed on that square. For example, Corners are given the highest value because once captured, they cannot be flanked by the opponent. The cells adjacent to corners have negative values as they can be flanked easily if the other player occupies corner.
  
2. Disk Parity: The move which increases the number of disks of the player on the board by a greater amount is considered a better move. So, this parameter of heuristics takes into account the relative difference in number of disks occupied by max player and the min player after a move.  
        Disk Parity =   (Max Player Disks - Min Player Disks) / (Max Player Disks + Min Player Disks)  
        
3. Mobility: It is good to have greater number of possible moves so that the player could choose the best move among them. Also, it is good to play a move which decreases other player’s moves. Thus a move should restrict the opponent’s mobility and increase one’s own mobility. So this parameter finds the relative difference between the number of possible moves for the max and the min players.  
        Mobility =  (Max Player Moves - Min Player Moves) / (Max Player Moves + Min Player Moves) 
