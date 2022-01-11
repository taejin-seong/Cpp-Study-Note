#include <iostream>
#include <cstdlib>

//#define START1
//#define START2
//#define START3
//#define START4
//#define START5
//#define START6
//#define START7
#define START8
 

using namespace std;


#ifdef START1

//ArrayClass.cpp
class BoundCheckIntArray
{
	private:
		int* arr;
		int arrlen;
	
	public:
		BoundCheckIntArray(int len) : arrlen(len)
		{
			arr = new int[len];
		}
		
		int& operator[] (int idx)
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
		}
		
		~BoundCheckIntArray()
		{
			delete []arr;
		}
};



int main(void)
{
	BoundCheckIntArray arr(5);
	
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i+1)*11;
	}
	
	for (int i = 0; i < 6; i++)
	{
		cout<<arr[i]<<endl;
	}
	
	return 0;
}

#endif /* START1 */






#ifdef START2


using namespace std;


//StableArrayClass.cpp
class BoundCheckIntArray 
{
private:
	int * arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
	BoundCheckIntArray(int len) :arrlen(len)
	{
		arr=new int[len];
	}
	int& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		delete []arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);

	for(int i=0; i<5; i++)
		arr[i]=(i+1)*11;

	//BoundCheckIntArray copy1(5);
	//copy1=arr;
	//BoundCheckIntArray copy=arr;
	return 0;
}
#endif /* START2 */






#ifdef START3

//StableConstArrayProb.cpp
class BoundCheckIntArray
{
	private:
		int* arr;
		int arrlen;
		BoundCheckIntArray(const BoundCheckIntArray& arr) { }
		BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
	
	public:
		BoundCheckIntArray(int len) : arrlen(len)
		{
			arr = new int[len];
		}
		
		int& operator[] (int idx)
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
		}
		
		
		int GetArrLen() const
		{
			return arrlen;
		}
		
		
		~BoundCheckIntArray()
		{
			delete []arr;
		}
};




void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	
	for(int idx = 0; idx < len; idx++)
	{
		cout<<ref[idx]<<endl;
	}
}




int main(void)
{
	BoundCheckIntArray arr(5);
	
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i+1)*11;
	}
	
	ShowAllData(arr);
	
	return 0;
	
}

#endif /* START3 */






#ifdef START4

//StableConstArraySolu.cpp
class BoundCheckIntArray
{
	private:
		int* arr;
		int arrlen;
		BoundCheckIntArray(const BoundCheckIntArray& arr) { }
		BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
	
	public:
		BoundCheckIntArray(int len) : arrlen(len)
		{
			arr = new int[len];
		}
		
		
		int& operator[] (int idx)
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
		}
		
		//const의 선언유무도 함수 오버로딩의 조건에 해당한다.
		int operator[] (int idx) const
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
			
		}
		
		 
		int GetArrLen() const
		{
			return arrlen;
		}
		
		
		~BoundCheckIntArray()
		{
			delete []arr;
		}
};




void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	
	for(int idx = 0; idx < len; idx++)
	{
		cout<<ref[idx]<<endl;
	}
}




int main(void)
{
	BoundCheckIntArray arr(5);
	
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i+1)*11;
	}
	
	ShowAllData(arr);
	
	return 0;
	
}
#endif /* START4 */





#ifdef START5

//StablePointObjArray.cpp
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y) 
		{ }
		
		friend ostream& operator<<(ostream& os, const Point& pos);
};





ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
}





class BoundCheckPointArray
{
	private:
		Point* arr;
		int arrlen;
		
		BoundCheckPointArray(const BoundCheckPointArray& arr) { }
		BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }
	
	public:
		BoundCheckPointArray(int len) : arrlen(len)
		{
			arr = new Point[len];
		}
		
		Point& operator[] (int idx)
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
		}
		
	
		Point operator[] (int idx) const
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
			
		}
		
		 
		int GetArrLen() const
		{
			return arrlen;
		}
		
		
		~BoundCheckPointArray()
		{
			delete []arr;
		}
	
};





int main(void)
{
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);
	
	for(int i = 0; i <arr.GetArrLen(); i++)
	{
		cout<<arr[i];
	}
	
	return 0;
}
#endif /* START5 */






#ifdef START6

//StablePointPtrArray.cpp
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y) 
		{ }
		
		friend ostream& operator<<(ostream& os, const Point& pos);
};



ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
}




typedef Point* POINT_PTR; //Point 포인터 형을 의미하는 POINT_PTR 정의 




class BoundCheckPointPtrArray
{
	private:
		POINT_PTR* arr;
		int arrlen;
		
		BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
		BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }
	
	public:
		BoundCheckPointPtrArray(int len) : arrlen(len)
		{
			arr = new POINT_PTR[len];
		}
		
		POINT_PTR& operator[] (int idx)
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
		}
		
	
		POINT_PTR operator[] (int idx) const
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
			
		}
		
		 
		int GetArrLen() const
		{
			return arrlen;
		}
		
		
		~BoundCheckPointPtrArray()
		{
			delete []arr;
		}
	
};




int main(void)
{
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);
	
	for(int i = 0; i <arr.GetArrLen(); i++)
	{
		cout<<*(arr[i]);
	}
	
	
	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}
#endif /* START6 */







#ifdef START7

//p468 Question 11-2 NO.1
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y) 
		{ }
		
		friend ostream& operator<<(ostream& os, const Point& pos);
		friend ostream& operator<<(ostream& os, const Point* pos);
};



ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	
	return os;
}


ostream& operator<<(ostream& os, const Point* pos)
{
	os<<'['<<pos->xpos<<", "<<pos->ypos<<']'<<endl;
	
	return os;
}


typedef Point* POINT_PTR; 




class BoundCheckPointPtrArray
{
	private:
		POINT_PTR* arr;
		int arrlen;
		
		BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
		BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }
	
	public:
		BoundCheckPointPtrArray(int len) : arrlen(len)
		{
			arr = new POINT_PTR[len];
		}
		
		POINT_PTR& operator[] (int idx)
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
		}
		
	
		POINT_PTR operator[] (int idx) const
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
			
		}
		
		 
		int GetArrLen() const
		{
			return arrlen;
		}
		
		
		~BoundCheckPointPtrArray()
		{
			delete []arr;
		}
	
};




int main(void)
{
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);
	
	for(int i = 0; i <arr.GetArrLen(); i++)
	{
		cout<<arr[i];
	}
	
	
	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}
#endif /* START7 */






#ifdef START8

//p468 Question 11-2 NO.2
class BoundCheckIntArray
{
	private:
		int* arr;
		int arrlen;
		BoundCheckIntArray(const BoundCheckIntArray& arr) { }
		BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
	
	public:
		BoundCheckIntArray(int len) : arrlen(len)
		{
			arr = new int[len];
		}
		
		
		int& operator[] (int idx)
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
		}
		
		int operator[] (int idx) const
		{
			if (idx < 0 || idx >= arrlen)
			{
				cout<<"Array index out of bound excpetion"<<endl;
				exit(1);
			}
			
			return arr[idx];
			
		}
		
		 
		int GetArrLen() const
		{
			return arrlen;
		}
		
		
		~BoundCheckIntArray()
		{
			delete []arr;
		}
};



typedef BoundCheckIntArray* BoundChekIntArrayPtr;



class BoundCheck2DIntArray
{
	private:
		BoundCheckIntArray **arr;
		int arrlen;
		BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) { }
		BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) { }
	
	public:
	BoundCheck2DIntArray(int col, int row) : arrlen(col)
	{
		arr =new BoundChekIntArrayPtr[col];
		
		for ( int i = 0; i < col; i++)
		{
			arr[i] = new BoundCheckIntArray(row);
		}
	}	
	
	
	BoundCheckIntArray& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen) 
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return *(arr[idx]);
	}
	
	~BoundCheck2DIntArray()
	{
		for (int i = 0; i < arrlen; i++)
		{
			delete arr[i];
		}
		
		delete []arr;
	}
};




int main(void)
{
	BoundCheck2DIntArray arr2d(3, 4);
	
	
	for (int n = 0; n < 3; n++)
	{
		for(int m = 0; m < 4; m++)
		{
			arr2d[n][m] = n+m;
		}
	}
	
	
	for (int n =0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			cout<<arr2d[n][m]<<" ";
			cout<<endl;		
		}
	}

	return 0;
	
}
#endif /* START8 */
