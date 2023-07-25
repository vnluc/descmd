#include <iostream>
#include "data_conv.h"
#include <vector>

using namespace std;

#include "tests.h"
#include "des.h"



void usage()
{
    std::cout << "Usage: des -e/-d  key [input-hex]" << endl;
}


int main(int argc, char **argv)
{
    //alltests(); return 0;

    if(argc < 4)
    {
        usage();
        return 1;
    }

    string enc_dec = argv[1];
    if(enc_dec != "-e" && enc_dec != "-d")
    {
        usage();
        return 2;
    }

    if(enc_dec == "-e")
    {
        std::cout << "encrypting..." << endl;
    }
    else {
        std::cout << "decrypting..." << endl;

    }

    string input;
    if(argc > 3)
        input  = argv[3];

    if (input.length() % 16 != 0)
    {
        cout << "data is not multiple of 8 bytes. please pad it";
        return 1;
    }





    // key
    string s_key = argv[2];
    if (s_key.length() == 16){

        cout << "Key single length" << endl;
        // single length -des
        ui64 key = strtoull(argv[2], nullptr, 16);

        DES des(key);

        int i = 0;
        string s_encrypted = "";
        
        while (i < input.length()){
            string block = input.substr(i, 16);
            // vector<char> blockc = HexToBytes(block);
            

            ui64 data = strtoull(block.c_str(), nullptr, 16);

            ui64  encrypted ;
            if (enc_dec == "-e"){
                encrypted = des.encrypt(data);

            }
            else {
                 encrypted = des.decrypt(data);
            }
            
            char s_buff [24];
            sprintf(s_buff, "%016lx", encrypted);

            s_encrypted = s_encrypted + s_buff;
            i = i + 16;

        }

        cout << s_encrypted << endl;

    }
    
    if (s_key.length() == 32){

        cout << "3DES double length" << endl;
        // single length -des
        ui64  k1 = strtoull(s_key.substr(0, 16).c_str(), nullptr, 16);
        ui64  k2 = strtoull(s_key.substr(16, 16).c_str(), nullptr, 16);

        DES3 des(k1, k2, k1);

        int i = 0;
        string s_encrypted = "";
        
        while (i < input.length()){
            string block = input.substr(i, 16);
            // vector<char> blockc = HexToBytes(block);
            
            ui64 data = strtoull(block.c_str(), nullptr, 16);
            
            
            ui64  encrypted ;
            if (enc_dec == "-e"){
                encrypted = des.encrypt(data);

            }
            else {
                 encrypted = des.decrypt(data);
            }
            

            char s_buff [24];
            sprintf(s_buff, "%016lx", encrypted);

            s_encrypted = s_encrypted + s_buff;
            i = i + 16;

        }

        cout << s_encrypted << endl;
    }


    if (s_key.length() == 48){

        cout << "3DES tripple length" << endl;
        // single length -des
        ui64  k1 = strtoull(s_key.substr(0, 16).c_str(), nullptr, 16);
        ui64  k2 = strtoull(s_key.substr(16, 16).c_str(), nullptr, 16);
        ui64  k3 = strtoull(s_key.substr(32, 16).c_str(), nullptr, 16);

        DES3 des(k1, k2, k3);

        int i = 0;
        string s_encrypted = "";
        
        while (i < input.length()){
            string block = input.substr(i, 16);
            // vector<char> blockc = HexToBytes(block);
            
            ui64 data = strtoull(block.c_str(), nullptr, 16);
            
            ui64  encrypted ;
            if (enc_dec == "-e"){
                encrypted = des.encrypt(data);

            }
            else {
                 encrypted = des.decrypt(data);
            }

            char s_buff [24];
            sprintf(s_buff, "%016lx", encrypted);

            s_encrypted = s_encrypted + s_buff;
            i = i + 16;

        }

        cout << s_encrypted << endl;

    }


    return 0;
}
