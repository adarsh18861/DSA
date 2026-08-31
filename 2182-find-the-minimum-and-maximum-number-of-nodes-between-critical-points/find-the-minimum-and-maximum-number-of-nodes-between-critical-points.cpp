/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
         ListNode* temp = head->next;
         int prev = head->val;


         vector<pair<int,int>>crit;
         int dist =1;

         while(temp->next!= NULL){
             
             if(temp->val < temp->next->val && temp->val < prev){
                crit.push_back({dist,temp->val});
             }

             if(temp->val > temp->next->val && temp->val > prev){
                crit.push_back({dist,temp->val});
             }

             prev = temp->val;
             temp = temp->next;
             dist++;
         }

         int maxdist =INT_MIN;
         int mindist = INT_MAX;

         if(crit.size() <2) return {-1,-1};

         for(int i=0;i<crit.size()-1;i++){
            mindist = min(mindist,crit[i+1].first-crit[i].first);
         }

         maxdist = crit[crit.size()-1].first - crit[0].first;

         
         return {mindist,maxdist};
    }
};