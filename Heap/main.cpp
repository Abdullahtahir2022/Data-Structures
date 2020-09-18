#include <iostream>

using namespace std;


class heap{

int array[15];
int index=0;
int a=0;


public:
    heap()
    {
        for(int a=0;a<15;a++)
        {
            array[a]=-1;
        }
    }
void adder(int d);
void disp();
void checker(int index,int d);
};

void heap::checker(int index,int d)
{
int a=(index-1)/2;



if(array[a]<d && index!=0)
{
    int i=array[index];
    array[index]=array[a];
    array[a]=i;
    checker(--index,d);
    //return;
}






}






void heap::disp()
{
    for(int a=0;a<15;a++)
    {
        cout << array[a] << endl;
    }
}






void heap::adder(int d)
{
array[index]=d;

checker(index,d);
index++;

}






int main()
{
heap obj;
obj.adder(80);
obj.adder(100);
obj.adder(90);
obj.adder(160);
//obj.adder(70);
obj.adder(140);
//obj.adder(30);
//obj.adder(90);


obj.disp();


}








