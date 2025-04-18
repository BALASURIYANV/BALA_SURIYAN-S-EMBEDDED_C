   BS Bus Ticket Reservation System.
This is a C-based Bus Ticket Reservation System that allows users to book, cancel, and view passenger seat information across different bus types: AC, Non-AC, and Sleeper. It uses a simple console interface and stores booking data in a text file.

📌 Features
Choose from 3 types of buses: AC, Non-AC, Sleeper

Display current seat layout for each bus

Book available seats with passenger details

Cancel previously booked seats

View passenger details for any booked seat

Save booking data to a file (passengerdetails.txt) for record keeping

🛠️ How It Works
Each bus has 12 rows × 3 columns (36 seats)

All seats are initialized as available at program start

Seat numbers are shown as available (01, 02, ...) or booked (X)

Upon booking, the system stores:

Passenger Name

Age

Gender

Bus Type and Seat Number

Booking info is stored in passengerdetails.txt (appended)

 Future Improvements (Ideas)
Save and load seat data from file for persistence between runs

Add login system for admin and user roles

Implement search/filtering by passenger name or seat number

Build GUI version using a graphics library

