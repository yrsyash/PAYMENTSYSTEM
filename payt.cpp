using namespace std;
#include<bits/stdc++.h>
#include<string.h>
void acc_create();
void home_screen();
void mobile_recharge();
void add_money();
void add_account();
void bank_modify();
void bank_delete();
void DTH_recharge();
void bill_electricity();
void broadband();
void pay(int amount);
void bankt();
void rail_tickets();
int flag=0;int a[9];char name[90];
int main()
{
 acc_create();
 int option,opt=1;
  while(opt==1)
{
 cout<<"Add Money(1)\t"<<"Add account(2)\t"<<"delete account(3)"<<endl;
 cout<<"Modify account(4)\t"<<"Recharge Phone(5)\t"<<"Pay electricity bill(6)"<<endl;
 cout<<"Book Tickets(7)\t"<<"DTH Recharge(8)\t"<<"Pay boadband bill(9)"<<endl;
 cout<<"Transfer to Bank(10)"<<endl;
 cout<<"Enter your choice(1/2/3/4/5/6/7/8/9/10)"<<endl;
 cin>>option;cout<<endl;
 switch(option)
 {
  case 1:
  add_money();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 2:
  add_account();
   cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 3:
  bank_delete();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 4:
  bank_modify();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 5:
  mobile_recharge();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 6:
   bill_electricity();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 7:
  rail_tickets();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 8:
  DTH_recharge();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 9:
  broadband();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  case 10:
  bankt();
  cout<<"Enter 1 to perform another action and 2 to exit"<<endl;
  cin>>opt;
  break;
  default:
  cout<<"INVALID INPUT";
 }
}
}

struct money
{
 int mon;  char bname[100],hname[100];
 char acn[90],cardno[90];int bankc;int count;
};

void acc_create()
{
  money mo;char ch='y';
  ofstream fout("app.dat",ios::out | ios::binary);
  while(ch=='y' || ch=='Y')
  {
  cout<<"Enter the bank name";
  gets(mo.bname);
  cout<<"Enter the bank holder's name";
  gets(mo.hname);
  cout<<"Enter the account number";
  gets(mo.acn);
  cout<<"Enter the card number";
  gets(mo.cardno);cout<<endl;
  cout<<"Enter the bank code";
  cin>>mo.bankc;cout<<endl;
  cout<<"Enter the amount";
  cin>>a[flag];
  mo.count=flag;
  fout.write((char*)&mo,sizeof(mo));
  flag++;
 cout<<"DO YOU WANT TO ENTER MORE ACCOUNTS"<<endl;
 cin>>ch;
}
}
void add_account()
{
 money mo;char ch='y';int i;
  ifstream fin("app.dat",ios::in | ios::binary);
  ofstream fout("temp.dat",ios::out | ios::binary);
  for(i=0;i<flag;i++)
 {
  fin.read((char*)&mo,sizeof(mo));
  fout.write((char*)&mo,sizeof(mo));
 }
  while(ch=='y' || ch=='Y')
  {
  cout<<"Enter the bank name";
  gets(mo.bname);
  cout<<"Enter the bank holder's name";
  gets(mo.hname);
  cout<<"Enter the account number";
  gets(mo.acn);
  cout<<"Enter the card number";
  gets(mo.cardno);
  cout<<"Enter the bank code";
  cin>>mo.bankc;cout<<endl;
  cout<<"Enter the amount";
  cin>>a[flag];
  mo.count=flag;
  fout.write((char*)&mo,sizeof(mo));
  flag++;
 cout<<"DO YOU WANT TO ENTER MORE ACCOUNTS"<<endl;
 cin>>ch;
}
fin.close();
fout.close();
remove("app.dat");
rename("temp.dat","app.dat");
}
void add_money()
{  int ncode;money mo;int adamt,i,t,ok=0;
 cout<<"Enter the bank code in which money is to be added";
 cin>>ncode;cout<<endl;
 ifstream fin("app.dat",ios::in | ios::binary);
 for(i=0;i<flag;i++)
 {
 fin.read((char*)&mo,sizeof(mo));
 if(mo.bankc==ncode)
 {t=mo.count;
 cout<<"Enter the amount to be added"<<endl;
 cin>>adamt;cout<<endl;
   a[t]=a[t]+adamt;
   ok=1;
 }
}
fin.close();
if(ok!=1)
cout<<"Bank Account doesn't exist"<<endl;
}
void bank_modify()
{   int ncode; money mo,mon;int ok=0,i;int t;
 cout<<"Enter the bank code whose modification is to be done";
 cin>>ncode; cout<<endl;
 ifstream fin("app.dat",ios::in | ios::binary);
 ofstream fout("temp.dat",ios::out | ios::binary);
 for(i=0;i<flag;i++)
 {
  fin.read((char*)&mo,sizeof(mo));
  if(ncode==mo.bankc)
  {t=mo.count;
   cout<<"Enter the bank name";
  gets(mon.bname);
  cout<<"Enter the bank holder's name";
  gets(mon.hname);
  cout<<"Enter the account number";
  cin>>mon.acn;cout<<endl;
  cout<<"Enter the card number";
  cin>>mon.cardno;cout<<endl;
  cout<<"Enter the bank code";
  cin>>mon.bankc;cout<<endl;
  cout<<"Enter the amount";
  cin>>a[t];cout<<endl;
  mon.count=t;
fout.write((char*)&mon,sizeof(mon));
   ok=1;
  }
 }
 if(ok!=1)
 cout<<"BANK ACCOUNT DOESN'T EXISTS";
remove("temp.dat");
 rename("temp.dat","app.dat");
}
void bank_delete()
{ money bd;int i,t;int ncode;
 cout<<"Enter the bank account to be deleted"<<endl;
 cin>>ncode;
 ifstream fin("app.dat", ios::in | ios::binary);
 ofstream fout("temp.dat",ios::out | ios::binary);
  for(i=1;i<=flag;i++)
  {
    fin.read((char*)&bd,sizeof(bd));
    if(bd.bankc!=ncode)
    {  t=bd.count;
	a[t]=0;
      fout.write((char*)&bd,sizeof(bd));
     }


  }
 remove("temp.dat");
 rename("temp.dat","app.dat");
}

struct mrcharge
{
char oname[90];long int rmn;int amt;
};
void mobile_recharge()
{
mrcharge mr,mrc,mo;int p=0,i;char ch='y';
ofstream fout("mrecharge.dat",ios::out | ios::binary);
 while(ch=='y')
{
 cout<<"Enter the operator"<<endl;
 gets(mr.oname);

cout<<"Enter the mobile number "<<endl;
cin>>mr.rmn;
cout<<"Enter the amount"<<endl;
cin>>mr.amt;

  fout.write((char*)&mr,sizeof(mr));
 cout<<"DO YOU WANT TO ENTER MORE MOBILE ACCOUNTS TO BE RECHARGED"<<endl;
 cin>>ch;
p++;
}

fout.close();
ifstream fin("mrecharge.dat",ios::in | ios::binary);
 int ncode;int ok=0,k=0,adamt=0;int y=0;
while(y==0)
{
   cout<<"THE DETAILS"<<endl;  
   for(i=1;i<=p;i++)
   {
     fin.read((char*)&mrc,sizeof(mrc));
     cout<<"The operator"<<endl;
     puts(mrc.oname);
     cout<<"The mobile number "<<endl;
     cout<<mrc.rmn;
     cout<<" The amount"<<endl;
     cout<<mrc.amt;
     adamt=adamt+mrc.amt;
    }
    fin.close();
    cout<<"Press 1 to confirm payment and 2 to edit details"<<endl;
    cin>>k;
    if(k==2)
   {
    cout<<"Enter the mobile number whose modification is to be done";
    cin>>ncode; cout<<endl;
    ifstream fin("mrecharge.dat",ios::in | ios::binary);
    ofstream fout("temp.dat",ios::out | ios::binary);
    for(i=1;i<=p;i++)
    {
     fin.read((char*)&mo,sizeof(mo));
     if(ncode==mo.rmn)
      {
       cout<<"Enter the operator"<<endl;
       gets(mr.oname);
       cout<<"Enter the mobile number "<<endl;
       cin>>mr.rmn;
       cout<<"Enter the amount"<<endl;
       cin>>mr.amt;
       fout.write((char*)&mr,sizeof(mr));
       ok=1;
      }
      else 
       fout.write((char*)&mo,sizeof(mo));
     }
      remove("mrecharge.dat");
      rename("temp.dat","mrecharge.dat");
      if(ok!=1)
      cout<<"MOBILE NUMBER DOESN'T EXISTS";
      
    }
    else if(k==3)
    {
      cout<<"Enter the bank account to be deleted"<<endl;
      cin>>ncode;
      ifstream fin("mrecharge.dat", ios::in | ios::binary);
      ofstream fout("temp.dat",ios::out | ios::binary);
      for(i=1;i<=p;i++)
      {
        fin.read((char*)&mr,sizeof(mr));
        if(mr.rmn!=ncode)
        {
          fout.write((char*)&mr,sizeof(mr));
        }
      }
      remove("mrecharge.dat");
      rename("temp.dat","mrecharge.dat");
      
    }
    if(k==1)
    {
     break;
    }
  }
 pay(adamt);
}
struct dtrcharge
{
 char pname[90];int id,rmn;int amt;
};
void DTH_recharge()
{ char ch='y';int i,p=0;
 dtrcharge dtr,dh,dr;
 ofstream fout("DTH.dat",ios::out | ios::binary);
 while(ch=='y')
{

 cout<<"Enter the service provider name"<<endl;
 gets(dtr.pname);
 cout<<"Enter the subscriber id"<<endl;
 cout<<dtr.id;
cout<<"Enter the registered mobile number"<<endl;
cin>>dtr.rmn;
cout<<"Enter the amount"<<endl;
cin>>dtr.amt;
fout.write((char*)&dtr,sizeof(dtr));
cout<<"Do you want to enter more DTH accounts"<<endl;
cin>>ch;
p++;
}
fout.close();
ifstream fin("DTH.dat",ios::in|ios::binary);
l3: int ncode;int ok=0,k=0,adamt=0;
 cout<<"THE DETAILS"<<endl;
for(i=1;i<=p;i++)
{
 fin.read((char*)&dtr,sizeof(dtr));
 cout<<"THE Service provider's NAME"<<endl;

 puts(dtr.pname);
 cout<<"The subscriber ID"<<endl;
 cout<<dtr.id;
 cout<<"The registered mobile number"<<endl;
 cout<<dtr.rmn;
 cout<<"Enter the amount"<<endl;
 cout<<dtr.amt;
adamt=adamt+dtr.amt;
}fin.close();
cout<<"Press 1 to confirm payment and 2 to edit details and 3 to delete"<<endl;
cin>>k;

if(k==2)
{
cout<<"Enter the subscriber id whose modification is to be done";
 cin>>ncode; cout<<endl;
 ifstream fin("DTH.dat",ios::in | ios::binary);
 ofstream fout("temp.dat",ios::out | ios::binary);
 for(i=1;i<=p;i++)
 {
  fin.read((char*)&dr,sizeof(dr));
  if(ncode==dr.id)
  {

  cout<<"Enter the new service provider";
  gets(dh.pname);
  cout<<"Enter the new subscriber id";
  cin>>dh.id;cout<<endl;
 cout<<"Enter the mobile number"<<endl;
 cin>>dh.rmn;
  cout<<"Enter the amount";
  cin>>dh.amt;cout<<endl;
 fout.write((char*)&dh,sizeof(dh));
   ok=1;
  }
 else
fout.write((char*)&dr,sizeof(dr));
 }    fin.close();
 fout.close();
 remove("mrecharge.dat");
rename("temp.dat","mrecharge.dat");
 if(ok!=1)
 cout<<"SUBSCRIBER ID DOESN'T EXISTS";
goto l3;
}
else if(k==3)
{
 cout<<"Enter the subscriber id of dth account to be deleted"<<endl;
 cin>>ncode;
 ifstream fin("DTH.dat", ios::in | ios::binary);
 ofstream fout("temp.dat",ios::out | ios::binary);
  for(i=1;i<=p;i++)
  {
    fin.read((char*)&dh,sizeof(dh));
    if(dh.id!=ncode)
    {
      fout.write((char*)&dh,sizeof(dh));
     }
  }
  fin.close();
  fout.close();
 remove("DTH.dat");
 rename("temp.dat","DTH.dat");
goto l3;
}
if(k==1)
{
 pay(adamt);
}
}
struct trticket
{
 char name[90],g;int age;
 int amt;
};
void rail_tickets()
{
 trticket ra,rt,trt;char ch='y',bst[90],dst[90],date[90],nname[90];int i,p=0;
 cout<<"Enter the boarding station"<<endl;
 gets(bst);
 cout<<"Enter the destination"<<endl;
 gets(dst);
 cout<<"Enter the journey date"<<endl;
 gets(date);
 cout<<"Enter the train name"<<endl;
 gets(name);
 ofstream fout("rail.dat",ios::out | ios::binary);
 while(ch=='y')
 {
  cout<<"Enter the details of the passenger"<<endl;
  cout<<"Enter the name";
  gets(ra.name);
  cout<<"Enter the age";
  cin>>ra.age;
  cout<<"Enter M for male and F for Female";
  cin>>ra.g;
  fout.write((char*)&ra,sizeof(ra));
  cout<<"Do you want to enter more passenger details"<<endl;
  cin>>ch;
  p++;
 }
 fout.close();
l4:
 ifstream fin("rail.dat",ios::in | ios::binary);
 for(i=1;i<=p;i++)
 {
   fin.read((char*)&ra,sizeof(ra));
   if(ra.age>=5)
   ra.amt=ra.amt+300;
   else
   ra.amt=ra.amt+500;
 }
 fin.close();
 int ok=0,k=0,adamt=0;
  cout<<"Check out the final detials"<<endl;
 ifstream fon("rail.dat",ios::in | ios::binary);

 for(i=1;i<=p;i++)
 {
  fon.read((char*)&ra,sizeof(ra));
  cout<<"The passenger's name"<<endl;
  puts(ra.name);
  cout<<"The passenger age"<<endl;
  cout<<ra.age;
  cout<<"The passenger gender"<<endl;
  cout<<ra.g;
  cout<<"The total amount"<<endl;
  cout<<ra.amt;
 adamt=adamt+ra.amt;
}fon.close();
  cout<<"press 1 to continue, 2 to edit passenger details and 3 to delete passenger details";
  cin>>k;

if(k==2)
{
cout<<"Enter the passenger name whose modification is to be done";
 gets(nname); cout<<endl;
 ifstream fin("rail.dat",ios::in | ios::binary);
 ofstream fout("temp.dat",ios::out | ios::binary);
 for(i=1;i<=flag;i++)
 {
  fin.read((char*)&ra,sizeof(ra));
  if(strcmp((ra.name),nname)==0)
  {
  cout<<"Enter the new passenger name";
  gets(trt.name);
  cout<<"Enter the new passenger age";
  cin>>trt.age;cout<<endl;
  cout<<"Enter the passenger's gender";
  cin>>trt.g;cout<<endl;
 fout.write((char*)&trt,sizeof(trt));
   ok=1;
  }
 else
fout.write((char*)&ra,sizeof(ra));
 }
 remove("rail.dat");
rename("temp.dat","rail.dat");
 if(ok!=1)
 cout<<"PASSENGER NAME DOESN'T EXISTS";
goto l4;
}
if(k==3)
{
 cout<<"Enter the passenger name to be deleted"<<endl;
 gets(nname);
 ifstream fin("rail.dat", ios::in | ios::binary);
 ofstream fout("temp.dat",ios::out | ios::binary);
  for(i=1;i<=flag;i++)
  {
    fin.read((char*)&trt,sizeof(trt));
    if(strcmp(trt.name,nname))
    {
      fout.write((char*)&trt,sizeof(trt));
     }
  }
 remove("rail.dat");
 rename("temp.dat","rail.dat");
goto l4;
}
if(k==1)
pay(adamt);
}
void broadband()
{int option;int code,num;int amt=0;
l:  int ch;
 cout<<"Choose the broadband network"<<endl;
 cout<<"Press 1 for Airtel limited"<<endl;
 cout<<"Press 2 for BSNL"<<endl;
 cout<<"Press 3 for Jio limited"<<endl;
 cin>>option;
 switch(option)
 {
  case 1:
  cout<<"Airtel Limited"<<endl;
  cout<<"Enter the mobile number and the telephone number"<<endl;
  cin>>num;
  cout<<"Enter the 10 digit unqique code"<<endl;
  cin>>code;
  cout<<"Enter the amount"<<endl;
  cin>>amt;
  cout<<"Press 1 to confirm payment and 2 to edit details"<<endl;
  cin>>ch;
  pay(amt);
  break;
  case 2:
    cout<<"BSNL Limited"<<endl;
  cout<<"Enter the mobile number and the telephone number"<<endl;
  cin>>num;
  cout<<"Enter the 10 digit unqique code"<<endl;
  cin>>code;
  cout<<"Enter the amount"<<endl;
  cin>>amt;
  cout<<"Press 1 to confirm payment and 2 to edit details"<<endl;
  cin>>ch;
  pay(amt);
  break;
  case 3:
  cout<<"JIO Limited"<<endl;
  cout<<"Enter the mobile number and the telephone number"<<endl;
  cin>>num;
  cout<<"Enter the 10 digit unqique code"<<endl;
  cin>>code;
  cout<<"Enter the amount"<<endl;
  cin>>amt;
  cout<<"Press 1 to confirm payment and 2 to edit details"<<endl;
  cin>>ch;
  pay(amt);
  break;
  default:
  cout<<"INVALID DETAILS"<<endl;
 }
 if(ch==1)
 pay(amt);
 else if(ch==2)
 goto l;
}
void bill_electricity()
{ char name[90],sname[90];int num;int amt;
 ln: int k;
 cout<<"Enter the name of the electricity supplier"<<endl;
 gets(name);
 cout<<"Enter the UID"<<endl;;
 cin>>num;
 cout<<"Enter the amount"<<endl;
 cin>>amt;
 cout<<"ELECTRICITY SUPPLIER IS";
 gets(sname);
 cout<<"Customer UID is"<<num<<endl;
 cout<<"THE AMOUNT"<<amt<<endl;
 cout<<"PRESS 1 to pay, PRESS 2 for edit details"<<endl;
 cin>>k;
 if(k==1)
 pay(amt);
 else if(k==2)
 goto ln;
}
struct bktransfer
{
 char bname[90],acname[90];int acn,bcode;int amt;
};
void bankt()
{ bktransfer bt,bk,bkt;char ch='y';int i,p=0;int ncode;
 while(ch=='y')
{
 ofstream fout("bttransfer.dat",ios::out | ios::binary);
 cout<<"Enter the bank name"<<endl;
 gets(bt.bname);
 cout<<"Enter the beneficary name"<<endl;
 gets(bt.acname);
cout<<"Enter the IFSC code "<<endl;
cin>>bt.bcode;
cout<<"Enter the account number"<<endl;
cin>>bt.acn;
cout<<"Enter the amount"<<endl;
cin>>bt.amt;
fout.write((char*)&bt,sizeof(bt));
cout<<"Do you want to enter more bank accounts"<<endl;
cin>>ch;
p++;
}
ifstream fin("bttransfer.dat",ios::in|ios::binary);
l5: int ok=0,k=0,adamt=0;
cout<<"THE DETAILS"<<endl;
for(i=1;i<=p;i++)
{
 fin.read((char*)&bt,sizeof(bt));
 cout<<"THE BANK NAME"<<endl;
 puts(bt.bname);
 cout<<"Enter the beneficiary name"<<endl;
 puts(bt.acname);
 cout<<"Enter the IFSC code"<<endl;
 cout<<bt.bcode;
 cout<<"The account number"<<endl;
 cout<<bt.acn;
 cout<<"Enter the amount"<<endl;
 cout<<bt.amt;
 adamt=bt.amt+adamt;
}
cout<<"Press 1 to confirm payment and 2 to edit details"<<endl;
cin>>k;
if(k==2)
{
cout<<"Enter the IFSC whose modification is to be done";
 cin>>ncode; cout<<endl;
 ifstream fin("bttransfer.dat",ios::in | ios::binary);
 ofstream fout("temp.dat",ios::out | ios::binary);
 for(i=1;i<=p;i++)
 {
  fin.read((char*)&bk,sizeof(bk));
  if(ncode==bk.bcode)
  {
   cout<<"Enter the new bank name"<<endl;
 gets(bkt.bname);

cout<<"Enter the new benficiary name "<<endl;
puts(bkt.acname);

cout<<"Enter the IFSC code"<<endl;
cin>>bkt.bcode;
 cout<<"Enter the account number"<<endl;
cin>>bkt.acn;
cout<<"Enter the amount"<<endl;
cin>>bkt.amt;

 fout.write((char*)&bkt,sizeof(bkt));
   ok=1;
  }
 else
fout.write((char*)&bk,sizeof(bk));
 }
 remove("bttransfer.dat");
rename("temp.dat","bttransfer.dat");
 if(ok!=1)
 cout<<"IFSC CODE DOESN'T EXISTS";
 goto l5;
}
if(k==3)
{
 cout<<"Enter the  IFSC CODE  of bank account to be deleted"<<endl;
 cin>>ncode;
 ifstream fin("bttransfer.dat", ios::in | ios::binary);
 ofstream fout("temp.dat",ios::out | ios::binary);
  for(i=1;i<=p;i++)
  {
    fin.read((char*)&bkt,sizeof(bkt));
    if(bkt.bcode!=ncode)
    {
      fout.write((char*)&bkt,sizeof(bkt));
     }
  }
 remove("bttransfer.dat");
 rename("temp.dat","bttransfer.dat");
 goto l5;
}

if(k==1)
{
pay(adamt);
}
}
void pay(int amount)
{money mo;int i,t;int ncode;
 cout<<"Enter the bank code of your bank"<<endl;
 cin>>ncode;
 ifstream fin("app.dat",ios::in|ios::binary);
 for(i=1;i<=flag;i++)
{
 fin.read((char*)&mo,sizeof(mo));
 if(mo.bankc==ncode)
  { 
 t=mo.count;
 a[t]=a[t]-amount;
}
}
cout<<"THANK YOU YOUR PAYMENT IS DONE"<<endl;
fin.close();
}

















