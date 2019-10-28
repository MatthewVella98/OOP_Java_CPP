public class CustomLinkedNode<T> {            //The node of the Linked List class
    private T data;                            //stores the data for the linked list
    private CustomLinkedNode<T> next;        //pointer for the next node in the list

    public CustomLinkedNode() {            //If the link list is initialized for the first time
        this.data = null;
        this.next = null;
    }

    public CustomLinkedNode(T obj) {        //Creates the New node object and stores the data
        this.data = obj;
        this.next = null;
    }

    public T getData() {                       //returns the data in the node
        return data;
    }

    public void setData(T data) {               //sets the value of the node
        this.data = data;
    }

    public CustomLinkedNode<T> getNext() {        //returns the pointer of the next node
        return next;
    }

    public void setNext(CustomLinkedNode<T> next) {    //sets the pointer for the next node
        this.next = next;
    }

}
