#include <iostream>
#include <fstream>
#include "AATree.h"
using namespace std;


int main( )
{
    AATree<int> t;
  /*  int NUMS = 200000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        t.insert( i );
    t.remove( 0 );
    for( i = 1; i < NUMS; i += 2 )
        t.remove( i );

    if( NUMS < 40 )
        t.printTree( );
    if( t.findMin( ) != 2 || t.findMax( ) != NUMS - 2 )
        cout << "FindMin or FindMax error!" << endl;

    for( i = 2; i < NUMS; i += 2 )
        if( !t.contains( i ) )
            cout << "Find error1!" << endl;

    for( i = 1; i < NUMS; i += 2 )
    {
        if( t.contains( i )  )
            cout << "Find error2!" << endl;
    }

    AATree<int> t2;
    t2 = t;

    for( i = 2; i < NUMS; i += 2 )
        if( !t2.contains( i ) )
            cout << "Find error1!" << endl;

    for( i = 1; i < NUMS; i += 2 )
    {
        if( t2.contains( i ) )
            cout << "Find error2!" << endl;
    }
*//*
    for (int i = 0; i < 100; i++)
        t.insert(i);

    t.printTree();

    cout << "End of test..." << endl;
    t.makeEmpty();
    t.insert(5);
    if(t.isEmpty())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        if(t.contains(5))
            cout<<"H";
        else
            cout<<"N";*/

            ifstream inFile;
            ofstream outFile;
    inFile.open("input.txt");
    outFile.open("testOutput2.txt");
    int x;
    while(inFile>>x){
        t.insert(x);
    }

    t.printTree();
    t.insert(45);
    t.remove(50);
    t.insert(45);
    t.insert(45);
    t.printTree();

    if(t.contains(48))
        cout<<"H\n";
    else
        cout<<"N";
    cout<<" Min :  "<<t.findMin();

    return 0;
}
