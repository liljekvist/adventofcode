#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
using std::cout;
using std::cin;
class data {
// Kommer inte ihåg om class defualtade till public eller private xd
public:
    data(int charPos1_in, int charPos2_in, char checkLetter_in, std::string password_in)
    :
    charPos1(charPos1_in),
    charPos2(charPos2_in),
    checkLetter(checkLetter_in),
    password(password_in)
    { /*Do nothing*/ }

    std::string passwordCheck(){
        int count = 0; //welp detta blev rätt fult. NTS skriva om detta
        if(password[charPos1 - 1] == checkLetter)
            count++;
        if(password[charPos2 - 1] == checkLetter)
            count++;
        if(count == 1)
            return password;
        else
            return "";
    }


private: 
    int charPos1;
    int charPos2;
    char checkLetter;
    std::string password;
};


std::vector<data> dataVec; // bad prac med global vars.

void split (std::string str)  
{  
    std::string const delims{ "- :\n" };
    int i = 0;
    size_t beg, pos = 0;
    while ((beg = str.find_first_not_of(delims, pos)) != std::string::npos)
    {
        int p1;
        int p2;
        char p3;
        std::string p4;
        pos = str.find_first_of(delims, beg + 1);
        switch(i)
        {
            case 0:
                p1 = std::stoi(str.substr(beg, pos - beg));
                i++;
                break;
            case 1:
                p2 = std::stoi(str.substr(beg, pos - beg));
                i++;
                break;
            case 2:
                p3 = str.substr(beg, pos - beg)[0]; // är alltid en bokstav så kan ta index 0
                i++;
                break;
            case 3:
                p4 = str.substr(beg, pos - beg);
                dataVec.push_back(data(p1,p2,p3,p4));
                i = 0;
                break;  
        }
    }
}

int main(int argc, char **argv){
    std::string tempStr;
    std::ifstream ifs("data.txt");
    tempStr.assign((std::istreambuf_iterator<char>(ifs)),(std::istreambuf_iterator<char>()));
    ifs.close();
    split(tempStr);
    std::vector<std::string> awnsers;
    for(int i = 0; i < dataVec.size(); i++){
        std::string awnser = dataVec[i].passwordCheck();
        if(!awnser.empty())
            awnsers.push_back(awnser);
    }
    cout << awnsers.size();
    return 0;
}