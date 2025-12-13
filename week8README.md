README – BankAccount Program
What this program does
This program is a simple bank account simulation written in C++.
It lets the user add money to an account, make purchases, check the balance, and save all transactions to a text file called transactions.txt.
Files in this project
main.cpp – the main C++ program
transactions.txt – a text file that stores all deposits, purchases, and the final balance
How it works
The program creates a bank account with a starting balance of $0.
It deposits $200 into the account.
It makes two purchases:
Daily necessities ($50.25)
Gas ($30.00)
It shows the final balance on the screen.
Every transaction is written to transactions.txt.
Example output (console)
Deposit amount: $200
Purchased: Daily necessities, cost $50.25
Purchased: Gas, cost $30
Current balance: $119.75
Example output (transactions.txt)
Deposit: $200
Purchase - Daily necessities: $50.25
Purchase - Gas: $30
Final balance: $119.75
How to run the program
Compile the program:
g++ main.cpp -o main
Run it:
./main
After running, the file transactions.txt will be created or updated.
Notes
The transactions.txt file is opened in append mode, so new transactions are added each time the program runs.
Some online compilers do not show generated files, so the program should be run in an environment that supports file creation.
