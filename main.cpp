#include "fileMethods.h"
#include "tree.h"

void main(){
	tree t;
	vector <string> text = getText();
	print(text);
	vector <letter> frequencyTable = getLetters(text);
	printTable(frequencyTable);
	vector <element*> elements = getElements(frequencyTable);
	
	t.top = haffman_algorithm(elements);
	cout << endl;
	calculate_huffman_codes(t.top);
	infix(t.top);
	
	cout << "Height= " << height(t) << endl;
	
	system("pause");
}
