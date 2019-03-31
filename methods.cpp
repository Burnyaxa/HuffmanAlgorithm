#include "tree.h"

bool compare(element *first, element *second){
	return first->amount < second->amount;
}
element *min(vector <element*> el){
	element *min = el[0];
	unsigned int erase_position = 0;
	for (unsigned int i = 1; i < el.size(); i++)
		if (!compare(min, el[i]))
		{
			min = el[i];
			erase_position = i;
		}
	el.erase(el.begin() + erase_position);
	return min;
}

element *add(element *l, element *r){
	element *new_top = new element;
	new_top->amount = l->amount + r->amount;
	if (compare(l, r))
	{
		new_top->left = l;
		new_top->right = r;
	}
	else
	{
		new_top->left = r;
		new_top->right = l;
	}
	return new_top;
}

char tree::find(const string &code){
	element *p = this->top;
	for (int i = 0; p, i < code.length(); i++)
		if (code[i] == '0')
			p = p->left;
		else if (code[i] == '1')
			p = p->right;
		else exit(1);
		if (!p || p->left || p->right) return '\0';
		return p->data;
}

element *haffman_algorithm(vector< element* > &el){
	while (el.size() > 1)
		el.insert(el.begin(), add(min(el), min(el)));
	return el[0];
}

void infix(element *top)
{
	if (!top) return;
	infix(top->left);
	if (!(top->left && top->right))
		cout << top->data << " ";
	infix(top->right);
}