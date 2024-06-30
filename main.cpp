#include<iostream>
#include<iomanip>
#include<string>
#include <vector>
using namespace std;

bool EuclidStep(vector<int>& nums, vector<int>& quotients, bool foreq);
int EuclidAlg(vector<int> nums, vector<int>& quotients, bool& algover, bool foreq);
void PrintEquations(int numa, int numb);
void MagicTable(vector<int> quotients);

int main() {
	int numa;
	int numb;
	bool algover = false;
	int gcd;
	string again;
	vector<int> nums;
	vector<int> quotients;

	while (true) {
		nums.clear();
		quotients.clear();
		algover = false;

		cout << "\nCalculate the greaest common divisor of positive integers a and b \n" << "\nEnter a:";
		cin >> numa;

		cout << "Enter b:";
		cin >> numb;

		nums.push_back(max(numa, numb));
		nums.push_back(min(numa, numb));

		gcd = EuclidAlg(nums, quotients, algover, false);

		cout << "The greatest common divisor of " << numa << " and " << numb << " is: " << gcd << "\n" << "\n";

		cout << "Type an option: \n (1) Print equations \n (2) Magic Table \n (3) Input new numbers \n (4) Quit \n";
		cin >> again;

		if (again == "3") {
			continue;
		}
		else if (again == "4") {
			break;
		}
		else if (again == "1") {
			PrintEquations(numa, numb);
			string option1;
			cout << "Type an option: \n (1) Magic Table \n (2) Input new numbers \n (3) Quit \n";
			cin >> option1;
			if (option1 == "1") {
				MagicTable(quotients);
			}
			else if (option1 == "3") {
				break;
			}

		}
		else if (again == "2") {
			MagicTable(quotients);
			string option2;
			cout << "Type an option: \n (1) Print equations \n (2) Input new numbers \n (3) Quit \n";
			cin >> option2;
			if (option2 == "1") {
				PrintEquations(numa, numb);
			}
			else if (option2 == "3") {
				break;
			}
		}
	}

	return 0;
}

bool EuclidStep(vector<int>& nums, vector<int>& quotients, bool foreq) {
	int quotient = 0;
	if (nums[nums.size() - 1] != 0) {
		int r = nums[nums.size() - 2];
		while (r >= nums[nums.size() - 1]) {
			quotient += 1;
			r -= nums[nums.size() - 1];
		}
		if (foreq) {
			cout << nums[nums.size() - 2] << " = " << quotient << " * " <<
				nums[nums.size() - 1] << " + " << r << "\n";
		}
		quotients.push_back(quotient);
		nums.push_back(r);
	}
	return((nums[nums.size()-1]) == 0);
}

int EuclidAlg(vector<int> nums, vector<int>& quotients, bool& algover, bool foreq){
	while (!algover) {
		algover = EuclidStep(nums, quotients, foreq);
	}
	return nums[nums.size() - 2];
}

void PrintEquations(int numa, int numb) {
	vector<int> foreq;
	vector<int> quotients;
	bool over = false;
	foreq.push_back(max(numa, numb));
	foreq.push_back(min(numa, numb));

	cout << "\n";
	EuclidAlg(foreq, quotients, over, true);
}

void MagicTable(vector<int> quotients) {
	vector<int> P;
	vector<int> Q;

	P.push_back(0);
	P.push_back(1);
	Q.push_back(1);
	Q.push_back(0);

	cout << "\n";

	for (int i = 0; i < quotients.size()-1; i++) {
		P.push_back(quotients[i] * P[P.size() - 1] + P[P.size() - 2]);
		Q.push_back(quotients[i] * Q[Q.size() - 1] + Q[Q.size() - 2]);
	}

	cout << right << setw(6) << setfill(' ') << "";
	cout << right << setw(6) << setfill(' ') << "";
	cout << right << setw(2) << setfill(' ') << "|";
	for (int i = 0; i < quotients.size()-1; i++) {
		cout << right << setw(6) << setfill(' ') << quotients[i];
	}
	cout << "\n";
	for (int i = 0; i < P.size(); i++) {
		cout << right << setw(6) << setfill('-') << "";
		if (i == 1) {
			cout << right << setw(2) << setfill('-') << "";
		}
	}
	cout << "\n";
	for (int i = 0; i < P.size(); i++) {
		//cout << " " << P[i];
		cout << right << setw(6) << setfill(' ') << P[i];

		if (i == 1) {
			//cout << "|";
			cout << right << setw(2) << setfill(' ') << "|";
		}
	}
	cout << "\n";
	for (int i = 0; i < Q.size(); i++) {
		//cout << " " << Q[i];
		cout << right << setw(6) << setfill(' ') << Q[i];

		if (i == 1) {
			cout << right << setw(2) << setfill(' ') << "|";
		}
	}
	cout << "\n";
	cout << "\n";
}
