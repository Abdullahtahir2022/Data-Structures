#include<iostream>
#include <fstream>
using namespace std;


class NODE{

int data;
NODE* next;

public:
    NODE(){
    data=0;
    next=NULL;
    }
    NODE(int dat)
    {
        data=dat;
        next=NULL;
    }

    void data1(int d){
    data=d;


    }
    void next1(NODE *n){
    next=n;

    }
    int getdata(){
    return data;}
    NODE* getnext(){
    return next;}

};


class linklist
{

public:
NODE* first;


linklist(){
first=NULL;
}
void adder(int d);
void findindex(int d);
int remval(int d);
void display();
};
 void linklist::adder(int d)
{
        NODE *temp=new NODE(d);
        NODE *temp2=first;

        if(first==NULL)
        {
            first=temp;
            return;
        }
        else{

            while(temp2!=NULL)
            {


                if(temp2->getnext()==NULL)
                {

                    temp2->next1(temp);
                    break;
                }
            else{temp2=temp2->getnext();}

            }

    }
}


void linklist::findindex(int d){
        NODE*temp=first;
        int x;

        int counter=0;



        if(first->getdata()==d)
        {
           cout<<"exist"<<endl;
}
        else{

    while(temp->getdata()!=d)
    {


        counter++;

        if(temp->getnext()==NULL)
        {   x=-1;
            cout << "exist" << endl;
            break;
        }
        temp=temp->getnext();


    }
if(x!=-1){
cout << counter << endl;}



    }


}




















int linklist::remval(int d){


       NODE* temp=first;
       if(temp->getdata()==d)
       {
           first=temp->getnext();
           return 1;
       }
       else{
        while(2)
        {
            if(temp->getnext()->getdata()==d)
            {
                temp->next1(temp->getnext()->getnext());
                return 1;
                //break;
            }
            else
            {
                    temp=temp->getnext();

            }
        }

        }



       }







void linklist::display()
    {
if(first==NULL)
{
    return;
}
        NODE* temp=first;
        cout <<"----------------"<< endl;
        while(temp!=NULL)
        {

            cout<<temp->getdata()<<endl;
            temp=temp->getnext();


        }

    }










class hash{

linklist array[10];


public:

void adder_linear(int d);
int hashf(int d);
int collision_linear(int d,int i);
void remov(int d);
void serarch(int d);
void disp();

void status();
};


void hash::status()
{ int i=0;
    for(int a=0;a<10;a++)
    {
        if(array[a].first==NULL)
        {
           i++;
        }
    }
            if(i==10)
        {
           cout<<"empty"<<endl;
        }
            if(i==0)
            {
                cout<<"full"<<endl;
            }
            else
                {cout<<"not full"<<endl;}

}






void hash::remov(int d)
{


        int b=array[hashf(d)].remval(d);


}
void hash::serarch(int d)
{


        array[hashf(d)].findindex(d);

}




int hash::hashf(int d)
{
    return d%10;
}

void hash::adder_linear(int d)
{

      array[hashf(d)].adder(d);

}

void hash::disp()
{
    for(int a=0;a<10;a++)
    {
        array[a].display();

    }
}





int main()
{
    hash obj;
    obj.adder_linear(30);
    obj.adder_linear(31);
    obj.adder_linear(32);
    obj.adder_linear(33);
    obj.adder_linear(34);
    obj.adder_linear(35);
    obj.adder_linear(36);
    obj.adder_linear(37);
    obj.adder_linear(38);
    obj.adder_linear(39);
    obj.status();

}

























