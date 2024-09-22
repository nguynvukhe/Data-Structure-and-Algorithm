/// STT: 22520662
/// Full name: Nguyễn Vũ Khê
/// In-class Exercise - Part 1
/// Note or Remarks: .......
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* taoNode(int giaTri) {
    Node* nodeMoi = new Node();
    nodeMoi->data = giaTri;
    nodeMoi->next = nullptr;
    return nodeMoi;
}

void themNode(Node*& dau, int giaTri) {
    if (dau == nullptr) {
        dau = taoNode(giaTri);
    } else {
        Node* tam = dau;
        while (tam->next != nullptr) {
            tam = tam->next;
        }
        tam->next = taoNode(giaTri);
    }
}

void inDanhSach(Node* dau) {
    while (dau != nullptr) {
        cout << dau->data << " ";
        dau = dau->next;
    }
    cout << endl;
}

// 1. Find the Middle Node of a Linked List
Node* timNodeGiua(Node* dau) {
    if (!dau) return nullptr;
    Node *chamCham = dau, *nhanh = dau;
    while (nhanh && nhanh->next) {
        chamCham = chamCham->next;
        nhanh = nhanh->next->next;
    }
    return chamCham;
}

// 2. Detect a Cycle in a Linked List
bool phatHienVong(Node* dau) {
    Node *chamCham = dau, *nhanh = dau;
    while (nhanh && nhanh->next) {
        chamCham = chamCham->next;
        nhanh = nhanh->next->next;
        if (chamCham == nhanh) return true;
    }
    return false;
}

// 3. Combine Two Sorted Linked List
Node* ketHopHaiDanhSach(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->data < l2->data) {
        l1->next = ketHopHaiDanhSach(l1->next, l2);
        return l1;
    } else {
        l2->next = ketHopHaiDanhSach(l1, l2->next);
        return l2;
    }
}

// 4. Find the Intersection of Two Linked List
Node* timGiaoDiem(Node* dau1, Node* dau2) {
    while (dau1) {
        Node* tam = dau2;
        while (tam) {
            if (dau1 == tam) return dau1;
            tam = tam->next;
        }
        dau1 = dau1->next;
    }
    return nullptr;
}

// 5. Reverse a Linked List
Node* daoNguocDanhSach(Node* dau) {
    Node* truoc = nullptr;
    Node* hienTai = dau;
    while (hienTai) {
        Node* ke = hienTai->next;
        hienTai->next = truoc;
        truoc = hienTai;
        hienTai = ke;
    }
    return truoc;
}

// 6. Eliminate Duplicates from a Sorted Linked List
void loaiBoTrungLap(Node*& dau) {
    Node* hienTai = dau;
    while (hienTai && hienTai->next) {
        if (hienTai->data == hienTai->next->data) {
            Node* tam = hienTai->next;
            hienTai->next = hienTai->next->next;
            delete tam;
        } else {
            hienTai = hienTai->next;
        }
    }
}

// 7. Check if a Linked List is a Palindrome
bool laPalindrome(Node* dau) {
    Node *chamCham = dau, *nhanh = dau;
    Node *truoc = nullptr;

    while (nhanh && nhanh->next) {
        nhanh = nhanh->next->next;
        Node* nodeKe = chamCham->next;
        chamCham->next = truoc;
        truoc = chamCham;
        chamCham = nodeKe;
    }
    if (nhanh) chamCham = chamCham->next;

    while (chamCham) {
        if (chamCham->data != truoc->data) return false;
        chamCham = chamCham->next;
        truoc = truoc->next;
    }
    return true;
}

// 8. Write a function to search for nodes with the value X in the list
Node* timNode(Node* dau, int x) {
    while (dau) {
        if (dau->data == x) return dau;
        dau = dau->next;
    }
    return nullptr;
}

int main() {
    Node* dau = nullptr;
    int luaChon, giaTri, soNode;

    cout << "Nhập số lượng node muốn thêm vào danh sách: ";
    cin >> soNode;
    for (int i = 0; i < soNode; i++) {
        cout << "Nhập giá trị cho node thứ " << (i + 1) << ": ";
        cin >> giaTri;
        themNode(dau, giaTri);
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Thêm Node\n";
        cout << "2. Tìm Node Giữa\n";
        cout << "3. Phát Hiện Vòng\n";
        cout << "4. Kết Hợp Hai Danh Sách Liên Kết\n";
        cout << "5. Tìm Giao Điểm Hai Danh Sách Liên Kết\n";
        cout << "6. Đảo Ngược Danh Sách Liên Kết\n";
        cout << "7. Loại Bỏ Trùng Lặp Từ Danh Sách Liên Kết Đã Sắp Xếp\n";
        cout << "8. Kiểm Tra Danh Sách Liên Kết Có Phải Là Palindrome\n";
        cout << "9. Tìm Kiếm Node Có Giá Trị X\n";
        cout << "0. Thoát\n";
        cout << "Chọn một tùy chọn: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Nhập giá trị để thêm: ";
                cin >> giaTri;
                themNode(dau, giaTri);
                inDanhSach(dau);
                break;
            case 2: {
                Node* nodeGiua = timNodeGiua(dau);
                if (nodeGiua) cout << "Node Giữa: " << nodeGiua->data << endl;
                else cout << "Danh sách rỗng." << endl;
                break;
            }
            case 3:
                cout << (phatHienVong(dau) ? "Phát hiện vòng!" : "Không có vòng.") << endl;
                break;
            case 4: {
                Node* l2 = nullptr;
                int soNode2;
                cout << "Nhập số lượng node cho danh sách thứ hai: ";
                cin >> soNode2;
                for (int i = 0; i < soNode2; i++) {
                    cout << "Nhập giá trị cho node thứ " << (i + 1) << ": ";
                    cin >> giaTri;
                    themNode(l2, giaTri);
                }
                dau = ketHopHaiDanhSach(dau, l2);
                cout << "Danh sách sau khi kết hợp: ";
                inDanhSach(dau);
                break;
            }
            case 5: {
                Node* dau2 = nullptr;
                int soNode2;
                cout << "Nhập số lượng node cho danh sách thứ hai: ";
                cin >> soNode2;
                for (int i = 0; i < soNode2; i++) {
                    cout << "Nhập giá trị cho node thứ " << (i + 1) << ": ";
                    cin >> giaTri;
                    themNode(dau2, giaTri);
                }
                Node* giaoDiem = timGiaoDiem(dau, dau2);
                if (giaoDiem) cout << "Giao điểm tìm thấy: " << giaoDiem->data << endl;
                else cout << "Không có giao điểm." << endl;
                break;
            }
            case 6:
                dau = daoNguocDanhSach(dau);
                cout << "Danh sách sau khi đảo ngược: ";
                inDanhSach(dau);
                break;
            case 7:
                loaiBoTrungLap(dau);
                cout << "Danh sách sau khi loại bỏ trùng lặp: ";
                inDanhSach(dau);
                break;
            case 8:
                cout << (laPalindrome(dau) ? "Danh sách là palindrome." : "Danh sách không phải là palindrome.") << endl;
                break;
            case 9:
                cout << "Nhập giá trị để tìm: ";
                cin >> giaTri;
                {
                    Node* nodeTimThay = timNode(dau, giaTri);
                    if (nodeTimThay) cout << "Node tìm thấy: " << nodeTimThay->data << endl;
                    else cout << "Không tìm thấy node." << endl;
                }
                break;
            case 0:
                cout << "Thoát chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ." << endl;
        }
    } while (luaChon != 0);

    return 0;
}
