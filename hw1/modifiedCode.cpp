#include <iostream>
#include <algorithm>
#include <time.h>
#include <iomanip>
#include <climits>//for INT_MAX
#include <fstream>
#include <vector>
using namespace std;

void display(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return;
}

void generateRandomInput(int a[], int n){//assume it is average case
	int j = 1;
	for (int i = 0; i < n; i++){
		a[i] = j++;
	}

	random_shuffle(a, a+n);
	return;
}

void generateWorstCaseInput(int (&a)[],int n){
	int j = n;
	for (int i = 0; i < n; i++){
		a[i] = j--;
	}
	return;
}

void generateBestCaseInput(int (&a)[],int n){
	int j = 1;
	for (int i = 0; i < n; i++){
		a[i] = j++;
	}
	return;
}

void InsertionSort(int a[], int n){
	for (int i = 1; i < n; i++){
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	
	return;
}

void merge(int A[], int p, int q, int r){
        int n1 = q - p;
        int n2 = r - q;
        int L[n1+1];
        int R[n2+1];

        int j = 0;
        for(int i = p; i < q; i++){
                L[j] = A[i];
                j++;
        }
        j = 0;
        for(int i = q; i < r; i++){
                R[j] = A[i];
                j++;
        }
        L[n1] = INT_MAX;
        R[n2] = INT_MAX;

        j = 0;
        int l = 0;
        for(int i = p; i < r; i++){
                if (L[j] < R[l]){
                        A[i] = L[j];
                        j++;
                }
                else{
                        A[i] = R[l];
                        l++;
                }
        }
}

void mergeSort(int A[], int p, int r){
        if(r - p > 1){
                int q = (int)(p + r)/2;
                mergeSort(A, p, q);
                mergeSort(A, q, r);
                merge(A, p, q, r);
        }
        return;
}


int main(){	
	char c = 'y';
	ofstream out;
	out.open("result.txt");
	out<<"Function, Size, Best case, Average Case, Worst Case\n";
	vector<int> vector;
	int z = 100;
	int z_old = z;
	while(z <= 100000){
		vector.push_back(z);
		if(z / z_old == 10)
			z_old = z;
		z+=z_old;
	}
	for(int k = 0; k < vector.size(); k++){
		clock_t start, end;
		int n = vector[k];
		int arrayBest[n];
		int arrayAver[n];
		int arrayWorst[n];
		generateBestCaseInput(arrayBest, n);
		generateRandomInput(arrayAver, n);
		generateWorstCaseInput(arrayWorst, n);	
		out<<"Insertion sort,"<<n;
		for(int j = 0; j < 3; j++){
			int arrayInsertion[n];
			if (j == 0)
				for(int i = 0; i < n; i++)
					arrayInsertion[i] = arrayBest[i];
			if (j == 1)
				for(int i = 0; i < n; i++)
					arrayInsertion[i] = arrayAver[i];
			if (j == 2)
				for(int i = 0; i < n; i++)
					arrayInsertion[i] = arrayWorst[i];
			start = clock();
			InsertionSort(arrayInsertion, n);
			end = clock();
			double InsertionDuration = double(end - start) / double(CLOCKS_PER_SEC);
			out<<","<<fixed<<InsertionDuration<<setprecision(6);
		}
		out<<"\n";
		out<<"Merge sort,"<<n;
		for(int j = 0; j < 3; j++){
			int arrayMerge[n];
			if (j == 0)
				for(int i = 0; i < n; i++)
					arrayMerge[i] = arrayBest[i];
			if (j == 1)
				for(int i = 0; i < n; i++)
					arrayMerge[i] = arrayAver[i];
			if (j == 2)
				for(int i = 0; i < n; i++)
					arrayMerge[i] = arrayWorst[i];
			start = clock();
			mergeSort(arrayMerge, 0, n);
			end = clock();
			double MergeDuration = double(end - start) / double(CLOCKS_PER_SEC);
			out<<","<<fixed<<MergeDuration<<setprecision(6);
		}
		out<<"\n";
	}
	out.close();
	return 0;
}
