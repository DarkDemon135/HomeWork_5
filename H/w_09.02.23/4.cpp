#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
count = 0;
eq = True;
with open("file1.txt", "r", encoding = "utf-8") as f1, open("file2.txt", "r", encoding = "utf-8") as f2:
    for a1, a2 in zip(f1, f2):
        count += 1
        if a1 != a2:
            eq = False
            break
print(f"Нет отличий") if eq else print(f"Отличается строка {count}")