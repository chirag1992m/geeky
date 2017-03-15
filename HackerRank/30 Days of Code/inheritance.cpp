/*
https://www.hackerrank.com/challenges/30-inheritance
*/
class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
  		// Write your constructor
        Student(string firstname, string lastname, int id, vector<int> &scores) : Person(firstname, lastname, id) {
            testScores = scores;
        }
  
  		// Write char calculate()
        char calculate() {
            double sum = 0;
            for(int i=0; i < testScores.size(); i++) {
                sum += testScores[i];
            }
            sum /= testScores.size();
            
            if(sum < 40) {
                return 'T';
            } else if (sum < 55) {
                return 'D';
            } else if (sum < 70) {
                return 'P';
            } else if(sum < 80) {
                return 'A';
            } else if(sum < 90) {
                return 'E';
            } else {
                return 'O';
            }
        }
};