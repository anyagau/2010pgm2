// Program: To give you a reciept for a custom Cedar Point trip
// Process: By assigning the admission and meal variable to the selected plans and the number of each plan, the code will determine the cost
// of the each section from the admission and meal plan, adding the parts together for the admissions total and meal plan total, respectively.
// The machine will then calculate the parking cost based off of the admissions plan, followed by calculating the admissions discount based
// off of how much money was spent on the admissions total. From there, it will add all of the above together, subtract the discount, 
// calculating the subtotal. It will then calculate the tax off of that, and finally add the tax and subtotal for the total.
// Results: The result will be a receipt showing you your number of admissions, the meal plans, and the types of each. It will also show the
// total cost for each, as well as the parking cost, admission discount, subtotal after the discount, taxes and the total cost. Each section
// is even and separated. 
//
// Class: CS2010, 8:30 MWF
// Section: 100x
// Term: Spring 2024
// Author: Anya Gau
//
// Reflection: This project was fairly straightforward, although there were a couple kinks that needed to be worked out. I first created an "if
// else" statement to be able to make a viable input for the admission and meal plans. Each plan was assigned the cost. The strange part was
// getting the code to abort, as it wasn't something I'd done before. Most of the mistakes I made were trivial errors, and it's something
// I should try to improve to make the process easier. 

#include<iostream>
#include<iomanip>
using namespace std;
int main () {

    string admissionType;               // all of my (possibly gratuitous) variables!!
    string mealPlan;
    int numAdmission;
    int numMeal;
    double admissionCost;
    double mealCost;
    double admission;
    double meal;

    const double PLATINUMPRICE = 230;
    const double GOLDPRICE = 135;
    const double TWODAYPRICE = 70;
    const double DAYPRICE = 45;
    const double ALLDAYPRICE = 31.55;
    const double SINGLEPRICE = 14.95;
    const double ENTREEPRICE = 8.25;
    const double NONEPRICE = 0;
    const double PARKING = 20;
    const double TAXRATE = .07;
    const double DISCOUNT_ONE = .85;
    const double DISCOUNT_TWO = .90;
    const double DISCOUNT_THREE = .95;
    double subTotal;
    double totalPrice;
    double parkingCost;
    double admissionDiscount;
    double admissionPrice;
    double mealPrice;
    double taxesPrice;
    double finalTotal;


    cout << "Enter your admission choice: (platinum, gold, twoday, or day) ";       // this is to determine which admission choice was 
    cin >> admissionType;                                                           // selected, and associated the cost with each one
    if (admissionType == "platinum") {
        cout << endl << "How many " << admissionType << "? ";
        admission = PLATINUMPRICE;
    }
    else if (admissionType == "gold") {
        cout << endl << "How many " << admissionType << "? ";
        admission = GOLDPRICE;
    }
    else if (admissionType == "twoday") {
        cout << endl << "How many " << admissionType << "? ";
        admission = TWODAYPRICE;
    }
    else if (admissionType == "day") {
        cout << endl << "How many " << admissionType << "? ";
        admission = DAYPRICE;
    }
    else {
        cout << "Invalid Admission Entry." << endl;
    abort();
    }
    
    cin >> numAdmission;                                                                    // This section is basically the same as the one 
    cout << endl << "Enter your meal choice: (allday, single, entree, or none) ";           // above, but with the meal plan instead
    cin >> mealPlan;

    if (mealPlan == "allday") {
        cout << endl << "How many " << mealPlan << "? ";
        meal = ALLDAYPRICE;
        cin >> numMeal;
    }
    else if (mealPlan == "single") {
        cout << endl << "How many " << mealPlan << "? ";
        meal = SINGLEPRICE;
        cin >> numMeal;
    }
    else if (mealPlan == "entree") {
        cout << endl << "How many " << mealPlan << "? "; 
        meal = ENTREEPRICE;
        cin >> numMeal;
    }
    else if (mealPlan == "none") {
        meal = NONEPRICE;
    }
    else {
        cout << "Invalid Meal Entry." << endl;
    abort();
    }

    cout << endl;                                                   // setting up the first part of the receiept, the admissions/meal plan
    cout << setfill('-') << setw(35) << "" << endl;                 // section
    cout << "Cedar Point:" << endl;
    cout << setfill('-') << setw(35) << "" << endl;
    cout << "Admission" << setw(12) << setfill(' ') << right << ":" << numAdmission << " " << admissionType << endl;
    cout << "Meal" << setw(17) << setfill(' ') << right << ":" << numMeal << " " << mealPlan << endl;
    cout << setfill('-') << setw(35) << "" << endl;

    admissionCost = (admission * numAdmission); 
    mealCost = (meal * numMeal);

    if (admission == PLATINUMPRICE) {                       // This set the parking price for the different plans, gold and platinum not
        parkingCost = 0;                                    // paying for parking, twoday and day pass do
    }
    else if (admission == GOLDPRICE) {
        parkingCost = 0;
    }
    else if (admission == TWODAYPRICE) {
        parkingCost = PARKING;
    }
    else if (admission == DAYPRICE) {
        parkingCost = PARKING;
    }
    else {
    }

    if (admissionCost >= 1000) {                                    //This section determines the discount receieved (if any) based on the 
        subTotal = admissionCost * DISCOUNT_ONE;                    // admissions total cost
        admissionDiscount = admissionCost - subTotal;
    }
    else if ((admissionCost < 1000) && (admissionCost >= 500)) {
        subTotal = admissionCost * DISCOUNT_TWO;
        admissionDiscount = admissionCost - subTotal;
    }
    else if ((admissionCost < 500) && (admissionCost >= 100)) {
        subTotal = admissionCost * DISCOUNT_THREE;
        admissionDiscount = admissionCost - subTotal;
    }
    else {
        admissionDiscount = 0.00;
    }

    subTotal = subTotal + mealCost + parkingCost;                   // calculating subtotal

    cout << setfill(' ');
    cout << fixed << setprecision(2);                               // Finishing off the receipt
    cout << setw(19) << left << "Admission Cost" << "$";
    cout << setw(10) << right << admissionCost << endl;
    cout << setw(19) << left << "Meal Cost" << "$";
    cout << setw(10) << right << mealCost << endl;
    cout << setw(19) << left << "Parking" << "$";
    cout << setw(10) << right << parkingCost << endl;
    cout << setw(19) << left << "Admission Discount" << "$";
    cout << setw(10) << right << admissionDiscount << endl;
    cout << setw(19) << left << "Subtotal" << "$";
    cout << setw(10) << right << subTotal << endl;
    
    cout << setfill('-') << setw(35) << "" << endl;
    cout << setfill('-') << setw(35) << "" << endl;

    taxesPrice = subTotal * TAXRATE;
    cout << setfill(' ');                                           // establishing taxes, and creating the tax section of the
    cout << setw(19) << left << "Taxes" << "$";                     // receipt
    cout << setw(10) << right << taxesPrice << endl;

    cout << setfill('-') << setw(35) << "" << endl;

    finalTotal = subTotal + taxesPrice;                             // calculating final price and last part of receipt 
    cout << setfill(' ');
    cout << setw(19) << left << "Final Total" << "$";
    cout << setw(10) << right << finalTotal << endl;


return 0;
};