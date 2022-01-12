/*

string 클래스를 대체하는 String 클래스를 구현
 
1. 문자열을 인자로 전달받는 생성자의 정의 
2. 생성자, 소멸자, 복사 생성사 (깊은 복사) 그리고 대입 연산자의 정의
3. 결합된 문자열로 초기화된 객체를 반환하는 + 연산자의 오버로딩 
4. 문자열을 덧붙이는 += 연산자의 오버로딩
5. 내용비교를 진행하는 == 연산자의 오버로딩
6. 콘솔입출력이 가능하도록 <<. >> 연산자의 오버로딩

*/ 

#include <iostream>
#include <cstring>


using namespace std;


class String
{
	private:
		int len;
		char* str;
		
	public:
		String();
		String(const char* s);
		String(const String& s);
		~String();
		String  operator+ (const String& s);
		String& operator= (const String& s);
		String& operator+= (const String& s);
		bool operator== (const String& s);
		
		friend ostream& operator<<(ostream& os, const String& s);
		friend istream& operator>>(istream& is, String& s);		
		
} ;
