#include<iostream>

struct list_node
{
    int value;
    list_node * next;
};

list_node * create_linklist(int arr[],int size){
    list_node *head = nullptr;
    list_node *current = nullptr;
    for (int i = 0;i < size;i++){
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
    int size = sizeof(array)/sizeof(array[0]);
    //在函数外部对全局数组使用 sizeof 时，返回整个数组的大小。
    //在函数内部对数组参数使用 sizeof 时，返回指针的大小，而不是数组本身的大小。
    list_node *head = create_linklist(array,size);

    for(list_node *visitor = head; visitor != nullptr; visitor  = visitor -> next){
        std::cout << visitor -> value << " ";
    }




    return 0;
}
