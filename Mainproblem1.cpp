//Roy Anguiano
//class: csc 340
//assigment: hw1 problem 1
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <string.h>
#include <array>
#include <vector>

using namespace std;
const int ascii = 128;

void getFreqLetter (string & CuserInputToCount, int size) {
	
	char cp[ascii];
	for ( int i = 0; i < size; i++ ) {
		cp[i] = CuserInputToCount[i];
	}

	int counterArray[ascii];
	for ( int j = 0; j < 26; j++ ) {
		counterArray[j] = 0;
	}


	char myChars[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	
	char myCharss[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	for ( int i = 0; i < size; i++ ) {
		for ( int y = 0; y < 26; y++ ) {
			if ( CuserInputToCount[i] == myChars[y] )
				counterArray[y] = counterArray[y] + 1;
		}
	}

	int largeNum = 0;
	char leastchara = ' ';
	int leastnum = 9999;

	int large;
	for ( int j = 0; j < 26; j++ ) {
		if ( counterArray[j] > 0 ) {
			if ( leastnum > counterArray[j] ) {
				leastnum = counterArray[j];
				large = j;
				leastchara = myChars[j];
			}
		}
	}

	cout << "Least Number: " << leastnum << endl;

	int noLarge = 0;
	cout << "Least frequent letter is ";
	for ( int i = 0; i < 26; i++ ) {
		if ( counterArray[i] == leastnum ) {
			cout << myChars[i] << ", ";
		}
	}

	cout << "  coming out:  " << leastnum << " times" << endl;
}

struct wordFreq {
	string word;
	int count;
};

void countWordFreq (string & userInput) {
	vector<wordFreq> wordAppear (100);
	for ( int k = 0; k < 99; k++ ) {
		wordAppear[k].count = 1;
	}

	string fuserInput = userInput + " ";
	vector<string>words (100);
	int size = fuserInput.length ();
	vector<int>front (100);

	for ( int i = 0; i < 99; i++ ) {
		front[i] = 0;
	}

	vector<int>back (100);
	int i = 0; 
	while ( i < 99 ){
		back[i] = 0;
		i++;
	}

	int track = 0;
	string quote = "";

	for ( int j = 0; j <size; j++ ) {
		if ( fuserInput[j] == ' ' || fuserInput[j] == '.' || fuserInput[j] == '?' ||
			fuserInput[j] == '!' || fuserInput[j] == ',' || fuserInput[j] == ';' ) {

			back[track] = j;
			int wordLength = back[track] - front[track];
			//insert each word to words[]; 
			words[track].insert (0, userInput, front[track], wordLength);
			//stores each string into index of array with the number of times being used. ex: word="" count="1"
			wordAppear[track].word = words[track];
			//track++ keeps track of indexes
			track++;
			front[track] = back[track - 1] + 1;
		}
	}

	for ( int i = 0; i < 100; i++ ) {
		for ( int j = i + 1; j < 100; j++ ) {
			if ( (wordAppear[i].word.compare (wordAppear[j].word) == 0) && (!wordAppear[i].word.empty ()) ) {
				wordAppear[i].count = wordAppear[i].count + 1;
				wordAppear[j].word = wordAppear[99].word;
			}
		}
	}

	int largeNum = 0;
	string largestString = " ";

	
	int large;
	for ( int j = 0; j < 99; j++ ) {
		if ( largeNum < wordAppear[j].count ) {
			largeNum = wordAppear[j].count;
			large = j;
			largestString = wordAppear[j].word;
		}
	}

	int noLarge = 0;
	for ( int k = 0; k < 100; k++ ) {
		if ( largeNum == wordAppear[k].count ){
			quote = wordAppear[k].word;
		}
	}

	int oneNumber = -2;
	for ( int k = 0; k < 99; k++ ) {
		if ( !wordAppear[k].word.empty () ) {
			oneNumber++;
		}
	}

	if ( largeNum >= 1 && oneNumber > -2 && noLarge == 0 ) {
		cout << "\nMost frequent word is " << quote << " "<< largestString << " with it coming out " 
			<< largeNum << " times" << endl;
		
		for ( int i = 0; i < 100; i++ ) {
			if ( !wordAppear[i].word.empty () )
				cout << "Number of Times:  "<< wordAppear[i].count << "\nString:" << wordAppear[i].word << endl;
		}
	}
	else if ( largeNum >= 1 && noLarge > 0 && oneNumber > -1 ) {
		cout << "No frequent word since multiple words have frequency of " << largeNum << endl << endl;
		for ( int i = 0; i < 100; i++ ) {
			if ( !wordAppear[i].word.empty () )
				cout << "Count: " << wordAppear[i].count << "\nString: " << wordAppear[i].word << endl << endl;
		}
	}
}

int main () {
 
	cout << "Enter String ";
	string userInput;
	getline (cin, userInput);

	int size = userInput.length ();
	getFreqLetter (userInput, size);
	countWordFreq (userInput);

	return 0;
}