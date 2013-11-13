/**   @file Gradebook.cpp    
      @author Harry Kran-Annexstein 
      @date 10-06-2013
      
      Implementation of the Gradebook class
      */

#include <Gradebook.h>

#include <math.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Gradebook::Gradebook() {
	head = oldhead = NULL; 
	size = 0;
	sourcefile = "";
}

Gradebook::Gradebook(const string &filename) {
	sourcefile = filename;
	ifstream book;
	book.open(filename.c_str());
	int s;
	oldhead = NULL;
	size = 0;
	while(book >> s){
		oldhead = head;
		head = new node;
		head->score = s;
		head->next = oldhead;
		size++;
	}
	book.close();		  
}

Gradebook::Gradebook(const Gradebook &that) {
  node* iter;
	iter = that.head;
	oldhead = NULL;	
	for (int i = 0; i < size; i++) {
		oldhead = head;
		head = new node;
		head->score = iter->score;
		head->next = oldhead;
		iter = iter->next;
	}
}

Gradebook::~Gradebook() { 
	node* oldhead;	
	for (int i = 0; i < size; i++) {
		oldhead = head;
		head = head->next;
		delete oldhead;
	}
}

void Gradebook::addScore(double grade) {
	oldhead = head;
	head = new node;
	head->score = grade;
	head->next = oldhead;
	size++;
}

double Gradebook::getScoreAt(int i) {
	node* iter;
	iter = head;
	if ((head == NULL)||(i >= size)) {
		return -1;
	}
	for (int j = 0; j < size-i; j++) {
		iter = iter->next;
	}
	return iter->score;  
}

int Gradebook::getCount() {
  return size;
}

string Gradebook::getSourceFile() {
	return sourcefile;
}  

double Gradebook::getMean() {
	double total = 0;
	node* iter;
	iter = head;
	for (int i = 0; i < size; i++) {
		total += iter->score;
		iter = iter->next;
	}
	return total/size;
}

double Gradebook::getMin() {
	node* iter;
	iter = head;
	double min = iter->score;
	for (int i = 0; i < size-1; i++) {
		iter = iter->next;
		if (min > iter->score) {
			min = iter->score;
		}
	}
	return min;
}

double Gradebook::getMax() {
	node* iter;
	iter = head;
	double max = iter->score;
	for (int i = 0; i < size-1; i++) {
		iter = iter->next;
		if (max < iter->score) {
			max = iter->score;
		}
	}
	return max;
}

double Gradebook::getMedian() {
  // Optional - extra credit method
}

double Gradebook::getStdDev() {
	double variance = 0;
	double mean = getMean();
	node* iter;
	iter = head;
	for (int i = 0; i < size; i++) {
		variance += pow((iter->score-mean),2);
		iter = iter->next;
	}
	variance = variance/size;
	return sqrt(variance);
}

int Gradebook::scoresInRange(double low, double high) { 
	int count = 0;
	node* iter;
	iter = head;
	for (int i = 0; i < size; i++) {
		if ((iter->score >= low)&&(iter->score <= high)) {
			count++;
		}
		iter = iter->next;
	}
	return count;
}
