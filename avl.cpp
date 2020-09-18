#include <iostream>
using namespace std;



class NODE{

int data;
NODE* left;
NODE* right;
int height;
public:
    NODE(){
    data=0;
    left=NULL;
    right=NULL;
    height=0;
    }
    NODE(int dat)
    {
        data=dat;
        left=NULL;
        right=NULL;
        height=0;
    }
    void height1(int h)
    {
        height=h;
    }
    int getheight()
    {
        return height;
    }

    void data1(int d){
    data=d;


    }
    void right1(NODE *n){
    right=n;

    }
    void left1(NODE *n)
   {

   left=n;}
    int getdata(){
    return data;}
     NODE* getright(){
    return right;}
    NODE* getleft(){
    return left;}

};
class AVL
{
   public:
       NODE* root;

       AVL()
       {
           root=NULL;
       }
       NODE* getroot()
       {
           return root;
       }
       void setroot(NODE* temp)
       {
           root=temp;
       }


NODE* adderrec(NODE* root, int d);
void disp_I(NODE* node);
int max(int a, int b);
int height(NODE* node);
int getbf(NODE* node);
void add(int d);
NODE* rotate_right(NODE* node);
NODE* rotate_left(NODE* node);
NODE* left_right(NODE* node);
NODE* right_left(NODE* node);
int search(NODE* node, int d);
int remove(NODE* node,NODE* node1,int d);
void last_value(NODE* node);
void last_value1(NODE* node);
};
void AVL::last_value(NODE* node)
{
    NODE* node2=node;
    node=node->getleft();
    NODE* node1;


    while(node->getright()!=NULL)
    {   node1=node;
        node=node->getright();
    }
if(root->getdata()!=node2->getdata())
   {int a=node->getdata();
    cout << node2->getdata() << "---" << endl;
    node1->right1(NULL);
    node2->data1(a);}
else if(root->getdata()==node2->getdata())
{
    node->left1(root->getleft());
    node->right1(root->getright());
    root->left1(NULL);
    root->right1(NULL);
    root=node;
    node1->right1(NULL);

}

}

void AVL::last_value1(NODE* node)
{
    NODE* node2=node;
    node=node->getright();
    NODE* node1;

    while(node->getleft()!=NULL)
    {   node1=node;
        node=node->getleft();
    }
    int a=node->getdata();
    node1->left1(NULL);
    node2->data1(a);

}









NODE* AVL::rotate_right(NODE* node)
{



NODE* n2=node->getleft();
node->left1(n2->getright());
 n2->right1(node);
 n2->height1(max(height(n2->getleft()),height(n2->getright()))+1);
 node->height1(max(height(node->getleft()),height(node->getright()))+1);


 return n2;

}


NODE* AVL::left_right(NODE* node)
{
   NODE* n2=node->getleft();
   NODE* n3=node->getleft()->getright();
   n3->left1(n2);
   n2->right1(NULL);
   node->left1(n3);
   n2->height1(max(height(n2->getleft()),height(n2->getright()))+1);
   n3->height1(max(height(n3->getleft()),height(n3->getright()))+1);
   node->height1(max(height(node->getleft()),height(node->getright()))+1);

   return node;

}

NODE* AVL::right_left(NODE* node)
{

   NODE* n2=node->getright();
   NODE* n3=node->getright()->getleft();
   n3->right1(n2);
   n2->left1(NULL);
   node->right1(n3);
   n2->height1(max(height(n2->getleft()),height(n2->getright()))+1);
   n3->height1(max(height(n3->getleft()),height(n3->getright()))+1);
   node->height1(max(height(node->getleft()),height(node->getright()))+1);

   return node;

}






















NODE* AVL::rotate_left(NODE* node)
{



NODE* n2=node->getright();
node->right1(n2->getleft());
n2->left1(node);
n2->height1(max(height(n2->getleft()),height(n2->getright()))+1);
node->height1(max(height(node->getleft()),height(node->getright()))+1);


return n2;

}


int AVL:: search(NODE* node, int d)
{

    if (node->getdata()==d)
       return node->getdata();


    if (node->getdata()<d)
    return search(node->getright(), d);



    return search(node->getleft(), d);
}




int AVL:: remove(NODE* node, NODE* node1, int d)
{
    int a;
    if (node->getdata()==d)
       {

           if(node->getleft()==NULL && node->getright()==NULL)
           {
               if( node1->getleft()!=NULL && node1->getleft()->getdata()==d )
               {
                   node1->left1(NULL);

               }
               else if(node1->getright()!=NULL && node1->getright()->getdata()==d )
               {
                   node1->right1(NULL);
               }

           }

           if(node->getleft()==NULL && node->getright()!=NULL || node->getright()==NULL && node->getleft()!=NULL)
           {
               if(node1->getleft()!=NULL && node1->getleft()->getdata()==d )
               {
                   if(node->getright()!=NULL)
                   {node1->left1(node->getright());}
                   else if(node->getleft()!=NULL)
                   {node1->left1(node->getleft());}

               }
               if(node1->getright()!=NULL && node1->getright()->getdata()==d )
               {
                   if(node->getright()!=NULL)
                   {node1->right1(node->getright());}
                   else if(node->getleft()!=NULL)
                   {node1->right1(node->getleft());}
               }
           }
           //work from here
         if(node->getleft()!=NULL && node->getright()!=NULL)
         {
             if(d<root->getdata())
             {
               if(node->getleft()->getright()==NULL)   //IF we cant recurse to right
               {

                node1->left1(node->getleft());
                node1->getleft()->right1(node->getright());

               }
                else              // if we can
{
     last_value(node);
}
             }

            if(d>root->getdata())
             {
               if(node->getright()->getleft()==NULL)   //IF we cant recurse to right
               {
                node1->right1(node->getright());
                node1->getright()->left1(node->getleft());
               }
                else              // if we can
{
            last_value1(node);
}
             }


             if(d==root->getdata())
             {
                 if(node->getleft()->getright()==NULL)

               {   node->data1(node->getleft()->getdata());
                   node->left1(node->getleft()->getleft());
               }
               else
               {
                   last_value(node);
               }

             }


         }

       }


    if (node->getdata()<d)

     remove(node->getright(),node, d);

    if (node->getdata()>d)


     remove(node->getleft(),node, d);
}










int AVL::getbf(NODE* node)
{
  return     height(node->getleft())-height(node->getright());
}



int AVL::max(int a, int b)
{
    if(a>b)
    {return a;}
    else if(a<b){return b;}
    else{return b;}
}

int AVL::height(NODE* node)
{
    if(node==NULL)
    {
        return -1;
    }
   else
   {return node->getheight();}
}

void AVL::disp_I(NODE* temp2)
{

    if(temp2==NULL)
        return;
    else
    {

         disp_I(temp2->getleft());
         cout << temp2->getdata() << endl;

         disp_I(temp2->getright());

    }
}

void AVL:: add(int d)
{
    setroot(adderrec(root,d));
}







NODE* AVL::adderrec(NODE* temp2,int d)
{



    if(temp2==NULL)
    {
         temp2=new NODE(d);


    }
    else if(d<temp2->getdata())
        {

            temp2->left1(adderrec(temp2->getleft(),d));
            int bf=getbf(temp2);
            if(bf==2 || bf==-2)
            {
                if(d<temp2->getleft()->getdata())
                {
                   temp2=rotate_right(temp2);
                }
                if(d>temp2->getleft()->getdata())
                {

                   temp2=left_right(temp2);
                   temp2=rotate_right(temp2);
                }

            }


        }
  else if(d>temp2->getdata())
        {

             temp2->right1(adderrec(temp2->getright(),d));
             int bf=getbf(temp2);
            if(bf==2 || bf==-2)
            {   ;
                if(d>temp2->getright()->getdata())
                {
                   temp2=rotate_left(temp2);
                }
                if(d<temp2->getright()->getdata())
                {

                   temp2=right_left(temp2);
                   temp2=rotate_left(temp2);
                }
            }
        }


temp2->height1(max(height(temp2->getleft()),height(temp2->getright()))+1);
return temp2;




}
























int main()
{
   AVL obj;




  obj.add(100);
  obj.add(120);
  obj.add(115);
  obj.add(122);

  obj.add(121);
  obj.add(123);
  obj.add(90);
  obj.add(89);
  obj.add(91);












}

