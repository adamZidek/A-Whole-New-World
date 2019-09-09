/*
	Adam Zidek
	CSCI 360
	Homework 4
	Off Putting
*/
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>

std::string DEFAULT_MODEL_NAME = "FloorModel";

using namespace std;

int main()
{
    string modelName = DEFAULT_MODEL_NAME;
    std::ofstream file;
    long count = 0;
    long countTwo = 0;
    vector <string> coords;
    long index = 0;
    
    file.open("floorModel.off");
    
    //Write initial off file stuff
    file<<"OFF"<<endl;
    file<<"160000 40000 0"<<endl;
    
    

    for(int row = -100; row < 100; row++)
    {
        countTwo++;
        for(int col = -100; col < 100; col++)
        {
            file<<row<<" 0 "<<col+1<<endl;
            file<<row<<" 0 "<<col<<endl;
            file<<row+1<<" 0 "<<col+1<<endl;
            file<<row+1<<" 0 "<<col<<endl;
        }
    }
    
    //Output faces
    for(int i = 0; i< 40000; i++)
    {
        file<<"4 "<<index<<" "<<index+1<<" "<<index+2<<" "<<index+3<<" "<<index+4<<endl;
        
        index+=4;
    }
    
    
    file.close();
    return 0;
}
