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
    ifstream name_sc(filename);
    string text;
    char text2[100];
    int i = 0;
    while(getline(name_sc,text))
    {
        text2[i] = text;
        i++;
    }
    int a,b,c,score;
    char name[100];
    char format[] = "%[^:] %d %d %d";
    sscanf(text2,format,name,&a,&b,&c);
    names.push_back(name);
    scores.push_back(a+b+c);
    score = a+b+c;
    grades.push_back(score2grade(score));
}

void getCommand(string &command ,string &key){
    cout << "Please in put your command: ";
    cin >> command >> key;
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key)
{
    cout << "---------------------------------";
    for(int i=0;i<26;i++)
    {
        if(toUpperStr(names.at(i)) == key)
        {
            cout << names.at(i) << "'s score = " << scores.at(i);
            cout << names.at(i) << "'s grade = " << grades.at(i);
        }
        else
        {
            cout << "Cannot found.";
        }
    }
    cout << "---------------------------------";
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key)
{
    cout << "---------------------------------";
    for(int i=0;i<26;i++)
    {
        if(toUpperStr(grades.at(i)) == key)
        {
            cout << names.at(i) << "(" << scores.at(i) << ")";
        }
        else
        {
            cout << "Cannot found.";
        }
    }
    cout << "---------------------------------";
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
        else
        {
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }

    }while(true);
    
    return 0;
}
