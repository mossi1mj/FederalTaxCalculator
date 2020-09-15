#include <iostream>
#include <string>

using namespace std;

//function prototypes
void programHeader();
void getData(char &maritalStatus, int &people, double &grossSalary, double &pension);
double taxAmount(char maritalStatus, int people, double grossSalary, double pension);
double federalTaxCalculations(double taxableIncome);


//main function
int main() {

    //declare variables
    char maritalStatus;
    int people;
    double grossSalary, pension, federalTax, taxableIncome;

    // call functions and variables
    programHeader(); // title of program and directions to user
    getData(maritalStatus, people, grossSalary, pension); // passes reference values.
    taxAmount(maritalStatus, people, grossSalary, pension); // calculates taxable income
    taxableIncome = taxAmount(maritalStatus, people, grossSalary, pension); // store in variable to show in details
    federalTax = federalTaxCalculations(taxableIncome); // store in variable to show in details

    // print details
    cout << "Marital Status: " << maritalStatus << endl;
    cout << "Family Size: " << people << endl;
    cout << "Total Income: " << grossSalary << endl;
    cout << "Pension Plan Contribution: " << pension << endl;
    cout << "Taxable Income: " << taxableIncome << endl;
    cout << "Federal Tax Payable: " << federalTax << endl;

    return 0;
}

void programHeader(){
    cout << "FEDERAL TAX CALCULATOR\n"
            "Enter the following information.\n" << endl;
}

void getData(char &maritalStatus, int &people, double &grossSalary, double &pension){
    // All character user input will use the tolower() function for easier validation methods.

    //initialize variables
    char input;
    int children;

    cout << "What is the Marital Status?\n"
            "[M]arried or [S]ingle: ";
    cin >> maritalStatus;

    //verify valid user input for marital status
    while (tolower(maritalStatus) != 'm' && tolower(maritalStatus) != 's'){
        cout << "Invalid Input!\n"
                "Enter either [M] for Married or [S] for Single: ";
        cin >> maritalStatus;
    }

    // structure if user inputs married status
    if (tolower(maritalStatus) == 'm'){
        cout << "Enter number of Children under age 14: ";
        cin >> children;

        people = 2 + children; // formula for household size

        cout << "\nDo both spouses earn income?\n"
                "Enter [Y]es or [N]o: ";
        cin >> input;

        //validate user input
        while (tolower(input) != 'y' && tolower(input) != 'n'){
            cout << "Invalid Input!\n"
                    "Enter either [Y] for yes or [N] for no: ";
            cin >> input;
        }

        if (tolower(input) == 'y'){
            cout << "Enter combined salary: ";
            cin >> grossSalary;
        }

        else{
            cout << "Enter salary: ";
            cin >> grossSalary;
        }
    }

    else{
        cout << "Enter salary: ";
        cin >> grossSalary;

        people = 1; // household size for single status
    }

    cout << "Enter pension plan contribution (6% limit!): ";
    cin >> pension;

    // validate pension plan is not more that 6
    while (pension > 6.00){
        cout << "Invalid Input! Pension plan can not exceed 6%!\n"
                "Enter pension plan contribution: ";
        cin >> pension;
    }

    pension = pension / 100 * grossSalary; // formula for pension contribution

}

double taxAmount(char maritalStatus, int people, double grossSalary, double pension){

    double standardExemption;
    double taxableIncome;

    // if else statement for exemptions based on marital status
    if (tolower(maritalStatus == 'm'))
        standardExemption = 7000;
    else
        standardExemption = 4000;

    taxableIncome = grossSalary - ((1500.00 * people) + pension + standardExemption); // formula for taxable income

    return taxableIncome;
}

double federalTaxCalculations(double taxableIncome){

    // tax formulas/calculations based on taxable income
    if (taxableIncome >= 0 && taxableIncome <= 15000)
        return taxableIncome * 0.15;

    else if (taxableIncome >= 15001 && taxableIncome <= 40000)
        return taxableIncome * 0.25 + 2250.00;

    else
        return taxableIncome * 0.35 + 8460.00;
}

