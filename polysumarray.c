#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

int main() {
    struct Term poly1[10], poly2[10], result[20];
    int n1, n2, n3 = 0;
    int i, j;


    printf("Enter the first polynomial:\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &poly1[i].coeff, &poly1[i].exp);
    }


    printf("\nEnter the second polynomial:\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &poly2[i].coeff, &poly2[i].exp);
    }


    i = 0; 
    j = 0;
    while (i < n1 && j < n2) {
        if (poly1[i].exp == poly2[j].exp) {
            result[n3].coeff = poly1[i].coeff + poly2[j].coeff;
            result[n3].exp = poly1[i].exp;
            i++;
            j++;
        } else if (poly1[i].exp > poly2[j].exp) {
            result[n3].coeff = poly1[i].coeff;
            result[n3].exp = poly1[i].exp;
            i++;
        } else {
            result[n3].coeff = poly2[j].coeff;
            result[n3].exp = poly2[j].exp;
            j++;
        }
        n3++;
    }

 
    while (i < n1) {
        result[n3].coeff = poly1[i].coeff;
        result[n3].exp = poly1[i].exp;
        i++;
        n3++;
    }

    while (j < n2) {
        result[n3].coeff = poly2[j].coeff;
        result[n3].exp = poly2[j].exp;
        j++;
        n3++;
    }


    printf("\nPolynomial 1: ");
    for (i = 0; i < n1; i++) {
        printf("%d x^%d", poly1[i].coeff, poly1[i].exp);
        if (i != n1 - 1) printf(" + ");
    }

    printf("\nPolynomial 2: ");
    for (i = 0; i < n2; i++) {
        printf("%d x^%d", poly2[i].coeff, poly2[i].exp);
        if (i != n2 - 1) printf(" + ");
    }

    printf("\n\nResultant Polynomial: ");
    for (i = 0; i < n3; i++) {
        printf("%d x^%d", result[i].coeff, result[i].exp);
        if (i != n3 - 1) printf(" + ");
    }

    printf("\n");
    return 0;
}
