/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MonthlyBudget{
    float housing;
    float utilities;
    float house;
    float transp;
    float food;
    float medical;
    float insurance;
    float enter;
    float clothing;
    float misc;
};

void getData(MonthlyBudget &toFill){
    /*
    Enter·housing·cost·for·the·month:$↵
    Enter·utilities·cost·for·the·month:$↵
    Enter·household·expenses·cost·for·the·month:$↵
    Enter·transportation·cost·for·the·month:$↵
    Enter·food·cost·for·the·month:$↵
    Enter·medical·cost·for·the·month:$↵
    Enter·insurance·cost·for·the·month:$↵
    Enter·entertainment·cost·for·the·month:$↵
    Enter·clothing·cost·for·the·month:$↵
    Enter·miscellaneous·cost·for·the·month:$↵
    */
    
    cout << "Enter housing cost for the month:$" << endl;
    cin >> toFill.housing;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> toFill.utilities;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> toFill.house;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> toFill.transp;
    cout << "Enter food cost for the month:$" << endl;
    cin >> toFill.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> toFill.medical;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> toFill.insurance;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> toFill.enter;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> toFill.clothing;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> toFill.misc;
}

void cmpBudget(MonthlyBudget &budget){
    if(budget.housing < 500) {cout << "Housing Under" << endl;}
    if(budget.housing == 500){cout << "Housing Even" << endl; }
    if(budget.housing > 500) {cout << "Housing Over" << endl; }
    
    if(budget.utilities < 150) {cout << "Utilities Under" << endl;}
    if(budget.utilities == 150){cout << "Utilities Even" << endl; }
    if(budget.utilities > 150) {cout << "Utilities Over" << endl; }
    
    if(budget.house < 65) {cout << "Household Expenses Under" << endl;}
    if(budget.house == 65){cout << "Household Expenses Even" << endl; }
    if(budget.house > 65) {cout << "Household Expenses Over" << endl; }
    
    if(budget.transp < 50) {cout << "Transportation Under" << endl;}
    if(budget.transp == 50){cout << "Transportation Even" << endl; }
    if(budget.transp > 50) {cout << "Transportation Over" << endl; }
    
    if(budget.food < 250) {cout << "Food Under" << endl;}
    if(budget.food == 250){cout << "Food Even" << endl; }
    if(budget.food > 250) {cout << "Food Over" << endl; }
    
    if(budget.medical < 30) {cout << "Medical Under" << endl;}
    if(budget.medical == 30){cout << "Medical Even" << endl; }
    if(budget.medical > 30) {cout << "Medical Over" << endl; }
    
    if(budget.insurance < 100) {cout << "Insurance Under" << endl;}
    if(budget.insurance == 100){cout << "Insurance Even" << endl; }
    if(budget.insurance > 100) {cout << "Insurance Over" << endl; }
    
    if(budget.enter < 150) {cout << "Entertainment Under" << endl;}
    if(budget.enter == 150){cout << "Entertainment Even" << endl; }
    if(budget.enter > 150) {cout << "Entertainment Over" << endl; }
    
    if(budget.clothing < 75) {cout << "Clothing Under" << endl;}
    if(budget.clothing == 75){cout << "Clothing Even" << endl; }
    if(budget.clothing > 75) {cout << "Clothing Over" << endl; }
    
    if(budget.misc < 50) {cout << "Miscellaneous Under" << endl;}
    if(budget.misc == 50){cout << "Miscellaneous Even" << endl; }
    if(budget.misc > 50) {cout << "Miscellaneous Over" << endl; }
    
    /*
    float housing;
    float utilities;
    float house;
    float transp;
    float food;
    float medical;
    float insurance;
    float enter;
    float clothing;
    float misc;
    */
    float sum = budget.housing + budget.utilities + 
    budget.house + budget.transp + budget.food + budget.medical + 
    budget.insurance + budget.enter + budget.clothing + budget.misc;
    
    if(sum < 1420){cout << "You were $"<<fixed<<setprecision(2)<< abs(sum - 1420)<<" under budget";}
    if(sum > 1420){cout << "You were $"<<fixed<<setprecision(2)<< abs(sum - 1420)<<" over budget";}
}

int main(int argc, char** argv) {

    MonthlyBudget realBud;
    
    getData(realBud);
    cmpBudget(realBud);
    return 0;
}