#include "fileMethods.h"
#include "tree.h"

void main(){
	tree t;
	vector <string> text = getText();
	print(text);
	vector <letter> frequencyTable = getLetters(text);
	printTable(frequencyTable);
	vector <element*> elements = getElements(frequencyTable);
	//t.top = haffman_algorithm(elements);
	system("pause");
}