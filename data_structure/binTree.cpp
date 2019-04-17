#include "binTree.h"
#include <iostream>
#include <stack>

//先序遍历，递归版
void travPre_R(binNode *x) {
	std::cout << x->data << std::endl;
	travPre_R(x->lc);
	travPre_R(x->rc);
}

//中序遍历，递归版
void travIn_R(binNode *x) {
	travIn_R(x->lc);
	std::cout << x->data << std::endl;
	travIn_R(x->rc);
}

//后序遍历，递归版
void travPost_R(binNode *x) {
	travPost_R(x->lc);
	travPost_R(x->rc);
	std::cout << x->data << std::endl;
}

void travPre_I(binNode *x) {
	std::stack<binNode*> s;
	while (true) {
		while (x) {
			std::cout << x->data << std::endl;
			s.push(x->rc);
			x = x -> lc;
		}
		if (s.empty()) break;
		x = s.top();
		s.pop();
	}
}

void travIn_I(binNode *x) {
	std::stack<binNode*> s;
	while (true) {
		while (x) { s.push(x); x = x->lc; }
		if (s.empty()) {
			break;
		}
		x = s.top();
		s.pop();
		std::cout << x->data << std::endl;
		x = x->rc;
	}
}

void gotoHLVFL(std::stack<binNode*>& s) {
	while (binNode* x = s.top()) {
		if (x->lc) {
			if (x->rc) s.push(x->rc);
			s.push(x->lc);
		}
		else {
			s.push(x->rc);
		}
	}
	s.pop();	//栈顶必然加入了一个空节点，要pop出来
}

void travPost_I(binNode* x) {
	std::stack<binNode*> s;
	if (x) s.push(x);
	while (!s.empty()) {
		if (s.top() != x->parent)
			gotoHLVFL(s);	//最高左侧可见叶节点
		x = s.top();
		s.pop();
		std::cout << x->data << std::endl;
	}
}


