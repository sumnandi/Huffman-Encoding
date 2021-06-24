// Huffman Encoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int reducedBits = 0;        //For calculating Huffman code bits
class Huff
{  
    public:
        struct Node             //Structure Of Tree
        {
            int freq;
            char data;
            Node* left;
            Node* right;
            Node(int x, char a)
            {
                freq = x;
                data = a;
                left = right = NULL;
            }
        };

        struct compare      //Function Overloading
        {
            bool operator()(Node* a, Node* b)
            {
                return a->freq > b->freq;
            }
        };
        
        void preorderTraversal(Node* root, vector<string>& ans, string s,vector<char> &ans1,vector<int>&ans2)   //Preorder Traversal
        {
            if (root)
            {
                if (!root->left && !root->right)
                {
                    ans.push_back(s);
                    ans1.push_back(root->data);
                    ans2.push_back(root->freq);
                }
                preorderTraversal(root->left, ans, s + "0",ans1,ans2);
                preorderTraversal(root->right, ans, s + "1",ans1,ans2);
            }
        }
        
        vector<string> huffmanCodes(string s, vector<int> f, int N)     //Main Function
        {
            priority_queue<Node*, vector<Node*>, compare> minHeap;          //Taking minheap
            int n = f.size();

            for (int i = 0; i < n; i++)
            {
                Node* temp = new Node(f[i], s[i]);
                minHeap.push(temp);
            }

            while (minHeap.size() != 1)
            {
                Node* x = minHeap.top();
                minHeap.pop();

                Node* y = minHeap.top();
                minHeap.pop();

                Node* root = new Node(x->freq + y->freq, '#');
                root->left = x;
                root->right = y;

                minHeap.push(root);
            }
            Node* r1 = minHeap.top();
            vector<string> ans;     //For storing Huffman Codes
            vector<char> ans1;      //For Storing the character corresponding to Huffman Code
            vector<int> ans2;       //For Storing the frequency corresponding to Huffman Code
            preorderTraversal(minHeap.top(), ans, "",ans1,ans2);
            cout << endl<<endl;
            cout << "Huffman Encoding for the characters are as follows:" << endl;
            cout << "---------------------------------------------------" << endl;
            cout << "Character\tFrequency" << endl;
            
            for (int i = 0; i < n; i++)
            {
                cout << ans1[i] << "\t\t" << ans[i] << endl;
                reducedBits += ans[i].size() * ans2[i];
            }
            return ans;
        }
};
int main()
{
    cout << "DEPICTION OF HUFFMAN ENCODING "<<endl;
    cout << "------------------------------" << endl;
    string s;

    cout << "Enter a string of Distinct characters: ";
    cin >> s;
    int n = s.size();
    vector<int> freq;
    int bits = 0;
    cout << "Now Enter the Frequencies of each character: ";
    for (int i = 0; i < n; i++)
    {
        int freqq;
        cin >> freqq;
        bits +=freqq;
        freq.push_back(freqq);
    }
    cout << "Values Entered : " << endl;
    cout << "--------------------------" << endl;
    cout << "Character\tFrequency" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << "\t\t" << freq[i] << endl;
        bits += freq[i];
    }
    
    Huff sol;
    vector<string> fans=sol.huffmanCodes(s, freq, n);
    cout << "The total Number of bits used : " << bits<<endl;
    cout << "Total Bits after using Huffman Encoding : " << reducedBits << endl;
    cout << "Reduction in Bits after Huffman Encoding : " << bits - reducedBits;
    cout << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
