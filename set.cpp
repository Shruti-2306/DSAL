#include<iostream>
using namespace std;

class Set
{
	int setA[10];
	int setB[10];
	int setU[10];
	int setD[10];
	int n,m,ele;
	char c;

	public:
	 Set()
	 {
		for(int i = 0; i < 10; i++)
		{
			setA[i] = -1;
			setB[i] = -1;
			setU[i] = -1;
		}
	 }

	 void create()
	 {
		cout<<"*********SET A***********\n";
		cout<<"Enter how many ele in A: ";
		cin>>n;

		cout<<"Enter number ";
		cout<<"Enter unique number always: \n";

		for(int i =1; i<= n; i++)
		{
			cin>>setA[i];
		}

			cout<<"*********SET B***********\n";
		cout<<"Enter how many ele in B: ";
		cin>>m;

		cout<<"Enter number ";
		cout<<"Enter unique number always: \n";

		for(int i =1; i<= m; i++)
		{
			cin>>setB[i];
		}
	 }

	 void display()
	 {
		cout<<"**************************\n";
		cout<<"SET A = {";
		for(int i = 1; i <= n; i++)
		{
			cout<<setA[i]<<" ";
		}
		cout<<"}"<<endl;

		cout<<"**************************\n";
		cout<<"SET B = {";
		for(int i = 1; i <= m; i++)
		{
			cout<<setB[i]<<" ";
		}
		cout<<"}"<<endl;
	 }
	 
	 bool cointainA()
	 {
		cout<<"Enter element: ";
		cin>>ele;

		for(int i = 0; i <= n; i++)
		{
			if(setA[i] == ele)
			{
				return true;
			}
		}
		return false;
	 }

	  bool cointainB()
	 {
		cout<<"Enter element: ";
		cin>>ele;

		for(int i = 0; i <= m; i++)
		{
			if(setB[i] == ele)
			{
				return true;
			}
		}
		return false;
	 }
	 void Add()
	 {
		cout<<"**********************\n";
		cout<<"Enter set: ";
		cin>>c;

		if(c =='a' || c=='A')
		{
			if(cointainA())
			{
			cout<<"not inserted because "<<ele<<" is already present\n";
			}
		}
		else
		{
			int pos;
			cout<<"enter position: ";
			cin>>pos;

			n= n+1;

			if(pos == n+1)
			{
				setA[pos] = ele;
			}
			else
			{
				for(int i = n; i>= pos; i--)
				{
					setA[i] = setA[i-1];
				}
				setA[pos] = ele;
			}
		}
	 

	 if(c=='b' || c== 'B')
	 {
		if(cointainB())
			{
			cout<<"not inserted because "<<ele<<" is already present";
			}
		}
		else
		{
			int pos;
			cout<<"enter position: ";
			cin>>pos;

			m= m+1;

			if(pos == m+1)
			{
				setB[pos] = ele;
			}
			else
			{
				for(int i = m; i>= pos; i--)
				{
					setB[i] = setB[i-1];
				}
				setB[pos] = ele;
			}

	    }
	 }

	 void remove()
	 {
		cout<<"******************************\n";
		cout<<"Enter set: ";
		cin>>c;

		cout<<"Enter element: ";
		cin>>ele;

		if(c =='a' || c=='A')
		{
			int i;
			for(i = 1; i<= n; i++)
			{
				if(setA[i] == ele)
				{
					break;
				}
			}


			if(i <= n)
			{
				for(int j = i; j < n; j++)
				{
					setA[j] = setA[j+1];
				}
				n= n+1;
			}

			else
			{
				cout<<ele<<" is not present"<<endl;
			}
		}

	 

	 
		if(c =='b' || c=='B')
		{
			int i;
			for(i = 1; i<= m; i++)
			{
				if(setB[i] == ele)
				{
					break;
				}
			}


			if(i <= m)
			{
				for(int j = i; j < m; j++)
				{
					setB[j] = setB[j+1];
				}
				m= m+1;
			}

			else
			{
				cout<<ele<<" is not present"<<endl;
			}
		}

		display();
		
	 }

	 void size()
	 {
		cout<<"*****************************\n";
		int count = 0;
		cout<<"Enter set: ";
		cin>>c;

		if(c=='a' || c=='A')
		{
			for(int i = 0; i< 10; i++)
			{
				if(setA[i] != -1)
				{
					count = count +1;
				}
			}

			cout<<"size of set A: "<<count<<"\n";
		}
			if(c=='b' || c=='B')
		{
			for(int i = 0; i< 10; i++)
			{
				if(setB[i] != -1)
				{
					count = count +1;
				}
			}

			cout<<"size of set B: "<<count<<"\n";
		}
		cout<<"****************************\n";
	 }

	 void Union()
	 {
		cout<<"**************************\n";
		for(int i = 1; i<= n; i++)
		{
			setU[i] = setA[i];
		}

		for(int j =1; j<=m; j++)
		{
			setU[n +j] = setB[j];
		}

		cout<<"union: { ";
		for(int i =1 ; i <= (n+m); i++)
		{
			int k = 0;
			for(int j = i+1 ; j <= (n+m); j++)
			{
				if(setU[i] == setU[j])
				{
					k = 1;
					break;
				}
			}
			if(k==0)
			{
				cout<<setU[i]<<" ";
			}
		}
		cout<<"}"<<"\n";
		cout<<"**********************\n";
	 }

	 void intersection()
	 {
		cout<<"************************\n";
		cout<<"intersection: {";
		for(int i = 1; i <= n; i++)
		{
			for(int j=1; j <= m; j++)
			{
				if(setA[i] == setB[j])
				{
					cout<<setA[i]<<" ";
				}
			}
		}
		cout<<"}";
		cout<<"****************************\n";
	 }

	 void difference()
	 {
		cout<<"*********************\n";
		int choice;

		do
		{
			cout<<"1. A - B"<<"\n";

            cout<<"2. B - A"<<"\n";		

			cout<<"3.Exit\n";

			cout<<"Enter choice: ";
			cin>>choice;

			switch(choice)
			{
				case 1:
				for(int i = 1; i <= n ; i++)
				{
					setD[i] = setA[i];
				}
				cout<<"Difference (A -B): {";
				for(int i =1; i<= n; i++)
				{
					int k = 0;
					for(int j =1 ; j <= m; j++)
					{
                        if(setD[i] == setB[j])
						{
							 k= 1;
							 break;
						}
					}

					if(k == 0)
					{
						cout<<setD[i]<<" ";
					}
				}
				cout<<"}\n";
				break;

				case 2:
				for(int i =1 ; i <= m; i++)
				{
					setD[i] = setB[i];
				}
				cout<<"Difference (B - A): {";
				for(int i = 1; i <= m; i++)
				{
					int k = 0;
					for(int j = 1; j <= n; j++)
					{
						if(setD[i] == setA[j])
						{
							k = 1;
							break;
						}
					}

					if(k == 0)
					{
						cout<<setD[i]<<" ";
					}
				}
				cout<<"}\n";
				break;

				case 3:
				cout<<"Terminating..\n";
				break;
			}
		}while(choice != 3);

		cout<<"*******************************\n";
	}

	bool subset()
	{
		cout<<"**********************\n";
		int j; 
		for(int i = 0; i<m; i++)
		{
			for(j = 0; j <n; j++)
			{
				if(setB[i] == setA[j])
				break;
			}

			if(j == n)
			{
				return 0;
			}

		}

		cout<<"********************\n";
		return 1;
	}
};
	

	int main()
	{
		Set s;
		int ch;

		do{
			cout<<"1.Create\n";
			cout<<"2.Display\n";
						cout<<"3.add\n";

			cout<<"4.remove\n";

			cout<<"5.size\n";

			cout<<"6.intersection\n";
			cout<<"7.union\n";

			cout<<"8.difference\n";
						cout<<"9.subset\n";
			cout<<"10.exit\n";

			cout<<"Enter choice: ";
			cin>>ch;

			switch(ch)
			{
				case 1:
				s.create();
				break;

				case 2:
				s.display();
				break;

				case 3:
				s.Add();
				break;

				case 4:
				s.remove();
				break;

				case 5:
				s.size();
				break;

				case 6:
				s.intersection();
				break;

				case 7:
				s.Union();
				break;

				case 8:
				s.difference();
				break;

				case 9:
				if(s.subset())
				{
					cout<<"YES!!! B is not a subset of A\n";
				}
				else
				{
					cout<<"NO!!! B is not a subset of A\n";
				}
				break;

				case 10:
				cout<<"Exit!!\n";
				break;
			}



		}while(ch != 10);
		return 0;
	}

	
