#ifndef BTREE_HPP_
#define BTREE_HPP_
#include <stack>
#include <deque>
#include <queue>

template<typename T>struct BinaryNode{
    T val;
    BinaryNode<T> *left,*right;;

    BinaryNode(const T& v,BinaryNode<T> *l = NULL,BinaryNode<T> *r=NULL):
        val(v),left(l),right(r){}

    ~BinaryNode()
    {
        if(left!=NULL){
            delete left;
        }
        left=NULL;
        if(right!=NULL){
            delete left;
        }
        right=NULL;
    }

};

//递归法遍历
template<typename T> void preorder(BinaryNode<T> *proot,int (*traverse)(BinaryNode<T>*))
{
    if(proot!=NULL){
        traverse(proot);
        //if(proot->left!=NULL)//递归会检查
        preorder(proot->left,traverse);
        //if(proot->right!=NULL)
        preorder(proot->right,traverse);
    }
}

template<typename T> void inorder(BinaryNode<T> *proot,int (*traverse)(BinaryNode<T>*))
{
    //if(proot->left!=NULL)
    if(proot!=NULL){
        inorder(proot->left,traverse);
        traverse(proot);
        //if(proot->right!=NULL)
        inorder(proot->right,traverse);
    }
}

template<typename T> void postorder(BinaryNode<T> *proot,int (*traverse)(BinaryNode<T>*))
{
    //if(proot->left!=NULL)
    if(proot!=NULL){
        postorder(proot->left,traverse);
        //if(proot->right!=NULL)
        postorder(proot->right,traverse);
        traverse(proot);
    }
}

//非递归遍历

/**1. 如果P不为空,访问P,并将P入栈
 * 2. 判断P的左孩子是否为空,如不为空，将P置为左孩子，循环1
 * 3. 如果P为NULL,判断栈是否为空,
 * 3. 如栈不为空,弹出栈顶元素，将元素的右孩子置为P，循环1
 * 4. 直到P为NULL且栈为空
 */
template<typename T> void preorderNotRecursive(BinaryNode<T> *proot,int (*traverse)(BinaryNode<T>*))
{
    BinaryNode<T> *p = proot;
    std::stack<BinaryNode<T>*> st;
    while((p!=NULL)||(!st.empty())){
        while(p!=NULL){
            traverse(p);
            st.push(p);
            p=p->left;
        }
        if(!st.empty()){
            p = st.top()->right;
            st.pop();
        }
    }
}

/**1. 将P压入栈，如果P的左子树不为空，重复直到P为空
 * 2. 如果栈不为空,栈顶出栈，访问栈顶元素,强P指向栈顶元素的右子树
 * 3. 重复1,直到P为NULL且栈为空
 */
template<typename T> void inorderNotRecursive(BinaryNode<T> *proot,int (*traverse)(BinaryNode<T>*))
{
    std::stack<BinaryNode<T>*> st;
    BinaryNode<T> *p = proot;
    while((p!=NULL)||(!st.empty())){
        while(p!=NULL){
            st.push(p);
            p=p->left;
        }
        if(!st.empty()){
            p = st.top();
            traverse(p);
            st.pop();
            p = p->right;
        }
    }
}
template<typename T> void postorderNotRecursive(BinaryNode<T> *proot,int (*traverse)(BinaryNode<T>*))
{
    std::stack<BinaryNode<T>*> st;
    BinaryNode<T> *cur = proot,*pre=NULL;
    st.push(proot);
    while(!st.empty()){
        cur = st.top();
        //如果当前结点没有子节点，或者都已被访问过
        if((cur->left==NULL && cur->right==NULL)||
                (pre!=NULL && (pre==cur->left||pre==cur->right))){
            traverse(cur);
            st.pop();
            pre=cur;//标记为访问
        }else{
            if(cur->right!=NULL)//当前结点右子树没有被访问
                st.push(cur->right);
            if(cur->left!=NULL)//先弹出左子树访问
                st.push(cur->left);
        }
    }
}
//层次遍历BFS
template<typename T> void levelorder(BinaryNode<T> *proot,int (*traverse)(BinaryNode<T>*))
{
    //测试使用stack看看会发生什么
    //经测试，使用stack替换变成了已右子树为先的DFS
    std::queue<BinaryNode<T>*> q;
    BinaryNode<T> *p = proot;
    if(p!=NULL)
        q.push(p);
    while(!q.empty()){
        //p = q.top();
        p = q.front();
        traverse(p);
        q.pop();
        if(p->left!=NULL)
            q.push(p->left);
        if(p->right!=NULL)
            q.push(p->right);
    }
}
#endif
