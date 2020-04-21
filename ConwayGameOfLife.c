//CONWAY'S GAME OF LIFE
//ITP SEMESTER PROJECT

#include <stdio.h> //standard input output library
#include <stdlib.h> //standard c functions library
#include <windows.h> //windows library for functions like sleep etc.

char mainArray[37][87]; //main array where every act is performed is globally initialized
char fakeArray[35][85] = { ' ' }; //a character dummy array is defined
int gen; //the no of generations globally initialized

void Block(void); //block pattern function prototype
void Boat(void); //boat pattern function prototype
void Loaf(void); //loaf pattern function prototype
void Beehive(void); //beehive pattern function prototype
void Blinker(void); //blinker pattern function prototype
void Beacon(void); //beacon pattern function prototype
void Toad(void); //toad pattern function prototype
void Pulsar(void); //pulsar pattern function prototype
void Glider(void); //glider pattern function prototype
void lightSShip(void); //light space ship pattern function prototype
void gliderGun(void); //glider gun pattern function prototype
void randomSeed(void); //random seed pattern function prototype

void welcome(void); //welcome function prototype
void functSelector(void); //the prototype for selection of different functions
void genSolver(void); //generation solver function prototype
void charconfig(int, int, int);
void blankconfig(int, int, int);
void printer(void); //printer function prototype
void boxer(void); //the outside box making function prototype
int checkfunct(int, int); //inside neighbour checking function prototype

int main(void) //main function
{
	welcome(); // function call for welcome function
	system("pause"); //the end of everything... :p
} //end main

void welcome(void) //welcome function starts
{
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("###############################################################################################################\n"); //game name
	printf("###############################################################################################################\n");
	printf("###############################################################################################################\n");
	printf("###################                                                                         ###################\n");
	printf("###################                                                                         ###################\n");
	printf("				           CONWAY GAME OF LIFE                                                   \n");
	printf("###################                                                                         ###################\n");
	printf("###################                                                                         ###################\n");
	printf("###############################################################################################################\n");
	printf("###############################################################################################################\n");
	printf("###############################################################################################################\n");
	printf("\n\n\n\n\n\tA Project By:\n\t\tMuhammad Hamza\n\t\tMuhammad Ovais\n\t\tLaiba Bukhsh"); //particpants name
	Sleep(3000); //3000ms sleep
	system("cls"); //clear screen
	printf("\n\n\t\t GREETINGS USER\n\t\tGOOD DAY TO YOU\n\n"); //intro.
	Sleep(500); //500ms sleep
	printf("This is Conway's Game Of Life. It was invented in 1970 by the British mathematician John Horton Conway.\nIt is the best-known example of a cellular automaton which is any system \nIn which rules are applied to cells and their neighbors in a regular grid.\n\n"); //game intro
	Sleep(500); //500ms sleep
	printf("The rules of this game is:\n");
	Sleep(100); //100ms sleep
	printf("\t 1: Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.\n"); //rule 1
	Sleep(100); //100ms sleep
	printf("\t 2: Any live cell with more than three live neighbors dies, as if by overcrowding.\n"); //rule 2
	Sleep(100); //100ms sleep
	printf("\t 3: Any live cell with two or three live neighbors lives on to the next generation.\n"); //rule 3
	Sleep(100); //100ms sleep
	printf("\t 4: Any dead cell with exactly three live neighbors becomes a live cell."); //rule 4
	Sleep(7000); //7000ms sleep
	system("cls"); //clear screen
	printf("\nTheir are many type of patterns and many of them are available to use.\nBut first we will see these types.\n\n");
	Sleep(200); //200ms sleep
	printf("Static Patterns: These are stable patterns that do not change. Some of them are:\n"); //pattern 1
	Sleep(200); //200ms sleep
	printf("\t1: Block\n\t2: Boat\n\t3: Loaf\n\t4: Beehive\n\n");
	Sleep(200); //200ms sleep
	printf("Oscillatory Patterns: These patterns are more complex and change over a specific number of ticks. \n\tThey repeat their pattern infinitely. Some of them are:\n"); //pattern 2
	Sleep(200); //200ms sleep
	printf("\t1: Blinker\n\t2: Beacon\n\t3: Toad\n\t4: Pulsar\n\n");
	Sleep(200); //200ms sleep
	printf("Glider and Spaceship: A spaceship is a pattern that moves, returning to the same configuration \n\tbut shifted after a finite number of generations.The glider is an example of a simple spaceship.\n\n"); //pattern 3
	Sleep(200); //200ms sleep
	printf("Guns: Guns are repeating patterns which produce a spaceship after a finite number of generations.\n\tThe simplest gun, called the Gosper glider gun, produces a glider every 30 generations."); //pattern 4
	Sleep(8000); //8s sleep
	system("cls"); //clear screen
	functSelector(); //funnction call for function selector function
} //end welcome function

void functSelector(void) //the pattern selector function
{
	int z = 0; //variable to control the no of times the patterns are choosed
	while (z != -1) {//loop to choose different pattern again continues until -1 is entered
		printf("\n\nDear User:\n\tYou are requested to enter the number of generations you wish the pattern should reproduce.\n"); //instruction
		printf("Enter the number of generations: ");
		scanf_s("%d", &gen); //no of generation input
		Sleep(100); //100ms sleep
		printf("\nDear User: \n\tNow the names of differnet types of patterns and their corresponding number are given.\n\tPlease Select any of them.\n\n");
		Sleep(100); //100ms sleep
		printf("1:  Block\n2:  Boat\n3:  Loaf\n4:  Beehive\n5:  Blinker\n6:  Beacon\n7:  Toad\n8:  Pulsar\n9:  Glider\n10: Light Space-Ship\n11: Glider Gun\n12: Random Seed\n"); //names of pattern

		for (int i = 0; i < 37; ++i) //row for loop
		for (int j = 0; j < 87; ++j) //column for loop
			mainArray[i][j] = ' '; //every element of main array initialized to a blank space

		int functSelect; //variable intialized to select pattern function
		printf("Enter The Number For Corresponding Function: ");
		scanf_s("%d", &functSelect); //input of corresponding number of function
		system("cls"); //clear screen

		switch (functSelect){//switch case with functselect as input 
		case 1: //when 1 is entered
			Block(); //block function initialized
			break; //switch loop break
		case 2: //when 2 is entered
			Boat(); //boat function initialized
			break; //switch loop break
		case 3: //when 3 is entered
			Loaf(); //loaf function initialized
			break; //switch loop break
		case 4: //when 4 is entered
			Beehive(); //beehive function initialized
			break; //switch loop break
		case 5: //when 5 is entered
			Blinker(); //blinker function initialized
			break; //switch loop break
		case 6: //when 6 is entered
			Beacon(); //beacon function initialized
			break; //switch loop break
		case 7: //when 7 is entered
			Toad(); //toad function initialized
			break; //switch loop break
		case 8: //when 8 is entered
			Pulsar(); //pulsar function initialized
			break; //switch loop break
		case 9: //when 9 is entered
			Glider(); //glider function initialized
			break; //switch loop break
		case 10: //when 10 is entered
			lightSShip(); //light space ship function initialized
			break; //switch loop break
		case 11: //when 11 is entered
			gliderGun(); //glider function initialized
			break; //switch loop break
		case 12: //when 12 is entered
			randomSeed(); //random seed function initialized
			break; //switch loop break
		default: //default statement
			break; //switch loop break
		} //end switch case

		Sleep(2000); //2s delay
		system("cls"); //clears screen
		printf("\n\nIf You Want To Continue, Enter Any Number, But If You Want To Exit Press -1: ");
		scanf_s("%d", &z); //input variable to see if user wants to continue or quit

		if (z == -1){ //begins only when user wants to quit
			printf("Well I Don't Really Want You To Leave.\nIt Took Me So Much Time To Make This Program And Now You Are Leaving.\nBut I Can't Do Anything So,\n\n\n\t\t\tGRACIAS!!!"); //bye bye
			Sleep(400); //400ms delay
			printf("\n\n\tIt Was One Hell Of A Program!\n\tTime To Give Full Marks. :p\n\n"); //:p
		}//endif
	}//endwhile
} // end function selector function

void Block(void) //block function begins
{
	char block[2][4] = { { ' ', '+', '+', ' ' }, { ' ', '+', '+', ' ' } };//array which contains the block seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 33; //random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 83;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 2; i++) //row for loop limit to seed row
	for (int j = 0; j < 4; j++) //column for loop limit to seed column
		mainArray[x + i][y + j] = block[i][j]; //the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end box function

void Boat(void)//boat function begins
{
	char boat[3][5] = { { ' ', '+', '+', ' ', ' ' }, { ' ', '+', ' ', '+', ' ' }, { ' ', ' ', '+', ' ', ' ' } };//array which contains the boat seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 32;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 80;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 3; i++)//row for loop limit to seed row
	for (int j = 0; j < 5; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = boat[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end boat function

void Loaf(void)//loaf function begins
{
	char loaf[4][6] = { { ' ', ' ', '+', '+', ' ', ' ' }, { ' ', '+', ' ', ' ', '+', ' ' }, { ' ', ' ', '+', ' ', '+', ' ' }, { ' ', ' ', ' ', '+', ' ', ' ' } };//array which contains the loaf seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 31;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 79;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 4; i++)//row for loop limit to seed row
	{
		for (int j = 0; j < 6; j++)//column for loop limit to seed column
			mainArray[x + i][y + j] = loaf[i][j];//the characters in seed are transfered to main array at random positions
	}

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end loaf function

void Beehive(void)//beehive function begins
{
	char beehive[3][6] = { { ' ', ' ', '+', '+', ' ', ' ' }, { ' ', '+', ' ', ' ', '+', ' ' }, { ' ', ' ', '+', '+', ' ', ' ' } };//array which contains the beehive seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 32;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 79;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 3; i++)//row for loop limit to seed row
	for (int j = 0; j < 6; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = beehive[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end beehive function

void Blinker(void)//blinker function begins
{
	char blinker[1][5] = { { ' ', '+', '+', '+', ' ' } };//array which contains the blinker seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 34;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 80;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 1; i++)//row for loop limit to seed row
	for (int j = 0; j < 5; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = blinker[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end blinker function

void Beacon(void)//beacon function begins
{
	char beacon[4][6] = { { ' ', '+', '+', ' ', ' ', ' ' }, { ' ', '+', ' ', ' ', ' ', ' ' }, { ' ', ' ', ' ', ' ', '+', ' ' }, { ' ', ' ', ' ', '+', '+', ' ' } };//array which contains the beacon seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 31;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 29;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 4; i++)//row for loop limit to seed row
	for (int j = 0; j < 6; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = beacon[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end beacon function

void Toad(void)//toad function begins
{
	char toad[2][6] = { { ' ', ' ', '+', '+', '+', ' ' }, { ' ', '+', '+', '+', ' ', ' ' } };//array which contains the toad seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 33;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 79;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 2; i++)//row for loop limit to seed row
	for (int j = 0; j < 6; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = toad[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end toad function

void Pulsar(void)//pulsar function begins
{
	char pulsar[15][17] = { { ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ' },//array which contains the pulsar seed
	{ ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', '+', '+', '+', ' ', ' ', '+', '+', ' ', '+', '+', ' ', ' ', '+', '+', '+', ' ' },
	{ ' ', ' ', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', ' ', ' ' },
	{ ' ', '+', '+', '+', ' ', ' ', '+', '+', ' ', '+', '+', ' ', ' ', '+', '+', '+', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ' } };

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 20;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 68;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 15; i++)//row for loop limit to seed row
	for (int j = 0; j < 17; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = pulsar[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end pulsar function

void Glider(void)//glider function begins
{
	char glider[3][5] = { { ' ', ' ', '+', ' ', ' ' }, { ' ', ' ', ' ', '+', ' ' }, { ' ', '+', '+', '+', ' ' } };//array which contains the glider seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 32;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 80;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 3; i++)//row for loop limit to seed row
	for (int j = 0; j < 5; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = glider[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end glider function

void lightSShip(void) //light space ship function begins
{
	char spaceship[4][5] = { { '+', ' ', ' ', '+', ' ' }, { ' ', ' ', ' ', ' ', '+' }, { '+', ' ', ' ', ' ', '+' }, { ' ', '+', '+', '+', '+' } }; //array which contains the light space ship seed

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 31;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 80;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 4; i++)//row for loop limit to seed row
	for (int j = 0; j < 5; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = spaceship[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
}// end light space ship function

void gliderGun(void) //glider gun function initialized
{
	char gggun[12][38] = { { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //array which contains the glider gun seed
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', '+', '+', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ' },
	{ ' ', '+', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', '+', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', '+', ' ', '+', ' ', ' ', '+', ' ', ' ', ' ', '+', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', '+', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, };

	srand(time(NULL)); //random function synced to cpu clock
	int x = rand() % 23;//random function limited to the maximum no of initial no that can be used in main array in row
	int y = rand() % 47;//random function limited to the maximum no of initial no that can be used in main array in column

	for (int i = 0; i < 12; i++)//row for loop limit to seed row
	for (int j = 0; j < 38; j++)//column for loop limit to seed column
		mainArray[x + i][y + j] = gggun[i][j];//the characters in seed are transfered to main array at random positions

	boxer(); //box making function initialized
	printer(); //printing function initialized
	genSolver(); //generation solver function initialized
} // end glider gun function

void randomSeed(void) //random function initialized
{
	srand(time(NULL));  //random seed linked to cpu clock
	for (int i = 0; i < 35; i++){	//row for loop
		for (int j = 0; j < 85; j++) //column for loop
		{
			int x = rand() % 2; //random function generates 1 and 0
			if (x == 1)
				mainArray[i + 1][j + 1] = '+';
			else
				mainArray[i + 1][j + 1] = ' ';
		}//end for
	}
	boxer(); //boxer function intialized
	printer(); //printer function initialized
	genSolver(); //function to solve generations initialzed
}

void genSolver(void)
{
	Sleep(100); //100ms sleep
	while (gen > 1) //as 1 generation happens when the pattern is first initialzed to while loop to see if all the generations have proceeded or not
	{
		for (int i = 1; i < 36; i++){ //row for loop for main 37x87 array
			for (int j = 1; j < 86; j++){//column for loop for main 37x87 array
				int res = checkfunct(i, j); //check function to see the number of char neighbours
				if (mainArray[i][j] == '+')
					charconfig(res, i, j);
				else
					blankconfig(res, i, j);
			}
		}
		for (int i = 0; i < 35; i++){ //row for loop
			for (int j = 0; j < 85; j++)//column for loop
				mainArray[i + 1][j + 1] = fakeArray[i][j];//loop to replace all values from fake array to main array
		}
		Sleep(100); //100ms sleep
		system("cls"); //clear screen
		gen--; //subtract 1 from generation variable
		boxer(); //initialize box making function
		printer(); //imitialize printing funcion
	}
}

void charconfig(int res, int i, int j)
{
	if (res >= 2 && res <= 3) //if the no of neighbour are either 2 or 3 then if statment proceeds
		fakeArray[i - 1][j - 1] = '+'; //if neighbours are 2 or 3 then the fake array getrs the char + at that element
	else
		fakeArray[i - 1][j - 1] = ' '; //if neighbours are less than 2 or greater 5 then continue
}

void blankconfig(int res, int i, int j)
{
	if (res == 3)
		fakeArray[i - 1][j - 1] = '+'; //if neighbours are exactly 3 then the fake array gets the char + at that element
	else
		fakeArray[i - 1][j - 1] = ' '; //if neighbours are not exactly 3 then the fake array gets the char ' ' at that element
}

int checkfunct(int i, int j)
{
	int x1 = i - 1; //variable initialization
	int y1 = j - 1;
	int x2 = i + 1;
	int y2 = j + 1;
	int count = 0;
	if (i == 1) //first row
		x1 = 35;
	if (i == 35) //last row
		x2 = 1;
	if (j == 1) //first column
		y1 = 85;
	if (j == 85) //last column
		y2 = 1;
	if (i == 1 && j == 1){ //left upper corner
		x1 = 35;
		x2 = 2;
		y1 = 85;
		y2 = 2;
	}
	if (i == 1 && j == 85){ //right upper corner
		x1 = 35;
		x2 = 2;
		y1 = 84;
		y2 = 1;
	}
	if (i == 35 && j == 1){ //left lower corner
		x1 = 34;
		x2 = 1;
		y1 = 85;
		y2 = 2;
	}
	if (i == 35 && j == 85){ //right lower corner
		x1 = 34;
		x2 = 1;
		y1 = 84;
		y2 = 1;
	}
	if (mainArray[x1][y1] == '+') //upper left neighbour
		count++;
	if (mainArray[x1][j] == '+') //upper middle neighbour
		count++;
	if (mainArray[x1][y2] == '+') //upper right neighbour
		count++;
	if (mainArray[i][y1] == '+') //left neighbour
		count++;
	if (mainArray[i][y2] == '+') //right neighbour
		count++;
	if (mainArray[x2][y1] == '+') //lower left neighbour
		count++;
	if (mainArray[x2][j] == '+') //lower middle neighbour
		count++;
	if (mainArray[x2][y2] == '+') //lower right neighbour
		count++;
	return count;
}

void boxer(void)
{
	for (int i = 0; i < 37; i++) //row for loop for main array
	{
		if (i == 0 || i == 36) {//in main array if the loop gets to the first and last row index then if statement is initialized	
			for (int j = 0; j < 87; j++) //column for loop for main array
				mainArray[i][j] = '#'; //print - on the top or bottom of the main array
		}
		else{
			for (int j = 0; j < 87; j++) //column for loop for main array
			if (j == 0 || j == 86) //in main array if the loop gets to the first or last column index then if statement is initialized
				mainArray[i][j] = '#';
		}// print | on the left or right of the main array
	}//end for
}//end boxer function

void printer(void) //function which prints everything
{
	for (int i = 0; i < 37; i++) //row for loop for main array
	{
		for (int j = 0; j < 87; j++) //column for loop for main array
			printf("%c", mainArray[i][j]); //printing of corresponding character
		printf("\n");
	}//endfor
}//end printer

//GRACIAS!!! FOR PUTTING WITH US FOR SO SO SO LONG!!!!! :p
