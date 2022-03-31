#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <random>
#include <time.h>
using namespace std;

struct Tree{
	vector<int> array;
	int heap_size = 0;
	int length;
}A;

void displayArray(){
	for(int i = 0; i < A.length; i++){
		cout<<A.array[i]<<" ";
	}
	cout<<"\n\n";
}

void generate(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib((-1)*A.length, A.length);
	for(int i = 0; i < A.length; i++){
		A.array.push_back(distrib(gen));
	}
}

int Parent(int i){
	return floor(i/2);
}

int Left(int i){
	return 2*i;
}

int Right(int i){
	return (2*i) + 1;
}

void swap(int i, int largest){
	int temp = A.array[i];
	A.array[i] = A.array[largest];
	A.array[largest] = temp;
}

void heapifyMaxHeap(int i){
	int left = Left(i);
	int right = Right(i);
	int largest;
	if (left <= A.heap_size && A.array[left] > A.array[i])
		largest = left;
	else
		largest = i;
	if (right <= A.heap_size && A.array[right] > A.array[largest])
		largest = right;
	if (largest != i){
		swap(i, largest);
		heapifyMaxHeap(largest);
	}
}

void buildMaxHeap(){
	A.heap_size = A.length;
	for (int i = A.length / 2; i >= 0; i--)
		heapifyMaxHeap(i);
}

void heapsort(){
	buildMaxHeap();
	for (int i = A.length; i >= 1; i--){
		swap(0, i);
		A.heap_size = A.heap_size - 1;
		heapifyMaxHeap(0);
	}
}

int main(){
	char c = 'y';
	while(c == 'y' || c == 'Y'){
		cout<<"Enter size of input array: ";
		cin>>A.length;
		generate();
		if (A.length <= 100){
			cout<<"Not sorted:\n";
			displayArray();
		}
		clock_t t = clock();
		heapsort();
		t = clock()-t;
		if (A.length <= 100){
			cout<<"Sorted:\n";
			displayArray();
		}
		cout<<"Run time of HeapSort algorithm is "<<((float)t)/CLOCKS_PER_SEC<<"(s)\n";
	}
}
