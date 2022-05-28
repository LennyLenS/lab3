#include <iostream>
#include <conio.h>
#include <string>
#include "set.hpp"

//menu for choose type of realization
int show_choose_type(int position) {
	system("cls");
	char list_menu[11][60] = { {"Add element"}, {"Delete element"}, {"Find element"} , {"Sum"}, {"Intersection"}, {"Subtraction"},
		{"Map"}, {"Reduce"}, {"Where"}, {"Print"}, {"Close app"} };
	for (int i = 0; i < 11; ++i) {
		if (i != position) {
			printf("%s\n", list_menu[i]);
		}
		else {
			printf("%s <=\n", list_menu[i]);
		}
	}
	return 0;
}

int Plus(int a) {
	return a + 10;
}

int Sum1(int a, int b) {
	return a + b;
}

bool Cond(int a) {
	return a > 5;
}
int main() {
	int position, count_list_menu = 11;
	int exit = 0;
	Set<int>* p = new Set<int>;
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
				p->add(a);
				system("pause");
			}
			if (position == 1) {
				system("cls");
				int a;
				printf("Enter element: ");
				scanf("%d", &a);
				p->delet(a);
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
				system("cls");
				int size = 0;
				printf("Enter quantity of elements: ");
				scanf("%d", &size);
				Set<int>* new_set = new Set<int>;
				for (int i = 0; i < size; ++i) {
					int a;
					printf("Enter element: ");
					scanf("%d", &a);
					new_set->add(a);
				}
				new_set->sum(p);
				new_set->Print2();
				system("pause");
			}
			if (position == 4) {
				system("cls");
				int size = 0;
				printf("Enter quantity of elements: ");
				scanf("%d", &size);
				Set<int>* new_set = new Set<int>;
				for (int i = 0; i < size; ++i) {
					int a;
					printf("Enter element: ");
					scanf("%d", &a);
					new_set->add(a);
				}
				new_set->Intersection(p);
				new_set->Print2();
				system("pause");
			}
			if (position == 5) {

			}
			if (position == 6) {
				p->map(Plus);
			}
			if (position == 7) {
				int red = p->reduce(Sum1);
				printf("Reduce = %d\n", red);
				system("pause");
			}
			if (position == 8) {
				system("cls");
				Set<int>* new_tree = p->where(Cond);
				new_tree->Print2();
				system("pause");
			}
			if (position == 9) {
				system("cls");
				std::string a = p->Print();
				std::cout << a << "\n";
				p->Print2();
				system("pause");
			}
			if (position == 10) {
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