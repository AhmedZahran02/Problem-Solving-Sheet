#include <iostream>

using namespace std ;
 
int main ()
{
   int n,p1,p2,p3,np=0;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>p1>>p2>>p3;
      if(p1==1&&p2==1||p2==1&&p3==1||p1==1&&p3==1){
         np++;
      }
   }
   cout<<np;

   return 0;
}
 