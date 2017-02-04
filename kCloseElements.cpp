//finding k closet elements ina an array for a given value
#include <iostream>
#include <vector>
using namespace std;
int binary_close_search(vector<int> ve, int start, int end, int value)
{
	if(ve[end]<= value)
		return end;
	if(ve[start] > value)
		return start;
	int mid = (start + end)/ 2;
	if(ve[mid]<=value && ve[mid+1]>value)
		return mid;
	if(ve[mid]<value)
		return binary_close_search(ve, mid+1, end, value);
	else return binary_close_search(ve, start, mid-1, value);
}
void print_k_elements(vector<int> ve, int value, int k)
{
	//first check for the element range in the vector using binary array
	int l = binary_close_search(ve,0, ve.size()-1, value);
	int r = l+1;
	if(ve[l]==value) 
		l--;//ignore this element
	int count =0;
	// use the logic of merging two merge lsits in mergesort 
	while(l>=0 && r<ve.size() && count<k)
	{
		if(value-ve[l] < ve[r] - value)
			cout<<ve[l--]<<" ";
		else
			cout<<ve[r++]<<" ";
		count++;
	}
	while(count<k && l>=0)
	{
		cout<<ve[l--]<<" ";
		count++;
	}
	while(count<k && r<ve.size())
	{
		cout<<ve[r++]<<" ";
		count++;
	}

}
int main()
{
	int n=0, k=0, value=0;
	cout<<"Enter the value of N: ";
	cin>>n;
	vector<int> ve(n);
	for(int i=0;i<n;i++)
	{
		cout<<(i+1)<<" element: ";
		cin>>ve[i];
	}
	//sort the elements
	sort(ve.begin(), ve.end());
	cout<<"Enter the value for K: ";
	cin>>k;
	cout<<"Enter the number for "<<k<<" clsosest elements: ";
	cin>>value;
	cout<<k<<" closest elemnts to "<<value<<" are: ";
	if(k>=ve.size())
		print_k_elements(ve, value,k);
	else cout<<"Not possible!";
	cout<<endl;
	return 0;
}