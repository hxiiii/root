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
#include <fstream>
#include <stdlib.h>
#define maxWeight 9999
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
    router()=default;
    void deleteVertex();
    void deleteEdge();
    void addVertex();
    void addEdge();
    void calculate();
    void createVertices();
    void createEdges();
    void createGraph();
    void save();
    int getVertexPos(int v)
    {
        for(int i=0; i<size; i++)
            if(router_info[i].num==v)return i;
        return -1;
    }
};

/*router::router()
{
    int i,j;
    for(i=0; i<)

    }*/

void router::calculate()
{
    int i, j;
    cout<<"here is the information of all roots:"<<endl;
    for(i=0; i<size; ++i)
    {

    }
    cout<<"please enter the number of router:";
    cin>>i;
    //start to calculate
}

void router::deleteVertex()
{
    int i,v;
    cout<<"enter delete routing number"<<endl;
    cin>>i;
    v=getVertexPos(i);
    if(v==-1)
    {
        cout<<"enter error!"<<endl;
        return;
    }
    router_info[v]=router_info[size-1];
    for(i=0; i<size; i++)
    {
        table[i][v]=table[i][size-1];
        //if(table[v][i]>0&&table[v][i]<MaxValue)
    }
    size--;
    for(i=0; i<size; i++)
    {
        table[v][i]=table[size][i];
    }
    save();
}

void router::deleteEdge()
{
    int a,b;
    cout<<"enter delete Edge information: "<<endl;
    cout<<"enter IP source number: ";
    cin>>a;
    cout<<endl<<"enter IP destination number: ";
    cin>>b;
    int v,t;
    v=getVertexPos(a);
    t=getVertexPos(b);
    if(v==-1)
    {
        cout<<"enter IP source information error!"<<endl;
        return;
    }
    else if(t==-1)
    {
        cout<<"enter IP source information error!"<<endl;
        return;
    }
    else if(table[v][t]>0&&table[v][t]<maxWeight)table[v][t]=table[t][v]=maxWeight;
    save();
}

void router::addVertex()
{
    int i;
    if(size>20)
    {
        cout<<"Table Full!"<<endl;
        return;
    }
    cout<<"please enter routing information :"<<endl;
    cout<<"IP: "<<endl;
    cin>>router_info[size].ip;
    cout<<"Number: "<<endl;
    cin>>router_info[size].num;
    for(i=0; i<size; i++)
    {
        table[size][i]=table[i][size]=maxWeight;
    }
    table[size][i]=0;
    size++;
    save();
}

void router::addEdge()
{
    int a,b,c;
    cout<<"enter add Edge information: "<<endl;
    cout<<"enter IP source number: ";
    cin>>a;
    cout<<endl<<"enter IP destination number: ";
    cin>>b;
    cout<<endl<<"enter const"<<endl;
    cin>>c;
    int v,t;
    v=getVertexPos(a);
    t=getVertexPos(b);
    if(v==-1)
    {
        cout<<"enter IP source information error!"<<endl;
        return;
    }
    else if(t==-1)
    {
        cout<<"enter IP source information error!"<<endl;
        return;
    }
    else if(table[v][t]!=0&&table[v][t]<maxWeight)table[v][t]=table[t][v]=c;
    save();
}

void menu(router &G)
{
    return ;
}

void router::createVertices()
{
    int i=0,j,tag=1;
    cout<<"please enter routing information :"<<endl;
    while(tag)
    {
        cout<<"IP: "<<endl;
        cin>>router_info[i++].ip;
        cout<<"Number: "<<endl;
        cin>>router_info[i++].num;
        cout<<"enter "0" to exit"<<endl;
        cin>>tag;
        size++;
    }
    ofstream out("rout_info.txt");
    if(out.is_open())
    {
        for(j=0; j<i; j++)
            out<<router_info[j].ip<<" "<<router_info[j].num<<endl;;
    }
    out.close();
}

void router::createEdges()
{
    int i,j,count=0,tag=1;
    int a,b,c;
    int v,t;
    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
        {
            if(i==j)table[i][j]=0;
            else table[i][j]=maxWeight;
        }
    cout<<"please enter path information :";
    while(tag)
    {
        cout<<endl<<"enter IP source : ";
        cin>>a;
        cout<<endl<<"enter IP destination : ";
        cin>>b;
        cout<<endl<<"enter const: ";
        cin>>c;
        cout<<endl<<"enter "0" to exit!  ";
        cin>>tag;
        v=getVertexPos(a);
        t=getVertexPos(b);
        if(v!=-1&&t!=-1)
        {
            table[v][t]=c;
            table[t][v]=c;
        }
    }
    ofstream out("rout_path.txt");
    if(out.is_open())
    {
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
            {
                out<<table[i][j]<<" ";
                count++;
                if(count%size==0)out<<endl;
            }
    }
    out.close();
}

void router::createGraph()
{
    int i=0,j;
    char buff[255];
    int number;
    ifstream in("rout_info.txt");
    if(!in)
    {
        cout<<"open error!"<<endl;
        exit(1);
    }
    while(!in.eof()&&size<=20)
    {
        in>>buff>>number;
        router_info[i].ip=buff;
        router_info[i].num=number;
        i++;
        size++;
    }
    in.close();
    ifstream fin("rout_path.txt");
    if(!fin)
    {
        cout<<"open error!"<<endl;
        exit(1);
    }
    while(!fin.eof())
    {
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
            {
                fin>>table[i][j];
            }
    }
}

void router::save()
{
    int i,j,count=0;
    ofstream out("rout_info.txt");
    if(out.is_open())
    {
        for(i=0; j<size; i++)
            out<<router_info[i].ip<<" "<<router_info[i].num<<endl;
    }
    out.close();
    ofstream fout("rout_path.txt");
    if(fout.is_open())
    {
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
            {
                fout<<table[i][j]<<" ";
                count++;
                if(count%size==0)fout<<endl;
            }
    }
    fout.close();
}
int main()
{
    router G;
    menu(G);
    G.createVertices();
    G.createEdges();
    return 0;
}
