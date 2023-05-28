#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int profit;
};

bool compareByWeight(Item i1, Item i2) {
    return i1.weight < i2.weight;
}

bool compareByProfit(Item i1, Item i2) {
    return i1.profit > i2.profit;
}

bool compareByPbyW(Item i1, Item i2) {
    double pbyw1 = (double)i1.profit / i1.weight;
    double pbyw2 = (double)i2.profit / i2.weight;
    return pbyw1 > pbyw2;
}

double fractionalKnapsack(int capacity, std::vector<Item>& items, bool (*compare)(Item, Item)) {
    std::sort(items.begin(), items.end(), compare);

    double total_profit = 0.0;
    for (const auto& item : items) {
        if (capacity <= 0)
            break;

        if (item.weight <= capacity) {
            total_profit += item.profit;
            capacity -= item.weight;
        } else {
            total_profit += capacity * ((double)item.profit / item.weight);
            break;
        }
    }

    return total_profit;
}

int main() {
    int capacity;
    std::cout << "Enter the knapsack capacity: ";
    std::cin >> capacity;

    int num_items;
    std::cout << "Enter the number of items: ";
    std::cin >> num_items;

    std::vector<Item> items(num_items);
    for (int i = 0; i < num_items; ++i) {
        std::cout << "Enter weight and profit for item " << (i + 1) << ": ";
        std::cin >> items[i].weight >> items[i].profit;
    }

    double max_profit;

    std::cout << "\n1. Sort by weight\n";
    max_profit = fractionalKnapsack(capacity, items, compareByWeight);
    std::cout << "The maximum profit obtained is: " << max_profit << std::endl;

    std::cout << "\n2. Sort by profit\n";
    max_profit = fractionalKnapsack(capacity, items, compareByProfit);
    std::cout << "The maximum profit obtained is: " << max_profit << std::endl;

    std::cout << "\n3. Sort by profit-to-weight ratio (P/W)\n";
    max_profit = fractionalKnapsack(capacity, items, compareByPbyW);
    std::cout << "The maximum profit obtained is: " << max_profit << std::endl;

    return 0;
}