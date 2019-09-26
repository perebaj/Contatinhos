#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <boost/algorithm/string/join.hpp>
#include <sstream>


using namespace std;

bool interpreter(vector<string> args){
    map<string, string> contact_schedule;
    if((args[0]).compare("I") == 0){
        contact_schedule.insert({args[1],args[2]});
        cout << "Inserido" << endl;
        return true;
    }
    else if((args[0]).compare("R") == 0){
        cout << "Remoção" << endl;
        return true;
    }
    else if((args[0]).compare("A") == 0){
        contact_schedule.erase(args[1]);
        cout << "Alteração" << endl;
        return true;
    }
    else if ((args[0]).compare("S") == 0){
        cout << "Saindo" << endl;
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
        flag = interpreter(input);
        
    }while(flag);

    return 0;
}