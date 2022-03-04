#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <bits/stdc++.h>
#define MAX_LENGTH_PASS 10
#define MAX_LENGTH_USERNAME 20
#define MAX_LENGTH_EMAIL 50
using namespace std;
void ShowAlgoDetails(char filename[50]){
	ifstream f;
	//const string filename="Ceaser_Cipher.txt";
	f.open(filename);
    if (f)
    {
        string str((istreambuf_iterator<char>(f)),
        istreambuf_iterator<char>());
        cout<<str;
    }
}
void ShowAlgoDashboard(){
	
	system("CLS");
			cout<<"\n\n\t\t\t\t\t\xb3\xB2=\xB2=\xB2-\xB3 CryptoGrapher \xB3-\xB2=\xB2=\xB2\xB3\n\n"<<endl;

	cout<<"\t1- Encrypt\t\t2- Decrypt\n\t3- Show Details\t\t4- Go Back\n\n";
	cout<<"\tPlease Select option: ";
}
int Convertchar(char c){
	int x;
	x=int(c);
	x-=48;
	return x;
}
void ShowAlgorithms(){
	cout<<"\n\n\t\t\t\t\t\xb3\xB2=\xB2=\xB2-\xB3 All Available Algorithms! \xB3-\xB2=\xB2=\xB2\xB3\n\n"<<endl;

	cout<<"\t[+] Ceaser Cipher\n";
	cout<<"\t[+] Transpostion Cipher\n";
	cout<<"\t[+] XOR Cipher\n";
	cout<<"\t[+] Vigenere Cipher\n";
	cout<<"\t[+] Playfair Cipher\n";
}
bool ValidateLogIn(string user,string password){
	string username,email,pass;
	fstream accounts;
	accounts.open("accounts.txt",ios::in);
	if(!accounts.is_open()) 
	{
		cout<<"File could not be opened"; 
		return false;       
    }
   else
    {
    	string n,e,p;

		while (!accounts.eof()) {
			accounts>>n>>p>>e;
			if(n==user&&p==password){
    			return true;
    			
			}

			
		}
    	/*while(accounts>>username>>pass>>email){
    		if(!(user==username&&password==pass)){
    			return false;
			}
		}*/
        accounts.close();     
    }
	return false;
}
bool LogIn(){
	string user,pass;
		cout<<"\n\n\t\t\t\t\t\xb3\xB2=\xB2=\xB2-\xB3 Log In to Continue! \xB3-\xB2=\xB2=\xB2\xB3\n\n"<<endl;
		cout<<"\tEnter User Name: ";
			cin>>user;
			cout<<"\tEnter Password: ";
			cin>>pass;
		if(ValidateLogIn(user,pass)){
			system("CLS");
			cout<<"\tLogged In Successfully!\n";
			return true;
		}
		else{
			system("CLS");
			cout<<"\tLog in Error, Try Again!\n";
			return false;
		}
}
bool ValidateUserName(string user){
	string username,email,pass;
	fstream accounts;
	accounts.open("accounts.txt",ios::in);
	if(!accounts.is_open()) 
	{
		cout<<"File could not be opened"; 
		return false;       
    }
   else
    {
    	while(accounts>>username>>pass>>email){
    		if(user==username){
    			return false;
			}
		}
        accounts.close();     
    }
    return true;
}
bool SaveAccounts(string username,string email,string pass){
	fstream accounts;
	accounts.open("accounts.txt",ios::out | ios::app);
	if(!accounts.is_open()) 
	{
		cout<<"File could not be opened"; 
		return false;       
    }
   else
    {
        accounts<<username<<" "<<pass<<" "<<email<<endl;
		if(accounts.bad()){
			cout<<"Unable to Write in file";
			return false;
		}else{
			return true;
		}
        accounts.close(); 
        
    }  
    return true;
}
bool SignUp(){
	cout<<"\n\n\t\t\t\t\t\xb3\xB2=\xB2=\xB2-\xB3 Sign Up to Get Started! \xB3-\xB2=\xB2=\xB2\xB3\n\n"<<endl;

	string userName,email,pass,rePass;
	string a="@gmail.com";
	cout<<"\tEnter User Name: ";
	cin.ignore();
	getline(cin,userName);
	while(!ValidateUserName(userName)){
		cout<<"\tUser Name Exists, Try Another!\n";
		cout<<"\tEnter User Name: ";
	    cin.ignore();
	    getline(cin,userName);
	}
	cout<<"\tEnter Email: ";
	cin.ignore();
	getline(cin,email);
	while(!strstr(email.c_str(),a.c_str())){
		cout<<"\tInvalid Email, Try Again!\n";
		cout<<"\tEnter Email: ";
	    cin.ignore();
    	getline(cin,email);
	}
	cout<<"\tEnter Password: ";
	cin>>pass;
	cout<<"\tRe-Enter Password: ";
	cin>>rePass;
	int tries=0;
	while(rePass!=pass){
		cout<<"\tPassword Not Match!\n";
		cout<<"\tRe-Enter Password: ";
	    cin>>rePass;
	}
	if(SaveAccounts(userName,email,pass)){
		system("CLS");
		cout<<"\nSignd Up Successfully\n";
		return true;
	}	
	else{
		system("CLS");
		cout<<"\tSign Up Error!\n";
		return false;
	}
}
void Welcome(){
	cout<<"\n\n\t\t\t\t\t\xb3\xB2=\xB2=\xB2-\xB3 BASIC CRYPTOGRAPHER \xB3-\xB2=\xB2=\xB2\xB3\n\n"<<endl;
	cout<<"\t1- Log In\n";
	cout<<"\t2- Register\n";
	cout<<"\t3- Show Algorithms\n";
	cout<<"\tPress q to Quit!\n\n";
	cout<<"\tPlease Select one of the above:\t";
	
}

void ShowDashboard(){
	cout<<"\n\n\t\t\t\t\t\xb3\xB2=\xB2=\xB2-\xB3 BASIC CRYPTOGRAPHER \xB3-\xB2=\xB2=\xB2\xB3\n\n"<<endl;
	cout<<"\n\n\n\t1- Ceaser Cipher";
	cout<<"\t\t2- PlayFair Cipher\n";
	cout<<"\t3- TransPostion Cipher";
	cout<<"\t\t4- XOR Cipher\n";
	cout<<"\t5- Vigenere Cipher";
	cout<<"\t6- Log Out\n\n";
	cout<<"\tPress q to Quit!\n\n";
	cout<<"\tPlease Select Option: ";
}

