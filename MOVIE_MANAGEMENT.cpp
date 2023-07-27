#include <iostream>
#include <vector>
#include <iomanip>

// Constants for the number of rows and columns of seats
const int NUM_ROWS = 5;
const int NUM_COLS = 10;

// Function to display the seating arrangement
void displaySeats(const std::vector<std::vector<char>>& seats) {
    std::cout << "  ";
    for (int col = 1; col <= NUM_COLS; ++col) {
        std::cout << std::setw(2) << col << " ";
    }
    std::cout << std::endl;

    for (int row = 0; row < NUM_ROWS; ++row) {
        std::cout << char('A' + row) << " ";
        for (int col = 0; col < NUM_COLS; ++col) {
            std::cout << seats[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to book a seat
bool bookSeat(std::vector<std::vector<char>>& seats, int row, int col) {
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
        std::cout << "Invalid seat selection. Please try again." << std::endl;
        return false;
    }

    if (seats[row][col] == 'X') {
        std::cout << "Seat already booked. Please choose another seat." << std::endl;
        return false;
    }

    seats[row][col] = 'X';
    return true;
}

int main() {
    std::vector<std::vector<char>> seats(NUM_ROWS, std::vector<char>(NUM_COLS, 'O'));

    std::vector<std::string> movieListings = {"Movie 1", "Movie 2", "Movie 3"};
    double ticketPrice = 10.0;

    std::cout << "Welcome to Movie Ticket Booking System!" << std::endl;

    char choice;
    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. View Movie Listings" << std::endl;
        std::cout << "2. Book Tickets" << std::endl;
        std::cout << "3. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::cout << "\nMovie Listings:" << std::endl;
                for (size_t i = 0; i < movieListings.size(); ++i) {
                    std::cout << i + 1 << ". " << movieListings[i] << std::endl;
                }
                break;
            }
            case '2': {
                std::cout << "\nMovie Listings:" << std::endl;
                for (size_t i = 0; i < movieListings.size(); ++i) {
                    std::cout << i + 1 << ". " << movieListings[i] << std::endl;
                }

                int movieChoice;
                std::cout << "Enter the movie number: ";
                std::cin >> movieChoice;

                if (movieChoice < 1 || movieChoice > static_cast<int>(movieListings.size())) {
                    std::cout << "Invalid movie selection. Please try again." << std::endl;
                    break;
                }

                std::cout << "Selected Movie: " << movieListings[movieChoice - 1] << std::endl;
                displaySeats(seats);

                int row, col;
                std::cout << "Enter the row and column of the seat you want to book (e.g., A 1): ";
                std::cin >> row >> col;
                --row; // Adjusting for 0-based indexing of seats in the array
                --col;

                if (bookSeat(seats, row, col)) {
                    std::cout << "Seat booked successfully!" << std::endl;
                    double totalCost = ticketPrice;
                    std::cout << "Total Cost: $" << totalCost << std::endl;
                }

                break;
            }
            case '3':
                std::cout << "Thank you for using the Movie Ticket Booking System! Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != '3');

    return 0;
}