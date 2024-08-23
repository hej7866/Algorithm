using System;

public class Solution
{
    public int solution(int chicken)
    {
        int serviceChicken = 0;
        int coupons = chicken;
        
        while (coupons >= 10) 
        {
            int newService = coupons / 10; // 현재 쿠폰으로 받을 수 있는 서비스 치킨 수
            serviceChicken += newService; // 서비스 치킨 수를 더합니다.
            coupons = coupons % 10 + newService; // 남은 쿠폰 수 + 새로 받은 쿠폰 수
        }

        // 총 서비스 치킨 수를 반환합니다.
        return serviceChicken;
    }
}
