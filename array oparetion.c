#include <stdio.h>

int main() {
    int a[50], n = 0, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Update (Insert at position)\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Sort\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("How many numbers to insert? ");
            scanf("%d", &n);
            printf("Enter %d numbers:\n", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
        }
        else if (choice == 2) {
            int pos, value;
            printf("Enter position to insert (0 to %d): ", n);
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            if (pos >= 0 && pos <= n) {
                for (int i = n; i > pos; i--) {
                    a[i] = a[i - 1];
                }
                a[pos] = value;
                n++;
                printf("Value inserted.\n");
            } else {
                printf("Invalid position.\n");
            }
        }
        else if (choice == 3) {
            int pos;
            printf("Enter position to delete (0 to %d): ", n - 1);
            scanf("%d", &pos);
            if (pos >= 0 && pos < n) {
                for (int i = pos; i < n - 1; i++) {
                    a[i] = a[i + 1];
                }
                n--;
                printf("Value deleted.\n");
            } else {
                printf("Invalid position.\n");
            }
        }
        else if (choice == 4) {
            printf("Array elements:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
        else if (choice == 5) {
            int temp, order;
            printf("1. Ascending\n2. Descending\nChoose order: ");
            scanf("%d", &order);
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ((order == 1 && a[i] > a[j]) || (order == 2 && a[i] < a[j])) {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
            }
            printf("Array sorted.\n");
        }
        else if (choice == 6) {
            int key, found = 0;
            printf("Enter number to search: ");
            scanf("%d", &key);
            for (int i = 0; i < n; i++) {
                if (a[i] == key) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                printf("Number found.\n");
            } else {
                printf("Number not found.\n");
            }
        }
        else if (choice == 7) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
