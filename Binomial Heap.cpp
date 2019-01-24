#include<iostream>
#include<string>
#include<cstring>

using namespace std;

typedef struct node {
    int key;//键值
    int degree;//度数
    node *child;//第一个儿子
    node *parent;//父结点
    node *next;//兄弟结点
} bnode, *bheap;

bnode *Make_Node(int key) {
    bnode *node;
    node = new bnode;
    node->key = key;
    node->degree = 0;
    node->parent = nullptr;
    node->child = nullptr;
    node->next = nullptr;
    return node;
}

//合并两个根节点链表
bnode *Merge(bheap h1, bheap h2) {
    if (h1 == nullptr) return h2;
    else if (h2 == nullptr) return h1;
    bnode *head = nullptr;
    if (h1->degree < h2->degree) {
        head = h1;
        head->next = Merge(h1->next, h2);
    } else {
        head = h2;
        head->next = Merge(h2->next, h1);
    }
    return head;
}

//将两个相邻的根树合并
void Link(bheap child, bheap heap) {
    child->parent = heap;
    child->next = heap->child;
    heap->child = child;
    heap->degree++;
}

//合并
bnode *Union(bheap h1, bheap h2) {
    bnode *heap;
    bnode *pre_x, *x, *nxt_x;
    heap = Merge(h1, h2);
    if (heap == nullptr) return nullptr;
    pre_x = nullptr;
    x = heap;
    nxt_x = x->next;
    while (nxt_x != nullptr) {
        if ((x->degree != nxt_x->degree)
            || ((nxt_x->next != nullptr)
                && (nxt_x->degree == nxt_x->next->degree))) {
            pre_x = x;
            x = nxt_x;
        } else if (x->key <= nxt_x->key) {
            x->next = nxt_x->next;
            nxt_x->parent = x;
            Link(nxt_x, x);
        } else {
            if (pre_x == nullptr) heap = nxt_x;
            else pre_x->next = nxt_x;
            Link(x, nxt_x);
            x = nxt_x;
        }
        nxt_x = x->next;
    }
    return heap;
}

//插入
bnode *Insert(bheap heap, int key) {
    bnode *node;
    node = Make_Node(key);
    if (node == nullptr) return heap;
    return Union(heap, node);
}

//返回最小值指针
bnode *Minimun(bheap heap) {
    bnode *pos = heap;
    bnode *minn = heap;
    while (pos != nullptr) {
        if (pos->key < minn->key) minn = pos;
        pos = pos->next;
    }
    return minn;
}

//将子树们转换成一个新的二项堆
bnode *Transform(bheap heap) {
    bnode *next;
    bnode *tail = nullptr;
    if (!heap) return heap;
    heap->parent = nullptr;
    while (heap->next) {
        next = heap->next;
        heap->next = tail;
        tail = heap;
        heap = next;
        heap->parent = nullptr;
    }
    heap->next = tail;
    return heap;
}

//删除最小堆顶元素
bnode *Extract_Min(bheap heap) {
    bnode *minnode = Minimun(heap);
    bnode *pre, *pos;
    pre = nullptr;
    pos = heap;
    while (pos != minnode) {
        pre = pos;
        pos = pos->next;
    }
    if (pre) pre->next = minnode->next;
    else heap = minnode->next;
    heap = Union(heap, Transform(minnode->child));
    delete (minnode);
    return heap;
}