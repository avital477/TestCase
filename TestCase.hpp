#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int numOfFunction = 0;

class TestCase(){

    TestCase(string TestName, ostream& os){
        numOfFunction = 0;
    }
    template <typename T, typename U>{
        void check_equal(T a, T b){
            numOfFunction++;
            if(a != b)
                print();   
        }
        void check_different(T a, T b){
            numOfFunction++;
            if(a == b)
                print(); 
        }
        void check_output(T os, string s){
            numOfFunction++;
            os << s;
            string os_str =  os.str();
            if(os_str != s)
                print();
        }
        //void check_function(T ) 
        void print(){
          cout<< TestName <<": Failure in test #" << numOfFunction << ": Function should return "<< 


        }
    }




}