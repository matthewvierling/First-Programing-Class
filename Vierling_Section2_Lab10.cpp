// 3D Tic Tac Toe
// Matthew Vierling
// 11/5/2015	
// Lab #10
// Section 2                                              

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class TTTBoard{//************************************************************************************ class
	private:
		
	
	public:
		
		int board[3][3];//row, column
		
		TTTBoard();//constructor 
		
		void putX(int[][3], int, int);//row, column
		void putO(int[][3], int, int);
		bool spotOpen(int [][3],int, int);
		void showGame(int [][3]);
		bool isWin();
		bool isDraw();
		
};//class 

TTTBoard::TTTBoard(){//****************************************************************************** constructor
	for(int c=0;c<3;c++){
		for (int b=0;b<3; b++){
			board[c][b]=0;
		}
	}
}//constructor assigns zero to all spost in my 2d int array
	

void TTTBoard::putX(int b[][3], int row, int col){//************************************************************ put X

	b[row][col]=5;
	
}//put X

void TTTBoard::putO(int b[][3],int row, int col){//************************************************************ put O
	
	b[row][col]=8;
	
}//put O

bool TTTBoard::spotOpen(int b[][3],int r, int c){//************************************************************ spotOpen
	
	if(b[r][c]!=0){
		return false;
	}
	else{
		return true;
	}
}

bool TTTBoard::isWin(){//*************************************************************************** need to make these -- isWin
	
	int i,flag;
	flag=0;
	
	for(i=0;i<3;i++){//***********************************************************************--row check
		if((board[i][0]+board[i][1]+board[i][2])==15||(board[i][0]+board[i][1]+board[i][2])==24){
			flag=1;
		}
	}
	
	for(i=0;i<3;i++){//***********************************************************************--column check
		if((board[0][i]+board[1][i]+board[2][i])==15||(board[0][i]+board[1][i]+board[2][i])==24){
			flag=1;
		}
	}
	
	if((board[0][0]+board[1][1]+board[2][2])==15||(board[0][0]+board[1][1]+board[2][2])==24){//**-- top/left->bottom/right check
		flag=1;
	}
	
	if((board[0][2]+board[1][1]+board[2][0])==15||(board[0][2]+board[1][1]+board[2][0])==24){//**-- top/right->bottom/left check
		flag=1;
	}
	
	if(flag==1){
		return true;
	}
	else{
		return false;
	}
}

bool TTTBoard::isDraw(){//**************************************************************************  isDraw
	
	int i,j,flag;
	flag=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==0){
				flag=1;
			}
		}
	}
	
	if(flag==1){
		return false;
	}
	else{
		return true;
	}
}



void TTTBoard::showGame(int b[][3]){//************************************************************************ showGame

	int i,j;
	int dboard[3][3];
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(b[i][j]==5){
				dboard[i][j]='X';
			}
			else if(b[i][j]==8){
				dboard[i][j]='O';
			}
			else{
				dboard[i][j]=' ';
			}
		}
	}
	
	cout<<"     1   2   3\n"<<endl;
	cout<<" 1   "<<(char)dboard[0][0]<<" | "<<(char)dboard[0][1]<<" | "<<(char)dboard[0][2]<<endl;
	cout<<"    -----------"<<endl;
	cout<<" 2   "<<(char)dboard[1][0]<<" | "<<(char)dboard[1][1]<<" | "<<(char)dboard[1][2]<<endl;
	cout<<"    -----------"<<endl;
	cout<<" 3   "<<(char)dboard[2][0]<<" | "<<(char)dboard[2][1]<<" | "<<(char)dboard[2][2]<<endl;
	
	
}

class TDBoard: public TTTBoard{//*******************************************************************************Derived Class for 3D game
	
	public:
		
	int board1[3][3];
	int board2[3][3];
	
	TDBoard(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				board1[i][j]=0;
				board2[i][j]=0;
			}
		}
	}	
	void playergo();
	void computergo();
	void show3dgame();
	bool gameover();
	void finalgamecount();
	
	
};

void TDBoard::playergo(){//************************************************************************player go of 3d game
	
	int brd,row,col,flag;
	flag=0;
	
	while(flag==0){
		cout<<"Enter board number, row then column seperated by a space here: ";
		cin>>brd>>row>>col;
		brd=brd-1;
		row=row-1;
		col=col-1;
		if((brd>2||brd<0)||(row>2||row<0)||(col>2||col<0)){
			cout<<"\nOut of the range of the board. Try again."<<endl;
		}
		else{
			switch(brd){
				case 0:
					if(spotOpen(board,row,col)){
						TDBoard::putX(board,row,col);
						flag=1;
					}
					else{
						cout<<"\n Spot is already filled. Try again."<<endl;
					}
					break;
				case 1:
					if(spotOpen(board1,row,col)){
						putX(board1,row,col);
						flag=1;
					}
					else{
						cout<<"\n Spot is already filled. Try again."<<endl;
					}
					break;
				case 2:
					if(spotOpen(board2,row,col)){
						putX(board2,row,col);
						flag=1;
					}
					else{
						cout<<"\n Spot is already filled. Try again."<<endl;
					}
					break;
				default:
					cout<<"\n Spot is already filled. Try again."<<endl;
					break;
			}
		}	
	}//gets user input only if available spot.---while flag
	
}//player go

void TDBoard::computergo(){//***************************************************************************computer go for 3d game
	
	int brd,row,col,flag;
	flag=0;
			
 		while(flag==0){
			brd=rand()%3;
			row=rand()%3;
			col=rand()%3;
			
			switch (brd){
				case 0:
					if(spotOpen(board, row, col)){
						putO(board,row,col);
						flag=1;
						break;
					}
					else
						break;
				case 1:
					if(spotOpen(board1, row, col)){
						putO(board1,row,col);
						flag=1;
						break;
					}
					else
						break;
				case 2:
					if(spotOpen(board2, row, col)){
						putO(board2,row,col);
						flag=1;
						break;
					}
					else
						break;		
			}//end switch
		}//end while loop
}// computer go

void TDBoard::show3dgame(){//***************************************************************************show 3d game
	
	cout<<"Board 1"<<endl;
	showGame(board);
	cout<<"Board 2"<<endl;
	showGame(board1);
	cout<<"Board 3"<<endl;
	showGame(board2);
	
}

bool TDBoard::gameover(){//*************************************************************************game over 3d game
	
	int flag=0;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(spotOpen(board,i,j)){
				flag++;
			}
			if(spotOpen(board1,i,j)){
				flag++;
			}
			if(spotOpen(board2,i,j)){
				flag++;
			}
		}
	}//end loops
	
	if(flag==0){
		return true;
	}
	else{
		return false;
	}
}//gameover

void TDBoard::finalgamecount(){//************************************************************************ final game check for 3d game
	
	int player=0;
	int computer=0;
	
	//single board checks
	for(int i=0;i<3;i++){
		//rows&columns
		//board
		if((board[i][0]+board[i][1]+board[i][2])==15){
			player++;
		}
		if((board[0][i]+board[1][i]+board[2][i])==15){
			player++;
		}
		if((board[i][0]+board[i][1]+board[i][2])==24){
			computer++;
		}
		if((board[0][i]+board[1][i]+board[2][i])==24){
			computer++;
		}
		//board1
		if((board1[i][0]+board1[i][1]+board1[i][2])==15){
			player++;
		}
		if((board1[0][i]+board1[1][i]+board1[2][i])==15){
			player++;
		}
		if((board1[i][0]+board1[i][1]+board1[i][2])==24){
			computer++;
		}
		if((board1[0][i]+board1[1][i]+board1[2][i])==24){
			computer++;
		}
		//board2
		if((board2[i][0]+board2[i][1]+board2[i][2])==15){
			player++;
		}
		if((board2[0][i]+board2[1][i]+board2[2][i])==15){
			player++;
		}
		if((board2[i][0]+board2[i][1]+board2[i][2])==24){
			computer++;
		}
		if((board2[0][i]+board2[1][i]+board2[2][i])==24){
			computer++;
		}
	}
	
	//top/left->bottom/right
	//board
	if((board[0][0]+board[1][1]+board[2][2])==15){
		player++;
	}
	if((board[0][0]+board[1][1]+board[2][2])==24){
		computer++;
	}
	//board1
	if((board1[0][0]+board1[1][1]+board1[2][2])==15){
		player++;
	}
	if((board1[0][0]+board1[1][1]+board1[2][2])==24){
		computer++;
	}	
	//board2
	if((board2[0][0]+board2[1][1]+board2[2][2])==15){
		player++;
	}
	if((board2[0][0]+board2[1][1]+board2[2][2])==24){
		computer++;
	}
	
	//top/right->bottom/left
	//board
	if((board[0][2]+board[1][1]+board[2][0])==15){
		player++;
	}
	if((board[0][2]+board[1][1]+board[2][0])==24){
		computer++;
	}
	//board1
	if((board1[0][2]+board1[1][1]+board1[2][0])==15){
		player++;
	}
	if((board1[0][2]+board1[1][1]+board1[2][0])==24){
		computer++;
	}
	//board2
	if((board2[0][2]+board2[1][1]+board2[2][0])==15){
		player++;
	}
	if((board2[0][2]+board2[1][1]+board2[2][0])==24){
		computer++;
	}
	
	//multi board checks
	//rows
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if((board[i][j]+board1[i][j]+board2[i][j])==15){
				player++;
			}
			if((board[i][j]+board1[i][j]+board2[i][j])==24){
				computer++;
			}
		}
	}
	
	//diagonals
	for(int i=0;i<3;i++){
		if((board[0][i]+board1[1][i]+board2[2][i])==15){
			player++;
		}
		if((board[0][i]+board1[1][i]+board2[2][i])==24){
			computer++;
		}
		if((board[2][i]+board1[1][i]+board2[0][i])==15){
			player++;
		}
		if((board[2][i]+board1[1][i]+board2[0][i])==24){
			computer++;
		}
	}
	
	if((board[0][0]+board1[1][1]+board2[2][2])==15){
		player++;
	}
	if((board[0][0]+board1[1][1]+board2[2][2])==24){
		computer++;
	}
	if((board[0][2]+board1[1][1]+board2[2][0])==15){
		player++;
	}
	if((board[0][2]+board1[1][1]+board2[2][0])==24){
		computer++;
	}
	if((board[2][0]+board1[1][1]+board2[0][2])==15){
		player++;
	}
	if((board[2][0]+board1[1][1]+board2[0][2])==24){
		computer++;
	}
	if((board[2][2]+board1[1][1]+board2[0][0])==15){
		player++;
	}
	if((board[2][2]+board1[1][1]+board2[0][0])==24){
		computer++;
	}
	
	//final output
	cout<<"\nYou scored "<<player<<" and the computer scored "<<computer<<endl;
	if(player==computer){
		cout<<"\nIt's a draw. Good Game!"<<endl;
	}
	else if(player>computer){
		cout<<"\nGreat Game!!! You won!"<<endl;
	}
	else{
		cout<<"\nSorry you lost to a mindless bot. Try again."<<endl;
	}
}

int main (void){//********************************************************************************** main function.
	
	TDBoard Game;
	int player, gameflag;
	srand(time(0));
	player=rand()%2;
	gameflag=0;
	int flag=0;
	
	if(player==0){//******************************************************************************** player goes first.
		cout<<"You go first"<<endl;
		while(gameflag==0){
			
			cout<<"Your turn"<<endl;
			Game.show3dgame();
			Game.playergo();
			
			system("CLS");
			
			Game.show3dgame();
			if(Game.gameover()){
				flag=1;
				break;
			}
			else{
				cout<<"Computer's turn now."<<endl;
				
				system("PAUSE");
				system("CLS");
			}
			
			Game.computergo();
			
			if(Game.gameover()){
				flag=1;
				break;
			}
			
		}//while loop for the game (player first)
	}
	else{//****************************************************************************************** computer goes first.
		cout<<"Computer goes first\n";
		while(gameflag==0){
			
			cout<<"Computer's turn"<<endl;
			Game.show3dgame();
			
			system("PAUSE");
			system("CLS");
			
			Game.computergo();
			if(Game.gameover()){
				flag=1;
				break;
			}
			else{
				cout<<"Your turn."<<endl;
				Game.show3dgame();
			}
			Game.playergo();
			
			system("CLS");
			
			if(Game.gameover()){
				flag=1;
				break;
			}
						
		}//while loop for the game (comp first)
	}
	
	system("CLS");
	Game.show3dgame();
	Game.finalgamecount();
	
	return 0;
}





