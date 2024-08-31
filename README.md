# Cryptocurrency Management System

This project is a **Cryptocurrency Management System** developed as part of the Object-Oriented Programming Specialization course on Coursera, offered by the University of London. The project showcases the application of OOP principles, encapsulation, and class design in C++. It is a comprehensive management system for handling digital currencies, placing orders, and managing a wallet, demonstrating intermediate-level C++ skills.

## Table of Contents
- [Project Overview](#project-overview)
- [Course Details](#course-details)
- [Programming Skills Developed](#programming-skills-developed)
- [Modules](#modules)
  - [Currency](#currency)
  - [Wallet](#wallet)
  - [Order](#order)
  - [Exchange](#exchange)
  - [Crypto Management System](#crypto-management-system)
- [Features](#features)
- [How to Run](#how-to-run)
- [Learning Outcomes](#learning-outcomes)

## Project Overview

The Cryptocurrency Management System is designed to:
- Manage multiple cryptocurrencies within a wallet.
- Place and manage ask/bid orders.
- Display portfolio values based on active orders.
- Provide an interactive command-line interface for user interaction.

## Course Details

This project was completed as part of the **Object-Oriented Programming Specialization** on Coursera, offered by the **University of London**. The course covered fundamental OOP concepts, emphasizing practical implementation in C++. Topics included class design, encapsulation, inheritance, polymorphism, and real-world application development, culminating in this capstone project.

## Programming Skills Developed

During this project, I honed several key programming skills:
- Mastery of object-oriented programming concepts in C++, including class design, encapsulation, and data abstraction.
- Proficient use of standard C++ libraries for managing collections, such as vectors.
- Implementation of interactive command-line interfaces to enhance user experience.
- Application of logical reasoning and problem-solving skills in designing a multi-module system for managing digital assets.
- Understanding of modular programming by breaking down a complex system into manageable components.

## Modules

### Currency

The `Currency` class represents a cryptocurrency with a type (e.g., Bitcoin, Ethereum) and an amount. It is used within the `Wallet` to track and manage different types of cryptocurrencies.

- **Attributes:**
  - `type`: The name of the cryptocurrency.
  - `amount`: The quantity of the cryptocurrency.

### Wallet

The `Wallet` class is responsible for managing various currencies. It allows users to add, remove, and check the availability of currencies. It also displays the contents of the wallet.

- **Key Functions:**
  - `insertCurrency`: Adds a specified amount of a cryptocurrency to the wallet.
  - `removeCurrency`: Removes a specified amount of a cryptocurrency from the wallet if available.
  - `containsCurrency`: Checks if the wallet contains enough of a specified cryptocurrency.
  - `displayWallet`: Displays the contents of the wallet with current balances.

### Order

The `Order` class represents an order in the exchange system, either as an "ask" (selling) or "bid" (buying) order. It includes the type, currency, amount, and price per unit.

- **Attributes:**
  - `type`: The type of order ("ask" or "bid").
  - `currency`: The type of cryptocurrency in the order.
  - `amount`: The amount involved in the order.
  - `price`: The price at which the order is placed.

- **Key Functions:**
  - `displayOrder`: Displays the details of the order.

### Exchange

The `Exchange` class manages all orders, providing functionalities to place, display, and cancel orders. It also calculates the total portfolio value based on the active orders.

- **Key Functions:**
  - `placeOrder`: Adds an order to the exchange's order book.
  - `displayOrders`: Shows all active orders.
  - `cancelOrder`: Cancels an order based on its index.
  - `calculatePortfolioValue`: Computes the total value of all "ask" orders in the portfolio.

### Crypto Management System

The `CryptoManagementSystem` class serves as the main interface for the project, integrating the `Wallet` and `Exchange` functionalities. It provides a menu-driven command-line interface for users to interact with the system.

- **Key Functions:**
  - `mainMenu`: Displays the main menu and handles user inputs.
  - `insertCurrency`: Facilitates adding currency through user input.
  - `removeCurrency`: Facilitates removing currency through user input.
  - `checkCurrency`: Checks and confirms currency availability based on user input.
  - `placeAsk`: Handles the process of placing an ask order.
  - `placeBid`: Handles the process of placing a bid order.
  - `cancelOrder`: Facilitates the cancellation of orders.
  - `calculatePortfolioValue`: Calculates and displays the total portfolio value.

## Features

- **Currency Management:** Easily add, remove, and manage cryptocurrencies in a wallet.
- **Order Placement:** Place bid and ask orders seamlessly.
- **Order Book Management:** View, manage, and cancel orders.
- **Portfolio Value Calculation:** Real-time calculation of the portfolio value based on active orders.
- **User-Friendly Interface:** Intuitive command-line menu for smooth navigation.

## How to Run

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Adarsh-Singh07/CPP-Project-Crypto-Management-System
2. **Compile the program:**
   ```bash
    g++ main.cpp -o crypto_management_system
3. **Run the program:**
   ```bash
    ./crypto_management_system
