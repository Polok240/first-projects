#include <stdio.h>

float calculateBill(int units) {
    if (units <= 100)
        return units * 5.0;
    else if (units <= 200)
        return (100 * 5.0) + (units - 100) * 6.0;
    else
        return (100 * 5.0) + (100 * 6.0) + (units - 200) * 8.0;
}

float calculateVat(float charge) {
    return charge * 0.05;
}

void displayBill(int id, char name[], int units, float charge, float vat, float finalBill) {
    printf("\\n------ Electricity Bill ------\\n");
    printf("Customer ID: %d\\n", id);
    printf("Customer Name: %s\\n", name);
    printf("Units consumed: %d\\n", units);
    printf("Electricity Charge: Tk %.2f\\n", charge);
    printf("VAT (5%%): Tk %.2f\\n", vat);
    printf("Final Bill: Tk %.2f\\n", finalBill);
}

int main() {
    int id, units;
    char name[50];

    printf("Enter customer ID: ");
    scanf("%d", &id);
    printf("Enter customer name: ");
    scanf(" %[^\\n]", name);
    printf("Enter units consumed: ");
    scanf("%d", &units);

    if (units < 0) {
        printf("Invalid Units!\\n");
        return 0;
    }

    float charge = calculateBill(units);
    float vat = calculateVat(charge);
    displayBill(id, name, units, charge, vat, charge + vat);

    return 0;
}
