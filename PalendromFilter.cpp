#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int UnicPalindrome(const vector <string>& jp) {
	set <string> PO;
	for (auto p : jp) {
		PO.insert(p);
	}
	return PO.size();
}

bool IsPalindrome(const string& word) {
	string temp = word;
	for (int i = 0; i < word.size(); i++) {
		temp[word.size() - i - 1] = word[i];
	}
	if (temp == word) {
		return true;
	}
	else {
		return false;
	}
}

vector <string> SplitInToWords(const string& text) {
	vector <string> words;
	string word;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ') {
			words.push_back(word);
			word = ""s;
		}
		else {
			word += text[i];
		}
	}
	words.push_back(word);
	return words;
}

vector <string> PalFilter(const vector <string>& words, const int min_len) {
	vector <string> res;
	for (auto p : words) {
		if (p.size() >= min_len) {
			if (IsPalindrome(p)) {
				res.push_back(p);
			}
		}
	}
	return res;
}

void enter(const vector <string>& vec) {
	for (auto p : vec) {
		cout << p << endl;
	}
}

string ReadQuery() {
	string hallo;
	getline(cin, hallo);
	return hallo;
}

int main() {
	const string text = ReadQuery();
	vector <string> many_words;
	many_words = SplitInToWords(text);
	many_words = PalFilter(many_words, 4);
	cout << UnicPalindrome(many_words);
}