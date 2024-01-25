#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>

#include "GenericHeap.h"
#include "Trie.h"
#include "HeapApplications.h"
#include "Student.h"
using namespace std;

static const string STUDENT_PATH = "students.txt";

void printArray(string array[], int len) {
	if (0 == len) {
		cout << "[]";
		return;
	}
	cout << "[";
	for (int i = 0; i < len - 1; i++) {
		cout << array[i] << ", ";
	}
	cout << array[len - 1] << "]";
}

template<typename F>
void printVector(vector<F> &students) {
	int len = students.size();
	if (0 == len) {
		cout << "[]";
		return;
	}
	cout << "[";
	for (int i = 0; i < len - 1; i++) {
		cout << students.at(i).toString() << ", ";
	}
	cout << students.at(len - 1).toString() << "]";
}

void testTrie() {
	Trie trie;
	cout << "*** Test Trie (Spell Checker) ***" << endl << endl;
	string dictionary[] = { "abc$", "abcd$", "bce$", "abx$", "acfe$", "bfr$",
			"de$" };
	int numWordsInDict = 7;
	for (int i = 0; i < numWordsInDict; i++)
		trie.insert(dictionary[i]);

	string document[] = { "abc", "def", "abcd", "bce", "abx", "acfe", "bfr",
			"xyz", "de", "tyu", "ab" };
	int numWordsInDoc = 11;
	bool spellCheck[numWordsInDoc];

	for (int i = 0; i < numWordsInDoc; i++) {
		string word = document[i] + "$";
		spellCheck[i] = trie.search(word);
	}

	cout << "Dictionary: ";
	printArray(dictionary, numWordsInDict);
	cout << endl;

	cout << "Document:   ";
	printArray(document, numWordsInDoc);
	cout << endl;

	cout << endl << "Incorrect spellings: ";
	for (int i = 0; i < numWordsInDoc; i++) {
		if (!spellCheck[i])
			cout << document[i] << " ";
	}
}

void testHeap() {
	cout << "\n*** Test Heap Sort ***" << endl << endl;
	string array[] = { "abc", "def", "abcd", "bce", "abx", "acfe", "bfr", "xyz",
			"de", "tyu", "ab", "abcd", "xy", "zxy", "abx", "def" };
	int length = 16;
	cout << "Before Sorting: ";
	printArray(array, length);
	cout << endl;
	HeapApplications ha;
	ha.heapSort(array, length);
	cout << "After Sorting:  ";
	printArray(array, length);
	cout << endl;
}

void testTopKElements() {
	cout << "*** Test Top-k ***\n" << endl;
	vector<Student> students = Student().readStudents(STUDENT_PATH);
	cout << "Original Array:     ";
	printVector(students);
	cout << endl;
	HeapApplications ha;
	vector<Student> top3 = ha.topK(students, 3);
	vector<Student> top7 = ha.topK(students, 7);
	vector<Student> all = ha.topK(students,
			students.size());
	cout << "Highest 3 students: ";
	printVector(top3);
	cout << endl;
	cout << "Highest 7 students: ";
	printVector(top7);
	cout << endl;
	cout << "All students:       ";
	printVector(all);
}

int main() {
	testTrie();
	cout << endl;
	testHeap();
	cout << endl;
	testTopKElements();
	return 1;
}
