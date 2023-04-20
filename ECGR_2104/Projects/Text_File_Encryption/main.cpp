#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

bool encrypt = false;
bool decrypt = false;

void encryption(int key, string input, string output, bool decrypt){
    int x, y, z;
    if(key > 26){
        int q = key / 26;
        int r = q * 26;
        key = key - r;
    }
    
    if(decrypt){
        key = key * (-1);    
    }
    
    ifstream ifile;
    ifile.open(input);
    
    ofstream ofile;
    ofile.open(output);
    
    string text;
    
    while(getline(ifile, text)){
        for(int i = 0; i < text.length(); i++){
            if(isalpha(text[i])){
                z = int(text[i]);
                text[i] = key + text[i];
                x = int(text[i]);
                if((z >= 65) && (z <= 90)){
                    if(x < 65){
                        y = 90 - (64 - x);
                        text[i] = char(y);
                    }
                        
                    else if(x > 90){
                        y = (64 + x) - 90;
                        text[i] = char(y);
                    }
                }
                
                if((z >= 97) && (z <= 122)){
                    if(x < 97){
                        y = 122 - (96 - x);
                        text[i] = char(y);
                    }
                        
                    else if(x > 122){
                        y = (96 + x) - 122;
                        text[i] = char(y);
                    }
                }
            }
        }
        
        ofile << text << endl;
    }
    
    ifile.close();
    ofile.close();
    
}

int main(int argc, char* argv[]){
    int key;
    stringstream j, k, l;
    int x;
    string input, output;

    for(int i = 0; i < argc; i++){
        if(argv[i][0] == '-'){
            if(argv[i][1] == 'e'){
                encrypt = true;
            }
            
            else if(argv[i][1] == 'd'){
                decrypt = true;
            }
            
            else if(argv[i][1] == 'k'){
                x = i + 1;
                j << argv[x];
                j >> key;
            }
            
            else if(argv[i][1] == 'i'){
                x = i + 1;
                k << argv[x];
                k >> input;
            }
            
            else if(argv[i][1] == 'o'){
                x = i + 1;
                l << argv[x];
                l >> output;
            }
        }
    }
    
    if(encrypt || decrypt){
        encryption(key, input, output, decrypt);
    }
    
    
    return 0;
}