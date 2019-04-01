#include "tree.h"
#include "fileMethods.h"

void sort_table(vector<element*> &elements) {
	for (int i = 0; i < elements.size(); i++) {
		for (int j = i; j < elements.size(); j++) {
			if (elements[j]->amount > elements[i]->amount) {
				element *temp = new element;
				temp = elements[j];
				elements[j] = elements[i];
				elements[i] = temp;
			}
		}
	}
}

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
	while (el.size() > 1) {
		element *root = new element;
		root->amount = 0;
		root->right = el.back();
		root->amount += el.back()->amount;
		el.pop_back();
		root->left = el.back();
		root->amount += el.back()->amount;
		el.pop_back();
		el.push_back(root);
		sort_table(el);
	}
	return el[0];
}

void infix(element *top)
{
	if (!top) return;
	infix(top->left);
	if (!(top->left && top->right))
		cout << top->data <<" "<<top->code << endl;
	infix(top->right);
}
void prefix(element *top)
{
	if (!top) return;
	cout << top->data << " ";
	infix(top->left);
	infix(top->right);
}

int height(tree b) {
	element *p = b.top;
	if (p == NULL) {
		return -1;
	}

	int lefth = height(p->left);
	int righth = height(p->right);

	if (lefth > righth) {
		return lefth + 1;
	}
	else {
		return righth + 1;
	}
}

vector <element*> getElements(vector<letter> table){
	vector <element*> elements(table.size());
	for (int i = 0; i < table.size(); i++){
		elements[i]= new element(table[i].symbol, table[i].frequency);
	}
	return elements;
}


void traverse(element *node, string code)
{
	if (node->left == NULL && node->right == NULL)
	{
		node->code = code;
	}
	else
	{
		traverse(node->left, code + '0');
		traverse(node->right, code + '1');
	}
}

void calculate_huffman_codes(element *root)
{
	traverse(root, "");
}
