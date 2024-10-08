class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
  }

  //method to insert a node at the beginning of the list
  insertAtBeginning(data) {
    const newNode = new Node(data);

    //pointing new node to head
    //null, initially
    newNode.next = this.head;

    this.head = newNode;
  }

  //method to insert data at the end of the list
  insertAtEnd(data) {
    const newNode = new Node(data);

    //if no node exist after head node
    if (!this.head) {
      this.head = newNode;
      return;
    }

    //end of list
    let current = this.head;
    while (current.next) {
      current = current.next;
    }
    current.next = newNode;
  }

  //delet a node by value
  deleteNode(data) {
    //head points to nothing
    if (!this.head) {
      return;
    }

    //if node is the head
    if (this.head.data == data) {
      this.head = this.head.next;
      return;
    }

    let current = this.head;
    let prev = null;
    while (current && current.data !== data) {
      prev = current;
      current = current.next;
    }

    //node not found
    if (!current) {
      return;
    }

    //unlinking the node
    prev.next = current.next;
  }

  printList() {
    let current = this.head;
    let result = "";
    while (current) {
      result += current.data + "->";
      current = current.next;
    }
    console.log(result + "NULL");
  }
}
