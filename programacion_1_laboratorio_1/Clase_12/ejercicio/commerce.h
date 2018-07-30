#define MAX_QTY 200

typedef struct{
    char description[51];
    int code;
    int qty;
    float price;
    int status; /**< Active (1) or Inactive (0)  */
}Product;


void setStatus(Product productArray[],int arrayLenght,int value);
int findEmptyPlace(Product productArray[],int arrayLenght);
int findProductByCode(Product productArray[],int arrayLenght,int code);
float getCheaperPrice(Product productArray[],int arrayLenght);
float getAveragePrice(Product productArray[],int arrayLenght);
void orderArrayByDescription(Product productArray[],int arrayLenght);
