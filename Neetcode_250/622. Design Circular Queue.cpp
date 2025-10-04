// class Node {
//     public:
//     int data;
//     Node* next;

//     Node(int data) : data(data), next(NULL) {};
// };

class MyCircularQueue {
public:

    // Node* head;
    // Node* tail;
    // int size;

    int *arr;
    int n;
    int front;
    int rear;

    MyCircularQueue(int k) {
        // head = NULL;
        // tail = NULL;
        // size = k;

        this->n = k;
        arr = new int[k];
        this->front = -1;
        this->rear = -1;
    }
    
    bool enQueue(int value) {
        // // full
        // if (size == 0) {
        //     return false;
        // }
        // // first element
        // else if (head == NULL && tail == NULL) {
        //     Node* newNode = new Node(value);
        //     head = newNode;
        //     tail = newNode;
        //     size--;

        //     return true;
        // }
        // // normal insertion
        // else {
        //     Node* newNode = new Node(value);
        //     tail->next = newNode;
        //     tail = newNode;
        //     size--;

        //     return true;
        // }

        
        // overflow
        if ((front == 0 && rear == n-1) || (rear == front-1)) {
            return false;
        }
        // first element
        else if (front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = value;
            return true;
        }
        // circular nature
        else if (rear == n-1 && front != 0) {
            // from start
            rear = 0;
            arr[rear] = value;
            return true;
        }
        // normal flow
        else {
            rear++;
            arr[rear] = value;
            return true;
        }
    }
    
    bool deQueue() {
        // // empty
        // if (!head && !tail) {
        //     return false;
        // }
        // // single node
        // else if (!head->next && !tail->next) {
        //     Node* toDel = head;
        //     head = NULL;
        //     tail = NULL;

        //     toDel->next = NULL;
        //     delete toDel;
        //     size++;

        //     return true;
        // }
        // // normal deletetion
        // else {
        //     Node* toDel = head;
        //     head = head->next;

        //     toDel->next = NULL;
        //     delete toDel;
        //     size++;

        //     return true;
        // }


        // underflow
        if (front == -1 && rear == -1) {
            return false;
        }
        // single element
        else if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
            return true;
        }
        // circular nature
        else if (front == n-1) {
            arr[front] = -1;
            front = 0;
            return true;
        }
        // normal case
        else {
            arr[front] = -1;
            front++;
            return true;
        }
    }
    
    int Front() {
        // // empty
        // if (!head && !tail) {
        //     return -1;
        // }
        // // no empty
        // else {
        //     return head->data;
        // }


        // underflow
        if (front == -1 && rear == -1) {
            return -1;
        }
        // not mepty
        else {
            return arr[front];
        }
    }
    
    int Rear() {
        // // empty
        // if (!head && !tail) {
        //     return -1;
        // }
        // // not empty
        // else {
        //     return tail->data;
        // }


        // empty
        if (front == -1 && rear == -1) {
            return -1;
        }
        // not empty
        else {
            return arr[rear];
        }

    }
    
    bool isEmpty() {
        // return (!head && !tail);

        return (front == -1 && rear == -1);
    }
    
    bool isFull() {
        // return (size == 0);

        return (front == 0 && rear == n-1) || (rear == front-1);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */