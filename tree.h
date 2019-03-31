#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct element
{
	char data;
	int amount;
	element *left, *right;
};

struct tree
{
	element *top;
	tree(element *t = 0) : top(t){}
	
	char find(const string &code);


};

bool compare(element *first, element *second);
element *min(vector <element*> el);
element *add(element *l, element *r);element *haffman_algorithm(vector< element* > &el);void infix(element *top);