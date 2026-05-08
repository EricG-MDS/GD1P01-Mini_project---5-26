#include <iostream>
#include <windows.h>
#include <conio.h>

//var decleration
unsigned long player_chips = 2000;
unsigned int current_bet = 0;
char input = '0';
char wheel_1[8] = { '&', '%', '@', '$', '!', '7', '&', '%' };
char wheel_2[8] = { '&', '%', '@', '$', '!', '7', '&', '%' };
char wheel_3[8] = { '&', '%', '@', '$', '!', '7', '&', '%' };
int wheel_output_1 = 0;
int wheel_output_2 = 0;
int wheel_output_3 = 0;
int w1_landed_on = 0;
int w2_landed_on = 0;
int w3_landed_on = 0;




//Functions
void _shuffle_array(char array[], int count) {
	for (int i = 0; i < count; i++)
	{
		int j = rand() % count;
		std::swap(array[i], array[j]);
	}
	for (int i = 0; i < count; i++)
	{
		int j = rand() % count;
		std::swap(array[i], array[j]);
	}
	array[6] = array[0];
	array[7] = array[1];
}


void print_screen(char screen)
{
	// Each screen has a related letter
	// s|start screen , p|play slots , c|credits

	// Clear screen before printing new screen
	system("cls");

	// Switch case statement using char to print the related next screen
	switch (screen)
	{
	case 'c':
		system("cls");
		std::cout << "***************************************************\n";
		std::cout << "*** ---                                         ***\n";
		std::cout << "*** lead programmer - Sylvia Hagen              ***\n";
		std::cout << "*** Assistant lead - Nicolas Martens            ***\n";
		std::cout << "*** ---                                         ***\n";
		std::cout << "*** Unpaid Intern - Eric Grogan                 ***\n";
		std::cout << "*** ---                                         ***\n";
		std::cout << "*** Rubber Duck - Ben Whaley                    ***\n";
		std::cout << "*** Rubber Duck 2 - Zane Jackson                ***\n";
		std::cout << "*** ---                                         ***\n";
		std::cout << "***************************************************\n";
		_getch();
		print_screen('s');
		break;

	case 's':
		input = 0;
		std::cout << "Players chips: $" << player_chips << "\n";
		std::cout << std::endl << "1)  Play Slots\n";
		std::cout << "2)  Credits\n";
		std::cout << "3)  Quit Game\n";
		break;
	case 'p':
		while (true)
		{
			if (0 < current_bet && current_bet <= player_chips)
			{
				break;
			}
			// enter bet screen
			std::cout << "***************************************************\n";
			std::cout << "***                                             ***\n";
			std::cout << "*** Current chipis:                             ***\n";
			std::cout << "*** Please enter your bet:                      ***\n";
			std::cout << "***                                             ***\n";
			std::cout << "***************************************************";
			std::cout << "\033[3A\033[31D";
			std::cout << player_chips;
			std::cout << "\033[999D";
			std::cout << "\033[1B\033[27C";
			std::cin >> current_bet;
			system("cls");
		}

		//spining slots
		std::cout << "***************************************************\n";
		std::cout << "*#################################################*\n";
		std::cout << "*### -money- ##### 0 ### 0 ### 0 ##### 777-x10 ###*\n";
		std::cout << "*### $2000   #### -0- # -0- # -0- #### ###- x5 ###*   @\n";
		std::cout << "*### +- #    ##### 0 ### 0 ### 0 #####  ##- x2 ###*   |\n";
		std::cout << "*#################################################*   |\n";
		std::cout << "*################# Try Your Luck #################*   |\n";
		std::cout << "*#################################################****#\n";
		std::cout << "******************************************************\n";
		std::cout << "\033[6A\033[55C";
		while (player_chips > 0)
		{			//updat money to '$<new money total>' and '+- #'
			std::cout << "\033[49D";
			std::cout << "       " << "\033[7D";
			std::cout << player_chips;
			std::cout << "\033[999D" << "\033[55C";
			_getch();
			player_chips -= current_bet;
			std::cout << "\033[999A\033[999D";
			std::cout << "\033[4B\033[5C";
			std::cout << "       " << "\033[7D";
			std::cout << "-" << current_bet;
			std::cout << "\033[999A\033[999D";
			std::cout << "\033[2B\033[19C";

			//spin the wheels
			int spin_amount = 65;

			//hide console cursour for spin
			HANDLE hStdOut = NULL;
			CONSOLE_CURSOR_INFO curInfo;
			hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			GetConsoleCursorInfo(hStdOut, &curInfo);
			curInfo.bVisible = FALSE;
			SetConsoleCursorInfo(hStdOut, &curInfo);

			//spin wheel 1
			_shuffle_array(wheel_1, 6);
			for (int spiin = 0; spiin <= spin_amount; spiin++)
			{
				int wheel_output_1 = spiin % 6;
				std::cout << wheel_1[wheel_output_1];
				std::cout << "\033[1B\033[1D";
				std::cout << wheel_1[wheel_output_1 + 1];
				std::cout << "\033[1B\033[1D";
				std::cout << wheel_1[wheel_output_1 + 2];
				std::cout << "\033[2A\033[1D";
				spiin > 54 ? spiin > 62 ? Sleep(400) : Sleep(200) : spiin > 36 ? Sleep(100) : spiin > 20 ? Sleep(75) : Sleep(50);
			}
			std::cout << "\033[6C";

			//spin wheel 2
			_shuffle_array(wheel_2, 6);
			for (int spiin = 0; spiin <= spin_amount; spiin++)
			{
				int wheel_output_2 = spiin % 6;
				std::cout << wheel_2[wheel_output_2];
				std::cout << "\033[1B\033[1D";
				std::cout << wheel_2[wheel_output_2 + 1];
				std::cout << "\033[1B\033[1D";
				std::cout << wheel_2[wheel_output_2 + 2];
				std::cout << "\033[2A\033[1D";
				spiin > 54 ? spiin > 62 ? Sleep(400) : Sleep(200) : spiin > 36 ? Sleep(100) : spiin > 20 ? Sleep(75) : Sleep(50);
			}
			std::cout << "\033[6C";

			//spin wheel 3
			_shuffle_array(wheel_3, 6);
			for (int spiin = 0; spiin <= spin_amount; spiin++)
			{
				int wheel_output_3 = spiin % 6;
				std::cout << wheel_3[wheel_output_3];
				std::cout << "\033[1B\033[1D";
				std::cout << wheel_3[wheel_output_3 + 1];
				std::cout << "\033[1B\033[1D";
				std::cout << wheel_3[wheel_output_3 + 2];
				std::cout << "\033[2A\033[1D";
				spiin > 50 ? spiin > 58 ? spiin > 62 ? Sleep(800) : Sleep(400) : Sleep(200) : spiin > 32 ? Sleep(100) : spiin > 16 ? Sleep(75) : Sleep(50);
			}

			//update money
			std::cout << "\033[2B\033[26D";
			w1_landed_on = wheel_1[wheel_output_1];
			w2_landed_on = wheel_2[wheel_output_2];
			w3_landed_on = wheel_3[wheel_output_3];

			if (w1_landed_on == w2_landed_on && w2_landed_on == w3_landed_on)
			{
				if (w1_landed_on == '7')
				{
					player_chips += current_bet * 10;
					std::cout << "    " << "\033[4D";
					std::cout << "+" << current_bet * 9;
				}
				else
				{
					player_chips += current_bet * 5;
					std::cout << "    " << "\033[4D";
					std::cout << "+" << current_bet * 4;
				}
			}
			else if (w1_landed_on == w2_landed_on || w1_landed_on == w3_landed_on || w2_landed_on == w3_landed_on)
			{
				player_chips += current_bet * 2;
				std::cout << "    " << "\033[4D";
				std::cout << "+" << current_bet;
			}
			else
			{
				if (player_chips < 1) { print_screen('w'); break; }
				std::cout << "    " << "\033[4D";
				std::cout << "-" << current_bet;
			}

			//normalise cursour pos
			std::cout << "\033[999A\033[999D";
			std::cout << "\033[3B\033[55C";

			//unhide console cursour
			GetConsoleCursorInfo(hStdOut, &curInfo);
			curInfo.bVisible = TRUE;
			SetConsoleCursorInfo(hStdOut, &curInfo);

			//get next input
			_getch();
			if (GetKeyState('R') & 0x8000)
			{
				current_bet = 0;
				print_screen('p');
			}
			else if (GetKeyState('X') & 0x8000)
			{
				print_screen('w');
				break;
			}
		}
		break;
	case 'w':
		// enter bet screen
		//hide console cursour for spin
		HANDLE hStdOut = NULL;
		CONSOLE_CURSOR_INFO curInfo;
		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleCursorInfo(hStdOut, &curInfo);
		curInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hStdOut, &curInfo);
		system("cls");
		std::cout << "***************************************************\n";
		std::cout << "***                                             ***\n";
		std::cout << "*** starting money:                             ***\n";
		std::cout << "*** final cashout:                              ***\n";
		std::cout << "*** total gain's:                               ***\n";
		std::cout << "***                                             ***\n";
		std::cout << "***************************************************\n";
		std::cout << "\033[5A\033[20C";
		Sleep(400);
		std::cout << "$2000";
		std::cout << "\033[1B\033[6D";
		Sleep(400);
		std::cout << "$" << player_chips;
		std::cout << "\033[999A\033[999D";
		std::cout << "\033[4B\033[18C";
		Sleep(400);
		std::cout << "$" << (long long)player_chips - 2000;
		if (player_chips < 2000) { std::cout << "\033[999D\033[18C" << "-$"; }
		std::cout << "\033[3B\033[999D";
		//unhide console cursour
		GetConsoleCursorInfo(hStdOut, &curInfo);
		curInfo.bVisible = TRUE;
		SetConsoleCursorInfo(hStdOut, &curInfo);
		_getch();
		print_screen('s');
		break;

	
	}
	
}

int main()
{	
	std::srand((unsigned int)std::time(0));
	std::ignore = rand();

	//starting printed screen
	using namespace std;
	{	
		print_screen('s');

		while (true)
		{
			std::cout << "\n: ";
			std::cin >> input;

			switch (input)
			{
			case '1':
				player_chips = 2000;
				current_bet = 0;
				print_screen('p');
				break;

			case '2':
				print_screen('c');
				break;

			case '3':
				return 0;
			}
		}
	}
}