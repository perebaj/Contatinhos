#include "interpreter.h"
#include "worker.h"
#include <iostream>
#include <iterator>
#include <boost/algorithm/string/join.hpp>
#include <sstream>

void interpreter::exec()
{
    vector<string> input;

    do
    {
        input = read();
        cout << input[0] << endl;

    } while (run_all(input));
}

vector<string> interpreter::read()
{
    string input;
    vector<string> splitted_input;
    cout << "[SHELL>$]";

    do
    {
        if (this->_input.compare("cin"))
            getline(cin, input);
        

    } while (!input.compare(""));
    //Separa o input do usuário por empaço e coloca-o no vector splitted_input
    stringstream iss(input);
    if (input.compare("") != 0)
    {
        for (string s; iss >> input;)
        {
            splitted_input.push_back(input);
        }

        transform(splitted_input[0].begin(), splitted_input[0].end(), splitted_input[0].begin(), ::toupper); // Colocar o primeiro argumento em MAIÚSCULO


    }
    return splitted_input;
}

bool interpreter::run_all(vector<string> args)
{
    if (args[0].compare("S"))
        return true;
    return false;
}

interpreter::interpreter(string in)
{
    this->_input = in;
}