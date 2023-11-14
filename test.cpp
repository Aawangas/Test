#include<iostream>

struct list_node
{
    int value;
    list_node * next;
};
int len(int arr[]){
    return (sizeof(arr)/sizeof(arr[0]));
}
list_node* create_linklist(int arr[],list_node *head){
    list_node *current = nullptr;
    for (int i = 0;i < len(arr);i++){
        list_node *node = new list_node;
        node -> value = arr[i];
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
    return head;
}

int main(){
    int array[] = {1,3,5,7,9,11,13,15};
    list_node *head = nullptr;
    head = create_linklist(array,head);
    for(list_node *visitor = head; visitor != nullptr; visitor  = visitor -> next){
        std::cout << visitor -> value;
    }




    return 0;
}