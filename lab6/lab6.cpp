#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Course requirement - prints my own name on the console
void printMyName()
{
	cout << "MADE BY GREGORY BRISEBOIS" << endl;
	cout << "CS116 OHLONE COLLEGE" << endl;
	cout << "-------------------------" << endl;
}

// Asks the user for the filename to analyze
// @return - the string of the filename
string getFilename()
{
	string inFilename = "";
	cout << "Please enter the name of the file: ";
	cin >> inFilename;
	return inFilename;
	//return "file.txt";
}

// Checks if the specified file is readable
// @param filename - name of file
// @return - true if readable
bool fileExists(string filename)
{
	ifstream file(filename.c_str());
	return file.good();
}

// Warns that the file was not found
void printFileAccessError()
{
	cout << "Error: the specified file does not exist or is being used by another program!" << endl;
}

// Get the number of words in a one-line string.
// @return - number of words
int getWordsFromString(string line)
{
	int numWords = 0;
	char lastChar = ' ';
	
	for(int i = 0; i < line.length(); i++)
	{		
		// We know we are going on to a new word if the previous character was a space, but the
		// current character is a digit or a number.
		if((lastChar == ' ' || lastChar == '\t') && (isalpha(line[i]) || isdigit(line[i]))) numWords++;
		
		lastChar = line[i];
	}
	
	return numWords;
}

// Analyzes the given file and passes the results by reference
// @param fileStream - the filestream we are going to analyze
// @param numCharacters - number of characters
// @param numLines - number of lines
// @param numSpaces - number of spaces
// @param numAlphabet - number of alphabetical characters
// @param numDigits - number of numerical digits
// @param numWords - number of complete words, including numbers; no special characters
void getFileInfo(ifstream& fileStream, int& numCharacters, int& numLines, int& numSpaces, int& numAlphabet, int& numDigits, int& numWords)
{
	// temp to store our current line
	string line = "";
	
	// Analyze each line of the file separately
	while(getline(fileStream, line))
	{
		numCharacters += line.length();
		numLines++;
		
		for(int i = 0; i < line.length(); i++)
		{
			// Count spaces and tabs
			if(line[i] == ' ' || line[i] == '\t') numSpaces++;
			
			// Count numerical digits
			if(isdigit(line[i])) numDigits++;
			
			// Count alphabetical characters
			if(isalpha(line[i])) numAlphabet++;
		}
		
		// Count words in the line
		numWords += getWordsFromString(line);
	}
	
	// Add on a linebreak for each line, -1:
	numCharacters += numLines - 1;
}

// Prints out the file info, which it gets from getFileInfo
// @param filename - name of file to print info from
void printFileInfo(string filename)
{
	ifstream fileStream(filename.c_str());
	
	if(!fileStream.good()){ printFileAccessError(); return; }
	
	int numCharacters = 0, numLines = 0, numSpaces = 0, numAlphabet = 0, numDigits = 0, numWords = 0;
	
	getFileInfo(fileStream, numCharacters, numLines, numSpaces, numAlphabet, numDigits, numWords);
	
	cout << "Characters: " << numCharacters << endl;
	cout << "Lines: " << numLines << endl;
	cout << "Spaces and tabs: " << numSpaces << endl;
	cout << "Digits: " << numDigits << endl;
	cout << "Alphabet: " << numAlphabet << endl;
	cout << "Words: " << numWords << endl;
	
}

int main()
{
	printMyName();
	
	bool loop = true;
	do
	{
		string filename = getFilename();
		
		if(fileExists(filename))
		{
			printFileInfo(filename);
		}
		else
		{
			printFileAccessError();
			loop = false;
		}
	}
	while(loop);
}



















