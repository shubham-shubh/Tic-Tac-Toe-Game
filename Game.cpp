#include <iostream>
using namespace std;
class game{
    char zero_cross[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    //during the time of declaration of 2d array no of rows is optional
    void printLine()
    {
        for(int j=0;j<11;j++)
		   cout<<'=';
    }
    public:
      void getter()
      {
          for(int i=0;i<5;i++)
	        {
	   	        cout<<" ";
	   	        if(i%2==0)
	   	          cout<<" "<<zero_cross[i/2][0]<<" | "<<zero_cross[i/2][1]<<" | "<<zero_cross[i/2][2];
		        else
		         printLine();
		       cout<<endl;
	        }
      }
      //default constructor
     game()
      {
          getter();
          cout<<"___________________________________________________________________"<<endl;
          cout<<"Let's play!!!"<<endl;
	      cout<<"Type numbers between 1-9 ... Then number will be replaced by o or x"<<endl;
	      cout<<"First player will use x and the other one will use o"<<endl;
	      cout<<"___________________________________________________________________"<<endl;
      }
     bool setter(char key,char mark)
     {
         for(int i=0;i<3;i++)
	       {
	  	      for(int j=0;j<3;j++)
	  	        {
	  	   	       if(zero_cross[i][j]==key)
	  	   	        {
	  	   	   	       zero_cross[i][j]=mark;
	  	   	   	       return true;
			        }
		        }
	       }
	     return false;
     }
    
    bool check()
    {
        if(checkRow())
         return true;
        
        if(checkCol())
         return true;
        
        if(leftDiagonal())
         return true;
        
        if(rightDiagonal())
         return true;
         
        return false;
    }
   bool checkRow()
    {
        for(int i=0;i<3;i++)
          {
              bool flag=true;
              for(int j=0;j<2;j++)
                {
                    if(zero_cross[i][j]!=zero_cross[i][j+1])
                     {
                         flag=false;
                         break;
                     }
                }
              if(flag)
               return true;
          }
        return false;
    }
   
   bool checkCol()
    {
        for(int j=0;j<3;j++)
          {
              bool flag=true;
              for(int i=0;i<2;i++)
                {
                    if(zero_cross[i][j]!=zero_cross[i+1][j])
                     {
                         flag=false;
                         break;
                     }
                }
              if(flag)
               return true;
          }
        return false;
    }
  
   bool leftDiagonal()
    {
        bool flag=true;
        for(int i=0;i<2;i++)
          {
              if(zero_cross[i][i]!=zero_cross[i+1][i+1])
               {
                   flag=false;
                   break;
               }
          }
        if(flag)
         return true;
        return false;
    }
   bool rightDiagonal()
    {
        bool flag=true;
        for(int i=0;i<2;i++)
          {
              if(zero_cross[i][2-i]!=zero_cross[i+1][1-i])
               {
                   flag=false;
                   break;
               }
          }
        if(flag)
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
   
//  bool matchTied()
//   {
//   	  if(check())
//   	   return true;
//   	  for(int i=0;i<3;i++)
//   	     {
//   	     	for(int j=0;j<3;j++)
//   	     	   {
//   	     	   	   if(zero_cross[i][j]>='1'&&zero_cross[i][j]<='9')
//   	     	   	    {
//   	     	   	    	zero_cross[i][j]='x';
//   	     	   	    	if(matchTied())
//                         return true;
//   	     	   	    	zero_cross[i][j]='o';
//   	     	   	        if(matchTied())
//   	     	   	         return true;
//					}
//			   }
//	     }
//	   return false;
//   }
};
int main() 
{
    game tic_tac_toe;
	while(1)
	{
		 while(1)
		    {
		    	char key1;
		        cin>>key1;
		        if(!tic_tac_toe.setter(key1,'x'))
		         {
		         	cout<<"This key is already Pressed!!!"<<endl;
		    	    cout<<"Try Another key"<<endl;
				 }
				else
				 break;
			}
		 tic_tac_toe.getter();
		 
		 if(tic_tac_toe.check())
		  {
		    cout<<"Hurray Player 1 is winner!!!"<<endl;
		    break;
          }
          
         if(tic_tac_toe.the_end())
		  {
		  	cout<<"Match Tied!!!"<<endl;
		  	break;
		  }
//          if(!tic_tac_toe.matchTied())
//           {
//           	 cout<<"Match Tied!!!"<<endl;
//           	 break;
//		   }
          
         
		 while(1)
		    {
		    	char key2;
		        cin>>key2;
		        if(!tic_tac_toe.setter(key2,'o'))
		         {
		         	cout<<"This key is already Pressed!!!"<<endl;
		    	    cout<<"Try Another key"<<endl;
				 }
				else
				 break;
			}
		 tic_tac_toe.getter();
		 
		 if(tic_tac_toe.check())
		  {
		    cout<<"Hurray Player 2 is winner!!!"<<endl;
		    break;
          }
          
//         if(tic_tac_toe.the_end())
//		  {
//		  	cout<<"Match Tied!!!"<<endl;
//		  	break;
//		  }
		 
	 }
	return 0;

}
