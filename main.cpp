#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <boost/algorithm/string/join.hpp>
#include <sstream>


using namespace std;
typedef int (*pfunc)(vector<string> arg);
/*
Protótipos
*/

int run(vector<string> args);
bool interpreter(vector<string> args);
vector<string> splitted();
int insertContact(vector<string> args);
int removeContact(vector<string> args);
int resume();
int exit();

void run_functions();
map<string,pfunc> functions;
map<string, string> contact_schedule;

int main()
{
    run_functions();
    vector<string> input;
    bool flag;
    do{
        input = splitted();
        flag = interpreter(input);
        
    }while(flag);

    return 0;
}

/*
@BRIEF
*/
int run(vector<string> args){
    if(functions.find(args[0]) != functions.end())
        return functions[args[0]](args);
    return 0;
}

/*
@BRIEF
*/
bool interpreter(vector<string> args){
    return(run(args));
}

/*
@BRIEF
*/
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


/*
@BRIEF
*/
int insertContact(vector<string> args){ // Inserir
    if(contact_schedule.find(args[1]) == contact_schedule.end()){
        contact_schedule.insert({args[1],args[2]});
        cout << "Inserido" << endl;
    }
    else
        cout << "Contatinho ja inserido" << endl;
    return true;
}

int exit(vector<string> args){ //Alterar contato
    if(args[0] == "S")
        return false;
    return false;
}

/*
@BRIEF
*/
int removeContact(vector<string> args){ //Remove Contato
    if(contact_schedule.find(args[1]) != contact_schedule.end()) {
        contact_schedule.erase(args[1]);
        cout << "Removido" << endl;
    }
    else{
        cout << "Operacao invalida: contatinho nao encontrado" << endl;
    }
    return true;
}

/*
@BRIEF
*/
int resume(){
    for(map<string, string>::iterator it = contact_schedule.begin(); it != contact_schedule.end(); ++it){
        cout << it->first << " => " 
        << it->second << endl;
    }
    return true;
}

int search(vector<string> args){
    if(contact_schedule.find(args[1]) == contact_schedule.end()){
        cout << "Operacao invalida: contatinho nao encontrado" << endl;
        return true;
    }
    else
        cout << "Contatinho encontrado: telefone " << contact_schedule.lower_bound(args[1])->second << endl;
    return true;
}

int change(vector<string> args){
    contact_schedule.lower_bound(args[1])->second = args[2];
    return true;
}

/*
@BRIEF
*/
void run_functions(){
    functions["I"] = (pfunc) insertContact;
    functions["R"] = (pfunc) removeContact;
    functions["RE"] = (pfunc) resume;
    functions["P"] = (pfunc) search;
    functions["S"] = (pfunc) exit;
    functions["A"] =  (pfunc) change;
}
