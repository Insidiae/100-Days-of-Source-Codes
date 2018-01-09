/*
ID: insidia1
PROB: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int encode(string);

int main(int argc, char** argv) {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    string str1, str2;
    
    fin >> str1 >> str2;
    
    
    if(encode(str1) == encode(str2)) {
    	fout << "GO" << endl;
	} else {
		fout << "STAY" << endl;
	}
	
	return 0;
}

int encode(string str) {
	string alphabet = "~ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int mult = 1;
	for (int i = 0; i < str.length(); i++) {
		mult *= alphabet.find(str[i]);
	}
	
	return mult % 47;
}
