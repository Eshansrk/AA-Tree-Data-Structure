#ifndef AA_TREE_H
#define AA_TREE_H

#include <iostream>
using namespace std;


template <class ItemType>
class AATree
{
  public:
    AATree( )
    {
        nullNode = new AANode;
        nullNode->left = nullNode->right = nullNode;
        nullNode->level = 0;
        root = nullNode;
    }



    ~AATree( )
    {
        makeEmpty( );
        delete nullNode;
    }

    const ItemType & findMin( ) const
    {
        if( isEmpty( ) )
            cout<<"Empty"<<endl;

        AANode *ptr = root;
        while( ptr->left != nullNode )
            ptr = ptr->left;

        return ptr->info;
    }

    const ItemType & findMax( ) const
    {
        if( isEmpty( ) )

            cout<<"Empty"<<endl;

        AANode *ptr = root;
        while( ptr->right != nullNode )
            ptr = ptr->right;

        return ptr->info;
    }

    bool contains( const ItemType & x ) const
    {
        AANode *current = root;
        nullNode->info = x;

        for( ; ; )
        {
            if( x < current->info )
                current = current->left;
            else if( current->info < x )
                current = current->right;
            else
                return current != nullNode;
        }
    }

    bool isEmpty( ) const
    {
        return root == nullNode;
    }


    void printTree( ) const
    {
        if( root == nullNode )
            cout << "Empty tree" << endl;
        else
            printTreeT( root );
    }

    void makeEmpty( )
    {
        makeEmpty( root );
    }


    void insert( const ItemType & x )
    {
        insertT( x, root );
    }

    void remove( const ItemType & x )
    {
        removeR( x, root );
    }


  private:
    struct AANode
    {
        ItemType info;
        AANode    *left;
        AANode    *right;
        int        level;

        AANode( ) : left( NULL ), right( NULL ), level( 1 ) { }
        AANode( const ItemType & e, AANode *lt, AANode *rt, int lv = 1 )
          : info( e ), left( lt ), right( rt ), level( lv ) { }
    };

    AANode *root;
    AANode *nullNode;


    void insertT( const ItemType & x, AANode * & t )
    {
        if( t == nullNode )
            t = new AANode( x, nullNode, nullNode );
        else if( x < t->info )
            insertT( x, t->left );
        else if( t->info < x )
            insertT( x, t->right );
        else
            return;

        skew( t );
        split( t );
    }


    void removeR( const ItemType & x, AANode * & t )
    {
        static AANode *lastNode, *deletedNode = nullNode;

        if( t != nullNode )
        {

            lastNode = t;
            if( x < t->info )
                removeR( x, t->left );
            else
            {
                deletedNode = t;
                removeR( x, t->right );
            }


            if( t == lastNode )
            {
                if( deletedNode == nullNode || x != deletedNode->info )
                    return;
                deletedNode->info = t->info;
                deletedNode = nullNode;
                t = t->right;
                delete lastNode;
            }


            else
                if( t->left->level < t->level - 1 ||
                    t->right->level < t->level - 1 )
                {
                    if( t->right->level > t->level )
                        t->right->level = t->level;
                    skew( t );
                    skew( t->right );
                    skew( t->right->right );
                    split( t );
                    split( t->right );
                }
        }
    }

    void makeEmpty( AANode * & t )
    {
        if( t != nullNode )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullNode;
    }

    void printTreeT( AANode *t ) const
    {
        if( t != nullNode )
        {
            printTreeT( t->left );
            cout << t->info << endl;
            printTreeT( t->right );
        }
    }


    void skew( AANode * & t )
    {
        if( t->left->level == t->level )
            rotateWithLeftChild( t );
    }


    void split( AANode * & t )
    {
        if( t->right->right->level == t->level )
        {
            rotateWithRightChild( t );
            t->level++;
        }
    }

    void rotateWithLeftChild( AANode * & k2 )
    {
        AANode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild( AANode * & k1 )
    {
        AANode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }


};

#endif
