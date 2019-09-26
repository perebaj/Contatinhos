#include <vector>
#include <string>
#include <iostream>
#include <list>


#include "worker.h"



using namespace std;

#ifndef INTEPRETER_H
#define INTERPRETER_H


class interpreter{
public:
    interpreter(string input);
    // virtual ~interpreter();
    list<worker*> *workers;
    void exec();
    bool run_all(vector<string> input);
    vector<string> read();
private:
    string _input;
};

#endif