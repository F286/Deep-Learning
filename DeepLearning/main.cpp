//
//  main.cpp
//  DeepLearning
//
//  Created by Free Debreuil on 2/7/16.
//  Copyright © 2016 Binary Pipeline. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

#include "Neuron.cpp"

streampos size;
char * memblock;

void LoadData()
{
    ifstream file;
    file.open("train-images-idx3-ubyte",
              ios::binary | ios::in | ios::ate);
    
    if(file.is_open())
    {
        size = file.tellg();
        memblock = new char[size];
        file.seekg(ios::beg);
        file.read(memblock, size);
        
//        int magic;
//        
//        file >> magic;
//        
//        cout << magic;
        
        int magic = 0;
        
        int i = 0;
        for (; i < 8; i++)
        {
            magic += pow(2, 7 - i) * memblock[i];
//            cout << memblock[i] << "\n";
        }
        cout << magic;
        
//        for (; i < 4; i++)
//        {
//            cout << memblock[i];
//        }
        
//        for (int i = 0; i < size; i++)
//        {
//            cout << memblock[i];
//        }
        
//        memblock++;
//        for (int i = 0; i < 10; i++)
//        {
//            cout << memblock[size] << "\n";
//            size++;
//            file.seek
//        }
//        cout << memblock[size] << "\n";
        
//        file.read(memblock, size);
        
//        char * header;
//        
//        file.read(header, 2);
        
        // Dispose
//        file.seekg(ios::beg);
        delete [] memblock;
        
//        cout << size << "\n";
    }
    else
    {
        cout << "Could not open file" << "\n";
    }
    
    file.close();
}

int main(int argc, const char * argv[])
{
    LoadData();

//    cout << *memblock;
//    for (char* i = memblock; *i; ++i)
//    {
//        cout << *i;
//    }
    
    Neuron n {};
    n.Calculate();

    // insert code here...
//    std::cout << "Finish!\n";
    cout << "\n";
    return 0;
}