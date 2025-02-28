package main

func countStudents(students []int, sandwiches []int) int {
    cnt := [2]int{0, 0}
    for _, n := range students {
        cnt[n] += 1
    }

    n := len(sandwiches)
    for i := 0; i < n; i++ {
        cnt[sandwiches[i]] -= 1
        if cnt[sandwiches[i]] == -1 {
            return n - i
        }
    }
    return 0
}


func main() {
	str := "abc"
}

type Node struct {
    key, val int
    prev, next *Node
}

func initNode(k, v int) *Node {
    return &Node {
        key: k,
        val: v,
    }
}

type LRUCache struct {
    size, capacity int
    head, tail *Node
    cache map[int]*Node
}


func Constructor(capacity int) LRUCache {
    lru := LRUCache{
        capacity: capacity,
        head: initNode(-1, -1),
        tail: initNode(-1, -1),
        cache: make(map[int]*Node),
    }
    lru.head.next = lru.tail
    lru.tail.prev = lru.head

    return lru
}

func (this *LRUCache) addToHead(node *Node) {
    node.next = this.head.next
    node.prev = this.head
    this.head.next.prev = node
    this.head.next = node
}

func (this *LRUCache) removeNode(node *Node) {
    node.prev.next = node.next
    node.next.prev = node.prev
}

func (this *LRUCache) moveToHead(node *Node) {
    this.removeNode(node)
    this.addToHead(node)
}

func (this *LRUCache) removeTailNode() {
    tailNode := this.tail.prev
    delete(this.cache, tailNode.key)
    this.removeNode(tailNode)
}

func (this *LRUCache) Get(key int) int {
    if _, ok := this.cache[key]; !ok {
        return -1
    }

    node := this.cache[key]
    this.moveToHead(node)
    return node.val
}

func (this *LRUCache) Put(key int, value int)  {
    if _, ok := this.cache[key]; ok {
        this.cache[key].val = value
        this.moveToHead(this.cache[key])
    } else {
        newNode := initNode(key, value)
        this.addToHead(newNode)
        this.cache[key] = newNode

        this.size += 1
        if this.size > this.capacity {
            this.removeTailNode()
            this.size -= 1
        }
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */