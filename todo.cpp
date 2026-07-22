#include<iostream>
using namespace std;

class Todo{
    private:
        string itemname;
        int id;
        int quantity;
        static int totalitems;
        int s = 3;
        Todo *ptr= new Todo[s];
    public:
        Todo(string name=" ",int i=0,int q=0):itemname(name),id(i),quantity(q){
            totalitems++;
        }
        void additem(){
            int ns = 1;
            Todo *nitem = new Todo[ns];
            for(int i=0;i<3;i++){
                nitem[i] = ptr[i];
            }
            ptr = nitem;
            s = ns;
        }
        void removeitem(){

        }
        void checkcomplete(){

        }
        void displayallitems(){

        }
        void updateitem(){

        }
};

int main(){

    return 0;
}