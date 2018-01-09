/*
ID: insidia1
PROB: gift1
LANG: C++11                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int searchFriend(string[], int, string);

int main(int argc, char** argv) {
    ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");
	
	string friends[100];
	int accounts[100];
	int i, r, amt, split, gift;
	string giver, rcvr;
	
	int NP;
	fin >> NP;
	
	for(i = 0; i < NP; i++) {
		fin>>friends[i];
		accounts[i] = 0;
		//cout << friends[i] << '\t';
	}
	
	bool done = false;
	while(!done) {
		fin >> giver;
		i = searchFriend(friends, NP, giver);
		
		//fin >> amt;
		if (fin >> amt) {
			if(fin >> split && split > 0) {
				gift = amt / split;
				accounts[i] -= (amt - (amt % split ));
			
				//cout << friends[i] << " splits " << amt << " between ";
				for(int j = 0; j < split; j++) {
					fin >> rcvr;
					r = searchFriend(friends, NP, rcvr);
					accounts[r] += gift;
					//cout << rcvr << ", ";
				}
				//cout << endl;
				//for(i = 0; i < NP; i++) {
				//	cout << friends[i] << " " << accounts[i] << endl;
				//}
			}
		} else {
			done = true;
		}
	}
	
	for(i = 0; i < NP; i++) {
		fout << friends[i] << " " << accounts[i] << endl;
	}
	return 0;
}

int searchFriend(string friends[], int NP, string person) {
	int i;
	for(i = 0; i < NP; i++) {
			if(friends[i] == person)
				break;
		}
	return i;
}
