#include<iostream>
#include<string>
#include <vector>
using namespace std;

bool EuclidStep(vector<int>& nums);
int EuclidAlg(vector<int> nums, bool& algover);

int main() {
	int numa;
	int numb;
	bool algover = false;
	int gcd;
	string again;
	vector<int> nums;

	cout << "GCD calculator \n \n";

	while (true) {
		nums.clear();
		algover = false;

		cout << "Enter a:";
		cin >> numa;

		cout << "Enter b:";
		cin >> numb;

		nums.push_back(max(numa, numb));
		nums.push_back(min(numa, numb));

		gcd = EuclidAlg(nums, algover);

		cout << "The greatest common divisor of " << numa << " and " << numb << " is: " << gcd << "\n" << "\n";

		cout << "Type y to find another gcd, or type q to quit: ";
		cin >> again;

		if (again == "y") {
			cout << "\n";
			continue;
		}
		else {
			break;
		}
	}

	return 0;
}

bool EuclidStep(vector<int>& nums) {
	if (nums[nums.size() - 1] != 0) {
		int r = nums[nums.size() - 2];
		while (r >= nums[nums.size() - 1]) {
			r -= nums[nums.size() - 1];
		}
		nums.push_back(r);
	}
	return((nums[nums.size()-1]) == 0);
}

int EuclidAlg(vector<int> nums, bool& algover){
	while (!algover) {
		algover = EuclidStep(nums);
	}
	return nums[nums.size() - 2];
}