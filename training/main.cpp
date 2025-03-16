#include <iostream>
#include <vector>
#include"test.h"

using namespace std;
int main() {
    
    vector<int> p = { 30, 35, 15, 5, 10, 20, 25 };
    cout <<  min_multipy_numbers(p)<< endl;
    list mylist;
    for(int b:p){
        mylist.append(b);
    }
    mylist.print();
    return 0;
}
