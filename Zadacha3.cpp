//#include <iostream>
//#include <string>
//using namespace std;
//
//bool solution(int nums[], int N, int valueDiff, int indexDiff);
//
//int main() {
//    int indexDiff = 2;
//    int valueDiff = 3;
//    int n;
//    int nums[6] = { 1,5,9,1,5,9 };
//    n = size(nums);
//
//    if (solution(nums, n, valueDiff, indexDiff))
//    {
//        cout << "True" << endl;
//    }
//    else
//    {
//        cout << "False" << endl;
//    }
//
//    return 0;
//}
//
//bool solution(int nums[], int N, int valueDiff, int indexDiff)
//{
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = i + 1; j < N; ++j)
//        {
//            if ((abs(nums[i] - nums[j]) <= valueDiff) && (abs(i-j) <= indexDiff))
//            {
//                return true;
//            }
//        }
//    }
//    return false;
//}



#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MedianFinder
{
public:
	vector<int> arr;
	int a;
	void findMedian()
	{
		int x = (size(arr) / 2);
		if (size(arr) % 2 == 0)
		{ 
			cout << (arr[x-1] + arr[x])*1.0 / 2.0;
		}
		else
		{
			cout << arr[x];
		}
	}
	vector<int> addNum(int a)
	{
		arr.push_back(a);
		return arr;
	}

};

int main()
{
	MedianFinder medianfinder;
	medianfinder.arr = {};
	string deystv;
	int a;
	cout << "You can findMedian and addNum. Or end the programm with end" << endl;
	cin >> deystv;
	while (deystv != "end")
	{
		if (deystv == "addNum")
		{
			cout << "Text num" << endl;
			cin >> a;
			medianfinder.arr = medianfinder.addNum(a);
		}
		else
		{
			medianfinder.findMedian();
		}
		cin >> deystv;
	}
}