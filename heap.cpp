#include<iostream>
using namespace std;
#define Max 10

class heap
{

	float Minheap[Max],Maxheap[Max];

	public:
	void insertMinHeap(float);
	void insertMaxHeap(float);
	
	void UpAdjustMin(int);
	void UpAdjustMax(int);
	void Create();
	float FindMax();
	
	float FindMin();
	
	};
void heap::insertMinHeap(float x)
	{
		int n = Minheap[0];
		Minheap[n+1] = x;
		Minheap[0] = n+1;

		UpAdjustMin(n+1);

	}
	
void heap:: insertMaxHeap(float x)
	{
		int n = Maxheap[0];
		Maxheap[n+1] = x;
		Maxheap[0] = n+1;
		
		UpAdjustMax(n+1);

	}
	void heap::UpAdjustMax(int i)
	{
		

		while((i > 1) && Maxheap[i] > Maxheap[i/2])
		{
			
                    int temp = Maxheap[i/2];
					Maxheap[i/2] = Maxheap[i];
					Maxheap[i] = temp;
			
			i = i/2;
		}
	}
	void heap:: UpAdjustMin(int i)
	{
		 

		while((i > 1) && Minheap[i] < Minheap[i/2])
		{
			
                    int temp = Minheap[i/2];
					Minheap[i/2] = Minheap[i];
					Minheap[i] = temp;
			

			i = i/2;
		}
	}
	
	void heap:: Create()
	{
		int n;
		float x;

		cout<<"Enter number of stud: \n";
		cin>>n;

		Maxheap[0] = 0;
		Minheap[0] = 0;

		for(int i = 0; i< n; i++)
		{
          cout<<"Enter marks for: "<<i+1<<"\n";
		  cin>>x;

		  insertMaxHeap(x);
		  insertMinHeap(x);
		} 

	}
	
	float heap:: FindMax()
	{
		/*int n = Maxheap[0];
		cout<<"\nMax mark"<<Maxheap[1];

		for(int i = 0; i<=n;i++)
		{
			cout<<"\n"<<Maxheap[i];
		}
		*/
		

		return Maxheap[1];
    }
	float heap:: FindMin()
	{
		/*int n = Minheap[0];
		cout<<"\nMax mark"<<Minheap[1];

		for(int i = 0; i<=n;i++)
		{
			cout<<"\n"<<Minheap[i];
		}
		*/
		return Minheap[1];
	}

int main()
{
	heap h;
	h.Create();

	cout<<"Max value is: "<<h.FindMax()<<"\n";
	
	cout<<"Min value is: "<<h.FindMin()<<"\n";

	return 0;
}