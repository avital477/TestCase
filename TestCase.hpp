#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int numOfFunction = 0;
int Pass=0;
int NoPass=0;

class TestCase{
    public:
    string myname;
    ostream& os;
    
    TestCase(string TestName, ostream& os):os(os){
        numOfFunction = 0;
        Pass=0;
        NoPass=0;
        myname= TestName;
    }
    
    template <typename T> TestCase& check_equal(T a, T b){
        numOfFunction++;
        if(a == b)
            Pass++;
        else{
             NoPass++;
            os << myname <<": Failure in test #" << numOfFunction <<": " << a <<" should equal" << b<<"!"<<endl;     
         }
    return *this;     
    }

    template <typename T> TestCase& check_different(T a, T b){
        numOfFunction++;
        if(a == b){
            NoPass++;
            os << myname <<": Failure in test #" << numOfFunction <<": " << a <<" should not equal" << b<<"!"<< endl; 
        }
        else
            Pass++;
        return *this;      
    }
    template <typename T> TestCase& check_output(T variable, string s){
        numOfFunction++;
        stringstream p;
        p << variable;   // תכניס את os לp- תהפוך אותו ךstring
        if(p.str() != s){
            NoPass++;
            
            os << myname <<": Failure in test #" << numOfFunction <<": string value should be "<< s <<" but is " << variable << endl;
        }
        else
            Pass++;

        return *this;  
    }

    template <typename Function, typename T, typename Ans> TestCase& check_function(Function f, T a , Ans ans ) {
        numOfFunction++;
        if(f(a) == ans){
            Pass++;
        }
        else{
            NoPass++;
        os << myname <<": Failure in test #" << numOfFunction <<": Function should return "<< ans << " but returned "<<f(a)<<"!" << endl;
        }
     return *this;  
    }
    TestCase& print(){
    cout << myname <<": " << NoPass << " failed, " << Pass<< " passed, " << numOfFunction << " total." << endl ;
    cout << "---" << endl; 
    return *this;  
    }

};

