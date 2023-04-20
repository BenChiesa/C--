#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ifstream filestream;
    filestream.open("hello.txt");
    
    ofstream ofile;
    ofile.open("goodbye.txt");
    
    string text;
    
    if(!filestream.is_open()){
        cout << "File is not open" << endl;
    }
    
    if(filestream.bad()){
        cout << "File is bad" << endl;
    }
    
    if(filestream.good()){
        cout << "File is good." << endl;
    }
    
    while(!filestream.eof() && filestream.is_open()){
        //filestream >> text;
        getline(filestream, text);
        ofile << text << endl;
    }
    
    filestream.close();
    ofile.close();
    
    return 0;
}