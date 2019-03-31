#include "fileMethods.h"

vector <string> getText(){
	vector <string> text;
	string row;
	ifstream input("text.txt");
	while (input.good()){
		getline(input, row);
		text.push_back(row);
		row.clear();
	}
	input.close();
	return text;
}

void print(vector <string> text){
	for (int i = 0; i < text.size(); i++){
		cout << text[i] << endl;
	}
}