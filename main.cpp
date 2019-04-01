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
	vector<node_with_code*> code_string;
	create_table_with_code(t.top, code_string);
	codding_text(code_string, text);
	cout << "Height= " << height(t) << endl;
	
	system("pause");
}
