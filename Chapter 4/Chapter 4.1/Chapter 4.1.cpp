#include <iostream>

//#define START1
#define START2

using namespace std;


#ifdef START1

//RectangleFault.cpp
class Point
{
	public:
		int x; //x좌표의 범위는 0이상 100이하
		int y; //y좌표의 범위는 0이상 100이하 
};

class Rectangle
{
	public:
		Point upLeft;
		Point lowRight;
	
	public:
		void ShowecInfo()
		{
			cout<<"좌 상단: "<<'['<<upLeft.x<<",";
			cout<<upLeft.y<<']'<<endl;
			cout<<"우 하단: "<<'['<<lowRight.x<<",";
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
   	  	cout<<"잘못된 정보가 전달되어 판매를 취소합니다."<<endl;
   	  	return 0;
	  }

      int num = money / APPLE_PRICE;
      numOfApples -= num;
      myMoney += money;
      
      return num;
   }
   
   void ShowSalesResult() const
   {
      cout<<"남은 사과: "<<numOfApples<<endl;
      cout<<"판매 수익: "<<myMoney<<endl<<endl;
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
   	  		cout<<"잘못된 정보가 전달되어 판매를 취소합니다."<<endl;
   	  		return;
	 	}
	 	
         numOfApples += seller.SaleApples(money);
         myMoney -= money;
      }
      
      void ShowBuyResult() const
      {
         cout<<"현재 잔액: "<<myMoney<<endl;
         cout<<"사과 개수: "<<numOfApples<<endl;
      }

};



int main(void)
{
   FruitSeller seller;
   seller.InitMembers(1000, 20, 0);
   
   FruitBuyer buyer;
   buyer.InitMembers(5000);
   buyer.BuyApples(seller, 2000);  // 과일의 구매!
   
   cout<<"과일 판매자의 현황"<<endl;
   seller.ShowSalesResult();
   
   cout<<"과일 구매자의 현황"<<endl;
   buyer.ShowBuyResult();
   
   return 0; 
}

#endif /* START2 */
