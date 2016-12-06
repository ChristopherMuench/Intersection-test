/*Written by Christopher Muench
December 2016
Program to compare warehouse stock product #s
C++ language (minGW G++ compiler)*/
/*Some code from set intersection algorithm adapted from
c++ reference code*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{ //Declaration of necessary variables and containers
    vector <int> chicago;
    vector <int> detroit;
    vector <int> intersection(25);
    vector <int>::iterator container;
    vector <int>::iterator firstC;
    vector <int>::iterator lastC;
    vector <int>::iterator firstD;
    vector <int>::iterator lastD;
    int productNum = 0;

    cout <<"Please enter product numbers of the products stored in Chicago, ";
    cout <<endl<<"Enter a negative number when finished with input: "<<endl;
    do //Enter loop to push product nums onto vector chicago
    {
        cin >>productNum;
        if (productNum < 0)
        {
            break;
        }
        else
        {
            chicago.push_back(productNum);
        }

    }while (productNum >= 0);

    cout <<"Please enter product numbers of the products stored in Detroit, ";
    cout <<endl<<"Enter a negative number when finished with input: "<<endl;
    do //Enter loop to push product nums onto vector detroit
    {
        cin >>productNum;
        if (productNum < 0)
        {
            break;
        }
        else
        {
            detroit.push_back(productNum);
        }

    }while (productNum >= 0);

    //Assign iterators to the beginnings and ends of vectors
    firstC = chicago.begin();
    lastC = chicago.end() + 1;
    firstD = detroit.begin();
    lastD = detroit.end() + 1;
    container = intersection.begin();

    //Apply STL algorithm to sort values, determine intersections
    // and store result in third vector
    sort(firstC,lastC);
    sort(firstD,lastD);
    container = set_intersection(firstC,lastC,firstD,lastD,intersection.begin());
    intersection.resize(container - intersection.begin());//resize vector to amount of elements stored there

    //Display results of intersection
    cout <<"Intersection of warehouse product numbers is/are: "<<endl;
    for(container = intersection.begin();container != intersection.end(); ++container)
    {
        cout << *container << " ";
    }


return 0;
}
