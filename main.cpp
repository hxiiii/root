//  main.cpp
//  root_table
//
//  Created by ただかなで on 2017/1/7.
//  Copyright © 2017年 ただかなで. All rights reserved.
//
/*
 function
 menu,add,delet,calculate


 */

#include <iostream>

using namespace std;


struct info
{
    string ip;
    int num;
};

class router
{
private:
    int table[20][20];
    int size;//the number of roots(it changes with the using of function delet and add)
    info router_info[20];//the information of routers
public:
    router();
    void add();
    void delet();
    void calculate();
};

router::router()
{

}

void router::calculate()
{
    int i, j;
    cout<<"here is the information of all roots:"<<endl;
    for(i=0;i<size;++i)
    {

    }
    cout<<"please enter the number of router:";
    cin>>i;
    //start to calculate
}

void router::delet()
{

}

void router::add()
{

}

void menu(router &G)
{

}

int main()
{
    router G;
    menu(G);
    return 0;
}
