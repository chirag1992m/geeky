/*
https://www.hackerrank.com/challenges/30-class-vs-instance
*/
class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if(initialAge < 0) {
            age = 0;
            cout<<"Age is not valid, setting age to 0."<<endl;
        } else {
            age = initialAge;
        }
    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
        if(age < 13)
            cout<<"You are young.";
        else if(age < 18)
            cout<<"You are a teenager.";
        else
            cout<<"You are old.";
        cout<<endl;
    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        age++;
    }