import java.util.ArrayList;
import java.util.List;

class CustomLinkedList<T> {
    private CustomLinkedNode<T> first;            //stores the first node of the Linked List
    private CustomLinkedNode<T> last;            //stores the last node of the linked list
    private int count;                            //total count of the nodes in the linked list


    public CustomLinkedList() {                //Creating a New Linked List Object
        CustomLinkedNode<T> newLiked = new CustomLinkedNode<T>();    //creates a new object i.e., the node for root
        this.first = newLiked;
        this.last = this.first;
    }

    public void add(T data) {                //adds a new node to the linked list and adjusts it accordingly
        CustomLinkedNode<T> newData = new CustomLinkedNode<T>(data);
        if (this.first.getData() == null) {        //this checks if the tree has any further nodes or not
            this.first = newData;
            this.last = this.first;
        } else {                    //if not it adds the node to the next memeber in the Node tree
            this.last.setNext(newData);
            this.last = newData;
        }
        count++;
    }

    public List<String> toList() {                //Just to type cast a the tree into a List
        List<String> l = new ArrayList<String>(count);
        boolean allStored = false;
        int count = 0;
        CustomLinkedNode<T> crr = first;
        while (!allStored) {                //just to check if tree is completely stored in the list or not
            if (crr.getData() != null) {
                l.add(crr.getData().toString());
                //System.out.print(crr.getData().toString()+", ");
                if (crr.getNext() != null) {            //if the Tree is not reached it's end
                    CustomLinkedNode<T> crrNext = crr.getNext();
                    crr = crrNext;
                } else {                        //if it has reached the end it changes the value of allStored
                    //System.out.println();
                    allStored = true;
                }
            } else {
                allStored = true;
            }
        }
        return l;
    }

    public int getCount() {        //returns the count of nodes of the tree
        return count;
    }
}