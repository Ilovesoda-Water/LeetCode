ListNode *p1, *p2;
        while(curr!=NULL){
            count = 0;
            p1 = curr; p2 = curr;
            while(p2!=NULL&&count<k-1){
                p2 = p2->next;
                count++;
            }
            if (p2!=NULL){
                curr = p2->next;
                reverseList(p1,p2);
                begin->next = p2;
                begin = p1;
            }
        }
