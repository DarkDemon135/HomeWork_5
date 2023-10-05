#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& item1, const Item& item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;

    return ratio1 > ratio2;
}

std::vector<int> greedyAlgorithm(int capacity, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compareItems);
    
    std::vector<int> selectedItems(items.size(), 0);

    int currentWeight = 0;
  
   for (int i = 0; i < items.size(); ++i) {
        if (currentWeight + items[i].weight <= capacity) {
            selectedItems[i] = 1;
            currentWeight += items[i].weight;
        }
        else {
            break;
        }
 }
 
 return selectedItems;
}

int main() {

 int capacity; // Вместимость рюкзака
 std::cout << "Введите вместимость рюкзака: ";
 std::cin >> capacity;

 int numItems; // Количество предметов
   std::cout << "Введите количество предметов: ";
   std::cin >> numItems;


   // Ввод информации о каждом предмете: вес и стоимость
   std::vector<Item> items(numItems);
   
 for (int i = 0; i < numItems; ++i){
     Item newItem;
     
     std::cout << "Введите вес для предмета " << i+1 << ": ";
     std::cin >> newItem.weight;

     std::cout << "Введите стоимость для предмета " << i+1 << ": ";
     std::cin >> newItem.value;
     
  items[i] = newItem;
   }

   std::vector<int> selectedItems = greedyAlgorithm(capacity, items);

   // Вывод выбранных предметов
    std::cout << "\nВыбранные предметы (1 - выбран, 0 - не выбран):" << std::endl;
  
 for (int i = 0; i < items.size(); ++i) {
        std::cout <<"Предмет "<<i+1<<": "<<selectedItems[i]<<std::endl;
    }
   
 return 0;
}