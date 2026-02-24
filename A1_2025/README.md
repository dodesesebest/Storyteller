# Assignment 1 - Spritzerstand Simulator

## Introduction

In Assignment 1 (A1) of the ISP practicals (KU), you will implement a program that simulates a _non-alcoholic Spritzerstand_.

This document describes the structure of the assignment and the expected functionality of the program.

## Learning Goals

Variables, Data Types, Functions, Conditional Statements (If - Else), Loops, Structs

## Specification

There are some general specifications that must be followed for every assignment in this course. A list of these and which point deductions
may result from violating them can be found here:
[Assessment of Assignments - Deductions](https://www.notion.so/coding-tugraz/Assessment-of-Assignments-How-do-you-get-your-points-d7cca6cc89a344e38ad74dd3ccb73cb3?pvs=4#e3203e50b1fc4ba787bdbf5fb46262ae)

Additionally, the following specification must be followed for this assignment (A1) as well:
- **Attention:** Each type of order must be represented as its own struct. In particular, you must define two separate structs: (1) one for ordering drinks, and (2) one for deposit returns (Pfand). Failure to do so may result in a deduction of **up to 25%**.


## Grading

Assignment 1 is worth **12 points**.

Information on how your assignment submission will be assessed can be found here: [Assessment of Assignments](https://coding-tugraz.notion.site/Assessment-of-Assignments-How-do-you-get-your-points-Testcases-Style-Guide-Deductions-d7cca6cc89a344e38ad74dd3ccb73cb3). Please read this carefully, as it also contains guidelines on what your final code should look like (Coding Standard, Style Guide).

Here you can find an overview of how your total grade for the KU will be calculated: [Procedure and Grading](https://coding-tugraz.notion.site/Practicals-Structure-and-Grading-59975fee4a9c4047867772cd20caf73d)


## Submission

- Deliverables: `a1.c`
- Push to your repository
- **Deadline: 29.10.2025, 18:00 (Austrian time)**

## Weekly Exercises

There are **Weekly Exercises** associated with this assignment available on
[TeachCenter](https://tc.tugraz.at/main/course/section.php?id=72261).
These are simple exercises designed to help you prepare for the assignment, and **must** be solved at least partially to avoid deductions.

- **Attention**: At least 50% of the Weekly Exercises for A1 must be solved before the A1 deadline. Failure to meet this requirement will result in a **25% point deduction on A1**.

## Assignment Description

This program implements a simplified kiosk simulator (Spritzerstand). Users can either order drinks or return deposit glasses (Pfand).

- For a drink order, the program asks for the glass size, the drink type, and a tip.
- For a deposit return, the program asks for the glass size and the number of glasses to return.

After each interaction, the program displays a short summary (see the respective _Calculations and Output_ section for drink orders or deposit returns below).

### General Notes

The notes given in this section are important for the entire assignment description:

- `\n` should not be printed as separate characters, instead they represent the newline character.
- Note the leading and trailing spaces in the text fields! You can make them visible by selecting the text field.
- Words in angle brackets (such as `<TOTAL_PRICE>`) should be replaced by calculated or given data. They are **not** part of the output itself! For a better understanding, you can look at the [example outputs](#example-outputs) at the very bottom of this document.
- <code>&nbsp;>&nbsp;</code> (command prompt, always printed with a leading and trailing space) in the output indicates that the program should wait for user input at this point. Execution should only continue after the user submits their input with `ENTER`.
- In the testcases of this assignment only integers will be tested as user input. You do not have to think about other inputs like characters or multiple integers separated by spaces. However, it is possible that values outside the valid integer range occur.
- If the user's input is invalid, the corresponding error message should be printed. After this, the same question is asked again, the command prompt is printed, and the user can input again. This process is repeated **as long as** the input is invalid.

## Program Sequence

The simulator follows a defined sequence of steps, starting with a welcome message and continuing through user interactions. The program runs in a loop, allowing multiple interactions until the user chooses to quit.

### Starting Sequence

When the program starts, it first prints a welcome message and then presents the main menu for selecting an interaction.

#### Welcome Message
At the start of the program, the following welcome message is printed to the screen.

```
Welcome to the Spritzerstand Simulator!!!\n
```

After this, the logic of the simulator starts.

#### Choosing Interaction Type
The simulator program is capable of handling three interactions:
1. returning glasses for a deposit (Pfand),
2. ordering drinks,
3. and quitting the simulator.

The user selects one of these options from the main menu shown below.

```
\n
How can I assist you today?\n
1. I'd like to return my glasses.\n
2. I'd like to order.\n
3. Quit\n
 > 
```

> **Note:**
>
> The list elements shown in the program’s prompts always indicate the valid input options.
> - In an enumerated list, each number (enumeration) corresponds directly to the input required to select that option.
> - In an unordered list, the values written next to the list items are the valid inputs.
>
> For example, in the menu prompt above, the valid inputs are `1`, `2`, and `3`. Any other input is considered invalid.


If the input is invalid, an error message is printed, followed by the main menu message and prompt again. This process is repeated until a valid input is entered.
The following error message is to be printed.

```
[Error]: Please choose a valid option!\n
```

The prompt above is repeated after each interaction (drink order or deposit return), until the user chooses **Quit**. The program then terminates with return value `0`.

### Returning Deposit Glasses

> **Reminder:** You must define a `struct` type to represent a deposit glass return. This struct must contain all the relevant information for a single return (e.g. the number of glasses and the glass size). It is allowed to include additional members if you find them useful, but the required information must be stored in this struct.

If the user chooses `1` in the main menu, the deposit glass return sequence starts.

#### Number of Glasses

The first question asked is how many glasses the user wants to return.

```
\n
How many glasses do you want to return?\n
 > 
```

The user must enter a number greater than 0. If the input is invalid, the following error message is printed.

```
[Error]: How do you plan on returning that?\n
```

#### Glass Size

All glasses are either 300 ml or 500 ml. After the prompt below is displayed, the user can choose a size by entering `300` or `500`.

```
\n
Select a glass size (in ml)\n
- 300\n
- 500\n
 > 
```

> **Note:** For each deposit glass return, only one glass size can be returned, but you may return multiple glasses of that size.

If the input is invalid, the following error message is printed.

```
[Error]: Sorry that glass size is invalid.\n
```

#### Calculations and Output

After the user has entered the number of glasses to return and their size, the program calculates the refund and prints a short summary. Each 300 ml glass is worth 1.5 € and each 500 ml glass is worth 2 €.


```
\n
--------------------------------\n
You returned <GLASS_COUNT> glasses at <DEPOSIT_REFUND> € each.\n
Your total cashback is: <TOTAL_RETURN> €\n
--------------------------------\n
Here you go... have a pleasant evening!\n
```

In the message above, some placeholders must be replaced. Each has the following meaning and print format:

- `<GLASS_COUNT>` -- An integer representing how many glasses the user returns.
- `<DEPOSIT_REFUND>` -- A decimal value representing the refund per glass. It must be printed with two decimal places.
- `<TOTAL_RETURN>` -- A decimal value representing the total refund to the user. It must be printed with two decimal places.

The program returns to the main menu, ready for the next interaction.

### Ordering Drinks

> **Reminder:** You must define a `struct` type to represent a drink order. This struct must contain all the relevant information for a single order (e.g. the chosen drink, the glass size, and the tip). It is allowed to include additional members if you find them useful, but the required information must be stored in this struct.

If the user chooses `2` in the main menu, the drink order sequence starts.

The customer can order one drink at a time. The simulation program offers three different beverages, listed in the table below with their respective prices per glass **(without deposit)**:

| Drink name                | Price per glass in EUR |
|---------------------------|------------------------|
| Virgin Cuba Libre         | 2.5                    |
| Carbonas rhoncus bibendum | 3                      |
| Fizzy water               | 1                      |


#### Choosing a Drink

To choose a drink, the following message is printed. The user must input either `1`, `2` or `3`.

```
\n
What are you feeling today?\n
1. Virgin Cuba Libre\n
2. Carbonas rhoncus bibendum\n
3. Fizzy water\n
 > 
```

If the input is invalid, the following error message is printed.

```
[Error]: Hmm I don't seem to have that drink.\n
```

#### Glass Size

In the same way as in the glass deposit return process, a drink order can be placed in either a 300 ml or 500 ml glass. The prompt and error message are identical to those described [here](#glass-size).

#### Tip

As any good service would, the program asks the user for a tip. After the prompt below is displayed, the user can enter a tip (`0` - `100` %).

```
\n
How much would you like to tip? (in %)\n
 > 
```

If the input is invalid, the following error message is printed.

```
[Error]: I cannot accept that. Please insert an amount from 0 to 100.\n
```

#### Calculations and Output

The simulator now calculates the total cost of the order, including the drink price, deposit for the selected glass size, and any tip. The tip is applied to the sum of the drink price and the deposit fee. Each 300 ml glass is worth 1.5 € and each 500 ml glass is worth 2 €. Once the calculation is complete, a summary of the order is printed, showing all relevant amounts.

```
\n
--------------------------------\n
- <GLASS_SIZE> ml glass of <DRINK_NAME>\n
- Drink price: <DRINK_PRICE> €\n
- Deposit: <DEPOSIT_FEE> €\n
- Total without tip: <TOTAL_BEFORE_TIP> €\n
- Tip: <TIP> %\n
- Total: <TOTAL> €\n
--------------------------------\n
Here you go... have a pleasant evening!\n
```

In the message above, some placeholders must be replaced. Each has the following meaning and print format:

The following placeholders have been read from the user:
- `<GLASS_SIZE>` -- The chosen glass size
- `<DRINK_NAME>` -- The name of the selected drink
- `<TIP>` -- The tip percentage entered by the user

Other placeholders must be computed:
- `<DRINK_PRICE>` -- The price of the selected drink (print with two decimal places)
- `<DEPOSIT_FEE>` -- The deposit fee for the selected glass (print with two decimal places)
- `<TOTAL_BEFORE_TIP>` -- The sum of the drink price and the deposit fee. This is the amount the tip is calculated on (print with two decimal places)
- `<TOTAL>` -- The total amount to pay, including tip (print with two decimal places)

The program returns to the main menu, ready for the next interaction.

## Example Outputs

<details>
<summary><h3>Returning Deposit Glasses</h3></summary>

```
Welcome to the Spritzerstand Simulator!!!

How can I assist you today?
1. I'd like to return my glasses.
2. I'd like to order.
3. Quit
 > 4
[Error]: Please choose a valid option!

How can I assist you today?
1. I'd like to return my glasses.
2. I'd like to order.
3. Quit
 > 1

How many glasses do you want to return?
 > 2

Select a glass size (in ml)
- 300
- 500
 > 300

--------------------------------
You returned 2 glasses at 1.50 € each.
Your total cashback is: 3.00 €
--------------------------------
Here you go... have a pleasant evening!

How can I assist you today?
1. I'd like to return my glasses.
2. I'd like to order.
3. Quit
 > 3
```
</details>

<details>
<summary><h3>Ordering Drinks</h3></summary>

```
Welcome to the Spritzerstand Simulator!!!

How can I assist you today?
1. I'd like to return my glasses.
2. I'd like to order.
3. Quit
 > 2

What are you feeling today?
1. Virgin Cuba Libre
2. Carbonas rhoncus bibendum
3. Fizzy water
 > 1

Select a glass size (in ml)
- 300
- 500
 > 300

How much would you like to tip? (in %)
 > 10

--------------------------------
- 300 ml glass of Virgin Cuba Libre
- Drink price: 2.50 €
- Deposit: 1.50 €
- Total without tip: 4.00 €
- Tip: 10 %
- Total: 4.40 €
--------------------------------
Here you go... have a pleasant evening!

How can I assist you today?
1. I'd like to return my glasses.
2. I'd like to order.
3. Quit
 > 3
```
</details>