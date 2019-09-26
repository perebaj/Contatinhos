#include <string>
#include <vector>
#include <map>
#include <iostream>


#ifndef WORKER_H
#define WORKER_H

using namespace std;


typedef int (*tfunc)(vector<string> arg);

class worker{
    public:
        worker();
        ~worker();
        int run(vector<string> arg);
    
    private:

        map<string,tfunc> *functions;
};


#endif