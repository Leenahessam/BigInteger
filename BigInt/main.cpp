
#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;

class BigDecimalInt{
private:
 int num;
bool negative=false;
 int Size=0;
 vector<int>arr;

public:

 friend ostream& operator<< (ostream& out , BigDecimalInt big0) ;


 BigDecimalInt ()
 {

 }

 BigDecimalInt(string st)
 {
 string temp;
 if (st[0]=='-'){
 negative=st[0]=='-'?true:false;
 st.erase(0,1);
for (int i=0;i<st.length();i++){
    if (i==0){
    temp=st[i];
    stringstream strInt(temp);
    strInt>>num;
    arr.push_back(num*-1);
    }
    else{
    temp=st[i];
    stringstream strInt(temp);
    strInt>>num;
    arr.push_back(num);
 }}
 }
 else {
 for (int i=0;i<st.length();i++){
   temp=st[i];
   stringstream strInt(temp);
   strInt>>num;
   arr.push_back(num);
 }

 }
 Size=st.length();
 }



BigDecimalInt operator= (BigDecimalInt big4){
 for(int i=0;i<Size;i++){
    this->arr[i]=big4.arr[i];
 }

return big4;

 }



 BigDecimalInt operator+ (BigDecimalInt big2){
 BigDecimalInt big3;
 //x+y
 if (this->arr[0]>=0 && big2.arr[0]>=0){
 for (int i=(Size-1);i>=0;i--){
    if (i==0){
        num=this->arr[i]+big2.arr[i];
        big3.arr.push_back(num);
        break;
    }
    num=this->arr[i]+big2.arr[i];
    if (num<10){
    big3.arr.push_back(num);
           }
    else if (num>=10){
       num=num-10;
       big3.arr.push_back(num);
       big2.arr[i-1]=big2.arr[i-1]+1;
}
}
}
//-x+-y=(x+y)*-1
else {
if (this->arr[0]<0 && big2.arr[0]<0){
 this->arr[0]=this->arr[0]*-1;
 big2.arr[0]=big2.arr[0]*-1;
 for (int i=(Size-1);i>=0;i--){
    if (i==0){
    num=this->arr[i]+big2.arr[i];
    big3.arr.push_back(num);
    break;
    }
    num=this->arr[i]+big2.arr[i];
    if (num<10){
    big3.arr.push_back(num);
           }
    else if (num>=10){
       num=num-10;
       big3.arr.push_back(num);
       big2.arr[i-1]=big2.arr[i-1]+1;
}
}
big3.arr[Size-1]=big3.arr[Size-1]*-1;
}


//-x+y=y-x

else if (this->arr[0]<0 && big2.arr[0]>0){
this->arr[0]=this->arr[0]*-1;

if (big2.arr[0]>this->arr[0]){
for (int i=(Size-1);i>=0;i--){
    if (i==0){
       num=big2.arr[i]-(this->arr[i]);
       big3.arr.push_back(num);
       break;
    }

    if (big2.arr[i]>=this->arr[i]){
        num=big2.arr[i]-this->arr[i];
        big3.arr.push_back(num);
    }

    else if (this->arr[i]>big2.arr[i]){
        big2.arr[i]=big2.arr[i]+10;
        num=big2.arr[i]-this->arr[i];
        big3.arr.push_back(num);
        big2.arr[i-1]=big2.arr[i-1]-1;}


}}
else {
  for (int i=(Size-1);i>=0;i--)  {
        num=this->arr[i]-big2.arr[i];
        if (num<0){
            num*=-1;
        }
        if (i!=0){
        big3.arr.push_back(num);}
        else {
            big3.arr.push_back(num*-1);
        }
  }

}
}
//x-y
 else if (this->arr[0]>0 && big2.arr[0]<0){
big2.arr[0]=big2.arr[0]*-1;
if (this->arr[0]>big2.arr[0]){
for (int i=(Size-1);i>=0;i--){
    if (i==0){
       num=(this->arr[i])-big2.arr[i];
       big3.arr.push_back(num);
       break;
    }


    if (this->arr[i]>=big2.arr[i]){
        num=this->arr[i]-big2.arr[i];
        big3.arr.push_back(num);
    }

    else if (this->arr[i]<big2.arr[i]){
        this->arr[i]=this->arr[i]+10;
        num=this->arr[i]-big2.arr[i];
        big3.arr.push_back(num);
        this->arr[i-1]=this->arr[i-1]-1;}


}
//big3.arr[Size-1]=big3.arr[Size-1]*-1;
}

else {
  for (int i=(Size-1);i>=0;i--){
    num=big2.arr[i]-this->arr[i];
    if (num<0){
            num*=-1;
        }
    if (i!=0){
        big3.arr.push_back(num);
    }
    else {
        big3.arr.push_back(num*-1);
    }
}


}



return big3;
}}}


BigDecimalInt operator- (BigDecimalInt big2){
 BigDecimalInt big3;
 //x-y

 if (this->arr[0]>0 && big2.arr[0]>0){
 if (this->arr[0]>big2.arr[0]){
 for (int i=(Size-1);i>=0;i--){
    if (i==0){
       num=this->arr[i]-big2.arr[i];
       big3.arr.push_back(num);
       break;
    }
    if (this->arr[i]>=big2.arr[i]){
        num=this->arr[i]-big2.arr[i];
        big3.arr.push_back(num);
    }

    else if (this->arr[i]<big2.arr[i]){
        this->arr[i]=this->arr[i]+10;
        num=this->arr[i]-big2.arr[i];
        big3.arr.push_back(num);
        this->arr[i-1]=this->arr[i-1]-1;}}




}
else {
    for (int i=(Size-1);i>=0;i--){
        num=big2.arr[i]-this->arr[i];
        if (num<0){
            num*=-1;
        }
        if (i!=0){
        big3.arr.push_back(num);
        }
        else {

            big3.arr.push_back(num*-1);
        }
    }

}}
else{
    //-x-(-y)=-x+y=y-x
if (this->arr[0]<0 && big2.arr[0]<0){
big2.arr[0]=big2.arr[0]*-1;
//cout<<"-";
return (big2+*this);
}


  //-x-y
if (this->arr[0]<0 && big2.arr[0]>0){
this->arr[0]=this->arr[0]*-1;
cout<<"-";
  return(*this+big2);
}

  //x--y
if (this->arr[0]>0 && big2.arr[0]<0){
  big2.arr[0]=big2.arr[0]*-1;
  return(*this+big2);
}
}

  return big3;
}};

ostream& operator<<(ostream& out , BigDecimalInt big0)
{
    for(int i = (big0.arr.size()-1) ; i >=0  ; i--)
    {
        out << big0.arr[i] << " ";
    }
return out ;
}

int main()
{

 BigDecimalInt num1("123456789012345678901234567890");
 BigDecimalInt num2("113456789011345678901134567890");
 BigDecimalInt num3=(num1+num2);
 //236913578023691357802369135780
 cout<<"1- 123456789012345678901234567890+113456789011345678901134567890="<<endl;
 cout<<endl;
 cout <<num3<<endl ;
 cout<<endl;cout<<endl;
 cout<<"---------------------------------------------------------"<<endl;


 BigDecimalInt num5("333333333333333333333333333333");
 BigDecimalInt num6("-111111111111111111111111111111");
 BigDecimalInt num7=(num5+num6);
 //222222222222222222222222222222
 cout<<"2- 333333333333333333333333333333+-111111111111111111111111111111="<<endl;
 cout<<endl;
 cout<<num7<<endl;
 cout<<endl<<endl;
 cout<<"---------------------------------------------------------"<<endl;

 BigDecimalInt num123("-12345");
 BigDecimalInt num22("98765");
 BigDecimalInt num44=(num123+num22);
 //86420
 cout<<"3- -12345+98765="<<endl;
 cout<<endl;
 cout<<num44;
 cout<<endl<<endl;
 cout<<"----------------------------------------------------------"<<endl;

 BigDecimalInt num88("-12345");
 BigDecimalInt num17("-98765");
 BigDecimalInt num28=(num88+num17);
 //-111110
 cout<<"4- -12345+-98765="<<endl;
 cout<<endl;
 cout<<num28<<endl;
 cout<<endl<<endl;
 cout<<"---------------------------------------------------------"<<endl;

 BigDecimalInt num87("-98765");
 BigDecimalInt num86("12345");
 BigDecimalInt num14=(num87+num86);
 //-86420
 cout<<"5- -98765+12345="<<endl;
 cout<<endl;
 cout<<num14<<endl;
 cout<<endl<<endl;


}
