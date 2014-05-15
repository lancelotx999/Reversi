/*Name: Sean Nathaniel Lee Keat Cheong*/
/*Student I.D: 4308131*/
/*Numbers Crush Assignment*/

/*Libraries used in program*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/*Structures*/
typedef struct 
 {
     int row; 
     int col;
 }Size;

/*Function prototypes*/
void Intructions(int Score);
void Board(int x, int y,int Numbers[28][28], char Select[28][28],Size *BoardSize);
int BasicFunction(int Numbers[28][28], char Select[28][28], int x, int y,int Score, char Name [90], Size *BoardSize, int row, int col);
int MovementFunction(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, Size *BoardSize,char Name[90]);
int CheckFunctionPlayer1(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key,int Score, int *Choice, int *Valid, Size *BoardSize);
int CheckFunctionPlayer2(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, int *Choice, int *Valid, Size *BoardSize);
void PlayerFunction(char Name[90], int Score);
void ReadPlayerFunction();
void BoardSizeFunction(Size *BoardSize);
int PlacePiecePlayer1(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, Size *BoardSize,char Name[90]);
int PlacePiecePlayer2(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, Size *BoardSize,char Name[90]);

int main()
{	
	/*Set colour to light green*/
	system("Color 2");

	/*Declares variables and arrays and also assigns value to them*/
	Size BoardSize;

	int Numbers[28][28];
	char Select[28][28];
	int x,y;
	int col = 1,row=1 ;
	char Key;
	int Score = 0;
	int Choice= 0;
	int Valid = 0;
	char Name[90];
	
	/*Call functions*/
	BoardSizeFunction(&BoardSize);

	/*Calculates the starting position.*/
	col = BoardSize.col / 2;
	row = BoardSize.row / 2;

	/*Call functions*/
	BasicFunction(Numbers,Select,x,y, Score, Name, &BoardSize, row ,col);
	
	/*Do loop to call functions until 'q' is pressed*/
	do
	{
		Valid = 0;
		PlacePiecePlayer1(&row,&col,x,y,Select,Numbers,&Key,Score, &BoardSize, Name);
		CheckFunctionPlayer1(&row,&col,x,y,Select,Numbers,&Key,Score,&Choice,&Valid, &BoardSize);
		PlacePiecePlayer2(&row,&col,x,y,Select,Numbers,&Key,Score, &BoardSize, Name);
		CheckFunctionPlayer2(&row,&col,x,y,Select,Numbers,&Key,Score,&Choice,&Valid, &BoardSize);

		// MovementFunction(&row,&col,x,y,Select,Numbers,&Key,Score, &BoardSize, Name);

		// SwapFunction(&row,&col,x,y,Select,Numbers,&Key,Score,&Choice, &BoardSize, Name);

		// Score = CheckFunction(&row,&col,x,y,Select,Numbers,&Key,Score,&Choice,&Valid, &BoardSize);
		
		// if(Valid == 0)
		// {
		// 	InvalidFunction(&row,&col,x,y,Select,Numbers,&Key, Score,&Choice,&Valid, &BoardSize);
		// }

	}while (Key != 113);

	// PlayerFunction(Name,Score);
	// ReadPlayerFunction();

	return 0;
}

void Intructions(int Score)
{
	/*Function to display instructions*/
	printf("\nScore: %i\n", Score);
	printf("\nPress W to move up. \n");
	printf("Press A to move down. \n");
	printf("Press S to move left. \n");
	printf("Press D to move right. \n");
	printf("Press ENTER to select a slot. \n");
	printf("Press Q to quit. \n");
}

void Board(int x, int y,int Numbers[28][28], char Select[28][28], Size *BoardSize)
{
	/*Function to display the board*/
	for(x=1; x < BoardSize->row; x++)
		{	
			printf("\n");	
			for(y=1; y < BoardSize->col; y++)
				{
					printf("%c", Select[x][y]);
					if(Numbers[x][y] == 0)
					{
						printf(" ");
					}
					else if(Numbers[x][y] == 1)
					{
						printf("B");
					}
					else if(Numbers[x][y] == 2)
					{
						printf("W");
					}
					printf("%c", Select[x][y]);
				}
			printf("\n");  	    	
		}
}

int BasicFunction(int Numbers[28][28], char Select[28][28], int x, int y, int Score, char Name [90], Size *BoardSize, int row, int col)
{
	system("cls");
	
	/* Welcome stuff*/
	printf("\t   WELCOME   \n");
	printf("\t     TO   \n");
	printf("\tNumbers CRUSH\n\n");
	
	/*Ask and displays user name*/
	printf("Please Enter your Name:");
	scanf("%s", Name);
	printf("\nGood Luck %s. May The Odds Be Ever In Your Favor. \n", Name);
	fflush(stdin);
	
	/*Blank Map*/
	for(x=1; x < BoardSize->row; x++)
		{
			for(y=1; y < BoardSize->col; y++)
			{
				Numbers[x][y] = 0;
				Select[x][y] = ' ';
			}	 	 	 
		}
		
	Select[row][col]= '|';	 

	/*Displays The board and the Numberss*/
	Board(x,y,Numbers,Select,BoardSize);
	Intructions(Score);

	return 0;
}

int MovementFunction(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, Size *BoardSize,char Name[90])
{
	/*Function to get user input and move selection accordingly*/
	/*Loops until 'q' or Enter key is pressed*/
	do
	{
		
		*Key = getch();
		
		if((*Key == 115 || *Key == 83) && *row != (BoardSize->row-1)) 
		{
			system("cls");
			*row = *row + 1;
			Select[*row][*col]= '|';
			Select[*row-1][*col]= ' ';
			
			Board(x,y,Numbers,Select,BoardSize);

			fflush(stdin);
			Intructions(Score);
			}
		else if((*Key == 119 || *Key == 87) && *row != 1 )
		{
			system("cls");
			*row = *row - 1;
			Select[*row][*col]= '|';
			Select[*row+1][*col]= ' ';
			
			Board(x,y,Numbers,Select,BoardSize);

			fflush(stdin);
			Intructions(Score);
			}
		else if((*Key == 97 || *Key == 65) && *col != 1)
		{
			system("cls");
			*col = *col - 1;
			Select[*row][*col]= '|';
			Select[*row][*col+1]= ' ';

			Board(x,y,Numbers,Select,BoardSize);

			fflush(stdin);
			Intructions(Score);
			}
			
			
		else if((*Key == 100 || *Key == 68) && *col != (BoardSize->col-1))
		{
			system("cls");
			*col = *col + 1;
			Select[*row][*col]= '|';
			Select[*row][*col-1]= ' ';
			Board(x,y,Numbers,Select,BoardSize);

			fflush(stdin);
			Intructions(Score);

		}

		else if(*Key == 113 || *Key == 81)
		{
			PlayerFunction(Name,Score);
			ReadPlayerFunction();
			exit(0);
		}
	}while(*Key != 13);

	return 0;
}

int CheckFunctionPlayer1(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, int *Choice, int *Valid, Size *BoardSize)
{	
	for(x=1; x< BoardSize->row; x++)
		{
			for(y=1; y < BoardSize->col; y++)
			{
				/*Checks the vertically if there are any valid combinations and adds scores if there are*/
				if((Numbers[x-1][y] == Numbers[x+1][y] && Numbers[x][y] == 2 && Numbers[x][y] != 0) && (Numbers[x-1][y] != 0 || Numbers[x+1][y] != 0) )
				{

					printf("\a");

					Select[x+1][y] ='|';
					Select[x][y] ='|';
					Select[x-1][y] ='|';

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					getch();

					Select[x+1][y] =' ';
					Select[x][y] =' ';
					Select[x-1][y] =' ';

					Numbers[x][y] = 1;

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					*Valid = 1;
				}
				/*Checks the horizontally if there are any valid combinations and adds scores if there are*/
				else if((Numbers[x][y-1] == Numbers[x][y+1] && Numbers[x][y] == 2 && Numbers[x][y] != 0) && (Numbers[x][y-1] != 0 || Numbers[x][y+1] != 0) )
				{

					printf("\a");

					Select[x][y+1] ='|';
					Select[x][y] ='|';
					Select[x][y-1] ='|';

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					getch();

					Select[x][y+1] =' ';
					Select[x][y] =' ';
					Select[x][y-1] =' ';

					Numbers[x][y] = 1;

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					*Valid = 1;
				}
				/*Checks the diagonally if there are any valid combinations and adds scores if there are*/
				else if((Numbers[x-1][y+1] == Numbers[x+1][y-1] && Numbers[x][y] == 2 && Numbers[x][y] != 0) && (Numbers[x-1][y+1] != 0 || Numbers[x+1][y-1] != 0) )
				{

					printf("\a");

					Select[x-1][y+1] ='|';
					Select[x][y] ='|';
					Select[x+1][y-1] ='|';

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					getch();

					Select[x+1][y-1] =' ';
					Select[x][y] =' ';
					Select[x-1][y+1] =' ';

					Numbers[x][y] = 1;

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					*Valid = 1;
				}
				else if((Numbers[x+1][y+1] == Numbers[x+1][y+1] && Numbers[x][y] == 2 && Numbers[x][y] != 0) && (Numbers[x+1][y+1] != 0 || Numbers[x+1][y+1] != 0) )
				{

					printf("\a");

					Select[x+1][y+1] ='|';
					Select[x][y] ='|';
					Select[x+1][y+1] ='|';

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					getch();

					Select[x+1][y+1] =' ';
					Select[x][y] =' ';
					Select[x+1][y+1] =' ';

					Numbers[x][y] = 1;

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					*Valid = 1;
				}
			}	 	 	 
		}

	return 0;
}

int CheckFunctionPlayer2(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, int *Choice, int *Valid, Size *BoardSize)
{	
	for(x=1; x< BoardSize->row; x++)
		{
			for(y=1; y < BoardSize->col; y++)
			{
				/*Checks the vertically if there are any valid combinations and adds scores if there are*/
				if((Numbers[x-1][y] == Numbers[x+1][y] && Numbers[x][y] == 1 && Numbers[x][y] != 0) && (Numbers[x-1][y] != 0 || Numbers[x+1][y] != 0) )
				{

					printf("\a");

					Select[x+1][y] ='|';
					Select[x][y] ='|';
					Select[x-1][y] ='|';

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					getch();

					Select[x+1][y] =' ';
					Select[x][y] =' ';
					Select[x-1][y] =' ';

					Numbers[x][y] = 2;

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					*Valid = 1;
				}
				/*Checks the horizontally if there are any valid combinations and adds scores if there are*/
				else if((Numbers[x][y-1] == Numbers[x][y+1] && Numbers[x][y] == 1 && Numbers[x][y] != 0) && (Numbers[x][y-1] != 0 || Numbers[x][y+1] != 0) )
				{
					printf("\a");

					Select[x][y+1] ='|';
					Select[x][y] ='|';
					Select[x][y-1] ='|';

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					getch();

					Select[x][y+1] =' ';
					Select[x][y] =' ';
					Select[x][y-1] =' ';

					Numbers[x][y] = 2;

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					*Valid = 1;
				}
				/*Checks the diagonally if there are any valid combinations and adds scores if there are*/
				else if((Numbers[x-1][y+1] == Numbers[x+1][y-1] && Numbers[x][y] == 1 && Numbers[x][y] != 0) && (Numbers[x-1][y+1] != 0 || Numbers[x+1][y-1] != 0) )
				{

					printf("\a");

					Select[x-1][y+1] ='|';
					Select[x][y] ='|';
					Select[x+1][y-1] ='|';

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					getch();

					Select[x+1][y-1] =' ';
					Select[x][y] =' ';
					Select[x-1][y+1] =' ';

					Numbers[x][y] = 2;

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					*Valid = 1;
				}
				else if((Numbers[x+1][y+1] == Numbers[x+1][y+1] && Numbers[x][y] == 1 && Numbers[x][y] != 0) && (Numbers[x+1][y+1] != 0 || Numbers[x+1][y+1] != 0) )
				{

					printf("\a");

					Select[x+1][y+1] ='|';
					Select[x][y] ='|';
					Select[x+1][y+1] ='|';

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					getch();

					Select[x+1][y+1] =' ';
					Select[x][y] =' ';
					Select[x+1][y+1] =' ';

					Numbers[x][y] = 2;

					system("cls");
					Board(x,y,Numbers,Select,BoardSize);
					Intructions(Score);
					*Valid = 1;
				}
			}	 	 	 
		}

	return 0;
}

int PlacePiecePlayer1(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, Size *BoardSize,char Name[90])
{
	int Valid = 0;
	do
	{
		system("cls");
		printf("Player 1's Turn\n");
		Board(x,y,Numbers,Select,BoardSize);
		fflush(stdin);
		Intructions(Score);
		MovementFunction(row,col,x,y,Select,Numbers,Key,Score, BoardSize, Name);

		if (Numbers[*row][*col] == 0 || Numbers[*row][*col] == 0)
		{
			Numbers[*row][*col] = 1;
			Valid = 1;
			system("cls");
			Board(x,y,Numbers,Select,BoardSize);
			fflush(stdin);
			Intructions(Score);
		}
		else
		{
			system("cls");
			Board(x,y,Numbers,Select,BoardSize);
			fflush(stdin);
			printf("Invalid Input");
			Intructions(Score);
		}	
	}while(Valid == 0);

	Valid = 0;

	return 0;
}

int PlacePiecePlayer2(int *row,int *col,int x,int y,char Select[28][28],int Numbers[28][28],char *Key, int Score, Size *BoardSize,char Name[90])
{
	int Valid = 0;
	do
	{	
		system("cls");
		printf("Player 2's Turn\n");
		Board(x,y,Numbers,Select,BoardSize);
		fflush(stdin);
		Intructions(Score);
		MovementFunction(row,col,x,y,Select,Numbers,Key,Score, BoardSize, Name);

		if (Numbers[*row][*col] == 0 || Numbers[*row][*col] == 0)
		{
			Numbers[*row][*col] = 2;
			Valid = 1;
			system("cls");
			Board(x,y,Numbers,Select,BoardSize);
			fflush(stdin);
			Intructions(Score);
		}
		else
		{
			system("cls");
			Board(x,y,Numbers,Select,BoardSize);
			fflush(stdin);
			printf("Invalid Input");
			Intructions(Score);		
		}	
	}while(Valid == 0);

	Valid = 0;

	return 0;
}

void PlayerFunction(char Name[90], int Score)
{
	/*Save a .txt file called Players which stores the name and score of people who have played.*/
	FILE *File = fopen("Players.txt","a");

	fprintf(File,"%s\t\t%i\t\n", Name, Score);

	fclose(File);
}

void ReadPlayerFunction()
{
	/*Find and scan the Players.txt file then display the scores and names of previous players.*/
	FILE *File = fopen("Players.txt","r");
	char Name[90];
	int Score = 0;
	system("cls");
	if(File == NULL)
	{
		printf("No Previous Record Found.\n");
	}

	printf("\t      SCORE BOARD\n\n");

	while (fscanf(File,"%s%i", Name,&Score) == 2)
	{
		printf("\tName:%s\t Score:%i\n", Name,Score);
	}

	printf("\n\tTHANK YOU FOR PLAYING!\n");
	printf("\a");
	getch();
}

void BoardSizeFunction(Size *BoardSize)
{
	int Valid = 0;
	BoardSize->row = 0;
	BoardSize->col = 0;

	/* Welcome stuff*/
	printf("\t   WELCOME   \n");
	printf("\t     TO   \n");
	printf("\tNumbers CRUSH\n\n");

	printf("Maximum for DOS Screen is 25x25.\nMinimum is 3x3.\n\n");

	do 
	{
		printf("Enter Numbers of rows.\n");
		scanf("%i", &BoardSize->row);
		if (BoardSize->row < 26 && BoardSize->row > 2)
		{Valid = 1;}
		else
		{Valid = 0;}
	}while (Valid == 0);

	do 
	{
		printf("Enter Numbers of columns.\n");
		scanf("%i", &BoardSize->col);
		if (BoardSize->col < 26 && BoardSize->col > 2)
		{Valid = 1;}
		else
		{Valid = 0;}
	}while (Valid == 0);

	/*Compensate for array starting at 1*/
	BoardSize->col = BoardSize->col + 1;
	BoardSize->row = BoardSize->row + 1;
}
