#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for gcd

using namespace std;

// 배열의 모든 원소의 GCD를 구하는 함수
int findGCD(const vector<int>& arr) {
    int result = arr[0];
    for (int num : arr) {
        result = gcd(result, num);
        if (result == 1) break; // GCD가 1이면 더 이상 계산할 필요 없음
    }
    return result;
}

// 조건 확인 함수
bool isDivisibleByAny(const vector<int>& arr, int x) {
    for (int num : arr) {
        if (num % x == 0) return true; // x가 arr의 어떤 원소를 나눌 수 있으면 true
    }
    return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = findGCD(arrayA); // arrayA의 GCD
    int gcdB = findGCD(arrayB); // arrayB의 GCD

    int resultA = (isDivisibleByAny(arrayB, gcdA)) ? 0 : gcdA;
    int resultB = (isDivisibleByAny(arrayA, gcdB)) ? 0 : gcdB;

    return max(resultA, resultB); // 조건을 만족하는 GCD 중 최댓값 반환
}