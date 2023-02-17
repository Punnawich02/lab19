#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades)
{
    ifstream name_sc(filename.c_str());
    string text;
    char name[100];
    int a,b,c,i = 0;
    char format[] = "%[^:]:%d %d %d";
    while(getline(name_sc,text))
    {
        sscanf(text.c_str(),format,name,&a,&b,&c);
        names.push_back(name);
        scores.push_back(a+b+c);
        grades.push_back(score2grade(scores.at(i)));
        i++;
    }
}

void getCommand(string &command ,string &key){
    cout << "Please input your command: ";
    string comm;
    char com[10],ke[100];
    getline(cin,comm);
    sscanf(comm.c_str(),"%s %[^1234567890]",com,ke);
    command = com;
    key = ke;
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key)
{
    bool check = 1;
    cout << "---------------------------------" << endl;
    for(int i=0;i<26;i++)
    {
        if(toUpperStr(names.at(i)) == toUpperStr(key))
        {
            cout << names.at(i) << "'s score = " << scores.at(i) << endl;
            cout << names.at(i) << "'s grade = " << grades.at(i) << endl;
            check = 0;
        }
    }
    if(check == 1) cout << "Cannot found." << endl;
    cout << "---------------------------------" << endl;
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key)
{
    bool check = 1;
    cout << "---------------------------------" << endl;
    for(int i=0;i<26;i++)
    {
        if(grades.at(i) == key[0])
        {
            cout << names.at(i) << " (" << scores.at(i) << ")" << endl;
            check = 0;
        }
    }
    if(check == 1) cout << "Cannot found." << endl;
    cout << "---------------------------------" << endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}