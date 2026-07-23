#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class Todo{
    private:
        string itemname;
        int id;
        int quantity;
        static int totalitems;
        int s = 1;
        Todo *ptr;
    public:
        Todo(string name=" ",int i=0,int q=0):itemname(name),id(i),quantity(q){
            totalitems++;
            ptr = nullptr;
        }
        void additem(){

            Todo *nitem = new Todo[s+1];
            string name;int i,q;
            cout<<"Enter the name of the item: ";
            getline(cin,name);
            cout<<"Enter the id: ";
            cin>>i;
            cout<<"Enter the quantity: ";
            cin>>q;

            for(int i=0;i<s;i++){
                nitem[i] = ptr[i];
            }
            nitem[s] = Todo(name,i,q);
            delete[] ptr;
            ptr = nitem;
            s++;
            cout<<"\nAdded Successfully\n";
        }
        void removeitem(){
            int i_d,f;
            bool find = false;
            cout<<"Enter the ID to Remove the element: ";
            cin>>i_d;
            for(int i=0;i<s;i++){
                if(ptr[i].id == i_d){
                    find = true;
                    f = i;
                    break;
                }
            }
            Todo*newlist = new Todo[s-1];

            ptr[f];
        }
        void checkcomplete(){

        }
        void displayallitems(){
            for(int i=0;i<s;i++){
                cout<<"\n====================\n";
                cout<<itemname<<endl;
                cout<<id<<endl;
                cout<<quantity<<endl;
                cout<<"====================\n";
            }
        }
        void updateitem(){
            int i_d,f;
            bool find = false;
            cout<<"Enter the ID to Remove the element: ";
            cin>>i_d;
            for(int i=0;i<s;i++){
                if(ptr[i].id==i_d){
                    find = true;
                    f = i;
                    break;
                }
            }
            if(find){
                int q;
                cout<<"Enter the new quantity: ";
                cin>>q;
                ptr[f].quantity =q;
                cout<<"\nUpdated successfully\n";
            }
            else{
                cout<<"\ninvalid id entered\n";
            }
        }
};

int main(){

    return 0;
}