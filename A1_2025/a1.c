#include <stdio.h>



typedef struct _DrinkOrder_
{
    int glas_size_;
    int choosen_drink_;
    int tip_;
    float price_;
    float refund_money_;

} DrinkOrder;

typedef struct _DepositReturn_
{
    int number_of_glasses_;
    int glas_size_;
    float refund_money_;
} DepositReturn;

void kioskSimulator(void);
void printMainMenue(void);
void returnGlasses(void);
void orderDrinks(void);
void printRefundMessage(DepositReturn deposit);
void printGlasSizeMessage(void);
void printOrderMessage(DrinkOrder order);

int main(void)
{
    printf("Welcome to the Spritzerstand Simulator!!!\n");
    kioskSimulator();
    return 0;
}

void kioskSimulator(void)
{
    int number_of_task = 0;
    while(1)
    {
        printMainMenue();
        scanf("%d", &number_of_task);

        switch(number_of_task)
        {
            case 1: 
                returnGlasses();
                break;
            case 2:
                orderDrinks();
                break;
            case 3:
                return;
                break;
            default:
                printf("[Error]: Please choose a valid option!\n");

        }
    }
}

void printMainMenue(void)
{
    printf("\n");
    printf("How can I assist you today?\n");
    printf("1. I'd like to return my glasses.\n");
    printf("2. I'd like to order.\n");
    printf("3. Quit\n");
    printf(" > ");
}

void returnGlasses(void)
{
    DepositReturn deposit;
    deposit.number_of_glasses_ = 0;
    deposit.glas_size_ = 0;
    deposit.refund_money_ = 0;
    printf("\n");
    printf("How many glasses do you want to return?\n");
    printf(" > ");

    scanf("%d", &deposit.number_of_glasses_);

    if(deposit.number_of_glasses_ <= 0)
    {
        printf("[Error]: How do you plan on returning that?\n");
        return;
    }

    printGlasSizeMessage();

    scanf("%d", &deposit.glas_size_);

    if(deposit.glas_size_ == 300)
    {
        deposit.refund_money_ = 1.5;
    }
    else if(deposit.glas_size_ == 500)
    {
        deposit.refund_money_ = 2;
    }
    else
    {
        printf("[Error]: Sorry that glass size is invalid.\n");
        return;
    }
    printRefundMessage(deposit);
}

void orderDrinks(void)
{
    DrinkOrder order;
    order.choosen_drink_ = 0;
    order.glas_size_ = 0;
    order.price_ = 0;
    order.tip_ = 0;

    printf("\n");
    printf("What are you feeling today?\n");
    printf("1. Virgin Cuba Libre\n");
    printf("2. Carbonas rhoncus bibendum\n");
    printf("3. Fizzy water\n");
    printf(" > ");

    scanf("%d", &order.choosen_drink_);

    switch(order.choosen_drink_)
    {
        case 1:
            order.price_ = 2.5;
            break;
        case 2:
            order.price_ = 3;
            break;
        case 3:
            order.price_ = 1;
            break;
        default:
            printf("[Error]: Hmm I don't seem to have that drink.\n");
            return;
    }

    printGlasSizeMessage();

    scanf("%d", &order.glas_size_);

    if(order.glas_size_ == 300)
    {
        order.refund_money_ = 1.5;
    }
    else if(order.glas_size_ == 500)
    {
        order.refund_money_ = 2;
    }
    else
    {
        printf("[Error]: Sorry that glass size is invalid.\n");
        return;
    }

    printf("\n");
    printf("How much would you like to tip? (in %%)\n");
    printf(" > "); 

    scanf("%d" ,&order.tip_);

    if(order.tip_ < 0 || order.tip_ > 100)
    {
        printf("[Error]: I cannot accept that. Please insert an amount from 0 to 100.\n");
        return;
    }

    printOrderMessage(order);
}

void printRefundMessage(DepositReturn deposit)
{
    printf("\n");
    printf("--------------------------------\n");
    printf("You returned %d glasses at %.1f € each.\n", deposit.number_of_glasses_, deposit.refund_money_);
    printf("Your total cashback is: %.1f €\n", deposit.number_of_glasses_ * deposit.refund_money_);
    printf("--------------------------------\n");
    printf("Here you go... have a pleasant evening!\n");
}

void printGlasSizeMessage(void)
{
    printf("\n");
    printf("Select a glass size (in ml)\n");
    printf("- 300\n");
    printf("- 500\n");
    printf(" > ");
}

void printOrderMessage(DrinkOrder order)
{
    printf("\n");
    printf("--------------------------------\n");
    printf("- %d ml glass of <DRINK_NAME>\n", order.glas_size_);
    printf("- Drink price: %.1f €\n", order.price_);
    printf("- Deposit: %.1f €\n", order.refund_money_);
    printf("- Total without tip: %1f €\n", order.price_ + order.refund_money_);
    printf("- Tip: %d %%\n", order.tip_);
    printf("- Total: %.1f €\n", order.price_ + order.refund_money_ + order.tip_ * (order.price_ + order.refund_money_));
    printf("--------------------------------\n");
    printf("Here you go... have a pleasant evening!\n");
}
