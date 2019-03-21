#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Circle{
    int x, y;
    float radius;
public:
    Circle(int x = 0, int y = 0, float radius = 0): x(x), y(y), radius(radius)  {}
    void getdata()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "radius = " << radius << endl;
    }
};


Circle getdata(string toParse)
{
    int commaindex;
    int x_coord, y_coord;
    float radius;
    if(toParse.find("circle") == -1)
    {
        cout << "error in input syntax" << endl;
        cout << toParse << endl;
        return 1;
    }

    x_coord = atoi(toParse.substr(7, 2).c_str());
    commaindex = toParse.find(',');
    y_coord = atoi(toParse.substr((commaindex - 2), 2).c_str());
    radius = stof(toParse.substr((commaindex + 2), toParse.find(')') - commaindex - 2).c_str());
        
    Circle temp = Circle(x_coord, y_coord, radius);
    return temp;
    
}




vector<Circle> parse()
{
    vector<Circle> array;
    string toParse;
    ifstream in("example.txt");
    if(in.is_open())
    {
        while(getline(in, toParse))
        {
            array.push_back(getdata(toParse));
        }
    }
    in.close();
    return array;
}

