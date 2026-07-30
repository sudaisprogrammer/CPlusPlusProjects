#include<iostream>
using namespace std;
class Product{
    public:
        int id;
        char name[40];
        float price;
        static float totalcatvalue;
        static int count;
        Product *prod = new Product[3];
        Product(){

        }
        Product(int i,char *n,float p):id(i),name(*n),price(p){
            totalcatvalue+=p;
            count++;
        }
        void addProduct(){

        }
        void removeProduct(){

        }
        void applyDiscount(){

        }
        ~Product(){
            delete[] prod;
            prod = nullptr;
            cout<<"\nThanks for using our Store\n";
            return;
        }
        void display()const{
            for(int i=0;i<count;i++){
                cout<<"Name is "<<name<<endl;
                cout<<"ID is "<<id<<endl;
                cout<<"Price is "<<price<<endl;
            }
            cout<<"Total Cart Value is "<<totalcatvalue<<endl;
        }
};
int main(){
    Product ptr;
    int c;
    while(true){
        cout<<"1. Add Product\n";
        cout<<"2. Remove Product\n";
        cout<<"3. Apply Discount\n";
        cout<<"4. Display All Product\n";
        cout<<"5. Exit...\n";

        cout<<"\nSelect from menu: ";
        cin>>c;
        switch(c){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
        }
    }
    return 0;
}