#ifndef MORTGAGE_H
#define MORTGAGE_H

#include <cmath> //For pow

class mortgage 
{
private:
    double loanAmount;
    double annualRate;
    int years;

public:
    //Default Constructor
    mortgage() 
	{
        loanAmount = 0.0;
        annualRate = 0.0;
        years = 0;
    }

    //Setters
    void setLoanAmount(double loan)
		{ loanAmount = loan; }
    void setAnnualRate(double rate)
		{ annualRate = rate; }
    void setYears(int yrs)
		{ years = yrs; }

    //Getters
    double getLoanAmount() const
		{ return loanAmount; }
    double getAnnualRate() const
		{ return annualRate; }
    int getYears() const
		{ return years; }

    //Calculating monthly payment
    double getMonthlyPayment() const 
	{
        if (loanAmount <= 0.0 || years <= 0) 
		{
            return 0.0;
        }
        
        double monthlyRate = annualRate / 12.0;
        int totalMonths = years * 12;

        double term = std::pow(1.0 + monthlyRate, totalMonths);
        double payment = (loanAmount * monthlyRate * term) / (term - 1.0);

        return payment;
    }

    //Calculating total pay
    double getTotalPaid() const 
	{
        return getMonthlyPayment() * (years * 12);
    }
};

#endif