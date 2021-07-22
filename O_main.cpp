 #include <iostream>
#include "OList1.h"
using namespace std;



int main()
{

    OList1 <int> temp;
    OList1 <int> a;

    // insert the following values in to the "temp" and "A" variable
    temp.insertion(3);
    a.insertion(5);
    a.insertion(9);
    a.insertion(1);

    //temp = a;

    cout << "\n\n After inserting '3' values into the OList 'A': ";
    a.printForward();
    cout << "\n\n";
    a.remove(1);
    
    cout << "\n\nafter removing the second element in the list we have the following list. List printed in reverse: ";
    a.printBackward();
    //Ca.clear();
    a.insertion(38);
    a.insertion(5);

    cout << "\n\n after inserting two more values into Olist A. reverse print: ";
    a.printBackward();
    cout << "\n\n\n\n ";
    cout << "\n\n print 'temp' list forward: ";
    temp.printForward();
    cout << endl << endl;
    //cout << a.getsmallest();
    cout << endl << endl;
    a.printForward();
    cout << endl << endl;
    cout << "the smallest element in list 'A' is: " << a.getsmallest();
    cout << endl << endl;
    cout << "\n\n the largest element in list 'A' is: " << a.getBiggest();
    cout << endl << endl;
    cout << "\n\n the current size of list 'A' is: " << a.getSize();
    cout << endl << endl;
    OList1 <int> b;
    b.insertion(1);
    b = a;
    b.remove(1);
    cout << "\n setting list 'B' to list 'A' and removing the second element in the list: print B list backwards: ";
    b.printForward();
    cout << endl << endl;

    return 0;
}
