#include "stdafx.h"
#include "infixToPostfix.h"
#include <stack>
#include <iostream>

void inToPost(char *infix,int len,char *postfix) {
	char *start = postfix;
	char e;
	std::stack<char> s;
	//��׺���ʽδ���꣬����������
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
				//������ջΪ�ջ�����������ʱ��������ջ
				s.push(inVal);
				infixIndex++;
				continue;
			}
			if (inVal == ')') {
				//����������ʱ��ջ��Ԫ�����γ�ջ��ֱ��������һ��������ʱ����

				while (s.top() != '(')
				{
					postfix[postIndex++] = s.top();
					s.pop();
				}
				s.pop();
				infixIndex++;
				continue;
			}
			//�����Ĵ���Ҫȡ����ʱ��ջ��Ԫ�أ��뵱ǰ����ķ���*mid��Ƚ�
			//����ʱջ��Ԫ�����ȼ����ڵ���������ŵ����ȼ�ʱ����ջ
			//���������ջ���Ѿ�����һ�����ǵðѵ�����Ԫ��Ҳ��ջ��
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