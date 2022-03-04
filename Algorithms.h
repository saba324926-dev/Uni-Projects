#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <bits/stdc++.h>
#include<ctype.h>

using namespace std;
   /*
   
          Ceaser Cipher
   
    */
string ECeaserCipher(string msg,int key){
    char ch;
      for(int i = 0; msg[i] != '\0'; ++i) {
         ch = msg[i];
         //encrypt for lowercase letter
         if (ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if (ch > 'z') {
               ch = ch - 'z' + 'a' - 1;
            }  
            msg[i] = ch;
         }
         //encrypt for uppercase letter
         else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if (ch > 'Z'){
               ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
         }
      }

   
   return msg;
}
string DCeaserCipher(string msg,int key){
    char ch;
      for(int i = 0; msg[i] != '\0'; ++i) {
         ch = msg[i];
         //decrypt for lowercase letter
         if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a'){
               ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
         }
         //decrypt for uppercase letter
         else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
               ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
         }
      }
      return msg;
   }
   /* 
   
           Play Fair Cipher
   
   */
static int Mod(int a, int b)
{
	return (a % b + b) % b;
}

static char** Create2DArray(int rowCount, int colCount) {
	char** arr = new char*[rowCount];

	for (int i = 0; i < rowCount; ++i)
		arr[i] = new char[colCount];

	return arr;
}

static string ToUpper(string str) {
	string output = str;
	int strLen = str.size();

	for (int i = 0; i < strLen; ++i)
		output[i] = toupper(output[i]);

	return output;
}

static string RemoveChar(string str, char ch) {
	string output = str;

	for (int i = 0; i < output.size(); ++i)
		if (output[i] == ch)
			output = output.erase(i, 1);

	return output;
}

static vector<int> FindAllOccurrences(string str, char value)
{
	vector<int> indexes;

	int index = 0;
	while ((index = str.find(value, index)) != -1)
		indexes.push_back(index++);

	return indexes;
}

static string RemoveAllDuplicates(string str, vector<int> indexes)
{
	string retVal = str;

	for (int i = indexes.size() - 1; i >= 1; i--)
		retVal = retVal.erase(indexes[i], 1);

	return retVal;
}

static char** GenerateKeySquare(string key)
{
	char** keySquare = Create2DArray(5, 5);
	string defaultKeySquare = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	string tempKey = key.empty() ? "CIPHER" : ToUpper(key);

	tempKey = RemoveChar(tempKey, 'J');
	tempKey += defaultKeySquare;

	for (int i = 0; i < 25; ++i)
	{
		vector<int> indexes = FindAllOccurrences(tempKey, defaultKeySquare[i]);
		tempKey = RemoveAllDuplicates(tempKey, indexes);
	}

	tempKey = tempKey.substr(0, 25);

	for (int i = 0; i < 25; ++i)
		keySquare[(i / 5)][(i % 5)] = tempKey[i];

	return keySquare;
}

static void GetPosition(char** keySquare, char ch, int* row, int* col)
{
	if (ch == 'J')
		GetPosition(keySquare, 'I', row, col);

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (keySquare[i][j] == ch)
			{
				*row = i;
				*col = j;
				return;
			}
}

static char* SameRow(char** keySquare, int row, int col1, int col2, int encipher)
{
	return new char[2] { keySquare[row][Mod((col1 + encipher), 5)], keySquare[row][Mod((col2 + encipher), 5)] };
}

static char* SameColumn(char** keySquare, int col, int row1, int row2, int encipher)
{
	return new char[2] { keySquare[Mod((row1 + encipher), 5)][col], keySquare[Mod((row2 + encipher), 5)][col] };
}

static char* SameRowColumn(char** keySquare, int row, int col, int encipher)
{
	return new char[2] { keySquare[Mod((row + encipher), 5)][Mod((col + encipher), 5)], keySquare[Mod((row + encipher), 5)][Mod((col + encipher), 5)] };
}

static char* DifferentRowColumn(char** keySquare, int row1, int col1, int row2, int col2)
{
	return new char[2] { keySquare[row1][col2], keySquare[row2][col1] };
}

static string RemoveOtherChars(string input)
{
	string output = input;
	int strLen = input.size();

	for (int i = 0; i < strLen; ++i)
		if (!isalpha(output[i]))
			output = output.erase(i, 1);

	return output;
}

static string AdjustOutput(string input, string output)
{
	string retVal = output;
	int strLen = input.size();

	for (int i = 0; i < strLen; ++i)
	{
		if (!isalpha(input[i]))
			retVal = retVal.insert(i, 1, input[i]);

		if (islower(input[i]))
			retVal[i] = tolower(retVal[i]);
	}

	return retVal;
}

static string PlayfairCipher(string input, string key, bool encipher)
{
	string retVal = "";
	char** keySquare = GenerateKeySquare(key);
	string tempInput = RemoveOtherChars(input);
	int e = encipher ? 1 : -1;
	int tempInputLen = tempInput.size();

	if ((tempInputLen % 2) != 0)
		tempInput += "X";

	for (int i = 0; i < tempInputLen; i += 2)
	{
		int row1 = 0;
		int col1 = 0;
		int row2 = 0;
		int col2 = 0;

		GetPosition(keySquare, toupper(tempInput[i]), &row1, &col1);
		GetPosition(keySquare, toupper(tempInput[i + 1]), &row2, &col2);

		if (row1 == row2 && col1 == col2)
		{
			retVal += string(SameRowColumn(keySquare, row1, col1, e), 2);
		}
		else if (row1 == row2)
		{
			retVal += string(SameRow(keySquare, row1, col1, col2, e), 2);
		}
		else if (col1 == col2)
		{
			retVal += string(SameColumn(keySquare, col1, row1, row2, e), 2);
		}
		else
		{
			retVal += string(DifferentRowColumn(keySquare, row1, col1, row2, col2), 2);
		}
	}

	retVal = AdjustOutput(input, retVal);

	return retVal;
}

static string EPlayfairCipher(string input, string key)
{
	return PlayfairCipher(input, key, true);
}

static string DPlayfairCipher(string input, string key)
{
	return PlayfairCipher(input, key, false);
}
/*

                  Transpostion Cipher


*/

string const key = "HACK"; 
map<int,int> keyMap;
  
void setPermutationOrder()
{             
    // Add the permutation order into map 
    for(int i=0; i < key.length(); i++)
    {
        keyMap[key[i]] = i;
    }
}
  
// Encryption 
string ETranspostionCipher(string msg)
{
    int row,col,j;
    string cipher = "";
      
    /* calculate column of the matrix*/
    col = key.length(); 
      
    /* calculate Maximum row of the matrix*/
    row = msg.length()/col; 
      
    if (msg.length() % col)
        row += 1;
  
    char matrix[row][col];
  
    for (int i=0,k=0; i < row; i++)
    {
        for (int j=0; j<col; )
        {
            if(msg[k] == '\0')
            {
                /* Adding the padding character '_' */
                matrix[i][j] = '_';     
                j++;
            }
              
            if( isalpha(msg[k]) || msg[k]==' ')
            { 
                /* Adding only space and alphabet into matrix*/
                matrix[i][j] = msg[k];
                j++;
            }
            k++;
        }
    }
  
    for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
    {
        j=ii->second;
          
        // getting cipher text from matrix column wise using permuted key
        for (int i=0; i<row; i++)
        {
            if( isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]=='_')
                cipher += matrix[i][j];
        }
    }
  
    return cipher;
}
  
// Decryption 
string DTranspostionCipher(string cipher)
{
    /* calculate row and column for cipher Matrix */
    int col = key.length();
  
    int row = cipher.length()/col;
    char cipherMat[row][col];
  
    /* add character into matrix column wise */
    for (int j=0,k=0; j<col; j++)
        for (int i=0; i<row; i++)
            cipherMat[i][j] = cipher[k++];
  
    /* update the order of key for decryption */
    int index = 0;
    for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
        ii->second = index++;
  
    /* Arrange the matrix column wise according 
    to permutation order by adding into new matrix */
    char decCipher[row][col];
    map<int,int>::iterator ii=keyMap.begin();
    int k = 0;
    for (int l=0,j; key[l]!='\0'; k++)
    {
        j = keyMap[key[l++]];
        for (int i=0; i<row; i++)
        {
            decCipher[i][k]=cipherMat[i][j];
        }
    }
  
    /* getting Message using matrix */
    string msg = "";
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(decCipher[i][j] != '_')
                msg += decCipher[i][j];
        }
    }
    return msg;
}
  
  /*
  
                
                
                
                XOR Cipher
  
  
  */
  
  static string XORCipher(string data, string key) {
	int dataLen = data.size();
	int keyLen = key.size();
	string output = data;

	for (int i = 0; i < dataLen; ++i) {
		output[i] = data[i] ^ key[i % keyLen];
	}

	return output;
}

/*

                Vigenere Cipher

*/

string generateKey(string str, string key)
{
    int x = str.size();
 
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}
 
// This function returns the encrypted text
// generated with the help of the key
string EVigenereCipher(string str, string key)
{
    string cipher_text;
 
    for (int i = 0; i < str.size(); i++)
    {
        // converting in range 0-25
        char x = (str[i] + key[i]) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
 
        cipher_text.push_back(x);
    }
    return cipher_text;
}
 
// This function decrypts the encrypted text
// and returns the original text
string DVigenereCipher(string cipher_text, string key)
{
    string orig_text;
 
    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        // converting in range 0-25
        char x = (cipher_text[i] - key[i] + 26) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}
 
