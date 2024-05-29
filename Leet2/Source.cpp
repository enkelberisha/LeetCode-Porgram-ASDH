#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <unordered_map>

using namespace std;

// time:O(n)  space:O(n)
bool backspaceCompare(string& s, string& t)
{
	string answerOne;
	string answerTwo;

	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) != '#')
		{
			answerOne += s.at(i);
		}
		else
		{
			if (!(answerOne).empty())
			{
				answerOne.pop_back();
			}
		}
	}
	for (int i = 0; i < t.size(); i++)
	{
		if (t.at(i) != '#')
		{
			answerTwo += t.at(i);
		}
		else
		{
			if (!(answerTwo).empty())
			{
				answerTwo.pop_back();
			}
		}
	}
	s = answerOne;
	t = answerTwo;
	return (answerOne == answerTwo);
}
// time:O(n)  space:O(n)
bool isValid(string s)
{
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{

		if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
		{
			st.push(s.at(i));
		}
		else if (st.empty())
		{
			return false;
		}
		else if (s.at(i) == ')' && st.top() == '(' || s.at(i) == '}' && st.top() == '{' || s.at(i) == ']' && st.top() == '[')
		{
			st.pop();
		}
		else
		{
			return false;
		}
	}

	return st.empty();
}

// time:O(n)  size:O(n)
string makeGood(string s)
{

	string answer = "";
	if (s.empty())
	{
		return answer;
	}

	int i = 0;
	while (i < s.size())
	{

		if (!answer.empty() && abs(s.at(i) - answer.back()) == 32)
		{
			answer.pop_back();
		}
		else
		{
			answer.push_back(s.at(i));
		}
		i++;
	}
	return answer;
}
// time: O(n^2)   size:O(1)
int timeRequiredToBuy(vector<int> tickets, int k)
{
	int time = 0;
	while (true)
	{
		for (int i = 0; i < tickets.size(); i++)
		{
			if (tickets.at(k) == 0)
			{
				return time;
			}
			else
			{
				if (tickets.at(i) != 0)
				{
					tickets.at(i) -= 1;
					time += 1;
				}
			}
		}
	}
}

// push{time: O(n) size: O(n)} ||| else{time: O(1)  size: O(n)}
class MyStack
{
public:
	queue<int> q;
	queue<int> q1;

	void print()
	{
		queue<int> q2;
		q2 = q1;
		cout << "Stack contents:" << endl;
		while (!q2.empty())
		{
			cout << q2.front() << endl;
			q2.pop();
		}
	}
	void push(int x)
	{
		q.push(x);
		while (!q1.empty())
		{
			q.push(q1.front());
			q1.pop();
		}
		swap(q, q1);
	}

	int pop()
	{
		int result = q1.front();
		q1.pop();
		return result;
	}

	int top()
	{
		return q1.front();
	}

	bool empty()
	{
		return q1.empty();
	}
};

// ListNode declaration ++ extra functions.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* stringToLinkedList(string& binaryNumber)
{
	ListNode* dummy = new ListNode();
	ListNode* curr = dummy;

	for (int i = 0; i < binaryNumber.size(); i++)
	{
		char bit = binaryNumber[i];
		curr->next = new ListNode(bit - '0');
		curr = curr->next;
	}

	ListNode* result = dummy->next;
	delete dummy;
	return result;
}

void printLinkedList(ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

ListNode* addElementsToList(int n, int test)
{

	ListNode* dummy = new ListNode(-1);
	ListNode* current = dummy;

	int x, prevX = -1;

	if (test == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << "\nWrite the desired value of the LinkedList node nr." << i + 1 << " : " << endl;
			cin >> x;
			current->next = new ListNode(x);
			current = current->next;
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{

			cout << "\nWrite the desired value of the LinkedList node nr." << i + 1 << " : " << endl;
			cin >> x;
			if ((i == 0 || i == n - 1) && x != 0)
			{
				cout << "\nThe first and last node must be 0" << endl;
				x = 0;
			}

		No0:
			if (prevX == 0 && x == 0)
			{
				cout << "\nConsecutive 0 are not allowed. " << endl;
				cout << "\nRewrite the desired value of the LinkedList node nr." << i + 1 << " : " << endl;
				cin >> x;
				goto No0;
			}

			current->next = new ListNode(x);
			current = current->next;
			prevX = x;
		}
	}

	ListNode* result = dummy->next;
	delete dummy;
	return result;
}

vector<int> listToVector(ListNode* head)
{
	vector<int> v;
	while (head)
	{
		v.push_back(head->val);
		head = head->next;
	}
	return v;
}

ListNode* vectorToList(vector<int> v)
{
	ListNode* dummy = new ListNode(-1);
	ListNode* curr = dummy;

	for (int i = 0; i < v.size(); i++)
	{
		curr->next = new ListNode(v.at(i));
		curr = curr->next;
	}
	ListNode* result = dummy->next;
	delete dummy;
	return result;
}

ListNode* sortLinkedList(ListNode* head)
{
	vector<int> v = listToVector(head);
	sort(v.begin(), v.end());
	return vectorToList(v);
}

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// time: O(n)    size: O(n)
int getDecimalValue(ListNode* head)
{

	vector<int> v;
	while (head != NULL)
	{
		v.push_back(head->val);
		head = head->next;
	}

	int sum = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		sum += v.at(i) * pow(2, v.size() - 1 - i);
	}
	return sum;
}

// time: O(n)   size: O(1)
ListNode* reverseList(ListNode* head)
{
	ListNode* answer = NULL;
	ListNode* current = head;

	while (current != NULL)
	{
		ListNode* forward = current->next;
		current->next = answer;
		answer = current;
		current = forward;
	}
	return answer;
}

// time: O(n+m)   size: O(n+m)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{

	if (list1 == NULL)
	{
		return list2;
	}
	else if (list2 == NULL)
	{
		return list1;
	}

	if (list1->val <= list2->val)
	{
		list1->next = mergeTwoLists(list1->next, list2);

		return list1;
	}
	else
	{
		list2->next = mergeTwoLists(list1, list2->next);
		return list2;
	}
}

// time: O(n)   size: O(1)
ListNode* mergeNodes(ListNode* head)
{
	ListNode* temp = head;
	ListNode* front = temp->next;
	int sum = 0;
	while (front != NULL)
	{
		if (front->val != 0)
		{
			sum += front->val;
			front = front->next;
		}
		else
		{
			temp->next = front;
			front->val = sum;
			sum = 0;
			temp = front;
			front = front->next;
		}
	}
	return head->next;
}

// time: O(n)  size:O(n)

ListNode* insertGreatestCommonDivisors(ListNode* head)
{
	ListNode* first = head;
	ListNode* second = head->next;
	while (second != NULL)
	{
		ListNode* temp = new ListNode(gcd(first->val, second->val));
		first->next = temp;
		temp->next = second;
		first = second;
		second = second->next;
	}
	return head;
}
// TreeNode struct ++ extra functions
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
		right(right) {}
};
TreeNode* insertIntoBST(TreeNode* root, int val);

TreeNode* createBST()
{
	TreeNode* root = nullptr;
	char choice;
	do
	{
		int value;
		cout << "\nEnter the desired value to insert into the binary search tree: ";
		cin >> value;
		root = insertIntoBST(root, value);

		cout << "\nDo you want to insert another value? ('Y'->Yes || 'N'->No): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');

	return root;
}

void inOrderTraversal(TreeNode* root, int depth = 0)
{
	if (!root)
	{
		return;
	}

	inOrderTraversal(root->right, depth + 1);

	for (int i = 0; i < depth; i++)
	{
		cout << "   ";
	}
	cout << "|--" << root->val << endl;

	inOrderTraversal(root->left, depth + 1);
}

// time: O(n)    space: O(n)
int rangeSumBST(TreeNode* root, int low, int high)
{
	int sum = 0;
	if (root == NULL)
	{
		return 0;
	}

	if (root != NULL)
	{
		if (root->val <= high && root->val >= low)
		{
			sum += root->val;
			sum += rangeSumBST(root->right, low, high);
			sum += rangeSumBST(root->left, low, high);
		}
		else if (root->val > high)
		{
			sum += rangeSumBST(root->left, low, high);
		}
		else
		{
			sum += rangeSumBST(root->right, low, high);
		}
	}
	return sum;
}

// time: O(log(n))  space: O(h)
TreeNode* searchBST(TreeNode* root, int val)
{
	if (root != NULL)
	{
		if (root->val == val)
		{
			return root;
		}
		if (root->val > val)
		{
			return searchBST(root->left, val);
		}
		else
		{
			return searchBST(root->right, val);
		}
	}
	return NULL;
}

// time: O(logn)  // space: O(logn) 
TreeNode* insertIntoBST(TreeNode* root, int val)
{
	if (root == NULL)
	{
		TreeNode* root = new TreeNode(val);
		return root;
	}
	if (val < root->val)
	{
		root->left = insertIntoBST(root->left, val);
	}
	else
	{
		root->right = insertIntoBST(root->right, val);
	}
	return root;
}

// time:O(n)->>
void BSTelements(TreeNode* root, vector<int>& v)
{

	if (root != NULL)
	{
		BSTelements(root->left, v);
		v.push_back(root->val);
		BSTelements(root->right, v);
	}
}
// time:O(n^2)  space:O(n)
bool findTarget(TreeNode* root, int k, int& n1, int& n2)
{
	vector<int> v = {};
	BSTelements(root, v);
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{

			if (v.at(i) + v.at(j) == k)
			{
				n1 = v.at(i);
				n2 = v.at(j);
				return true;
			}
		}
	}
	return false;
}

// time: O(nlogn)  space:O(n) ->>
vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{

	vector<int> v = {};

	BSTelements(root1, v);
	BSTelements(root2, v);

	int n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] > v[j])
			{
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}

	return v;
}
void printVector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
}

// time: O(n+m)   space:O(n+m)
vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2)
{

	unordered_map<int, int> mp2;
	unordered_map<int, int> mp1;
	int n = 0, m = 0;
	for (int i = 0; i < nums2.size(); i++)
	{
		mp2[nums2.at(i)]++;
	}
	for (int i = 0; i < nums1.size(); i++)
	{
		mp1[nums1.at(i)]++;
	}

	for (auto i = mp1.begin(); i != mp1.end(); i++)
	{
		if (mp2.find(i->first) != mp2.end())
		{
			n += i->second;
		}
	}

	for (auto i = mp2.begin(); i != mp2.end(); i++)
	{
		if (mp1.find(i->first) != mp1.end())
		{
			m += i->second;
		}
	}

	vector<int> v = { n, m };
	return v;
}

// time: O(n)  space:O(n)
int maxFrequencyElements(vector<int>& nums)
{

	unordered_map<int, int> mp;

	for (int i = 0; i < nums.size(); i++)
	{
		mp[nums.at(i)]++;
	}
	int max = 0, freq = 0;
	for (auto i = mp.begin(); i != mp.end(); i++)
	{

		if ((i->second) > max)
		{
			max = i->second;
			freq = i->second;
		}
		else if (i->second == max)
		{
			freq += i->second;
		}
	}
	return freq;
}

// time:O(n)  space:O(n)
bool uniqueOccurrences(vector<int> arr)
{
	unordered_map<int, int> mp, mp1;

	for (int i = 0; i < arr.size(); i++)
	{
		mp[arr[i]]++;
	}
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		mp1[i->second]++;
	}
	for (auto i = mp1.begin(); i != mp1.end(); i++)
	{
		if (i->second > 1)
		{
			return false;
		}
	}
	return true;
}

// time:O(n)   space:O(n)
int repeatedNTimes(vector<int>& nums)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++)
	{
		mp[nums[i]]++;
	}
	int n = nums.size() / 2;
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		if (i->second == n)
		{
			return i->first;
		}
	}
	return 0;
}

bool hasLetters(const string& str)
{
	bool foundR = false, foundG = false, foundB = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == 'R')
		{
			foundR = true;
		}
		else if (str.at(i) == 'G')
		{
			foundG = true;
		}
		else if (str.at(i) == 'B')
		{
			foundB = true;
		}

		if (foundR && foundG && foundB)
		{
			return true;
		}
	}

	return false;
}
// time:O(n)   space:O(n)
int countPoints(string rings)
{
	unordered_map<int, string> mp;
	int ans = 0;
	for (int i = 0; i < rings.size(); i += 2)
	{
		int key = rings[i + 1] - '48';
		int val = rings[i];
		mp[key] += val;
	}
	for (auto i = mp.begin(); i != mp.end(); i++)
	{

		if (hasLetters(i->second))
		{
			ans++;
		}
	}
	return ans;
}
void addString(string& s)
{
	char c;
colourRestart:
	cout << "\nWrite a colour you want to add ('R','G','B'): " << endl;
	cin >> c;
	if (c == 'R' || c == 'G' || c == 'B')
	{
	}
	else
	{
		cout << "Not a supported answer." << endl;
		goto colourRestart;
	}
	s += c;
rodRestart:
	cout << "\nWrite the rod the ring is placed on: " << endl;
	int c1;
	cin >> c1;

	if (c1 < 0 || c1 > 9)
	{
		cout << "Rod numbers only allowed from 0 to 9." << endl;
		goto rodRestart;
	}
	s += to_string(c1);
}

int main()
{

	int numOfFunction;

	cout << "A simple program including 20 functions."
		<< endl;
restart:
	cout << "\nList of functions and their corresponding number:" << endl;
	cout << " 1. Backspace String Compare." << endl;
	cout << " 2. Valid Parentheses." << endl;
	cout << " 3. Make The String Great." << endl;
	cout << " 4. Time Needed to Buy Tickets." << endl;
	cout << " 5. Implement Stack using Queues." << endl;
	cout << " 6. Convert Binary Number in a Linked List to Integer." << endl;
	cout << " 7. Reverse Linked List." << endl;
	cout << " 8. Merge Two Sorted Lists." << endl;
	cout << " 9. Merge Nodes in Between Zeros." << endl;
	cout << "10. Insert Greatest Common Divisors in Linked List." << endl;
	cout << "11. Range Sum of BST." << endl;
	cout << "12. Search in a Binary Search Tree." << endl;
	cout << "13. Insert into a Binary Search Tree." << endl;
	cout << "14. Two Sum IV - Input is a BST." << endl;
	cout << "15. All Elements in Two Binary Search Trees." << endl;
	cout << "16. Find Common Elements Between Two Arrays." << endl;
	cout << "17. Count Elements With Maximum Frequency." << endl;
	cout << "18. Unique Number of Occurrences." << endl;
	cout << "19. N-Repeated Element in Size 2N Array." << endl;
	cout << "20. Rings and Rods.\n\n"
		<< endl;

	cout << "To continue using the program type one of the corresponding numbers of a function : " << endl;
	cin >> numOfFunction;

	switch (numOfFunction)
	{

	case (1):
	{
		cout << "\n\n 1. Backspace String Compare." << endl;
		cout << "Given two strings s and t,\nthe program returns true if they are equal when both are typed into empty text editors." << endl;
		cout << "'#' means a backspace character." << endl;

		string t, s;

		cout << "Write the first string: " << endl;
		cin >> s;
		cout << "Write the second string: " << endl;
		cin >> t;

		if (backspaceCompare(t, s))
		{
			cout << "String s:\"" << s << "\" and string t:\"" << t << "\" are the same. " << endl;
		}
		else
		{
			cout << "String s:\"" << s << "\" and string t:\"" << t << "\" are not the same. " << endl;
		}

		goto restartDefault;
	}

	case (2):
	{
		cout << "\n\n 2. Valid Parentheses." << endl;
		cout << "\nGiven a string containing just the characters '(', ')', '{', '}', '[' and ']',\nthe program determines if the input string is valid." << endl;
		cout << "\nAn input string is valid if:\n\n1.Open brackets must be closed by the same type of brackets.\n2.Open brackets must be closed in the correct order.\n3.Every close bracket has a corresponding open bracket of the same type." << endl;

	restart2:

		string s;
		cout << "Write the desired string: " << endl;
		cin >> s;

		for (int i = 0; i < s.size(); i++)
		{
			if (s.at(i) == '(' || s.at(i) == ')' || s.at(i) == '{' || s.at(i) == '}' || s.at(i) == '[' || s.at(i) == ']')
			{
			}
			else
			{
				cout << "The program only allows characters: '(', ')', '{', '}', '[' and ']'" << endl;

				goto restart2;
			}
		}
		if (isValid(s))
		{
			cout << "The string that was given \"" << s << "\" has a valid order of parentheses." << endl;
		}
		else
		{
			cout << "The string that was given \"" << s << "\" doesn't have a valid order of parentheses." << endl;
		}
		goto restartDefault;
	}

	case (3):
	{
		cout << "\n\n 3. Make The String Great." << endl;
		cout << "\nGiven a string of lower and upper case English letters,\nthe program returns a good string." << endl;
		cout << "\nA good string is a string where there are no adjacent letters that are the same but have different cases." << endl;
		string s;
		cout << "Write the desired string: " << endl;
		cin >> s;

		cout << "The string: \"" << s << "\" after making it good is:\"" << makeGood(s) << "\"" << endl;

		goto restartDefault;
	}
	case (4):
	{
		cout << "\n\n 4. Time Needed to Buy Tickets." << endl;
		cout << "\nThere are n people in a line queueing to buy tickets,\neach person takes exactly 1 second to buy a ticket." << endl;
		cout << "\nA person can only buy 1 ticket at a time and has to go back to the end of the line(which happens instantaneously)\nin order to buy more tickets." << endl;
		cout << "If a person does not have any tickets left to buy, the person will leave the line." << endl;
		cout << "\nThe program determines the duration required for an individual to buy the tickets." << endl;

		int size;
		cout << "Write the desired number of people: " << endl;
		cin >> size;

		vector<int> v;

		for (int i = 0; i < size; i++)
		{
			int tickets;
			cout << "Write the number of tickets person nr " << i << " has to purchase:" << endl;
			cin >> tickets;
			v.push_back(tickets);
		}

		int nthPerson;

		cout << "Write the desired person you want to determine the time required to buy the tickets: " << endl;
		cin >> nthPerson;

		cout << "The time required for the " << nthPerson << " person to buy his tickets in the queue: ";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v.at(i) << " ";
		}
		cout << "is: " << timeRequiredToBuy(v, nthPerson) << endl;

		goto restartDefault;
	}
	case (5):
	{
		MyStack s;
		cout << "\n\n 5. Implement Stack using Queues." << endl
			<< endl;
		cout << "Implement a last-in-first-out (LIFO) stack using only two queues." << endl;
		cout << "The implemented stack should support all the functions of a normal stack(push, top, pop, and empty)." << endl;

		cout << "\nThe supported commands are:\nVoid push(int x) Pushes element x to the top of the stack.\nInt pop() Removes the element on the top of the stack and returns it." << endl;
		cout << "Int top() Returns the element on the top of the stack.\nBoolean empty() Returns true if the stack is empty, false otherwise." << endl;

	commStart:
		int comm;
		cout << "\nWhat command do u want to use: " << endl;
		cout << "The allowed commands are:\n1.push(int x)\n2.pop()\n3.top()\n4.empty()" << endl;
		cin >> comm;
		switch (comm)
		{
		case (1):
		{
			int x;
			cout << "Write the desired value you want to add to the stack : " << endl;
			cin >> x;
			s.push(x);
			s.print();
			goto restartComm;
		}
		case (2):
		{

			if (!s.empty())
			{
				cout << "\nThe stack before pop: " << endl;
				s.print();
				s.pop();
				cout << "\nThe stack after pop: " << endl;
				s.print();
			}
			else
			{
				cout << "You cannot use pop on an empty stack." << endl;
			}

			goto restartComm;
		}
		case (3):
		{
			cout << "\nThe stack is: " << endl;
			s.print();
			cout << "\nThe function top returns: " << s.top() << endl;
			goto restartComm;
		}
		case (4):
		{

			if (s.empty())
			{
				cout << "The stack is empty. " << endl;
			}
			else
			{
				cout << "\nThe given stack is: " << endl;
				s.print();
				cout << "The stack is not empty." << endl;
			}
			goto restartComm;
		}
		default:
		{

			cout << "\nThe given answer is not supported. ";
			goto restartComm;
		}
		}
	restartComm:
		string test;
		cout << "\nDo you want to use another command ('Y'->Yes || 'N'->No): " << endl;
		cin >> test;
		if (test == "Y" || test == "y")
		{
			goto commStart;
		}
		else if (test == "N" || test == "n")
		{
			cout << "The end result is: " << endl;
			s.print();
			goto restartDefault;
		}
		else
		{
			cout << "Not a supported answer." << endl;
			goto restartComm;
		}

		goto restartDefault;
	}

	case (6):
	{

		cout << "\n\n 6. Convert Binary Number in a Linked List to Integer." << endl
			<< endl;

		cout << "Given head which is a reference node to a singly-linked list." << endl;
		cout << "The value of each node in the linked list is either 0 or 1.\nThe linked list holds the binary representation of a number." << endl;
		cout << "\nThe program returns the decimal value of the number in the linked list." << endl
			<< endl;

		string binaryNr;
	binaryNrRestart:
		cout << "Write the desired binary number: " << endl;
		cin >> binaryNr;
		for (int i = 0; i < binaryNr.size(); i++)
		{
			if (binaryNr.at(i) != '0' && binaryNr.at(i) != '1')
			{
				cout << "The given number is not a valid binary number." << endl;
				goto binaryNrRestart;
			}
		}
		ListNode* LN = stringToLinkedList(binaryNr);

		cout << "\nThe given binary number is: " << endl;
		printLinkedList(LN);

		cout << "\nThe binary numbers value is: " << getDecimalValue(LN) << endl;

		goto restartDefault;
	}
	case (7):
	{
		cout << "\n\n 7. Reverse Linked List." << endl
			<< endl;

		cout << "Given the head of a singly linked list,the program reverses the list, and returns the reversed list." << endl;

		int size;
		cout << "Write the desired length of the linked list: " << endl;
		cin >> size;
		ListNode* LN = addElementsToList(size, 1);

		cout << "\nThe given linked list is: " << endl;
		printLinkedList(LN);

		ListNode* LNreverse = reverseList(LN);

		cout << "\nThe reversed list is: " << endl;
		printLinkedList(LNreverse);

		goto restartDefault;
	}

	case (8):
	{
		cout << "\n\n 8. Merge Two Sorted Lists." << endl
			<< endl;

		cout << "Given the heads of two sorted linked lists." << endl;
		cout << "The program merges the two lists into one sorted list.\nThe list should be made by splicing together the nodes of the first two lists." << endl;
		cout << "\nThe program returns the new linked list." << endl;

		int size;
		cout << "Write the desired length of the first linked list: " << endl;
		cin >> size;
		ListNode* LN1 = addElementsToList(size, 1);

		cout << "\nThe first linked list is: " << endl;
		printLinkedList(LN1);

		cout << "The sorted first list is: " << endl;
		LN1 = sortLinkedList(LN1);
		printLinkedList(LN1);

		cout << "\nWrite the desired length of the second linked list: " << endl;
		cin >> size;
		ListNode* LN2 = addElementsToList(size, 1);

		cout << "\nThe second linked list is: " << endl;
		printLinkedList(LN2);

		cout << "The sorted second list is: " << endl;
		LN2 = sortLinkedList(LN2);
		printLinkedList(LN2);

		ListNode* LN3 = mergeTwoLists(LN1, LN2);

		cout << "\nThe final result linked list is: " << endl;
		printLinkedList(LN3);

		goto restartDefault;
	}
	case (9):
	{
		cout << "\n\n 9. Merge Nodes in Between Zeros." << endl
			<< endl;

		cout << "Given the head of a linked list, which contains a series of integers separated by 0's." << endl;
		cout << "The program returns the sum of all the merged nodes that lie in between two consecutive 0 nodes." << endl;
		cout << "\nThe modified list should not contain any 0's." << endl;
		cout << "The beginning and end of the linked list must be 0." << endl;

		int size;
		cout << "\nWrite the desired length of the linked list: " << endl;
		cin >> size;
		ListNode* LN = addElementsToList(size, 0);

		cout << "\nThe given linked list is: " << endl;
		printLinkedList(LN);

		cout << "\nThe merged nodes linked list is: " << endl;

		LN = mergeNodes(LN);
		printLinkedList(LN);
		goto restartDefault;
	}
	case (10):
	{

		cout << "\n\n 10. Insert Greatest Common Divisors in Linked List." << endl
			<< endl;
		cout << "Given the head of a linked list, the program inserts a new node inbetween every pair of adjacent nodes,\nwith the value of the greatest common divisor of them." << endl;
		int size;
		cout << "\nWrite the desired length of the linked list: " << endl;
		cin >> size;
		ListNode* LN = addElementsToList(size, 1);
		cout << "The given linked list is: " << endl;
		printLinkedList(LN);
		LN = insertGreatestCommonDivisors(LN);
		cout << "\nThe final result linked list is: " << endl;
		printLinkedList(LN);
		goto restartDefault;
	}
	case (11):
	{
		cout << "\n\n 11. Range Sum of BST." << endl
			<< endl;
		cout << "Given the root node of a binary search tree and two integers low and high,\nthe program returns the sum of values of all nodes with a value in the inclusive range." << endl;

		TreeNode* TN = createBST();

		int low, high;

		cout << "\nThe given tree is: " << endl;
		inOrderTraversal(TN);

		cout << "\nWrite the desired minimum value: " << endl;
		cin >> low;
		cout << "\nWrite the desired maximum value: " << endl;
		cin >> high;

		cout << "\nThe sum of numbers between " << low << " and " << high << " is " << rangeSumBST(TN, low, high) << endl;

		goto restartDefault;
	}
	case (12):
	{
		cout << "\n\n 12. Search in a Binary Search Tree." << endl
			<< endl;
		cout << "Given the root of a binary search tree (BST) and an integer value." << endl;

		cout << "The program finds the node in the BST that the node's value equals value and return the subtree rooted with that node." << endl;

		TreeNode* TN = createBST();
		cout << "\nWrite the desired value: " << endl;
		int value;
		cin >> value;

		cout << "\nThe given tree is: " << endl;
		inOrderTraversal(TN);

		TN = searchBST(TN, value);
		cout << "\nThe final result tree is: " << endl;
		inOrderTraversal(TN);

		goto restartDefault;
	}

	case (13):
	{

		cout << "\n\n 13. Insert into a Binary Search Tree." << endl
			<< endl;
		cout << "Given the root node of a binary search tree (BST) and a value to insert into the tree.\nThe program returns the root node of the BST after the insertion." << endl;

		TreeNode* TN = createBST();

		cout << "\nThe given tree is: " << endl;
		inOrderTraversal(TN);

		cout << "Write the desired value to add to the tree: " << endl;
		int value;
		cin >> value;

		TN = insertIntoBST(TN, value);
		cout << "\nThe final result tree is: " << endl;
		inOrderTraversal(TN);

		goto restartDefault;
	}

	case (14):
	{
		cout << "\n\n 14. Two Sum IV - Input is a BST." << endl
			<< endl;
		cout << " Given the root of a binary search tree and an integer k," << endl;
		cout << "The program returns true if there exist two elements in the BST such that their sum is equal to k, or false otherwise." << endl;

		TreeNode* TN = createBST();

		cout << "\nThe given tree is: " << endl;
		inOrderTraversal(TN);

		cout << "What is the desired value you are searching for: " << endl;
		int value, n1, n2;
		cin >> value;

		if (findTarget(TN, value, n1, n2))
		{
			cout << "The numbers: " << n1 << " and " << n2 << " add to: " << value << endl;
		}
		else
		{
			cout << "No two numbers add to: " << value << endl;
		}

		goto restartDefault;
	}

	case (15):
	{
		cout << "\n\n 15. All Elements in Two Binary Search Trees." << endl
			<< endl;

		cout << "Given two binary search,\nthe program returns a list containing all the integers from both trees sorted in ascending order." << endl;

		cout << "\nFirst tree: " << endl;
		TreeNode* TN1 = createBST();
		cout << "\nSecond tree: " << endl;
		TreeNode* TN2 = createBST();
		cout << "\nThe first tree is: " << endl;
		inOrderTraversal(TN1);

		cout << "\nThe second tree is: " << endl;
		inOrderTraversal(TN2);

		vector<int> v = getAllElements(TN1, TN2);

		cout << "The final result vector is: " << endl;

		for (int i = 0; i < v.size(); i++)
		{
			cout << v.at(i) << " ";
		}
		goto restartDefault;
	}

	case (16):
	{
		cout << "\n\n 16. Find Common Elements Between Two Arrays." << endl
			<< endl;
		cout << "Given two arrays, the program returns the number of occurrences for each array." << endl
			<< endl;

		vector<int> nums1, nums2;
		int x, t;
		cout << "Write the desired length for the first array: " << endl;
		cin >> x;
		cout << "\nArray 1: " << endl;

		for (int i = 0; i < x; i++)
		{
			cout << "Write the value for element nr." << i << ": " << endl;
			cin >> t;
			nums1.push_back(t);
		}

		cout << "\nWrite the desired length for the second array: " << endl;
		cin >> x;

		cout << "\nArray 2: " << endl;

		for (int i = 0; i < x; i++)
		{
			cout << "\nWrite the value for element nr." << i << ": " << endl;
			cin >> t;
			nums2.push_back(t);
		}

		vector<int> v = findIntersectionValues(nums1, nums2);

		cout << "\nFor the arrays: ";
		printVector(nums1);
		cout << " and ";
		printVector(nums2);
		cout << "." << endl;
		cout << "\nThe first array elements occur " << v.at(0) << " times." << endl;
		cout << "\nThe second array elements occur " << v.at(1) << " times." << endl;

		goto restartDefault;
	}

	case (17):
	{
		cout << "\n\n 17. Count Elements With Maximum Frequency." << endl
			<< endl;
		cout << "\nGiven an array consisting of positive integers." << endl;
		cout << "\nThe program returns the total frequencies of elements in the array,\nsuch that those elements all have the maximum frequency." << endl;

		vector<int> nums;
		int x, t;
		cout << "\nWrite the desired length for the array: " << endl;
		cin >> x;
		cout << "\nArray elements: " << endl;

		for (int i = 0; i < x; i++)
		{
		restart1:
			cout << "Write the value for element nr." << i << ": " << endl;
			cin >> t;
			if (t < 0)
			{
				cout << "\nOnly positive numbers allowed." << endl;
				goto restart1;
			}
			nums.push_back(t);
		}

		cout << "\nThe given array is: ";
		printVector(nums);

		cout << "\n\nThe number of elements in the array with maximum frequency is " << maxFrequencyElements(nums) << "." << endl;
		goto restartDefault;
	}

	case (18):
	{
		cout << "\n\n 18. Unique Number of Occurrences." << endl
			<< endl;
		cout << "\nGiven an array of integers,\nthe program shows if the number of occurrences of each value in the array is unique otherwise." << endl;

		vector<int> nums;
		int x, t;
		cout << "\nWrite the desired length for the array: " << endl;
		cin >> x;
		cout << "\nArray elements: " << endl;

		for (int i = 0; i < x; i++)
		{

			cout << "Write the value for element nr." << i << ": " << endl;
			cin >> t;

			nums.push_back(t);
		}

		cout << "\nThe given array is: ";
		printVector(nums);

		if (uniqueOccurrences(nums))
		{
			cout << "\n\nNo two values have the same number of occurrences." << endl;
		}
		else
		{
			cout << "\n\nTwo or more values have the same number of occurrences." << endl;
		}

		goto restartDefault;
	}

	case (19):
	{
		cout << "\n\n 19. N-Repeated Element in Size 2N Array." << endl
			<< endl;

		cout << "Given an integer array." << endl;
		cout << "\nThe program determines if there exists an element that is repeated n times," << endl;
		cout << "where n is half the size of the array." << endl;

		vector<int> nums;
		int x, t;
		cout << "\nWrite the desired length for the array: " << endl;
		cin >> x;
		cout << "\nArray elements: " << endl;

		for (int i = 0; i < x; i++)
		{

			cout << "Write the value for element nr." << i << ": " << endl;
			cin >> t;

			nums.push_back(t);
		}

		cout << "\nThe given array is: ";
		printVector(nums);

		if (repeatedNTimes(nums) == 0)
		{
			cout << "\nThere isn't an element that is repeated " << nums.size() / 2 << " times." << endl;
		}
		else
		{
			cout << "\nThe element that is repeated " << nums.size() / 2 << " times is: " << repeatedNTimes(nums) << "." << endl;
		}

		goto restartDefault;
	}

	case (20):
	{
		cout << "\n\n 20. Rings and Rods." << endl
			<< endl;

		cout << "There are n rings and each ring is either red, green, or blue.\nThe rings are distributed across ten rods labeled from 0 to 9." << endl;
		cout << "\nGiven a string that describes the n rings that are placed onto the rods.\n\nEvery two characters in rings forms a color-position pair that is used to describe each ring where:" << endl;
		cout << "\nThe first character of the ith pair denotes the ith ring's color ('R', 'G', 'B')." << endl;
		cout << "The second character of the ith pair denotes the rod that the ith ring is placed on ('0' to '9')." << endl;
		cout << "\nThe program returns the number of rods that have all three colors of rings on them." << endl;

		string s;
	reString:
		addString(s);
		cout << "\nDo you want to continue adding rings? ('Y'->Yes || 'N'->No)" << endl;
		char test;
		cin >> test;

		if (test == 'Y' || test == 'y')
		{
			goto reString;
		}

		cout << "\n\nThe given string is: " << s << endl;

		cout << "\nThe number of rods that have all three colours of rings on them is: " << countPoints(s) << endl;

		goto restartDefault;
	}
	default:
		cout << "The number you wrote doesn't correspond to any function." << endl;
	restartDefault:
		cout << "\nDo you want to relaunch the program('Y') or to end it('N')." << endl;

		char testDefault;
		cin >> testDefault;

		switch (testDefault)
		{
		case 'Y':
			goto restart;
		case 'y':
			goto restart;

		case 'N':
			return 0;
		case 'n':
			return 0;
		default:
			cout << "Not a supported answer.\n";
			goto restartDefault;
		}
	}

	return 0;
}