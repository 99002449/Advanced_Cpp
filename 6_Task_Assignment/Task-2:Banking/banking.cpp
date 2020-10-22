#include "account.h"
#include "banking.h"
#include<list>
#include<iostream>
#include<algorithm>
//using namespace std;
double sum=0;
void Banking::addAccount(std::string id,std::string name,double bal) {
   //Account temp(id,name,bal);
   //accounts.push_back(temp);     //Method-1
   accounts.push_back(Account(id,name,bal));  //Method-2
   //accounts.emplace_back(id,name,bal);  //Method-3,C++11
}
void Banking::displayAll() {

 auto var =std::for_each(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return  r1.display();}
);

      
   /* for(Account& ref:accounts)    //C++11
        ref.display();  
   */
   /* for(auto& ref:accounts) 
        ref.display();
   */   
}
double Banking::findAverageBalance()
{
 

auto var =std::for_each(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return ((sum+=r1.getBalance()) );}
);


return sum/3;


/*

//std::vector<double> vbal;
   std::list<Account>::iterator iter;
   double sum=0;
   int count=0;
   double avg=0;
   for(iter=accounts.begin();iter!=accounts.end();++iter)
	{
      		sum+=iter->getBalance();
		count++;
	}
   avg=(sum/count);
   return avg;*/
}
int Banking::countAccountsByBalanceRange(double min,double max) 
{  
 auto var =std::count_if(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return ((r1.getBalance()>=min) && (r1.getBalance()<=max) );}
);


return var;



/*
int count=0;
std::list<Account>::iterator iter;
   for(iter=accounts.begin();iter!=accounts.end();++iter)
       if((iter->getBalance()>=min) && (iter->getBalance()<=max))
		count+=1;
return count;*/
}

Account* Banking::findAccountById(std::string keyId) 
{
    auto var =std::find_if(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return (r1.getId()==keyId );}
);
if(&(*var)!= NULL)
  return &(*var);
else 
return NULL;

}
void Banking::removeAccountById(std::string keyId) 
{
   auto pos=std::find_if(accounts.begin(),accounts.end(),[=] (Account& r1)
{ return  (r1.getId() == keyId) ;}
);
    cout<<pos->getId();
    if(&(*pos)!=NULL)
    accounts.erase(pos);
    
    
}
/*

  std::list<Account>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter)
  {
    if(iter->getId()==keyId)
        break;
  }
  if(iter!=accounts.end())
    accounts.erase(iter); 
}*/
Account* Banking::findAccountWithMinBalance() {
   auto var =std::min_element(accounts.begin(),accounts.end(),[=] (Account&  r1, Account& r2) 
{ return ( r1.getBalance() < r2.getBalance());}
);
if(&(*var)!= NULL)
  return &(*var);
else 
return NULL;
         

}
  
  
  

        

