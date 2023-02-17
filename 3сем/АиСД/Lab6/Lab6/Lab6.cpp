#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node
{
	char c;
	int freq;
	Node* left, * right;
};


Node* getNode(char c, int freq, Node* left, Node* right)
{
	Node* node = new Node();
	node->c = c;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

struct comp
{
	bool operator()(Node* left, Node* right)
	{
		return left->freq > right->freq;
	}
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		huffmanCode[root->c] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}


void buildHuffmanTree(string text)
{
	unordered_map<char, int> freq;
	for (char c : text) {
		freq[c]++;
	}

	cout << "Таблица встречаемости символов в тексте в процентном варианте:" << endl;
	unordered_map<char, int> ::iterator it = freq.begin();
	for (int i = 0; it != freq.end(); it++, i++) {
		cout << it->first << " — " << it->second * 100 / text.length() << "%" << endl;
	}
	cout << endl;

	priority_queue<Node*, vector<Node*>, comp> pq;

	for (auto p : freq) {
		pq.push(getNode(p.first, p.second, nullptr, nullptr));
	}

	while (pq.size() != 1)
	{
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top();	pq.pop();
		
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	Node* root = pq.top();

	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Коды Хаффмана:\n";
	for (auto p : huffmanCode) {
		cout << p.first << " " << p.second << '\n';
	}

	cout << "\nВведенная строка :\n" << text << '\n';

	string str = "";
	for (char c : text) {
		str += huffmanCode[c];
	}
	cout << "\nЗакодированная строка: \n" << str << '\n';
}


int main()
{
	setlocale(LC_ALL, "rus");
	string str = "фанат";
	buildHuffmanTree(str);
	return 0;
}