// ConsoleApplication20.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<vector>
using namespace std;
void swap(int & a, int & b) {
	int t = a;
	a = b;
	b = t;
}
void maopao(vector<int> nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = 0; j < nums.size() - i-1; j++) {
			if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
		}
	}
	for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
	cout<<endl;
}

void select(vector<int> nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		int index = i;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] < nums[index]) index = j;
			   }
		swap(nums[i], nums[index]);
	   }
	for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
	cout<<endl;
}

void insert(vector<int> nums) {
	for (int i = 1; i < nums.size(); i++) {
		for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; j--) {
			swap(nums[j], nums[j + 1]);
		}
		}
	 for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
	 cout<<endl;
}

void shell(vector<int> nums) {
	int len = nums.size();
	int step = 1;
	while (step < len / 3) step = 3 * step + 1;
	while (step >= 1) {
		for (int i = step; i < len; i++) {
			for (int j = i; j >= step && nums[j - step] > nums[j]; j -= step) {
				swap(nums[j], nums[j - step]);
			}
		}
		step /= 3;
	}
	for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
	cout<<endl;
}

void quick_sort(vector<int>& nums,int left,int right) {
	if (left >= right) return;
	int l = left;
	int r = right;
	int temp = nums[l];
	while (l < r) {
		while (r > l && nums[r] > temp) r--;
		nums[l] = nums[r];
		while (l < r && nums[l] <= temp) l++;
		nums[r] = nums[l];
	}
	nums[l] = temp;
	quick_sort(nums, left,l-1);
	quick_sort(nums, l+1, right);
}

void quick(vector<int> nums) {
	quick_sort(nums,0,nums.size()-1);
	for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
	cout<<endl;
}

void heap_sort(vector<int> &nums,int start,int end){
	int dad = start;
	int son = 2*dad + 1;
	while(son<=end){
		if(son+1<=end && nums[son+1]>nums[son]) son++;
		if(nums[dad]>=nums[son]) break;
		else{
			swap(nums[dad],nums[son]);
			dad = son;
			son = 2*dad + 1;
		}
	}

}

void heap(vector<int> nums) {
	int len = nums.size();
	for (int i = len / 2 - 1; i >= 0; i--) {
		     heap_sort(nums,i,len-1);
	   }
	for (int j = len - 1; j > 0; j--) {
		swap(nums[j], nums[0]);
		heap_sort(nums, 0, j-1);
	}
	for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
	cout<<endl;
}

int main() {
	vector<int> num = {5,7,2,8,4,3,2,1,10,9,15,12};
	maopao(num);
	select(num);
	insert(num);
	shell(num);
	quick(num);
	heap(num);
	//merger(nums);
	//count(nums);
	system("pause");
	return 0;
}

