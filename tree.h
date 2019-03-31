#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct element
{
	char data;
	int amount;
	element *left, *right;
	element(char value = '\0', int am = 0) : left(NULL),right(NULL), data(value), amount(am) {}
};

struct tree
{
	element *top;
	tree(element* t = 0) : top(t){}
	
	char find(const string &code);


};

struct letter;

bool compare(element *first, element *second);
element *min(vector <element*> el);
element *add(element *l, element *r);
element *haffman_algorithm(vector< element* > &el);
void infix(element *top);
int height(tree b);
vector <element*> getElements(vector<letter> table);
