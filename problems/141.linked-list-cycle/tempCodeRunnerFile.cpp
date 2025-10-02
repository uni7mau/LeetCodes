        if (head == nullptr || head->next == nullptr) return false;

        ListNode* node1 = head;
        ListNode* node2 = head;

        while (node1 != nullptr && node2 != nullptr) {
            node1 = node1->next;
            node2 = node2->next;
            if (node2 != nullptr) node2 = node2->next;
            if (node1 == node2) return true;
        }

        return false;