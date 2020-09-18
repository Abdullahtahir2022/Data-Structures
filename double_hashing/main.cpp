#include <iostream>
using namespace std;


class hash{
int array[11];
public:
    hash()
    {
        for(int a=0;a<11;a++)
        {
            array[a]=-1;
        }
    }
void adder_linear(int d);
int hashf(int d);
void disp();
int hashf2(int d, int i);
void search(int d);
void remove(int d);
void status();
};

void hash::adder_linear(int d)
{ int i=1;
    if(array[hashf(d)]==-1)
    {
      array[hashf(d)]=d;
    }
    else if(array[hashf(d)]!=-1)
    {
      while(true)
      {
          if(array[( hashf(d)+ ( i * hashf2(d,i)) )%11 ] ==-1)
          {
            array[ (hashf(d)+ ( i * hashf2(d,i) ) )% 11]= d;
            break;
          }
          i++;
      }

    }

}


void hash:: remove(int d)
{
 int i=1;
    if(array[hashf(d)]==d)
    {
      array[hashf(d)]=-1;
    }
    else if(array[hashf(d)]!=d)
    {
      while(true)
      {
          if(array[( hashf(d)+ ( i * hashf2(d,i)) )%11 ] ==d)
          {
            array[ (hashf(d)+ ( i * hashf2(d,i) ) )% 11]= -1;
            break;
          }
          else if(i>11)
          {
                cout << "not" << endl;
                break;
          }

          i++;
      }

    }
}


void hash::search(int d)
{
 int i=1;
    if(array[hashf(d)]==d)
    {
      cout << "yes it exist" << endl;
    }
    else if(array[hashf(d)]!=d)
    {
      while(true)
      {
          if(array[( hashf(d)+ ( i * hashf2(d,i)) )%11 ] ==d)
          {
            cout << "yes, it exist" << endl;
            break;
          }
          else if(i>11)
          {
                cout << "not" << endl;
                break;
          }
          i++;
      }

    }
}















int hash::hashf(int d)
{
    return d%11;
}

int hash::hashf2(int d, int i)
{
  return 7-(d%7);
}

void hash::disp()
{
    for(int a=0;a<11;a++)
    {
        cout << array[a] << endl;
    }
}

void hash::status()
{ int i=0;
    for(int a=0;a<11;a++)
    {
        if(array[a]==-1)
        {
           i++;
        }


    }
  if(i==0)
  {
      cout << "hash table is full" << endl;
  }
  else if(i==11)
  {
      cout << "hash table is Empty" << endl;
  }
  else{cout << "Not Full" << endl;}
}











int main()
{
hash obj;
obj.adder_linear(20);
obj.adder_linear(21);
obj.adder_linear(28);
obj.adder_linear(22);
obj.adder_linear(25);
obj.adder_linear(25);
obj.adder_linear(25);
obj.adder_linear(25);
obj.adder_linear(25);
obj.adder_linear(25);
obj.adder_linear(25);
obj.status();


obj.disp();
}
