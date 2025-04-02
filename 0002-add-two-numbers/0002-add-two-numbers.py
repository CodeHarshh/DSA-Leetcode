# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, list1, list2):
            dummy = ListNode()
            current = dummy
            carry = 0

            # Traverse both linked lists until all numbers and carry are processed
            while list1 is not None or list2 is not None or carry:
                sum = carry  # Start with the carry from the previous addition
                
                # Add data from list1 if available
                if list1 is not None:
                    sum += list1.val
                    list1 = list1.next  # Move to the next node in list1

                # Add data from list2 if available
                if list2 is not None:
                    sum += list2.val
                    list2 = list2.next  # Move to the next node in list2

                # Update carry (the part that will be carried to the next node)
                carry = sum // 10

                # Create a new node with the current sum's last digit
                new_node = ListNode(sum % 10)

                # Link the new node to the result list
                current.next = new_node
                current = current.next  # Move current pointer to the new node

            # Return the result linked list, skipping the dummy node
            return dummy.next
        