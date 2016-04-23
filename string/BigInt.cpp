#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

class BigInt{
private:
	int sign;
	std::vector<char> digits;

public:
	BigInt(const int &capacity):sign(1),digits(capacity){}

	BigInt(const std::string &s):sign(s[0]=='-'?-1:1),
							digits(s.size()-(s[0]=='-')){
		for(int i=s.size()-1,j=0;i>=(s[0]=='-');i--,j++){
			if(isdigit(s[i])){
				digits[j]=s[i]-'0';
			}
		}
	}

	BigInt operator*(const BigInt &rhs)const{
		BigInt result(digits.size()+rhs.digits.size());
		result.sign=sign*rhs.sign;
		size_t i,j;
		for(i=0;i<rhs.digits.size();i++){
			if(rhs.digits[i]){
				int carry=0;
				for(j=0;j<digits.size()||carry;j++){
					int n_digit=result.digits[i+j]+
							(j<digits.size()?rhs.digits[i]*digits[j]:0)+
							carry;
					result.digits[i+j]=n_digit%10;
					carry=n_digit/10;
				}
			}
		}
		if((digits.size()==1&&digits.front()==0)||
				(rhs.digits.size()==1&&rhs.digits.front()==0)){
			result.digits.resize(1);
		}else{
			result.digits.resize(i+j-1);
		}
		return result;
	}

	std::string getString() const{
		std::string result;
		for(int i=digits.size()-1;i>=0;i--)
			result+=digits[i]+'0';
		return result;
	}
};

int main(){
	using namespace std;
	cout<<"BigInt testing\n";
	string num1="99",num2="98";
	BigInt a(num1),b(num2);
	BigInt c=a*b;
	cout<<"a="<<a.getString()<<endl;
	cout<<"b="<<b.getString()<<endl;
	cout<<c.getString();
}
