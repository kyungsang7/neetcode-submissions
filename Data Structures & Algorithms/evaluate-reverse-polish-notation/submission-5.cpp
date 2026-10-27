class DoublyLinkedList{
public:
    string val;
    DoublyLinkedList* next;
    DoublyLinkedList* prev;
    
    DoublyLinkedList(string val, DoublyLinkedList* next = nullptr, DoublyLinkedList* prev = nullptr){
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;

        for (int i = 1; i < tokens.size(); i++){
            curr->next = new DoublyLinkedList(tokens[i], nullptr, curr);
            curr = curr->next;
        }

        int ans;
        while (head != nullptr){
            if (head->val == "+" || head->val == "-" || head->val == "*" || head->val == "/"){
                int a = stoi(head->prev->prev->val);
                int b = stoi(head->prev->val);
                int res;
                if (head->val == "+"){
                    res = a + b;
                }
                if (head->val == "-"){
                    res = a - b;
                }
                if (head->val == "*"){
                    res = a * b;
                }
                if (head->val == "/"){
                    res = a / b;
                }
                head->val = to_string(res);
                head->prev = head->prev->prev->prev;
                if (head->prev != nullptr){
                    head->prev->next = head;
                }
            }
            ans = stoi(head->val);
            head = head->next;
        }
        return ans;
    }
};
