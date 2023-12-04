#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

string first_player, second_player;
int x=0, y=0, z=0;
int a=0, b=0, c=0;

void show_menu();
void show_stats();
void show_board(char[][3]);
bool checking_winner(char[][3], char);
void player_moves(char[][3], char);
void computer_player_moves(char[][3], char);

int main()
{
	srand(time(0));
	int type_of_player;
	int choice;
	
	while(true)
    {
        show_menu();
        cin>>choice;
		if(choice==1)
		{
			while(true)
			{
				cout<<"Select Option! Enter 1 to play with another player and 2 to play with the computer: ";
				cin>>type_of_player;
				cout<<"Enter first player name: ";
				cin>>first_player;
				
				if(type_of_player==2)
				{
					second_player="Computer";
					cout<<"Player 2 is: "<<second_player<<endl;
				}
				else if(type_of_player==1)
				{
					cout<<"Enter second player name: ";
					cin>>second_player;
				}
				
				int winner=0;
				char board[3][3]={{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
				int moves=0;
				while(true)
				{
					show_board(board);
					cout<<"Player 1 moves\n";
					player_moves(board, 'X');
					moves++;
					
					if(checking_winner(board, 'X'))
					{
						show_board(board);
						cout<<"\nPlayer 1 (X) wins!\n";
						winner=1;
						x++;
						b++;
						break;
					}
					if(moves>=9)
					break;
						
					show_board(board);
					cout<<"Second player moves\n";	
					if(type_of_player==1)
					{
						player_moves(board, 'O');
					}
					else
					{
						computer_player_moves(board, 'O');
					}
					moves++;
					
					if(checking_winner(board, 'O'))
					{
						show_board(board);
						cout<<"\nSecond player (O) wins!"<<endl;
						winner=2;
						a++;
						y++;
						break;
					}
				}
				if(winner==0)
				{
					show_board(board);
					cout<<"This game is a tie!\n";
					z++;
					c++;
				}
				show_board(board);
				show_stats();
				cout<<"Would you like to play again? (y/n):";
				char play_again;
				cin>>play_again;
				if (play_again!='y'&&play_again!='Y')
				{
					show_menu();
					cin>>choice;
					break;
				}
			}
		}
		else if(choice==2)
		{
			show_stats();
		}
		else if(choice==3)
		{
			break;
		}
	}
	return 0;
}

void show_menu()
{
	cout<<"WELCOME TO TIC - TAC - TOE!\n";
	cout<<"Please select an option.\n\n";
	cout<<"1. Play game\n\n";
	cout<<"2. Show stats\n\n";
	cout<<"3. Quit\n\n";
}

void show_stats()
{
	cout<<"\n\n";
	cout<<"Player "<<first_player << "stats:\n\n";
	cout<<"Wins: "<<x<<endl<<endl;
	cout<<"Losses: "<<y<<endl<<endl;
	cout<<"Ties: "<<z<<endl<<endl;
	cout<<"Player "<<second_player<<"stats:\n\n";
	cout<<"Wins: "<<a<<endl<<endl;
	cout<<"Losses: "<<b<<endl<<endl;
	cout<<"Ties: "<<c<<endl<<endl;
}

void show_board(char board[][3])
{
	cout<<endl;
	cout<<"\nColumn 1 2 3"<<endl<<endl;
	cout<<"Row"<<endl;
	
	for(int row=0; row<3; row++)
	{
		cout<<"      "<<row+1<<"";
		for(int col=0; col<3; col++)
		{
			cout<<board[row][col]<<" ";
		}
		cout<<endl<<endl;
	}
	cout<<endl;
}

bool checking_winner(char board[][3], char player)
{
	bool flag;
	
	for(int row=0; row<3; row++)
	{
		flag=true;
		
		for(int col=0; col<3; col++)
		{
			flag*=(board[row][col]==player);
		}
		if(flag)
		{
			return true;
		}
	}
	
	for(int col=0; col<3; col++)
	{
		flag=true;
		for(int row=0; row<3; row++)
		{
			flag*=(board[row][col]==player);
		}
		if(flag)
		{
			return true;
		}
	}
	flag=true;
	for(int i=0; i<3; i++)
	{
		flag*=(board[i][i]==player);
	}
	if(flag)
	{
		return true;
	}
	flag=true;
	
	for(int col=0; col<3; col++)
	{
		flag*=(board[2-col][col]==player);
	}
	return flag;
}

void computer_player_moves(char board[][3], char player)
{
	int row, col;
	row=rand()%3;
	col=rand()%3;
	
	while (board[row][col]!='*')
	{
		row=rand()%3;
		col=rand()%3;
	}
	board[row][col]=player;
}

void player_moves(char board[][3], char player)
{
	int row, col;
	cout<<"Row: ";
	cin>>row;
	cout<<"Col: ";
	cin>>col;
	
	while(board[row-1][col-1]!='*'||row>3||row<1||col>3||col<1)
	{
		cout<<"Invalid move! Try again\n";
		cout<<"Row: ";
		cin>>row;
		cout<<"Col: ";
		cin>>col;
	}
	board[row-1][col-1]=player;
}