class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>graph(numCourses);
        
        for(auto it:prerequisites)
        {
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }

        vector<int>order;
        while(!q.empty())
        {
           int course=q.front();
           q.pop();
           order.push_back(course);

           for(auto it:graph[course])
           {
             indegree[it]--;
             if(indegree[it]==0)
             q.push(it);
           }
        }
        if(order.size()== numCourses)
        return order;
        else
        return vector<int>();
    }
};

//Here V is the number of courses, and E is the number of prerequisites.
//TC:O(V+E)[ Building the graph O(E), processing the graph(Traversing nodes and edges) takes O(V+E).]
//SC:O(V+E)[ O(V+E) for the graph representation and O(V) for the indegree array and queue].
//Problem:https://leetcode.com/problems/course-schedule-ii/
