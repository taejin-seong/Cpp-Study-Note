#include <iostream>

//#define START1
#define START2

using namespace std;


#ifdef START1

//RectangleFault.cpp
class Point
{
	public:
		int x; //x��ǥ�� ������ 0�̻� 100����
		int y; //y��ǥ�� ������ 0�̻� 100���� 
};

class Rectangle
{
	public:
		Point upLeft;
		Point lowRight;
	
	public:
		void ShowecInfo()
		{
			cout<<"�� ���: "<<'['<<upLeft.x<<",";
			cout<<upLeft.y<<']'<<endl;
			cout<<"�� �ϴ�: "<<'['<<lowRight.x<<",";
			cout<<lowRight.y<<']'<<endl<<endl;
			 
		}
};

int main(void)
{
	Point pos1 = {-2, 4};
	Point pos2 = {5, 9};
	Rectangle rec = {pos2, pos1};
	rec.ShowecInfo();
	
	return 0;	
}

#endif /* START1 */




#ifdef START2

//p160 Question 4-1

class FruitSeller
{

private:
   int APPLE_PRICE;
   int numOfApples;
   int myMoney;
   
public:
   void InitMembers(int price, int num, int money)
   {
      APPLE_PRICE = price;
      numOfApples = num;
      myMoney = money;   
   }
   
   int SaleApples(int money)
   {
   	  if (money < 0)
   	  {
   	  	cout<<"�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�."<<endl;
   	  	return 0;
	  }

      int num = money / APPLE_PRICE;
      numOfApples -= num;
      myMoney += money;
      
      return num;
   }
   
   void ShowSalesResult() const
   {
      cout<<"���� ���: "<<numOfApples<<endl;
      cout<<"�Ǹ� ����: "<<myMoney<<endl<<endl;
   }
};


class FruitBuyer
{
   int myMoney;     // private:
   int numOfApples; // private:
   
   public:
      void InitMembers(int money)
      {
         myMoney = money;
         numOfApples =0;
      }
      
      void BuyApples(FruitSeller &seller, int money)
      {
      	if (money < 0)
   	  	{
   	  		cout<<"�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�."<<endl;
   	  		return;
	 	}
	 	
         numOfApples += seller.SaleApples(money);
         myMoney -= money;
      }
      
      void ShowBuyResult() const
      {
         cout<<"���� �ܾ�: "<<myMoney<<endl;
         cout<<"��� ����: "<<numOfApples<<endl;
      }

};



int main(void)
{
   FruitSeller seller;
   seller.InitMembers(1000, 20, 0);
   
   FruitBuyer buyer;
   buyer.InitMembers(5000);
   buyer.BuyApples(seller, 2000);  // ������ ����!
   
   cout<<"���� �Ǹ����� ��Ȳ"<<endl;
   seller.ShowSalesResult();
   
   cout<<"���� �������� ��Ȳ"<<endl;
   buyer.ShowBuyResult();
   
   return 0; 
}

#endif /* START2 */
