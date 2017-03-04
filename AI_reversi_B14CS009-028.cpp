#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <ctime>
using namespace std;

//	8X8 uncheckered board
//	64 identical discs
//	Player is assigned X
// 	AI is assigned O
class Board
{
	public:
	int grid[8][8]=	{};
	Board()
	{
        //Starting positions in Diamond shape
		grid[3][3]=-1;
		grid[3][4]=1;
		grid[4][3]=1;
		grid[4][4]=-1;
	}

	Board(const Board &b) // Copy constructor
	{
		int i=0,j=0;
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
				grid[i][j]=b.grid[i][j];
		}
	}

	std::vector<int> search_legal_moves(int color)      //Will return all the possible moves for the Player/AI for a particular board state
	{
		std::vector<int> legal_moves;
		int i,j,k=0,l=0,val=0;
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(grid[i][j]!=0)
					continue;
				if(j>0&&grid[i][j-1]==-color)
				{
					k=j-2;
					while(k>=0&&grid[i][k]==-color)
						k--;
					if(k>=0&&grid[i][k]!=0)
					{
						legal_moves.push_back(i*8+j);
						continue;
					}
				}
				if(j<7&&grid[i][j+1]==-color)
				{
					k=j+2;
					while(k<=7&&grid[i][k]==-color)
						k++;
					if(k<=7&&grid[i][k]!=0)
					{
						legal_moves.push_back(i*8+j);
						continue;
					}
				}
				if(i>0&&grid[i-1][j]==-color)
				{
					k=i-2;
					while(k>=0&&grid[k][j]==-color)
						k--;
					if(k>=0&&grid[k][j]!=0)
					{
						legal_moves.push_back(i*8+j);
						continue;
					}
				}
				if(i<7&&grid[i+1][j]==-color)
				{
					k=i+2;
					while(k<=7&&grid[k][j]==-color)
						k++;
					if(k<=7&&grid[k][j]!=0)
					{
						legal_moves.push_back(i*8+j);
						continue;
					}
				}
				if(j<7&&i<7&&grid[i+1][j+1]==-color)
				{
					k=i+2;
					l=j+2;
					while(k<=7&&l<=7&&grid[k][l]==-color)
					{
						k++;
						l++;
					}
					if(k<=7&&l<=7&&grid[k][l]!=0)
					{
						legal_moves.push_back(i*8+j);
						continue;
					}
				}
				if(j>0&&i>0&&grid[i-1][j-1]==-color)
				{
					k=i-2;
					l=j-2;
					while(k>=0&&l>=0&&grid[k][l]==-color)
					{
						k--;
						l--;
					}
					if(k>=0&&l>=0&&grid[k][l]!=0)
					{
						legal_moves.push_back(i*8+j);
						continue;
					}
				}
				if(j<7&&i>0&&grid[i-1][j+1]==-color)
				{
					k=i-2;
					l=j+2;
					while(k>=0&&l<=7&&grid[k][l]==-color)
					{
						k--;
						l++;
					}
					if(k>=0&&l<=7&&grid[k][l]!=0)
					{
						legal_moves.push_back(i*8+j);
						continue;
					}
				}
				if(j>0&&i<7&&grid[i+1][j-1]==-color)
				{
					k=i+2;
					l=j-2;
					while(k<=7&&l>=0&&grid[k][l]==-color)
					{
						k++;
						l--;
					}
					if(k<=7&&l>=0&&grid[k][l]!=0)
					{
						legal_moves.push_back(i*8+j);
						continue;
					}
				}
			}
		}
		return legal_moves;
	}

	int play_move(int color,int x,int y)    //Check if the move is valid or not and will apply the move to the board
	{
		int flag2=0;
		if(x<0||x>7||y<0||y>7){
			cout<<"Inputs should lie between 1-8\n";
			flag2=1;
			return flag2;
		}
		if(grid[x][y]!=0){
			cout<<"Disc is already placed there.\n";
			flag2=1;
			return flag2;
		}
		bool flag=false;
		int i=0,j=0;
		if(x>0&&grid[x-1][y]==-color)
		{
			i=x-1;
			while(i>=0&&grid[i][y]==-color)
				i--;
			if(i>=0&&grid[i][y]!=0)
			{
				flag=true;
				int temp1=x-1;
				while(temp1>i)
					grid[temp1--][y]=color;
			}
		}
		if(x<7&&grid[x+1][y]==-color)
		{
			i=x+1;
			while(i<=7&&grid[i][y]==-color)
				i++;
			if(i<=7&&grid[i][y]!=0)
			{
				flag=true;
				int temp1=x+1;
				while(temp1<i)
					grid[temp1++][y]=color;
			}
		}
		if(y>0&&grid[x][y-1]==-color)
		{
			j=y-1;
			while(j>=0&&grid[x][j]==-color)
				j--;
			if(j>=0&&grid[x][j]!=0)
			{
				flag=true;
				int temp2=y-1;
				while(temp2>j)
					grid[x][temp2--]=color;
			}
		}
		if(y<7&&grid[x][y+1]==-color)
		{
			j=y+1;
			while(j<=7&&grid[x][j]==-color)
				j++;
			if(j<=7&&grid[x][j]!=0)
			{
				flag=true;
				int temp2=y+1;
				while(temp2<j)
					grid[x][temp2++]=color;
			}
		}
		if(x<7&&y<7&&grid[x+1][y+1]==-color)
		{
			i=x+1;
			j=y+1;
			while(i<=7&&j<=7&&grid[i][j]==-color)
			{
				i++;
				j++;
			}
			if(i<=7&&j<=7&&grid[i][j]!=0)
			{
				flag=true;
				int temp1=x+1,temp2=y+1;
				while(temp1<i)
					grid[temp1++][temp2++]=color;
			}
		}
		if(x>0&&y>0&&grid[x-1][y-1]==-color)
		{
			i=x-1;
			j=y-1;
			while(i>=0&&j>=0&&grid[i][j]==-color)
			{
				i--;
				j--;
			}
			if(i>=0&&j>=0&&grid[i][j]!=0)
			{
				flag=true;
				int temp1=x-1,temp2=y-1;
				while(temp1>i)
					grid[temp1--][temp2--]=color;
			}
		}
		if(x<7&&y>0&&grid[x+1][y-1]==-color)
		{
			i=x+1;
			j=y-1;
			while(i<=7&&j>=0&&grid[i][j]==-color)
			{
				i++;
				j--;
			}
			if(i<=7&&j>=0&&grid[i][j]!=0)
			{
				flag=true;
				int temp1=x+1,temp2=y-1;
				while(temp1<i)
					grid[temp1++][temp2--]=color;
			}
		}
		if(x>0&&y<7&&grid[x-1][y+1]==-color)
		{
			i=x-1;
			j=y+1;
			while(i>=0&&j<=7&&grid[i][j]==-color)
			{
				i--;
				j++;
			}
			if(i>=0&&j<=7&&grid[i][j]!=0)
			{
				flag=true;
				int temp1=x-1,temp2=y+1;
				while(temp1>i)
					grid[temp1--][temp2++]=color;
			}
		}
		if(!flag){
			cout<<"Invalid square to play a move\n";
			flag2=1;
			return flag2;
		}
		grid[x][y]=color;
		return flag2;
	}

	void displayResult()    // Final Result
	{
		int player=0;
		int comp=0;
		int i=0,j=0;
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(grid[i][j]==1)
					comp++;
				else if(grid[i][j]==-1)
					player++;
			}
		}
		cout<<"Computer: "<<comp;
		cout<<"\tPlayer: "<<player;
		if(comp>player)
			cout<<"\nComputer wins!\n";
		else if(player>comp)
			cout<<"\nPLayer wins!\n";
		else
			cout<<"\nDraw!\n";
	}


	void displayBoard ()    // Display the current state of board
	{
	    cout<<'\n';
		string str="";
		str=str+"    1 2 3 4 5 6 7 8\n\n";
		for(int i=0;i<8;i++)
		{
		    char c=i+'1';
		    str=str+c+"   ";
			for(int j=0;j<8;j++)
			{
				switch(grid[i][j])
				{
					case 0:
					str=str+". ";
					break;
					case 1:
					str=str+"O ";
					break;
					case -1:
					str=str+"X ";
					break;
					default:
					cout<< "Hmmm...Corrupted maybe!!\n";
				}
			}
			str=str+'\n';
		}
		cout<< str<<'\n';
	}
};

//Class to implement Minimax function along with alpha beta pruning
//Heuristic value of a particular state of board depends on three factors
//No. of pieces of a particular player
//No. of moves available for the player
//Positions which the player has acquired till now
class AI
{
	public:
	int depth;

	AI()
	{
	    // Hardness of game depends on its depth
	    // Depth = 8-10 --> Hard
	    // Depth = 5-7  --> Medium
	    // Depth = 3-4  --> Easy
		depth=8;
	}

	int alpha_beta_pruning(Board board,vector<int> moves)
	{
		Board temp_Board;
		int i,l=moves.size();
		int max=INT_MIN,val=0;
		int finalMove=moves[0];
		int alpha=INT_MIN,beta=INT_MAX;
		for(i=0;i<l;i++)
		{
			temp_Board=Board(board);
			int f=temp_Board.play_move(1,moves[i]/8,moves[i]%8);
			val=min_func(temp_Board,1,alpha,beta);
			if(val>max)
			{
				max=val;
				finalMove=moves[i];
			}
			if(max>=beta)
				return finalMove;
			alpha=alpha>max?alpha:max;
		}
		return finalMove;
	}

	int min_func(Board board,int d,int alpha,int beta)
	{
		if(d==depth)
			return heuristic_func(board);
		Board temp_Board;
		vector<int> moves=board.search_legal_moves(-1);
		if(moves.size()==0)
			return max_func(board,d+1,alpha,beta);
		int i,l=moves.size();
		int min=INT_MAX,val=0;
		for(i=0;i<l;i++)
		{
			temp_Board=Board(board);
			int f=temp_Board.play_move(-1,moves[i]/8,moves[i]%8);
			val=max_func(temp_Board,d+1,alpha,beta);
			if(val<min)
				min=val;
			if(min<=alpha)
				return min;
			beta=beta<min?beta:min;
		}
		return min;
	}

	int max_func(Board board,int d,int alpha,int beta)
	{
		if(d==depth)
			return heuristic_func(board);
		Board temp_Board;
		vector<int> moves=board.search_legal_moves(1);
		if(moves.size()==0)
			return min_func(board,d+1,alpha,beta);
		int i,l=moves.size();
		int max=INT_MIN,val=0;
		for(i=0;i<l;i++)
		{
			temp_Board=Board(board);
			temp_Board.play_move(1,moves[i]/8,moves[i]%8);
			val=min_func(temp_Board,d+1,alpha,beta);
			if(val>max)
				max=val;
			if(max>=beta)
				return max;
			alpha=alpha>max?alpha:max;
		}
		return max;
	}

	int heuristic_func(Board board)		//heuristic function
	{
		int i=0,j=0;
		int count1=0,count2=0;
		int v=0,p=0,f=0;

        // 8x8 position matrix
        // Corner position has the most value
        // Positions closest to corner are not suitable

        int cellUtility[8][8] = { {25, -5, 14, 10, 10, 14, -5, 25},
                        {-5, -7, -4, 1, 1, -4, -7, -5},
                        {14, -4, 3, 2, 2, 3, -4, 14},
                        {10, 1, 2, -6, -6, 2, 1, 10},
                        {10, 1, 2, -6, -6, 2, 1, 10},
                        {14, -4, 3, 2, 2, 3, -4, 14},
                        {-5, -7, -4, 1, 1, -4, -7, -5},
                        {25, -5, 14, 10, 10, 14, -5, 25}
                      };
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(board.grid[i][j]==1)
					{
					    count1++;
                        v+=cellUtility[i][j];
					}
				if(board.grid[i][j]==-1)
                    {
                        count2++;
                        v-=cellUtility[i][j];
                    }
			}
		}

		// p signifies the number of pieces of a particular player on the board
		// f signifies the number of moves available for a particular player
		// v signifies the positions which the player has acquired till now
		p=(count1-count2)/(count1+count2);
		vector<int> m1=board.search_legal_moves(1);
		vector<int> m2=board.search_legal_moves(-1);
		if(m1.size()+m2.size()!=0)
            f=(m1.size()-m2.size())/(m1.size()+m2.size());
		//p=(count1-count2)/(count1+count2);
		return v+50*p+100*f;//(count1-count2)/(count1+count2);
	}
};

int main()
{
    cout<< "\t\t\t\t|| Reversi ||\n\n";
    cout<< "\t\t\tX-Player\tO-Computer\n";
	Board board;
	AI ai;
	board.displayBoard();
	int i=0;
	int a,b,value;
	bool isPossiblePlayer = false, isPossibleAI = false;
	vector<int> possibleMoves;
	while(i<61)      // 64 is the maximum number of moves for Reversi and 4 turns have already been played
	{
		clock_t begin = clock();
		//whoseMove=0;
		possibleMoves=board.search_legal_moves(-1);     // To check if the user has any valid move or not
                                                        // User is given the first turn
		if(possibleMoves.size()>0)
		{
			cout<<"Your move\n";
				cin>>a>>b;
				int f=board.play_move(-1,a-1,b-1);
				if(f==1)
					continue;
			i++;
			clock_t end = clock();
			 double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			 cout<<elapsed_secs<<" secs"<<'\n';
			board.displayBoard();
		}


		else
			isPossiblePlayer = true;
		possibleMoves=board.search_legal_moves(1);      // To check if the AI has any valid move or not
		clock_t begin2 = clock();

		if(possibleMoves.size()>0)
		{
			cout<<"Computer's move\n";
			value=ai.alpha_beta_pruning(board,possibleMoves);
			a=value/8;
			b=value%8;
			cout<<a+1<<" "<<b+1<<'\n';
			int f=board.play_move(1,a,b);
			i++;
			clock_t end2 = clock();
			double elapsed_secs2 = double(end2 - begin2) / CLOCKS_PER_SEC;
			 cout<<elapsed_secs2<<" secs"<<'\n';
			board.displayBoard();
		}
		else
			isPossibleAI = true;    // To check if any of the players has any valid move
                       		// If not then game ends
		if(isPossibleAI && isPossiblePlayer)
		{
			board.displayResult();
			break;
		}
	}
}
