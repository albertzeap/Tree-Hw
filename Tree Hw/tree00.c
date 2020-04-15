//Section 6.5 Trees
//Albert Paez

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode tnode;
struct tnode {
	const char* word;
	int count;
	tnode* left;
	tnode* right;
};

typdef struct tree tree;
struct tree {
	tnode* root;
	size_t size;
};

int getword(const char*, int);


//tnode* talloc(void);
//void treeprint(tnode*);
//tnode* addtree(tnode*, const char*);

//Written as a node constuctor
tnode* tnode_create(const char* word) {
	tnode* p;
	p = (tnode*)malloc(sizeof(tnode));
	p->word = strdup(word);
	p->count = 1;
	p->left = p->right = NULL;
	return p;
}

tnode* tree_create(void) {
	tree * p = (tree*)malloc(sizeof(tree));
	p->root = NULL:
	p->size = 0;

	return p;
}

bool tree_empty(tree* t) { return t->size == 0; }
size_t tree_size(tree*)  { return t->size;     }


//IN ORDER L me R --do this first
//PRE ORDER: ME L R
//POST ORDER: L R ME
//LEVEL ORDER: all parent then children then grandchildren
static void tree_printnode(tree*, tnode* p){
	if (p == NULL) { return; }

	tree_printnode(t, p->left);
	printf("%s -- %d -- (%p, %p)\n,", p->word, p->count, p->left, p->right);
	tree_printnode(t, p->right);
}
void tree_print(tree* t) { tree_printnode(t, t->root); };


tnode* tree_addnode(tree*, const char*) {
	int cond;
	
	if (p == NULL) {
		p = tnode_create(w);
	} else if ((cond = strcmp(w, p->word)) == 0) { p->count++; }
	else if (cond < 0) { p->left = tree_addnode(t, p->left w; }
	else { 
		p->right = tree_addnode(t,p->right,w);
	}

	return p;
}

tnode tree_add(tree*, const char* w) { 
	return tree_addnode(t, t->root, w);
}

int main(int argc, const char* argv[]) {
	tree * t = tree_create();
	tree_add(t, "now");
	tree_add(t, "is");
	tree_add(t, "the");
	tree_add(t, "time");

	tree_print(t);
	printf("Is my tree empty? %d\n", tree_empty(t));
}
