#include <iostream> 
#define START1



#ifdef START1
/*
1. �ζ��� �Լ��� ��ũ�� �Լ� ó�� �Լ��� ȣ��� ���� ������ �Ҵ�� ��ȯ�̶�� ������ ������ �� ���� -> ���� ���, ��ũ�� �Լ� ���� 
2. �ζ��� �Լ��� ������ �Լ��鵵 �ζ��� �Լ���� ���� ������ -> ��ũ�� �Լ� ���� ����
3. ��ũ�� �Լ���"��ó����"�� ���ؼ� ó���ȴ�. (������ ������ ó�� ��),
4. ��ũ�� �Լ��� ������ ����� �ϴ� �ζ��� �Լ��� "�����Ϸ�"�� ó����. -> �ζ���ȭ�� ������ ���ɿ� �ذ� �ȴٰ� �Ǵ��� ���, �����ع����⵵ �Ѵ�. 
5. ��ũ�� �Լ��� �ڷ����� �������̳�.. �ζ��� �Լ��� �ڷ����� ������. 
*/

//InlineFunc.cpp
inline int SQUARE(int x)  // �ζ��� �Լ��� ���ǹ��, Ű���� inline�� ������ ���ؼ� �Լ� SQUARE�� �ζ��� �Լ��� �Ǿ���. 
{
	return x*x;
}

int main(void)
{
	std::cout<<SQUARE(5)<<std::endl;  // �ζ��� �Լ��� SQUARE �Լ� ȣ��  
	std::cout<<SQUARE(12)<<std::endl;
	
	return 0;
}

#endif /* START1 */