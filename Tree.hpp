namespace ariel{
    
    class Tree{
        
        
        private:
        
        public:
        Tree();
        Tree insert(int i);
        Tree remove(int i);
        int size();
        bool contains(int i);
        int root();
        int parent(int i);
        int left(int i);
        int right(int i);
        void print();
    };
}
