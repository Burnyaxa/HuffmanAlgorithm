#include "fileMethods.h"
#include "tree.h"

void main(){
	vector <string> text = getText();
	print(text);
	vector <letter> frequencyTable = getLetters(text);
	printTable(frequencyTable);
	system("pause");
}