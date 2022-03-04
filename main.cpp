#include <iostream>
#include <fstream>
#include <streambuf>
#include <iomanip>
#include <string>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include "material.h"
#include "Algorithms.h"
#include <string.h>
using namespace std;
int main()
{
	int getUserSel, getAlgoSel;
	char c;
start:
	Welcome();
	cin >> c;
	getUserSel = Convertchar(c);

	switch (getUserSel)
	{
	case 1:
		if (LogIn()) // if logged in successfully
		{

		home:
			ShowDashboard();
			cin >> c;
			int getDashboardSel = Convertchar(c);
			switch (getDashboardSel) // to manage dashboard
			{
			case 1:

			algo:
				ShowAlgoDashboard(); // to show algorithm dashboard
				cin >> c;
				getAlgoSel = Convertchar(c);
				switch (getAlgoSel) // to manage algo
				{

				case 1: // to encrypt algorithm

					while (true)
					{
						string encrypted;
						char pp;
						char msg[1000];
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter Shift No:";
						cin >> pp;
						int p = Convertchar(pp);
						if (!(p > 0 && p < 27))
						{
							system("CLS");
							cout << "\tIvalid shift value!\n";
							goto algo;
						}
						encrypted = ECeaserCipher(msg, p);
						cout << "\tCeaser Encryption: " << encrypted << endl;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto algo;
						} // if
					}	  // while
					break;
				case 2: // to decrypt
					while (true)
					{
						string encrypted;
						char pp;
						char msg[1000];
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter Shift No:";
						cin >> pp;
						int p = Convertchar(pp);
						if (!(p > 0 && p < 27))
						{
							system("CLS");
							cout << "\tIvalid shift value!\n";
							goto algo;
						}
						encrypted = DCeaserCipher(msg, p);
						cout << "\tCeaser Encryption: " << encrypted << endl;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto algo;
						} // if
					}
					break;
				case 3: // to show details of algorithm
					ShowAlgoDetails("Algos\\Ceaser_Cipher.txt");
					cout << "\n\n\tPress Any Key to Go Back!\n";
					cin >> c;
					goto algo;
					break;
				case 4: // to go back to home
					goto home;
					break;
				default: // to handle wron input
					system("CLS");
					cout << "\tPlease, Select Correct Option!\n";
					goto algo;
				} // algo switch
				break;
			case 2:
			playfairAlgo:
				ShowAlgoDashboard(); // to show algorithm dashboard
				cin >> c;
				getAlgoSel = Convertchar(c);
				switch (getAlgoSel) // to manage algo
				{
				case 1: // to encrypt algorithm
					while (true)
					{
						string encrypted;
						string key = "cipher";
						char pp;
						char msg[1000];
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						encrypted = EPlayfairCipher(msg, key);
						cout << "\tPlayfair Encryption: " << encrypted;
						cout << "\n\tAnd Encrytion Key is: " << key << endl;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto playfairAlgo;
						} // if
					}	  // while
					break;
				case 2: // to decrypt
					while (true)
					{
						string encrypted;
						char pp;
						string dKey;
						string key = "cipher";
						char msg[1000];
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						encrypted = DPlayfairCipher(msg, key);
						cout << "\tPlayfair Decryption: " << encrypted << endl;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto playfairAlgo;
						} // if
					}
					break;
				case 3: // to show details of algorithm
					ShowAlgoDetails("Algos\\Playfair_Cipher.txt");
					cout << "\n\n\tPress Any Key to Go Back!\n";
					cin >> c;
					goto playfairAlgo;
					break;
				case 4: // to go back to home
					goto home;
					break;
				default: // to handle wron input
					system("CLS");
					cout << "\tPlease, Select Correct Option!\n";
					goto playfairAlgo;
				}
				break;
			case 3:
			TranspostionAlgo:
				ShowAlgoDashboard(); // to show algorithm dashboard
				cin >> c;
				getAlgoSel = Convertchar(c);
				switch (getAlgoSel) // to manage algo
				{
				case 1: // to encrypt algorithm
					while (true)
					{
						string encrypted;
						char pp;
						char msg[1000];
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						setPermutationOrder();
						encrypted = ETranspostionCipher(msg);
						cout << "\tTranspostion Encryption: " << encrypted;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto TranspostionAlgo;
						} // if
					}	  // while
					break;
				case 2: // to decrypt
					while (true)
					{
						string encrypted;
						char pp;

						char msg[1000];
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						encrypted = DTranspostionCipher(msg);
						cout << "\tTranspostion Decryption: " << encrypted << endl;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto TranspostionAlgo;
						} // if
					}
					break;
				case 3: // to show details of algorithm
					ShowAlgoDetails("Algos\\Transposition_Cipher.txt");
					cout << "\n\n\tPress Any Key to Go Back!\n";
					cin >> c;
					goto TranspostionAlgo;
					break;
				case 4: // to go back to home
					goto home;
					break;
				default: // to handle wron input
					system("CLS");
					cout << "\tPlease, Select Correct Option!\n";
					goto TranspostionAlgo;
				}
				break;
			case 4:
			XORAlgo:
				ShowAlgoDashboard(); // to show algorithm dashboard
				cin >> c;
				getAlgoSel = Convertchar(c);
				switch (getAlgoSel) // to manage algo
				{
				case 1: // to encrypt algorithm
					while (true)
					{
						string encrypted;
						string key;
						char pp;
						char msg[1000];
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter Key: ";
						getline(cin, key);
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						encrypted = XORCipher(msg, key);
						cout << "\tXOR Encryption: " << encrypted;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto XORAlgo;
						} // if
					}	  // while
					break;
				case 2: // to decrypt
					while (true)
					{
						string encrypted;
						char pp;
						string dKey;
						char msg[1000];
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\tEnter Key: ";
						getline(cin, dKey);
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						encrypted = XORCipher(msg, dKey);
						cout << "\tXOR Decryption: " << encrypted << endl;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto XORAlgo;
						} // if
					}
					break;
				case 3: // to show details of algorithm
					ShowAlgoDetails("Algos\\XOR_Cipher.txt");
					cout << "\n\n\tPress Any Key to Go Back!\n";
					cin >> c;
					goto XORAlgo;
					break;
				case 4: // to go back to home
					goto home;
					break;
				default: // to handle wron input
					system("CLS");
					cout << "\tPlease, Select Correct Option!\n";
					goto XORAlgo;
				}
				break;
			case 5:
			VigenereAlgo:
				ShowAlgoDashboard(); // to show algorithm dashboard
				cin >> c;
				getAlgoSel = Convertchar(c);
				switch (getAlgoSel) // to manage algo
				{
				case 1: // to encrypt algorithm
					while (true)
					{
						string encrypted;
						string key;
						char pp;
						char msg[1000];
						cin.ignore();
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore();
						cout << "\tEnter Key: ";
						getline(cin, key);
						cin.ignore();
						string sKey = generateKey(msg, key);
						encrypted = EVigenereCipher(msg, sKey);
						cout << "\tVigenere Encryption: " << encrypted;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto VigenereAlgo;
						} // if
					}	  // while
					break;
				case 2: // to decrypt
					while (true)
					{
						string encrypted;
						char pp;
						string dKey;
						char msg[1000];
						cin.ignore();
						cout << "\tEnter MSG: ";
						cin.getline(msg, 1000, '\n');
						cin.ignore();
						cout << "\tEnter Key: ";
						getline(cin, dKey);
						cin.ignore();
						string sdKey = generateKey(msg, dKey);
						encrypted = DVigenereCipher(msg, sdKey);
						cout << "\tVigenere Decryption: " << encrypted << endl;
						cout << "\n\tWant Again? (y|n): ";
						cin >> pp;
						if (pp == 'n' || pp == 'N')
						{
							goto VigenereAlgo;
						} // if
					}
					break;
				case 3: // to show details of algorithm
					ShowAlgoDetails("Algos\\Vigenere_Cipher.txt");
					cout << "\n\n\tPress Any Key to Go Back!\n";
					cin >> c;
					goto VigenereAlgo;
					break;
				case 4: // to go back to home
					goto home;
					break;
				default: // to handle wron input
					system("CLS");
					cout << "\tPlease, Select Correct Option!\n";
					goto VigenereAlgo;
				}
				break;
			case 6: // to log out
				goto start;
				break;
			case 65: // to quit program
				return -1;
				break;
			default: // to handle wrong input
				system("CLS");
				cout << "\tPlease, Select Correct Option!\n";
				goto home;
			} // dashboard switch
		}	  // log in if
		else
		{ // log in else
			goto start;
		} // log in else
		break;
	case 2:			  // to sign up
		if (SignUp()) // if sign up successfull
		{
			goto home;
		}
		else
		{
			goto start;
		}
		break;
	case 3: // to show all algorithms
		ShowAlgorithms();
		goto start;
		break;
	case 65: // to stop program
		return -1;
		break;
	default: // to manage wrong input
		system("CLS");
		cout << "\tPlease, Select Correct Option!\n";
		goto start;
	}
	return 0;
}
