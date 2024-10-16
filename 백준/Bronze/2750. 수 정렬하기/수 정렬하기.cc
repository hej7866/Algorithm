#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> vec, int n)
{
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        j = i;
        while (vec[j] > vec[j + 1] && j >= 0)
        {
            swap(vec[j], vec[j + 1]);
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << "\n";
    }
}

int main() 
{
    ios::sync_with_stdio(false);  // 입출력 속도 최적화
    cin.tie(NULL);

    
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    insertionSort(v, v.size());

    return 0;
}