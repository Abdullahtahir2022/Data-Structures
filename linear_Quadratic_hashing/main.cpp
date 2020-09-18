#include <iostream>
using namespace std;

class hash{

int array[10];
int array_q[11];
public:
    hash()
    {
        for(int a=0;a<11;a++)
        {
            array_q[a]=-1;
        }
    }
void adder_linear(int d);
void adder_quadratic(int d);
int hashf(int d);
int hashf_q(int d);
void disp();
int collision_linear(int d, int i);
int collision_quadratic(int d, int i);
void search_q(int d);
void remove_q(int d);
void status();
};

int hash::collision_linear(int d, int i)
{
  return (hashf(d)+i)%10;
}


int hash::collision_quadratic(int d, int i)
{
  return (hashf_q(d)+i)%11;
}



int hash::hashf_q(int d)
{
    return d%11;
}

void hash::search_q(int d)
{
    int i=1, a=1;
    if(array_q[hashf_q(d)]==d)
    {
      cout << "yes, it exist" << endl;
    }
    else if(array_q[hashf_q(d)]!=d)
    {
      while(true)
      {
          if(array_q[collision_quadratic(d,i)]==d)
          {
            cout << "yes, it exist" << endl;
            break;
          }
          else if(a>10)
          {
            cout << "not" << endl;
            break;
          }
          i=a*a;
          a++;
      }

    }

}






int hash::hashf(int d)
{
    return d%10;
}

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
          if(array[collision_linear(d,i)]==-1)
          {
            array[collision_linear(d,i)]=d;
            break;
          }
          i++;
      }

    }

}

void hash::adder_quadratic(int d)
{
    int i=1, a=1;
    if(array_q[hashf_q(d)]==-1)
    {
      array_q[hashf_q(d)]=d;
    }
    else if(array_q[hashf_q(d)]!=-1)
    {
      while(true)
      {
          if(array_q[collision_quadratic(d,i)]==-1)
          {
            array_q[collision_quadratic(d,i)]=d;
            break;
          }
          i=a*a;
          a++;
      }

    }


}

void hash::remove_q(int d)
{
    int i=1, a=1;
    if(array_q[hashf_q(d)]==d)
    {
      array_q[hashf_q(d)]=-1;
    }
    else if(array_q[hashf_q(d)]!=d)
    {
      while(true)
      {
          if(array_q[collision_quadratic(d,i)]==d)
          {
            array_q[hashf_q(d)]=-1;
            break;
          }
          else if(a>10)
          {
            cout << "not" << endl;
            break;
          }
          i=a*a;
          a++;
      }

    }
}
























void hash::disp()
{
    for(int a=0;a<11;a++)
    {
        cout << array_q[a] << endl;
    }
}


void hash::status()
{ int i=0;
    for(int a=0;a<11;a++)
    {
        if(array_q[a]==-1)
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
    obj.adder_quadratic(29);
    obj.adder_quadratic(39);
    obj.adder_quadratic(49);
    obj.adder_quadratic(59);
    obj.adder_quadratic(59);
    obj.adder_quadratic(59);
    obj.adder_quadratic(59);
    obj.adder_quadratic(59);
    obj.adder_quadratic(59);
    obj.adder_quadratic(59);
    //obj.adder_quadratic(59);
    obj.status();





    obj.disp();
}
