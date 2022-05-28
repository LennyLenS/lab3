#ifndef BINHEAP_HPP
#define BINHEAP_HPP
#include <vector>
#include <iostream>
#include <string>

template<typename Type>
class Heap {
private:
	static const int SIZE = 100;
	std::vector<Type> h;
	int HeapSize;
	std::string heapstr(int i);
public:
	Heap() {
		h = std::vector<Type>();
		this->HeapSize = 0;
	}
	void addelem(Type n);
	std::string outHeap();
	void out();
	int getmax(); 
	void heapify(Type); 
	bool find(Type k);
	Heap<Type>* buildheap(Type k) {
		Heap<Type>* n_heap = new Heap<Type>();
		int ind = 0;
		for (int i = 0; i < this->HeapSize; ++i) {
			if (this->h[i] == k) {
				ind = i;
				break;
			}
		}
		std::vector<Type> vec;
		nodebuildheap(vec, ind);
		for (int i = 0; i < vec.size(); ++i) {
			n_heap->addelem(vec[i]);
		}
		return n_heap;
	}

	int nodebuildheap(std::vector<Type>&vec, int ind) {
		if (ind >= HeapSize) {
			return 0;
		}
		vec.push_back(this->h[ind]);
		nodebuildheap(vec, ind * 2 + 1);
		nodebuildheap(vec, ind * 2 + 2);
		return 0;
	}
};

template<typename Type>
void Heap<Type>::addelem(Type n) {
	int i, parent;
	i = this->HeapSize;
	this->h.push_back(n);
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (this->h[i] > this->h[parent]) {
			int temp = this->h[i];
			this->h[i] = this->h[parent];
			this->h[parent] = temp;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	this->HeapSize++;
}

template<typename Type>
std::string Heap<Type>::heapstr(int i) {
	if (i < this->HeapSize) {
		return "( " + heapstr(i * 2 + 1) + std::to_string(this->h[i]) + heapstr(i * 2 + 2) + " )";
	}
	else {
		return "(null)";
	}
}

template<typename Type>
std::string Heap<Type>::outHeap() {
	int i = 0;
	int k = 1;
	std::string ans = "";
	return heapstr(0);
}

template<typename Type>
void Heap<Type>::out() {
	int i = 0;
	int k = 1;
	while (i < this->HeapSize) {
		while ((i < k) && (i < this->HeapSize)) {
			std::cout << this->h[i] << " ";
			i++;
		}
		std::cout << "\n";
		k = k * 2 + 1;
	}
}

template<typename Type>
void Heap<Type>::heapify(Type i) {
	int left, right;
	int temp;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < HeapSize) {
		if (this->h[i] < this->h[left]) {
			temp = this->h[i];
			this->h[i] = this->h[left];
			this->h[left] = temp;
			heapify(left);
		}
	}
	if (right < HeapSize) {
		if (this->h[i] < this->h[right]) {
			temp = this->h[i];
			this->h[i] = this->h[right];
			this->h[right] = temp;
			heapify(right);
		}
	}
}

template<typename Type>
int Heap<Type>::getmax() {
	int x;
	x = this->h[0];
	this->h[0] = this->h[HeapSize - 1];
	this->HeapSize = this->HeapSize - 1;
	heapify(0);
	this->h.pop_back();
	return(x);
}

template<typename Type>
bool Heap<Type>::find(Type k) {
	for (int i = 0; i < this->HeapSize; ++i) {
		if (this->h[i] == k) {
			return true;
		}
	}
	return false;
}
#endif