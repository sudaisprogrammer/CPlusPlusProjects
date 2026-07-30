#include<iostream>
using namespace std;
class Product{
    public:
        int id;
        char name[40];
        float price;
        static float totalcatvalue;
        static int count;
        Product(){

        }
        Product(int i,char *n,float p):id(i),name(*n),price(p){
            totalcatvalue+=p;
            count++;
        }
        void display()const{
            for(int i=0;i<count;i++){
                cout<<"Name is "<<name<<endl;
                cout<<"ID is "<<id<<endl;
                cout<<"Price is "<<price<<endl;
                cout<<"Total Cart Value is "<<totalcatvalue<<endl;
            }
        }
};
int main(){

    return 0;
}