#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int op;
    char t;
    int pre;
    int nxt;
} a[200];
int k=1;

stack<char> ck;

int chk(char ch)
{
    if(ch=='(') return 0;
    if(ch=='+'||ch=='-') return 1;
    if(ch=='*'||ch=='/') return 2;
    return 3;
}

int cnt=0;

void del(int t)
{
    a[a[t].nxt].pre=a[t].pre;
    a[a[t].pre].nxt=a[t].nxt;
}

signed main()
{
    string t;
    cin >> t;
    a[0].nxt=1;
    for(int i=0; i<t.length(); i++)
    {
        if(isdigit(t[i]))
        {
            a[k].pre=k-1;
            a[k].nxt=k+1;
            a[k].t='#';
            a[k].op=t[i]-'0';
            k++;
        }
        else
        {
            cnt++;
            if(ck.empty()) ck.push(t[i]);
            else
            {
                int op=chk(t[i]);
                int op1=chk(ck.top());
                
                if(t[i]=='(')
                {
                    ck.push(t[i]);
                    continue;
                }
                if(t[i]==')')
                {
                    cnt-=2;
                    char l=ck.top();
                    ck.pop();
                    while(ck.size()&&l!='(')
                    {
                        
                        a[k].pre=k-1;
                        a[k].nxt=k+1;
                        a[k].t=l;
                        k++;
                        l=ck.top();
                        ck.pop();
                    }
                    continue;
                }
                if(t[i]=='^'&&op==op1) ck.push(t[i]);
                else
                {
                    while(ck.size()&&op<=op1)
                    {
                        char l=ck.top();
                        ck.pop();
                        a[k].pre=k-1;
                        a[k].nxt=k+1;
                        a[k].t=l;
                        k++;
                        if(ck.size()) op1=chk(ck.top());
                    }
                    ck.push(t[i]);
                }
            }
        }
    }
    while(ck.size())
    {
        char l=ck.top();
        ck.pop();
        a[k].pre=k-1;
        a[k].nxt=k+1;
        a[k].t=l;
        k++;
    }
    for(int i=1;i!=k;i=a[i].nxt)
    {
        if(a[i].t=='#') cout<<a[i].op<<' ';
        else cout<<a[i].t<<' ';
    }
    cout<<endl;
    for(int i=0;i<cnt;i++)
    {
        int op=1;
        while(a[op].t=='#') op=a[op].nxt;
        int kl=a[op].pre;
        int kj=a[kl].pre;
        del(kl);
        del(kj);
        kl=a[kl].op;
        kj=a[kj].op;
        char m=a[op].t;
        a[op].t='#';
        if(m=='+') a[op].op=kl+kj;
        else if(m=='-') a[op].op=kj-kl;
        else if(m=='*') a[op].op=kj*kl;
        else if(m=='/') a[op].op=kj/kl;
        else a[op].op=pow(kj,kl);
        for(int i=a[0].nxt;i!=k;i=a[i].nxt)
        {
            if(a[i].t=='#') cout<<a[i].op<<' ';
            else cout<<a[i].t<<' ';
        }
        cout<<endl;
    }
    return 0;
}
