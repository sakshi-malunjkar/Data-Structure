#include <iostream>
using namespace std;

class CircularQueue 
{
private:
    int front, rear, capacity;
    int* orders;

public:
    CircularQueue(int size)               
	{
        capacity = size + 1; 
        front = rear = 0;
        orders = new int[capacity];
    }

    ~CircularQueue()              
	{
        delete[] orders;
        }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int orderNumber) {
        if (isFull()) {
            cout << "Order cannot be placed. Pizza parlor is full!" << endl;
            return;
        }

        orders[rear] = orderNumber;
        rear = (rear + 1) % capacity;
        cout << "Order #" << orderNumber << " placed successfully!" << endl;
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve. Pizza parlor is empty!" << endl;
            return;
        }

        int servedOrder = orders[front];
        front = (front + 1) % capacity;
        cout << "Order #" << servedOrder << " served successfully!" << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> maxOrders;

    CircularQueue pizzaParlor(maxOrders);

    int choice, orderNumber;
    do {
        cout << "\nPizza Parlor Simulation Menu:\n";
        cout << "1. Place an order\n";
        cout << "2. Serve an order\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order number: ";
                cin >> orderNumber;
                pizzaParlor.enqueue(orderNumber);
                break;

            case 2:
                pizzaParlor.serveOrder();
                break;

            case 3:
                cout << "Exiting simulation. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 3);

    return 0;
}
