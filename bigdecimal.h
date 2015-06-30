//Contributed By Shubhankit Saxena and Team From National Institute Of Technology Agartala
#ifndef BIG_DECIMAL_H
#define BIG_DECIMAL_H
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
class BigDecimal
{
public:
	string add(string , string);
	string subtract(string , string);
	string multiply(string , string);
	string char_remove(string,char);
	//division functions strat
	int get_actuall_length(string s);
    void make(int diff,string &result);
    string make_for_diff(string s2,int diff);
    bool compare(string sub, string s2);
    bool isallzero(string sub);
    bool isallzero_for_inf(string s);
    string  divide(string s1,string s2);
    string mod(string s1, string s2);
	BigDecimal(){}
	~BigDecimal(){}
};
// for removal of any specific character from string given
string BigDecimal::char_remove(string n1,char ch)
{
   string::iterator itr1=find(n1.begin(),n1.end(),ch); // finds postion of character
	n1.erase(itr1);  //erasing character
	return n1;
}

//subtracttraction function
string BigDecimal::subtract(string n1,string n2)
{
  // data type declration start
  int i=0,j=0,f1=0,f2=0,temp,l1,l2;
  int t1,t2,lv,br=0;

  string ans,ans2,s_temp;
  // data type declration ends

  // checking either string is negative or not
  if(n1[0]=='-'&&n2[0]=='-')     //if both string is negative
    {
       s_temp=n1;
      n1=char_remove(n2,'-');      //since both is negative i.e (-)n1-(-)n2 = n2-n1 =>sub(n2,n1)
      n2=char_remove(s_temp,'-');       // char_remove for removing -ve char_remove
      s_temp.clear();          // clear content of string
    }
else if(n1[0]=='-')                 // if first strinh have -ve
{
    n1=char_remove(n1,'-');
	return ans="-"+add(n1,n2);       // (-n1)-(n2)=-(n1+n2)
}
else if(n2[0]=='-')                // if 2nd strinh have -ve
{
   n2=char_remove(n2,'-');
	return ans=add(n1,n2);          //(n1)-(-n2)=(n1+n2)
}
//-ve checking ends


  l1=n1.size();        //size of string after removing -ve char_remove if any
  l2=n2.size();

  //checking dot present or not in n1
  while(i<l1)
   {
     if(n1[i]=='.')
       {
          f1++;         //if dot present then flagvalue1 set i.e 1 and breakout from while loop
          break;
        }
        i++;
   }
 //checking dot present or not in n2
   while(j<l2)
   {
     if(n2[j]=='.')
       {
          f2++;             //if dot present then flagvalue2 set i.e 1 and breakout from while loop
          break;
        }
        j++;
   }
   //dot checking ends


    t1=l1-i-1;   // number of zer0 that will be inserted
	t2=l2-j-1;
    if(f1==1&&f2==1)  // if both have dots
     {
    	if(t1>t2)
    	{
    		while(t1-t2)
    		{
    			n2+='0';        //insertinh zero after dot
    			t1--;
    		}
    	}
    	else if(t2>t1)
    	{
    			while(t2-t1)
    		{
    			n1+='0';                     //insertinh zero after dot
    			t2--;
    		}
    	}
    	if(i>j)      // i>j denoting first have moredigit before dot so insert zero in n2 before starting digit
        {
            while(i-j++)
             n2='0'+n2;                 //insertinh zero befor dot...eg: (222.254,25.250)=>(222.254,025.250)



        }
        else if(i<j)            // i<j denoting 2nd have more digit before dot so insert zero in n1 before starting digit
        {
            while(j-i++)           //insertinh zero befor dot...eg: (2.254,25.250)=>(02.254,25.250)
            n1='0'+n1;
        }
        else                         //i==j
        {
           n1='0'+n1;
		    n2='0'+n2;
        }

     }
    else if((f1==1&&f2==0)||(f1==0&&f2==1))  // if one string have dot
     {
    	if(f2==0)
    	{
    		n2+='.';                     //inserting dot  and after dot insert zero acoording to second string
    		while(t1--!=0)
    		n2+='0';
    	}
    	else
    	{
    		n1+='.';
    		while(t2--!=0)                //inserting dot  and after dot insert zero acoording to second string
    		n1+='0';
    	}
    	if(i>j)
        {
            while(i-j++)                             //insertinh zero befor dot...eg: (2.254,25.250)=>(02.254,25.250)
           n2='0'+n2;
        }
        else if(i<j)
        {
            while(j-i++)                          //insertinh zero befor dot...eg: (2.254,25.250)=>(02.254,25.250)
            n1='0'+n1;
        }
      }
    else                         // both dont have dot
    {
       if(l1>l2)
       {
         while(i-j++)                             //insertinh zero befor digit ...eg: (225,25)=>(225,025)
            n2='0'+n2;
       }
       else if(l1<l2)
       {
         while(j-i++)                          //insertinh zero befor digit ...eg: (5,25)=>(05,25)
            n1='0'+n1;
       }

    }

    // here we hets n1 and n2 having equall length
      i=0;
     lv=0;
    l1=n1.size();
    l2=n2.size();

    // checking which string greater
    while(i<l1)
    {
       if(n1[i]!=n2[i])
       {
           if(n1[i]>n2[i])
            {
			  lv=1;
              break;
            }
            else
            {
			  lv=2;
              break;
			}
       }
       i++;
    }

if(lv==0)      //lv still remain 0 => strings are equall so ans =0
return "0";

    for(i=l1-1;i>=0;i--)
    {
       if(lv==1)                 // string n1 is greater
       {
           if(n1[i]=='.')          // if dot comes then add dot and decrease i=i-1
                  {
				    ans+='.';
                    i--;
                    if(i<0)
                    break;
                  }

             if(br==0)
             {
               if(n1[i]>=n2[i])
                temp=n1[i]-n2[i];
               else
                {
                  temp=n1[i]-n2[i]+10;                           //sustraction logic
                  br=1;
                }
             }
            else
            {
               if(n1[i]-1>=n2[i])
                {
			    	temp=n1[i]-n2[i]-1;
                    br=0;
				}
               else
               temp=n1[i]-n2[i]-1+10;
            }
           ans+=(char)(temp+'0');
       }
       if(lv==2)
       {
           if(n2[i]=='.')
                  {
				    ans+='.';
                    i--;
                    if(i<0)
                     break;
                  }

             if(br==0)
             {
               if(n2[i]>=n1[i])
                temp=n2[i]-n1[i];                      //sustraction logic
               else
                {
                  temp=n2[i]-n1[i]+10;
                   br=1;
               }
             }
            else
            {
             if((n2[i]-1)>=n1[i])
                {
                   temp=n2[i]-n1[i]-1;
                    br=0;
                }
               else
                 temp=n2[i]-n1[i]-1+10;
            }
            ans+=(char)(temp+'0');
       }
    }

// substrction ends and result in ans bt in reverse manner
    i=ans.size()-1;

    if(lv==2)               // ie string 2 is greater so n1-n2=-ve
    ans2+="-";


while(ans[i]=='0'&&i>0&&ans[i-1]!='.')    // for removal of too many zero if before actual digit 0009=>9
     i--;

  while(i>=0)
  {
    ans2+=ans[i];                      //copy after removal of zero if present or copy simply in string ans2
     i--;
  }

return ans2;
}


//addition of strings
string BigDecimal::add(string n1, string n2)
{    //data type declaration starts
    int l1,l2,i,j,k=0,n,m,flag,carry=0,temp,f1=0,f2=0,lv=0;
    int t1,t2;
    string ans,ans2;
    //data type declaration ends

    //checking for negative strings
    if(n1[0]=='-'&&n2[0]=='-')                 // both negative strings
    {
      n1=char_remove(n1,'-');
      n2=char_remove(n2,'-');
       lv++;
    }
  else if(n1[0]=='-')                        //first string negative so,-n1+n2=>n2-n1=>sub(n2,n1)
   {
     n1=char_remove(n1,'-');
	return subtract(n2,n1);
   }
 else if(n2[0]=='-')                      //second string negative so n1-n2=>sub(n1,n2)
   {     n2=char_remove(n2,'-');
	   return subtract(n1,n2);
   }

    l1=n1.size();
    l2=n2.size();
    i=0;
    //dot checking
    while(i<l1)          //  if dot present in string 1
    {
    	if(n1[i]=='.')
    	{
    		f1++;
    		break;
    	}
    	i++;             //i gives postion of dot from strating
    }

   j=0;
  while(j<l2)          //  if dot present in string 1
    {
    	if(n2[j]=='.')
    	{
    		f2++;
    		break;
    	}
    	j++;           //j gives postion of dot from strating
    }

    t1=l1-i-1;     //after dot how many numbers
	t2=l2-j-1;
//inserting zeros and dots accordingly
    if(f1==1&&f2==1)     //dot presents in both
    {
    	if(t1>t2)        //if first string have more numbers after dot than 2nd string
    	{
    		while(t1-t2)
    		{
    			n2+='0';      //insert zero in 2nd string
    			t1--;
    		}
    	}
    	else if(t2>t1)       //if 2nd string have more numbers after dot than 1st string
    	{
    			while(t2-t1)
    		{
    			n1+='0';       //insert zero in 1st string
    			t2--;
    		}
    	}

    }
    else if((f1==1&&f2==0)||(f1==0&&f2==1))       //only one string have dots
    {
    	if(f2==0)                      //string2 dont have dots
    	{
    		n2+='.';
    		while(t1--!=0)            // insert zeros after dot as many int string 1 after dot
    		n2+='0';

    	}
    	else                                //string1 dont have dots
    	{
    		n1+='.';
    		while(t2--!=0)          // insert zeros after dot as many int string 2 after dot
    		n1+='0';
    	}
    }
    //dot and zero insertion ends here

    l1=n1.size();
    l2=n2.size();
    if(l1>=l2)               //checks for greater length not for greatre strings
    {
        n=l1-1;
        m=l2-1;
        flag=1;
    }
    else
    {
        n=l2-1;
        m=l1-1;
        flag=2;
    }

        for(i=n;i>=0;--i)
        {
                if(flag==1)              // str1>=str2
                {
                  if(n1[i]=='.')
                  {
				    ans+='.';
                    i--;
					m--;
                    if(i<0)
                    break;
                  }
                    if(m>=0)
                        temp=n1[i]+n2[m]+carry-96;      // addition  logic
                    else
                        temp=n1[i]+carry-48;

                    if(temp>9)
                    {
                        temp%=10;
                        carry=1;
                    }
                    else
                        carry=0;

                }
                else
                {
                   if(n2[i]=='.')
                    {
				     	ans+='.';
                        i--;
						m--;
                      if(i<0)
                      break;
				    }
                    if(m>=0)
                        temp=n2[i]+n1[m]+carry-96;    // additionlogic
                    else
                        temp=n2[i]+carry-48;

                    if(temp>9)
                    {
                        temp%=10;
                        carry=1;
                    }
                    else
                        carry=0;
                }



                ans+=(char)(temp+'0');


              m--;
        }
        if(carry==1)           //if in last carry remains then add
            ans+='1';

        if(lv==1)
         ans2+="-";

          i=ans.size()-1;

         if(ans[i]=='.')         // for .2=>0.2
          {
           ans+='0';i++;
		  }

while(ans[i]=='0'&&i>0&&ans[i-1]!='.')    // for removal of too many zero if before actual digit 0009=>9
     i--;

  while(i>=0)
  {
    ans2+=ans[i];                      //copy after removal of zero if present or copy simply in string ans2
     i--;
  }

return ans2;
}

//multiply

string BigDecimal::multiply(string first,string sec){
        string F,S,temp;
		F=first;
		S=sec;
		char s1='+',s2='+';
		if(F.at(0)=='-')
		{
		 s1='-';
		 F.erase(F.begin());
		}
		if(S.at(0)=='-')
		{
		 s2='-';
		 S.erase(S.begin());
		}
		int p1=0,p2=0,p=0;
		string::iterator itr;
		string::reverse_iterator it1,it2;
		itr=find(F.begin(),F.end(),'.');
		if(itr!=F.end())
		{
			it1=F.rbegin();
			while(*it1!='.')
			{
			 ++p1;
			 ++it1;
			}
			++it1;
			F.erase(it1.base());
		}
		itr=find(S.begin(),S.end(),'.');
		if(itr!=S.end())
		{
			it2=S.rbegin();
			while(*it2!='.')
			{
			 ++p2;
			 ++it2;
			}
			++it2;
			S.erase(it2.base());
		}
		p=p1+p2;
        int f_len,s_len,f,s,r,t_len,hold,res;
        f_len=F.size();
        s_len=S.size();
        reverse(F.begin(),F.end());
        reverse(S.begin(),S.end());
        t_len=f_len+s_len;
        r=-1;
            temp=string(t_len,'0');
			for(s=0;s<s_len;++s){

            hold=0;
            for(f=0;f<f_len;++f){

                res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
                temp[f+s]=res%10+'0';
                hold=res/10;
                if(f+s>r) r=f+s;
            }
            while(hold!=0){
                res=hold+temp[f+s]-'0';
                hold=res/10;
                temp[f+s]=res%10+'0';
                if(r<f+s) r=f+s;
                f++;
            }
        }
	reverse(temp.begin(),temp.end());
	string str=temp;
	string::iterator tit=str.begin();
	while(*tit=='0')
	{
	 tit=str.erase(tit);
	}
	if(str.empty())
	{
	 str="0";
	 return str;
	}
	string::reverse_iterator it=temp.rbegin();
	if(p!=0)
	temp.insert((it+p).base(),'.');
	string::iterator itr1=temp.begin();
	while(*itr1=='0')
	{
	 itr1=temp.erase(itr1);
	}
	if(temp[0]=='.')
	temp='0'+temp;
	if(temp.empty())
		temp="0";
	else if(s1!=s2)
		temp='-'+temp;
	return temp;
    }


 //division functions
 int BigDecimal::get_actuall_length(string s)
{
    int i=0;
    while(s[i]=='0')
        i++;
    return s.length()-i;
}
void BigDecimal::make(int diff,string &result){
	string s="1";
	for(int i=diff;i>0;i--)
		s=s+"0";
	result=add(s,result);
}

string BigDecimal::make_for_diff(string s2,int diff)
{
string s=s2;

for(int i=0;i<diff;i++)
	s+="0";

return s;
}

bool BigDecimal::compare(string sub, string s2)
{
    if(sub[0]=='0')
    {
        int i=0,ln=sub.length();

        while(i<ln&&sub[0]=='0')
        {
             sub=char_remove(sub,'0');
             i++;
        }
    }
  if(s2[0]=='0')
    {
        int i=0,ln=s2.length();
        while(i<ln&&s2[0]=='0')
        {
             s2=char_remove(s2,'0');
             i++;
        }
    }

int i=0;
if(sub.length()<s2.length())
    return false;
 else if(sub.length()==s2.length())
    {
       while(i<sub.length())
       {
           if(sub[i]<s2[i])
             return false;
            else if(sub[i]>s2[i])
            return true;
           i++;
      }
 return true;
   }
else if(sub.length()>s2.length())
     return true;

}

bool BigDecimal::isallzero(string sub)
{
for(int i=0;i<sub.length();i++)
{
if(sub[i]!='0')
return false;
}
return true;
}

bool BigDecimal::isallzero_for_inf(string s)
{
    int i=0;
    while(s[i]!='\0'&&s[i]!='.')
    {
        if(s[i]!='0')
            return false;

        i++;
    }

    if(s[i]=='\0')
        return true;

    if(s[i]=='.')
    {
        i++;
        while(s[i]!='\0')
        {
            if(s[i]!='0')
                return false;
                i++;
        }
    }

    return true;
}

string  BigDecimal::divide(string s1,string s2)
{   int i;
    if(isallzero_for_inf(s1)==true&&isallzero_for_inf(s2)==true)
        return "math error";
    else if(isallzero_for_inf(s1)==true)
        return "0";
    else if(isallzero_for_inf(s2)==true)
        return "infinite";
    if(s2[0]=='0')
    {
        i=0;
        while(i<s2.length()&&s2[0]=='0')
        {
             s2=char_remove(s2,'0');
             i++;
        }
    }
    if(s1[0]=='-'&&s2[0]=='-')
    {
        s1=char_remove(s1,'-');
        s2=char_remove(s2,'-');
    }
int flag=0;//0 means no - ve or both -

    if(s1[0]=='-')
    {
        s1=char_remove(s1,'-');
	flag=1;//means  one -
    }

    if(s2[0]=='-')
    {
        s2=char_remove(s2,'-');
	flag=1;
    }

    int len1=0,len2=0;
 i=-1;
    for( i=s1.length();i>=0;i--)
    {
        if(s1[i]=='.')
            break;

    }
if(i!=-1)
 len1=s1.length()-i-1;
i=-1;
 for( i=s2.length();i>=0;i--)
    {
        if(s2[i]=='.')
            break;

    }
if(i!=-1)
len2=s2.length()-i-1;

if(len1>len2)
{
    for(i=len1-len2;i>0;i--)
        s2+="0";
}
else
{
    for(i=len2-len1;i>0;i--)
        s1+="0";
}

string::iterator itr1=find(s1.begin(),s1.end(),'.');
if(*itr1==46)
	s1.erase(itr1);
string::iterator itr2=find(s2.begin(),s2.end(),'.');
if(*itr2==46)
	s2.erase(itr2);

 if(s1[0]=='0')
    {
        int ln=s1.length();
        i=0;

        while(i<ln&&s1[0]=='0')
        {
             s1=char_remove(s1,'0');
             i++;
        }
    }
  if(s2[0]=='0')
    {
        int ln=s2.length();
        i=0;
        while(i<ln&&s2[0]=='0')
        {
             s2=char_remove(s2,'0');
             i++;
        }
    }



  string result,temp,sub;
  string pre;
  sub=s1;
  int count=0;
  while(1)
  {

      int diff=get_actuall_length(sub)-s2.length()-1;
      if(compare(sub,s2)==false)//if sub is smaller than s2 return false
          break;
      make(diff,result);

      temp=make_for_diff(s2,diff);

      sub=subtract(sub,temp);

      if(isallzero(sub)==true)
        break;
  }

if(isallzero(sub)!=true)
{
   result+='.';
    int j=1;
    while(j<=20)
  {
      sub+="0";
      int count=0;
      while(compare(sub,s2)==true)
      {
          count++;
           sub=subtract(sub,s2);
      }
      result+=char(count%10+'0');
      j++;

  }
}
if(result[0]=='.')
result='0'+result;
if(flag==1)
result='-'+result;

return result;
}

string BigDecimal::mod(string s1,string s2)
{  BigDecimal ob;
    string temp;
    while(s1[0]=='0'&&s1.size()>1)
         s1.erase(s1.begin());

    while(1)
    {  temp=s1;
        s1=ob.subtract(s1,s2);

        if(s1[0]=='-')
         return temp;
         else if(s1[0]=='0'&&s1.size()==1)
            return "0";
    }
}
#endif
