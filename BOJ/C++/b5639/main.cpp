#include <bits/stdc++.h>
using namespace std;

class bstree
{
public:
    int k=0;
    bstree *p = NULL, *l = NULL, *r = NULL;
    bstree(int key)
    {
        this->k=key;
    };
    bstree(bstree * b, int key)
    {

        this->k=key;
        this->p=b;
        if((b->k)<key)
        {
            (b->r)=this;
        }
        else
        {
            (b->l)=this;
        }
    };
    bstree * srch(int key);
    void preorder();

};

bstree * bstree::srch(int key)
{
    bstree *nxt = (key<(this->k))?(this->l):(this->r);
    if(nxt == NULL)
    {
        return this;
    }
    else
    {
        return nxt->srch(key);
    }
}

void bstree::preorder()
{
    //bstree *l = this->l, *r = this->r;
    if(l != NULL)
    {
        l->preorder();
    }
    if(r != NULL)
    {
        r->preorder();
    }
    printf("%d\n", k);
}

int main()
{
    int preorder[10001], p_size=0;
    //while(scanf("%d",&preorder[p_size++]) != EOF)의 경우 마지막이 \n으로 끝나면 0이 추가로 입력되기에 이렇게 함.
    /// https://www.acmicpc.net/board/view/56592 https://www.acmicpc.net/board/view/73033 참고!
    while(scanf("%d",&preorder[p_size]) != EOF)
    {
        ++p_size;
    }
    //printf("%d", p_size);
    //p_size--;
    bstree root(preorder[0]), *tmp;
    for(int i=1,key;i<p_size;++i)
    {
        /// new is necessary!
        key=preorder[i];
        tmp = new bstree(root.srch(key), key);
        /// NOT this : bstree(root.srch(key), key);
        /// Why? hmm... IDK..
        /// In debugging, the 'this' in bstree(bstree * b, int key) were the same as the root's in the first time in while loop.
    }
    root.preorder();
    return 0;
}
