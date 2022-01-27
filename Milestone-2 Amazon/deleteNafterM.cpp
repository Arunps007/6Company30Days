class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {   
        while(head) {
            int M = m, N = n;
            Node* prev = NULL;
            Node* start = head;
            while(start && M) {
                prev = start;
                start = start->next;
                M--;
            }
            
            Node* end = start;
            while(end && N) {
                Node* temp = end;
                end = end->next;
                N--;
                free(temp);
            }
            
            if(prev) {
                prev->next = end;
            }   
            head = end;
        }
    }
};