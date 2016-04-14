//============================================================================
// Name        : TempTest.cpp
// Author      : Malcolm Ma
// Description : A practice of constructor,copy assignment with String.
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class CMystring{
public:
    CMystring():size_t(0),m_pData(NULL){};
    CMystring(const char *pData);
    CMystring(const CMystring &str);
    ~CMystring(){delete[] m_pData;}
    CMystring copyString(const CMystring &s);
    CMystring& operator=(const CMystring &rhs);
    void print()const{
        cout<<m_pData<<endl;
    }
    int getSize()const{
        return size_t;
    }
private:
    void swap(CMystring &target);
    int size_t;
    char *m_pData;
};

CMystring::CMystring(const char *pData){
    size_t=strlen(pData);
    m_pData=new char[size_t+1];
    strcpy(m_pData,pData);
}

CMystring::CMystring(const CMystring &str){
    size_t=strlen(str.m_pData);
    m_pData=new char[size_t+1];
    strcpy(m_pData,str.m_pData);
}

/*
 * Overloading operator=
 * Method 1. Simple way
 * Potential bug:the m_pData is deleted before allocating a new space for string,
 * if an exception occur then we have a wandering pointer.
 */
/*
CMystring& CMystring::operator=(const CMystring &rhs){
    if(this == &rhs)
        return *this;
    delete[] m_pData;               //delete the old resource
    size_t=strlen(rhs.m_pData);
    m_pData = new char[size_t+1];   //strcpy copies the ending null character
    strcpy(m_pData,rhs.m_pData);    //and doesn't check destination array overflow
    return *this;
}
*/

/*
 * Overloading operator=
 * Method 2. Exception Safe
 * This method first calls the copy constructor to create a temp object on the stack.
 * If an exception occurs during constructor then the lhs won't change.
 * After swapping,the m_pData will be referenced by tempString,which is then deleted
 * after function ends.
 */

CMystring& CMystring::operator =(const CMystring &rhs){
    CMystring tempString(rhs);
    this->swap(tempString);
    return *this;
}


void CMystring::swap(CMystring &target){
    std::swap(this->m_pData,target.m_pData);
    std::swap(this->size_t,target.size_t);  //don't forget to exchange the size
}



/*
 * BAD code demonstration!!Why returning a class type is not a good idea.
 * When returning s1,actually a copy constructor is called to build an object,
 * which is usually not intended.
 */
CMystring copyString(const CMystring &s){
    CMystring s1("Inefficient copy method");
    return s1;
}

int main()
{
    //First,test the default constructor CMystring(char*)
    CMystring s1("default constructor");
    cout<<"output:\n";
    s1.print();
    cout<<"size="<<s1.getSize()<<endl;

    //Second,test the copy assignment operator=(char*)
    /*
     * Although I did't implement the operator=(char*) function,the following
     * still works.What happens is,the compiler will first call CMstring(char*)
     * to construct a CMystring and then call the operator=(CMystring &),which
     * is defined above.
     */
    s1="performed copy assignment";
    s1.print();

    //Third,test the copy constructor
    CMystring s2(s1);
    s2.print();
    cout<<"size="<<s2.getSize()<<endl;


    //Fourth,test the copy assignment operator=(CMystring &)
    CMystring s3;
    s3=s2;
    s3.print();
    cout<<"size="<<s3.getSize()<<endl;

    //Bad code demonstration
    CMystring s4("this is s3");
    s4=copyString(s4);
    s4.print();

}



