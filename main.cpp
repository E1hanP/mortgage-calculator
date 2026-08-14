#include <iostream>
#include <iomanip>
#include "mortgage.h"

using namespace std;

int main() 
{
    mortgage userMortgage;
    double inputLoan;
    double inputRate;
    int inputYears;

    cout<<"Enter the loan amount:"<<endl;
    cin>>inputLoan;
    while (inputLoan < 0) 
	{
        cout<<"Loan amount cannot be negative, please retry."<<endl;
        cin>>inputLoan;
    }
    userMortgage.setLoanAmount(inputLoan);

    cout<<"Enter the annual interest rate (For example, 5% = 0.05)"<<endl;
    cin>>inputRate;
    while (inputRate < 0) 
	{
        cout<<"Interest rate cannot be negative, please retry."<<endl;
        cin>>inputRate;
    }
    userMortgage.setAnnualRate(inputRate);

    cout<<"Enter the number of years: "<<endl;
    cin>>inputYears;
    while (inputYears < 0) 
	{
        cout<<"Years cannot be negative, please retry."<<endl;
        cin>>inputYears;
    }
    userMortgage.setYears(inputYears);

    //Show only 2 decimal places.
    cout<<fixed<<setprecision(2);

    //Displaying Results
    cout<<"--- Mortgage Results ---"<<endl;
    cout<<"Monthly Payment:   $"<<userMortgage.getMonthlyPayment()<<endl;
    cout<<"Total Amount Paid: $"<<userMortgage.getTotalPaid()<<endl;

    return 0;
}
