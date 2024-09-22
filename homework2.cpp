#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Hàm tạo danh sách liên kết từ dãy số nhập vào
Node* createList() {
    int n, value;
    Node* head = nullptr;
    Node* tail = nullptr;
    cout << "Nhập số lượng phần tử: ";
    cin >> n;
    cout << "Nhập các giá trị: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

// Hàm hiển thị danh sách liên kết
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Bài 1: Cộng hai số
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}

// Bài 2: Sao chép danh sách với con trỏ ngẫu nhiên
Node* copyList(Node* head) {
    if (!head) return nullptr;

    // Bước 1: Tạo bản sao của từng node và chèn vào danh sách
    Node* curr = head;
    while (curr) {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // Bước 2: Thiết lập con trỏ ngẫu nhiên (không sử dụng ở đây để đơn giản hóa)
    curr = head;
    while (curr) {
        curr = curr->next ? curr->next->next : nullptr;
    }

    // Bước 3: Tách danh sách ra
    curr = head;
    Node* copyHead = head->next;
    Node* copyCurr = copyHead;

    while (curr) {
        curr->next = curr->next ? curr->next->next : nullptr;
        copyCurr->next = copyCurr->next ? copyCurr->next->next : nullptr;
        curr = curr->next;
        copyCurr = copyCurr->next;
    }
    return copyHead;
}

// Bài 3: Đổi chỗ hai node
Node* swapNodes(Node* head, int k) {
    Node* first = head;
    Node* second = head;
    Node* temp = head;

    for (int i = 1; i < k; ++i) {
        first = first->next;
    }
    while (temp->next != nullptr) {
        second = second->next;
        temp = temp->next;
    }

    // Đổi chỗ dữ liệu giữa hai node
    int tempData = first->data;
    first->data = second->data;
    second->data = tempData;

    return head;
}

// Bài 4: Xóa node thứ N tính từ cuối
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* first = dummy;
    Node* second = dummy;

    for (int i = 0; i < n + 1; ++i) {
        first = first->next;
    }

    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    return dummy->next;
}

// Bài 5: Phân tách các node lẻ và chẵn
Node* separateOddEven(Node* head) {
    if (!head) return nullptr;

    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;

    while (head) {
        if (head->data % 2 == 0) {
            if (!evenHead) {
                evenHead = head;
                evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        } else {
            if (!oddHead) {
                oddHead = head;
                oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }

    if (evenTail) evenTail->next = nullptr;
    if (oddTail) oddTail->next = nullptr;

    // Kết nối danh sách lẻ và chẵn
    if (oddHead) {
        oddTail->next = evenHead;
        return oddHead;
    }
    return evenHead;
}

// Bài 6: Chia danh sách thành các phần
Node** divideList(Node* head, int k) {
    Node** parts = new Node*[k];
    for (int i = 0; i < k; i++) {
        parts[i] = nullptr;
    }

    int length = 0;
    Node* temp = head;

    while (temp) {
        length++;
        temp = temp->next;
    }

    int partSize = length / k;
    int remainder = length % k;

    temp = head;
    for (int i = 0; i < k; i++) {
        parts[i] = temp;
        int currentPartSize = partSize + (i < remainder ? 1 : 0);

        for (int j = 0; j < currentPartSize - 1; j++) {
            if (temp) temp = temp->next;
        }

        if (temp) {
            Node* nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }
    }
    return parts;
}

// Bài 7: Xóa các node liên tiếp có tổng bằng 0
Node* removeZeroSumConsecutive(Node* head) {
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* curr = head;
    Node* prev = dummy;
    
    while (curr) {
        int sum = 0;
        Node* temp = curr;
        
        while (temp) {
            sum += temp->data;
            if (sum == 0) {
                prev->next = temp->next;
                curr = prev->next; // Bắt đầu từ node tiếp theo
                break;
            }
            temp = temp->next;
        }
        if (sum != 0) {
            prev = curr; // Chỉ khi không tìm thấy tổng bằng 0
            curr = curr->next;
        }
    }
    return dummy->next;
}

// Bài 8: Nhập giá trị tự động cho danh sách
Node* autoInputList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int value = rand() % 199 - 99; // Tạo số ngẫu nhiên từ -99 đến 99
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

// Hàm hiển thị menu
void menu() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    Node* result = nullptr;
    int choice, n;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Two Numbers\n";
        cout << "2. Copy List with Random Pointers\n";
        cout << "3. Swap Nodes in a Linked List\n";
        cout << "4. Remove the N-th Node from the End of a List\n";
        cout << "5. Separate Odd and Even Nodes in a Linked List\n";
        cout << "6. Divide a Linked List into Parts\n";
        cout << "7. Remove Zero-Sum Consecutive Nodes from a Linked List\n";
        cout << "8. Auto-Input a List\n";
        cout << "0. Thoát\n";
        cout << "Lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Tạo danh sách 1:\n";
                list1 = createList();
                cout << "Tạo danh sách 2:\n";
                list2 = createList();
                result = addTwoNumbers(list1, list2);
                cout << "Kết quả cộng hai danh sách: ";
                printList(result);
                break;
            }
            case 2: {
                cout << "Tạo danh sách:\n";
                list1 = createList();
                Node* copiedList = copyList(list1);
                cout << "Danh sách đã sao chép:\n";
                printList(copiedList);
                break;
            }
            case 3: {
                cout << "Tạo danh sách:\n";
                list1 = createList();
                int k;
                cout << "Nhập vị trí k: ";
                cin >> k;
                list1 = swapNodes(list1, k);
                cout << "Danh sách sau khi đổi chỗ:\n";
                printList(list1);
                break;
            }
            case 4: {
                cout << "Tạo danh sách:\n";
                list1 = createList();
                cout << "Nhập N: ";
                cin >> n;
                list1 = removeNthFromEnd(list1, n);
                cout << "Danh sách sau khi xóa node N từ cuối:\n";
                printList(list1);
                break;
            }
            case 5: {
                cout << "Tạo danh sách:\n";
                list1 = createList();
                Node* separatedList = separateOddEven(list1);
                cout << "Danh sách sau khi phân tách lẻ và chẵn:\n";
                printList(separatedList);
                break;
            }
            case 6: {
                cout << "Tạo danh sách:\n";
                list1 = createList();
                int k;
                cout << "Nhập số phần: ";
                cin >> k;
                Node** parts = divideList(list1, k);
                cout << "Danh sách sau khi chia:\n";
                for (int i = 0; i < k; ++i) {
                    cout << "Phần " << i + 1 << ": ";
                    printList(parts[i]);
                }
                delete[] parts; // Giải phóng bộ nhớ
                break;
            }
            case 7: {
                cout << "Tạo danh sách:\n";
                list1 = createList();
                list1 = removeZeroSumConsecutive(list1);
                cout << "Danh sách sau khi xóa các node có tổng = 0:\n";
                printList(list1);
                break;
            }
            case 8: {
                cout << "Nhập số lượng phần tử ngẫu nhiên (39-59): ";
                int num = rand() % 21 + 39; // Số ngẫu nhiên từ 39 đến 59
                list1 = autoInputList(num);
                cout << "Danh sách đã được nhập tự động:\n";
                printList(list1);
                break;
            }
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
                break;
        }
    } while (choice != 0);
}

// Hàm chính
int main() {
    menu();
    return 0;
}
