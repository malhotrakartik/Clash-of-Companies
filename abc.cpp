#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std ;
int c;

class MNC 
{   public:
    float moneym ;
    MNC()
    {
        moneym=10000 ;
    }
    
};


class bank 
{   public:
    float moneyb ;
     bank()
    {
        moneyb=10000 ;
    }
    
};

class loan 
{
	public:
    int cycle,cstart,cend ;
    float intrest,amount ;
    float pay;
               loan()
    
    {
        cycle=0; intrest=0; cstart=-1 ; cend=-1 ; amount=0; pay=0;
    }
        void inloan()
    {
        cout<<"\nEnter no. of cycles:" ;
        cin>>cycle ;
        cout<<"\nEnter amount:" ;
        cin>>amount ;
        cout<<"\nEnter intrest %;" ;
        cin>>intrest ;
        cstart=c ;
        cend=c+1+cycle ;
        pay=(amount/cycle)+(amount*intrest/100) ;
    }

};

class asset 
{ 
	public:
    int ownerid,start ;
    float sp,cp,profit,bp;
    float bech;
    
    asset()
    {
        ownerid=0 ;
        sp=0; cp=0 ; profit=0 ; bp=0 ; start=100;
    }

    void inasset()
    {   cout<<"\nEnter ownerid" ;
        cin>>ownerid;

        cout<<"\nEnter profit:" ;
        cin>>profit;
        cout<<"\nEnter price bought:";
        cin>>cp;
        cout<<"\nEnter selling price:" ;
        cin>>sp ;
        start=c;
        
    }


};


int main()
{  
    MNC mnc[2] ;
    bank b[2] ; loan l[2][2]; asset a[10] ;
    for(c=0;c<20;c++)
    {  cout<<"\nSubcycle :"<<c+1 ;
       if((c<=4)||((c>=8)&&(c<=12))||((c>=16)&&(c<=20)))
       {
           for(int i=0;i<2;i++)
           {
               cout<<"\nMNC "<<i+1<<"\n"<<" balance:"<<mnc[i].moneym<<"\n"<<"\nWant to take Loan? y/n " ;
               char c1;
               cin>>c1;
               if((c1=='Y')||(c1=='y'))
               {
                   cout<<"\nEnter bank no:" ;
                   int x;
                   cin>>x;
                   x=x-1;
                   l[i][x].inloan() ;
                   b[x].moneyb=b[x].moneyb-l[i][x].amount ;
                   mnc[i].moneym=mnc[i].moneym+l[i][x].amount ;
                   
               }
               cout<<"\nWant to sell asset? y/n" ;
               char c2;
               cin>>c2;
               if((c2=='Y')||(c2=='y'))
               {
				   cout<<"\nEnter asset id:";
				   int a_id;
				   cin>>a_id;
				   cout<<"\nWhich bank do you wan to sell it to?" ;
				   int b_id ; 
				   cin>>b_id;
				   int tr=a[a_id-1].sp;
				   mnc[i].moneym = mnc[i].moneym+tr;
				   b[b_id-1].moneyb= b[b_id-1].moneyb - tr;
				   
			   }
               for(int j=0;j<2;j++)
               {          
                   
                   if((c>(l[i][j].cstart))&&(c<(l[i][j].cend)))
                       
                       {b[j].moneyb=b[j].moneyb+l[i][j].pay ;} 


                    if((c>=(l[i][j].cstart))&&(c<(l[i][j].cend-1)))
                        mnc[i].moneym=mnc[i].moneym-l[i][j].pay ;
                        cout<<"\nbank"<<j+1<<"balance:"<<b[j].moneyb ;
               }
           }
           for(int d=0;d<10;d++)
           {
               if(c>=a[d].start) { mnc[a[d].ownerid-1].moneym=mnc[a[d].ownerid-1].moneym+a[d].profit ;}
               
               
               
           }
           

       }
      else
       {
           for(int i=0;i<2;i++)
           {   cout<<"\nMNC "<<i+1<<" balance:"<<mnc[i].moneym ;
               
               cout<<"\nWant to buy asset?y/n ";
               char ch;
               cin>>ch;
                if((ch=='y')||(ch=='Y'))
				{
                    cout<<"\nEnter assest id" ;
                    int q ;
                    cin>>q ;
                    q--;
                    a[q].inasset() ;
                    mnc[a[q].ownerid-1].moneym=mnc[a[q].ownerid-1].moneym-a[q].bp-a[q].cp ;
                    
               }
               for(int j=0;j<2;j++)
               {          
                   
                   if((c>(l[i][j].cstart))&&(c<(l[i][j].cend)))
                       
                       {b[j].moneyb=b[j].moneyb+l[i][j].pay ;} 


                    if((c>=(l[i][j].cstart))&&(c<(l[i][j].cend-1)))
                        mnc[i].moneym=mnc[i].moneym-l[i][j].pay ;
                        cout<<"\nbank"<<j+1<<"balance:"<<b[j].moneyb ;
               }
           }
           
           for(int d=0;d<10;d++)
           {
               if(c>=a[d].start) { mnc[a[d].ownerid-1].moneym=mnc[a[d].ownerid-1].moneym+a[d].profit ;}
           
       
      
           }
		}
    }
}
