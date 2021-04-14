/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head)
{
    int count=0,i;
    bool consistence=1;
    struct ListNode *forward, *backward=NULL, *temp;
    forward=head;
    while(forward)
    {
        count++;
        forward=forward->next;
    }
    forward=head;
    if(count%2==0)
    {
        for(i=1;i<=count/2;i++)
        {
            temp=forward->next;
            forward->next=backward;
            backward=forward;
            forward=temp;
        }
    }
    else
    {
        for(i=1;i<=count/2;i++)
        {
            temp=forward->next;
            forward->next=backward;
            backward=forward;
            forward=temp;
        }
        forward=forward->next;
    }
    while(consistence && forward)
    {
        if(forward->val == backward->val)
        {
            forward=forward->next;
            backward=backward->next;
        }
        else
            consistence=0;
    }
    if(consistence)
        return 1;
    else
        return 0;
}
