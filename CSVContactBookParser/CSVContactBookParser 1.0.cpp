
/* 
 * A console based C++ program that reads lines of strings from a vector<string>
 * which are further themselves a bunch of comma separated values. The first 
 * string is the name of columns separated by comma and the strings following 
 * are the contact data. 
 * (CSV Format Only)
 * File:   ContactBookParser.cpp 
 * Version: 1.0
 * Author: Anil Jaiswal
 * Created on 01 July 2013, 14:40
 */

#include <string>       //string class
#include <vector>       //STL vector Container
#include <iostream>     //count, cin
#include <algorithm>    //find())
using namespace std;


class splitstring : public string  //splitstring class extends the string class
{                                  //so that it can create split-able string obs     
    vector<string> fields;
   public:
    splitstring(string s) : string(s) { };
    vector<string>& split(char delim, int rep=0); // split() takes a delimiter
                                                  // on the basis of which it      
};                                                // splits the splitstring objs

void printNames(vector<string>& csv)    // takes a csv vector<string> as
{                                              // input and on the basis of 1st
                                               // column header, it processes 
                                               // the rest of entries. 
    splitstring s(csv.at(0));
    vector<string> fields = s.split(',');
    vector<string>::iterator itPhone,itName;
    itPhone=find(fields.begin(),fields.end(),"Phone");
    int posPhone = distance(fields.begin(),itPhone); //position of column "Phone" in the split string of header column of vector
    itName=find(fields.begin(),fields.end(),"Name");
    int posName = distance(fields.begin(),itName);   //position of column "Phone" in the split string of header column of vector
    vector<string> words;                               
    for(int i=1;i<csv.size();i++)                    //loop processes each element of csv vector and gives output of required fields
    {                                                //such as names, phone no.. etc as specified by user in argument list
        s=splitstring(csv.at(i));
        words=s.split(',');
        string phone = words.at(posPhone);
        string name = words.at(posName);
        cout<<"Name : "<<name<<"| Phone No: "<<phone<<endl;
    }
}

// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
vector<string>& splitstring::split(char delim, int rep) 
{
    if (!fields.empty()) 
        fields.clear();  // empty vector if necessary
    string temp = data();// data() copies the contents of string object on which this function is called into new 'temp' string object
    string buffer = "";  // used to extract & process individual characters
    int i = 0;
    while (i < temp.length()) 
    {
        if (temp[i] != delim)
            buffer += temp[i];
        else if (rep == 1) 
        {
            fields.push_back(buffer);
            buffer = "";
        } 
        else if (buffer.length() > 0) 
        {
            fields.push_back(buffer);
            buffer = "";
        }
        i++;
    }
    if (!buffer.empty())        //if buffer is still not empty, push_back on to fields vector
        fields.push_back(buffer);
    return fields;
}


int main()
{
    vector<string> csv; // The program can be easily modified to read from an actual csv file by using vector<string> and getline()
    csv.push_back("Name,Address,Phone,DOB"); // column headers
    csv.push_back("Bob Jaker,20th Hill Road California,837-7247882,12-03-1982");
    csv.push_back("Mario Luigi,120 Sand Hill Road,98272-28388,30-08-1971");
    csv.push_back("Biswanath Rai,488 Banjara Apartments Kolkata,625-25423-263,16-12-1991");
    printNames(csv);
    cin.get();
    return 0;
}