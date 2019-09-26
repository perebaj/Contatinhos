#include "interpreter.h"
#include <iostream>
#include <iterator>

void interpreter::exec() {
    vector<string> input;

    do{
        input = read();

    }while (run_all(input));
}



vector<string> interpreter::read(){
    string input;
    vector<string> vecinput;
    cout << "[SHELL>$]";

    do{
       getline(cin,input);
       cout << input << endl;
        
    }while(!input.compare(""));

    return vecinput;
    
}


bool interpreter::run_all(vector<string>args) {
    if(args[0].compare("S")){
        for (list<worker*>::iterator it = (this->workers->begin()); it != (this->workers->end()); it++)
        
        worker *wk = *it;    
        return true;
    
    }
    return false;
}


interpreter::interpreter(string in){
    this->_input = in;

}