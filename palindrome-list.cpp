#include <iostream>
#include <string>

using namespace std;

class list
{
	public: 

		bool isPalindrome(int length);
		void add(char letter);
		string toString(int length);

	private:

		struct node
		{
			char letter;
			struct node *next;
			struct node *prev;
		};

		struct node *head=NULL;
		struct node *last=NULL;
};

void list::add(char letter)
{
	struct node* curr = new node;
	
	curr->letter = letter;

	curr->next = head;
	curr->prev = NULL;

	if (head != NULL)
		head->prev = curr;

	head = curr;

	while (curr != NULL)
	{
		last = curr;
		curr = curr->next;
	}
}

bool list::isPalindrome(int length)
{
	struct node *curr = head;
	struct node *curr2 = last;

	int count=0;

	while (count<(length/2)&&curr!=NULL)
	{
		if (curr->letter != curr2->letter)
		{
			return false;
		}
		curr = curr->next;
		curr2 = curr2->prev;
		count++;
	}

	return true;
}

string list::toString(int length)
{
	struct node *curr = head;
	string word;
	int index=0;

	while (curr != NULL&&index<length)
	{
		word=curr->letter+word;
		index++;
		curr = curr->next;
	}

	return word;
}

int main()
{
	string word;
	cout << "Welcome to the Palindrome program! Enter -1 to exit.\n" << endl;
	
	while (word!="-1")
	{
		cout << "Enter your word: ";
		cin >> word;

		if (word == "-1")
		{
			break;
		}

		int length = word.length();

		list sentence;

		for (int i = 0; i < length; i++)
		{
			sentence.add(word[i]);
		}
		if (sentence.isPalindrome(length))
		{
			cout << "\nYes, " << sentence.toString(length) << " is a palindrome!\n" << endl;
		}
		else
		{
			cout << "\nSorry, " << sentence.toString(length) << " is not a palindrome.\n" << endl;
		}
	}

	//system("pause");
	return 0;
}