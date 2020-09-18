#include <iostream>

using namespace std;


class heap{

int array[15];
int array1[15];
int index=0;
int index1=14;
int a=0;


public:
    heap()
    {
        for(int a=0;a<15;a++)
        {
            array[a]=-1;
            array1[a]=-1;
        }
    }
void adder(int d);
void disp();
void checker(int index,int d);
void revchecker(int index);
void remove1(int index);
void forchecker(int index);
void dispsorted();
void remove();

};

void heap::remove1(int index)
{
    if(index>=0)
   {
    array1[index1]=array[0];
    index1--;

    array[0]=array[index];

    array[index]=-1;

    revchecker(index);
    forchecker(index);

   }
}
void heap::remove()
{
    remove1(--index);

}












void heap::revchecker(int index)
{

    while(index!=0)
    {
        int a=(index-1)/2;

        if(array[a]<array[index])
        {
            int i=array[index];
            array[index]=array[a];
            array[a]=i;
        }
        index--;
    }
}

void heap::forchecker(int index1)
{
if(index1<=1){return;}

    int index=1;

    while(index !=index1)
    {
        int a=(index-1)/2;

        if(array[a]<array[index])
        {
            int i=array[index];
            array[index]=array[a];
            array[a]=i;
        }
        index++;
    }
}











void heap::checker(int index,int d)
{
int a=(index-1)/2;



if(array[a]<d)
{
    int i=array[index];
    array[index]=array[a];
    array[a]=i;


}






}






void heap::disp()
{
    for(int a=0;a<15;a++)
    {
        cout << array[a] << endl;
    }
}


void heap::dispsorted()
{ cout << "------------" << endl;
    for(int a=0;a<15;a++)
    {
        cout << array1[a] << endl;
    }
}





void heap::adder(int d)
{
array[index]=d;

checker(index,d);
revchecker(index);
index++;

}






int main()
{
heap obj;
obj.adder(160);
obj.adder(140);
obj.adder(7);
obj.adder(80);
obj.adder(70);
obj.adder(90);
obj.adder(30);
obj.adder(20);
obj.adder(40);
obj.adder(1456);
obj.adder(1678);
obj.adder(111);
obj.adder(165);
obj.adder(132);
obj.adder(78);
obj.adder(11);
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();
obj.remove();


obj.disp();
obj.dispsorted();







}








