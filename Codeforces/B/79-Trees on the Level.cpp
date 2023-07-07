// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
#define getdiff(v1,v2,dist) set_difference(all(v1), all(v2),back_inserter(dist)); // search for v1 in v2 if v is empty without order else use search(v1,v2)
typedef long long ll;
typedef unsigned long long ull;
const double pi = 3.14159265358979323846;

using namespace std;

struct node {
    string data = "-1";
    node* left = NULL;
    node* right = NULL;
};

void solve() {
    string s;
    node* root = new node();
    bool d = 0;
    while (cin >> s)
    {
        if (s == "()")
        {

            //cout << "evaluation time" << endl;
            queue<node*> q;
            q.push(root);
            string ans = "";

            while (!q.empty())
            {
                if (d)
                {
                    break;
                }
                node* n = q.front();
                q.pop();
                if (n->data == "-1")
                {
                    d = 1;
                    break;
                }
                else {
                    ans += n->data;
                    ans += " ";
                }
                if (n->left != NULL)
                {
                    q.push(n->left);
                }
                if (n->right != NULL)
                {
                    q.push(n->right);
                }
            }
            if (d)
            {
                cout << "not complete" << endl;
                d = 0;
            }
            else {
                for (ll i = 0; i < ans.length() - 1; i++)
                {
                    cout << ans[i];
                }
                cout << endl;
            }
            // reseting tree
            root = new node();
        }
        else {
            string nodedata = "";
            string direction = "";
            ll i = 1;
            while (s[i] != ',')
            {
                nodedata += s[i];
                i++;
            }
            i++;
            while (s[i] != ')')
            {
                direction += s[i];
                i++;
            }
            //cout << nodedata << " " << direction << endl;
            node* trav = root;
            i = 0;
            while (i < direction.length())
            {
                if (direction[i] == 'L')
                {
                    node* left;
                    if (trav->left == NULL)
                    {
                        left = new node();
                        trav->left = left;
                    }
                    trav = trav->left;
                }
                else {
                    node* right;
                    if (trav->right == NULL)
                    {
                        right = new node();
                        trav->right = right;
                    }
                    trav = trav->right;
                }
                i++;
            }
            if (trav->data == "-1")
            {
                trav->data = nodedata;
            }
            else {
                d = 1;
            }
        }
    }
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    ll t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
