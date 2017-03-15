/*
https://www.hackerrank.com/challenges/30-data-types
*/
// Declare second integer, double, and String variables.
int j = 0;
double k = 0.0;
string str;

// Read and save an integer, double, and String to your variables.
cin>>j>>k;
cin.ignore();
getline(cin, str);

// Print the sum of both integer variables on a new line.
cout<<i+j<<endl;

// Print the sum of the double variables on a new line.
cout<<setprecision(1)<<fixed<<d+k<<endl;

// Concatenate and print the String variables on a new line
// The 's' variable above should be printed first.
cout<<s+str;