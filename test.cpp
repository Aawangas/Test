#include<iostream>

struct list_node
{
    int value;
    list_node * next;
};

int main(){
    int array[] = {1,3,5,7,9,11,13,15};
    list_node *head = nullptr;
    list_node *current = nullptr;
    for (int i = 0;i < sizeof(array)/sizeof(array[0]);i++){
        list_node *node = new list_node;
        node -> value = array[i];
        node -> next = nullptr;
        if(head == nullptr){
            head = node;
            current = node;
        }
        else{
            current -> next = node;
            current = node;
        }  
    }

    for(list_node *visitor = head; visitor != nullptr; visitor  = visitor -> next){
        std::cout << visitor -> value;
    }




    return 0;
}
