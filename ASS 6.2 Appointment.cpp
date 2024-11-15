#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

// Structure to represent a time slot for an appointment
struct Appointment {
    string startTime;
    string endTime;
    string appointmentDetails;
    Appointment* next;
};

class AppointmentManager {
private:
    Appointment* head;

public:
    AppointmentManager() : head(nullptr) {}

    // Function to display free slots
    void displayFreeSlots() {
        Appointment* current = head;
        while (current != nullptr) {
            cout << "Free Slot: " << current->startTime << " - " << current->endTime << endl;
            current = current->next;
        }
    }

    // Function to book an appointment
    void bookAppointment() {
        string startTime, endTime, details;

        cout << "Enter start time (HH:mm): ";
        cin >> startTime;
        cout << "Enter end time (HH:mm): ";
        cin >> endTime;
        cout << "Enter appointment details: ";
        cin.ignore();
        getline(cin, details);

        if (isSlotAvailable(startTime, endTime)) {
            addAppointment(startTime, endTime, details);
            cout << "Appointment booked successfully!\n";
        } else {
            cout << "Appointment slot not available. Please choose another time.\n";
        }
    }

    // Function to cancel an appointment
    void cancelAppointment() {
        string startTime, endTime;

        cout << "Enter start time of the appointment to cancel (HH:mm): ";
        cin >> startTime;
        cout << "Enter end time of the appointment to cancel (HH:mm): ";
        cin >> endTime;

        if (removeAppointment(startTime, endTime)) {
            cout << "Appointment canceled successfully!\n";
        } else {
            cout << "Appointment not found. Please check the time.\n";
        }
    }

    // Function to sort the list based on time
    void sortListByTime() {
        if (head == nullptr) {
            cout << "No appointments to sort.\n";
            return;
        }

        Appointment* sortedList = nullptr;
        Appointment* current = head;

        while (current != nullptr) {
            Appointment* next = current->next;
            insertSorted(sortedList, current);
            current = next;
        }

        head = sortedList;

        cout << "List sorted by time!\n";
    }

    // Function to sort the list based on time using pointer manipulation
    void sortListByTimePointer() {
        if (head == nullptr) {
            cout << "No appointments to sort.\n";
            return;
        }

        head = mergeSort(head);

        cout << "List sorted by time using pointer manipulation!\n";
    }

private:
    // Function to check if a slot is available
    bool isSlotAvailable(const string& startTime, const string& endTime) {
        Appointment* current = head;

        while (current != nullptr) {
            if ((startTime >= current->startTime && startTime < current->endTime) ||
                (endTime > current->startTime && endTime <= current->endTime) ||
                (startTime <= current->startTime && endTime >= current->endTime)) {
                return false; // Slot is not available
            }
            current = current->next;
        }

        return true; // Slot is available
    }

    // Function to add an appointment
    void addAppointment(const string& startTime, const string& endTime, const string& details) {
        Appointment* newAppointment = new Appointment{startTime, endTime, details, nullptr};

        if (head == nullptr || endTime < head->startTime) {
            newAppointment->next = head;
            head = newAppointment;
            return;
        }

        Appointment* current = head;

        while (current->next != nullptr && current->next->startTime < endTime) {
            current = current->next;
        }

        newAppointment->next = current->next;
        current->next = newAppointment;
    }

    // Function to remove an appointment
    bool removeAppointment(const string& startTime, const string& endTime) {
        if (head == nullptr) {
            return false;
        }

        if (head->startTime == startTime && head->endTime == endTime) {
            Appointment* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Appointment* current = head;

        while (current->next != nullptr) {
            if (current->next->startTime == startTime && current->next->endTime == endTime) {
                Appointment* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return true;
            }
            current = current->next;
        }

        return false; // Appointment not found
    }

    // Function to insert an appointment into a sorted list
    void insertSorted(Appointment*& sortedList, Appointment* newAppointment) {
        if (sortedList == nullptr || newAppointment->endTime < sortedList->startTime) {
            newAppointment->next = sortedList;
            sortedList = newAppointment;
        } else {
            Appointment* current = sortedList;

            while (current->next != nullptr && newAppointment->endTime > current->next->startTime) {
                current = current->next;
            }

            newAppointment->next = current->next;
            current->next = newAppointment;
        }
    }

    // Merge Sort for linked list using pointer manipulation
    Appointment* mergeSort(Appointment* start) {
        if (start == nullptr || start->next == nullptr) {
            return start;
        }

        // Split the list into two halves
        Appointment* slow = start;
        Appointment* fast = start->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Appointment* secondHalf = slow->next;
        slow->next = nullptr;

        // Recursively sort both halves
        start = mergeSort(start);
        secondHalf = mergeSort(secondHalf);

        // Merge the sorted halves
        return merge(start, secondHalf);
    }

    // Merge two sorted linked lists
    Appointment* merge(Appointment* first, Appointment* second) {
        Appointment dummy{ "", "", "", nullptr };
        Appointment* current = &dummy;

        while (first != nullptr && second != nullptr) {
            if (first->startTime < second->startTime) {
                current->next = first;
                first = first->next;
            } else {
                current->next = second;
                second = second->next;
            }
            current = current->next;
        }

        if (first != nullptr) {
            current->next = first;
        } else {
            current->next = second;
        }

        return dummy.next;
    }
};

// Function to display the menu
void displayMenu() {
    cout << "Appointment Management System\n";
    cout << "1. Display Free Slots\n";
    cout << "2. Book Appointment\n";
    cout << "3. Cancel Appointment\n";
    cout << "4. Sort List Based on Time\n";
    cout << "5. Sort List Based on Time (Pointer Manipulation)\n";
    cout << "6. Exit\n";
}

int main() {
    AppointmentManager appointmentManager;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                appointmentManager.displayFreeSlots();
                break;
            case 2:
                appointmentManager.bookAppointment();
                break;
            case 3:
                appointmentManager.cancelAppointment();
                break;
            case 4:
                appointmentManager.sortListByTime();
                break;
            case 5:
                appointmentManager.sortListByTimePointer();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}
