#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;


/* 문제 
정수를 저장하는 덱을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100,000)
2 X: 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100,000)
3: 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
5: 덱에 들어있는 정수의 개수를 출력한다.
6: 덱이 비어있으면 1, 아니면 0을 출력한다.
7: 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
8: 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.

/* 입력
첫째 줄에 명령의 수 N이 주어진다. (1 ≤ N ≤ 1,000,000)
둘째 줄부터 N개 줄에 명령이 하나씩 주어진다.
출력을 요구하는 명령은 하나 이상 주어진다.

/* 출력
출력을 요구하는 명령이 주어질 때마다 명령의 결과를 한 줄에 하나씩 출력한다.


/* 제한
*/

template <typename T>
class MyDeque 
{
private:
    vector<T*> blocks;
    int blockSize;
    int frontIndex;
    int backIndex;
    int iCount;

    void allocateBlock() 
    {
        blocks.push_back(new T[blockSize]());
        frontIndex = blockSize / 2;  // 중앙에서 시작
        backIndex = frontIndex + 1;  // back은 front 다음에서 시작
    }

    void addFrontBlock() 
    {
        blocks.insert(blocks.begin(), new T[blockSize]());
        frontIndex = blockSize - 1;
    }

    void addBackBlock() 
    {
        blocks.push_back(new T[blockSize]());
        backIndex = 0;
    }

public:
    MyDeque(int blockSize) : blockSize(blockSize), frontIndex(0), backIndex(0), iCount(0) 
    {
        allocateBlock();
    }

    ~MyDeque() {
        for (T* block : blocks) 
        {
            delete[] block;
        }
    }

    int getSize() const { return iCount; }
    bool isEmpty() const { return iCount == 0; }

    T& getFront() const 
    {
        if (isEmpty()) 
        {
            throw out_of_range("덱이 비었음");
        }
        return blocks[0][frontIndex + 1];
    }

    T& getBack() const 
    {
        if (isEmpty()) 
        {
            throw out_of_range("덱이 비었음");
        }
        return blocks.back()[backIndex - 1];
    }

    void pushFront(const T& data) 
    {
        if (frontIndex < 0) 
        {
            addFrontBlock();
        }
        blocks[0][frontIndex--] = data;
        ++iCount;
    }

    void pushBack(const T& data) 
    {
        if (backIndex == blockSize) 
        {
            addBackBlock();
        }
        blocks.back()[backIndex++] = data;
        ++iCount;
    }

    void popFront() 
    {
        if (isEmpty()) 
        {
            return;
        }
        ++frontIndex;
        --iCount;

        if (frontIndex == blockSize) 
        {
            delete[] blocks.front();
            blocks.erase(blocks.begin());
            frontIndex = 0;
        }
    }

    void popBack() 
    {
        if (isEmpty()) 
        {
            return;
        }
        --backIndex;
        --iCount;

        if (backIndex < 0) 
        {
            delete[] blocks.back();
            blocks.pop_back();
            backIndex = blockSize - 1;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);  // 입출력 속도 최적화
    cin.tie(NULL);

    int N;
    cin >> N;

    MyDeque<int> dq(1000001);  

    int c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        int X;
        switch (c) {
        case 1:
            cin >> X;
            dq.pushFront(X);
            break;
        case 2:
            cin >> X;
            dq.pushBack(X);
            break;
        case 3:
            if (!dq.isEmpty()) 
            {
                cout << dq.getFront() << "\n";
                dq.popFront();
            } 
            else 
            {
                cout << -1 << "\n";
            }
            break;
        case 4:
            if (!dq.isEmpty()) 
            {
                cout << dq.getBack() << "\n";
                dq.popBack();
            } 
            else 
            {
                cout << -1 << "\n";
            }
            break;
        case 5:
            cout << dq.getSize() << "\n";
            break;
        case 6:
            cout << (dq.isEmpty() ? 1 : 0) << "\n";
            break;
        case 7:
            cout << (dq.isEmpty() ? -1 : dq.getFront()) << "\n";
            break;
        case 8:
            cout << (dq.isEmpty() ? -1 : dq.getBack()) << "\n";
            break;
        }
    }

    return 0;
}