#include "stdafx.h"
#include "infixToPostfix.h"
#include <stack>
#include <iostream>

void inToPost(char *infix,int len,char *postfix) {
	char *start = postfix;
	char e;
	std::stack<char> s;
	//中缀表达式未读完，则连续处理
	int infixIndex = 0;
	int postIndex = 0;
	while (infixIndex < len) {
		char inVal = infix[infixIndex];
		if (infix[infixIndex] >= '0' && infix[infixIndex] <= '9') {
			postfix[postIndex++] = infix[infixIndex++];
			continue;
		}
		else if (inVal == '+' || inVal == '-' || inVal == '*' || inVal == '/' || inVal == '(' || inVal == ')') {
			if (s.empty() || inVal == '(') {
				//当符号栈为空或遇到左括号时，符号入栈
				s.push(inVal);
				infixIndex++;
				continue;
			}
			if (inVal == ')') {
				//遇到右括号时，栈顶元素依次出栈；直到遇到第一个左括号时结束

				while (s.top() != '(')
				{
					postfix[postIndex++] = s.top();
					s.pop();
				}
				s.pop();
				infixIndex++;
				continue;
			}
			//后续的处理都要取出临时的栈顶元素，与当前输入的符号*mid相比较
			//当临时栈顶元素优先级大于等于输入符号的优先级时，出栈
			//否则符号入栈（已经弹出一个，记得把弹出的元素也入栈）
			e = s.top();
			s.pop();
			if (inVal == '+' || inVal == '-') {
				if (e == '(') {
					s.push(inVal);
					infixIndex++;
					continue;
				}
				else {
					postfix[postIndex++] = e;
					s.push(inVal);
					infixIndex++;
					continue;
				}
			}
			else if (inVal == '*' || inVal == '/') {
				if ('*' == e || '/' == e) {
					postfix[postIndex++] = e;
					s.push(inVal);
					infixIndex++;
					continue;
				}
				else {
					s.push(e);
					s.push(inVal);
					infixIndex++;
					continue;
				}
			}
			
		}
		else {
			break;
		}
	}
	while (!s.empty()) {
		postfix[postIndex++] = s.top();
		s.pop();
	}
	postfix[postIndex] = '\0';
}