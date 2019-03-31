#include "fileMethods.h"
#include "tree.h"

void main(){
	tree t;
	vector <string> text = getText();
	print(text);
	vector <letter> frequencyTable = getLetters(text);
	printTable(frequencyTable);
	vector <element*> elements = getElements(frequencyTable);
	for (int i = 0; i < elements.size(); i++) {
		for (int j = i; j < elements.size(); j++) {
			if (elements[j]->amount < elements[i]->amount) {
				element *temp = new element;
				temp = elements[j];
				elements[j] = elements[i];
				elements[i] = temp;
			}
		}
	}
	t.top = haffman_algorithm(elements);
	cout << endl;
	infix(t.top);
	system("pause");
}
