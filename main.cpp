#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <boost/algorithm/string/join.hpp>
#include <sstream>


using namespace std;

bool interpreter(string argzero){
    if(argzero.compare("I") == 0){
        cout << "Inserção" << endl;
        return true;
    }
    else if(argzero.compare("R") == 0){
        cout << "Remoção" << endl;
        return true;
    }
    else if(argzero.compare("A") == 0){
        cout << "Alteração" << endl;
        return true;
    }
    else if (argzero.compare("S") == 0){
        cout << "Sainda" << endl;
        return false;
    }
    else return false;
}

vector<string> splitted(){
    string input;
    vector<string> splitted_input;

    getline(cin, input);

    stringstream iss(input);
    if (input.compare("") != 0)
    {
        for (string s; iss >> input;)
            splitted_input.push_back(input);
        transform(splitted_input[0].begin(), splitted_input[0].end(), splitted_input[0].begin(), ::toupper);
    }
    return splitted_input;
}


int main()
{
    vector<string> input;
    bool flag;
    do{
        input = splitted();
        flag = interpreter(input[0]);
        
    }while(flag);

    return 0;
}