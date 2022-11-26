#include <iostream>
using namespace std;

struct Date
{
    int day, month, year;
};

struct Passport
{
    int id;
    struct Date d;
};

// To compare dates
int compare(const struct Date d1, const struct Date d2)
{
    if (d1.year < d2.year)
        return 1;
    if (d1.year == d2.year && d1.month < d2.month)
        return 1;
    if (d1.year == d2.year && d1.month == d2.month &&
        d1.day < d2.day)
        return 1;
    return 0;
}

// To sort passport details based on the passport id using insertion sort
void insertionSort(Passport array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        Passport key = array[i];
        int j = i - 1;
        while (key.id < array[j].id && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// To sort passport details based on the renewal date using selection sort
void selectionSort(Passport array[], int size)
{
    Passport temp;
    for (int i = 0; i < size; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (compare(array[j].d, array[min_idx].d))
                min_idx = j;
        }
        temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

// To print passport details
void printDetails(Passport array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Id: ";
        cout << array[i].id << "\t\t";
        cout << "Date: ";
        cout << array[i].d.day << "." << array[i].d.month << "." << array[i].d.year << endl;
    }
}

int main()
{
    int i, n;
    cout << "Enter number of records:" << endl;
    cin >> n;
    struct Passport p1[n], p2[n];
    cout << "Enter records:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Passportort id: ";
        cin >> p1[i].id;
        cout << "Date of renewal(dd mm yyyy): ";
        cin >> p1[i].d.day >> p1[i].d.month >> p1[i].d.year;
    }
    for (i = 0; i < n; i++)
    {
        p2[i] = p1[i];
    }
    insertionSort(p1, n);
    cout << "--------------------------------------------------" << endl;
    cout << "Records sorted based on Passport id:" << endl;
    cout << "--------------------------------------------------" << endl;
    printDetails(p1, n);
    cout << "\n\n";
    selectionSort(p2, n);
    cout << "--------------------------------------------------" << endl;
    cout << "Records sorted based on date of renewal:" << endl;
    cout << "--------------------------------------------------" << endl;
    printDetails(p2, n);
}