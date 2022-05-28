#include <iostream>
#include <conio.h>
#include <string>
#include "binheap.hpp"

//menu for choose type of realization
int show_choose_type(int position) {
	system("cls");
	char list_menu[7][60] = { {"Add element"}, {"Get max element"}, {"Find element"} , {"Find subtree"}, {"Build subtree"},
		{"Print"}, {"Close app"} };
	for (int i = 0; i < 7; ++i) {
		if (i != position) {
			printf("%s\n", list_menu[i]);
		}
		else {
			printf("%s <=\n", list_menu[i]);
		}
	}
	return 0;
}

int main() {
	int position, count_list_menu = 7;
	int exit = 0;
	Heap<int>* p = new Heap<int>;
	show_choose_type(position);
	do {
		int key = 0;
		key = _getch();
		switch (key) {
		case(72): //up
		{
			position -= 1;
			if (position == -1) {
				position = count_list_menu - 1;
			}
			show_choose_type(position);
			break;
		}
		case(80): //down
		{
			position += 1;
			if (position == count_list_menu) {
				position = 0;
			}
			show_choose_type(position);
			break;
		}
		case(13):
		{
			if (position == 0) {
				system("cls");
				int a;
				printf("Enter element: ");
				scanf("%d", &a);
				p->addelem(a);
				system("pause");
			}
			if (position == 1) {
				system("cls");
				int a = p->getmax();
				printf("Max element = %d", a);
				system("pause");
			}
			if (position == 2) {
				system("cls");
				int a;
				printf("Enter element: ");
				scanf("%d", &a);
				bool flag = p->find(a);
				if (flag) {
					printf("Element is found\n");
				}
				else {
					printf("Element isnt found\n");
				}
				system("pause");
			}
			if (position == 3) {
				/*
				system("cls");
				int size = 0;
				printf("Enter quantity of elements: ");
				scanf("%d", &size);
				AVL<int>* new_tree = new AVL<int>;
				for (int i = 0; i < size; ++i) {
					int a;
					printf("Enter element: ");
					scanf("%d", &a);
					new_tree->add(a);
				}
				if (p->findsubtree(new_tree)) {
					printf("Subtree is found\n");
				}
				else {
					printf("Subtree is not found\n");
				}
				system("pause");
				*/
			}
			if (position == 4) {
				system("cls");
				int a;
				printf("Enter element: ");
				scanf("%d", &a);
				Heap<int>* new_tree = p->buildheap(a);
				new_tree->out();
				system("pause");
			}
			if (position == 5) {
				system("cls");
				std::string a = p->outHeap();
				std::cout << a << "\n";
				p->out();
				system("pause");
			}
			if (position == 6) {
				exit = 1;
				system("cls");
				printf("Good bye!\n");
				break;
			}
			show_choose_type(position);
			break;
		}
		}
	} while (exit == 0);
}