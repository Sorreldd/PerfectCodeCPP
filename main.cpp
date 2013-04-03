#include <iostream>

using namespace std;

const int MAXN = 1000; // Так объявляются константы, изменять данные константы в программе нельзя.
/*
    1) Отступ от левого края 2 или 4 символа.
    2) Пробелы между переменными и арифметическими операциями, пробел после запятой.
    3) Каждому выражению своя строка.
*/
int n;
int a[MAXN], b[MAXN];

void merge_sort(int l, int r) {
    if(l == r) return ;
    merge_sort(l, (l + r) / 2);
    merge_sort((l + r) / 2 + 1, r);
    int i = l;
    int j = (l + r) / 2 + 1;
    int k = l;
    while(k <= r) {
        if(i <= (l + r) / 2 && (j > r || a[i] <= a[j])) {
            b[k] = a[i];
            k++;
            i++;
        } else {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    for(i = l; i <= r; i++) {
        a[i] = b[i];
    }
    return ;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    merge_sort(0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
