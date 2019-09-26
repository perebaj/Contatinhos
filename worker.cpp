#include "worker.h"

int I(vector<string> args){

    cout << "Inserindo Contato" << args[1] <<  "Com Telefone" << args[2];
    return 0;

}

// int P(vector<string> args){
//     return 0;
// }

// int A(vector<string> args){
//     return 0;

// }

worker::worker(){
    this->functions = new map<string,tfunc>;
    (*this->functions)["I"] = (tfunc) I;
    // (*this->functions)["P"] = (tfunc) P;
    // (*this->functions)["A"] = (tfunc) A;

}


worker::~worker(){
    delete this->functions;
}


int worker::run(vector<string> args){
    if((*this->functions).find(args[0]) != (*this->functions).end())
        return (*(*this->functions)[args[0]])(args);
    return 1;
} 
