#include <stdio.h>

int main() {
    int i, j, k = 1, m, n;
    int a[10][10], b[10][3];

    printf("Enter the number of rows and columns\n");
    scanf("%d%d", &m, &n);

    printf("Enter the Elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

   
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;        
                b[k][1] = j;        
                b[k][2] = a[i][j];  
                k++;
            }
        }
    }

    
    b[0][0] = m;        
    b[0][1] = n;         
    b[0][2] = k - 1;     

   
    printf("Sparse matrix representation Of First Matrix:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i < k; i++)
    {
    for(j=0;j<3;j++)
     {
        printf("%d\t", b[i][j]);
        
    }
    printf("\n");
    }
     int x[10][10], c[10][3], p = 1, r, s;
    printf("Enter the number of rows and columns for second matrix\n");
    scanf("%d%d", &r, &s);

    printf("Enter the Elements of second matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < s; j++) {
            scanf("%d", &x[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < s; j++) {
            if (x[i][j] != 0) {
                c[p][0] = i;
                c[p][1] = j;
                c[p][2] = x[i][j];
                p++;
            }
        }
    }

    c[0][0] = r;
    c[0][1] = s;
    c[0][2] = p - 1;

    printf("Resulting Sparse Matrix for second matrix:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
      if (b[0][0] != c[0][0] || b[0][1] != c[0][1]) {
        printf("Matrix dimensions do not match, cannot add.\n");
        return 0;
    }

    int d[20][3];
    i = 1; j = 1; k = 1;
    d[0][0] = b[0][0];
    d[0][1] = b[0][1];

    while (i <= b[0][2] && j <= c[0][2]) {
        if (b[i][0] < c[j][0] || (b[i][0] == c[j][0] && b[i][1] < c[j][1])) {
            d[k][0] = b[i][0];
            d[k][1] = b[i][1];
            d[k][2] = b[i][2];
            i++; k++;
        } else if (b[i][0] > c[j][0] || (b[i][0] == c[j][0] && b[i][1] > c[j][1])) {
            d[k][0] = c[j][0];
            d[k][1] = c[j][1];
            d[k][2] = c[j][2];
            j++; k++;
        } else {
            int sum = b[i][2] + c[j][2];
            if (sum != 0) {
                d[k][0] = b[i][0];
                d[k][1] = b[i][1];
                d[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= b[0][2]) {
        d[k][0] = b[i][0];
        d[k][1] = b[i][1];
        d[k][2] = b[i][2];
        i++; k++;
    }

    while (j <= c[0][2]) {
        d[k][0] = c[j][0];
        d[k][1] = c[j][1];
        d[k][2] = c[j][2];
        j++; k++;
    }

    d[0][2] = k - 1;

    printf("Resulting Sparse Matrix after addition:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }

    printf("Resulting Transpose Sparse Matrix after addition:\n");

    for (j = 0; j < 3; j++) {
        for (i = 0; i < k; i++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
