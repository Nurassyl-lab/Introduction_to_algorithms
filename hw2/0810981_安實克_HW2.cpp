#include <random>
#include <time.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
#include <math.h>
#include <fstream>
using namespace std;

int COUNT = 0;

void display_One_D_Vector(vector<int> v){
	char choice = 'y';
	if (v.size() > 100){
		cout<<"Size is too big to display it accurately\n";
		cout<<"Do you want to display content of vector of size "<<v.size()<<"? [y|n]\n";
		cin>>choice;
		cout<<"\n";
	}
		if (choice == 'y' || choice == 'Y'){
		cout<<"\n= = = = = = = = = = = = ="<<endl;
		cout<<"Length of 1D vector = "<<v.size()<<endl;
		cout<<"Vector content: "<<endl;
		for(int i = 0; i < v.size(); i++){
			if (i % 10 == 0 && i != 0)
				cout<<"\n";
			cout<<v[i]<<" ";
		}
		cout<<"\n= = = = = = = = = = = = ="<<endl;
		cout<<"\n";
	}
}

vector<int> generate_random_One_D_Vector(int N){
	vector<int> v;

	random_device rd;
    	mt19937 gen(rd());
    	uniform_int_distribution<> distrib((-1)*N, N);
	
	for(int i = 0; i < N; i++){
		v.push_back(distrib(gen));
	}
	return v;
}

int sum(vector<int> v, int i, int j){
	int s = 0;
	while(i <= j){
		s += v[i++];
	}
	return s;
}

void BF(vector<int> v, int &bestI, int &bestJ){
	int bestSum = v[0];
	for(int i = 0; i < v.size(); i++){
		for(int j = i; j < v.size(); j++){
			int s = sum(v, i, j);
			if(s > bestSum){
				bestSum = s;
				bestI = i;
				bestJ = j;
			}	
		}
	}
	cout<<"Brute Force Best sum: "<<bestSum<<endl;
	cout<<"Range -> ["<<bestI<<","<<bestJ<<"]"<<endl;
}

tuple<int, int, int> DCross(vector<int> v, int low, int mid, int high){
	int left_sum = -(INT_MAX - 1);
	int s = 0;
	int max_left, max_right;
	for (int i = mid; i >= low; i--){
		s = s + v[i];
		if (s > left_sum){
			left_sum = s;
			max_left = i;
		}
	}
	int right_sum = -(INT_MAX - 1);
	s = 0;
	for (int i = mid + 1; i <= high; i++){
		s = s + v[i];
		if (s > right_sum){
			right_sum = s;
			max_right = i;
		}
	}
	return(make_tuple(max_left, max_right, left_sum + right_sum));
}

tuple<int, int, int> DC(vector<int> v, int low, int high){
	if (high == low)
		return(make_tuple(low, high, v[low]));
	else{
		int left_low, left_high, left_sum;
		int right_low, right_high, right_sum;
		int cross_low, cross_high, cross_sum;
		
		int mid = (int) floor((high+low)/2);
		tie(left_low, left_high, left_sum) = DC(v, low, mid);
		tie(right_low, right_high, right_sum) = DC(v, mid+1, high);
		tie(cross_low, cross_high, cross_sum) = DCross(v, low, mid, high);
		if (left_sum >= right_sum && left_sum >= cross_sum)
			return (make_tuple(left_low, left_high, left_sum));
		else if(right_sum >= left_sum && right_sum >= cross_sum)
			return (make_tuple(right_low, right_high, right_sum));
		else
			return (make_tuple(cross_low, cross_high, cross_sum));
	}
}

int main(){
	char c = 'y';
	while (c == 'y' || c == 'Y'){
		cout<<"Enter size of an array: ";
		int N;
		cin>>N;
		cout<<"\n";
		cout<<"\nN = "<<N<<endl;
		//file<<N<<",";
		vector<int> v;
		v = generate_random_One_D_Vector(N);
		//display_One_D_Vector(v);	
		int BFi = 0; int BFj = 0;
		clock_t t = clock();
		BF(v, BFi, BFj);
		t = clock() - t;
		cout<<"Run time of Brute Force Algorithm is ";
		cout<<((float)t)/CLOCKS_PER_SEC<<"(s)\n\n";
		//file<<((float)t)/CLOCKS_PER_SEC<<",";
		int DCi = 0, DCj = v.size()-1, DCs;
		t = clock();
		tie(DCi, DCj, DCs) = DC(v, DCi, DCj);
		t = clock() - t;
		cout<<"Divide-and-Conquer Best sum: "<<DCs<<endl;
		cout<<"Range -> ["<<DCi<<","<<DCj<<"]"<<endl;
		cout<<"Run time of Divide-and-Conquer is ";
		cout<<((float)t)/CLOCKS_PER_SEC<<"(s)\n\n";
		//file<<((float)t)/CLOCKS_PER_SEC<<"\n";
		cout<<"\nContinue?[y|n] ";
		cin>>c;
		cout<<"\n";
	}
	return 0;
}
