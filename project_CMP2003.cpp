#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "hashT.h"
#include "sorting_heap.h"
using namespace std;
int main() {

	auto start = chrono::steady_clock::now(); //gets time at the beginnig

	hashT hashTab_0;
	sorting_heap hashSort_0;

	fstream input_File;
	string word;
	bool body_tag = false;

	fstream stop_File;
	string stopW;

	for (int j = 0; j <= 21; j++) {
		if (j <= 9) {
			string file_name = "reut2-00" + to_string(j) + ".sgm";
			input_File.open(file_name, ios::in);
		}
		else {
			string file_name = "reut2-0" + to_string(j) + ".sgm";
			input_File.open(file_name, ios::in);
		}
		if (!input_File) {
			cout << "Unable to open file.";
			exit(1);
		}
		else {
			while (input_File >> word) {
				if (word.find("<BODY>") != string::npos) {
					body_tag = true; //tag opened
					int b = word.find("<BODY>") + 6;
					word.erase(0, b); //deletes until body tag
				}
				else if (word.find("</BODY>") != string::npos) {
					body_tag = false; //tag closed
				}
				if (body_tag == true) {
					if (word.find("/") != string::npos || word.find("-") != string::npos) {
						for (int i = 0, stringSize = word.size(); i < stringSize; i++) { //checks words that will be seperated with "-" or "/" 
							if (word[i] == '/' || word[i] == '-') {
								word[i] = ' ';
								string tempWord;
								int post = word.find(" ");
								tempWord = word.substr(post + 1);
								for (int i = 0, stringSize = tempWord.size(); i < stringSize; i++) {
									tempWord[i] = tolower(tempWord[i]);
									if (ispunct(tempWord[i])) {
										tempWord.erase(i--, 1);
										stringSize = tempWord.size();
									}
									else if (isdigit(tempWord[i])) {
										tempWord.erase(i--, 1);
										stringSize = tempWord.size();
									}
								}
								hashTab_0.insert(tempWord);
								word = word.erase(i, word.length());
								stringSize = word.length();
							}
						}
					}
					for (int i = 0, stringSize = word.size(); i < stringSize; i++) {
						word[i] = tolower(word[i]); //changes letters to lower-case
						if (ispunct(word[i])) { //removes punctuation
							word.erase(i--, 1);
							stringSize = word.size();
						}
						else if (isdigit(word[i])) { //removes digit
							word.erase(i--, 1);
							stringSize = word.size();
						}
					}
					hashTab_0.insert(word);
				}
			}

		}
		input_File.close();
	}

	stop_File.open("stopwords.txt", ios::in);
	while (getline(stop_File, stopW, ' '))
	{
		for (int i = 0, stringSize = stopW.size(); i < stringSize; i++) { //arranges stopwords
			stopW[i] = tolower(stopW[i]);
			if (ispunct(stopW[i])) {
				stopW.erase(i--, 1);
				stringSize = stopW.size();
			}
		}
	}

	hashSort_0.heapSortingAll(hashTab_0, stopW);

	auto end = chrono::steady_clock::now(); //gets time at the end
	cout << "Total Elapsed Time: "
		<< chrono::duration_cast<chrono::seconds>(end - start).count() //substract the times
		<< " seconds " << chrono::duration_cast<chrono::milliseconds>(end - start).count() % 1000 << " miliseconds" << endl;
	//1000ms = 1 sec

	return 0;
}