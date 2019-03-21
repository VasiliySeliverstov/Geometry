#include <iostream>
#include <math.h>
#include <string>
#include "parser.cpp"

int main(int argc, char const *argv[])
{
    vector<Circle> array;
    array = parse();   

    for(int i = 0; i < array.size(); i++)
    {
        for(int j = 0; j < array.size(); j++)
        {
            if(i == j)  continue;
            if(sqrt((array[i].x - array[j].x) * (array[i].x - array[j].x) + (array[i].y - array[j].y) * (array[i].y - array[j].y)) <= array[i].radius + array[j].radius)
                {
                    array[i].intersects.push_back(j);
                } 
        }
    }

    for(int i = 0; i < array.size(); i++)
    {
        cout << i + 1 << ". circle(" << array[i].x << " " << array[i].y << ")" << endl;
        cout << "   perimetr = " << array[i].getPerimetr() << endl;
        cout << "   area = " << array[i].getArea() << endl;
        cout << "   intersects:" << endl;


        for(int j = 0; j < array[i].intersects.size(); j++)
        {
            cout << "       " << array[i].intersects[j] << ".  circle" << endl;
        }

        cout << "\n" << endl;
    }

    return 0;
}