#include <iostream>
using namespace std;


float ReadTotalSales()
{
    float TotalSales;  

    cout << "Please enter Total Sales? " << endl;
    cin >> TotalSales;

    return TotalSales;  
}


float GetCommissionPercentage(float TotalSales)
{
    if (TotalSales >= 1000000)
        return 0.01;  // 1% commission for sales ≥ 1,000,000
    else if (TotalSales >= 500000)
        return 0.02;  // 2% commission for sales between 500,000 and 999,999
    else if (TotalSales >= 100000)
        return 0.03;  // 3% commission for sales between 100,000 and 499,999
    else if (TotalSales >= 50000)
        return 0.05;  // 5% commission for sales between 50,000 and 99,999
    else 
        return 0.00;  // No commission for sales below 50,000
}


float CalculateTotalCommission(float TotalSales)
{
    return GetCommissionPercentage(TotalSales) * TotalSales;  
}


int main()
{
    float TotalSales = ReadTotalSales();

    cout << endl << "Commission Percentage = " << GetCommissionPercentage(TotalSales) * 100 << "%" << endl;

    cout << endl << "Total Commission = " << CalculateTotalCommission(TotalSales) << endl;

    return 0;  
}