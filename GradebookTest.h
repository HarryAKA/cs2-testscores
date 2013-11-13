/**   @file GradebookTest.h    
      @author Harry Kran-Annexstein 
      @date 10-06-2013      
      
      Unit tests for the gradebook.
      */

#ifndef GRADEBOOK_TEST_H
#define GRADEBOOK_TEST_H

#include <Gradebook.h>

#include <cxxtest/TestSuite.h>

class GradebookTest : public CxxTest::TestSuite {
public:
	void testPassByFileName() {
		Gradebook gb("grades.txt");
	}
	void testAddScores() {
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(8, gb.getCount());
	}	
	void testGetScoreAt() {
		Gradebook gb;	
		gb.addScore(50);
		gb.addScore(60);
		gb.addScore(70);
		TS_ASSERT_EQUALS(60, gb.getScoreAt(2));
	}
	void testGetSourceFileEmpty() {
		Gradebook gb;
		TS_ASSERT_EQUALS("", gb.getSourceFile());
	}
	void testGetSourceFileGrades() {
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS("grades.txt", gb.getSourceFile());
	} 
	void testGetMean() {
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(87.75, gb.getMean());
	}
	void testGetMin() { 
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(73, gb.getMin());
	}
	void testGetMax() {
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(100, gb.getMax());
	}
	void testGetStdDev() {
		Gradebook gb("grades.txt");
		TS_ASSERT_DELTA(8.85649, gb.getStdDev(),0.0001);
	}
	void testScoresInARange() {	
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(4, gb.scoresInRange(90,100));
	}
	void testScoresInBRange() {	
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(3, gb.scoresInRange(80,89));
	}
	void testScoresInCRange() {	
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(1, gb.scoresInRange(70,79));
	}
	void testScoresInDRange() {	
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(0, gb.scoresInRange(50,69));
	}
	void testScoresInFRange() {	
		Gradebook gb("grades.txt");
		TS_ASSERT_EQUALS(0, gb.scoresInRange(0,49));
	}
	void testAddOne() {
    Gradebook gb;
    gb.addScore(50);
    TS_ASSERT_EQUALS(1, gb.getCount());
    TS_ASSERT_DELTA(50, gb.getMean(), 0.001);
  }
  void testAddMultiple() {
    Gradebook gb;
    gb.addScore(75);
    TS_ASSERT_EQUALS(1, gb.getCount());
    gb.addScore(85);
    TS_ASSERT_EQUALS(2, gb.getCount());
    TS_ASSERT_DELTA(80, gb.getMean(), 0.001);
  }
  void testAddALot() {
    Gradebook gb;
    for (int i = 0; i < 20000; i++) {
      gb.addScore(90);
    }
    for (int i = 0; i < 20000; i++) {
      gb.addScore(100);
    }
    TS_ASSERT_EQUALS(40000, gb.getCount());
    TS_ASSERT_DELTA(95, gb.getMean(), 0.001);
  }
  void testStdDev() {
    Gradebook gb;
    gb.addScore(90);
    gb.addScore(92);
    gb.addScore(94);
    TS_ASSERT_EQUALS(3, gb.getCount());
    TS_ASSERT_DELTA(92.0, gb.getMean(), 0.001);
    TS_ASSERT_DELTA(1.63299, gb.getStdDev(), 0.01);
  }
};

#endif
