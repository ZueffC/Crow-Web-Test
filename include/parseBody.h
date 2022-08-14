#pragma once
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

map<string, string> parsedBody;
map<string, string> parseBody(string body){
    if(!body.empty()) {

    }

    return parsedBody;
}


vector<string> &split(const string &s, char delim, vector<string> &elems){
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}
