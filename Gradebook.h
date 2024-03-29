/**   @file Gradebook.h    
      @author Harry Kran-Annexstein 
      @date 10-06-2013
      
      Interface for the Gradebook class.
      */

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
using namespace std;

class Gradebook {
public:
  Gradebook();

  Gradebook(const string &filename);
 
  Gradebook(const Gradebook &that);

  virtual ~Gradebook();

  void addScore(double grade);

  double getScoreAt(int i);

  int getCount();

  string getSourceFile();

  double getMean();

  double getMin();

  double getMax();

  double getMedian();

  double getStdDev();

  int scoresInRange(double low, double high);
  
private:
	struct node {
		double score;
		struct node* next;
	};
	node* head;
	node* oldhead;
	int size;
	string sourcefile;
};

#endif
