#include<iostream>
using namespace std;
char zero_cross[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void print_zero_cross()
{
	for(int i=0;i<5;i++)
	   {
	   	 cout<<" ";
	   	 
	   	  if(i%2==0)
	   	   {
	   	   	  cout<<" "<<zero_cross[i/2][0]<<" "<<'|'<<" "<<zero_cross[i/2][1]<<" "<<'|'<<" "<<zero_cross[i/2][2];
		   }
		  else
		   {
		   	  for(int j=0;j<11;j++)
		   	     cout<<'=';
		   }
		  cout<<endl;
	   }
}
void display(char key,char tic)
{
	for(int i=0;i<3;i++)
	  {
	  	for(int j=0;j<3;j++)
	  	   {
	  	   	  if(zero_cross[i][j]==key)
	  	   	   {
	  	   	   	  zero_cross[i][j]=tic;
	  	   	   	  break;
			   }
		   }
	  }
}
bool check()
{
	if(zero_cross[0][0]=='x'&&zero_cross[1][0]=='x'&&zero_cross[2][0]=='x')
	 return true;
	if(zero_cross[0][1]=='x'&&zero_cross[1][1]=='x'&&zero_cross[2][1]=='x')
	 return true;
	if(zero_cross[0][2]=='x'&&zero_cross[1][2]=='x'&&zero_cross[2][2]=='x')
	 return true;
    if(zero_cross[0][0]=='x'&&zero_cross[0][1]=='x'&&zero_cross[0][2]=='x')
	 return true;
	if(zero_cross[1][0]=='x'&&zero_cross[1][1]=='x'&&zero_cross[1][2]=='x')
	 return true;
	if(zero_cross[2][0]=='x'&&zero_cross[2][1]=='x'&&zero_cross[2][2]=='x')
	 return true;
	if(zero_cross[0][0]=='x'&&zero_cross[1][1]=='x'&&zero_cross[2][2]=='x')
	 return true;
	if(zero_cross[2][0]=='x'&&zero_cross[1][1]=='x'&&zero_cross[0][2]=='x')
	 return true;
	if(zero_cross[0][0]=='o'&&zero_cross[1][0]=='o'&&zero_cross[2][0]=='o')
	 return true;
	if(zero_cross[0][1]=='o'&&zero_cross[1][1]=='o'&&zero_cross[2][1]=='o')
	 return true;
    if(zero_cross[0][2]=='o'&&zero_cross[1][2]=='o'&&zero_cross[2][2]=='o')
	 return true;
	if(zero_cross[0][0]=='o'&&zero_cross[0][1]=='o'&&zero_cross[0][2]=='o')
	 return true;
	if(zero_cross[1][0]=='x'&&zero_cross[1][1]=='x'&&zero_cross[1][2]=='x')
	 return true;
	if(zero_cross[2][0]=='o'&&zero_cross[2][1]=='o'&&zero_cross[2][2]=='o')
	 return true;
	if(zero_cross[0][0]=='o'&&zero_cross[1][1]=='o'&&zero_cross[2][2]=='o')
	 return true;
	if(zero_cross[2][0]=='o'&&zero_cross[1][1]=='o'&&zero_cross[0][2]=='o')
	 return true;
	return false;	
}
bool the_end()
{
	for(int i=0;i<3;i++)
	   {
	   	 for(int j=0;j<3;j++)
	   	    {
	   	    	if(zero_cross[i][j]!='o'&&zero_cross[i][j]!='x')
	   	    	  return false;
			}
	   }
	return true;
}
int main()
{
	print_zero_cross();
	cout<<"___________________________________________________________________"<<endl;
	cout<<"Let's play!!!"<<endl;
	cout<<"Type numbers between 1-9 ... Then number will be replaced by o or x"<<endl;
	cout<<"First player will use x and the other one will use o"<<endl;
	cout<<"___________________________________________________________________"<<endl;
	while(1)
	{
		 char key1;
		 cin>>key1;
		 display(key1,'x');
		 print_zero_cross();
		 
		 if(check())
		  {
		    cout<<"Hurray Player 1 is winner!!!"<<endl;
		    break;
          }
          
         if(the_end())
		  {
		  	cout<<"Match Tied!!!"<<endl;
		  	break;
		  }
          
         char key2;
		 cin>>key2;
		 display(key2,'o');
		 print_zero_cross();
		 
		 if(check())
		  {
		    cout<<"Hurray Player 2 is winner!!!"<<endl;
		    break;
          }
          
         if(the_end())
		  {
		  	cout<<"Match Tied!!!"<<endl;
		  	break;
		  }
		 
	 }
	return 0;
}
